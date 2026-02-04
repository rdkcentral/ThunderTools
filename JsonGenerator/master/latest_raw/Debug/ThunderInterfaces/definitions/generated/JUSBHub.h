// Generated automatically from 'IUSBHub.h'. DO NOT EDIT.

#pragma once
#include "Module.h"
#include "JsonData_USBHub.h"
#include <interfaces/IUSBHub.h>

namespace Thunder {

namespace Exchange {

    namespace JUSBHub {

        namespace Version {

            constexpr uint8_t Major = 1;
            constexpr uint8_t Minor = 0;
            constexpr uint8_t Patch = 0;

        } // namespace Version

        PUSH_WARNING(DISABLE_WARNING_UNUSED_FUNCTIONS)
        PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
        PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

        template<typename MODULE>
        static void Register(MODULE& _module__, IUSBHub* _implementation__)
        {
            ASSERT(_implementation__ != nullptr);

            _module__.PluginHost::JSONRPC::RegisterVersion(_T("JUSBHub"), Version::Major, Version::Minor, Version::Patch);

            // Register methods and properties...

            // Method: 'devices' - Get a string array defning al devices hooked up to this hub
            _module__.PluginHost::JSONRPC::template Register<void, Core::JSON::ArrayType<Core::JSON::String>>(_T("devices"),
                [_implementation__](Core::JSON::ArrayType<Core::JSON::String>& iterator) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    ::Thunder::RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>* _iterator_{};

                    _errorCode__ = _implementation__->Devices(_iterator_);

                    if (_errorCode__ == Core::ERROR_NONE) {
                        iterator.Set(true);

                        if (_iterator_ != nullptr) {
                            string _resultItem__{};
                            while (_iterator_->Next(_resultItem__) == true) { iterator.Add() = _resultItem__; }
                            _iterator_->Release();
                        }
                    }

                    return (_errorCode__);
                });

            // Method: 'vendorDevices' - Get a string array defining all devices hooked up to this hub cmpliant to the given VendorId/ProductId
            _module__.PluginHost::JSONRPC::template Register<JsonData::USBHub::VendorDevicesParamsData, Core::JSON::ArrayType<Core::JSON::String>>(_T("vendorDevices"),
                [_implementation__](const JsonData::USBHub::VendorDevicesParamsData& params, Core::JSON::ArrayType<Core::JSON::String>& iterator) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                        _errorCode__ = Core::ERROR_BAD_REQUEST;
                    }
                    else {
                        const uint16_t _vendorId_{params.VendorId};
                        const uint16_t _productId_{params.ProductId};
                        ::Thunder::RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>* _iterator_{};

                        _errorCode__ = _implementation__->VendorDevices(_vendorId_, _productId_, _iterator_);

                        if (_errorCode__ == Core::ERROR_NONE) {
                            iterator.Set(true);

                            if (_iterator_ != nullptr) {
                                string _resultItem__{};
                                while (_iterator_->Next(_resultItem__) == true) { iterator.Add() = _resultItem__; }
                                _iterator_->Release();
                            }
                        }
                    }

                    return (_errorCode__);
                });

            // Method: 'device' - Get the metadata information about the name passed in the paramater
            _module__.PluginHost::JSONRPC::template Register<JsonData::USBHub::DeviceParamsData, JsonData::USBHub::DeviceMetadataInfo>(_T("device"),
                [_implementation__](const JsonData::USBHub::DeviceParamsData& params, JsonData::USBHub::DeviceMetadataInfo& device) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                        _errorCode__ = Core::ERROR_BAD_REQUEST;
                    }
                    else {
                        const string _deviceName_{params.DeviceName};
                        Exchange::IUSBHub::DeviceMetadata _device_{};

                        _errorCode__ = _implementation__->Device(_deviceName_, _device_);

                        if (_errorCode__ == Core::ERROR_NONE) {
                            device.Set(true);
                            device = _device_;
                        }
                    }

                    return (_errorCode__);
                });

        }

        template<typename MODULE>
        static void Unregister(MODULE& _module__)
        {
            // Unregister methods and properties...
            _module__.PluginHost::JSONRPC::Unregister(_T("devices"));
            _module__.PluginHost::JSONRPC::Unregister(_T("vendorDevices"));
            _module__.PluginHost::JSONRPC::Unregister(_T("device"));
        }

        namespace Event {

            // Event: 'announce' - Device Plugged in on the bus notification
            template<typename MODULE>
            static void Announce(const MODULE& module_, const JsonData::USBHub::AnnounceParamsInfo& params, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                module_.Notify(_T("announce"), params, sendIfMethod_);
            }

            // Event: 'announce' - Device Plugged in on the bus notification
            template<typename MODULE>
            static void Announce(const MODULE& module_, const JsonData::USBHub::DeviceMetadataInfo& device, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                JsonData::USBHub::AnnounceParamsInfo params_;
                params_.Device = device;

                Announce(module_, params_, sendIfMethod_);
            }

            // Event: 'announce' - Device Plugged in on the bus notification
            template<typename MODULE>
            static void Announce(const MODULE& module_, const IUSBHub::DeviceMetadata& device, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                JsonData::USBHub::AnnounceParamsInfo params_;
                params_.Device = device;

                Announce(module_, params_, sendIfMethod_);
            }

            // Event: 'revoke' - Device removed from the bus notification
            template<typename MODULE>
            static void Revoke(const MODULE& module_, const JsonData::USBHub::AnnounceParamsInfo& params, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                module_.Notify(_T("revoke"), params, sendIfMethod_);
            }

            // Event: 'revoke' - Device removed from the bus notification
            template<typename MODULE>
            static void Revoke(const MODULE& module_, const JsonData::USBHub::DeviceMetadataInfo& device, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                JsonData::USBHub::AnnounceParamsInfo params_;
                params_.Device = device;

                Revoke(module_, params_, sendIfMethod_);
            }

            // Event: 'revoke' - Device removed from the bus notification
            template<typename MODULE>
            static void Revoke(const MODULE& module_, const IUSBHub::DeviceMetadata& device, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                JsonData::USBHub::AnnounceParamsInfo params_;
                params_.Device = device;

                Revoke(module_, params_, sendIfMethod_);
            }

        } // namespace Event

        POP_WARNING()
        POP_WARNING()
        POP_WARNING()

    } // namespace JUSBHub

} // namespace Exchange

} // namespace Thunder

