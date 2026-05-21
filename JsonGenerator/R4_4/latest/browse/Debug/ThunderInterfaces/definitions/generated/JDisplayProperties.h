// Generated automatically from 'IDisplayInfo.h'. DO NOT EDIT.

#pragma once

#include "Module.h"
#include "JsonData_DisplayProperties.h"
#include <interfaces/IDisplayInfo.h>

namespace WPEFramework {

namespace Exchange {

    namespace JDisplayProperties {

        namespace Version {

            constexpr uint8_t Major = 1;
            constexpr uint8_t Minor = 0;
            constexpr uint8_t Patch = 0;

        } // namespace Version

        using JSONRPC = PluginHost::JSONRPC;

        PUSH_WARNING(DISABLE_WARNING_UNUSED_FUNCTIONS)

        static void Register(JSONRPC& _module_, IDisplayProperties* _impl_)
        {
            ASSERT(_impl_ != nullptr);

            _module_.RegisterVersion(_T("JDisplayProperties"), Version::Major, Version::Minor, Version::Patch);

            // Register methods and properties...

            // Property: 'colorspace' - Provides access to the display's Colour space (chroma subsampling format) (r/o)
            _module_.Register<void, Core::JSON::EnumType<Exchange::IDisplayProperties::ColourSpaceType>>(_T("colorspace"), 
                [_impl_](Core::JSON::EnumType<Exchange::IDisplayProperties::ColourSpaceType>& result) -> uint32_t {
                    uint32_t _errorCode = Core::ERROR_NONE;

                    // read-only property get
                    Exchange::IDisplayProperties::ColourSpaceType _result{};

                    _errorCode = _impl_->ColorSpace(_result);

                    if (_errorCode == Core::ERROR_NONE) {
                        result = _result;
                    }

                    return (_errorCode);
                });

            // Property: 'framerate' - Provides access to Frame Rate (r/o)
            _module_.Register<void, Core::JSON::EnumType<Exchange::IDisplayProperties::FrameRateType>>(_T("framerate"), 
                [_impl_](Core::JSON::EnumType<Exchange::IDisplayProperties::FrameRateType>& result) -> uint32_t {
                    uint32_t _errorCode = Core::ERROR_NONE;

                    // read-only property get
                    Exchange::IDisplayProperties::FrameRateType _result{};

                    _errorCode = _impl_->FrameRate(_result);

                    if (_errorCode == Core::ERROR_NONE) {
                        result = _result;
                    }

                    return (_errorCode);
                });

            // Property: 'colourdepth' - Provides access to display's colour Depth (r/o)
            _module_.Register<void, Core::JSON::EnumType<Exchange::IDisplayProperties::ColourDepthType>>(_T("colourdepth"), 
                [_impl_](Core::JSON::EnumType<Exchange::IDisplayProperties::ColourDepthType>& result) -> uint32_t {
                    uint32_t _errorCode = Core::ERROR_NONE;

                    // read-only property get
                    Exchange::IDisplayProperties::ColourDepthType _result{};

                    _errorCode = _impl_->ColourDepth(_result);

                    if (_errorCode == Core::ERROR_NONE) {
                        result = _result;
                    }

                    return (_errorCode);
                });

            // Property: 'colorimetry' - Provides access to display's colorimetry (r/o)
            _module_.Register<void, Core::JSON::ArrayType<Core::JSON::EnumType<Exchange::IDisplayProperties::ColorimetryType>>>(_T("colorimetry"), 
                [_impl_](Core::JSON::ArrayType<Core::JSON::EnumType<Exchange::IDisplayProperties::ColorimetryType>>& result) -> uint32_t {
                    uint32_t _errorCode = Core::ERROR_NONE;

                    // read-only property get
                    ::WPEFramework::RPC::IIteratorType<IDisplayProperties::ColorimetryType, ID_COLORIMETRY_ITERATOR>* _result{};

                    _errorCode = _impl_->Colorimetry(_result);

                    if (_errorCode == Core::ERROR_NONE) {

                        if (_result != nullptr) {
                            Exchange::IDisplayProperties::ColorimetryType _resultItem_{};
                            while (_result->Next(_resultItem_) == true) { result.Add() = _resultItem_; }
                            _result->Release();
                        }
                    }

                    return (_errorCode);
                });

            // Property: 'quantizationrange' - Provides access to display's Qauntization Range (r/o)
            _module_.Register<void, Core::JSON::EnumType<Exchange::IDisplayProperties::QuantizationRangeType>>(_T("quantizationrange"), 
                [_impl_](Core::JSON::EnumType<Exchange::IDisplayProperties::QuantizationRangeType>& result) -> uint32_t {
                    uint32_t _errorCode = Core::ERROR_NONE;

                    // read-only property get
                    Exchange::IDisplayProperties::QuantizationRangeType _result{};

                    _errorCode = _impl_->QuantizationRange(_result);

                    if (_errorCode == Core::ERROR_NONE) {
                        result = _result;
                    }

                    return (_errorCode);
                });

            // Property: 'eotf' - Provides access to display's Electro optical transfer function (r/o)
            _module_.Register<void, Core::JSON::EnumType<Exchange::IDisplayProperties::EotfType>>(_T("eotf"), 
                [_impl_](Core::JSON::EnumType<Exchange::IDisplayProperties::EotfType>& result) -> uint32_t {
                    uint32_t _errorCode = Core::ERROR_NONE;

                    // read-only property get
                    Exchange::IDisplayProperties::EotfType _result{};

                    _errorCode = _impl_->EOTF(_result);

                    if (_errorCode == Core::ERROR_NONE) {
                        result = _result;
                    }

                    return (_errorCode);
                });

        }

        static void Unregister(JSONRPC& _module_)
        {
            // Unregister methods and properties...
            _module_.Unregister(_T("colorspace"));
            _module_.Unregister(_T("framerate"));
            _module_.Unregister(_T("colourdepth"));
            _module_.Unregister(_T("colorimetry"));
            _module_.Unregister(_T("quantizationrange"));
            _module_.Unregister(_T("eotf"));
        }

        POP_WARNING()

    } // namespace JDisplayProperties

} // namespace Exchange

} // namespace WPEFramework

