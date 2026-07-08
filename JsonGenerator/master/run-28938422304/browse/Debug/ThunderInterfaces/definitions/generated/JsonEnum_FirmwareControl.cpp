// Enumeration code for Firmware Control API.
// Generated automatically from 'FirmwareControl.json'.

#include <core/Enumerate.h>

#include "definitions.h"
#include "JsonData_FirmwareControl.h"

namespace Thunder {

ENUM_CONVERSION_BEGIN(JsonData::FirmwareControl::UpgradeParamsData::TypeType)
    { JsonData::FirmwareControl::UpgradeParamsData::TypeType::CDL, _TXT("CDL") },
    { JsonData::FirmwareControl::UpgradeParamsData::TypeType::RCDL, _TXT("RCDL") },
ENUM_CONVERSION_END(JsonData::FirmwareControl::UpgradeParamsData::TypeType)

ENUM_CONVERSION_BEGIN(JsonData::FirmwareControl::StatusType)
    { JsonData::FirmwareControl::StatusType::NONE, _TXT("none") },
    { JsonData::FirmwareControl::StatusType::UPGRADESTARTED, _TXT("upgradestarted") },
    { JsonData::FirmwareControl::StatusType::DOWNLOADSTARTED, _TXT("downloadstarted") },
    { JsonData::FirmwareControl::StatusType::DOWNLOADABORTED, _TXT("downloadaborted") },
    { JsonData::FirmwareControl::StatusType::DOWNLOADCOMPLETED, _TXT("downloadcompleted") },
    { JsonData::FirmwareControl::StatusType::INSTALLINITIATED, _TXT("installinitiated") },
    { JsonData::FirmwareControl::StatusType::INSTALLNOTSTARTED, _TXT("installnotstarted") },
    { JsonData::FirmwareControl::StatusType::INSTALLABORTED, _TXT("installaborted") },
    { JsonData::FirmwareControl::StatusType::INSTALLSTARTED, _TXT("installstarted") },
    { JsonData::FirmwareControl::StatusType::UPGRADECOMPLETED, _TXT("upgradecompleted") },
    { JsonData::FirmwareControl::StatusType::UPGRADECANCELLED, _TXT("upgradecancelled") },
ENUM_CONVERSION_END(JsonData::FirmwareControl::StatusType)

ENUM_CONVERSION_BEGIN(JsonData::FirmwareControl::UpgradeprogressParamsData::ErrorType)
    { JsonData::FirmwareControl::UpgradeprogressParamsData::ErrorType::NONE, _TXT("none") },
    { JsonData::FirmwareControl::UpgradeprogressParamsData::ErrorType::GENERIC, _TXT("generic") },
    { JsonData::FirmwareControl::UpgradeprogressParamsData::ErrorType::INVALIDPARAMETERS, _TXT("invalidparameters") },
    { JsonData::FirmwareControl::UpgradeprogressParamsData::ErrorType::INVALIDSTATE, _TXT("invalidstate") },
    { JsonData::FirmwareControl::UpgradeprogressParamsData::ErrorType::NOENOUGHSPACE, _TXT("noenoughspace") },
    { JsonData::FirmwareControl::UpgradeprogressParamsData::ErrorType::OPERATIONOTSUPPORTED, _TXT("operationotsupported") },
    { JsonData::FirmwareControl::UpgradeprogressParamsData::ErrorType::INCORRECTHASH, _TXT("incorrecthash") },
    { JsonData::FirmwareControl::UpgradeprogressParamsData::ErrorType::UNAUTHENTICATED, _TXT("unauthenticated") },
    { JsonData::FirmwareControl::UpgradeprogressParamsData::ErrorType::UNAVAILABLE, _TXT("unavailable") },
    { JsonData::FirmwareControl::UpgradeprogressParamsData::ErrorType::TIMEDOUT, _TXT("timedout") },
    { JsonData::FirmwareControl::UpgradeprogressParamsData::ErrorType::DOWNLOADDIRECTORYNOTEXIST, _TXT("downloaddirectorynotexist") },
    { JsonData::FirmwareControl::UpgradeprogressParamsData::ErrorType::RESUMENOTSUPPORTED, _TXT("resumenotsupported") },
    { JsonData::FirmwareControl::UpgradeprogressParamsData::ErrorType::INVALIDRANGE, _TXT("invalidrange") },
    { JsonData::FirmwareControl::UpgradeprogressParamsData::ErrorType::UNKOWN, _TXT("unkown") },
ENUM_CONVERSION_END(JsonData::FirmwareControl::UpgradeprogressParamsData::ErrorType)

}
