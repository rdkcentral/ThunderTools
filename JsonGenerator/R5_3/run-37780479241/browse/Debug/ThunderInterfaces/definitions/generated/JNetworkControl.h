// Generated automatically from 'INetworkControl.h'. DO NOT EDIT.

#pragma once
#include "Module.h"
#include "JsonData_NetworkControl.h"
#include <interfaces/INetworkControl.h>

namespace Thunder {

namespace Exchange {

    namespace JNetworkControl {

        namespace Version {

            constexpr uint8_t Major = 1;
            constexpr uint8_t Minor = 0;
            constexpr uint8_t Patch = 0;

        } // namespace Version

        PUSH_WARNING(DISABLE_WARNING_UNUSED_FUNCTIONS)
        PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
        PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

        template<typename MODULE>
        static void Register(MODULE& _module__, INetworkControl* _implementation__)
        {
            ASSERT(_implementation__ != nullptr);

            _module__.PluginHost::JSONRPC::RegisterVersion(_T("JNetworkControl"), Version::Major, Version::Minor, Version::Patch);

            // Register methods and properties...

            // Method: 'flush' - Flush and reload requested interface
            _module__.PluginHost::JSONRPC::template Register<JsonData::NetworkControl::FlushParamsData, void>(_T("flush"),
                [_implementation__](const JsonData::NetworkControl::FlushParamsData& params) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                        _errorCode__ = Core::ERROR_BAD_REQUEST;
                    }
                    else {
                        const string _interface_{params.Interface};

                        _errorCode__ = _implementation__->Flush(_interface_);

                    }

                    return (_errorCode__);
                });

            // Property: 'interfaces' - Currently available interfaces (r/o)
            _module__.PluginHost::JSONRPC::template Register<void, Core::JSON::ArrayType<Core::JSON::String>>(_T("interfaces"),
                [_implementation__](Core::JSON::ArrayType<Core::JSON::String>& result) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    ::Thunder::RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>* _result_{};

                    _errorCode__ = _implementation__->Interfaces(_result_);

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

            // Indexed Property: 'status' - Status of requested interface (r/o)
            _module__.PluginHost::JSONRPC::template Register<void, Core::JSON::EnumType<Exchange::INetworkControl::StatusType>, std::function<uint32_t(const string&, Core::JSON::EnumType<Exchange::INetworkControl::StatusType>&)>>(_T("status"),
                [_implementation__](const string& interface, Core::JSON::EnumType<Exchange::INetworkControl::StatusType>& result) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if (interface.empty() == true) {
                        _errorCode__ = Core::ERROR_BAD_REQUEST;
                    }

                    if (_errorCode__ == Core::ERROR_NONE) {
                        Exchange::INetworkControl::StatusType _result_{};

                        _errorCode__ = _implementation__->Status(interface, _result_);

                        if (_errorCode__ == Core::ERROR_NONE) {
                            result = _result_;
                        }
                    }

                    return (_errorCode__);
                });

            // Indexed Property: 'network' - Network info of requested interface
            _module__.PluginHost::JSONRPC::template Register<JsonData::NetworkControl::NetworkData, Core::JSON::ArrayType<JsonData::NetworkControl::NetworkInfoInfo>, std::function<uint32_t(const string&, const JsonData::NetworkControl::NetworkData&, Core::JSON::ArrayType<JsonData::NetworkControl::NetworkInfoInfo>&)>>(_T("network"),
                [_implementation__](const string& interface, const JsonData::NetworkControl::NetworkData& params, Core::JSON::ArrayType<JsonData::NetworkControl::NetworkInfoInfo>& result) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if (interface.empty() == true) {
                        _errorCode__ = Core::ERROR_BAD_REQUEST;
                    }

                    if (_errorCode__ == Core::ERROR_NONE) {

                        if (params.IsSet() == false) {
                            ::Thunder::RPC::IIteratorType<INetworkControl::NetworkInfo, ID_NETWORKCONTROL_NETWORK_INFO_ITERATOR>* _result_{};

                            _errorCode__ = (static_cast<const INetworkControl*>(_implementation__))->Network(interface, _result_);

                            if (_errorCode__ == Core::ERROR_NONE) {
                                result.Set(true);

                                if (_result_ != nullptr) {
                                    Exchange::INetworkControl::NetworkInfo _resultItem__{};
                                    while (_result_->Next(_resultItem__) == true) { result.Add() = _resultItem__; }
                                    _result_->Release();
                                }
                            }
                        }
                        else {

                            if (params.IsDataValid() == false) {
                                _errorCode__ = Core::ERROR_BAD_REQUEST;
                            }
                            else {
                                ::Thunder::RPC::IIteratorType<INetworkControl::NetworkInfo, ID_NETWORKCONTROL_NETWORK_INFO_ITERATOR>* _value_{};
                                std::list<Exchange::INetworkControl::NetworkInfo> _valueElements_{};
                                auto _valueIterator_ = params.Value.Elements();
                                while (_valueIterator_.Next() == true) { _valueElements_.push_back(_valueIterator_.Current()); }
                                using _valueIteratorImplType_ = ::Thunder::RPC::IteratorType<::Thunder::RPC::IIteratorType<INetworkControl::NetworkInfo, ID_NETWORKCONTROL_NETWORK_INFO_ITERATOR>>;
                                _value_ = Core::ServiceType<_valueIteratorImplType_>::Create<::Thunder::RPC::IIteratorType<INetworkControl::NetworkInfo, ID_NETWORKCONTROL_NETWORK_INFO_ITERATOR>>(std::move(_valueElements_));
                                ASSERT(_value_ != nullptr);

                                _errorCode__ = _implementation__->Network(interface, static_cast<::Thunder::RPC::IIteratorType<INetworkControl::NetworkInfo, ID_NETWORKCONTROL_NETWORK_INFO_ITERATOR>* const&>(_value_));

                            }

                            result.Null(true);
                        }
                    }

                    return (_errorCode__);
                });

            // Property: 'dns' - DNS list
            _module__.PluginHost::JSONRPC::template Register<JsonData::NetworkControl::DNSData, Core::JSON::ArrayType<Core::JSON::String>>(_T("dns"),
                [_implementation__](const JsonData::NetworkControl::DNSData& params, Core::JSON::ArrayType<Core::JSON::String>& result) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if (params.IsSet() == false) {
                        ::Thunder::RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>* _result_{};

                        _errorCode__ = (static_cast<const INetworkControl*>(_implementation__))->DNS(_result_);

                        if (_errorCode__ == Core::ERROR_NONE) {
                            result.Set(true);

                            if (_result_ != nullptr) {
                                string _resultItem__{};
                                while (_result_->Next(_resultItem__) == true) { result.Add() = _resultItem__; }
                                _result_->Release();
                            }
                        }
                    }
                    else {

                        if (params.IsDataValid() == false) {
                            _errorCode__ = Core::ERROR_BAD_REQUEST;
                        }
                        else {
                            ::Thunder::RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>* _value_{};
                            std::list<string> _valueElements_{};
                            auto _valueIterator_ = params.Value.Elements();
                            while (_valueIterator_.Next() == true) { _valueElements_.push_back(_valueIterator_.Current()); }
                            using _valueIteratorImplType_ = ::Thunder::RPC::IteratorType<::Thunder::RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>>;
                            _value_ = Core::ServiceType<_valueIteratorImplType_>::Create<::Thunder::RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>>(std::move(_valueElements_));
                            ASSERT(_value_ != nullptr);

                            _errorCode__ = _implementation__->DNS(static_cast<::Thunder::RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>* const&>(_value_));

                        }

                        result.Null(true);
                    }

                    return (_errorCode__);
                });

            // Indexed Property: 'up' - Provides given requested interface is up or not
            _module__.PluginHost::JSONRPC::template Register<JsonData::NetworkControl::UpData, Core::JSON::Boolean, std::function<uint32_t(const string&, const JsonData::NetworkControl::UpData&, Core::JSON::Boolean&)>>(_T("up"),
                [_implementation__](const string& interface, const JsonData::NetworkControl::UpData& params, Core::JSON::Boolean& result) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if (interface.empty() == true) {
                        _errorCode__ = Core::ERROR_BAD_REQUEST;
                    }

                    if (_errorCode__ == Core::ERROR_NONE) {

                        if (params.IsSet() == false) {
                            bool _result_{};

                            _errorCode__ = (static_cast<const INetworkControl*>(_implementation__))->Up(interface, _result_);

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

                                _errorCode__ = _implementation__->Up(interface, _value_);

                            }

                            result.Null(true);
                        }
                    }

                    return (_errorCode__);
                });

        }

        template<typename MODULE>
        static void Unregister(MODULE& _module__)
        {
            // Unregister methods and properties...
            _module__.PluginHost::JSONRPC::Unregister(_T("flush"));
            _module__.PluginHost::JSONRPC::Unregister(_T("interfaces"));
            _module__.PluginHost::JSONRPC::Unregister(_T("status"));
            _module__.PluginHost::JSONRPC::Unregister(_T("network"));
            _module__.PluginHost::JSONRPC::Unregister(_T("dns"));
            _module__.PluginHost::JSONRPC::Unregister(_T("up"));
        }

        namespace Event {

            // Event: 'update' - Signal interface update
            template<typename MODULE>
            static void Update(const MODULE& module_, const JsonData::NetworkControl::UpdateParamsData& params, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                module_.Notify(_T("update"), params, sendIfMethod_);
            }

            // Event: 'update' - Signal interface update
            template<typename MODULE>
            static void Update(const MODULE& module_, const Core::JSON::String& interfaceName, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                JsonData::NetworkControl::UpdateParamsData params_;
                params_.InterfaceName = interfaceName;

                Update(module_, params_, sendIfMethod_);
            }

            // Event: 'update' - Signal interface update
            template<typename MODULE>
            static void Update(const MODULE& module_, const string& interfaceName, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                JsonData::NetworkControl::UpdateParamsData params_;
                params_.InterfaceName = interfaceName;

                Update(module_, params_, sendIfMethod_);
            }

        } // namespace Event

        POP_WARNING()
        POP_WARNING()
        POP_WARNING()

    } // namespace JNetworkControl

} // namespace Exchange

} // namespace Thunder

