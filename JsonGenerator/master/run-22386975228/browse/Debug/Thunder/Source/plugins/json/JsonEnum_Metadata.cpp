// Enumeration code for Metadata API.
// Generated automatically from 'IController.h'.

#include <core/Enumerate.h>

#include "definitions.h"
#include "JsonData_Metadata.h"

namespace Thunder {

ENUM_CONVERSION_BEGIN(Exchange::Controller::IMetadata::Data::Service::state)
    { Exchange::Controller::IMetadata::Data::Service::state::UNAVAILABLE, _TXT("Unavailable") },
    { Exchange::Controller::IMetadata::Data::Service::state::DEACTIVATED, _TXT("Deactivated") },
    { Exchange::Controller::IMetadata::Data::Service::state::DEACTIVATION, _TXT("Deactivation") },
    { Exchange::Controller::IMetadata::Data::Service::state::ACTIVATED, _TXT("Activated") },
    { Exchange::Controller::IMetadata::Data::Service::state::ACTIVATION, _TXT("Activation") },
    { Exchange::Controller::IMetadata::Data::Service::state::DESTROYED, _TXT("Destroyed") },
    { Exchange::Controller::IMetadata::Data::Service::state::PRECONDITION, _TXT("Precondition") },
    { Exchange::Controller::IMetadata::Data::Service::state::HIBERNATED, _TXT("Hibernated") },
    { Exchange::Controller::IMetadata::Data::Service::state::SUSPENDED, _TXT("Suspended") },
    { Exchange::Controller::IMetadata::Data::Service::state::RESUMED, _TXT("Resumed") },
ENUM_CONVERSION_END(Exchange::Controller::IMetadata::Data::Service::state)

ENUM_CONVERSION_BEGIN(PluginHost::IShell::startmode)
    { PluginHost::IShell::startmode::UNAVAILABLE, _TXT("Unavailable") },
    { PluginHost::IShell::startmode::DEACTIVATED, _TXT("Deactivated") },
    { PluginHost::IShell::startmode::ACTIVATED, _TXT("Activated") },
ENUM_CONVERSION_END(PluginHost::IShell::startmode)

ENUM_CONVERSION_BEGIN(Exchange::Controller::IMetadata::Data::Link::state)
    { Exchange::Controller::IMetadata::Data::Link::state::CLOSED, _TXT("Closed") },
    { Exchange::Controller::IMetadata::Data::Link::state::WEBSERVER, _TXT("WebServer") },
    { Exchange::Controller::IMetadata::Data::Link::state::WEBSOCKET, _TXT("WebSocket") },
    { Exchange::Controller::IMetadata::Data::Link::state::RAWSOCKET, _TXT("RawSocket") },
    { Exchange::Controller::IMetadata::Data::Link::state::COMRPC, _TXT("COMRPC") },
    { Exchange::Controller::IMetadata::Data::Link::state::SUSPENDED, _TXT("Suspended") },
ENUM_CONVERSION_END(Exchange::Controller::IMetadata::Data::Link::state)

ENUM_CONVERSION_BEGIN(Exchange::Controller::IMetadata::Data::BuildInfo::systemtype)
    { Exchange::Controller::IMetadata::Data::BuildInfo::systemtype::SYSTEM_WINDOWS, _TXT("Windows") },
    { Exchange::Controller::IMetadata::Data::BuildInfo::systemtype::SYSTEM_LINUX, _TXT("Linux") },
    { Exchange::Controller::IMetadata::Data::BuildInfo::systemtype::SYSTEM_MACOS, _TXT("MacOS") },
ENUM_CONVERSION_END(Exchange::Controller::IMetadata::Data::BuildInfo::systemtype)

ENUM_CONVERSION_BEGIN(Exchange::Controller::IMetadata::Data::BuildInfo::buildtype)
    { Exchange::Controller::IMetadata::Data::BuildInfo::buildtype::DEBUG, _TXT("Debug") },
    { Exchange::Controller::IMetadata::Data::BuildInfo::buildtype::DEBUG_OPTIMIZED, _TXT("DebugOptimized") },
    { Exchange::Controller::IMetadata::Data::BuildInfo::buildtype::RELEASE_WITH_DEBUG_INFO, _TXT("ReleaseWithDebugInfo") },
    { Exchange::Controller::IMetadata::Data::BuildInfo::buildtype::RELEASE, _TXT("Release") },
    { Exchange::Controller::IMetadata::Data::BuildInfo::buildtype::PRODUCTION, _TXT("Production") },
ENUM_CONVERSION_END(Exchange::Controller::IMetadata::Data::BuildInfo::buildtype)

ENUM_CONVERSION_BEGIN(Exchange::Controller::IMetadata::Data::BuildInfo::extensiontype)
    { Exchange::Controller::IMetadata::Data::BuildInfo::extensiontype::WARNING_REPORTING, _TXT("WarningReporting") },
    { Exchange::Controller::IMetadata::Data::BuildInfo::extensiontype::BLUETOOTH, _TXT("Bluetooth") },
    { Exchange::Controller::IMetadata::Data::BuildInfo::extensiontype::HIBERNATE, _TXT("Hibernate") },
    { Exchange::Controller::IMetadata::Data::BuildInfo::extensiontype::PROCESS_CONTAINERS, _TXT("ProcessContainers") },
ENUM_CONVERSION_END(Exchange::Controller::IMetadata::Data::BuildInfo::extensiontype)

}
