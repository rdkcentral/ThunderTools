// Generated automatically from 'INetworkControl.h'. DO NOT EDIT.

#pragma once

#include "Module.h"
#include "JsonData_NetworkControl.h"
#include <interfaces/INetworkControl.h>

namespace WPEFramework {

namespace Exchange {

    namespace JNetworkControl {

        namespace Version {

            constexpr uint8_t Major = 1;
            constexpr uint8_t Minor = 0;
            constexpr uint8_t Patch = 0;

        } // namespace Version

        using JSONRPC = PluginHost::JSONRPC;

        PUSH_WARNING(DISABLE_WARNING_UNUSED_FUNCTIONS)

        static void Register(JSONRPC& _module_, INetworkControl* _impl_)
        {
            ASSERT(_impl_ != nullptr);

            _module_.RegisterVersion(_T("JNetworkControl"), Version::Major, Version::Minor, Version::Patch);

            // Register methods and properties...

            // Method: 'flush' - Flush and reload requested interface
            _module_.Register<JsonData::NetworkControl::FlushParamsData, void>(_T("flush"), 
                [_impl_](const JsonData::NetworkControl::FlushParamsData& params) -> uint32_t {
                    uint32_t _errorCode = Core::ERROR_NONE;

                    const string _interface{params.Interface};

                    _errorCode = _impl_->Flush(_interface);

                    return (_errorCode);
                });

            // Property: 'interfaces' - Currently available interfaces (r/o)
            _module_.Register<void, Core::JSON::ArrayType<Core::JSON::String>>(_T("interfaces"), 
                [_impl_](Core::JSON::ArrayType<Core::JSON::String>& result) -> uint32_t {
                    uint32_t _errorCode = Core::ERROR_NONE;

                    // read-only property get
                    ::WPEFramework::RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>* _result{};

                    _errorCode = _impl_->Interfaces(_result);

                    if (_errorCode == Core::ERROR_NONE) {

                        if (_result != nullptr) {
                            string _resultItem_{};
                            while (_result->Next(_resultItem_) == true) { result.Add() = _resultItem_; }
                            _result->Release();
                        }
                    }

                    return (_errorCode);
                });

            // Indexed Property: 'status' - Status of requested interface (r/o)
            _module_.Register<void, Core::JSON::EnumType<Exchange::INetworkControl::StatusType>, std::function<uint32_t(const string&,
                     Core::JSON::EnumType<Exchange::INetworkControl::StatusType>&)>>(_T("status"), 
                [_impl_](const string& _index_, Core::JSON::EnumType<Exchange::INetworkControl::StatusType>& result) -> uint32_t {
                    uint32_t _errorCode = Core::ERROR_NONE;

                    // read-only property get
                    Exchange::INetworkControl::StatusType _result{};

                    _errorCode = _impl_->Status(_index_, _result);

                    if (_errorCode == Core::ERROR_NONE) {
                        result = _result;
                    }

                    return (_errorCode);
                });

            // Indexed Property: 'network' - Network info of requested interface
            _module_.Register<JsonData::NetworkControl::NetworkData, Core::JSON::ArrayType<JsonData::NetworkControl::NetworkInfoInfo>,
                     std::function<uint32_t(const string&, const JsonData::NetworkControl::NetworkData&,
                     Core::JSON::ArrayType<JsonData::NetworkControl::NetworkInfoInfo>&)>>(_T("network"), 
                [_impl_](const string& _index_, const JsonData::NetworkControl::NetworkData& params,
                         Core::JSON::ArrayType<JsonData::NetworkControl::NetworkInfoInfo>& result) -> uint32_t {
                    uint32_t _errorCode = Core::ERROR_NONE;

                    if (params.IsSet() == false) {
                        // property get
                        ::WPEFramework::RPC::IIteratorType<INetworkControl::NetworkInfo, ID_NETWORKCONTROL_NETWORK_INFO_ITERATOR>* _result{};

                        _errorCode = (static_cast<const INetworkControl*>(_impl_))->Network(_index_, _result);

                        if (_errorCode == Core::ERROR_NONE) {

                            if (_result != nullptr) {
                                Exchange::INetworkControl::NetworkInfo _resultItem_{};
                                while (_result->Next(_resultItem_) == true) { result.Add() = _resultItem_; }
                                _result->Release();
                            }
                        }

                    } else {
                        // property set
                        std::list<Exchange::INetworkControl::NetworkInfo> _elements;
                        auto _Iterator = params.Value.Elements();
                        while (_Iterator.Next() == true) { _elements.push_back(_Iterator.Current()); }

                        ::WPEFramework::RPC::IIteratorType<INetworkControl::NetworkInfo,
                                 ID_NETWORKCONTROL_NETWORK_INFO_ITERATOR>* const _value{Core::Service<::WPEFramework::RPC::IteratorType<::WPEFramework::RPC::IIteratorType<INetworkControl::NetworkInfo,
                                 ID_NETWORKCONTROL_NETWORK_INFO_ITERATOR>>>::Create<::WPEFramework::RPC::IIteratorType<INetworkControl::NetworkInfo,
                                 ID_NETWORKCONTROL_NETWORK_INFO_ITERATOR>>(_elements)};

                        ASSERT(_value != nullptr); 

                        if ((_value != nullptr)) {
                            _errorCode = _impl_->Network(_index_, _value);
                            _value->Release();
                        } else {
                            _errorCode = Core::ERROR_GENERAL;
                        }

                        // result.Null(true);
                    }
                    return (_errorCode);
                });

            // Property: 'dns' - DNS list
            _module_.Register<JsonData::NetworkControl::DNSData, Core::JSON::ArrayType<Core::JSON::String>>(_T("dns"), 
                [_impl_](const JsonData::NetworkControl::DNSData& params, Core::JSON::ArrayType<Core::JSON::String>& result) -> uint32_t {
                    uint32_t _errorCode = Core::ERROR_NONE;

                    if (params.IsSet() == false) {
                        // property get
                        ::WPEFramework::RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>* _result{};

                        _errorCode = (static_cast<const INetworkControl*>(_impl_))->DNS(_result);

                        if (_errorCode == Core::ERROR_NONE) {

                            if (_result != nullptr) {
                                string _resultItem_{};
                                while (_result->Next(_resultItem_) == true) { result.Add() = _resultItem_; }
                                _result->Release();
                            }
                        }

                    } else {
                        // property set
                        std::list<string> _elements;
                        auto _Iterator = params.Value.Elements();
                        while (_Iterator.Next() == true) { _elements.push_back(_Iterator.Current()); }

                        ::WPEFramework::RPC::IIteratorType<string,
                                 RPC::ID_STRINGITERATOR>* const _value{Core::Service<::WPEFramework::RPC::IteratorType<::WPEFramework::RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>>>::Create<::WPEFramework::RPC::IIteratorType<string,
                                 RPC::ID_STRINGITERATOR>>(_elements)};

                        ASSERT(_value != nullptr); 

                        if ((_value != nullptr)) {
                            _errorCode = _impl_->DNS(_value);
                            _value->Release();
                        } else {
                            _errorCode = Core::ERROR_GENERAL;
                        }

                        // result.Null(true);
                    }
                    return (_errorCode);
                });

            // Indexed Property: 'up' - Provides given requested interface is up or not
            _module_.Register<JsonData::NetworkControl::UpData, Core::JSON::Boolean, std::function<uint32_t(const string&,
                     const JsonData::NetworkControl::UpData&, Core::JSON::Boolean&)>>(_T("up"), 
                [_impl_](const string& _index_, const JsonData::NetworkControl::UpData& params, Core::JSON::Boolean& result) -> uint32_t {
                    uint32_t _errorCode = Core::ERROR_NONE;

                    if (params.IsSet() == false) {
                        // property get
                        bool _result{};

                        _errorCode = (static_cast<const INetworkControl*>(_impl_))->Up(_index_, _result);

                        if (_errorCode == Core::ERROR_NONE) {
                            result = _result;
                        }

                    } else {
                        // property set
                        const bool _value{params.Value};

                        _errorCode = _impl_->Up(_index_, _value);

                        result.Null(true);
                    }
                    return (_errorCode);
                });

        }

        static void Unregister(JSONRPC& _module_)
        {
            // Unregister methods and properties...
            _module_.Unregister(_T("flush"));
            _module_.Unregister(_T("interfaces"));
            _module_.Unregister(_T("status"));
            _module_.Unregister(_T("network"));
            _module_.Unregister(_T("dns"));
            _module_.Unregister(_T("up"));
        }

        namespace Event {

            // Event: 'update'
            static void Update(const JSONRPC& _module_, const JsonData::NetworkControl::UpdateParamsData& params)
            {
                _module_.Notify(_T("update"), params);
            }

            // Event: 'update'
            static void Update(const JSONRPC& _module_, const Core::JSON::String& interfaceName)
            {
                JsonData::NetworkControl::UpdateParamsData _params_;
                _params_.InterfaceName = interfaceName;

                Update(_module_, _params_);
            }

            // Event: 'update'
            static void Update(const JSONRPC& _module_, const string& interfaceName)
            {
                JsonData::NetworkControl::UpdateParamsData _params_;
                _params_.InterfaceName = interfaceName;

                Update(_module_, _params_);
            }

        } // namespace Event

        POP_WARNING()

    } // namespace JNetworkControl

} // namespace Exchange

} // namespace WPEFramework

