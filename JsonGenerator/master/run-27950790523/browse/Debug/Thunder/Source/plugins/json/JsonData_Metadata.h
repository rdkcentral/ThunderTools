// C++ types for Metadata API.
// Generated automatically from 'IController.h'. DO NOT EDIT.

// Note: This code is inherently not thread safe. If required, proper synchronisation must be added.

#pragma once

#include <core/JSON.h>

namespace Thunder {

namespace JsonData {

    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    namespace Metadata {

        // Common classes
        //

        class VersionInfo : public Core::JSON::Container {
        public:
            VersionInfo()
                : Core::JSON::Container()
            {
                _Init();
            }

            VersionInfo(const VersionInfo& _other)
                : Core::JSON::Container()
                , Hash(_other.Hash)
                , Major(_other.Major)
                , Minor(_other.Minor)
                , Patch(_other.Patch)
            {
                _Init();
            }

            VersionInfo(VersionInfo&& _other) noexcept
                : Core::JSON::Container()
                , Hash(std::move(_other.Hash))
                , Major(std::move(_other.Major))
                , Minor(std::move(_other.Minor))
                , Patch(std::move(_other.Patch))
            {
                _Init();
            }

            VersionInfo(const Exchange::Controller::IMetadata::Data::Version& _other)
                : Core::JSON::Container()
            {
                Hash = _other.Hash;
                Major = _other.Major;
                Minor = _other.Minor;
                Patch = _other.Patch;
                _Init();
            }

            VersionInfo& operator=(const VersionInfo& _rhs)
            {
                Hash = _rhs.Hash;
                Major = _rhs.Major;
                Minor = _rhs.Minor;
                Patch = _rhs.Patch;
                return (*this);
            }

            VersionInfo& operator=(VersionInfo&& _rhs) noexcept
            {
                Hash = std::move(_rhs.Hash);
                Major = std::move(_rhs.Major);
                Minor = std::move(_rhs.Minor);
                Patch = std::move(_rhs.Patch);
                return (*this);
            }

            VersionInfo& operator=(const Exchange::Controller::IMetadata::Data::Version& _rhs)
            {
                Hash = _rhs.Hash;
                Major = _rhs.Major;
                Minor = _rhs.Minor;
                Patch = _rhs.Patch;
                return (*this);
            }

            operator Exchange::Controller::IMetadata::Data::Version() const
            {
                Exchange::Controller::IMetadata::Data::Version _value{};
                _value.Hash = Hash;
                _value.Major = Major;
                _value.Minor = Minor;
                _value.Patch = Patch;
                return (_value);
            }

            ~VersionInfo() = default;

        public:
            bool IsDataValid() const
            {
                return ((((Hash.IsSet() == true) && (Hash.Value().size() >= 64 && Hash.Value().size() <= 64))) && (Major.IsSet() == true) && (Minor.IsSet() == true) && (Patch.IsSet() == true));
            }

        private:
            void _Init()
            {
                Add(_T("hash"), &Hash);
                Add(_T("major"), &Major);
                Add(_T("minor"), &Minor);
                Add(_T("patch"), &Patch);
            }

        public:
            Core::JSON::String Hash; // SHA256 hash identifying the source code
            Core::JSON::DecUInt8 Major; // Major number
            Core::JSON::DecUInt8 Minor; // Minor number
            Core::JSON::DecUInt8 Patch; // Patch number
        }; // class VersionInfo

        // Method params/result classes
        //

        class BuildInfoData : public Core::JSON::Container {
        public:
            BuildInfoData()
                : Core::JSON::Container()
            {
                _Init();
            }

            BuildInfoData(const BuildInfoData& _other)
                : Core::JSON::Container()
                , SystemType(_other.SystemType)
                , BuildType(_other.BuildType)
                , Extensions(_other.Extensions)
                , Messaging(_other.Messaging)
                , ExceptionCatching(_other.ExceptionCatching)
                , DeadlockDetection(_other.DeadlockDetection)
                , WCharSupport(_other.WCharSupport)
                , InstanceIDBits(_other.InstanceIDBits)
                , TraceLevel(_other.TraceLevel)
                , ThreadPoolCount(_other.ThreadPoolCount)
                , COMRPCTimeOut(_other.COMRPCTimeOut)
            {
                _Init();
            }

            BuildInfoData(BuildInfoData&& _other) noexcept
                : Core::JSON::Container()
                , SystemType(std::move(_other.SystemType))
                , BuildType(std::move(_other.BuildType))
                , Extensions(std::move(_other.Extensions))
                , Messaging(std::move(_other.Messaging))
                , ExceptionCatching(std::move(_other.ExceptionCatching))
                , DeadlockDetection(std::move(_other.DeadlockDetection))
                , WCharSupport(std::move(_other.WCharSupport))
                , InstanceIDBits(std::move(_other.InstanceIDBits))
                , TraceLevel(std::move(_other.TraceLevel))
                , ThreadPoolCount(std::move(_other.ThreadPoolCount))
                , COMRPCTimeOut(std::move(_other.COMRPCTimeOut))
            {
                _Init();
            }

            BuildInfoData(const Exchange::Controller::IMetadata::Data::BuildInfo& _other)
                : Core::JSON::Container()
            {
                SystemType = _other.SystemType;
                BuildType = _other.BuildType;
                if (_other.Extensions.IsSet() == true) {
                    Extensions.Set(true);
                    Extensions = _other.Extensions.Value();
                }
                Messaging = _other.Messaging;
                ExceptionCatching = _other.ExceptionCatching;
                DeadlockDetection = _other.DeadlockDetection;
                WCharSupport = _other.WCharSupport;
                InstanceIDBits = _other.InstanceIDBits;
                if (_other.TraceLevel.IsSet() == true) {
                    TraceLevel = _other.TraceLevel.Value();
                }
                ThreadPoolCount = _other.ThreadPoolCount;
                COMRPCTimeOut = _other.COMRPCTimeOut;
                _Init();
            }

            BuildInfoData& operator=(const BuildInfoData& _rhs)
            {
                SystemType = _rhs.SystemType;
                BuildType = _rhs.BuildType;
                if (_rhs.Extensions.IsSet() == true) {
                    Extensions = _rhs.Extensions;
                }
                Messaging = _rhs.Messaging;
                ExceptionCatching = _rhs.ExceptionCatching;
                DeadlockDetection = _rhs.DeadlockDetection;
                WCharSupport = _rhs.WCharSupport;
                InstanceIDBits = _rhs.InstanceIDBits;
                if (_rhs.TraceLevel.IsSet() == true) {
                    TraceLevel = _rhs.TraceLevel;
                }
                ThreadPoolCount = _rhs.ThreadPoolCount;
                COMRPCTimeOut = _rhs.COMRPCTimeOut;
                return (*this);
            }

            BuildInfoData& operator=(BuildInfoData&& _rhs) noexcept
            {
                SystemType = std::move(_rhs.SystemType);
                BuildType = std::move(_rhs.BuildType);
                Extensions = std::move(_rhs.Extensions);
                Messaging = std::move(_rhs.Messaging);
                ExceptionCatching = std::move(_rhs.ExceptionCatching);
                DeadlockDetection = std::move(_rhs.DeadlockDetection);
                WCharSupport = std::move(_rhs.WCharSupport);
                InstanceIDBits = std::move(_rhs.InstanceIDBits);
                TraceLevel = std::move(_rhs.TraceLevel);
                ThreadPoolCount = std::move(_rhs.ThreadPoolCount);
                COMRPCTimeOut = std::move(_rhs.COMRPCTimeOut);
                return (*this);
            }

            BuildInfoData& operator=(const Exchange::Controller::IMetadata::Data::BuildInfo& _rhs)
            {
                SystemType = _rhs.SystemType;
                BuildType = _rhs.BuildType;
                if (_rhs.Extensions.IsSet() == true) {
                    Extensions.Set(true);
                    Extensions = _rhs.Extensions.Value();
                }
                Messaging = _rhs.Messaging;
                ExceptionCatching = _rhs.ExceptionCatching;
                DeadlockDetection = _rhs.DeadlockDetection;
                WCharSupport = _rhs.WCharSupport;
                InstanceIDBits = _rhs.InstanceIDBits;
                if (_rhs.TraceLevel.IsSet() == true) {
                    TraceLevel = _rhs.TraceLevel.Value();
                }
                ThreadPoolCount = _rhs.ThreadPoolCount;
                COMRPCTimeOut = _rhs.COMRPCTimeOut;
                return (*this);
            }

            operator Exchange::Controller::IMetadata::Data::BuildInfo() const
            {
                Exchange::Controller::IMetadata::Data::BuildInfo _value{};
                _value.SystemType = SystemType;
                _value.BuildType = BuildType;
                if (Extensions.IsSet() == true) {
                    _value.Extensions = Extensions;
                }
                _value.Messaging = Messaging;
                _value.ExceptionCatching = ExceptionCatching;
                _value.DeadlockDetection = DeadlockDetection;
                _value.WCharSupport = WCharSupport;
                _value.InstanceIDBits = InstanceIDBits;
                if (TraceLevel.IsSet() == true) {
                    _value.TraceLevel = TraceLevel;
                }
                _value.ThreadPoolCount = ThreadPoolCount;
                _value.COMRPCTimeOut = COMRPCTimeOut;
                return (_value);
            }

            ~BuildInfoData() = default;

        public:
            bool IsDataValid() const
            {
                return ((SystemType.IsSet() == true) && (BuildType.IsSet() == true) && (Messaging.IsSet() == true) && (ExceptionCatching.IsSet() == true) && (DeadlockDetection.IsSet() == true) && (WCharSupport.IsSet() == true) && (InstanceIDBits.IsSet() == true) && (ThreadPoolCount.IsSet() == true) && (COMRPCTimeOut.IsSet() == true));
            }

        private:
            void _Init()
            {
                Add(_T("systemtype"), &SystemType);
                Add(_T("buildtype"), &BuildType);
                Add(_T("extensions"), &Extensions);
                Add(_T("messaging"), &Messaging);
                Add(_T("exceptioncatching"), &ExceptionCatching);
                Add(_T("deadlockdetection"), &DeadlockDetection);
                Add(_T("wcharsupport"), &WCharSupport);
                Add(_T("instanceidbits"), &InstanceIDBits);
                Add(_T("tracelevel"), &TraceLevel);
                Add(_T("threadpoolcount"), &ThreadPoolCount);
                Add(_T("comrpctimeout"), &COMRPCTimeOut);
            }

        public:
            Core::JSON::EnumType<Exchange::Controller::IMetadata::Data::BuildInfo::systemtype> SystemType; // System type
            Core::JSON::EnumType<Exchange::Controller::IMetadata::Data::BuildInfo::buildtype> BuildType; // Build type
            Core::JSON::ArrayType<Core::JSON::EnumType<Exchange::Controller::IMetadata::Data::BuildInfo::extensiontype>> Extensions; // Build information
            Core::JSON::Boolean Messaging; // Denotes whether Messaging is enabled
            Core::JSON::Boolean ExceptionCatching; // Denotes whether there is an exception
            Core::JSON::Boolean DeadlockDetection; // Denotes whether deadlock detection is enabled
            Core::JSON::Boolean WCharSupport; // Build information
            Core::JSON::DecUInt8 InstanceIDBits; // Core instance bits
            Core::JSON::DecUInt8 TraceLevel; // Trace level
            Core::JSON::DecUInt8 ThreadPoolCount; // Build information
            Core::JSON::DecUInt32 COMRPCTimeOut; // Build information
        }; // class BuildInfoData

        class CallStackData : public Core::JSON::Container {
        public:
            CallStackData()
                : Core::JSON::Container()
            {
                _Init();
            }

            CallStackData(const CallStackData& _other)
                : Core::JSON::Container()
                , Address(_other.Address)
                , Module(_other.Module)
                , Function(_other.Function)
                , Line(_other.Line)
            {
                _Init();
            }

            CallStackData(CallStackData&& _other) noexcept
                : Core::JSON::Container()
                , Address(std::move(_other.Address))
                , Module(std::move(_other.Module))
                , Function(std::move(_other.Function))
                , Line(std::move(_other.Line))
            {
                _Init();
            }

            CallStackData(const Exchange::Controller::IMetadata::Data::CallStack& _other)
                : Core::JSON::Container()
            {
                Address = _other.Address;
                Module = _other.Module;
                if (_other.Function.IsSet() == true) {
                    Function = _other.Function.Value();
                }
                if (_other.Line.IsSet() == true) {
                    Line = _other.Line.Value();
                }
                _Init();
            }

            CallStackData& operator=(const CallStackData& _rhs)
            {
                Address = _rhs.Address;
                Module = _rhs.Module;
                if (_rhs.Function.IsSet() == true) {
                    Function = _rhs.Function;
                }
                if (_rhs.Line.IsSet() == true) {
                    Line = _rhs.Line;
                }
                return (*this);
            }

            CallStackData& operator=(CallStackData&& _rhs) noexcept
            {
                Address = std::move(_rhs.Address);
                Module = std::move(_rhs.Module);
                Function = std::move(_rhs.Function);
                Line = std::move(_rhs.Line);
                return (*this);
            }

            CallStackData& operator=(const Exchange::Controller::IMetadata::Data::CallStack& _rhs)
            {
                Address = _rhs.Address;
                Module = _rhs.Module;
                if (_rhs.Function.IsSet() == true) {
                    Function = _rhs.Function.Value();
                }
                if (_rhs.Line.IsSet() == true) {
                    Line = _rhs.Line.Value();
                }
                return (*this);
            }

            operator Exchange::Controller::IMetadata::Data::CallStack() const
            {
                Exchange::Controller::IMetadata::Data::CallStack _value{};
                _value.Address = Address;
                _value.Module = Module;
                if (Function.IsSet() == true) {
                    _value.Function = Function;
                }
                if (Line.IsSet() == true) {
                    _value.Line = Line;
                }
                return (_value);
            }

            ~CallStackData() = default;

        public:
            bool IsDataValid() const
            {
                return ((Address.IsSet() == true) && (Module.IsSet() == true));
            }

        private:
            void _Init()
            {
                Add(_T("address"), &Address);
                Add(_T("module"), &Module);
                Add(_T("function"), &Function);
                Add(_T("line"), &Line);
            }

        public:
            Core::JSON::InstanceId Address; // Memory address
            Core::JSON::String Module; // Module name
            Core::JSON::String Function; // Function name
            Core::JSON::DecUInt32 Line; // Line number
        }; // class CallStackData

        class LinkData : public Core::JSON::Container {
        public:
            LinkData()
                : Core::JSON::Container()
            {
                _Init();
            }

            LinkData(const LinkData& _other)
                : Core::JSON::Container()
                , Remote(_other.Remote)
                , State(_other.State)
                , Id(_other.Id)
                , Activity(_other.Activity)
                , Name(_other.Name)
            {
                _Init();
            }

            LinkData(LinkData&& _other) noexcept
                : Core::JSON::Container()
                , Remote(std::move(_other.Remote))
                , State(std::move(_other.State))
                , Id(std::move(_other.Id))
                , Activity(std::move(_other.Activity))
                , Name(std::move(_other.Name))
            {
                _Init();
            }

            LinkData(const Exchange::Controller::IMetadata::Data::Link& _other)
                : Core::JSON::Container()
            {
                Remote = _other.Remote;
                State = _other.State;
                Id = _other.Id;
                Activity = _other.Activity;
                if (_other.Name.IsSet() == true) {
                    Name = _other.Name.Value();
                }
                _Init();
            }

            LinkData& operator=(const LinkData& _rhs)
            {
                Remote = _rhs.Remote;
                State = _rhs.State;
                Id = _rhs.Id;
                Activity = _rhs.Activity;
                if (_rhs.Name.IsSet() == true) {
                    Name = _rhs.Name;
                }
                return (*this);
            }

            LinkData& operator=(LinkData&& _rhs) noexcept
            {
                Remote = std::move(_rhs.Remote);
                State = std::move(_rhs.State);
                Id = std::move(_rhs.Id);
                Activity = std::move(_rhs.Activity);
                Name = std::move(_rhs.Name);
                return (*this);
            }

            LinkData& operator=(const Exchange::Controller::IMetadata::Data::Link& _rhs)
            {
                Remote = _rhs.Remote;
                State = _rhs.State;
                Id = _rhs.Id;
                Activity = _rhs.Activity;
                if (_rhs.Name.IsSet() == true) {
                    Name = _rhs.Name.Value();
                }
                return (*this);
            }

            operator Exchange::Controller::IMetadata::Data::Link() const
            {
                Exchange::Controller::IMetadata::Data::Link _value{};
                _value.Remote = Remote;
                _value.State = State;
                _value.Id = Id;
                _value.Activity = Activity;
                if (Name.IsSet() == true) {
                    _value.Name = Name;
                }
                return (_value);
            }

            ~LinkData() = default;

        public:
            bool IsDataValid() const
            {
                return ((Remote.IsSet() == true) && (State.IsSet() == true) && (Id.IsSet() == true) && (Activity.IsSet() == true));
            }

        private:
            void _Init()
            {
                Add(_T("remote"), &Remote);
                Add(_T("state"), &State);
                Add(_T("id"), &Id);
                Add(_T("activity"), &Activity);
                Add(_T("name"), &Name);
            }

        public:
            Core::JSON::String Remote; // IP address (or FQDN) of the other side of the connection
            Core::JSON::EnumType<Exchange::Controller::IMetadata::Data::Link::state> State; // State of the link
            Core::JSON::DecUInt32 Id; // A unique number identifying the connection
            Core::JSON::Boolean Activity; // Denotes if there was any activity on this connection
            Core::JSON::String Name; // Name of the connection
        }; // class LinkData

        class ProxyData : public Core::JSON::Container {
        public:
            ProxyData()
                : Core::JSON::Container()
            {
                _Init();
            }

            ProxyData(const ProxyData& _other)
                : Core::JSON::Container()
                , Interface(_other.Interface)
                , Name(_other.Name)
                , Instance(_other.Instance)
                , Count(_other.Count)
                , Origin(_other.Origin)
            {
                _Init();
            }

            ProxyData(ProxyData&& _other) noexcept
                : Core::JSON::Container()
                , Interface(std::move(_other.Interface))
                , Name(std::move(_other.Name))
                , Instance(std::move(_other.Instance))
                , Count(std::move(_other.Count))
                , Origin(std::move(_other.Origin))
            {
                _Init();
            }

            ProxyData(const Exchange::Controller::IMetadata::Data::Proxy& _other)
                : Core::JSON::Container()
            {
                Interface = _other.Interface;
                Name = _other.Name;
                Instance = _other.Instance;
                Count = _other.Count;
                if (_other.Origin.IsSet() == true) {
                    Origin = _other.Origin.Value();
                }
                _Init();
            }

            ProxyData& operator=(const ProxyData& _rhs)
            {
                Interface = _rhs.Interface;
                Name = _rhs.Name;
                Instance = _rhs.Instance;
                Count = _rhs.Count;
                if (_rhs.Origin.IsSet() == true) {
                    Origin = _rhs.Origin;
                }
                return (*this);
            }

            ProxyData& operator=(ProxyData&& _rhs) noexcept
            {
                Interface = std::move(_rhs.Interface);
                Name = std::move(_rhs.Name);
                Instance = std::move(_rhs.Instance);
                Count = std::move(_rhs.Count);
                Origin = std::move(_rhs.Origin);
                return (*this);
            }

            ProxyData& operator=(const Exchange::Controller::IMetadata::Data::Proxy& _rhs)
            {
                Interface = _rhs.Interface;
                Name = _rhs.Name;
                Instance = _rhs.Instance;
                Count = _rhs.Count;
                if (_rhs.Origin.IsSet() == true) {
                    Origin = _rhs.Origin.Value();
                }
                return (*this);
            }

            operator Exchange::Controller::IMetadata::Data::Proxy() const
            {
                Exchange::Controller::IMetadata::Data::Proxy _value{};
                _value.Interface = Interface;
                _value.Name = Name;
                _value.Instance = Instance;
                _value.Count = Count;
                if (Origin.IsSet() == true) {
                    _value.Origin = Origin;
                }
                return (_value);
            }

            ~ProxyData() = default;

        public:
            bool IsDataValid() const
            {
                return ((Interface.IsSet() == true) && (Name.IsSet() == true) && (Instance.IsSet() == true) && (Count.IsSet() == true));
            }

        private:
            void _Init()
            {
                Add(_T("interface"), &Interface);
                Add(_T("name"), &Name);
                Add(_T("instance"), &Instance);
                Add(_T("count"), &Count);
                Add(_T("origin"), &Origin);
            }

        public:
            Core::JSON::DecUInt32 Interface; // Interface ID
            Core::JSON::String Name; // The fully qualified name of the interface
            Core::JSON::InstanceId Instance; // Instance ID
            Core::JSON::DecUInt32 Count; // Reference count
            Core::JSON::String Origin; // The Origin of the assocated connection
        }; // class ProxyData

        class ServiceData : public Core::JSON::Container {
        public:
            ServiceData()
                : Core::JSON::Container()
            {
                _Init();
            }

            ServiceData(const ServiceData& _other)
                : Core::JSON::Container()
                , Callsign(_other.Callsign)
                , Locator(_other.Locator)
                , ClassName(_other.ClassName)
                , Module(_other.Module)
                , State(_other.State)
                , StartMode(_other.StartMode)
                , Resumed(_other.Resumed)
                , Version(_other.Version)
                , Communicator(_other.Communicator)
                , PersistentPathPostfix(_other.PersistentPathPostfix)
                , VolatilePathPostfix(_other.VolatilePathPostfix)
                , SystemRootPath(_other.SystemRootPath)
                , Precondition(_other.Precondition)
                , Termination(_other.Termination)
                , Control(_other.Control)
                , Configuration(_other.Configuration)
                , Observers(_other.Observers)
                , ProcessedRequests(_other.ProcessedRequests)
                , ProcessedObjects(_other.ProcessedObjects)
            {
                _Init();
            }

            ServiceData(ServiceData&& _other) noexcept
                : Core::JSON::Container()
                , Callsign(std::move(_other.Callsign))
                , Locator(std::move(_other.Locator))
                , ClassName(std::move(_other.ClassName))
                , Module(std::move(_other.Module))
                , State(std::move(_other.State))
                , StartMode(std::move(_other.StartMode))
                , Resumed(std::move(_other.Resumed))
                , Version(std::move(_other.Version))
                , Communicator(std::move(_other.Communicator))
                , PersistentPathPostfix(std::move(_other.PersistentPathPostfix))
                , VolatilePathPostfix(std::move(_other.VolatilePathPostfix))
                , SystemRootPath(std::move(_other.SystemRootPath))
                , Precondition(std::move(_other.Precondition))
                , Termination(std::move(_other.Termination))
                , Control(std::move(_other.Control))
                , Configuration(std::move(_other.Configuration))
                , Observers(std::move(_other.Observers))
                , ProcessedRequests(std::move(_other.ProcessedRequests))
                , ProcessedObjects(std::move(_other.ProcessedObjects))
            {
                _Init();
            }

            ServiceData(const Exchange::Controller::IMetadata::Data::Service& _other)
                : Core::JSON::Container()
            {
                Callsign = _other.Callsign;
                Locator = _other.Locator;
                ClassName = _other.ClassName;
                Module = _other.Module;
                State = _other.State;
                StartMode = _other.StartMode;
                Resumed = _other.Resumed;
                Version.Set(true);
                Version = _other.Version;
                if (_other.Communicator.IsSet() == true) {
                    Communicator = _other.Communicator.Value();
                }
                if (_other.PersistentPathPostfix.IsSet() == true) {
                    PersistentPathPostfix = _other.PersistentPathPostfix.Value();
                }
                if (_other.VolatilePathPostfix.IsSet() == true) {
                    VolatilePathPostfix = _other.VolatilePathPostfix.Value();
                }
                if (_other.SystemRootPath.IsSet() == true) {
                    SystemRootPath = _other.SystemRootPath.Value();
                }
                if (_other.Precondition.IsSet() == true) {
                    Precondition = _other.Precondition.Value();
                }
                if (_other.Termination.IsSet() == true) {
                    Termination = _other.Termination.Value();
                }
                if (_other.Control.IsSet() == true) {
                    Control = _other.Control.Value();
                }
                if (_other.Configuration.empty() == false) {
                    Configuration = _other.Configuration;
                }
                Observers = _other.Observers;
                if (_other.ProcessedRequests.IsSet() == true) {
                    ProcessedRequests = _other.ProcessedRequests.Value();
                }
                if (_other.ProcessedObjects.IsSet() == true) {
                    ProcessedObjects = _other.ProcessedObjects.Value();
                }
                _Init();
            }

            ServiceData& operator=(const ServiceData& _rhs)
            {
                Callsign = _rhs.Callsign;
                Locator = _rhs.Locator;
                ClassName = _rhs.ClassName;
                Module = _rhs.Module;
                State = _rhs.State;
                StartMode = _rhs.StartMode;
                Resumed = _rhs.Resumed;
                Version = _rhs.Version;
                if (_rhs.Communicator.IsSet() == true) {
                    Communicator = _rhs.Communicator;
                }
                if (_rhs.PersistentPathPostfix.IsSet() == true) {
                    PersistentPathPostfix = _rhs.PersistentPathPostfix;
                }
                if (_rhs.VolatilePathPostfix.IsSet() == true) {
                    VolatilePathPostfix = _rhs.VolatilePathPostfix;
                }
                if (_rhs.SystemRootPath.IsSet() == true) {
                    SystemRootPath = _rhs.SystemRootPath;
                }
                if (_rhs.Precondition.IsSet() == true) {
                    Precondition = _rhs.Precondition;
                }
                if (_rhs.Termination.IsSet() == true) {
                    Termination = _rhs.Termination;
                }
                if (_rhs.Control.IsSet() == true) {
                    Control = _rhs.Control;
                }
                if (_rhs.Configuration.Value().empty() == false) {
                    Configuration = _rhs.Configuration;
                }
                Observers = _rhs.Observers;
                if (_rhs.ProcessedRequests.IsSet() == true) {
                    ProcessedRequests = _rhs.ProcessedRequests;
                }
                if (_rhs.ProcessedObjects.IsSet() == true) {
                    ProcessedObjects = _rhs.ProcessedObjects;
                }
                return (*this);
            }

            ServiceData& operator=(ServiceData&& _rhs) noexcept
            {
                Callsign = std::move(_rhs.Callsign);
                Locator = std::move(_rhs.Locator);
                ClassName = std::move(_rhs.ClassName);
                Module = std::move(_rhs.Module);
                State = std::move(_rhs.State);
                StartMode = std::move(_rhs.StartMode);
                Resumed = std::move(_rhs.Resumed);
                Version = std::move(_rhs.Version);
                Communicator = std::move(_rhs.Communicator);
                PersistentPathPostfix = std::move(_rhs.PersistentPathPostfix);
                VolatilePathPostfix = std::move(_rhs.VolatilePathPostfix);
                SystemRootPath = std::move(_rhs.SystemRootPath);
                Precondition = std::move(_rhs.Precondition);
                Termination = std::move(_rhs.Termination);
                Control = std::move(_rhs.Control);
                Configuration = std::move(_rhs.Configuration);
                Observers = std::move(_rhs.Observers);
                ProcessedRequests = std::move(_rhs.ProcessedRequests);
                ProcessedObjects = std::move(_rhs.ProcessedObjects);
                return (*this);
            }

            ServiceData& operator=(const Exchange::Controller::IMetadata::Data::Service& _rhs)
            {
                Callsign = _rhs.Callsign;
                Locator = _rhs.Locator;
                ClassName = _rhs.ClassName;
                Module = _rhs.Module;
                State = _rhs.State;
                StartMode = _rhs.StartMode;
                Resumed = _rhs.Resumed;
                Version.Set(true);
                Version = _rhs.Version;
                if (_rhs.Communicator.IsSet() == true) {
                    Communicator = _rhs.Communicator.Value();
                }
                if (_rhs.PersistentPathPostfix.IsSet() == true) {
                    PersistentPathPostfix = _rhs.PersistentPathPostfix.Value();
                }
                if (_rhs.VolatilePathPostfix.IsSet() == true) {
                    VolatilePathPostfix = _rhs.VolatilePathPostfix.Value();
                }
                if (_rhs.SystemRootPath.IsSet() == true) {
                    SystemRootPath = _rhs.SystemRootPath.Value();
                }
                if (_rhs.Precondition.IsSet() == true) {
                    Precondition = _rhs.Precondition.Value();
                }
                if (_rhs.Termination.IsSet() == true) {
                    Termination = _rhs.Termination.Value();
                }
                if (_rhs.Control.IsSet() == true) {
                    Control = _rhs.Control.Value();
                }
                if (_rhs.Configuration.empty() == false) {
                    Configuration = _rhs.Configuration;
                }
                Observers = _rhs.Observers;
                if (_rhs.ProcessedRequests.IsSet() == true) {
                    ProcessedRequests = _rhs.ProcessedRequests.Value();
                }
                if (_rhs.ProcessedObjects.IsSet() == true) {
                    ProcessedObjects = _rhs.ProcessedObjects.Value();
                }
                return (*this);
            }

            operator Exchange::Controller::IMetadata::Data::Service() const
            {
                Exchange::Controller::IMetadata::Data::Service _value{};
                _value.Callsign = Callsign;
                _value.Locator = Locator;
                _value.ClassName = ClassName;
                _value.Module = Module;
                _value.State = State;
                _value.StartMode = StartMode;
                _value.Resumed = Resumed;
                _value.Version = Version;
                if (Communicator.IsSet() == true) {
                    _value.Communicator = Communicator;
                }
                if (PersistentPathPostfix.IsSet() == true) {
                    _value.PersistentPathPostfix = PersistentPathPostfix;
                }
                if (VolatilePathPostfix.IsSet() == true) {
                    _value.VolatilePathPostfix = VolatilePathPostfix;
                }
                if (SystemRootPath.IsSet() == true) {
                    _value.SystemRootPath = SystemRootPath;
                }
                if (Precondition.IsSet() == true) {
                    _value.Precondition = Precondition;
                }
                if (Termination.IsSet() == true) {
                    _value.Termination = Termination;
                }
                if (Control.IsSet() == true) {
                    _value.Control = Control;
                }
                _value.Configuration = Configuration;
                _value.Observers = Observers;
                if (ProcessedRequests.IsSet() == true) {
                    _value.ProcessedRequests = ProcessedRequests;
                }
                if (ProcessedObjects.IsSet() == true) {
                    _value.ProcessedObjects = ProcessedObjects;
                }
                return (_value);
            }

            ~ServiceData() = default;

        public:
            bool IsDataValid() const
            {
                return ((Callsign.IsSet() == true) && (Locator.IsSet() == true) && (ClassName.IsSet() == true) && (Module.IsSet() == true) && (State.IsSet() == true) && (StartMode.IsSet() == true) && (Resumed.IsSet() == true) && ((Version.IsSet() == true) && (Version.IsDataValid() == true)) && (Observers.IsSet() == true));
            }

        private:
            void _Init()
            {
                Add(_T("callsign"), &Callsign);
                Add(_T("locator"), &Locator);
                Add(_T("classname"), &ClassName);
                Add(_T("module"), &Module);
                Add(_T("state"), &State);
                Add(_T("startmode"), &StartMode);
                Add(_T("resumed"), &Resumed);
                Add(_T("version"), &Version);
                Add(_T("communicator"), &Communicator);
                Add(_T("persistentpathpostfix"), &PersistentPathPostfix);
                Add(_T("volatilepathpostfix"), &VolatilePathPostfix);
                Add(_T("systemrootpath"), &SystemRootPath);
                Add(_T("precondition"), &Precondition);
                Precondition.SetQuoted(false);
                Add(_T("termination"), &Termination);
                Termination.SetQuoted(false);
                Add(_T("control"), &Control);
                Control.SetQuoted(false);
                Add(_T("configuration"), &Configuration);
                Configuration.SetQuoted(false);
                Add(_T("observers"), &Observers);
                Add(_T("processedrequests"), &ProcessedRequests);
                Add(_T("processedobjects"), &ProcessedObjects);
            }

        public:
            Core::JSON::String Callsign; // Plugin callsign
            Core::JSON::String Locator; // Shared library path
            Core::JSON::String ClassName; // Plugin class name
            Core::JSON::String Module; // Module name
            Core::JSON::EnumType<Exchange::Controller::IMetadata::Data::Service::state> State; // Current state
            Core::JSON::EnumType<PluginHost::IShell::startmode> StartMode; // Startup mode
            Core::JSON::Boolean Resumed; // Determines if the plugin is to be activated in resumed or suspended mode
            VersionInfo Version; // Version
            Core::JSON::String Communicator; // Communicator
            Core::JSON::String PersistentPathPostfix; // Postfix of persistent path
            Core::JSON::String VolatilePathPostfix; // Postfix of volatile path
            Core::JSON::String SystemRootPath; // Path of system root
            Core::JSON::String Precondition; // Activation conditons
            Core::JSON::String Termination; // Deactivation conditions
            Core::JSON::String Control; // Conditions controlled by this service
            Core::JSON::String Configuration; // Plugin configuration
            Core::JSON::DecUInt16 Observers; // Number or observers
            Core::JSON::DecUInt32 ProcessedRequests; // Number of API requests that have been processed by the plugin
            Core::JSON::DecUInt32 ProcessedObjects; // Number of objects that have been processed by the plugin
        }; // class ServiceData

        class ThreadData : public Core::JSON::Container {
        public:
            ThreadData()
                : Core::JSON::Container()
            {
                _Init();
            }

            ThreadData(const ThreadData& _other)
                : Core::JSON::Container()
                , Id(_other.Id)
                , Job(_other.Job)
                , Runs(_other.Runs)
            {
                _Init();
            }

            ThreadData(ThreadData&& _other) noexcept
                : Core::JSON::Container()
                , Id(std::move(_other.Id))
                , Job(std::move(_other.Job))
                , Runs(std::move(_other.Runs))
            {
                _Init();
            }

            ThreadData(const Exchange::Controller::IMetadata::Data::Thread& _other)
                : Core::JSON::Container()
            {
                Id = _other.Id;
                Job = _other.Job;
                Runs = _other.Runs;
                _Init();
            }

            ThreadData& operator=(const ThreadData& _rhs)
            {
                Id = _rhs.Id;
                Job = _rhs.Job;
                Runs = _rhs.Runs;
                return (*this);
            }

            ThreadData& operator=(ThreadData&& _rhs) noexcept
            {
                Id = std::move(_rhs.Id);
                Job = std::move(_rhs.Job);
                Runs = std::move(_rhs.Runs);
                return (*this);
            }

            ThreadData& operator=(const Exchange::Controller::IMetadata::Data::Thread& _rhs)
            {
                Id = _rhs.Id;
                Job = _rhs.Job;
                Runs = _rhs.Runs;
                return (*this);
            }

            operator Exchange::Controller::IMetadata::Data::Thread() const
            {
                Exchange::Controller::IMetadata::Data::Thread _value{};
                _value.Id = Id;
                _value.Job = Job;
                _value.Runs = Runs;
                return (_value);
            }

            ~ThreadData() = default;

        public:
            bool IsDataValid() const
            {
                return ((Id.IsSet() == true) && (Job.IsSet() == true) && (Runs.IsSet() == true));
            }

        private:
            void _Init()
            {
                Add(_T("id"), &Id);
                Add(_T("job"), &Job);
                Add(_T("runs"), &Runs);
            }

        public:
            Core::JSON::InstanceId Id; // Thread ID
            Core::JSON::String Job; // Job name
            Core::JSON::DecUInt32 Runs; // Number of runs
        }; // class ThreadData

    } // namespace Metadata

    POP_WARNING()

} // namespace JsonData

// Enum conversion handlers
ENUM_CONVERSION_HANDLER(PluginHost::IShell::state)
ENUM_CONVERSION_HANDLER(PluginHost::IShell::reason)
ENUM_CONVERSION_HANDLER(Exchange::Controller::ILifeTime::state)
ENUM_CONVERSION_HANDLER(PluginHost::ISubSystem::subsystem)
ENUM_CONVERSION_HANDLER(Exchange::Controller::IMetadata::Data::Service::state)
ENUM_CONVERSION_HANDLER(PluginHost::IShell::startmode)
ENUM_CONVERSION_HANDLER(Exchange::Controller::IMetadata::Data::Link::state)
ENUM_CONVERSION_HANDLER(Exchange::Controller::IMetadata::Data::BuildInfo::systemtype)
ENUM_CONVERSION_HANDLER(Exchange::Controller::IMetadata::Data::BuildInfo::buildtype)
ENUM_CONVERSION_HANDLER(Exchange::Controller::IMetadata::Data::BuildInfo::extensiontype)

}

