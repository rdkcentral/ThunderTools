// Generated automatically from 'IIOConnector.h'. DO NOT EDIT.

#pragma once
#include "Module.h"
#include "JsonData_IOConnector.h"
#include <interfaces/IIOConnector.h>

namespace Thunder {

namespace Exchange {

    namespace JIOConnector {

        namespace Version {

            constexpr uint8_t Major = 1;
            constexpr uint8_t Minor = 0;
            constexpr uint8_t Patch = 0;

        } // namespace Version

        PUSH_WARNING(DISABLE_WARNING_UNUSED_FUNCTIONS)
        PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
        PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

        template<typename MODULE>
        static void Register(MODULE& _module__, IIOConnector* _implementation__)
        {
            ASSERT(_implementation__ != nullptr);

            _module__.PluginHost::JSONRPC::RegisterVersion(_T("JIOConnector"), Version::Major, Version::Minor, Version::Patch);

            // Register methods and properties...

            // Indexed Property: 'pin' - GPIO pin value
            _module__.PluginHost::JSONRPC::template Register<JsonData::IOConnector::PinInfo, Core::JSON::DecSInt32, std::function<uint32_t(const string&, const JsonData::IOConnector::PinInfo&, Core::JSON::DecSInt32&)>>(_T("pin"),
                [_implementation__](const string& id, const JsonData::IOConnector::PinInfo& params, Core::JSON::DecSInt32& result) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    uint16_t _idConv__{};

                    if (id.empty() == true) {
                        _errorCode__ = Core::ERROR_BAD_REQUEST;
                    }
                    else {
                        const bool _idConvResult__ = Core::FromString(id, _idConv__);

                        if (_idConvResult__ == false) {
                            _errorCode__ = Core::ERROR_BAD_REQUEST;
                        }
                    }

                    if (_errorCode__ == Core::ERROR_NONE) {

                        if (params.IsSet() == false) {
                            int32_t _result_{};

                            _errorCode__ = (static_cast<const IIOConnector*>(_implementation__))->Pin(_idConv__, _result_);

                            if (_errorCode__ == Core::ERROR_NONE) {
                                result = _result_;
                            }
                        }
                        else {

                            if (params.IsDataValid() == false) {
                                _errorCode__ = Core::ERROR_BAD_REQUEST;
                            }
                            else {
                                const int32_t _value_{params.Value};

                                _errorCode__ = _implementation__->Pin(_idConv__, _value_);

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
            _module__.PluginHost::JSONRPC::Unregister(_T("pin"));
        }

        namespace Event {

            // Event: 'activity' - Notifies about GPIO pin activity
            template<typename MODULE>
            static void Activity(const MODULE& module_, const uint16_t& id_, const JsonData::IOConnector::PinInfo& params, typename MODULE::SendIfMethodIndexed sendIfMethod_ = nullptr)
            {
                if (sendIfMethod_ == nullptr) {
                    module_.Notify(_T("activity"), params, [&id_](const string&, const string& index_) -> bool {
                        Core::hresult _errorCode__ = Core::ERROR_NONE;
                        uint16_t _indexConv__{};

                        if (index_.empty() == true) {
                            _errorCode__ = Core::ERROR_BAD_REQUEST;
                        }
                        else {
                            const bool _indexConvResult__ = Core::FromString(index_, _indexConv__);
                        }

                        return ((_errorCode__ == Core::ERROR_NONE) && (id_ == _indexConv__));
                    });
                }
                else {
                    module_.Notify(_T("activity"), params, sendIfMethod_);
                }
            }

            // Event: 'activity' - Notifies about GPIO pin activity
            template<typename MODULE>
            static void Activity(const MODULE& module_, const uint16_t& id_, const Core::JSON::DecSInt32& value, typename MODULE::SendIfMethodIndexed sendIfMethod_ = nullptr)
            {
                JsonData::IOConnector::PinInfo params_;
                params_.Value = value;

                Activity(module_, id_, params_, sendIfMethod_);
            }

            // Event: 'activity' - Notifies about GPIO pin activity
            template<typename MODULE>
            static void Activity(const MODULE& module_, const uint16_t& id_, const int32_t value, typename MODULE::SendIfMethodIndexed sendIfMethod_ = nullptr)
            {
                JsonData::IOConnector::PinInfo params_;
                params_.Value = value;

                Activity(module_, id_, params_, sendIfMethod_);
            }

        } // namespace Event

        POP_WARNING()
        POP_WARNING()
        POP_WARNING()

    } // namespace JIOConnector

} // namespace Exchange

} // namespace Thunder

