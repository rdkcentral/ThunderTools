// Generated automatically from 'IController.h'. DO NOT EDIT.

#pragma once

namespace Thunder {

namespace Exchange {

    namespace Controller {

        namespace JEvents {

            namespace Version {

                constexpr uint8_t Major = 1;
                constexpr uint8_t Minor = 0;
                constexpr uint8_t Patch = 0;

            } // namespace Version

            PUSH_WARNING(DISABLE_WARNING_UNUSED_FUNCTIONS)
            PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
            PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

            template<typename MODULE>
            static void Register(MODULE& _module__, IEvents*)
            {
                _module__.PluginHost::JSONRPC::RegisterVersion(_T("JEvents"), Version::Major, Version::Minor, Version::Patch);
            }

            template<typename MODULE>
            static void Unregister(MODULE&)
            {
            }

            namespace Event {

                // Event: 'all' - Notifies all events forwarded by the framework
                template<typename MODULE>
                static void ForwardMessage(const MODULE& module_, const JsonData::Events::ForwardMessageParamsData& params, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
                {
                    module_.Notify(_T("all"), params, sendIfMethod_);
                }

                // Event: 'all' - Notifies all events forwarded by the framework
                template<typename MODULE>
                static void ForwardMessage(const MODULE& module_, const Core::JSON::String& event, const Core::JSON::String& callsign, const Core::JSON::String& params, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
                {
                    JsonData::Events::ForwardMessageParamsData params_;
                    params_.Event = event;
                    params_.Callsign = callsign;
                    params_.Params = params;

                    ForwardMessage(module_, params_, sendIfMethod_);
                }

                // Event: 'all' - Notifies all events forwarded by the framework
                template<typename MODULE>
                static void ForwardMessage(const MODULE& module_, const string& event, const Core::OptionalType<string>& callsign, const Core::OptionalType<string>& params, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
                {
                    JsonData::Events::ForwardMessageParamsData params_;
                    params_.Event = event;

                    if (callsign.IsSet() == true) {
                        params_.Callsign = callsign.Value();
                    }

                    if (params.IsSet() == true) {
                        params_.Params = params.Value();
                        params_.Params.SetQuoted(false);
                    }

                    ForwardMessage(module_, params_, sendIfMethod_);
                }

            } // namespace Event

            POP_WARNING()
            POP_WARNING()
            POP_WARNING()

        } // namespace JEvents

    } // namespace Controller

} // namespace Exchange

} // namespace Thunder

