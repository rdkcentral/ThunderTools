// Generated automatically from 'IDisplayInfo.h'. DO NOT EDIT.

#pragma once
#include "Module.h"
#include "JsonData_ConnectionProperties.h"
#include <interfaces/IDisplayInfo.h>

namespace Thunder {

namespace Exchange {

    namespace JConnectionProperties {

        namespace Version {

            constexpr uint8_t Major = 1;
            constexpr uint8_t Minor = 0;
            constexpr uint8_t Patch = 0;

        } // namespace Version

        PUSH_WARNING(DISABLE_WARNING_UNUSED_FUNCTIONS)
        PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
        PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

        template<typename MODULE>
        static void Register(MODULE& _module__, IConnectionProperties* _implementation__)
        {
            ASSERT(_implementation__ != nullptr);

            _module__.PluginHost::JSONRPC::RegisterVersion(_T("JConnectionProperties"), Version::Major, Version::Minor, Version::Patch);

            // Register methods and properties...

            // Method: 'edid' - TV's Extended Display Identification Data
            _module__.PluginHost::JSONRPC::template Register<JsonData::ConnectionProperties::EDIDParamsData, JsonData::ConnectionProperties::EDIDResultData>(_T("edid"),
                [_implementation__](const JsonData::ConnectionProperties::EDIDParamsData& params, JsonData::ConnectionProperties::EDIDResultData& result) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                        _errorCode__ = Core::ERROR_BAD_REQUEST;
                    }
                    else {
                        uint16_t _length_{params.Length.Value()};
                        uint8_t* _data_{};

                        if (_length_ != 0) {
                            _data_ = reinterpret_cast<uint8_t*>(ALLOCA(_length_));
                            ASSERT(_data_ != nullptr);
                        }

                        _errorCode__ = _implementation__->EDID(_length_, _data_);

                        if (_errorCode__ == Core::ERROR_NONE) {
                            result.Length = _length_;

                            if ((_length_ != 0) && (_data_ != nullptr)) {
                                string _dataEncoded__;
                                Core::ToString(_data_, _length_, true, _dataEncoded__);
                                result.Data = std::move(_dataEncoded__);
                            }
                        }
                    }

                    return (_errorCode__);
                });

            // Method: 'widthincentimeters' - Horizontal size in centimeters
            _module__.PluginHost::JSONRPC::template Register<void, Core::JSON::DecUInt8>(_T("widthincentimeters"),
                [_implementation__](Core::JSON::DecUInt8& width) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    uint8_t _width_{};

                    _errorCode__ = _implementation__->WidthInCentimeters(_width_);

                    if (_errorCode__ == Core::ERROR_NONE) {
                        width = _width_;
                    }

                    return (_errorCode__);
                });

            // Method: 'heightincentimeters' - Vertical size in centimeters
            _module__.PluginHost::JSONRPC::template Register<void, Core::JSON::DecUInt8>(_T("heightincentimeters"),
                [_implementation__](Core::JSON::DecUInt8& height) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    uint8_t _height_{};

                    _errorCode__ = _implementation__->HeightInCentimeters(_height_);

                    if (_errorCode__ == Core::ERROR_NONE) {
                        height = _height_;
                    }

                    return (_errorCode__);
                });

            // Property: 'isaudiopassthrough' - Current audio passthrough status on HDMI (r/o)
            _module__.PluginHost::JSONRPC::template Register<void, Core::JSON::Boolean>(_T("isaudiopassthrough"),
                [_implementation__](Core::JSON::Boolean& result) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    bool _result_{};

                    _errorCode__ = _implementation__->IsAudioPassthrough(_result_);

                    if (_errorCode__ == Core::ERROR_NONE) {
                        result = _result_;
                    }

                    return (_errorCode__);
                });

            // Property: 'connected' - Current HDMI connection status (r/o)
            _module__.PluginHost::JSONRPC::template Register<void, Core::JSON::Boolean>(_T("connected"),
                [_implementation__](Core::JSON::Boolean& result) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    bool _result_{};

                    _errorCode__ = _implementation__->Connected(_result_);

                    if (_errorCode__ == Core::ERROR_NONE) {
                        result = _result_;
                    }

                    return (_errorCode__);
                });

            // Property: 'width' - Horizontal resolution of TV (r/o)
            _module__.PluginHost::JSONRPC::template Register<void, Core::JSON::DecUInt32>(_T("width"),
                [_implementation__](Core::JSON::DecUInt32& result) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    uint32_t _result_{};

                    _errorCode__ = _implementation__->Width(_result_);

                    if (_errorCode__ == Core::ERROR_NONE) {
                        result = _result_;
                    }

                    return (_errorCode__);
                });

            // Property: 'height' - Vertical resolution of TV (r/o)
            _module__.PluginHost::JSONRPC::template Register<void, Core::JSON::DecUInt32>(_T("height"),
                [_implementation__](Core::JSON::DecUInt32& result) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    uint32_t _result_{};

                    _errorCode__ = _implementation__->Height(_result_);

                    if (_errorCode__ == Core::ERROR_NONE) {
                        result = _result_;
                    }

                    return (_errorCode__);
                });

            // Property: 'verticalfreq' - Vertical Frequency (r/o)
            _module__.PluginHost::JSONRPC::template Register<void, Core::JSON::DecUInt32>(_T("verticalfreq"),
                [_implementation__](Core::JSON::DecUInt32& result) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    uint32_t _result_{};

                    _errorCode__ = _implementation__->VerticalFreq(_result_);

                    if (_errorCode__ == Core::ERROR_NONE) {
                        result = _result_;
                    }

                    return (_errorCode__);
                });

            // Property: 'hdcpprotection' - HDCP protocol used for transmission
            _module__.PluginHost::JSONRPC::template Register<Core::JSON::EnumType<Exchange::IConnectionProperties::HDCPProtectionType>, Core::JSON::EnumType<Exchange::IConnectionProperties::HDCPProtectionType>>(_T("hdcpprotection"),
                [_implementation__](const Core::JSON::EnumType<Exchange::IConnectionProperties::HDCPProtectionType>& params, Core::JSON::EnumType<Exchange::IConnectionProperties::HDCPProtectionType>& result) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if (params.IsSet() == false) {
                        Exchange::IConnectionProperties::HDCPProtectionType _result_{};

                        _errorCode__ = (static_cast<const IConnectionProperties*>(_implementation__))->HDCPProtection(_result_);

                        if (_errorCode__ == Core::ERROR_NONE) {
                            result = _result_;
                        }
                    }
                    else {
                        const Exchange::IConnectionProperties::HDCPProtectionType _params_{params};

                        _errorCode__ = _implementation__->HDCPProtection(_params_);

                        result.Null(true);
                    }

                    return (_errorCode__);
                });

            // Property: 'portname' - Video output port on the STB used for connection to TV (r/o)
            _module__.PluginHost::JSONRPC::template Register<void, Core::JSON::String>(_T("portname"),
                [_implementation__](Core::JSON::String& result) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    string _result_{};

                    _errorCode__ = _implementation__->PortName(_result_);

                    if (_errorCode__ == Core::ERROR_NONE) {
                        result = _result_;
                    }

                    return (_errorCode__);
                });

        }

        template<typename MODULE>
        static void Unregister(MODULE& _module__)
        {
            // Unregister methods and properties...
            _module__.PluginHost::JSONRPC::Unregister(_T("edid"));
            _module__.PluginHost::JSONRPC::Unregister(_T("widthincentimeters"));
            _module__.PluginHost::JSONRPC::Unregister(_T("heightincentimeters"));
            _module__.PluginHost::JSONRPC::Unregister(_T("isaudiopassthrough"));
            _module__.PluginHost::JSONRPC::Unregister(_T("connected"));
            _module__.PluginHost::JSONRPC::Unregister(_T("width"));
            _module__.PluginHost::JSONRPC::Unregister(_T("height"));
            _module__.PluginHost::JSONRPC::Unregister(_T("verticalfreq"));
            _module__.PluginHost::JSONRPC::Unregister(_T("hdcpprotection"));
            _module__.PluginHost::JSONRPC::Unregister(_T("portname"));
        }

        namespace Event {

            // Event: 'updated' - Signal changes on the display update
            template<typename MODULE>
            static void Updated(const MODULE& module_, const JsonData::ConnectionProperties::UpdatedParamsData& params, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                module_.Notify(_T("updated"), params, sendIfMethod_);
            }

            // Event: 'updated' - Signal changes on the display update
            template<typename MODULE>
            static void Updated(const MODULE& module_, const Core::JSON::EnumType<Exchange::IConnectionProperties::INotification::Source>& event, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                JsonData::ConnectionProperties::UpdatedParamsData params_;
                params_.Event = event;

                Updated(module_, params_, sendIfMethod_);
            }

            // Event: 'updated' - Signal changes on the display update
            template<typename MODULE>
            static void Updated(const MODULE& module_, const IConnectionProperties::INotification::Source event, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                JsonData::ConnectionProperties::UpdatedParamsData params_;
                params_.Event = event;

                Updated(module_, params_, sendIfMethod_);
            }

        } // namespace Event

        POP_WARNING()
        POP_WARNING()
        POP_WARNING()

    } // namespace JConnectionProperties

} // namespace Exchange

} // namespace Thunder

