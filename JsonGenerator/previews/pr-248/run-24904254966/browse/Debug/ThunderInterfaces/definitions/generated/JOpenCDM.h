// Generated automatically from 'IOCDM.h'. DO NOT EDIT.

#pragma once
#include "Module.h"
#include <interfaces/IOCDM.h>

namespace Thunder {

namespace Exchange {

    namespace JOpenCDM {

        namespace Version {

            constexpr uint8_t Major = 1;
            constexpr uint8_t Minor = 0;
            constexpr uint8_t Patch = 0;

        } // namespace Version

        PUSH_WARNING(DISABLE_WARNING_UNUSED_FUNCTIONS)
        PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
        PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

        template<typename MODULE>
        static void Register(MODULE& _module__, IOpenCDM* _implementation__)
        {
            ASSERT(_implementation__ != nullptr);

            _module__.PluginHost::JSONRPC::RegisterVersion(_T("JOpenCDM"), Version::Major, Version::Minor, Version::Patch);

            // Register methods and properties...

            // Property: 'systems' - Supported DRM systems (r/o)
            _module__.PluginHost::JSONRPC::template Register<void, Core::JSON::ArrayType<Core::JSON::String>>(_T("systems"),
                [_implementation__](Core::JSON::ArrayType<Core::JSON::String>& result) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    ::Thunder::RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>* _result_{};

                    _errorCode__ = _implementation__->Systems(_result_);

                    if (_errorCode__ == Core::ERROR_NONE) {
                        result.Set(true);

                        if (_result_ != nullptr) {
                            string _resultItem__{};
                            while (_result_->Next(_resultItem__) == true) { result.Add() = _resultItem__; }
                            _result_->Release();
                        }
                    }

                    return (_errorCode__);
                });

            // Indexed Property: 'designators' - Designators of a specified DRM system (r/o)
            _module__.PluginHost::JSONRPC::template Register<void, Core::JSON::ArrayType<Core::JSON::String>, std::function<uint32_t(const string&, Core::JSON::ArrayType<Core::JSON::String>&)>>(_T("designators"),
                [_implementation__](const string& keySystem, Core::JSON::ArrayType<Core::JSON::String>& result) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if (keySystem.empty() == true) {
                        _errorCode__ = Core::ERROR_BAD_REQUEST;
                    }

                    if (_errorCode__ == Core::ERROR_NONE) {
                        ::Thunder::RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>* _result_{};

                        _errorCode__ = _implementation__->Designators(keySystem, _result_);

                        if (_errorCode__ == Core::ERROR_NONE) {
                            result.Set(true);

                            if (_result_ != nullptr) {
                                string _resultItem__{};
                                while (_result_->Next(_resultItem__) == true) { result.Add() = _resultItem__; }
                                _result_->Release();
                            }
                        }
                    }

                    return (_errorCode__);
                });

        }

        template<typename MODULE>
        static void Unregister(MODULE& _module__)
        {
            // Unregister methods and properties...
            _module__.PluginHost::JSONRPC::Unregister(_T("systems"));
            _module__.PluginHost::JSONRPC::Unregister(_T("designators"));
        }

        POP_WARNING()
        POP_WARNING()
        POP_WARNING()

    } // namespace JOpenCDM

} // namespace Exchange

} // namespace Thunder

