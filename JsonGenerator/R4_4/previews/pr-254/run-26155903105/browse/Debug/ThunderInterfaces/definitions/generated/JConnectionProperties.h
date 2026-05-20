// Generated automatically from 'IDisplayInfo.h'. DO NOT EDIT.

#pragma once

#include "Module.h"
#include "JsonData_ConnectionProperties.h"
#include <interfaces/IDisplayInfo.h>

namespace WPEFramework {

namespace Exchange {

    namespace JConnectionProperties {

        namespace Version {

            constexpr uint8_t Major = 1;
            constexpr uint8_t Minor = 0;
            constexpr uint8_t Patch = 0;

        } // namespace Version

        using JSONRPC = PluginHost::JSONRPC;

        PUSH_WARNING(DISABLE_WARNING_UNUSED_FUNCTIONS)

        static void Register(JSONRPC& _module_, IConnectionProperties* _impl_)
        {
            ASSERT(_impl_ != nullptr);

            _module_.RegisterVersion(_T("JConnectionProperties"), Version::Major, Version::Minor, Version::Patch);

            // Register methods and properties...

            // Method: 'edid' - TV's Extended Display Identification Data
            _module_.Register<JsonData::ConnectionProperties::EDIDParamsData, JsonData::ConnectionProperties::EDIDResultData>(_T("edid"), 
                [_impl_](const JsonData::ConnectionProperties::EDIDParamsData& params, JsonData::ConnectionProperties::EDIDResultData& result) -> uint32_t {
                    uint32_t _errorCode = Core::ERROR_NONE;

                    uint16_t _length{params.Length};
                    uint8_t* _data = nullptr;

                    if ((_length != 0) && (_length <= 0x400000)) {
                        _data = reinterpret_cast<uint8_t*>(ALLOCA(_length));
                        ASSERT(_data != nullptr);
                    }
                    else {
                        _errorCode = Core::ERROR_INVALID_RANGE;
                    }

                    _errorCode = _impl_->EDID(_length, _data);

                    if (_errorCode == Core::ERROR_NONE) {
                        result.Length = _length;

                        if (_length != 0) {
                            string _dataEncoded_;
                            Core::ToString(_data, _length, true, _dataEncoded_);
                            result.Data = _dataEncoded_;
                        }
                    }

                    return (_errorCode);
                });

            // Method: 'widthincentimeters' - Horizontal size in centimeters
            _module_.Register<void, Core::JSON::DecUInt8>(_T("widthincentimeters"), 
                [_impl_](Core::JSON::DecUInt8& width) -> uint32_t {
                    uint32_t _errorCode = Core::ERROR_NONE;

                    uint8_t _width{};

                    _errorCode = _impl_->WidthInCentimeters(_width);

                    if (_errorCode == Core::ERROR_NONE) {
                        width = _width;
                    }

                    return (_errorCode);
                });

            // Method: 'heightincentimeters' - Vertical size in centimeters
            _module_.Register<void, Core::JSON::DecUInt8>(_T("heightincentimeters"), 
                [_impl_](Core::JSON::DecUInt8& height) -> uint32_t {
                    uint32_t _errorCode = Core::ERROR_NONE;

                    uint8_t _height{};

                    _errorCode = _impl_->HeightInCentimeters(_height);

                    if (_errorCode == Core::ERROR_NONE) {
                        height = _height;
                    }

                    return (_errorCode);
                });

            // Property: 'isaudiopassthrough' - Current audio passthrough status on HDMI (r/o)
            _module_.Register<void, Core::JSON::Boolean>(_T("isaudiopassthrough"), 
                [_impl_](Core::JSON::Boolean& result) -> uint32_t {
                    uint32_t _errorCode = Core::ERROR_NONE;

                    // read-only property get
                    bool _result{};

                    _errorCode = _impl_->IsAudioPassthrough(_result);

                    if (_errorCode == Core::ERROR_NONE) {
                        result = _result;
                    }

                    return (_errorCode);
                });

            // Property: 'connected' - Current HDMI connection status (r/o)
            _module_.Register<void, Core::JSON::Boolean>(_T("connected"), 
                [_impl_](Core::JSON::Boolean& result) -> uint32_t {
                    uint32_t _errorCode = Core::ERROR_NONE;

                    // read-only property get
                    bool _result{};

                    _errorCode = _impl_->Connected(_result);

                    if (_errorCode == Core::ERROR_NONE) {
                        result = _result;
                    }

                    return (_errorCode);
                });

            // Property: 'width' - Horizontal resolution of TV (r/o)
            _module_.Register<void, Core::JSON::DecUInt32>(_T("width"), 
                [_impl_](Core::JSON::DecUInt32& result) -> uint32_t {
                    uint32_t _errorCode = Core::ERROR_NONE;

                    // read-only property get
                    uint32_t _result{};

                    _errorCode = _impl_->Width(_result);

                    if (_errorCode == Core::ERROR_NONE) {
                        result = _result;
                    }

                    return (_errorCode);
                });

            // Property: 'height' - Vertical resolution of TV (r/o)
            _module_.Register<void, Core::JSON::DecUInt32>(_T("height"), 
                [_impl_](Core::JSON::DecUInt32& result) -> uint32_t {
                    uint32_t _errorCode = Core::ERROR_NONE;

                    // read-only property get
                    uint32_t _result{};

                    _errorCode = _impl_->Height(_result);

                    if (_errorCode == Core::ERROR_NONE) {
                        result = _result;
                    }

                    return (_errorCode);
                });

            // Property: 'verticalfreq' - Vertical Frequency (r/o)
            _module_.Register<void, Core::JSON::DecUInt32>(_T("verticalfreq"), 
                [_impl_](Core::JSON::DecUInt32& result) -> uint32_t {
                    uint32_t _errorCode = Core::ERROR_NONE;

                    // read-only property get
                    uint32_t _result{};

                    _errorCode = _impl_->VerticalFreq(_result);

                    if (_errorCode == Core::ERROR_NONE) {
                        result = _result;
                    }

                    return (_errorCode);
                });

            // Property: 'hdcpprotection' - HDCP protocol used for transmission
            _module_.Register<Core::JSON::EnumType<Exchange::IConnectionProperties::HDCPProtectionType>,
                     Core::JSON::EnumType<Exchange::IConnectionProperties::HDCPProtectionType>>(_T("hdcpprotection"), 
                [_impl_](const Core::JSON::EnumType<Exchange::IConnectionProperties::HDCPProtectionType>& params,
                         Core::JSON::EnumType<Exchange::IConnectionProperties::HDCPProtectionType>& result) -> uint32_t {
                    uint32_t _errorCode = Core::ERROR_NONE;

                    if (params.IsSet() == false) {
                        // property get
                        Exchange::IConnectionProperties::HDCPProtectionType _result{};

                        _errorCode = (static_cast<const IConnectionProperties*>(_impl_))->HDCPProtection(_result);

                        if (_errorCode == Core::ERROR_NONE) {
                            result = _result;
                        }

                    } else {
                        // property set
                        const Exchange::IConnectionProperties::HDCPProtectionType _params{params};

                        _errorCode = _impl_->HDCPProtection(_params);

                        result.Null(true);
                    }
                    return (_errorCode);
                });

            // Property: 'portname' - Video output port on the STB used for connection to TV (r/o)
            _module_.Register<void, Core::JSON::String>(_T("portname"), 
                [_impl_](Core::JSON::String& result) -> uint32_t {
                    uint32_t _errorCode = Core::ERROR_NONE;

                    // read-only property get
                    string _result{};

                    _errorCode = _impl_->PortName(_result);

                    if (_errorCode == Core::ERROR_NONE) {
                        result = _result;
                    }

                    return (_errorCode);
                });

        }

        static void Unregister(JSONRPC& _module_)
        {
            // Unregister methods and properties...
            _module_.Unregister(_T("edid"));
            _module_.Unregister(_T("widthincentimeters"));
            _module_.Unregister(_T("heightincentimeters"));
            _module_.Unregister(_T("isaudiopassthrough"));
            _module_.Unregister(_T("connected"));
            _module_.Unregister(_T("width"));
            _module_.Unregister(_T("height"));
            _module_.Unregister(_T("verticalfreq"));
            _module_.Unregister(_T("hdcpprotection"));
            _module_.Unregister(_T("portname"));
        }

        namespace Event {

            // Event: 'updated'
            static void Updated(const JSONRPC& _module_, const JsonData::ConnectionProperties::UpdatedParamsData& params)
            {
                _module_.Notify(_T("updated"), params);
            }

            // Event: 'updated'
            static void Updated(const JSONRPC& _module_, const Core::JSON::EnumType<Exchange::IConnectionProperties::INotification::Source>& event)
            {
                JsonData::ConnectionProperties::UpdatedParamsData _params_;
                _params_.Event = event;

                Updated(_module_, _params_);
            }

            // Event: 'updated'
            static void Updated(const JSONRPC& _module_, const Exchange::IConnectionProperties::INotification::Source& event)
            {
                JsonData::ConnectionProperties::UpdatedParamsData _params_;
                _params_.Event = event;

                Updated(_module_, _params_);
            }

        } // namespace Event

        POP_WARNING()

    } // namespace JConnectionProperties

} // namespace Exchange

} // namespace WPEFramework

