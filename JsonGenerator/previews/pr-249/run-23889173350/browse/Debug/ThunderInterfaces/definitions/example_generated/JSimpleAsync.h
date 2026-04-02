// Generated automatically from 'ISimpleAsync.h'. DO NOT EDIT.

#pragma once
#include "Module.h"
#include "JsonData_SimpleAsync.h"
#include <example_interfaces/ISimpleAsync.h>

namespace Thunder {

namespace Example {

    namespace JSimpleAsync {

        namespace Version {

            constexpr uint8_t Major = 1;
            constexpr uint8_t Minor = 0;
            constexpr uint8_t Patch = 0;

        } // namespace Version

        namespace Async {

            namespace Connect {

                // Event: 'connect'
                template<typename MODULE>
                static void Complete(const MODULE& module_, const string& id_, const JsonData::SimpleAsync::CompleteParamsInfo& params, typename MODULE::SendIfMethodIndexed sendIfMethod_ = nullptr)
                {
                    if (sendIfMethod_ == nullptr) {
                        module_.Notify(_T("connect"), params, [&id_](const string&, const string& index_) -> bool {
                            Core::hresult _errorCode__ = Core::ERROR_NONE;

                            if (index_.empty() == true) {
                                _errorCode__ = Core::ERROR_BAD_REQUEST;
                            }
                            return ((_errorCode__ == Core::ERROR_NONE) && (id_ == index_));
                        });
                    }
                    else {
                        module_.Notify(_T("connect"), params, sendIfMethod_);
                    }
                }

                // Event: 'connect'
                template<typename MODULE>
                static void Complete(const MODULE& module_, const string& id_, const Core::JSON::String& address, const Core::JSON::EnumType<Example::ISimpleAsync::state>& state, typename MODULE::SendIfMethodIndexed sendIfMethod_ = nullptr)
                {
                    JsonData::SimpleAsync::CompleteParamsInfo params_;
                    params_.Address = address;
                    params_.State = state;

                    Complete(module_, id_, params_, sendIfMethod_);
                }

                // Event: 'connect'
                template<typename MODULE>
                static void Complete(const MODULE& module_, const string& id_, const Core::OptionalType<std::vector<uint8_t>>& address, const ISimpleAsync::state state, typename MODULE::SendIfMethodIndexed sendIfMethod_ = nullptr)
                {
                    JsonData::SimpleAsync::CompleteParamsInfo params_;

                    if (address.IsSet() == true) {
                        string _addressEncoded__;
                        Core::ToHexString(address.Value(), _addressEncoded__, TCHAR(':'));
                        params_.Address = std::move(_addressEncoded__);
                    }
                    params_.State = state;

                    Complete(module_, id_, params_, sendIfMethod_);
                }

            } // namespace Connect

        } // namespace Async

        class CallbackImplementation : public Example::ISimpleAsync::ICallback {
        public:
            CallbackImplementation() = delete;
            CallbackImplementation(const CallbackImplementation&) = delete;
            CallbackImplementation(CallbackImplementation&&) = delete;
            CallbackImplementation& operator=(CallbackImplementation&&) = delete;
            CallbackImplementation& operator=(const CallbackImplementation&) = delete;

            CallbackImplementation(PluginHost::JSONRPC& module, const string& id)
                : _module(module)
                , _id(id)
            {
            }
            ~CallbackImplementation() override
            {
            }

            void Complete(const Core::OptionalType<std::vector<uint8_t>>& address, const ISimpleAsync::state state) override
            {
                Async::Connect::Complete(_module, _id, address, state);
            }

            BEGIN_INTERFACE_MAP(CallbackImplementation)
                INTERFACE_ENTRY(Example::ISimpleAsync::ICallback)
            END_INTERFACE_MAP

        private:
            PluginHost::JSONRPC& _module;
            string _id;
        };

        PUSH_WARNING(DISABLE_WARNING_UNUSED_FUNCTIONS)
        PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
        PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

        template<typename MODULE>
        static void Register(MODULE& _module__, ISimpleAsync* _implementation__)
        {
            ASSERT(_implementation__ != nullptr);

            _module__.PluginHost::JSONRPC::RegisterVersion(_T("JSimpleAsync"), Version::Major, Version::Minor, Version::Patch);

            // Register methods and properties...

            // Method: 'connect' - Connects to a server
            _module__.PluginHost::JSONRPC::template Register<JsonData::SimpleAsync::ConnectParamsData, void, std::function<uint32_t(const Core::JSONRPC::Context&, const JsonData::SimpleAsync::ConnectParamsData&)>>(_T("connect"),
                [_implementation__, &_module__](const Core::JSONRPC::Context& context_, const JsonData::SimpleAsync::ConnectParamsData& params) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                        _errorCode__ = Core::ERROR_BAD_REQUEST;
                    }
                    else {
                        std::vector<uint8_t> _addressContainer_{};
                        Core::FromHexString(params.Address.Value(), _addressContainer_, 6, TCHAR(':'));
                        Core::OptionalType<std::vector<uint8_t>> _address_{};
                        _address_ = std::move(_addressContainer_);
                        const Core::OptionalType<uint16_t> _timeout_{params.Timeout};
                        const string _cb_asyncId_{params.Cb};
                        Example::ISimpleAsync::ICallback* _cb_ = Core::ServiceType<CallbackImplementation>::Create<Example::ISimpleAsync::ICallback>(_module__, _cb_asyncId_);
                        const uint32_t _subscribe_result__ = _module__.Subscribe(context_.ChannelId(), _T("connect"), _cb_asyncId_, _T(""), true /* one-off */);
                        ASSERT(_cb_ != nullptr);

                        if (_subscribe_result__ == Core::ERROR_NONE) {
                            _errorCode__ = _implementation__->Connect(_address_, _timeout_, _cb_);

                            if (_errorCode__ != Core::ERROR_NONE) {
                                _module__.Unsubscribe(context_.ChannelId(), _T("connect"), _cb_asyncId_, _T(""));
                            }
                        }
                        else {
                            _errorCode__ = Core::ERROR_UNKNOWN_KEY;
                        }

                        if (_cb_ != nullptr) {
                            _cb_->Release();
                        }

                    }

                    return (_errorCode__);
                });

            // Method: 'abort' - Aborts connecting to a server
            _module__.PluginHost::JSONRPC::template Register<void, void>(_T("abort"),
                [_implementation__]() -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    _errorCode__ = _implementation__->Abort();

                    return (_errorCode__);
                });

            // Method: 'disconnect' - Disconnects from the server
            _module__.PluginHost::JSONRPC::template Register<void, void>(_T("disconnect"),
                [_implementation__]() -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    _errorCode__ = _implementation__->Disconnect();

                    return (_errorCode__);
                });

            // Method: 'link' - Links a device
            _module__.PluginHost::JSONRPC::template Register<JsonData::SimpleAsync::LinkParamsInfo, void>(_T("link"),
                [_implementation__](const JsonData::SimpleAsync::LinkParamsInfo& params) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                        _errorCode__ = Core::ERROR_BAD_REQUEST;
                    }
                    else {
                        uint8_t _address_[6]{};
                        uint32_t _addressSize__(6);
                        Core::FromString(params.Address.Value(), _address_, _addressSize__);

                        _errorCode__ = _implementation__->Link(_address_);

                    }

                    return (_errorCode__);
                });

            // Method: 'unlink' - Unlinks a device
            _module__.PluginHost::JSONRPC::template Register<JsonData::SimpleAsync::LinkParamsInfo, void>(_T("unlink"),
                [_implementation__](const JsonData::SimpleAsync::LinkParamsInfo& params) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                        _errorCode__ = Core::ERROR_BAD_REQUEST;
                    }
                    else {
                        uint8_t _address_[6]{};
                        uint32_t _addressSize__(6);
                        Core::FromString(params.Address.Value(), _address_, _addressSize__);

                        _errorCode__ = _implementation__->Unlink(_address_);

                    }

                    return (_errorCode__);
                });

            // Method: 'bind' - Binds a device
            _module__.PluginHost::JSONRPC::template Register<JsonData::SimpleAsync::BindParamsInfo, void>(_T("bind"),
                [_implementation__](const JsonData::SimpleAsync::BindParamsInfo& params) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                        _errorCode__ = Core::ERROR_BAD_REQUEST;
                    }
                    else {
                        const Core::MACAddress _address_{params.Address.Value().c_str()};

                        _errorCode__ = _implementation__->Bind(_address_);

                    }

                    return (_errorCode__);
                });

            // Method: 'unbind' - Unlinks a device
            _module__.PluginHost::JSONRPC::template Register<JsonData::SimpleAsync::BindParamsInfo, void>(_T("unbind"),
                [_implementation__](const JsonData::SimpleAsync::BindParamsInfo& params) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                        _errorCode__ = Core::ERROR_BAD_REQUEST;
                    }
                    else {
                        const Core::MACAddress _address_{params.Address.Value().c_str()};

                        _errorCode__ = _implementation__->Unbind(_address_);

                    }

                    return (_errorCode__);
                });

            // Method: 'tables'
            _module__.PluginHost::JSONRPC::template Register<JsonData::SimpleAsync::TablesParamsInfo, Core::JSON::ArrayType<Core::JSON::String>>(_T("tables"),
                [_implementation__](const JsonData::SimpleAsync::TablesParamsInfo& params, Core::JSON::ArrayType<Core::JSON::String>& stringTables) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                        _errorCode__ = Core::ERROR_BAD_REQUEST;
                    }
                    else {
                        const bool _fill_{params.Fill};
                        std::vector<string> _stringTables_;

                        _errorCode__ = _implementation__->Tables(_fill_, _stringTables_);

                        if (_errorCode__ == Core::ERROR_NONE) {
                            stringTables.Set(true);
                            for (auto const& _elem__ : _stringTables_ ) { stringTables.Add() = _elem__; }
                        }
                    }

                    return (_errorCode__);
                });

            // Method: 'tables2'
            _module__.PluginHost::JSONRPC::template Register<JsonData::SimpleAsync::TablesParamsInfo, JsonData::SimpleAsync::Tables2ResultData>(_T("tables2"),
                [_implementation__](const JsonData::SimpleAsync::TablesParamsInfo& params, JsonData::SimpleAsync::Tables2ResultData& result) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                        _errorCode__ = Core::ERROR_BAD_REQUEST;
                    }
                    else {
                        const bool _fill_{params.Fill};
                        std::vector<string> _stringTables_;
                        std::vector<uint8_t> _intTables_;

                        _errorCode__ = _implementation__->Tables2(_fill_, _stringTables_, _intTables_);

                        if (_errorCode__ == Core::ERROR_NONE) {
                            result.StringTables.Set(true);
                            for (auto const& _elem__ : _stringTables_ ) { result.StringTables.Add() = _elem__; }
                            result.IntTables.Set(true);
                            for (auto const& _elem__ : _intTables_ ) { result.IntTables.Add() = _elem__; }
                        }
                    }

                    return (_errorCode__);
                });

            // Method: 'tables3'
            _module__.PluginHost::JSONRPC::template Register<JsonData::SimpleAsync::TablesParamsInfo, Core::JSON::ArrayType<Core::JSON::String>>(_T("tables3"),
                [_implementation__](const JsonData::SimpleAsync::TablesParamsInfo& params, Core::JSON::ArrayType<Core::JSON::String>& stringTables) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                        _errorCode__ = Core::ERROR_BAD_REQUEST;
                    }
                    else {
                        const bool _fill_{params.Fill};
                        Core::OptionalType<std::vector<string>> _stringTables_;

                        _errorCode__ = _implementation__->Tables3(_fill_, _stringTables_);

                        if (_errorCode__ == Core::ERROR_NONE) {

                            if (_stringTables_.IsSet() == true) {
                                for (auto const& _elem__ : _stringTables_.Value() ) { stringTables.Add() = _elem__; }
                            }
                        }
                    }

                    return (_errorCode__);
                });

            // Method: 'tables4'
            _module__.PluginHost::JSONRPC::template Register<JsonData::SimpleAsync::TablesParamsInfo, Core::JSON::ArrayType<Core::JSON::String>>(_T("tables4"),
                [_implementation__](const JsonData::SimpleAsync::TablesParamsInfo& params, Core::JSON::ArrayType<Core::JSON::String>& stringTables) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                        _errorCode__ = Core::ERROR_BAD_REQUEST;
                    }
                    else {
                        const bool _fill_{params.Fill};
                        ::Thunder::RPC::IIteratorType<string, ::Thunder::RPC::ID_STRINGITERATOR>* _stringTables_{};

                        _errorCode__ = _implementation__->Tables4(_fill_, _stringTables_);

                        if (_errorCode__ == Core::ERROR_NONE) {
                            stringTables.Set(true);

                            if (_stringTables_ != nullptr) {
                                string _resultItem__{};
                                while (_stringTables_->Next(_resultItem__) == true) { stringTables.Add() = _resultItem__; }
                                _stringTables_->Release();
                            }
                        }
                    }

                    return (_errorCode__);
                });

            // Method: 'tables5'
            _module__.PluginHost::JSONRPC::template Register<JsonData::SimpleAsync::TablesParamsInfo, JsonData::SimpleAsync::Tables5ResultData>(_T("tables5"),
                [_implementation__](const JsonData::SimpleAsync::TablesParamsInfo& params, JsonData::SimpleAsync::Tables5ResultData& result) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                        _errorCode__ = Core::ERROR_BAD_REQUEST;
                    }
                    else {
                        const bool _fill_{params.Fill};
                        ::Thunder::RPC::IIteratorType<string, ::Thunder::RPC::ID_STRINGITERATOR>* _stringTables_{};
                        ::Thunder::RPC::IIteratorType<uint32_t, ::Thunder::RPC::ID_VALUEITERATOR>* _intTables_{};

                        _errorCode__ = _implementation__->Tables5(_fill_, _stringTables_, _intTables_);

                        if (_errorCode__ == Core::ERROR_NONE) {
                            result.StringTables.Set(true);

                            if (_stringTables_ != nullptr) {
                                string _stringTablesItem__{};
                                while (_stringTables_->Next(_stringTablesItem__) == true) { result.StringTables.Add() = _stringTablesItem__; }
                                _stringTables_->Release();
                            }
                            result.IntTables.Set(true);

                            if (_intTables_ != nullptr) {
                                uint32_t _intTablesItem__{};
                                while (_intTables_->Next(_intTablesItem__) == true) { result.IntTables.Add() = _intTablesItem__; }
                                _intTables_->Release();
                            }
                        }
                    }

                    return (_errorCode__);
                });

            // Method: 'tables6'
            _module__.PluginHost::JSONRPC::template Register<JsonData::SimpleAsync::TablesParamsInfo, JsonData::SimpleAsync::RecordInfo>(_T("tables6"),
                [_implementation__](const JsonData::SimpleAsync::TablesParamsInfo& params, JsonData::SimpleAsync::RecordInfo& pod) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                        _errorCode__ = Core::ERROR_BAD_REQUEST;
                    }
                    else {
                        const bool _fill_{params.Fill};
                        Example::ISimpleAsync::Record _pod_{};

                        _errorCode__ = _implementation__->Tables6(_fill_, _pod_);

                        if (_errorCode__ == Core::ERROR_NONE) {
                            pod.Set(true);
                            pod = _pod_;
                        }
                    }

                    return (_errorCode__);
                });

            // Method: 'tables7'
            _module__.PluginHost::JSONRPC::template Register<JsonData::SimpleAsync::TablesParamsInfo, JsonData::SimpleAsync::RecordInfo>(_T("tables7"),
                [_implementation__](const JsonData::SimpleAsync::TablesParamsInfo& params, JsonData::SimpleAsync::RecordInfo& pod) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                        _errorCode__ = Core::ERROR_BAD_REQUEST;
                    }
                    else {
                        const bool _fill_{params.Fill};
                        Core::OptionalType<Example::ISimpleAsync::Record> _pod_{};

                        _errorCode__ = _implementation__->Tables7(_fill_, _pod_);

                        if (_errorCode__ == Core::ERROR_NONE) {
                            pod = _pod_;
                        }
                    }

                    return (_errorCode__);
                });

            // Method: 'tables8'
            _module__.PluginHost::JSONRPC::template Register<JsonData::SimpleAsync::TablesParamsInfo, JsonData::SimpleAsync::Record2Info>(_T("tables8"),
                [_implementation__](const JsonData::SimpleAsync::TablesParamsInfo& params, JsonData::SimpleAsync::Record2Info& pod) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                        _errorCode__ = Core::ERROR_BAD_REQUEST;
                    }
                    else {
                        const bool _fill_{params.Fill};
                        Core::OptionalType<Example::ISimpleAsync::Record2> _pod_{};

                        _errorCode__ = _implementation__->Tables8(_fill_, _pod_);

                        if (_errorCode__ == Core::ERROR_NONE) {
                            pod = _pod_;
                        }
                    }

                    return (_errorCode__);
                });

            // Method: 'tables9'
            _module__.PluginHost::JSONRPC::template Register<JsonData::SimpleAsync::TablesParamsInfo, JsonData::SimpleAsync::Record2Info>(_T("tables9"),
                [_implementation__](const JsonData::SimpleAsync::TablesParamsInfo& params, JsonData::SimpleAsync::Record2Info& pod) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                        _errorCode__ = Core::ERROR_BAD_REQUEST;
                    }
                    else {
                        const bool _fill_{params.Fill};
                        Example::ISimpleAsync::Record2 _pod_{};

                        _errorCode__ = _implementation__->Tables9(_fill_, _pod_);

                        if (_errorCode__ == Core::ERROR_NONE) {
                            pod = _pod_;
                        }
                    }

                    return (_errorCode__);
                });

            // Method: 'optionalResult'
            _module__.PluginHost::JSONRPC::template Register<JsonData::SimpleAsync::TablesParamsInfo, Core::JSON::String>(_T("optionalResult"),
                [_implementation__](const JsonData::SimpleAsync::TablesParamsInfo& params, Core::JSON::String& result) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                        _errorCode__ = Core::ERROR_BAD_REQUEST;
                    }
                    else {
                        const bool _fill_{params.Fill};
                        Core::OptionalType<string> _result_{};

                        _errorCode__ = _implementation__->OptionalResult(_fill_, _result_);

                        if (_errorCode__ == Core::ERROR_NONE) {
                            result = _result_;
                        }
                    }

                    return (_errorCode__);
                });

            // Indexed Property: 'connected' - Connection status (r/o)
            _module__.PluginHost::JSONRPC::template Register<void, Core::JSON::Boolean, std::function<uint32_t(const string&, Core::JSON::Boolean&)>>(_T("connected"),
                [_implementation__](const string& address, Core::JSON::Boolean& result) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    std::vector<uint8_t> _addressConv__{};

                    if (address.empty() == true) {
                        _errorCode__ = Core::ERROR_BAD_REQUEST;
                    }
                    else {
                        const bool _addressConvResult__ = (Core::FromHexString(address, _addressConv__, 6, TCHAR(':')) != 0);

                        if ((_addressConvResult__ == false) || (_addressConv__.size() < 6) || (_addressConv__.size() > 6)) {
                            _errorCode__ = Core::ERROR_BAD_REQUEST;
                        }
                    }

                    if (_errorCode__ == Core::ERROR_NONE) {
                        bool _result_{};

                        _errorCode__ = _implementation__->Connected(_addressConv__, _result_);

                        if (_errorCode__ == Core::ERROR_NONE) {
                            result = _result_;
                        }
                    }

                    return (_errorCode__);
                });

            // Property: 'linkedDevice' - Linked device (r/o)
            _module__.PluginHost::JSONRPC::template Register<void, Core::JSON::String>(_T("linkedDevice"),
                [_implementation__](Core::JSON::String& result) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    uint8_t _result_[6]{};

                    _errorCode__ = _implementation__->LinkedDevice(_result_);

                    if (_errorCode__ == Core::ERROR_NONE) {
                        {
                            string _resultEncoded__;
                            Core::ToString(_result_, 6, true, _resultEncoded__);
                            result = std::move(_resultEncoded__);
                        }
                    }

                    return (_errorCode__);
                });

            // Indexed Property: 'metadata' - Device metadata
            _module__.PluginHost::JSONRPC::template Register<JsonData::SimpleAsync::MetadataInfo, Core::JSON::String, std::function<uint32_t(const string&, const JsonData::SimpleAsync::MetadataInfo&, Core::JSON::String&)>>(_T("metadata"),
                [_implementation__](const string& address, const JsonData::SimpleAsync::MetadataInfo& params, Core::JSON::String& result) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    uint8_t _addressConv__[6];

                    if (address.empty() == true) {
                        _errorCode__ = Core::ERROR_BAD_REQUEST;
                    }
                    else {
                        uint16_t _addressConvLength__(sizeof(_addressConv__));
                        Core::FromString(address, _addressConv__, _addressConvLength__);
                        const bool _addressConvResult__ = (_addressConvLength__ != 0);

                        if (_addressConvResult__ == false) {
                            _errorCode__ = Core::ERROR_BAD_REQUEST;
                        }
                    }

                    if (_errorCode__ == Core::ERROR_NONE) {

                        if (params.IsSet() == false) {
                            string _result_{};

                            _errorCode__ = (static_cast<const ISimpleAsync*>(_implementation__))->Metadata(_addressConv__, _result_);

                            if (_errorCode__ == Core::ERROR_NONE) {
                                result = _result_;
                            }
                        }
                        else {

                            if (params.IsDataValid() == false) {
                                _errorCode__ = Core::ERROR_BAD_REQUEST;
                            }
                            else {
                                const string _value_{params.Value};

                                _errorCode__ = _implementation__->Metadata(_addressConv__, _value_);

                            }

                            result.Null(true);
                        }
                    }

                    return (_errorCode__);
                });

            // Property: 'boundDevice' (r/o)
            _module__.PluginHost::JSONRPC::template Register<void, Core::JSON::String>(_T("boundDevice"),
                [_implementation__](Core::JSON::String& result) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    Core::MACAddress _result_{};

                    _errorCode__ = _implementation__->BoundDevice(_result_);

                    if (_errorCode__ == Core::ERROR_NONE) {
                        result = _result_.ToString();
                    }

                    return (_errorCode__);
                });

            // Indexed Property: 'type' - Device metadata
            _module__.PluginHost::JSONRPC::template Register<JsonData::SimpleAsync::MetadataInfo, Core::JSON::String, std::function<uint32_t(const string&, const JsonData::SimpleAsync::MetadataInfo&, Core::JSON::String&)>>(_T("type"),
                [_implementation__](const string& address, const JsonData::SimpleAsync::MetadataInfo& params, Core::JSON::String& result) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    Core::MACAddress _addressConv__{address.c_str()};

                    if (address.empty() == true) {
                        _errorCode__ = Core::ERROR_BAD_REQUEST;
                    }
                    else {
                        const bool _addressConvResult__ = _addressConv__.IsValid();

                        if (_addressConvResult__ == false) {
                            _errorCode__ = Core::ERROR_BAD_REQUEST;
                        }
                    }

                    if (_errorCode__ == Core::ERROR_NONE) {

                        if (params.IsSet() == false) {
                            string _result_{};

                            _errorCode__ = (static_cast<const ISimpleAsync*>(_implementation__))->Type(_addressConv__, _result_);

                            if (_errorCode__ == Core::ERROR_NONE) {
                                result = _result_;
                            }
                        }
                        else {

                            if (params.IsDataValid() == false) {
                                _errorCode__ = Core::ERROR_BAD_REQUEST;
                            }
                            else {
                                const string _value_{params.Value};

                                _errorCode__ = _implementation__->Type(_addressConv__, _value_);

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
            _module__.PluginHost::JSONRPC::Unregister(_T("connect"));
            _module__.PluginHost::JSONRPC::Unregister(_T("abort"));
            _module__.PluginHost::JSONRPC::Unregister(_T("disconnect"));
            _module__.PluginHost::JSONRPC::Unregister(_T("link"));
            _module__.PluginHost::JSONRPC::Unregister(_T("unlink"));
            _module__.PluginHost::JSONRPC::Unregister(_T("bind"));
            _module__.PluginHost::JSONRPC::Unregister(_T("unbind"));
            _module__.PluginHost::JSONRPC::Unregister(_T("tables"));
            _module__.PluginHost::JSONRPC::Unregister(_T("tables2"));
            _module__.PluginHost::JSONRPC::Unregister(_T("tables3"));
            _module__.PluginHost::JSONRPC::Unregister(_T("tables4"));
            _module__.PluginHost::JSONRPC::Unregister(_T("tables5"));
            _module__.PluginHost::JSONRPC::Unregister(_T("tables6"));
            _module__.PluginHost::JSONRPC::Unregister(_T("tables7"));
            _module__.PluginHost::JSONRPC::Unregister(_T("tables8"));
            _module__.PluginHost::JSONRPC::Unregister(_T("tables9"));
            _module__.PluginHost::JSONRPC::Unregister(_T("optionalResult"));
            _module__.PluginHost::JSONRPC::Unregister(_T("connected"));
            _module__.PluginHost::JSONRPC::Unregister(_T("linkedDevice"));
            _module__.PluginHost::JSONRPC::Unregister(_T("metadata"));
            _module__.PluginHost::JSONRPC::Unregister(_T("boundDevice"));
            _module__.PluginHost::JSONRPC::Unregister(_T("type"));
        }

        namespace Event {

            // Event: 'statusChanged' - Signals completion of the Connect method
            template<typename MODULE>
            static void StatusChanged(const MODULE& module_, const JsonData::SimpleAsync::StatusChangedParamsData& params, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                module_.Notify(_T("statusChanged"), params, sendIfMethod_);
            }

            // Event: 'statusChanged' - Signals completion of the Connect method
            template<typename MODULE>
            static void StatusChanged(const MODULE& module_, const Core::JSON::ArrayType<Core::JSON::DecUInt8>& address, const Core::JSON::Boolean& linked, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                JsonData::SimpleAsync::StatusChangedParamsData params_;
                params_.Address = address;
                params_.Linked = linked;

                StatusChanged(module_, params_, sendIfMethod_);
            }

            // Event: 'statusChanged' - Signals completion of the Connect method
            template<typename MODULE>
            static void StatusChanged(const MODULE& module_, const uint8_t address[6], const bool linked, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                JsonData::SimpleAsync::StatusChangedParamsData params_;
                ASSERT(address != nullptr);
                for (uint16_t _i__ = 0; _i__ < 6; _i__++) { params_.Address.Add() = address[_i__]; }
                params_.Linked = linked;

                StatusChanged(module_, params_, sendIfMethod_);
            }

            // Event: 'bindingChanged' - Signals completion of the Connect method
            template<typename MODULE>
            static void BindingChanged(const MODULE& module_, const Core::MACAddress& id_, const JsonData::SimpleAsync::BindingChangedParamsData& params, typename MODULE::SendIfMethodIndexed sendIfMethod_ = nullptr)
            {
                if (sendIfMethod_ == nullptr) {
                    module_.Notify(_T("bindingChanged"), params, [&id_](const string&, const string& index_) -> bool {
                        Core::hresult _errorCode__ = Core::ERROR_NONE;
                        Core::MACAddress _indexConv__{index_.c_str()};

                        if (index_.empty() == true) {
                            _errorCode__ = Core::ERROR_BAD_REQUEST;
                        }
                        else {
                            const bool _indexConvResult__ = _indexConv__.IsValid();
                        }

                        return ((_errorCode__ == Core::ERROR_NONE) && (id_ == _indexConv__));
                    });
                }
                else {
                    module_.Notify(_T("bindingChanged"), params, sendIfMethod_);
                }
            }

            // Event: 'bindingChanged' - Signals completion of the Connect method
            template<typename MODULE>
            static void BindingChanged(const MODULE& module_, const Core::MACAddress& id_, const Core::JSON::Boolean& bound, typename MODULE::SendIfMethodIndexed sendIfMethod_ = nullptr)
            {
                JsonData::SimpleAsync::BindingChangedParamsData params_;
                params_.Bound = bound;

                BindingChanged(module_, id_, params_, sendIfMethod_);
            }

            // Event: 'bindingChanged' - Signals completion of the Connect method
            template<typename MODULE>
            static void BindingChanged(const MODULE& module_, const Core::MACAddress& id_, const bool bound, typename MODULE::SendIfMethodIndexed sendIfMethod_ = nullptr)
            {
                JsonData::SimpleAsync::BindingChangedParamsData params_;
                params_.Bound = bound;

                BindingChanged(module_, id_, params_, sendIfMethod_);
            }

        } // namespace Event

        POP_WARNING()
        POP_WARNING()
        POP_WARNING()

    } // namespace JSimpleAsync

} // namespace Example

} // namespace Thunder

