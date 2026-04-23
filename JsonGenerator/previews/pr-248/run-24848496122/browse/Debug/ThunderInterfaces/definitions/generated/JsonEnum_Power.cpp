// Enumeration code for Power API.
// Generated automatically from 'IPower.h'.

#include <core/Enumerate.h>

#include "definitions.h"
#include <interfaces/IPower.h>
#include "JsonData_Power.h"

namespace Thunder {

ENUM_CONVERSION_BEGIN(Exchange::IPower::PCState)
    { Exchange::IPower::PCState::On, _TXT("On") },
    { Exchange::IPower::PCState::ActiveStandby, _TXT("ActiveStandby") },
    { Exchange::IPower::PCState::PassiveStandby, _TXT("PassiveStandby") },
    { Exchange::IPower::PCState::SuspendToRAM, _TXT("SuspendToRAM") },
    { Exchange::IPower::PCState::Hibernate, _TXT("Hibernate") },
    { Exchange::IPower::PCState::PowerOff, _TXT("PowerOff") },
ENUM_CONVERSION_END(Exchange::IPower::PCState)

ENUM_CONVERSION_BEGIN(Exchange::IPower::PCPhase)
    { Exchange::IPower::PCPhase::Before, _TXT("Before") },
    { Exchange::IPower::PCPhase::After, _TXT("After") },
ENUM_CONVERSION_END(Exchange::IPower::PCPhase)

}
