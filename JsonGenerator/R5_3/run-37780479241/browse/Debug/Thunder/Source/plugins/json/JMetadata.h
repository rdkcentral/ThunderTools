// Generated automatically from 'IController.h'. DO NOT EDIT.

#pragma once

namespace Thunder {

namespace Exchange {

    namespace Controller {

        namespace JMetadata {

            namespace Version {

                constexpr uint8_t Major = 1;
                constexpr uint8_t Minor = 0;
                constexpr uint8_t Patch = 0;

            } // namespace Version

            PUSH_WARNING(DISABLE_WARNING_UNUSED_FUNCTIONS)
            PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
            PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

            template<typename MODULE>
            static void Register(MODULE& _module__, IMetadata* _implementation__)
            {
                ASSERT(_implementation__ != nullptr);

                _module__.PluginHost::JSONRPC::RegisterVersion(_T("JMetadata"), Version::Major, Version::Minor, Version::Patch);

                // Register methods and properties...

                // Indexed Property: 'services' - Services metadata (r/o)
                _module__.PluginHost::JSONRPC::template Register<void, Core::JSON::ArrayType<JsonData::Metadata::ServiceData>, std::function<uint32_t(const string&, Core::JSON::ArrayType<JsonData::Metadata::ServiceData>&)>>(_T("services"),
                    [_implementation__](const string& callsign, Core::JSON::ArrayType<JsonData::Metadata::ServiceData>& result) -> uint32_t {
                        uint32_t _errorCode__ = Core::ERROR_NONE;

                        Core::OptionalType<string> _callsignOpt__{};

                        if (callsign.empty() == true) {
                            // no error, optional
                        }
                        else {
                            _callsignOpt__ = callsign;
                        }

                        ::Thunder::RPC::IIteratorType<IMetadata::Data::Service, ::Thunder::RPC::ID_CONTROLLER_METADATA_SERVICES_ITERATOR>* _result_{};

                        _errorCode__ = _implementation__->Services(_callsignOpt__, _result_);

                        if (_errorCode__ == Core::ERROR_NONE) {
                            result.Set(true);

                            if (_result_ != nullptr) {
                                Exchange::Controller::IMetadata::Data::Service _resultItem__{};
                                while (_result_->Next(_resultItem__) == true) { result.Add() = _resultItem__; }
                                result.SetExtractOnSingle(true);
                                _result_->Release();
                            }
                        }

                        return (_errorCode__);
                    });

                _module__.PluginHost::JSONRPC::Register(_T("status"), _T("services"));

                // Property: 'links' - Connections list of Thunder connections (r/o)
                _module__.PluginHost::JSONRPC::template Register<void, Core::JSON::ArrayType<JsonData::Metadata::LinkData>>(_T("links"),
                    [_implementation__](Core::JSON::ArrayType<JsonData::Metadata::LinkData>& result) -> uint32_t {
                        uint32_t _errorCode__ = Core::ERROR_NONE;

                        ::Thunder::RPC::IIteratorType<IMetadata::Data::Link, ::Thunder::RPC::ID_CONTROLLER_METADATA_LINKS_ITERATOR>* _result_{};

                        _errorCode__ = _implementation__->Links(_result_);

                        if (_errorCode__ == Core::ERROR_NONE) {
                            result.Set(true);

                            if (_result_ != nullptr) {
                                Exchange::Controller::IMetadata::Data::Link _resultItem__{};
                                while (_result_->Next(_resultItem__) == true) { result.Add() = _resultItem__; }
                                _result_->Release();
                            }
                        }

                        return (_errorCode__);
                    });

                // Indexed Property: 'proxies' - Proxies list (r/o)
                _module__.PluginHost::JSONRPC::template Register<void, Core::JSON::ArrayType<JsonData::Metadata::ProxyData>, std::function<uint32_t(const string&, Core::JSON::ArrayType<JsonData::Metadata::ProxyData>&)>>(_T("proxies"),
                    [_implementation__](const string& linkID, Core::JSON::ArrayType<JsonData::Metadata::ProxyData>& result) -> uint32_t {
                        uint32_t _errorCode__ = Core::ERROR_NONE;

                        Core::OptionalType<string> _linkIDOpt__{};

                        if (linkID.empty() == true) {
                            // no error, optional
                        }
                        else {
                            _linkIDOpt__ = linkID;
                        }

                        ::Thunder::RPC::IIteratorType<IMetadata::Data::Proxy, ::Thunder::RPC::ID_CONTROLLER_METADATA_PROXIES_ITERATOR>* _result_{};

                        _errorCode__ = _implementation__->Proxies(_linkIDOpt__, _result_);

                        if (_errorCode__ == Core::ERROR_NONE) {
                            result.Set(true);

                            if (_result_ != nullptr) {
                                Exchange::Controller::IMetadata::Data::Proxy _resultItem__{};
                                while (_result_->Next(_resultItem__) == true) { result.Add() = _resultItem__; }
                                _result_->Release();
                            }
                        }

                        return (_errorCode__);
                    });

                // Property: 'framework' - Framework version (r/o)
                _module__.PluginHost::JSONRPC::template Register<void, JsonData::Metadata::VersionInfo>(_T("framework"),
                    [_implementation__](JsonData::Metadata::VersionInfo& result) -> uint32_t {
                        uint32_t _errorCode__ = Core::ERROR_NONE;

                        Exchange::Controller::IMetadata::Data::Version _result_{};

                        _errorCode__ = _implementation__->Framework(_result_);

                        if (_errorCode__ == Core::ERROR_NONE) {
                            result.Set(true);
                            result = _result_;
                        }

                        return (_errorCode__);
                    });

                _module__.PluginHost::JSONRPC::Register(_T("version"), _T("framework"));

                // Property: 'threads' - Workerpool threads (r/o)
                _module__.PluginHost::JSONRPC::template Register<void, Core::JSON::ArrayType<JsonData::Metadata::ThreadData>>(_T("threads"),
                    [_implementation__](Core::JSON::ArrayType<JsonData::Metadata::ThreadData>& result) -> uint32_t {
                        uint32_t _errorCode__ = Core::ERROR_NONE;

                        ::Thunder::RPC::IIteratorType<IMetadata::Data::Thread, ::Thunder::RPC::ID_CONTROLLER_METADATA_THREADS_ITERATOR>* _result_{};

                        _errorCode__ = _implementation__->Threads(_result_);

                        if (_errorCode__ == Core::ERROR_NONE) {
                            result.Set(true);

                            if (_result_ != nullptr) {
                                Exchange::Controller::IMetadata::Data::Thread _resultItem__{};
                                while (_result_->Next(_resultItem__) == true) { result.Add() = _resultItem__; }
                                _result_->Release();
                            }
                        }

                        return (_errorCode__);
                    });

                // Property: 'pendingrequests' - Pending requests (r/o)
                _module__.PluginHost::JSONRPC::template Register<void, Core::JSON::ArrayType<Core::JSON::String>>(_T("pendingrequests"),
                    [_implementation__](Core::JSON::ArrayType<Core::JSON::String>& result) -> uint32_t {
                        uint32_t _errorCode__ = Core::ERROR_NONE;

                        ::Thunder::RPC::IIteratorType<string, ::Thunder::RPC::ID_STRINGITERATOR>* _result_{};

                        _errorCode__ = _implementation__->PendingRequests(_result_);

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

                // Indexed Property: 'callstack' - Thread callstack (r/o)
                _module__.PluginHost::JSONRPC::template Register<void, Core::JSON::ArrayType<JsonData::Metadata::CallStackData>, std::function<uint32_t(const string&, Core::JSON::ArrayType<JsonData::Metadata::CallStackData>&)>>(_T("callstack"),
                    [_implementation__](const string& thread, Core::JSON::ArrayType<JsonData::Metadata::CallStackData>& result) -> uint32_t {
                        uint32_t _errorCode__ = Core::ERROR_NONE;

                        uint8_t _threadConv__{};

                        if (thread.empty() == true) {
                            _errorCode__ = Core::ERROR_BAD_REQUEST;
                        }
                        else {
                            const bool _threadConvResult__ = Core::FromString(thread, _threadConv__);

                            if (_threadConvResult__ == false) {
                                _errorCode__ = Core::ERROR_BAD_REQUEST;
                            }
                        }

                        if (_errorCode__ == Core::ERROR_NONE) {
                            ::Thunder::RPC::IIteratorType<IMetadata::Data::CallStack, ::Thunder::RPC::ID_CONTROLLER_METADATA_CALLSTACK_ITERATOR>* _result_{};

                            _errorCode__ = _implementation__->CallStack(_threadConv__, _result_);

                            if (_errorCode__ == Core::ERROR_NONE) {
                                result.Set(true);

                                if (_result_ != nullptr) {
                                    Exchange::Controller::IMetadata::Data::CallStack _resultItem__{};
                                    while (_result_->Next(_resultItem__) == true) { result.Add() = _resultItem__; }
                                    _result_->Release();
                                }
                            }
                        }

                        return (_errorCode__);
                    });

                // Property: 'buildinfo' - Build information (r/o)
                _module__.PluginHost::JSONRPC::template Register<void, JsonData::Metadata::BuildInfoData>(_T("buildinfo"),
                    [_implementation__](JsonData::Metadata::BuildInfoData& result) -> uint32_t {
                        uint32_t _errorCode__ = Core::ERROR_NONE;

                        Exchange::Controller::IMetadata::Data::BuildInfo _result_{};

                        _errorCode__ = _implementation__->BuildInfo(_result_);

                        if (_errorCode__ == Core::ERROR_NONE) {
                            result.Set(true);
                            result = _result_;
                        }

                        return (_errorCode__);
                    });

            }

            template<typename MODULE>
            static void Unregister(MODULE& _module__)
            {
                // Unregister methods and properties...
                _module__.PluginHost::JSONRPC::Unregister(_T("services"));
                _module__.PluginHost::JSONRPC::Unregister(_T("status"));
                _module__.PluginHost::JSONRPC::Unregister(_T("links"));
                _module__.PluginHost::JSONRPC::Unregister(_T("proxies"));
                _module__.PluginHost::JSONRPC::Unregister(_T("framework"));
                _module__.PluginHost::JSONRPC::Unregister(_T("version"));
                _module__.PluginHost::JSONRPC::Unregister(_T("threads"));
                _module__.PluginHost::JSONRPC::Unregister(_T("pendingrequests"));
                _module__.PluginHost::JSONRPC::Unregister(_T("callstack"));
                _module__.PluginHost::JSONRPC::Unregister(_T("buildinfo"));
            }

            POP_WARNING()
            POP_WARNING()
            POP_WARNING()

        } // namespace JMetadata

    } // namespace Controller

} // namespace Exchange

} // namespace Thunder

