// Generated automatically from 'IDisplayInfo.h'. DO NOT EDIT.

#pragma once
#include "Module.h"
#include "JsonData_HDRProperties.h"
#include <interfaces/IDisplayInfo.h>

namespace Thunder {

namespace Exchange {

    namespace JHDRProperties {

        namespace Version {

            constexpr uint8_t Major = 1;
            constexpr uint8_t Minor = 0;
            constexpr uint8_t Patch = 0;

        } // namespace Version

        PUSH_WARNING(DISABLE_WARNING_UNUSED_FUNCTIONS)
        PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
        PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

        template<typename MODULE>
        static void Register(MODULE& _module__, IHDRProperties* _implementation__)
        {
            ASSERT(_implementation__ != nullptr);

            _module__.PluginHost::JSONRPC::RegisterVersion(_T("JHDRProperties"), Version::Major, Version::Minor, Version::Patch);

            // Register methods and properties...

            // Property: 'tvcapabilities' - HDR formats supported by TV (r/o)
            _module__.PluginHost::JSONRPC::template Register<void, Core::JSON::ArrayType<Core::JSON::EnumType<Exchange::IHDRProperties::HDRType>>>(_T("tvcapabilities"),
                [_implementation__](Core::JSON::ArrayType<Core::JSON::EnumType<Exchange::IHDRProperties::HDRType>>& result) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    ::Thunder::RPC::IIteratorType<IHDRProperties::HDRType, ID_HDR_ITERATOR>* _result_{};

                    _errorCode__ = _implementation__->TVCapabilities(_result_);

                    if (_errorCode__ == Core::ERROR_NONE) {
                        result.Set(true);

                        if (_result_ != nullptr) {
                            Exchange::IHDRProperties::HDRType _resultItem__{};
                            while (_result_->Next(_resultItem__) == true) { result.Add() = _resultItem__; }
                            _result_->Release();
                        }
                    }

                    return (_errorCode__);
                });

            // Property: 'stbcapabilities' - HDR formats supported by STB (r/o)
            _module__.PluginHost::JSONRPC::template Register<void, Core::JSON::ArrayType<Core::JSON::EnumType<Exchange::IHDRProperties::HDRType>>>(_T("stbcapabilities"),
                [_implementation__](Core::JSON::ArrayType<Core::JSON::EnumType<Exchange::IHDRProperties::HDRType>>& result) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    ::Thunder::RPC::IIteratorType<IHDRProperties::HDRType, ID_HDR_ITERATOR>* _result_{};

                    _errorCode__ = _implementation__->STBCapabilities(_result_);

                    if (_errorCode__ == Core::ERROR_NONE) {
                        result.Set(true);

                        if (_result_ != nullptr) {
                            Exchange::IHDRProperties::HDRType _resultItem__{};
                            while (_result_->Next(_resultItem__) == true) { result.Add() = _resultItem__; }
                            _result_->Release();
                        }
                    }

                    return (_errorCode__);
                });

            // Property: 'hdrsetting' - HDR format in use (r/o)
            _module__.PluginHost::JSONRPC::template Register<void, Core::JSON::EnumType<Exchange::IHDRProperties::HDRType>>(_T("hdrsetting"),
                [_implementation__](Core::JSON::EnumType<Exchange::IHDRProperties::HDRType>& result) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    Exchange::IHDRProperties::HDRType _result_{};

                    _errorCode__ = _implementation__->HDRSetting(_result_);

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
            _module__.PluginHost::JSONRPC::Unregister(_T("tvcapabilities"));
            _module__.PluginHost::JSONRPC::Unregister(_T("stbcapabilities"));
            _module__.PluginHost::JSONRPC::Unregister(_T("hdrsetting"));
        }

        POP_WARNING()
        POP_WARNING()
        POP_WARNING()

    } // namespace JHDRProperties

} // namespace Exchange

} // namespace Thunder

