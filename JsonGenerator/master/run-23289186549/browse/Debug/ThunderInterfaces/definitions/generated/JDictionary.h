// Generated automatically from 'IDictionary.h'. DO NOT EDIT.

#pragma once
#include "Module.h"
#include "JsonData_Dictionary.h"
#include <interfaces/IDictionary.h>

namespace Thunder {

namespace Exchange {

    namespace JDictionary {

        namespace Version {

            constexpr uint8_t Major = 1;
            constexpr uint8_t Minor = 0;
            constexpr uint8_t Patch = 0;

        } // namespace Version

        PUSH_WARNING(DISABLE_WARNING_UNUSED_FUNCTIONS)
        PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
        PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

        template<typename MODULE>
        static void Register(MODULE& _module__, IDictionary* _implementation__)
        {
            ASSERT(_implementation__ != nullptr);

            _module__.PluginHost::JSONRPC::RegisterVersion(_T("JDictionary"), Version::Major, Version::Minor, Version::Patch);

            // Register methods and properties...

            // Method: 'get' - Getters for the dictionary
            _module__.PluginHost::JSONRPC::template Register<JsonData::Dictionary::GetParamsData, Core::JSON::String>(_T("get"),
                [_implementation__](const JsonData::Dictionary::GetParamsData& params, Core::JSON::String& value) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                        _errorCode__ = Core::ERROR_BAD_REQUEST;
                    }
                    else {
                        const string _path_{params.Path};
                        const string _key_{params.Key};
                        string _value_{};

                        _errorCode__ = _implementation__->Get(_path_, _key_, _value_);

                        if (_errorCode__ == Core::ERROR_NONE) {
                            value = _value_;
                        }
                    }

                    return (_errorCode__);
                });

            // Method: 'set' - Setters for the dictionary
            _module__.PluginHost::JSONRPC::template Register<JsonData::Dictionary::SetParamsData, void>(_T("set"),
                [_implementation__](const JsonData::Dictionary::SetParamsData& params) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                        _errorCode__ = Core::ERROR_BAD_REQUEST;
                    }
                    else {
                        const string _path_{params.Path};
                        const string _key_{params.Key};
                        const string _value_{params.Value};

                        _errorCode__ = _implementation__->Set(_path_, _key_, _value_);

                    }

                    return (_errorCode__);
                });

            // Method: 'pathentries' - Get a list of all entries for this namespace (could be keys or nested namespaces)
            _module__.PluginHost::JSONRPC::template Register<JsonData::Dictionary::PathEntriesParamsData, Core::JSON::ArrayType<JsonData::Dictionary::PathEntryData>>(_T("pathentries"),
                [_implementation__](const JsonData::Dictionary::PathEntriesParamsData& params, Core::JSON::ArrayType<JsonData::Dictionary::PathEntryData>& entries) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                        _errorCode__ = Core::ERROR_BAD_REQUEST;
                    }
                    else {
                        const string _path_{params.Path};
                        ::Thunder::RPC::IIteratorType<IDictionary::PathEntry, ID_DICTIONARY_ITERATOR>* _entries_{};

                        _errorCode__ = _implementation__->PathEntries(_path_, _entries_);

                        if (_errorCode__ == Core::ERROR_NONE) {
                            entries.Set(true);

                            if (_entries_ != nullptr) {
                                Exchange::IDictionary::PathEntry _resultItem__{};
                                while (_entries_->Next(_resultItem__) == true) { entries.Add() = _resultItem__; }
                                _entries_->Release();
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
            _module__.PluginHost::JSONRPC::Unregister(_T("get"));
            _module__.PluginHost::JSONRPC::Unregister(_T("set"));
            _module__.PluginHost::JSONRPC::Unregister(_T("pathentries"));
        }

        namespace Event {

            // Event: 'modified' - Changes on the subscribed namespace
            template<typename MODULE>
            static void Modified(const MODULE& module_, const string& id_, const JsonData::Dictionary::ModifiedParamsData& params, typename MODULE::SendIfMethodIndexed sendIfMethod_ = nullptr)
            {
                if (sendIfMethod_ == nullptr) {
                    module_.Notify(_T("modified"), params, [&id_](const string&, const string& index_) -> bool {
                        Core::hresult _errorCode__ = Core::ERROR_NONE;

                        if (index_.empty() == true) {
                            _errorCode__ = Core::ERROR_BAD_REQUEST;
                        }
                        return ((_errorCode__ == Core::ERROR_NONE) && (id_ == index_));
                    });
                }
                else {
                    module_.Notify(_T("modified"), params, sendIfMethod_);
                }
            }

            // Event: 'modified' - Changes on the subscribed namespace
            template<typename MODULE>
            static void Modified(const MODULE& module_, const string& id_, const Core::JSON::String& key, const Core::JSON::String& value, typename MODULE::SendIfMethodIndexed sendIfMethod_ = nullptr)
            {
                JsonData::Dictionary::ModifiedParamsData params_;
                params_.Key = key;
                params_.Value = value;

                Modified(module_, id_, params_, sendIfMethod_);
            }

            // Event: 'modified' - Changes on the subscribed namespace
            template<typename MODULE>
            static void Modified(const MODULE& module_, const string& id_, const string& key, const string& value, typename MODULE::SendIfMethodIndexed sendIfMethod_ = nullptr)
            {
                JsonData::Dictionary::ModifiedParamsData params_;
                params_.Key = key;
                params_.Value = value;

                Modified(module_, id_, params_, sendIfMethod_);
            }

        } // namespace Event

        POP_WARNING()
        POP_WARNING()
        POP_WARNING()

    } // namespace JDictionary

} // namespace Exchange

} // namespace Thunder

