from typing import Dict, List, Tuple


class PluginBlueprint:
    class ParsedPluginInfo:
        def __init__(self, parsed_data: Dict[str, Tuple]):
            self._parsed_data = parsed_data
            self._file_interface_map: Dict[str, str] = {}
            self._comrpc_interfaces: List[str] = []
            self._jsonrpc_interfaces: List[str] = []
            self._notification_interfaces: List[str] = []
            self._notification_entries: List[Tuple[str, object]] = []

            self.processInterfaces(parsed_data)

        def processInterfaces(self, parsed_data: Dict[str, Tuple]):
            for full_name, (cls_data, header_path) in parsed_data.items():
                root_name = self.extractRootName(full_name)
                header_file = header_path.split("/")[-1]

                self._file_interface_map[header_file] = root_name
                self._comrpc_interfaces.append(root_name)

                if "json" in cls_data.m_tags:
                    json_name = f"J{root_name[1:]}" if root_name.startswith("I") else f"J{root_name}"
                    self._jsonrpc_interfaces.append(json_name)

                if self.hasNotification(cls_data):
                    self._notification_interfaces.append(root_name)

                self.gatherNotificationEntries(full_name, cls_data)

        @staticmethod
        def extractRootName(full_name: str) -> str:
            return full_name.split("::")[-1]

        def hasNotification(self, cls_data) -> bool:
            if "Notification" in cls_data.m_name:
                return True
            return any(self.hasNotification(child) for child in cls_data.m_children.values())

        def gatherNotificationEntries(self, full_name: str, cls_data):
            parts = full_name.split("::")
            if len(parts) < 3:
                return

            exchange_ns = parts[1]
            iface_root = parts[2]
            stack = [(cls_data, iface_root)]

            while stack:
                current, iface = stack.pop()
                if "Notification" in current.m_name:
                    fq = f"{exchange_ns}::{iface}::{current.m_name}"
                    self._notification_entries.append((fq, current))
                for child in current.m_children.values():
                    stack.append((child, iface))

        def collectNotificationEntries(self) -> List[Tuple[str, object]]:
            return sorted(self._notification_entries)

        @property
        def comrpc_interfaces(self) -> List[str]:
            return self._comrpc_interfaces

        @property
        def jsonrpc_interfaces(self) -> List[str]:
            return self._jsonrpc_interfaces

        @property
        def notification_interfaces(self) -> List[str]:
            return self._notification_interfaces

        @property
        def file_interface_map(self) -> Dict[str, str]:
            return self._file_interface_map

        @property
        def notification_entries(self) -> List[Tuple[str, object]]:
            return self._notification_entries

    def __init__(self,
                 name,
                 out_of_process,
                 configuration,
                 parsed_data,
                 header_lookup,
                 locations,
                 preconditions=None,
                 terminations=None,
                 controls=None):
        self._name = name
        self._out_of_process = out_of_process
        self._configuration = configuration
        self._parsed_data = parsed_data
        self._header_lookup = header_lookup
        self._locations = locations

        preconditions = preconditions or []
        terminations = terminations or []
        controls = controls or []

        self._PRECONDITIONS = [entry.upper() for entry in preconditions if entry]
        self._TERMINATIONS = [entry.upper() for entry in terminations if entry]
        self._CONTROLS = [entry.upper() for entry in controls if entry]

        parsed_info = self.ParsedPluginInfo(parsed_data)
        self._parsed_info = parsed_info
        self._comrpc_interfaces = parsed_info.comrpc_interfaces
        self._jsonrpc_interfaces = parsed_info.jsonrpc_interfaces
        self._notification_interfaces = parsed_info.notification_interfaces
        self._file_interface_map = parsed_info.file_interface_map
        self._notification_entries = parsed_info.collectNotificationEntries()

    @property
    def name(self) -> str:
        return self._name

    @property
    def out_of_process(self) -> bool:
        return self._out_of_process

    @property
    def configuration(self) -> bool:
        return self._configuration

    @property
    def parsed_data(self) -> Dict[str, Tuple]:
        return self._parsed_data

    @property
    def header_lookup(self) -> Dict[str, str]:
        return self._header_lookup

    @property
    def locations(self) -> Dict[str, str]:
        return self._locations

    @property
    def comrpc_interfaces(self) -> List[str]:
        return self._comrpc_interfaces

    @property
    def jsonrpc_interfaces(self) -> List[str]:
        return self._jsonrpc_interfaces

    @property
    def notification_interfaces(self) -> List[str]:
        return self._notification_interfaces

    @property
    def file_interface_map(self) -> Dict[str, str]:
        return self._file_interface_map

    @property
    def notification_entries(self) -> List[Tuple[str, object]]:
        return self._notification_entries

    @property
    def preconditions(self) -> List[str]:
        return self._PRECONDITIONS

    @property
    def terminations(self) -> List[str]:
        return self._TERMINATIONS

    @property
    def controls(self) -> List[str]:
        return self._CONTROLS

    def isJsonRpcPlugin(self) -> bool:
        return any("json" in cls_data.m_tags for cls_data, _ in self._parsed_data.values())