// Enumeration code for LifeTime API JSON-RPC API.
// Generated automatically from 'IController.h'.

#include <core/Enumerate.h>

#include "definitions.h"
#include "JsonData_LifeTime.h"

namespace WPEFramework {

ENUM_CONVERSION_BEGIN(PluginHost::IShell::state)
    { PluginHost::IShell::state::UNAVAILABLE, _TXT("Unavailable") },
    { PluginHost::IShell::state::DEACTIVATED, _TXT("Deactivated") },
    { PluginHost::IShell::state::DEACTIVATION, _TXT("Deactivation") },
    { PluginHost::IShell::state::ACTIVATED, _TXT("Activated") },
    { PluginHost::IShell::state::ACTIVATION, _TXT("Activation") },
    { PluginHost::IShell::state::PRECONDITION, _TXT("Precondition") },
    { PluginHost::IShell::state::HIBERNATED, _TXT("Hibernated") },
    { PluginHost::IShell::state::DESTROYED, _TXT("Destroyed") },
ENUM_CONVERSION_END(PluginHost::IShell::state)

ENUM_CONVERSION_BEGIN(PluginHost::IShell::reason)
    { PluginHost::IShell::reason::REQUESTED, _TXT("Requested") },
    { PluginHost::IShell::reason::AUTOMATIC, _TXT("Automatic") },
    { PluginHost::IShell::reason::FAILURE, _TXT("Failure") },
    { PluginHost::IShell::reason::MEMORY_EXCEEDED, _TXT("MemoryExceeded") },
    { PluginHost::IShell::reason::STARTUP, _TXT("Startup") },
    { PluginHost::IShell::reason::SHUTDOWN, _TXT("Shutdown") },
    { PluginHost::IShell::reason::CONDITIONS, _TXT("Conditions") },
    { PluginHost::IShell::reason::WATCHDOG_EXPIRED, _TXT("WatchdogExpired") },
    { PluginHost::IShell::reason::INITIALIZATION_FAILED, _TXT("InitializationFailed") },
ENUM_CONVERSION_END(PluginHost::IShell::reason)

}
