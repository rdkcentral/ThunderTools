// Enumeration code for Dictionary API.
// Generated automatically from 'IDictionary.h'.

#include <core/Enumerate.h>

#include "definitions.h"
#include <interfaces/IDictionary.h>
#include "JsonData_Dictionary.h"

namespace Thunder {

ENUM_CONVERSION_BEGIN(Exchange::IDictionary::Type)
    { Exchange::IDictionary::Type::NAMESPACE, _TXT("Namespace") },
    { Exchange::IDictionary::Type::PERSISTENT_KEY, _TXT("PersistentKey") },
    { Exchange::IDictionary::Type::VOLATILE_KEY, _TXT("VolatileKey") },
ENUM_CONVERSION_END(Exchange::IDictionary::Type)

}
