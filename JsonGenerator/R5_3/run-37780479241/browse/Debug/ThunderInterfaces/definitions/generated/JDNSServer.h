// Generated automatically from 'IDNSServer.h'. DO NOT EDIT.

#pragma once
#include "Module.h"
#include "JsonData_DNSServer.h"
#include <interfaces/IDNSServer.h>

namespace Thunder {

namespace Exchange {

    namespace JDNSServer {

        namespace Version {

            constexpr uint8_t Major = 1;
            constexpr uint8_t Minor = 0;
            constexpr uint8_t Patch = 0;

        } // namespace Version

        PUSH_WARNING(DISABLE_WARNING_UNUSED_FUNCTIONS)
        PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
        PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

        template<typename MODULE>
        static void Register(MODULE& _module__, IDNSServer* _implementation__)
        {
            ASSERT(_implementation__ != nullptr);

            _module__.PluginHost::JSONRPC::RegisterVersion(_T("JDNSServer"), Version::Major, Version::Minor, Version::Patch);

            // Register methods and properties...

            // Method: 'findByKey'
            _module__.PluginHost::JSONRPC::template Register<JsonData::DNSServer::FindByKeyParamsData, JsonData::DNSServer::RecordInfo>(_T("findByKey"),
                [_implementation__](const JsonData::DNSServer::FindByKeyParamsData& params, JsonData::DNSServer::RecordInfo& entry) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                        _errorCode__ = Core::ERROR_BAD_REQUEST;
                    }
                    else {
                        const string _designator_{params.Designator};
                        const string _key_{params.Key};
                        Exchange::IDNSServer::Record _entry_{};

                        _errorCode__ = _implementation__->FindByKey(_designator_, _key_, _entry_);

                        if (_errorCode__ == Core::ERROR_NONE) {
                            entry.Set(true);
                            entry = _entry_;
                        }
                    }

                    return (_errorCode__);
                });

            // Method: 'countByType'
            _module__.PluginHost::JSONRPC::template Register<JsonData::DNSServer::CountByTypeParamsData, Core::JSON::DecUInt8>(_T("countByType"),
                [_implementation__](const JsonData::DNSServer::CountByTypeParamsData& params, Core::JSON::DecUInt8& index) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                        _errorCode__ = Core::ERROR_BAD_REQUEST;
                    }
                    else {
                        const string _designator_{params.Designator};
                        const Exchange::IDNSServer::Record::type _kind_{params.Kind};
                        uint8_t _index_{};

                        _errorCode__ = _implementation__->CountByType(_designator_, _kind_, _index_);

                        if (_errorCode__ == Core::ERROR_NONE) {
                            index = _index_;
                        }
                    }

                    return (_errorCode__);
                });

            // Method: 'findByType'
            _module__.PluginHost::JSONRPC::template Register<JsonData::DNSServer::FindByTypeParamsData, JsonData::DNSServer::RecordInfo>(_T("findByType"),
                [_implementation__](const JsonData::DNSServer::FindByTypeParamsData& params, JsonData::DNSServer::RecordInfo& entry) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                        _errorCode__ = Core::ERROR_BAD_REQUEST;
                    }
                    else {
                        const string _designator_{params.Designator};
                        const Exchange::IDNSServer::Record::type _kind_{params.Kind};
                        const uint8_t _index_{params.Index};
                        Exchange::IDNSServer::Record _entry_{};

                        _errorCode__ = _implementation__->FindByType(_designator_, _kind_, _index_, _entry_);

                        if (_errorCode__ == Core::ERROR_NONE) {
                            entry.Set(true);
                            entry = _entry_;
                        }
                    }

                    return (_errorCode__);
                });

            // Method: 'add'
            _module__.PluginHost::JSONRPC::template Register<JsonData::DNSServer::AddParamsData, void>(_T("add"),
                [_implementation__](const JsonData::DNSServer::AddParamsData& params) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                        _errorCode__ = Core::ERROR_BAD_REQUEST;
                    }
                    else {
                        const Exchange::IDNSServer::Record _entry_(params.Entry);

                        _errorCode__ = _implementation__->Add(_entry_);

                    }

                    return (_errorCode__);
                });

            // Method: 'remove'
            _module__.PluginHost::JSONRPC::template Register<JsonData::DNSServer::RemoveParamsData, void>(_T("remove"),
                [_implementation__](const JsonData::DNSServer::RemoveParamsData& params) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                        _errorCode__ = Core::ERROR_BAD_REQUEST;
                    }
                    else {
                        const Exchange::IDNSServer::Record _record_(params.Record);

                        _errorCode__ = _implementation__->Remove(_record_);

                    }

                    return (_errorCode__);
                });

        }

        template<typename MODULE>
        static void Unregister(MODULE& _module__)
        {
            // Unregister methods and properties...
            _module__.PluginHost::JSONRPC::Unregister(_T("findByKey"));
            _module__.PluginHost::JSONRPC::Unregister(_T("countByType"));
            _module__.PluginHost::JSONRPC::Unregister(_T("findByType"));
            _module__.PluginHost::JSONRPC::Unregister(_T("add"));
            _module__.PluginHost::JSONRPC::Unregister(_T("remove"));
        }

        POP_WARNING()
        POP_WARNING()
        POP_WARNING()

    } // namespace JDNSServer

} // namespace Exchange

} // namespace Thunder

