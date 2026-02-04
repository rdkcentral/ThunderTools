// Enumeration code for Application API.
// Generated automatically from 'IApplication.h'.

#include <core/Enumerate.h>

#include "definitions.h"
#include <interfaces/IApplication.h>
#include "JsonData_Application.h"

namespace Thunder {

ENUM_CONVERSION_BEGIN(Exchange::IApplication::resettype)
    { Exchange::IApplication::resettype::FACTORY, _TXT("Factory") },
    { Exchange::IApplication::resettype::CACHE, _TXT("Cache") },
    { Exchange::IApplication::resettype::CREDENTIALS, _TXT("Credentials") },
    { Exchange::IApplication::resettype::RECORDINGS, _TXT("Recordings") },
ENUM_CONVERSION_END(Exchange::IApplication::resettype)

ENUM_CONVERSION_BEGIN(Exchange::IApplication::launchpointtype)
    { Exchange::IApplication::launchpointtype::UNDEFINED, _TXT("Undefined") },
    { Exchange::IApplication::launchpointtype::DIAL, _TXT("Dial") },
    { Exchange::IApplication::launchpointtype::DEDICATED_BUTTON, _TXT("DedicatedButton") },
    { Exchange::IApplication::launchpointtype::DEDICATED_ICON, _TXT("DedicatedIcon") },
    { Exchange::IApplication::launchpointtype::APPLICATION_LIST, _TXT("ApplicationList") },
    { Exchange::IApplication::launchpointtype::INTEGRATED_TILE, _TXT("IntegratedTile") },
    { Exchange::IApplication::launchpointtype::SEARCH_RESULT, _TXT("SearchResult") },
    { Exchange::IApplication::launchpointtype::SEARCH_CONTINUATION, _TXT("SearchContinuation") },
    { Exchange::IApplication::launchpointtype::VOICE_CONTROL, _TXT("VoiceControl") },
    { Exchange::IApplication::launchpointtype::VOICE_SEARCH_RESULT, _TXT("VoiceSearchResult") },
    { Exchange::IApplication::launchpointtype::VISUAL_GESTURE, _TXT("VisualGesture") },
    { Exchange::IApplication::launchpointtype::TOUCH_GESTURE, _TXT("TouchGesture") },
    { Exchange::IApplication::launchpointtype::EPG_GRID, _TXT("EpgGrid") },
    { Exchange::IApplication::launchpointtype::CHANNEL_NUMBER, _TXT("ChannelNumber") },
    { Exchange::IApplication::launchpointtype::CHANNEL_ZAP, _TXT("ChannelZap") },
    { Exchange::IApplication::launchpointtype::CHANNEL_BAR, _TXT("ChannelBar") },
    { Exchange::IApplication::launchpointtype::WEB_BROWSER, _TXT("WebBrowser") },
    { Exchange::IApplication::launchpointtype::POWER_ON, _TXT("PowerOn") },
    { Exchange::IApplication::launchpointtype::POWER_ON_FROM_DEDICATED_BUTTON, _TXT("PowerOnFromDedicatedButton") },
    { Exchange::IApplication::launchpointtype::SUSPENDED_POWER_ON, _TXT("SuspendedPowerOn") },
    { Exchange::IApplication::launchpointtype::RESTART, _TXT("Restart") },
    { Exchange::IApplication::launchpointtype::SUSPENDED_RESTART, _TXT("SuspendedRestart") },
    { Exchange::IApplication::launchpointtype::RESUMED_FROM_SCREEN_SAVER, _TXT("ResumedFromScreenSaver") },
    { Exchange::IApplication::launchpointtype::RESUMED_FROM_STANDBY, _TXT("ResumedFromStandby") },
    { Exchange::IApplication::launchpointtype::BANNER_AD, _TXT("BannerAd") },
    { Exchange::IApplication::launchpointtype::TITLE_RECOMMENDATION, _TXT("TitleRecommendation") },
    { Exchange::IApplication::launchpointtype::APPLICATION_PROMOTION, _TXT("ApplicationPromotion") },
ENUM_CONVERSION_END(Exchange::IApplication::launchpointtype)

}
