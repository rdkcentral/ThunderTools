from typing import List


def convertToBaseName(interface: str) -> str:
    """
    Example:
        IWifiControl -> WifiControl
        JWifiControl -> WifiControl
        WifiControl -> WifiControl
    """
    return interface[1:] if interface.startswith("I") or interface.startswith("J") else interface

def convertToJSONRPC(interface: str) -> str:
    """
    Example:
        IWifiControl -> JWifiControl
        WifiControl -> JWifiControl
    """
    return "J" + convertToBaseName(interface)

def convertToCOMRPC(interface: str) -> str:
    """
    Example:
        JWifiControl -> IWifiControl
        WifiControl -> IWifiControl
    """
    return "I" + convertToBaseName(interface)

def generateSimpleText(lines: List[str], remove_empty: bool = True, sep: str = "\n") -> str:
    if remove_empty:
        lines = [line for line in lines if line.strip()]
    return sep.join(lines)