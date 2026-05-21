// Generated automatically from 'IZigWave.h'. DO NOT EDIT.

#pragma once

#include "Module.h"
#include "JsonData_ZigWave.h"
#include <interfaces/IZigWave.h>

namespace WPEFramework {

namespace Exchange {

    namespace JZigWave {

        namespace Version {

            constexpr uint8_t Major = 1;
            constexpr uint8_t Minor = 0;
            constexpr uint8_t Patch = 0;

        } // namespace Version

        using JSONRPC = PluginHost::JSONRPC;

        PUSH_WARNING(DISABLE_WARNING_UNUSED_FUNCTIONS)

        static void Register(JSONRPC& _module_, IZigWave* _impl_)
        {
            ASSERT(_impl_ != nullptr);

            _module_.RegisterVersion(_T("JZigWave"), Version::Major, Version::Minor, Version::Patch);

            // Register methods and properties...

            // Method: 'bind' - Bind the *out* from the soure to the *in* of the destination
            _module_.Register<JsonData::ZigWave::BindParamsInfo, void>(_T("bind"), 
                [_impl_](const JsonData::ZigWave::BindParamsInfo& params) -> uint32_t {
                    uint32_t _errorCode = Core::ERROR_NONE;

                    const uint32_t _source{params.Source};
                    const uint32_t _destination{params.Destination};

                    _errorCode = _impl_->Bind(_source, _destination);

                    return (_errorCode);
                });

            // Method: 'unbind' - Unbind the *out* from the soure to the *in* of the destination
            _module_.Register<JsonData::ZigWave::BindParamsInfo, void>(_T("unbind"), 
                [_impl_](const JsonData::ZigWave::BindParamsInfo& params) -> uint32_t {
                    uint32_t _errorCode = Core::ERROR_NONE;

                    const uint32_t _source{params.Source};
                    const uint32_t _destination{params.Destination};

                    _errorCode = _impl_->Unbind(_source, _destination);

                    return (_errorCode);
                });

            // Indexed Property: 'permutable' - To allow new devices to the network, the controller should be placed into an accepting mode
            _module_.Register<JsonData::ZigWave::PermutableInfo, Core::JSON::Boolean, std::function<uint32_t(const string&,
                     const JsonData::ZigWave::PermutableInfo&, Core::JSON::Boolean&)>>(_T("permutable"), 
                [_impl_](const string& _index_, const JsonData::ZigWave::PermutableInfo& params, Core::JSON::Boolean& result) -> uint32_t {
                    uint32_t _errorCode = Core::ERROR_NONE;

                    uint32_t _indexConverted_{};

                    if ((_index_.empty() == true) || (Core::FromString(_index_, _indexConverted_) == false)) {
                        _errorCode = Core::ERROR_UNKNOWN_KEY;
                        result.Null(true);
                    } else {
                        if (params.IsSet() == false) {
                            // property get
                            bool _result{};

                            _errorCode = (static_cast<const IZigWave*>(_impl_))->Permutable(_indexConverted_, _result);

                            if (_errorCode == Core::ERROR_NONE) {
                                result = _result;
                            }

                        } else {
                            // property set
                            const bool _value{params.Value};

                            _errorCode = _impl_->Permutable(_indexConverted_, _value);

                            result.Null(true);
                        }
                    }
                    return (_errorCode);
                });

            // Indexed Property: 'accept' - To allow new devices to the network, the controller should be placed into an accepting mode
            _module_.Register<JsonData::ZigWave::PermutableInfo, Core::JSON::Boolean, std::function<uint32_t(const string&,
                     const JsonData::ZigWave::PermutableInfo&, Core::JSON::Boolean&)>>(_T("accept"), 
                [_impl_](const string& _index_, const JsonData::ZigWave::PermutableInfo& params, Core::JSON::Boolean& result) -> uint32_t {
                    uint32_t _errorCode = Core::ERROR_NONE;

                    uint32_t _indexConverted_{};

                    if ((_index_.empty() == true) || (Core::FromString(_index_, _indexConverted_) == false)) {
                        _errorCode = Core::ERROR_UNKNOWN_KEY;
                        result.Null(true);
                    } else {
                        if (params.IsSet() == false) {
                            // property get
                            bool _result{};

                            _errorCode = (static_cast<const IZigWave*>(_impl_))->Permutable(_indexConverted_, _result);

                            if (_errorCode == Core::ERROR_NONE) {
                                result = _result;
                            }

                        } else {
                            // property set
                            const bool _value{params.Value};

                            _errorCode = _impl_->Permutable(_indexConverted_, _value);

                            result.Null(true);
                        }
                    }
                    return (_errorCode);
                });

            // Indexed Property: 'device' - To allow new devices to the network, the controller should be placed into an accepting mode (r/o)
            _module_.Register<void, Core::JSON::String, std::function<uint32_t(const string&, Core::JSON::String&)>>(_T("device"), 
                [_impl_](const string& _index_, Core::JSON::String& result) -> uint32_t {
                    uint32_t _errorCode = Core::ERROR_NONE;

                    uint32_t _indexConverted_{};

                    if ((_index_.empty() == true) || (Core::FromString(_index_, _indexConverted_) == false)) {
                        _errorCode = Core::ERROR_UNKNOWN_KEY;
                    } else {
                        // read-only property get
                        string _result{};

                        _errorCode = _impl_->Device(_indexConverted_, _result);

                        if (_errorCode == Core::ERROR_NONE) {
                            result = _result;
                        }

                    }
                    return (_errorCode);
                });

        }

        static void Unregister(JSONRPC& _module_)
        {
            // Unregister methods and properties...
            _module_.Unregister(_T("bind"));
            _module_.Unregister(_T("unbind"));
            _module_.Unregister(_T("permutable"));
            _module_.Unregister(_T("accept"));
            _module_.Unregister(_T("device"));
        }

        POP_WARNING()

    } // namespace JZigWave

} // namespace Exchange

} // namespace WPEFramework

