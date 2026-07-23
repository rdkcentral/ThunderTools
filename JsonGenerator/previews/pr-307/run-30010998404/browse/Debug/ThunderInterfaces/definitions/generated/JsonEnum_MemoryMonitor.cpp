// Enumeration code for MemoryMonitor API.
// Generated automatically from 'IMemoryMonitor.h'.

#include <core/Enumerate.h>

#include "definitions.h"
#include <interfaces/IMemoryMonitor.h>
#include "JsonData_MemoryMonitor.h"

namespace Thunder {

ENUM_CONVERSION_BEGIN(Exchange::IMemoryMonitor::INotification::action)
    { Exchange::IMemoryMonitor::INotification::action::DEACTIVATED, _TXT("Deactivated") },
    { Exchange::IMemoryMonitor::INotification::action::ACTIVATED, _TXT("Activated") },
    { Exchange::IMemoryMonitor::INotification::action::RESTARTING_STOPPED, _TXT("RestartingStopped") },
ENUM_CONVERSION_END(Exchange::IMemoryMonitor::INotification::action)

ENUM_CONVERSION_BEGIN(Exchange::IMemoryMonitor::INotification::reason)
    { Exchange::IMemoryMonitor::INotification::reason::EXCEEDED_MEMORY, _TXT("ExceededMemory") },
    { Exchange::IMemoryMonitor::INotification::reason::NOT_OPERATIONAL, _TXT("NotOperational") },
ENUM_CONVERSION_END(Exchange::IMemoryMonitor::INotification::reason)

}
