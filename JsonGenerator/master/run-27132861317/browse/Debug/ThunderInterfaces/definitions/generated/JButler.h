// Generated automatically from 'IButler.h'. DO NOT EDIT.

#pragma once
#include "Module.h"
#include "JsonData_Butler.h"
#include <interfaces/IButler.h>

namespace Thunder {

namespace Exchange {

    namespace JButler {

        namespace Version {

            constexpr uint8_t Major = 1;
            constexpr uint8_t Minor = 0;
            constexpr uint8_t Patch = 0;

        } // namespace Version

        PUSH_WARNING(DISABLE_WARNING_UNUSED_FUNCTIONS)
        PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
        PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

        template<typename MODULE>
        static void Register(MODULE& _module__, IButler* _implementation__)
        {
            ASSERT(_implementation__ != nullptr);

            ASSERT(_module__.template Exists<IValuePoint>() == true);

            _module__.PluginHost::JSONRPC::RegisterVersion(_T("JButler"), Version::Major, Version::Minor, Version::Patch);

            // Register methods and properties...

            // Method: 'name'
            _module__.PluginHost::JSONRPC::template Register<JsonData::Butler::NameParamsData, Core::JSON::String, std::function<uint32_t(const Core::JSONRPC::Context&, const JsonData::Butler::NameParamsData&, Core::JSON::String&)>>(_T("name"),
                [_implementation__, &_module__](const Core::JSONRPC::Context& context_, const JsonData::Butler::NameParamsData& params, Core::JSON::String& valuePoint) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                        _errorCode__ = Core::ERROR_BAD_REQUEST;
                    }
                    else {
                        const string _name_{params.Name};
                        string _valuePoint_{};
                        Exchange::IValuePoint* _real_valuePoint_{};

                        _errorCode__ = _implementation__->Name(_name_, _real_valuePoint_);

                        if (_errorCode__ == Core::ERROR_NONE) {
                            _valuePoint_ = _module__.PluginHost::JSONRPCSupportsObjectLookup::template InstanceId<Exchange::IValuePoint>(_real_valuePoint_, context_);
                            _real_valuePoint_->Release();
                            valuePoint = std::move(_valuePoint_);
                        }
                    }

                    return (_errorCode__);
                });

            // Method: 'identifier'
            _module__.PluginHost::JSONRPC::template Register<JsonData::Butler::IdentifierParamsInfo, Core::JSON::String, std::function<uint32_t(const Core::JSONRPC::Context&, const JsonData::Butler::IdentifierParamsInfo&, Core::JSON::String&)>>(_T("identifier"),
                [_implementation__, &_module__](const Core::JSONRPC::Context& context_, const JsonData::Butler::IdentifierParamsInfo& params, Core::JSON::String& valuePoint) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                        _errorCode__ = Core::ERROR_BAD_REQUEST;
                    }
                    else {
                        const uint32_t _id_{params.Id};
                        string _valuePoint_{};
                        Exchange::IValuePoint* _real_valuePoint_{};

                        _errorCode__ = _implementation__->Identifier(_id_, _real_valuePoint_);

                        if (_errorCode__ == Core::ERROR_NONE) {
                            _valuePoint_ = _module__.PluginHost::JSONRPCSupportsObjectLookup::template InstanceId<Exchange::IValuePoint>(_real_valuePoint_, context_);
                            _real_valuePoint_->Release();
                            valuePoint = std::move(_valuePoint_);
                        }
                    }

                    return (_errorCode__);
                });

            // Method: 'branch'
            _module__.PluginHost::JSONRPC::template Register<JsonData::Butler::BranchParamsInfo, void>(_T("branch"),
                [_implementation__](const JsonData::Butler::BranchParamsInfo& params) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                        _errorCode__ = Core::ERROR_BAD_REQUEST;
                    }
                    else {
                        const string _path_{params.Path};

                        _errorCode__ = _implementation__->Branch(_path_);

                    }

                    return (_errorCode__);
                });

            // Method: 'move'
            _module__.PluginHost::JSONRPC::template Register<JsonData::Butler::MoveParamsData, void>(_T("move"),
                [_implementation__](const JsonData::Butler::MoveParamsData& params) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                        _errorCode__ = Core::ERROR_BAD_REQUEST;
                    }
                    else {
                        const string _path_{params.Path};
                        const string _newName_{params.NewName};

                        _errorCode__ = _implementation__->Move(_path_, _newName_);

                    }

                    return (_errorCode__);
                });

            // Method: 'delete'
            _module__.PluginHost::JSONRPC::template Register<JsonData::Butler::BranchParamsInfo, void>(_T("delete"),
                [_implementation__](const JsonData::Butler::BranchParamsInfo& params) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                        _errorCode__ = Core::ERROR_BAD_REQUEST;
                    }
                    else {
                        const string _path_{params.Path};

                        _errorCode__ = _implementation__->Delete(_path_);

                    }

                    return (_errorCode__);
                });

            // Method: 'source'
            _module__.PluginHost::JSONRPC::template Register<JsonData::Butler::IdentifierParamsInfo, Core::JSON::String>(_T("source"),
                [_implementation__](const JsonData::Butler::IdentifierParamsInfo& params, Core::JSON::String& callsign) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                        _errorCode__ = Core::ERROR_BAD_REQUEST;
                    }
                    else {
                        const uint32_t _id_{params.Id};
                        string _callsign_{};

                        _errorCode__ = _implementation__->Source(_id_, _callsign_);

                        if (_errorCode__ == Core::ERROR_NONE) {
                            callsign = _callsign_;
                        }
                    }

                    return (_errorCode__);
                });

            // Method: 'link'
            _module__.PluginHost::JSONRPC::template Register<JsonData::Butler::LinkParamsData, void>(_T("link"),
                [_implementation__](const JsonData::Butler::LinkParamsData& params) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                        _errorCode__ = Core::ERROR_BAD_REQUEST;
                    }
                    else {
                        const string _name_{params.Name};
                        const uint32_t _id_{params.Id};

                        _errorCode__ = _implementation__->Link(_name_, _id_);

                    }

                    return (_errorCode__);
                });

            // Method: 'orphans'
            _module__.PluginHost::JSONRPC::template Register<JsonData::Butler::OrphansParamsData, Core::JSON::ArrayType<Core::JSON::DecUInt32>>(_T("orphans"),
                [_implementation__](const JsonData::Butler::OrphansParamsData& params, Core::JSON::ArrayType<Core::JSON::DecUInt32>& iterator) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                        _errorCode__ = Core::ERROR_BAD_REQUEST;
                    }
                    else {
                        const uint8_t _module_{params.Module};
                        ::Thunder::RPC::IIteratorType<uint32_t, ::Thunder::RPC::ID_VALUEITERATOR>* _iterator_{};

                        _errorCode__ = _implementation__->Orphans(_module_, _iterator_);

                        if (_errorCode__ == Core::ERROR_NONE) {
                            iterator.Set(true);

                            if (_iterator_ != nullptr) {
                                uint32_t _resultItem__{};
                                while (_iterator_->Next(_resultItem__) == true) { iterator.Add() = _resultItem__; }
                                _iterator_->Release();
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
            _module__.PluginHost::JSONRPC::Unregister(_T("name"));
            _module__.PluginHost::JSONRPC::Unregister(_T("identifier"));
            _module__.PluginHost::JSONRPC::Unregister(_T("branch"));
            _module__.PluginHost::JSONRPC::Unregister(_T("move"));
            _module__.PluginHost::JSONRPC::Unregister(_T("delete"));
            _module__.PluginHost::JSONRPC::Unregister(_T("source"));
            _module__.PluginHost::JSONRPC::Unregister(_T("link"));
            _module__.PluginHost::JSONRPC::Unregister(_T("orphans"));
        }

        namespace Event {

            // Event: 'added'
            template<typename MODULE>
            static void Added(const MODULE& module_, const JsonData::Butler::AddedParamsInfo& params, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                module_.Notify(_T("added"), params, sendIfMethod_);
            }

            // Event: 'added'
            template<typename MODULE>
            static void Added(const MODULE& module_, const Core::JSON::String& element, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                JsonData::Butler::AddedParamsInfo params_;
                params_.Element = element;

                Added(module_, params_, sendIfMethod_);
            }

            // Event: 'added'
            template<typename MODULE>
            static void Added(const MODULE& module_, IValuePoint* const element, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                JsonData::Butler::AddedParamsInfo params_;
                params_.Element = module_.PluginHost::JSONRPCSupportsObjectLookup::template InstanceId<Exchange::IValuePoint>(element);

                Added(module_, params_, sendIfMethod_);
            }

            // Event: 'removed'
            template<typename MODULE>
            static void Removed(const MODULE& module_, const JsonData::Butler::AddedParamsInfo& params, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                module_.Notify(_T("removed"), params, sendIfMethod_);
            }

            // Event: 'removed'
            template<typename MODULE>
            static void Removed(const MODULE& module_, const Core::JSON::String& element, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                JsonData::Butler::AddedParamsInfo params_;
                params_.Element = element;

                Removed(module_, params_, sendIfMethod_);
            }

            // Event: 'removed'
            template<typename MODULE>
            static void Removed(const MODULE& module_, IValuePoint* const element, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                JsonData::Butler::AddedParamsInfo params_;
                params_.Element = module_.PluginHost::JSONRPCSupportsObjectLookup::template InstanceId<Exchange::IValuePoint>(element);

                Removed(module_, params_, sendIfMethod_);
            }

            // Event: 'updated'
            template<typename MODULE>
            static void Updated(const MODULE& module_, const JsonData::Butler::AddedParamsInfo& params, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                module_.Notify(_T("updated"), params, sendIfMethod_);
            }

            // Event: 'updated'
            template<typename MODULE>
            static void Updated(const MODULE& module_, const Core::JSON::String& element, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                JsonData::Butler::AddedParamsInfo params_;
                params_.Element = element;

                Updated(module_, params_, sendIfMethod_);
            }

            // Event: 'updated'
            template<typename MODULE>
            static void Updated(const MODULE& module_, IValuePoint* const element, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                JsonData::Butler::AddedParamsInfo params_;
                params_.Element = module_.PluginHost::JSONRPCSupportsObjectLookup::template InstanceId<Exchange::IValuePoint>(element);

                Updated(module_, params_, sendIfMethod_);
            }

            // Event: 'metadata'
            template<typename MODULE>
            static void Metadata(const MODULE& module_, const JsonData::Butler::AddedParamsInfo& params, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                module_.Notify(_T("metadata"), params, sendIfMethod_);
            }

            // Event: 'metadata'
            template<typename MODULE>
            static void Metadata(const MODULE& module_, const Core::JSON::String& element, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                JsonData::Butler::AddedParamsInfo params_;
                params_.Element = element;

                Metadata(module_, params_, sendIfMethod_);
            }

            // Event: 'metadata'
            template<typename MODULE>
            static void Metadata(const MODULE& module_, IValuePoint* const element, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                JsonData::Butler::AddedParamsInfo params_;
                params_.Element = module_.PluginHost::JSONRPCSupportsObjectLookup::template InstanceId<Exchange::IValuePoint>(element);

                Metadata(module_, params_, sendIfMethod_);
            }

        } // namespace Event

        POP_WARNING()
        POP_WARNING()
        POP_WARNING()

    } // namespace JButler

} // namespace Exchange

} // namespace Thunder

