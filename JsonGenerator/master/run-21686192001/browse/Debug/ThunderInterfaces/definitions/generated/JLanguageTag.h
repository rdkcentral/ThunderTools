// Generated automatically from 'ILanguageTag.h'. DO NOT EDIT.

#pragma once
#include "Module.h"
#include <interfaces/ILanguageTag.h>

namespace Thunder {

namespace Exchange {

    namespace JLanguageTag {

        namespace Version {

            constexpr uint8_t Major = 1;
            constexpr uint8_t Minor = 0;
            constexpr uint8_t Patch = 0;

        } // namespace Version

        PUSH_WARNING(DISABLE_WARNING_UNUSED_FUNCTIONS)
        PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
        PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

        template<typename MODULE>
        static void Register(MODULE& _module__, ILanguageTag* _implementation__)
        {
            ASSERT(_implementation__ != nullptr);

            _module__.PluginHost::JSONRPC::RegisterVersion(_T("JLanguageTag"), Version::Major, Version::Minor, Version::Patch);

            // Register methods and properties...

            // Property: 'language' - Current application user interface language tag
            _module__.PluginHost::JSONRPC::template Register<Core::JSON::String, Core::JSON::String>(_T("language"),
                [_implementation__](const Core::JSON::String& params, Core::JSON::String& result) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if (params.IsSet() == false) {
                        string _result_{};

                        _errorCode__ = (static_cast<const ILanguageTag*>(_implementation__))->Language(_result_);

                        if (_errorCode__ == Core::ERROR_NONE) {
                            result = _result_;
                        }
                    }
                    else {
                        const string _params_{params};

                        _errorCode__ = _implementation__->Language(_params_);

                        result.Null(true);
                    }

                    return (_errorCode__);
                });

        }

        template<typename MODULE>
        static void Unregister(MODULE& _module__)
        {
            // Unregister methods and properties...
            _module__.PluginHost::JSONRPC::Unregister(_T("language"));
        }

        namespace Event {

            // Event: 'languagechanged' - Notify that the Language tag has been changed
            template<typename MODULE>
            static void LanguageChanged(const MODULE& module_, const Core::JSON::String& language, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                module_.Notify(_T("languagechanged"), language, sendIfMethod_);
            }

            // Event: 'languagechanged' - Notify that the Language tag has been changed
            template<typename MODULE>
            static void LanguageChanged(const MODULE& module_, const string& language, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                Core::JSON::String params_;
                params_ = language;

                LanguageChanged(module_, params_, sendIfMethod_);
            }

        } // namespace Event

        POP_WARNING()
        POP_WARNING()
        POP_WARNING()

    } // namespace JLanguageTag

} // namespace Exchange

} // namespace Thunder

