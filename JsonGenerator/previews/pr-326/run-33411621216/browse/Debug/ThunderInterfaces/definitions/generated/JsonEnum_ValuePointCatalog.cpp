// Enumeration code for Catalog API.
// Generated automatically from 'IValuePoint.h'.

#include <core/Enumerate.h>

#include "definitions.h"
#include <interfaces/IValuePoint.h>
#include "JsonData_ValuePointCatalog.h"

namespace Thunder {

ENUM_CONVERSION_BEGIN(Exchange::IValuePoint::condition)
    { Exchange::IValuePoint::condition::constructing, _TXT("CONSTRUCTING") },
    { Exchange::IValuePoint::condition::activated, _TXT("ACTIVATED") },
    { Exchange::IValuePoint::condition::deactivated, _TXT("DEACTIVATED") },
ENUM_CONVERSION_END(Exchange::IValuePoint::condition)

ENUM_CONVERSION_BEGIN(Exchange::IValuePoint::basic)
    { Exchange::IValuePoint::basic::regulator, _TXT("REGULATOR") },
    { Exchange::IValuePoint::basic::measurement, _TXT("MEASUREMENT") },
    { Exchange::IValuePoint::basic::group, _TXT("GROUP") },
    { Exchange::IValuePoint::basic::identification, _TXT("IDENTIFICATION") },
ENUM_CONVERSION_END(Exchange::IValuePoint::basic)

ENUM_CONVERSION_BEGIN(Exchange::IValuePoint::specific)
    { Exchange::IValuePoint::specific::general, _TXT("GENERAL") },
    { Exchange::IValuePoint::specific::electricity, _TXT("ELECTRICITY") },
    { Exchange::IValuePoint::specific::water, _TXT("WATER") },
    { Exchange::IValuePoint::specific::gas, _TXT("GAS") },
    { Exchange::IValuePoint::specific::air, _TXT("AIR") },
    { Exchange::IValuePoint::specific::smoke, _TXT("SMOKE") },
    { Exchange::IValuePoint::specific::carbonMonoxide, _TXT("CARBON_MONOXIDE") },
    { Exchange::IValuePoint::specific::carbonDioxide, _TXT("CARBON_DIOXIDE") },
    { Exchange::IValuePoint::specific::temperature, _TXT("TEMPERATURE") },
    { Exchange::IValuePoint::specific::accessControl, _TXT("ACCESS_CONTROL") },
    { Exchange::IValuePoint::specific::burglar, _TXT("BURGLAR") },
    { Exchange::IValuePoint::specific::powerManagement, _TXT("POWER_MANAGEMENT") },
    { Exchange::IValuePoint::specific::system, _TXT("SYSTEM") },
    { Exchange::IValuePoint::specific::emergency, _TXT("EMERGENCY") },
    { Exchange::IValuePoint::specific::clock, _TXT("CLOCK") },
    { Exchange::IValuePoint::specific::light, _TXT("LIGHT") },
    { Exchange::IValuePoint::specific::humidity, _TXT("HUMIDITY") },
    { Exchange::IValuePoint::specific::pressure, _TXT("PRESSURE") },
ENUM_CONVERSION_END(Exchange::IValuePoint::specific)

ENUM_CONVERSION_BEGIN(Exchange::IValuePoint::dimension)
    { Exchange::IValuePoint::dimension::logic, _TXT("LOGIC") },
    { Exchange::IValuePoint::dimension::percentage, _TXT("PERCENTAGE") },
    { Exchange::IValuePoint::dimension::kwh, _TXT("KWH") },
    { Exchange::IValuePoint::dimension::kvah, _TXT("KVAH") },
    { Exchange::IValuePoint::dimension::pulses, _TXT("PULSES") },
    { Exchange::IValuePoint::dimension::degrees, _TXT("DEGREES") },
    { Exchange::IValuePoint::dimension::units, _TXT("UNITS") },
    { Exchange::IValuePoint::dimension::lux, _TXT("LUX") },
    { Exchange::IValuePoint::dimension::volt, _TXT("VOLT") },
    { Exchange::IValuePoint::dimension::ampere, _TXT("AMPERE") },
    { Exchange::IValuePoint::dimension::frequency, _TXT("FREQUENCY") },
ENUM_CONVERSION_END(Exchange::IValuePoint::dimension)

ENUM_CONVERSION_BEGIN(Exchange::IValuePoint::protocol)
    { Exchange::IValuePoint::protocol::unknown, _TXT("UNKNOWN") },
    { Exchange::IValuePoint::protocol::serial, _TXT("SERIAL") },
    { Exchange::IValuePoint::protocol::modbus, _TXT("MODBUS") },
    { Exchange::IValuePoint::protocol::mqtt, _TXT("MQTT") },
    { Exchange::IValuePoint::protocol::http, _TXT("HTTP") },
    { Exchange::IValuePoint::protocol::coap, _TXT("COAP") },
    { Exchange::IValuePoint::protocol::zigbee, _TXT("ZIGBEE") },
    { Exchange::IValuePoint::protocol::zwave, _TXT("ZWAVE") },
    { Exchange::IValuePoint::protocol::bluetooth, _TXT("BLUETOOTH") },
    { Exchange::IValuePoint::protocol::hardware, _TXT("HARDWARE") },
    { Exchange::IValuePoint::protocol::onewire, _TXT("ONEWIRE") },
    { Exchange::IValuePoint::protocol::i2c, _TXT("I2C") },
    { Exchange::IValuePoint::protocol::spi, _TXT("SPI") },
    { Exchange::IValuePoint::protocol::nrf24, _TXT("NRF24") },
    { Exchange::IValuePoint::protocol::virtuals, _TXT("VIRTUALS") },
ENUM_CONVERSION_END(Exchange::IValuePoint::protocol)

}
