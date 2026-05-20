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

            using JSONRPC = PluginHost::JSONRPC;

            PUSH_WARNING(DISABLE_WARNING_UNUSED_FUNCTIONS)

            static void Register(JSONRPC& _module_, IMetadata* _impl_)
            {
                ASSERT(_impl_ != nullptr);

                _module_.RegisterVersion(_T("JMetadata"), Version::Major, Version::Minor, Version::Patch);

                // Register methods and properties...

                // Property: 'proxies' - Provides currenlty running proxy details (r/o)
                _module_.Register<void, Core::JSON::String>(_T("proxies"), 
                    [_impl_](Core::JSON::String& result) -> uint32_t {
                        uint32_t _errorCode = Core::ERROR_NONE;

                        // read-only property get
                        string _result{};

                        _errorCode = _impl_->Proxies(_result);

                        if (_errorCode == Core::ERROR_NONE) {
                            result = _result;
                            result.SetQuoted(false);
                        }

                        return (_errorCode);
                    });

                // Indexed Property: 'status' - Provides status of a plugin, including their configurations (r/o)
                _module_.Register<void, Core::JSON::String, std::function<uint32_t(const string&, Core::JSON::String&)>>(_T("status"), 
                    [_impl_](const string& _index_, Core::JSON::String& result) -> uint32_t {
                        uint32_t _errorCode = Core::ERROR_NONE;

                        // read-only property get
                        string _result{};

                        _errorCode = _impl_->Status(_index_, _result);

                        if (_errorCode == Core::ERROR_NONE) {
                            result = _result;
                            result.SetQuoted(false);
                        }

                        return (_errorCode);
                    });

                // Property: 'links' - Provides active connection details (r/o)
                _module_.Register<void, Core::JSON::String>(_T("links"), 
                    [_impl_](Core::JSON::String& result) -> uint32_t {
                        uint32_t _errorCode = Core::ERROR_NONE;

                        // read-only property get
                        string _result{};

                        _errorCode = _impl_->Links(_result);

                        if (_errorCode == Core::ERROR_NONE) {
                            result = _result;
                            result.SetQuoted(false);
                        }

                        return (_errorCode);
                    });

                // Property: 'processinfo' - Provides framework process info, like worker pools details (r/o)
                _module_.Register<void, Core::JSON::String>(_T("processinfo"), 
                    [_impl_](Core::JSON::String& result) -> uint32_t {
                        uint32_t _errorCode = Core::ERROR_NONE;

                        // read-only property get
                        string _result{};

                        _errorCode = _impl_->ProcessInfo(_result);

                        if (_errorCode == Core::ERROR_NONE) {
                            result = _result;
                            result.SetQuoted(false);
                        }

                        return (_errorCode);
                    });

                // Property: 'subsystems' - Provides currently active subsystem details (r/o)
                _module_.Register<void, Core::JSON::String>(_T("subsystems"), 
                    [_impl_](Core::JSON::String& result) -> uint32_t {
                        uint32_t _errorCode = Core::ERROR_NONE;

                        // read-only property get
                        string _result{};

                        _errorCode = _impl_->Subsystems(_result);

                        if (_errorCode == Core::ERROR_NONE) {
                            result = _result;
                            result.SetQuoted(false);
                        }

                        return (_errorCode);
                    });

                // Property: 'version' - Provides version of WPEFramework hash and in human readable (r/o)
                _module_.Register<void, Core::JSON::String>(_T("version"), 
                    [_impl_](Core::JSON::String& result) -> uint32_t {
                        uint32_t _errorCode = Core::ERROR_NONE;

                        // read-only property get
                        string _result{};

                        _errorCode = _impl_->Version(_result);

                        if (_errorCode == Core::ERROR_NONE) {
                            result = _result;
                            result.SetQuoted(false);
                        }

                        return (_errorCode);
                    });

                // Indexed Property: 'callstack' - callstack - Information the callstack associated with the given index 0 - <Max number of threads in the threadpool> (r/o)
                _module_.Register<void, Core::JSON::String, std::function<uint32_t(const string&, Core::JSON::String&)>>(_T("callstack"), 
                    [_impl_](const string& _index_, Core::JSON::String& result) -> uint32_t {
                        uint32_t _errorCode = Core::ERROR_NONE;

                        // read-only property get
                        string _result{};

                        _errorCode = _impl_->CallStack(_index_, _result);

                        if (_errorCode == Core::ERROR_NONE) {
                            result = _result;
                            result.SetQuoted(false);
                        }

                        return (_errorCode);
                    });

            }

            static void Unregister(JSONRPC& _module_)
            {
                // Unregister methods and properties...
                _module_.Unregister(_T("proxies"));
                _module_.Unregister(_T("status"));
                _module_.Unregister(_T("links"));
                _module_.Unregister(_T("processinfo"));
                _module_.Unregister(_T("subsystems"));
                _module_.Unregister(_T("version"));
                _module_.Unregister(_T("callstack"));
            }

            POP_WARNING()

        } // namespace JMetadata

    } // namespace Controller

} // namespace Exchange

} // namespace WPEFramework

