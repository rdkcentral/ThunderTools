// Generated automatically from 'IDisplayInfo.h'. DO NOT EDIT.

#pragma once

#include "Module.h"
#include "JsonData_HDRProperties.h"
#include <interfaces/IDisplayInfo.h>

namespace WPEFramework {

namespace Exchange {

    namespace JHDRProperties {

        namespace Version {

            constexpr uint8_t Major = 1;
            constexpr uint8_t Minor = 0;
            constexpr uint8_t Patch = 0;

        } // namespace Version

        using JSONRPC = PluginHost::JSONRPC;

        PUSH_WARNING(DISABLE_WARNING_UNUSED_FUNCTIONS)

        static void Register(JSONRPC& _module_, IHDRProperties* _impl_)
        {
            ASSERT(_impl_ != nullptr);

            _module_.RegisterVersion(_T("JHDRProperties"), Version::Major, Version::Minor, Version::Patch);

            // Register methods and properties...

            // Property: 'tvcapabilities' - HDR formats supported by TV (r/o)
            _module_.Register<void, Core::JSON::ArrayType<Core::JSON::EnumType<Exchange::IHDRProperties::HDRType>>>(_T("tvcapabilities"), 
                [_impl_](Core::JSON::ArrayType<Core::JSON::EnumType<Exchange::IHDRProperties::HDRType>>& result) -> uint32_t {
                    uint32_t _errorCode = Core::ERROR_NONE;

                    // read-only property get
                    ::WPEFramework::RPC::IIteratorType<IHDRProperties::HDRType, ID_HDR_ITERATOR>* _result{};

                    _errorCode = _impl_->TVCapabilities(_result);

                    if (_errorCode == Core::ERROR_NONE) {

                        if (_result != nullptr) {
                            Exchange::IHDRProperties::HDRType _resultItem_{};
                            while (_result->Next(_resultItem_) == true) { result.Add() = _resultItem_; }
                            _result->Release();
                        }
                    }

                    return (_errorCode);
                });

            // Property: 'stbcapabilities' - HDR formats supported by STB (r/o)
            _module_.Register<void, Core::JSON::ArrayType<Core::JSON::EnumType<Exchange::IHDRProperties::HDRType>>>(_T("stbcapabilities"), 
                [_impl_](Core::JSON::ArrayType<Core::JSON::EnumType<Exchange::IHDRProperties::HDRType>>& result) -> uint32_t {
                    uint32_t _errorCode = Core::ERROR_NONE;

                    // read-only property get
                    ::WPEFramework::RPC::IIteratorType<IHDRProperties::HDRType, ID_HDR_ITERATOR>* _result{};

                    _errorCode = _impl_->STBCapabilities(_result);

                    if (_errorCode == Core::ERROR_NONE) {

                        if (_result != nullptr) {
                            Exchange::IHDRProperties::HDRType _resultItem_{};
                            while (_result->Next(_resultItem_) == true) { result.Add() = _resultItem_; }
                            _result->Release();
                        }
                    }

                    return (_errorCode);
                });

            // Property: 'hdrsetting' - HDR format in use (r/o)
            _module_.Register<void, Core::JSON::EnumType<Exchange::IHDRProperties::HDRType>>(_T("hdrsetting"), 
                [_impl_](Core::JSON::EnumType<Exchange::IHDRProperties::HDRType>& result) -> uint32_t {
                    uint32_t _errorCode = Core::ERROR_NONE;

                    // read-only property get
                    Exchange::IHDRProperties::HDRType _result{};

                    _errorCode = _impl_->HDRSetting(_result);

                    if (_errorCode == Core::ERROR_NONE) {
                        result = _result;
                    }

                    return (_errorCode);
                });

        }

        static void Unregister(JSONRPC& _module_)
        {
            // Unregister methods and properties...
            _module_.Unregister(_T("tvcapabilities"));
            _module_.Unregister(_T("stbcapabilities"));
            _module_.Unregister(_T("hdrsetting"));
        }

        POP_WARNING()

    } // namespace JHDRProperties

} // namespace Exchange

} // namespace WPEFramework

