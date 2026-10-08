// Generated automatically from 'IContentProtection.h'. DO NOT EDIT.

#pragma once
#include "Module.h"
#include "JsonData_ContentProtection.h"
#include <interfaces/IContentProtection.h>

namespace Thunder {

namespace Exchange {

    namespace JContentProtection {

        namespace Version {

            constexpr uint8_t Major = 1;
            constexpr uint8_t Minor = 0;
            constexpr uint8_t Patch = 0;

        } // namespace Version

        PUSH_WARNING(DISABLE_WARNING_UNUSED_FUNCTIONS)
        PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
        PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

        template<typename MODULE>
        static void Register(MODULE& _module__, IContentProtection* _implementation__)
        {
            ASSERT(_implementation__ != nullptr);

            _module__.PluginHost::JSONRPC::RegisterVersion(_T("JContentProtection"), Version::Major, Version::Minor, Version::Patch);

            // Register alternative notification names...
            _module__.PluginHost::JSONRPC::RegisterEventAlias(_T("onWatermarkStatusChanged"), _T("watermarkStatusChanged"));

            // Register methods and properties...

            // Method: 'openDrmSession'
            _module__.PluginHost::JSONRPC::template Register<JsonData::ContentProtection::OpenDrmSessionParamsData, JsonData::ContentProtection::OpenDrmSessionResultData>(_T("openDrmSession"),
                [_implementation__](const JsonData::ContentProtection::OpenDrmSessionParamsData& params, JsonData::ContentProtection::OpenDrmSessionResultData& result) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                        _errorCode__ = Core::ERROR_BAD_REQUEST;
                    }
                    else {
                        const string _clientId_{params.ClientId};
                        const string _appId_{params.AppId};
                        const Exchange::IContentProtection::KeySystem _keySystem_{params.KeySystem};
                        const string _licenseRequest_{params.LicenseRequest};
                        const string _initData_{params.InitData};
                        uint32_t _sessionId_{};
                        string _response_{};

                        _errorCode__ = _implementation__->OpenDrmSession(_clientId_, _appId_, _keySystem_, _licenseRequest_, _initData_, _sessionId_, _response_);

                        if (_errorCode__ == Core::ERROR_NONE) {
                            result.SessionId = _sessionId_;
                            result.Response = _response_;
                        }
                    }

                    return (_errorCode__);
                });

            _module__.PluginHost::JSONRPC::Register(_T("openDrmSession"), _T("openDrmSession"));

            // Method: 'setDrmSessionState'
            _module__.PluginHost::JSONRPC::template Register<JsonData::ContentProtection::SetDrmSessionStateParamsData, void>(_T("setDrmSessionState"),
                [_implementation__](const JsonData::ContentProtection::SetDrmSessionStateParamsData& params) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                        _errorCode__ = Core::ERROR_BAD_REQUEST;
                    }
                    else {
                        const uint32_t _sessionId_{params.SessionId};
                        const Exchange::IContentProtection::State _sessionState_{params.SessionState};

                        _errorCode__ = _implementation__->SetDrmSessionState(_sessionId_, _sessionState_);

                    }

                    return (_errorCode__);
                });

            _module__.PluginHost::JSONRPC::Register(_T("setDrmSessionState"), _T("setDrmSessionState"));

            // Method: 'updateDrmSession'
            _module__.PluginHost::JSONRPC::template Register<JsonData::ContentProtection::UpdateDrmSessionParamsData, Core::JSON::String>(_T("updateDrmSession"),
                [_implementation__](const JsonData::ContentProtection::UpdateDrmSessionParamsData& params, Core::JSON::String& response) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                        _errorCode__ = Core::ERROR_BAD_REQUEST;
                    }
                    else {
                        const uint32_t _sessionId_{params.SessionId};
                        const string _licenseRequest_{params.LicenseRequest};
                        const string _initData_{params.InitData};
                        string _response_{};

                        _errorCode__ = _implementation__->UpdateDrmSession(_sessionId_, _licenseRequest_, _initData_, _response_);

                        if (_errorCode__ == Core::ERROR_NONE) {
                            response = _response_;
                        }
                    }

                    return (_errorCode__);
                });

            _module__.PluginHost::JSONRPC::Register(_T("updateDrmSession"), _T("updateDrmSession"));

            // Method: 'closeDrmSession'
            _module__.PluginHost::JSONRPC::template Register<JsonData::ContentProtection::CloseDrmSessionParamsData, Core::JSON::String>(_T("closeDrmSession"),
                [_implementation__](const JsonData::ContentProtection::CloseDrmSessionParamsData& params, Core::JSON::String& response) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                        _errorCode__ = Core::ERROR_BAD_REQUEST;
                    }
                    else {
                        const uint32_t _sessionId_{params.SessionId};
                        string _response_{};

                        _errorCode__ = _implementation__->CloseDrmSession(_sessionId_, _response_);

                        if (_errorCode__ == Core::ERROR_NONE) {
                            response = _response_;
                        }
                    }

                    return (_errorCode__);
                });

            _module__.PluginHost::JSONRPC::Register(_T("closeDrmSession"), _T("closeDrmSession"));

            // Method: 'showWatermark'
            _module__.PluginHost::JSONRPC::template Register<JsonData::ContentProtection::ShowWatermarkParamsData, void>(_T("showWatermark"),
                [_implementation__](const JsonData::ContentProtection::ShowWatermarkParamsData& params) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                        _errorCode__ = Core::ERROR_BAD_REQUEST;
                    }
                    else {
                        const uint32_t _sessionId_{params.SessionId};
                        const bool _show_{params.Show};
                        const uint8_t _opacityLevel_{params.OpacityLevel};

                        _errorCode__ = _implementation__->ShowWatermark(_sessionId_, _show_, _opacityLevel_);

                    }

                    return (_errorCode__);
                });

            _module__.PluginHost::JSONRPC::Register(_T("showWatermark"), _T("showWatermark"));

            // Method: 'setPlaybackPosition'
            _module__.PluginHost::JSONRPC::template Register<JsonData::ContentProtection::SetPlaybackPositionParamsData, void>(_T("setPlaybackPosition"),
                [_implementation__](const JsonData::ContentProtection::SetPlaybackPositionParamsData& params) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                        _errorCode__ = Core::ERROR_BAD_REQUEST;
                    }
                    else {
                        const uint32_t _sessionId_{params.SessionId};
                        const int32_t _speed_{params.Speed};
                        const int32_t _position_{params.Position};

                        _errorCode__ = _implementation__->SetPlaybackPosition(_sessionId_, _speed_, _position_);

                    }

                    return (_errorCode__);
                });

            _module__.PluginHost::JSONRPC::Register(_T("setPlaybackPosition"), _T("setPlaybackPosition"));

        }

        template<typename MODULE>
        static void Unregister(MODULE& _module__)
        {
            // Unregister methods and properties...
            _module__.PluginHost::JSONRPC::Unregister(_T("openDrmSession"));
            _module__.PluginHost::JSONRPC::Unregister(_T("openDrmSession"));
            _module__.PluginHost::JSONRPC::Unregister(_T("setDrmSessionState"));
            _module__.PluginHost::JSONRPC::Unregister(_T("setDrmSessionState"));
            _module__.PluginHost::JSONRPC::Unregister(_T("updateDrmSession"));
            _module__.PluginHost::JSONRPC::Unregister(_T("updateDrmSession"));
            _module__.PluginHost::JSONRPC::Unregister(_T("closeDrmSession"));
            _module__.PluginHost::JSONRPC::Unregister(_T("closeDrmSession"));
            _module__.PluginHost::JSONRPC::Unregister(_T("showWatermark"));
            _module__.PluginHost::JSONRPC::Unregister(_T("showWatermark"));
            _module__.PluginHost::JSONRPC::Unregister(_T("setPlaybackPosition"));
            _module__.PluginHost::JSONRPC::Unregister(_T("setPlaybackPosition"));

            // Unegister alternative notification names...
            _module__.PluginHost::JSONRPC::UnregisterEventAlias(_T("onWatermarkStatusChanged"), _T("watermarkStatusChanged"));
        }

        namespace Event {

            // Event: 'watermarkStatusChanged'
            template<typename MODULE>
            static void WatermarkStatusChanged(const MODULE& module_, const JsonData::ContentProtection::WatermarkStatusChangedParamsData& params, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                module_.Notify(_T("watermarkStatusChanged"), params, sendIfMethod_);
            }

            // Event: 'watermarkStatusChanged'
            template<typename MODULE>
            static void WatermarkStatusChanged(const MODULE& module_, const Core::JSON::DecUInt32& sessionId, const Core::JSON::String& appId, const JsonData::ContentProtection::WatermarkStatusChangedParamsData::StatusData& status, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                JsonData::ContentProtection::WatermarkStatusChangedParamsData params_;
                params_.SessionId = sessionId;
                params_.AppId = appId;
                params_.Status = status;

                WatermarkStatusChanged(module_, params_, sendIfMethod_);
            }

            // Event: 'watermarkStatusChanged'
            template<typename MODULE>
            static void WatermarkStatusChanged(const MODULE& module_, uint32_t sessionId, const string& appId, const IContentProtection::INotification::Status& status, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                JsonData::ContentProtection::WatermarkStatusChangedParamsData params_;
                params_.SessionId = sessionId;
                params_.AppId = appId;
                params_.Status = status;

                WatermarkStatusChanged(module_, params_, sendIfMethod_);
            }

        } // namespace Event

        POP_WARNING()
        POP_WARNING()
        POP_WARNING()

    } // namespace JContentProtection

} // namespace Exchange

} // namespace Thunder

