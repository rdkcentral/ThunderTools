// Generated automatically from 'IDisplayInfo.h'. DO NOT EDIT.

#pragma once
#include "Module.h"
#include "JsonData_DisplayProperties.h"
#include <interfaces/IDisplayInfo.h>

namespace Thunder {

namespace Exchange {

    namespace JDisplayProperties {

        namespace Version {

            constexpr uint8_t Major = 1;
            constexpr uint8_t Minor = 0;
            constexpr uint8_t Patch = 0;

        } // namespace Version

        PUSH_WARNING(DISABLE_WARNING_UNUSED_FUNCTIONS)
        PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
        PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

        template<typename MODULE>
        static void Register(MODULE& _module__, IDisplayProperties* _implementation__)
        {
            ASSERT(_implementation__ != nullptr);

            _module__.PluginHost::JSONRPC::RegisterVersion(_T("JDisplayProperties"), Version::Major, Version::Minor, Version::Patch);

            // Register methods and properties...

            // Property: 'colorspace' - Provides access to the display's Colour space (chroma subsampling format) (r/o)
            _module__.PluginHost::JSONRPC::template Register<void, Core::JSON::EnumType<Exchange::IDisplayProperties::ColourSpaceType>>(_T("colorspace"),
                [_implementation__](Core::JSON::EnumType<Exchange::IDisplayProperties::ColourSpaceType>& result) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    Exchange::IDisplayProperties::ColourSpaceType _result_{};

                    _errorCode__ = _implementation__->ColorSpace(_result_);

                    if (_errorCode__ == Core::ERROR_NONE) {
                        result = _result_;
                    }

                    return (_errorCode__);
                });

            // Property: 'framerate' - Provides access to Frame Rate (r/o)
            _module__.PluginHost::JSONRPC::template Register<void, Core::JSON::EnumType<Exchange::IDisplayProperties::FrameRateType>>(_T("framerate"),
                [_implementation__](Core::JSON::EnumType<Exchange::IDisplayProperties::FrameRateType>& result) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    Exchange::IDisplayProperties::FrameRateType _result_{};

                    _errorCode__ = _implementation__->FrameRate(_result_);

                    if (_errorCode__ == Core::ERROR_NONE) {
                        result = _result_;
                    }

                    return (_errorCode__);
                });

            // Property: 'colourdepth' - Provides access to display's colour Depth (r/o)
            _module__.PluginHost::JSONRPC::template Register<void, Core::JSON::EnumType<Exchange::IDisplayProperties::ColourDepthType>>(_T("colourdepth"),
                [_implementation__](Core::JSON::EnumType<Exchange::IDisplayProperties::ColourDepthType>& result) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    Exchange::IDisplayProperties::ColourDepthType _result_{};

                    _errorCode__ = _implementation__->ColourDepth(_result_);

                    if (_errorCode__ == Core::ERROR_NONE) {
                        result = _result_;
                    }

                    return (_errorCode__);
                });

            // Property: 'colorimetry' - Provides access to display's colorimetry (r/o)
            _module__.PluginHost::JSONRPC::template Register<void, Core::JSON::ArrayType<Core::JSON::EnumType<Exchange::IDisplayProperties::ColorimetryType>>>(_T("colorimetry"),
                [_implementation__](Core::JSON::ArrayType<Core::JSON::EnumType<Exchange::IDisplayProperties::ColorimetryType>>& result) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    ::Thunder::RPC::IIteratorType<IDisplayProperties::ColorimetryType, ID_COLORIMETRY_ITERATOR>* _result_{};

                    _errorCode__ = _implementation__->Colorimetry(_result_);

                    if (_errorCode__ == Core::ERROR_NONE) {
                        result.Set(true);

                        if (_result_ != nullptr) {
                            Exchange::IDisplayProperties::ColorimetryType _resultItem__{};
                            while (_result_->Next(_resultItem__) == true) { result.Add() = _resultItem__; }
                            _result_->Release();
                        }
                    }

                    return (_errorCode__);
                });

            // Property: 'quantizationrange' - Provides access to display's Qauntization Range (r/o)
            _module__.PluginHost::JSONRPC::template Register<void, Core::JSON::EnumType<Exchange::IDisplayProperties::QuantizationRangeType>>(_T("quantizationrange"),
                [_implementation__](Core::JSON::EnumType<Exchange::IDisplayProperties::QuantizationRangeType>& result) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    Exchange::IDisplayProperties::QuantizationRangeType _result_{};

                    _errorCode__ = _implementation__->QuantizationRange(_result_);

                    if (_errorCode__ == Core::ERROR_NONE) {
                        result = _result_;
                    }

                    return (_errorCode__);
                });

            // Property: 'eotf' - Provides access to display's Electro optical transfer function (r/o)
            _module__.PluginHost::JSONRPC::template Register<void, Core::JSON::EnumType<Exchange::IDisplayProperties::EotfType>>(_T("eotf"),
                [_implementation__](Core::JSON::EnumType<Exchange::IDisplayProperties::EotfType>& result) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    Exchange::IDisplayProperties::EotfType _result_{};

                    _errorCode__ = _implementation__->EOTF(_result_);

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
            _module__.PluginHost::JSONRPC::Unregister(_T("colorspace"));
            _module__.PluginHost::JSONRPC::Unregister(_T("framerate"));
            _module__.PluginHost::JSONRPC::Unregister(_T("colourdepth"));
            _module__.PluginHost::JSONRPC::Unregister(_T("colorimetry"));
            _module__.PluginHost::JSONRPC::Unregister(_T("quantizationrange"));
            _module__.PluginHost::JSONRPC::Unregister(_T("eotf"));
        }

        POP_WARNING()
        POP_WARNING()
        POP_WARNING()

    } // namespace JDisplayProperties

} // namespace Exchange

} // namespace Thunder

