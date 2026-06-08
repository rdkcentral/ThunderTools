// Generated automatically from 'IController.h'. DO NOT EDIT.

#pragma once

namespace WPEFramework {

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

                // Property: 'proxies' - Provides currenlty running proxy details (r/o)
                _module__.PluginHost::JSONRPC::Register<void, Core::JSON::String>(_T("proxies"),
                    [_implementation__](Core::JSON::String& result) -> uint32_t {
                        uint32_t _errorCode__ = Core::ERROR_NONE;

                        string _result_{};

                        _errorCode__ = _implementation__->Proxies(_result_);

                        if (_errorCode__ == Core::ERROR_NONE) {

                            if (_result_.empty() == false) {
                                result = _result_;
                                result.SetQuoted(false);
                            }
                        }

                        return (_errorCode__);
                    });

                // Indexed Property: 'status' - Provides status of a plugin, including their configurations (r/o)
                _module__.PluginHost::JSONRPC::Register<void, Core::JSON::String, std::function<uint32_t(const string&, Core::JSON::String&)>>(_T("status"),
                    [_implementation__](const string& index, Core::JSON::String& result) -> uint32_t {
                        uint32_t _errorCode__ = Core::ERROR_NONE;

                        if (index.empty() == true) {
                            // no error, optional
                        }
                        else {
                        }
                        string _result_{};

                        _errorCode__ = _implementation__->Status(index, _result_);

                        if (_errorCode__ == Core::ERROR_NONE) {

                            if (_result_.empty() == false) {
                                result = _result_;
                                result.SetQuoted(false);
                            }
                        }

                        return (_errorCode__);
                    });

                // Property: 'links' - Provides active connection details (r/o)
                _module__.PluginHost::JSONRPC::Register<void, Core::JSON::String>(_T("links"),
                    [_implementation__](Core::JSON::String& result) -> uint32_t {
                        uint32_t _errorCode__ = Core::ERROR_NONE;

                        string _result_{};

                        _errorCode__ = _implementation__->Links(_result_);

                        if (_errorCode__ == Core::ERROR_NONE) {

                            if (_result_.empty() == false) {
                                result = _result_;
                                result.SetQuoted(false);
                            }
                        }

                        return (_errorCode__);
                    });

                // Property: 'processinfo' - Provides framework process info, like worker pools details (r/o)
                _module__.PluginHost::JSONRPC::Register<void, Core::JSON::String>(_T("processinfo"),
                    [_implementation__](Core::JSON::String& result) -> uint32_t {
                        uint32_t _errorCode__ = Core::ERROR_NONE;

                        string _result_{};

                        _errorCode__ = _implementation__->ProcessInfo(_result_);

                        if (_errorCode__ == Core::ERROR_NONE) {

                            if (_result_.empty() == false) {
                                result = _result_;
                                result.SetQuoted(false);
                            }
                        }

                        return (_errorCode__);
                    });

                // Property: 'subsystems' - Provides currently active subsystem details (r/o)
                _module__.PluginHost::JSONRPC::Register<void, Core::JSON::String>(_T("subsystems"),
                    [_implementation__](Core::JSON::String& result) -> uint32_t {
                        uint32_t _errorCode__ = Core::ERROR_NONE;

                        string _result_{};

                        _errorCode__ = _implementation__->Subsystems(_result_);

                        if (_errorCode__ == Core::ERROR_NONE) {

                            if (_result_.empty() == false) {
                                result = _result_;
                                result.SetQuoted(false);
                            }
                        }

                        return (_errorCode__);
                    });

                // Property: 'version' - Provides version of WPEFramework hash and in human readable (r/o)
                _module__.PluginHost::JSONRPC::Register<void, Core::JSON::String>(_T("version"),
                    [_implementation__](Core::JSON::String& result) -> uint32_t {
                        uint32_t _errorCode__ = Core::ERROR_NONE;

                        string _result_{};

                        _errorCode__ = _implementation__->Version(_result_);

                        if (_errorCode__ == Core::ERROR_NONE) {

                            if (_result_.empty() == false) {
                                result = _result_;
                                result.SetQuoted(false);
                            }
                        }

                        return (_errorCode__);
                    });

                // Indexed Property: 'callstack' - callstack - Information the callstack associated with the given index 0 - <Max number of threads in the threadpool> (r/o)
                _module__.PluginHost::JSONRPC::Register<void, Core::JSON::String, std::function<uint32_t(const string&, Core::JSON::String&)>>(_T("callstack"),
                    [_implementation__](const string& index, Core::JSON::String& result) -> uint32_t {
                        uint32_t _errorCode__ = Core::ERROR_NONE;

                        if (index.empty() == true) {
                            _errorCode__ = Core::ERROR_BAD_REQUEST;
                        }

                        if (_errorCode__ == Core::ERROR_NONE) {
                            string _result_{};

                            _errorCode__ = _implementation__->CallStack(index, _result_);

                            if (_errorCode__ == Core::ERROR_NONE) {

                                if (_result_.empty() == false) {
                                    result = _result_;
                                    result.SetQuoted(false);
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
                _module__.PluginHost::JSONRPC::Unregister(_T("proxies"));
                _module__.PluginHost::JSONRPC::Unregister(_T("status"));
                _module__.PluginHost::JSONRPC::Unregister(_T("links"));
                _module__.PluginHost::JSONRPC::Unregister(_T("processinfo"));
                _module__.PluginHost::JSONRPC::Unregister(_T("subsystems"));
                _module__.PluginHost::JSONRPC::Unregister(_T("version"));
                _module__.PluginHost::JSONRPC::Unregister(_T("callstack"));
            }

            POP_WARNING()
            POP_WARNING()
            POP_WARNING()

        } // namespace JMetadata

    } // namespace Controller

} // namespace Exchange

} // namespace WPEFramework

