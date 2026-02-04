// Enumeration code for DisplayProperties API.
// Generated automatically from 'IDisplayInfo.h'.

#include <core/Enumerate.h>

#include "definitions.h"
#include <interfaces/IDisplayInfo.h>
#include "JsonData_DisplayProperties.h"

namespace Thunder {

ENUM_CONVERSION_BEGIN(Exchange::IDisplayProperties::ColourSpaceType)
    { Exchange::IDisplayProperties::ColourSpaceType::FORMAT_UNKNOWN, _TXT("FormatUnknown") },
    { Exchange::IDisplayProperties::ColourSpaceType::FORMAT_OTHER, _TXT("FormatOther") },
    { Exchange::IDisplayProperties::ColourSpaceType::FORMAT_RGB_444, _TXT("FormatRgb444") },
    { Exchange::IDisplayProperties::ColourSpaceType::FORMAT_YCBCR_444, _TXT("FormatYcbcr444") },
    { Exchange::IDisplayProperties::ColourSpaceType::FORMAT_YCBCR_422, _TXT("FormatYcbcr422") },
    { Exchange::IDisplayProperties::ColourSpaceType::FORMAT_YCBCR_420, _TXT("FormatYcbcr420") },
ENUM_CONVERSION_END(Exchange::IDisplayProperties::ColourSpaceType)

ENUM_CONVERSION_BEGIN(Exchange::IDisplayProperties::FrameRateType)
    { Exchange::IDisplayProperties::FrameRateType::FRAMERATE_UNKNOWN, _TXT("FramerateUnknown") },
    { Exchange::IDisplayProperties::FrameRateType::FRAMERATE_23_976, _TXT("Framerate23976") },
    { Exchange::IDisplayProperties::FrameRateType::FRAMERATE_24, _TXT("Framerate24") },
    { Exchange::IDisplayProperties::FrameRateType::FRAMERATE_25, _TXT("Framerate25") },
    { Exchange::IDisplayProperties::FrameRateType::FRAMERATE_29_97, _TXT("Framerate2997") },
    { Exchange::IDisplayProperties::FrameRateType::FRAMERATE_30, _TXT("Framerate30") },
    { Exchange::IDisplayProperties::FrameRateType::FRAMERATE_47_952, _TXT("Framerate47952") },
    { Exchange::IDisplayProperties::FrameRateType::FRAMERATE_48, _TXT("Framerate48") },
    { Exchange::IDisplayProperties::FrameRateType::FRAMERATE_50, _TXT("Framerate50") },
    { Exchange::IDisplayProperties::FrameRateType::FRAMERATE_59_94, _TXT("Framerate5994") },
    { Exchange::IDisplayProperties::FrameRateType::FRAMERATE_60, _TXT("Framerate60") },
    { Exchange::IDisplayProperties::FrameRateType::FRAMERATE_119_88, _TXT("Framerate11988") },
    { Exchange::IDisplayProperties::FrameRateType::FRAMERATE_120, _TXT("Framerate120") },
    { Exchange::IDisplayProperties::FrameRateType::FRAMERATE_144, _TXT("Framerate144") },
ENUM_CONVERSION_END(Exchange::IDisplayProperties::FrameRateType)

ENUM_CONVERSION_BEGIN(Exchange::IDisplayProperties::ColourDepthType)
    { Exchange::IDisplayProperties::ColourDepthType::COLORDEPTH_UNKNOWN, _TXT("ColordepthUnknown") },
    { Exchange::IDisplayProperties::ColourDepthType::COLORDEPTH_8_BIT, _TXT("Colordepth8Bit") },
    { Exchange::IDisplayProperties::ColourDepthType::COLORDEPTH_10_BIT, _TXT("Colordepth10Bit") },
    { Exchange::IDisplayProperties::ColourDepthType::COLORDEPTH_12_BIT, _TXT("Colordepth12Bit") },
ENUM_CONVERSION_END(Exchange::IDisplayProperties::ColourDepthType)

ENUM_CONVERSION_BEGIN(Exchange::IDisplayProperties::ColorimetryType)
    { Exchange::IDisplayProperties::ColorimetryType::COLORIMETRY_UNKNOWN, _TXT("ColorimetryUnknown") },
    { Exchange::IDisplayProperties::ColorimetryType::COLORIMETRY_OTHER, _TXT("ColorimetryOther") },
    { Exchange::IDisplayProperties::ColorimetryType::COLORIMETRY_SMPTE170M, _TXT("ColorimetrySmpte170m") },
    { Exchange::IDisplayProperties::ColorimetryType::COLORIMETRY_BT709, _TXT("ColorimetryBt709") },
    { Exchange::IDisplayProperties::ColorimetryType::COLORIMETRY_XVYCC601, _TXT("ColorimetryXvycc601") },
    { Exchange::IDisplayProperties::ColorimetryType::COLORIMETRY_XVYCC709, _TXT("ColorimetryXvycc709") },
    { Exchange::IDisplayProperties::ColorimetryType::COLORIMETRY_SYCC601, _TXT("ColorimetrySycc601") },
    { Exchange::IDisplayProperties::ColorimetryType::COLORIMETRY_OPYCC601, _TXT("ColorimetryOpycc601") },
    { Exchange::IDisplayProperties::ColorimetryType::COLORIMETRY_OPRGB, _TXT("ColorimetryOprgb") },
    { Exchange::IDisplayProperties::ColorimetryType::COLORIMETRY_BT2020YCCBCBRC, _TXT("ColorimetryBt2020yccbcbrc") },
    { Exchange::IDisplayProperties::ColorimetryType::COLORIMETRY_BT2020RGB_YCBCR, _TXT("ColorimetryBt2020rgbYcbcr") },
ENUM_CONVERSION_END(Exchange::IDisplayProperties::ColorimetryType)

ENUM_CONVERSION_BEGIN(Exchange::IDisplayProperties::QuantizationRangeType)
    { Exchange::IDisplayProperties::QuantizationRangeType::QUANTIZATIONRANGE_UNKNOWN, _TXT("QuantizationrangeUnknown") },
    { Exchange::IDisplayProperties::QuantizationRangeType::QUANTIZATIONRANGE_LIMITED, _TXT("QuantizationrangeLimited") },
    { Exchange::IDisplayProperties::QuantizationRangeType::QUANTIZATIONRANGE_FULL, _TXT("QuantizationrangeFull") },
ENUM_CONVERSION_END(Exchange::IDisplayProperties::QuantizationRangeType)

ENUM_CONVERSION_BEGIN(Exchange::IDisplayProperties::EotfType)
    { Exchange::IDisplayProperties::EotfType::EOTF_UNKNOWN, _TXT("EotfUnknown") },
    { Exchange::IDisplayProperties::EotfType::EOTF_OTHER, _TXT("EotfOther") },
    { Exchange::IDisplayProperties::EotfType::EOTF_BT1886, _TXT("EotfBt1886") },
    { Exchange::IDisplayProperties::EotfType::EOTF_BT2100, _TXT("EotfBt2100") },
    { Exchange::IDisplayProperties::EotfType::EOTF_SMPTE_ST_2084, _TXT("EotfSmpteSt2084") },
ENUM_CONVERSION_END(Exchange::IDisplayProperties::EotfType)

}
