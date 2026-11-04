// Enumeration code for Messenger API.
// Generated automatically from 'IMessenger.h'.

#include <core/Enumerate.h>

#include "definitions.h"
#include <interfaces/IMessenger.h>
#include "JsonData_Messenger.h"

namespace Thunder {

ENUM_CONVERSION_BEGIN(Exchange::JSONRPC::IMessenger::security)
    { Exchange::JSONRPC::IMessenger::security::INSECURE, _TXT("insecure") },
    { Exchange::JSONRPC::IMessenger::security::SECURE, _TXT("secure") },
ENUM_CONVERSION_END(Exchange::JSONRPC::IMessenger::security)

ENUM_CONVERSION_BEGIN(Exchange::JSONRPC::IMessenger::INotification::roomupdate)
    { Exchange::JSONRPC::IMessenger::INotification::roomupdate::CREATED, _TXT("created") },
    { Exchange::JSONRPC::IMessenger::INotification::roomupdate::DESTROYED, _TXT("destroyed") },
ENUM_CONVERSION_END(Exchange::JSONRPC::IMessenger::INotification::roomupdate)

ENUM_CONVERSION_BEGIN(Exchange::JSONRPC::IMessenger::INotification::userupdate)
    { Exchange::JSONRPC::IMessenger::INotification::userupdate::JOINED, _TXT("joined") },
    { Exchange::JSONRPC::IMessenger::INotification::userupdate::LEFT, _TXT("left") },
ENUM_CONVERSION_END(Exchange::JSONRPC::IMessenger::INotification::userupdate)

}
