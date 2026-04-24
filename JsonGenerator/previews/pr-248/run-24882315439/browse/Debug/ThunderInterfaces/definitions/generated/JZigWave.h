// Generated automatically from 'IZigWave.h'. DO NOT EDIT.

#pragma once
#include "Module.h"
#include "JsonData_ZigWave.h"
#include <interfaces/IZigWave.h>

namespace Thunder {

namespace Exchange {

    namespace JZigWave {

        namespace Version {

            constexpr uint8_t Major = 1;
            constexpr uint8_t Minor = 0;
            constexpr uint8_t Patch = 0;

        } // namespace Version

        PUSH_WARNING(DISABLE_WARNING_UNUSED_FUNCTIONS)
        PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
        PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

        template<typename MODULE>
        static void Register(MODULE& _module__, IZigWave* _implementation__)
        {
            ASSERT(_implementation__ != nullptr);

            _module__.PluginHost::JSONRPC::RegisterVersion(_T("JZigWave"), Version::Major, Version::Minor, Version::Patch);

            // Register methods and properties...

            // Method: 'bind' - Bind the *out* from the soure to the *in* of the destination
            _module__.PluginHost::JSONRPC::template Register<JsonData::ZigWave::BindParamsInfo, void>(_T("bind"),
                [_implementation__](const JsonData::ZigWave::BindParamsInfo& params) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                        _errorCode__ = Core::ERROR_BAD_REQUEST;
                    }
                    else {
                        const uint32_t _source_{params.Source};
                        const uint32_t _destination_{params.Destination};

                        _errorCode__ = _implementation__->Bind(_source_, _destination_);

                    }

                    return (_errorCode__);
                });

            // Method: 'unbind' - Unbind the *out* from the soure to the *in* of the destination
            _module__.PluginHost::JSONRPC::template Register<JsonData::ZigWave::BindParamsInfo, void>(_T("unbind"),
                [_implementation__](const JsonData::ZigWave::BindParamsInfo& params) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                        _errorCode__ = Core::ERROR_BAD_REQUEST;
                    }
                    else {
                        const uint32_t _source_{params.Source};
                        const uint32_t _destination_{params.Destination};

                        _errorCode__ = _implementation__->Unbind(_source_, _destination_);

                    }

                    return (_errorCode__);
                });

            // Method: 'metadata' - Return the Metadata associated with the controller for this instance
            _module__.PluginHost::JSONRPC::template Register<void, JsonData::ZigWave::ControllerData>(_T("metadata"),
                [_implementation__](JsonData::ZigWave::ControllerData& metadata) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    Exchange::IZigWave::Controller _metadata_{};

                    _errorCode__ = _implementation__->Metadata(_metadata_);

                    if (_errorCode__ == Core::ERROR_NONE) {
                        metadata.Set(true);
                        metadata = _metadata_;
                    }

                    return (_errorCode__);
                });

            // Indexed Property: 'permutable' - To allow new devices to the network, the controller should be placed into an accepting mode
            _module__.PluginHost::JSONRPC::template Register<JsonData::ZigWave::PermutableData, Core::JSON::Boolean, std::function<uint32_t(const string&, const JsonData::ZigWave::PermutableData&, Core::JSON::Boolean&)>>(_T("permutable"),
                [_implementation__](const string& address, const JsonData::ZigWave::PermutableData& params, Core::JSON::Boolean& result) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    uint32_t _addressConv__{};

                    if (address.empty() == true) {
                        _errorCode__ = Core::ERROR_BAD_REQUEST;
                    }
                    else {
                        const bool _addressConvResult__ = Core::FromString(address, _addressConv__);

                        if (_addressConvResult__ == false) {
                            _errorCode__ = Core::ERROR_BAD_REQUEST;
                        }
                    }

                    if (_errorCode__ == Core::ERROR_NONE) {

                        if (params.IsSet() == false) {
                            bool _result_{};

                            _errorCode__ = (static_cast<const IZigWave*>(_implementation__))->Permutable(_addressConv__, _result_);

                            if (_errorCode__ == Core::ERROR_NONE) {
                                result = _result_;
                            }
                        }
                        else {

                            if (params.IsDataValid() == false) {
                                _errorCode__ = Core::ERROR_BAD_REQUEST;
                            }
                            else {
                                const bool _value_{params.Value};

                                _errorCode__ = _implementation__->Permutable(_addressConv__, _value_);

                            }

                            result.Null(true);
                        }
                    }

                    return (_errorCode__);
                });

            _module__.PluginHost::JSONRPC::Register(_T("accept"), _T("permutable"));

            // Indexed Property: 'devices' - Get the information of available devices (r/o)
            _module__.PluginHost::JSONRPC::template Register<void, Core::JSON::ArrayType<JsonData::ZigWave::DeviceData>, std::function<uint32_t(const string&, Core::JSON::ArrayType<JsonData::ZigWave::DeviceData>&)>>(_T("devices"),
                [_implementation__](const string& id, Core::JSON::ArrayType<JsonData::ZigWave::DeviceData>& result) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    uint32_t _idConv__{};

                    if (id.empty() == true) {
                        _errorCode__ = Core::ERROR_BAD_REQUEST;
                    }
                    else {
                        const bool _idConvResult__ = Core::FromString(id, _idConv__);

                        if (_idConvResult__ == false) {
                            _errorCode__ = Core::ERROR_BAD_REQUEST;
                        }
                    }

                    if (_errorCode__ == Core::ERROR_NONE) {
                        ::Thunder::RPC::IIteratorType<IZigWave::Device, ID_ZIGWAVE_DEVICE_ITERATOR>* _result_{};

                        _errorCode__ = _implementation__->Devices(_idConv__, _result_);

                        if (_errorCode__ == Core::ERROR_NONE) {
                            result.Set(true);

                            if (_result_ != nullptr) {
                                Exchange::IZigWave::Device _resultItem__{};
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
            _module__.PluginHost::JSONRPC::Unregister(_T("bind"));
            _module__.PluginHost::JSONRPC::Unregister(_T("unbind"));
            _module__.PluginHost::JSONRPC::Unregister(_T("metadata"));
            _module__.PluginHost::JSONRPC::Unregister(_T("permutable"));
            _module__.PluginHost::JSONRPC::Unregister(_T("accept"));
            _module__.PluginHost::JSONRPC::Unregister(_T("devices"));
        }

        POP_WARNING()
        POP_WARNING()
        POP_WARNING()

    } // namespace JZigWave

} // namespace Exchange

} // namespace Thunder

