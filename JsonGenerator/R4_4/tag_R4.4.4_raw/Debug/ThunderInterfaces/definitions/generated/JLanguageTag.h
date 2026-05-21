// Generated automatically from 'ILanguageTag.h'. DO NOT EDIT.

#pragma once

#include "Module.h"
#include <interfaces/ILanguageTag.h>

namespace WPEFramework {

namespace Exchange {

    namespace JLanguageTag {

        namespace Version {

            constexpr uint8_t Major = 1;
            constexpr uint8_t Minor = 0;
            constexpr uint8_t Patch = 0;

        } // namespace Version

        using JSONRPC = PluginHost::JSONRPC;

        PUSH_WARNING(DISABLE_WARNING_UNUSED_FUNCTIONS)

        static void Register(JSONRPC& _module_, ILanguageTag* _impl_)
        {
            ASSERT(_impl_ != nullptr);

            _module_.RegisterVersion(_T("JLanguageTag"), Version::Major, Version::Minor, Version::Patch);

            // Register methods and properties...

            // Property: 'language' - Current application user interface language tag
            _module_.Register<Core::JSON::String, Core::JSON::String>(_T("language"), 
                [_impl_](const Core::JSON::String& params, Core::JSON::String& result) -> uint32_t {
                    uint32_t _errorCode = Core::ERROR_NONE;

                    if (params.IsSet() == false) {
                        // property get
                        string _result{};

                        _errorCode = (static_cast<const ILanguageTag*>(_impl_))->Language(_result);

                        if (_errorCode == Core::ERROR_NONE) {
                            result = _result;
                        }

                    } else {
                        // property set
                        const string _params{params};

                        _errorCode = _impl_->Language(_params);

                        result.Null(true);
                    }
                    return (_errorCode);
                });

        }

        static void Unregister(JSONRPC& _module_)
        {
            // Unregister methods and properties...
            _module_.Unregister(_T("language"));
        }

        namespace Event {

            // Event: 'languagechanged' - Notify that the Language tag has been changed
            static void LanguageChanged(const JSONRPC& _module_, const Core::JSON::String& language)
            {
                _module_.Notify(_T("languagechanged"), language);
            }

            // Event: 'languagechanged' - Notify that the Language tag has been changed
            static void LanguageChanged(const JSONRPC& _module_, const string& language)
            {
                Core::JSON::String _params_;
                _params_ = language;

                LanguageChanged(_module_, _params_);
            }

        } // namespace Event

        POP_WARNING()

    } // namespace JLanguageTag

} // namespace Exchange

} // namespace WPEFramework

