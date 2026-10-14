// Enumeration code for ZigWave API.
// Generated automatically from 'IZigWave.h'.

#include <core/Enumerate.h>

#include "definitions.h"
#include <interfaces/IZigWave.h>
#include "JsonData_ZigWave.h"

namespace Thunder {

ENUM_CONVERSION_BEGIN(Exchange::IZigWave::Device::type)
    { Exchange::IZigWave::Device::type::END_DEVICE, _TXT("END_DEVICE") },
    { Exchange::IZigWave::Device::type::ROUTER, _TXT("ROUTER") },
    { Exchange::IZigWave::Device::type::CONTROLLER, _TXT("CONTROLLER") },
ENUM_CONVERSION_END(Exchange::IZigWave::Device::type)

}
