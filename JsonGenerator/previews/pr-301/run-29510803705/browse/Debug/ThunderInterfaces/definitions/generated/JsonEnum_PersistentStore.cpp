// Enumeration code for PertsistentStore API.
// Generated automatically from 'PersistentStore.json'.

#include <core/Enumerate.h>

#include "definitions.h"
#include "JsonData_PersistentStore.h"

namespace Thunder {

ENUM_CONVERSION_BEGIN(JsonData::PersistentStore::ScopeType)
    { JsonData::PersistentStore::ScopeType::DEVICE, _TXT("device") },
    { JsonData::PersistentStore::ScopeType::ACCOUNT, _TXT("account") },
ENUM_CONVERSION_END(JsonData::PersistentStore::ScopeType)

}
