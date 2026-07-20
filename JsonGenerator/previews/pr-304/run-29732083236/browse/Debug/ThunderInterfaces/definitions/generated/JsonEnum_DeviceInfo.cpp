// Enumeration code for Device Info API.
// Generated automatically from 'DeviceInfo.json'.

#include <core/Enumerate.h>

#include "definitions.h"
#include "JsonData_DeviceInfo.h"

namespace Thunder {

ENUM_CONVERSION_BEGIN(JsonData::DeviceInfo::VideodisplayType)
    { JsonData::DeviceInfo::VideodisplayType::OTHER, _TXT("OTHER") },
    { JsonData::DeviceInfo::VideodisplayType::RF_MODULATOR, _TXT("RF_MODULATOR") },
    { JsonData::DeviceInfo::VideodisplayType::COMPOSITE, _TXT("COMPOSITE") },
    { JsonData::DeviceInfo::VideodisplayType::SVIDEO, _TXT("SVIDEO") },
    { JsonData::DeviceInfo::VideodisplayType::COMPONET, _TXT("COMPONET") },
    { JsonData::DeviceInfo::VideodisplayType::SCART_RGB, _TXT("SCART_RGB") },
    { JsonData::DeviceInfo::VideodisplayType::HDMI0, _TXT("HDMI0") },
    { JsonData::DeviceInfo::VideodisplayType::HDMI1, _TXT("HDMI1") },
    { JsonData::DeviceInfo::VideodisplayType::DISPLAYPORT, _TXT("DISPLAYPORT") },
ENUM_CONVERSION_END(JsonData::DeviceInfo::VideodisplayType)

ENUM_CONVERSION_BEGIN(JsonData::DeviceInfo::Output_resolutionType)
    { JsonData::DeviceInfo::Output_resolutionType::UNKNOWN, _TXT("unknown") },
    { JsonData::DeviceInfo::Output_resolutionType::E480I, _TXT("480i") },
    { JsonData::DeviceInfo::Output_resolutionType::E480P, _TXT("480p") },
    { JsonData::DeviceInfo::Output_resolutionType::E576I, _TXT("576i") },
    { JsonData::DeviceInfo::Output_resolutionType::E576P, _TXT("576p") },
    { JsonData::DeviceInfo::Output_resolutionType::E576P50, _TXT("576p50") },
    { JsonData::DeviceInfo::Output_resolutionType::E720P, _TXT("720p") },
    { JsonData::DeviceInfo::Output_resolutionType::E720P24, _TXT("720p24") },
    { JsonData::DeviceInfo::Output_resolutionType::E720P25, _TXT("720p25") },
    { JsonData::DeviceInfo::Output_resolutionType::E720P30, _TXT("720p30") },
    { JsonData::DeviceInfo::Output_resolutionType::E720P50, _TXT("720p50") },
    { JsonData::DeviceInfo::Output_resolutionType::E720P60, _TXT("720p60") },
    { JsonData::DeviceInfo::Output_resolutionType::E1080I, _TXT("1080i") },
    { JsonData::DeviceInfo::Output_resolutionType::E1080I25, _TXT("1080i25") },
    { JsonData::DeviceInfo::Output_resolutionType::E1080I50, _TXT("1080i50") },
    { JsonData::DeviceInfo::Output_resolutionType::E1080I60, _TXT("1080i60") },
    { JsonData::DeviceInfo::Output_resolutionType::E1080P, _TXT("1080p") },
    { JsonData::DeviceInfo::Output_resolutionType::E1080P24, _TXT("1080p24") },
    { JsonData::DeviceInfo::Output_resolutionType::E1080P25, _TXT("1080p25") },
    { JsonData::DeviceInfo::Output_resolutionType::E1080P30, _TXT("1080p30") },
    { JsonData::DeviceInfo::Output_resolutionType::E1080P50, _TXT("1080p50") },
    { JsonData::DeviceInfo::Output_resolutionType::E1080P60, _TXT("1080p60") },
    { JsonData::DeviceInfo::Output_resolutionType::E2160P24, _TXT("2160p24") },
    { JsonData::DeviceInfo::Output_resolutionType::E2160P25, _TXT("2160p25") },
    { JsonData::DeviceInfo::Output_resolutionType::E2160P30, _TXT("2160p30") },
    { JsonData::DeviceInfo::Output_resolutionType::E2160P50, _TXT("2160p50") },
    { JsonData::DeviceInfo::Output_resolutionType::E2160P60, _TXT("2160p60") },
    { JsonData::DeviceInfo::Output_resolutionType::E4320P30, _TXT("4320p30") },
    { JsonData::DeviceInfo::Output_resolutionType::E4320P60, _TXT("4320p60") },
ENUM_CONVERSION_END(JsonData::DeviceInfo::Output_resolutionType)

ENUM_CONVERSION_BEGIN(JsonData::DeviceInfo::CopyprotectionType)
    { JsonData::DeviceInfo::CopyprotectionType::HDCP_UNAVAILABLE, _TXT("unavailable") },
    { JsonData::DeviceInfo::CopyprotectionType::HDCP_14, _TXT("1.4") },
    { JsonData::DeviceInfo::CopyprotectionType::HDCP_20, _TXT("2.0") },
    { JsonData::DeviceInfo::CopyprotectionType::HDCP_21, _TXT("2.1") },
    { JsonData::DeviceInfo::CopyprotectionType::HDCP_22, _TXT("2.2") },
ENUM_CONVERSION_END(JsonData::DeviceInfo::CopyprotectionType)

ENUM_CONVERSION_BEGIN(JsonData::DeviceInfo::AudioportType)
    { JsonData::DeviceInfo::AudioportType::OTHER, _TXT("OTHER") },
    { JsonData::DeviceInfo::AudioportType::RF_MODULATOR, _TXT("RF_MODULATOR") },
    { JsonData::DeviceInfo::AudioportType::ANALOG, _TXT("ANALOG") },
    { JsonData::DeviceInfo::AudioportType::SPDIF0, _TXT("SPDIF0") },
    { JsonData::DeviceInfo::AudioportType::HDMI0, _TXT("HDMI0") },
    { JsonData::DeviceInfo::AudioportType::HDMI1, _TXT("HDMI1") },
    { JsonData::DeviceInfo::AudioportType::DISPLAYPORT, _TXT("DISPLAYPORT") },
ENUM_CONVERSION_END(JsonData::DeviceInfo::AudioportType)

ENUM_CONVERSION_BEGIN(JsonData::DeviceInfo::AudiocapabilityType)
    { JsonData::DeviceInfo::AudiocapabilityType::NONE, _TXT("none") },
    { JsonData::DeviceInfo::AudiocapabilityType::ATMOS, _TXT("ATMOS") },
    { JsonData::DeviceInfo::AudiocapabilityType::DD, _TXT("DOLBY DIGITAL") },
    { JsonData::DeviceInfo::AudiocapabilityType::DDPLUS, _TXT("DOLBY DIGITAL PLUS") },
    { JsonData::DeviceInfo::AudiocapabilityType::DAD, _TXT("Dual Audio Decode") },
    { JsonData::DeviceInfo::AudiocapabilityType::DAPV2, _TXT("DAPv2") },
    { JsonData::DeviceInfo::AudiocapabilityType::MS12, _TXT("MS12") },
ENUM_CONVERSION_END(JsonData::DeviceInfo::AudiocapabilityType)

ENUM_CONVERSION_BEGIN(JsonData::DeviceInfo::Ms12capabilityType)
    { JsonData::DeviceInfo::Ms12capabilityType::NONE, _TXT("none") },
    { JsonData::DeviceInfo::Ms12capabilityType::DOLBYVOLUME, _TXT("Dolby Volume") },
    { JsonData::DeviceInfo::Ms12capabilityType::INTELIGENTEQUALIZER, _TXT("Inteligent Equalizer") },
    { JsonData::DeviceInfo::Ms12capabilityType::DIALOGUEENHANCER, _TXT("Dialogue Enhancer") },
ENUM_CONVERSION_END(JsonData::DeviceInfo::Ms12capabilityType)

ENUM_CONVERSION_BEGIN(JsonData::DeviceInfo::Ms12profileType)
    { JsonData::DeviceInfo::Ms12profileType::NONE, _TXT("None") },
    { JsonData::DeviceInfo::Ms12profileType::MUSIC, _TXT("Music") },
    { JsonData::DeviceInfo::Ms12profileType::MOVIE, _TXT("Movie") },
    { JsonData::DeviceInfo::Ms12profileType::VOICE, _TXT("Voice") },
ENUM_CONVERSION_END(JsonData::DeviceInfo::Ms12profileType)

ENUM_CONVERSION_BEGIN(JsonData::DeviceInfo::FirmwareversionData::YoctoType)
    { JsonData::DeviceInfo::FirmwareversionData::YoctoType::DUNFELL, _TXT("dunfell") },
    { JsonData::DeviceInfo::FirmwareversionData::YoctoType::MORTY, _TXT("morty") },
    { JsonData::DeviceInfo::FirmwareversionData::YoctoType::DAISY, _TXT("daisy") },
    { JsonData::DeviceInfo::FirmwareversionData::YoctoType::KIRKSTONE, _TXT("kirkstone") },
ENUM_CONVERSION_END(JsonData::DeviceInfo::FirmwareversionData::YoctoType)

ENUM_CONVERSION_BEGIN(JsonData::DeviceInfo::MakeData::MakeType)
    { JsonData::DeviceInfo::MakeData::MakeType::PLATCO, _TXT("platco") },
    { JsonData::DeviceInfo::MakeData::MakeType::LLAMA, _TXT("llama") },
    { JsonData::DeviceInfo::MakeData::MakeType::HISENSE, _TXT("hisense") },
    { JsonData::DeviceInfo::MakeData::MakeType::ELEMENT, _TXT("element") },
    { JsonData::DeviceInfo::MakeData::MakeType::SKY, _TXT("sky") },
    { JsonData::DeviceInfo::MakeData::MakeType::SERCOMM, _TXT("sercomm") },
    { JsonData::DeviceInfo::MakeData::MakeType::COMMSCOPE, _TXT("commscope") },
    { JsonData::DeviceInfo::MakeData::MakeType::ARRIS, _TXT("arris") },
    { JsonData::DeviceInfo::MakeData::MakeType::CISCO, _TXT("cisco") },
    { JsonData::DeviceInfo::MakeData::MakeType::PACE, _TXT("pace") },
    { JsonData::DeviceInfo::MakeData::MakeType::SAMSUNG, _TXT("samsung") },
    { JsonData::DeviceInfo::MakeData::MakeType::TECHNICOLOR, _TXT("technicolor") },
    { JsonData::DeviceInfo::MakeData::MakeType::AMLOGIC_INC, _TXT("Amlogic_Inc") },
    { JsonData::DeviceInfo::MakeData::MakeType::RASPBERRYPI_ORG, _TXT("raspberrypi_org") },
    { JsonData::DeviceInfo::MakeData::MakeType::PIONEER, _TXT("Pioneer") },
ENUM_CONVERSION_END(JsonData::DeviceInfo::MakeData::MakeType)

ENUM_CONVERSION_BEGIN(JsonData::DeviceInfo::ModelidData::SkuType)
    { JsonData::DeviceInfo::ModelidData::SkuType::PLTL11AEI, _TXT("PLTL11AEI") },
    { JsonData::DeviceInfo::ModelidData::SkuType::ZWCN11MWI, _TXT("ZWCN11MWI") },
    { JsonData::DeviceInfo::ModelidData::SkuType::SKTL11AEI, _TXT("SKTL11AEI") },
    { JsonData::DeviceInfo::ModelidData::SkuType::LS301, _TXT("LS301") },
    { JsonData::DeviceInfo::ModelidData::SkuType::HSTP11MWR, _TXT("HSTP11MWR") },
    { JsonData::DeviceInfo::ModelidData::SkuType::HSTP11MWRFX50, _TXT("HSTP11MWRFX50") },
    { JsonData::DeviceInfo::ModelidData::SkuType::ELTE11MWR, _TXT("ELTE11MWR") },
    { JsonData::DeviceInfo::ModelidData::SkuType::SKXI11ADS, _TXT("SKXI11ADS") },
    { JsonData::DeviceInfo::ModelidData::SkuType::SKXI11AIS, _TXT("SKXI11AIS") },
    { JsonData::DeviceInfo::ModelidData::SkuType::SKXI11ANS, _TXT("SKXI11ANS") },
    { JsonData::DeviceInfo::ModelidData::SkuType::SCXI11AIC, _TXT("SCXI11AIC") },
    { JsonData::DeviceInfo::ModelidData::SkuType::SCXI11BEI, _TXT("SCXI11BEI") },
    { JsonData::DeviceInfo::ModelidData::SkuType::CMXI11BEI, _TXT("CMXI11BEI") },
    { JsonData::DeviceInfo::ModelidData::SkuType::AX013AN, _TXT("AX013AN") },
    { JsonData::DeviceInfo::ModelidData::SkuType::AX014AN, _TXT("AX014AN") },
    { JsonData::DeviceInfo::ModelidData::SkuType::AX061AEI, _TXT("AX061AEI") },
    { JsonData::DeviceInfo::ModelidData::SkuType::MX011AN, _TXT("MX011AN") },
    { JsonData::DeviceInfo::ModelidData::SkuType::CS011AN, _TXT("CS011AN") },
    { JsonData::DeviceInfo::ModelidData::SkuType::CXD01ANI, _TXT("CXD01ANI") },
    { JsonData::DeviceInfo::ModelidData::SkuType::PX001AN, _TXT("PX001AN") },
    { JsonData::DeviceInfo::ModelidData::SkuType::PX013AN, _TXT("PX013AN") },
    { JsonData::DeviceInfo::ModelidData::SkuType::PX022AN, _TXT("PX022AN") },
    { JsonData::DeviceInfo::ModelidData::SkuType::PX032ANI, _TXT("PX032ANI") },
    { JsonData::DeviceInfo::ModelidData::SkuType::PX051AEI, _TXT("PX051AEI") },
    { JsonData::DeviceInfo::ModelidData::SkuType::PXD01ANI, _TXT("PXD01ANI") },
    { JsonData::DeviceInfo::ModelidData::SkuType::SX022AN, _TXT("SX022AN") },
    { JsonData::DeviceInfo::ModelidData::SkuType::TX061AEI, _TXT("TX061AEI") },
    { JsonData::DeviceInfo::ModelidData::SkuType::PI, _TXT("PI") },
    { JsonData::DeviceInfo::ModelidData::SkuType::XUSHTC11MWR, _TXT("XUSHTC11MWR") },
    { JsonData::DeviceInfo::ModelidData::SkuType::XUSPTC11MWR, _TXT("XUSPTC11MWR") },
    { JsonData::DeviceInfo::ModelidData::SkuType::XUSHTB11MWR, _TXT("XUSHTB11MWR") },
    { JsonData::DeviceInfo::ModelidData::SkuType::PITU11MWR, _TXT("PITU11MWR") },
ENUM_CONVERSION_END(JsonData::DeviceInfo::ModelidData::SkuType)

ENUM_CONVERSION_BEGIN(JsonData::DeviceInfo::DevicetypeData::DevicetypeType)
    { JsonData::DeviceInfo::DevicetypeData::DevicetypeType::TV, _TXT("tv") },
    { JsonData::DeviceInfo::DevicetypeData::DevicetypeType::IPSTB, _TXT("IpStb") },
    { JsonData::DeviceInfo::DevicetypeData::DevicetypeType::QAMIPSTB, _TXT("QamIpStb") },
    { JsonData::DeviceInfo::DevicetypeData::DevicetypeType::HYBRID, _TXT("hybrid") },
    { JsonData::DeviceInfo::DevicetypeData::DevicetypeType::MEDIACLIENT, _TXT("mediaclient") },
ENUM_CONVERSION_END(JsonData::DeviceInfo::DevicetypeData::DevicetypeType)

ENUM_CONVERSION_BEGIN(JsonData::DeviceInfo::DistributoridData::DistributoridType)
    { JsonData::DeviceInfo::DistributoridData::DistributoridType::COMCAST, _TXT("comcast") },
    { JsonData::DeviceInfo::DistributoridData::DistributoridType::XGLOBAL, _TXT("xglobal") },
    { JsonData::DeviceInfo::DistributoridData::DistributoridType::SKY_DE, _TXT("sky-de") },
    { JsonData::DeviceInfo::DistributoridData::DistributoridType::SKY_ITALIA, _TXT("sky-italia") },
    { JsonData::DeviceInfo::DistributoridData::DistributoridType::SKY_UK, _TXT("sky-uk") },
    { JsonData::DeviceInfo::DistributoridData::DistributoridType::SKY_UK_DEV, _TXT("sky-uk-dev") },
    { JsonData::DeviceInfo::DistributoridData::DistributoridType::SKY_DEU, _TXT("sky-deu") },
    { JsonData::DeviceInfo::DistributoridData::DistributoridType::SKY_DEU_DEV, _TXT("sky-deu-dev") },
    { JsonData::DeviceInfo::DistributoridData::DistributoridType::SKY_IT, _TXT("sky-it") },
    { JsonData::DeviceInfo::DistributoridData::DistributoridType::SKY_IT_DEV, _TXT("sky-it-dev") },
    { JsonData::DeviceInfo::DistributoridData::DistributoridType::COX, _TXT("cox") },
    { JsonData::DeviceInfo::DistributoridData::DistributoridType::COX_HOSPITALITY, _TXT("cox-hospitality") },
    { JsonData::DeviceInfo::DistributoridData::DistributoridType::COX_DEV, _TXT("cox-dev") },
    { JsonData::DeviceInfo::DistributoridData::DistributoridType::COX_QA, _TXT("cox-qa") },
    { JsonData::DeviceInfo::DistributoridData::DistributoridType::MIT, _TXT("MIT") },
    { JsonData::DeviceInfo::DistributoridData::DistributoridType::SHAW, _TXT("shaw") },
    { JsonData::DeviceInfo::DistributoridData::DistributoridType::SHAW_DEV, _TXT("shaw-dev") },
    { JsonData::DeviceInfo::DistributoridData::DistributoridType::ROGERS, _TXT("rogers") },
    { JsonData::DeviceInfo::DistributoridData::DistributoridType::ROGERS_DEV, _TXT("rogers-dev") },
    { JsonData::DeviceInfo::DistributoridData::DistributoridType::VIDEOTRON, _TXT("videotron") },
    { JsonData::DeviceInfo::DistributoridData::DistributoridType::CHARTER, _TXT("charter") },
    { JsonData::DeviceInfo::DistributoridData::DistributoridType::CHARTER_DEV, _TXT("charter-dev") },
ENUM_CONVERSION_END(JsonData::DeviceInfo::DistributoridData::DistributoridType)

}
