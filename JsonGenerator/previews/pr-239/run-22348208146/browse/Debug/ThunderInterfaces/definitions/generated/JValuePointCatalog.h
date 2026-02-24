// Generated automatically from 'IValuePoint.h'. DO NOT EDIT.

#pragma once
#include "Module.h"
#include "JsonData_ValuePointCatalog.h"
#include <interfaces/IValuePoint.h>

namespace Thunder {

namespace Exchange {

    namespace ValuePoint {

        namespace JCatalog {

            namespace Version {

                constexpr uint8_t Major = 1;
                constexpr uint8_t Minor = 0;
                constexpr uint8_t Patch = 0;

            } // namespace Version

            PUSH_WARNING(DISABLE_WARNING_UNUSED_FUNCTIONS)
            PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
            PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

            template<typename MODULE>
            static void Register(MODULE& _module__, IValuePoint::ICatalog* _implementation__)
            {
                ASSERT(_implementation__ != nullptr);

                ASSERT(_module__.template Exists<IValuePoint>() == true);

                _module__.PluginHost::JSONRPC::RegisterVersion(_T("JCatalog"), Version::Major, Version::Minor, Version::Patch);

                // Register methods and properties...

                // Method: 'resource'
                _module__.PluginHost::JSONRPC::template Register<JsonData::ValuePoint::Catalog::ResourceParamsInfo, Core::JSON::String, std::function<uint32_t(const Core::JSONRPC::Context&, const JsonData::ValuePoint::Catalog::ResourceParamsInfo&, Core::JSON::String&)>>(_T("resource"),
                    [_implementation__, &_module__](const Core::JSONRPC::Context& context_, const JsonData::ValuePoint::Catalog::ResourceParamsInfo& params, Core::JSON::String& interface) -> uint32_t {
                        uint32_t _errorCode__ = Core::ERROR_NONE;

                        if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                            _errorCode__ = Core::ERROR_BAD_REQUEST;
                        }
                        else {
                            const uint32_t _id_{params.Id};
                            string _interface_{};
                            Exchange::IValuePoint* _real_interface_{};

                            _errorCode__ = _implementation__->Resource(_id_, _real_interface_);

                            if (_errorCode__ == Core::ERROR_NONE) {
                                _interface_ = _module__.PluginHost::JSONRPCSupportsObjectLookup::template InstanceId<Exchange::IValuePoint>(_real_interface_, context_);
                                _real_interface_->Release();
                                interface = std::move(_interface_);
                            }
                        }

                        return (_errorCode__);
                    });

                // Method: 'resources'
                _module__.PluginHost::JSONRPC::template Register<void, Core::JSON::ArrayType<Core::JSON::DecUInt32>>(_T("resources"),
                    [_implementation__](Core::JSON::ArrayType<Core::JSON::DecUInt32>& iterator) -> uint32_t {
                        uint32_t _errorCode__ = Core::ERROR_NONE;

                        ::Thunder::RPC::IIteratorType<uint32_t, ::Thunder::RPC::ID_VALUEITERATOR>* _iterator_{};

                        _errorCode__ = _implementation__->Resources(_iterator_);

                        if (_errorCode__ == Core::ERROR_NONE) {
                            iterator.Set(true);

                            if (_iterator_ != nullptr) {
                                uint32_t _resultItem__{};
                                while (_iterator_->Next(_resultItem__) == true) { iterator.Add() = _resultItem__; }
                                _iterator_->Release();
                            }
                        }

                        return (_errorCode__);
                    });

                // Property: 'valuePoint::identifier' - Each IValuePoint instance has a unique identifier that identifies the instance (r/o)
                _module__.PluginHost::JSONRPC::template Register<void, Core::JSON::DecUInt32, std::function<uint32_t(const Core::JSONRPC::Context&, Core::JSONRPC::instance_id_follows_t, const string&, Core::JSON::DecUInt32&)>>(_T("valuePoint::identifier"),
                    [_implementation__, &_module__](const Core::JSONRPC::Context& context_, Core::JSONRPC::instance_id_follows_t, const string& instanceId_, Core::JSON::DecUInt32& result) -> uint32_t {
                        uint32_t _errorCode__ = Core::ERROR_NONE;

                        IValuePoint* const _implementation__ = _module__.PluginHost::JSONRPCSupportsObjectLookup::template LookUp<IValuePoint>(instanceId_, context_);

                        if (_implementation__ != nullptr) {
                            uint32_t _result_{};

                            _errorCode__ = _implementation__->Identifier(_result_);
                            _implementation__->Release();

                            if (_errorCode__ == Core::ERROR_NONE) {
                                result = _result_;
                            }
                        }
                        else {
                            _errorCode__ = Core::ERROR_UNKNOWN_KEY;
                        }

                        return (_errorCode__);
                    });

                // Property: 'valuePoint::bundle' - If this IValuePoint belongs to a bundle that has multiple IValuePoints the id that identifies the bundle and the result will be Core::ERROR_NONE (r/o)
                _module__.PluginHost::JSONRPC::template Register<void, Core::JSON::DecUInt32, std::function<uint32_t(const Core::JSONRPC::Context&, Core::JSONRPC::instance_id_follows_t, const string&, Core::JSON::DecUInt32&)>>(_T("valuePoint::bundle"),
                    [_implementation__, &_module__](const Core::JSONRPC::Context& context_, Core::JSONRPC::instance_id_follows_t, const string& instanceId_, Core::JSON::DecUInt32& result) -> uint32_t {
                        uint32_t _errorCode__ = Core::ERROR_NONE;

                        IValuePoint* const _implementation__ = _module__.PluginHost::JSONRPCSupportsObjectLookup::template LookUp<IValuePoint>(instanceId_, context_);

                        if (_implementation__ != nullptr) {
                            uint32_t _result_{};

                            _errorCode__ = _implementation__->Bundle(_result_);
                            _implementation__->Release();

                            if (_errorCode__ == Core::ERROR_NONE) {
                                result = _result_;
                            }
                        }
                        else {
                            _errorCode__ = Core::ERROR_UNKNOWN_KEY;
                        }

                        return (_errorCode__);
                    });

                // Property: 'valuePoint::condition' - Current state/condition of this IValuePoint (r/o)
                _module__.PluginHost::JSONRPC::template Register<void, Core::JSON::EnumType<Exchange::IValuePoint::condition>, std::function<uint32_t(const Core::JSONRPC::Context&, Core::JSONRPC::instance_id_follows_t, const string&, Core::JSON::EnumType<Exchange::IValuePoint::condition>&)>>(_T("valuePoint::condition"),
                    [_implementation__, &_module__](const Core::JSONRPC::Context& context_, Core::JSONRPC::instance_id_follows_t, const string& instanceId_, Core::JSON::EnumType<Exchange::IValuePoint::condition>& result) -> uint32_t {
                        uint32_t _errorCode__ = Core::ERROR_NONE;

                        IValuePoint* const _implementation__ = _module__.PluginHost::JSONRPCSupportsObjectLookup::template LookUp<IValuePoint>(instanceId_, context_);

                        if (_implementation__ != nullptr) {
                            Exchange::IValuePoint::condition _result_{};

                            _errorCode__ = _implementation__->Condition(_result_);
                            _implementation__->Release();

                            if (_errorCode__ == Core::ERROR_NONE) {
                                result = _result_;
                            }
                        }
                        else {
                            _errorCode__ = Core::ERROR_UNKNOWN_KEY;
                        }

                        return (_errorCode__);
                    });

                // Property: 'valuePoint::type' - Characteristics of this IValuePoint(IElement) (r/o)
                _module__.PluginHost::JSONRPC::template Register<void, Core::JSON::DecUInt32, std::function<uint32_t(const Core::JSONRPC::Context&, Core::JSONRPC::instance_id_follows_t, const string&, Core::JSON::DecUInt32&)>>(_T("valuePoint::type"),
                    [_implementation__, &_module__](const Core::JSONRPC::Context& context_, Core::JSONRPC::instance_id_follows_t, const string& instanceId_, Core::JSON::DecUInt32& result) -> uint32_t {
                        uint32_t _errorCode__ = Core::ERROR_NONE;

                        IValuePoint* const _implementation__ = _module__.PluginHost::JSONRPCSupportsObjectLookup::template LookUp<IValuePoint>(instanceId_, context_);

                        if (_implementation__ != nullptr) {
                            uint32_t _result_{};

                            _errorCode__ = _implementation__->Type(_result_);
                            _implementation__->Release();

                            if (_errorCode__ == Core::ERROR_NONE) {
                                result = _result_;
                            }
                        }
                        else {
                            _errorCode__ = Core::ERROR_UNKNOWN_KEY;
                        }

                        return (_errorCode__);
                    });

                // Property: 'valuePoint::minimum' - The minimum value this IValuePoint(IElement) can reach (r/o)
                _module__.PluginHost::JSONRPC::template Register<void, Core::JSON::DecSInt32, std::function<uint32_t(const Core::JSONRPC::Context&, Core::JSONRPC::instance_id_follows_t, const string&, Core::JSON::DecSInt32&)>>(_T("valuePoint::minimum"),
                    [_implementation__, &_module__](const Core::JSONRPC::Context& context_, Core::JSONRPC::instance_id_follows_t, const string& instanceId_, Core::JSON::DecSInt32& result) -> uint32_t {
                        uint32_t _errorCode__ = Core::ERROR_NONE;

                        IValuePoint* const _implementation__ = _module__.PluginHost::JSONRPCSupportsObjectLookup::template LookUp<IValuePoint>(instanceId_, context_);

                        if (_implementation__ != nullptr) {
                            int32_t _result_{};

                            _errorCode__ = _implementation__->Minimum(_result_);
                            _implementation__->Release();

                            if (_errorCode__ == Core::ERROR_NONE) {
                                result = _result_;
                            }
                        }
                        else {
                            _errorCode__ = Core::ERROR_UNKNOWN_KEY;
                        }

                        return (_errorCode__);
                    });

                // Property: 'valuePoint::maximum' - The maximum value this IValuePoint(IElement) can reach (r/o)
                _module__.PluginHost::JSONRPC::template Register<void, Core::JSON::DecSInt32, std::function<uint32_t(const Core::JSONRPC::Context&, Core::JSONRPC::instance_id_follows_t, const string&, Core::JSON::DecSInt32&)>>(_T("valuePoint::maximum"),
                    [_implementation__, &_module__](const Core::JSONRPC::Context& context_, Core::JSONRPC::instance_id_follows_t, const string& instanceId_, Core::JSON::DecSInt32& result) -> uint32_t {
                        uint32_t _errorCode__ = Core::ERROR_NONE;

                        IValuePoint* const _implementation__ = _module__.PluginHost::JSONRPCSupportsObjectLookup::template LookUp<IValuePoint>(instanceId_, context_);

                        if (_implementation__ != nullptr) {
                            int32_t _result_{};

                            _errorCode__ = _implementation__->Maximum(_result_);
                            _implementation__->Release();

                            if (_errorCode__ == Core::ERROR_NONE) {
                                result = _result_;
                            }
                        }
                        else {
                            _errorCode__ = Core::ERROR_UNKNOWN_KEY;
                        }

                        return (_errorCode__);
                    });

                // Property: 'valuePoint::value' - The current value of this IValuePoint
                _module__.PluginHost::JSONRPC::template Register<JsonData::ValuePoint::Catalog::ValueData, Core::JSON::DecSInt32, std::function<uint32_t(const Core::JSONRPC::Context&, Core::JSONRPC::instance_id_follows_t, const string&, const JsonData::ValuePoint::Catalog::ValueData&, Core::JSON::DecSInt32&)>>(_T("valuePoint::value"),
                    [_implementation__, &_module__](const Core::JSONRPC::Context& context_, Core::JSONRPC::instance_id_follows_t, const string& instanceId_, const JsonData::ValuePoint::Catalog::ValueData& params, Core::JSON::DecSInt32& result) -> uint32_t {
                        uint32_t _errorCode__ = Core::ERROR_NONE;

                        if (params.IsSet() == false) {
                            const IValuePoint* const _implementation__ = _module__.PluginHost::JSONRPCSupportsObjectLookup::template LookUp<IValuePoint>(instanceId_, context_);

                            if (_implementation__ != nullptr) {
                                int32_t _result_{};

                                _errorCode__ = (static_cast<const IValuePoint*>(_implementation__))->Value(_result_);
                                _implementation__->Release();

                                if (_errorCode__ == Core::ERROR_NONE) {
                                    result = _result_;
                                }
                            }
                            else {
                                _errorCode__ = Core::ERROR_UNKNOWN_KEY;
                            }
                        }
                        else {

                            if (params.IsDataValid() == false) {
                                _errorCode__ = Core::ERROR_BAD_REQUEST;
                            }
                            else {
                                IValuePoint* const _implementation__ = _module__.PluginHost::JSONRPCSupportsObjectLookup::template LookUp<IValuePoint>(instanceId_, context_);

                                if (_implementation__ != nullptr) {
                                    const int32_t _value_{params.Value};

                                    _errorCode__ = _implementation__->Value(_value_);
                                    _implementation__->Release();

                                }
                                else {
                                    _errorCode__ = Core::ERROR_UNKNOWN_KEY;
                                }
                            }

                            result.Null(true);
                        }

                        return (_errorCode__);
                    });

                // Property: 'valuePoint::metadata' - There most be more than meets the eye, report it as a JSON string (r/o)
                _module__.PluginHost::JSONRPC::template Register<void, JsonData::ValuePoint::Catalog::InfoData, std::function<uint32_t(const Core::JSONRPC::Context&, Core::JSONRPC::instance_id_follows_t, const string&, JsonData::ValuePoint::Catalog::InfoData&)>>(_T("valuePoint::metadata"),
                    [_implementation__, &_module__](const Core::JSONRPC::Context& context_, Core::JSONRPC::instance_id_follows_t, const string& instanceId_, JsonData::ValuePoint::Catalog::InfoData& result) -> uint32_t {
                        uint32_t _errorCode__ = Core::ERROR_NONE;

                        IValuePoint* const _implementation__ = _module__.PluginHost::JSONRPCSupportsObjectLookup::template LookUp<IValuePoint>(instanceId_, context_);

                        if (_implementation__ != nullptr) {
                            Exchange::IValuePoint::Info _result_{};

                            _errorCode__ = _implementation__->Metadata(_result_);
                            _implementation__->Release();

                            if (_errorCode__ == Core::ERROR_NONE) {
                                result.Set(true);
                                result = _result_;
                            }
                        }
                        else {
                            _errorCode__ = Core::ERROR_UNKNOWN_KEY;
                        }

                        return (_errorCode__);
                    });

            }

            template<typename MODULE>
            static void Unregister(MODULE& _module__)
            {
                // Unregister methods and properties...
                _module__.PluginHost::JSONRPC::Unregister(_T("resource"));
                _module__.PluginHost::JSONRPC::Unregister(_T("resources"));
                _module__.PluginHost::JSONRPC::Unregister(_T("valuePoint::identifier"));
                _module__.PluginHost::JSONRPC::Unregister(_T("valuePoint::bundle"));
                _module__.PluginHost::JSONRPC::Unregister(_T("valuePoint::condition"));
                _module__.PluginHost::JSONRPC::Unregister(_T("valuePoint::type"));
                _module__.PluginHost::JSONRPC::Unregister(_T("valuePoint::minimum"));
                _module__.PluginHost::JSONRPC::Unregister(_T("valuePoint::maximum"));
                _module__.PluginHost::JSONRPC::Unregister(_T("valuePoint::value"));
                _module__.PluginHost::JSONRPC::Unregister(_T("valuePoint::metadata"));
            }

            namespace Event {

                // Event: 'activated' - Signal a new IValuePoint, with the given Id became actived
                template<typename MODULE>
                static void Activated(const MODULE& module_, const JsonData::ValuePoint::Catalog::ActivatedParamsInfo& params, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
                {
                    module_.Notify(_T("activated"), params, sendIfMethod_);
                }

                // Event: 'activated' - Signal a new IValuePoint, with the given Id became actived
                template<typename MODULE>
                static void Activated(const MODULE& module_, const Core::JSON::String& id, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
                {
                    JsonData::ValuePoint::Catalog::ActivatedParamsInfo params_;
                    params_.Id = id;

                    Activated(module_, params_, sendIfMethod_);
                }

                // Event: 'activated' - Signal a new IValuePoint, with the given Id became actived
                template<typename MODULE>
                static void Activated(const MODULE& module_, IValuePoint* const id, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
                {
                    JsonData::ValuePoint::Catalog::ActivatedParamsInfo params_;
                    params_.Id = module_.PluginHost::JSONRPCSupportsObjectLookup::template InstanceId<Exchange::IValuePoint>(id);

                    Activated(module_, params_, sendIfMethod_);
                }

                // Event: 'deactivated' - Signal a new IValuePoint, with the given Id became deactived
                template<typename MODULE>
                static void Deactivated(const MODULE& module_, const JsonData::ValuePoint::Catalog::ActivatedParamsInfo& params, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
                {
                    module_.Notify(_T("deactivated"), params, sendIfMethod_);
                }

                // Event: 'deactivated' - Signal a new IValuePoint, with the given Id became deactived
                template<typename MODULE>
                static void Deactivated(const MODULE& module_, const Core::JSON::String& id, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
                {
                    JsonData::ValuePoint::Catalog::ActivatedParamsInfo params_;
                    params_.Id = id;

                    Deactivated(module_, params_, sendIfMethod_);
                }

                // Event: 'deactivated' - Signal a new IValuePoint, with the given Id became deactived
                template<typename MODULE>
                static void Deactivated(const MODULE& module_, IValuePoint* const id, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
                {
                    JsonData::ValuePoint::Catalog::ActivatedParamsInfo params_;
                    params_.Id = module_.PluginHost::JSONRPCSupportsObjectLookup::template InstanceId<Exchange::IValuePoint>(id);

                    Deactivated(module_, params_, sendIfMethod_);
                }

                // Event: 'valuePoint#ID::update' - Signal event any change in value
                template<typename MODULE>
                static void Update(const MODULE& module_, const IValuePoint* const _obj, const JsonData::ValuePoint::Catalog::ResourceParamsInfo& params, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
                {
                    ASSERT(_obj != nullptr);

                    const string _instanceId = module_.PluginHost::JSONRPCSupportsObjectLookup::template InstanceId<IValuePoint>(_obj);
                    if (_instanceId.empty() == false) {
                        module_.Notify(Core::Format(_T("valuePoint#%s::update"), _instanceId.c_str()), params, sendIfMethod_);
                    }
                }

                // Event: 'valuePoint#ID::update' - Signal event any change in value
                template<typename MODULE>
                static void Update(const MODULE& module_, const IValuePoint* const _obj, const Core::JSON::DecUInt32& id, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
                {
                    JsonData::ValuePoint::Catalog::ResourceParamsInfo params_;
                    params_.Id = id;

                    Update(module_, _obj, params_, sendIfMethod_);
                }

                // Event: 'valuePoint#ID::update' - Signal event any change in value
                template<typename MODULE>
                static void Update(const MODULE& module_, const IValuePoint* const _obj, const uint32_t id, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
                {
                    JsonData::ValuePoint::Catalog::ResourceParamsInfo params_;
                    params_.Id = id;

                    Update(module_, _obj, params_, sendIfMethod_);
                }

                // Event: 'valuePoint#ID::metadata' - Signal event any change in Metadata
                template<typename MODULE>
                static void Metadata(const MODULE& module_, const IValuePoint* const _obj, const JsonData::ValuePoint::Catalog::ResourceParamsInfo& params, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
                {
                    ASSERT(_obj != nullptr);

                    const string _instanceId = module_.PluginHost::JSONRPCSupportsObjectLookup::template InstanceId<IValuePoint>(_obj);
                    if (_instanceId.empty() == false) {
                        module_.Notify(Core::Format(_T("valuePoint#%s::metadata"), _instanceId.c_str()), params, sendIfMethod_);
                    }
                }

                // Event: 'valuePoint#ID::metadata' - Signal event any change in Metadata
                template<typename MODULE>
                static void Metadata(const MODULE& module_, const IValuePoint* const _obj, const Core::JSON::DecUInt32& id, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
                {
                    JsonData::ValuePoint::Catalog::ResourceParamsInfo params_;
                    params_.Id = id;

                    Metadata(module_, _obj, params_, sendIfMethod_);
                }

                // Event: 'valuePoint#ID::metadata' - Signal event any change in Metadata
                template<typename MODULE>
                static void Metadata(const MODULE& module_, const IValuePoint* const _obj, const uint32_t id, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
                {
                    JsonData::ValuePoint::Catalog::ResourceParamsInfo params_;
                    params_.Id = id;

                    Metadata(module_, _obj, params_, sendIfMethod_);
                }

            } // namespace Event

            POP_WARNING()
            POP_WARNING()
            POP_WARNING()

        } // namespace JCatalog

    } // namespace ValuePoint

} // namespace Exchange

} // namespace Thunder

