// Generated automatically from 'IUserSettings.h'. DO NOT EDIT.

#pragma once
#include "Module.h"
#include "JsonData_UserSettings.h"
#include <interfaces/IUserSettings.h>

namespace WPEFramework {

namespace Exchange {

    namespace JUserSettings {

        namespace Version {

            constexpr uint8_t Major = 1;
            constexpr uint8_t Minor = 0;
            constexpr uint8_t Patch = 0;

        } // namespace Version

        PUSH_WARNING(DISABLE_WARNING_UNUSED_FUNCTIONS)
        PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
        PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

        template<typename MODULE>
        static void Register(MODULE& _module__, IUserSettings* _implementation__)
        {
            ASSERT(_implementation__ != nullptr);

            _module__.PluginHost::JSONRPC::RegisterVersion(_T("JUserSettings"), Version::Major, Version::Minor, Version::Patch);

            // Register methods and properties...

            // Property: 'setaudiodescription' - Sets AudioDescription ON/OFF (w/o)
            _module__.PluginHost::JSONRPC::Register<JsonData::UserSettings::SetAudioDescriptionInfo, void>(_T("setaudiodescription"),
                [_implementation__](const JsonData::UserSettings::SetAudioDescriptionInfo& params) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                        _errorCode__ = Core::ERROR_BAD_REQUEST;
                    }
                    else {
                        const bool _value_{params.Value};

                        _errorCode__ = _implementation__->SetAudioDescription(_value_);

                    }

                    return (_errorCode__);
                });

            // Property: 'getaudiodescription' - Gets the current AudioDescription setting (r/o)
            _module__.PluginHost::JSONRPC::Register<void, Core::JSON::Boolean>(_T("getaudiodescription"),
                [_implementation__](Core::JSON::Boolean& result) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    bool _result_{};

                    _errorCode__ = _implementation__->GetAudioDescription(_result_);

                    if (_errorCode__ == Core::ERROR_NONE) {
                        result = _result_;
                    }

                    return (_errorCode__);
                });

            // Property: 'setpreferredaudiolanguages' - A prioritized list of ISO 639-2/B codes for the preferred audio languages, expressed as a comma separated lists of languages of zero of more elements (w/o)
            _module__.PluginHost::JSONRPC::Register<JsonData::UserSettings::SetPreferredAudioLanguagesInfo, void>(_T("setpreferredaudiolanguages"),
                [_implementation__](const JsonData::UserSettings::SetPreferredAudioLanguagesInfo& params) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                        _errorCode__ = Core::ERROR_BAD_REQUEST;
                    }
                    else {
                        const string _value_{params.Value};

                        _errorCode__ = _implementation__->SetPreferredAudioLanguages(_value_);

                    }

                    return (_errorCode__);
                });

            // Property: 'getpreferredaudiolanguages' - Gets the current PreferredAudioLanguages setting (r/o)
            _module__.PluginHost::JSONRPC::Register<void, Core::JSON::String>(_T("getpreferredaudiolanguages"),
                [_implementation__](Core::JSON::String& result) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    string _result_{};

                    _errorCode__ = _implementation__->GetPreferredAudioLanguages(_result_);

                    if (_errorCode__ == Core::ERROR_NONE) {
                        result = _result_;
                    }

                    return (_errorCode__);
                });

            // Property: 'setpresentationlanguage' - Sets the presentationLanguages in a full BCP 47 value, including script, region, variant (w/o)
            _module__.PluginHost::JSONRPC::Register<JsonData::UserSettings::SetPreferredAudioLanguagesInfo, void>(_T("setpresentationlanguage"),
                [_implementation__](const JsonData::UserSettings::SetPreferredAudioLanguagesInfo& params) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                        _errorCode__ = Core::ERROR_BAD_REQUEST;
                    }
                    else {
                        const string _value_{params.Value};

                        _errorCode__ = _implementation__->SetPresentationLanguage(_value_);

                    }

                    return (_errorCode__);
                });

            // Property: 'getpresentationlanguage' - Gets the presentationLanguages (r/o)
            _module__.PluginHost::JSONRPC::Register<void, Core::JSON::String>(_T("getpresentationlanguage"),
                [_implementation__](Core::JSON::String& result) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    string _result_{};

                    _errorCode__ = _implementation__->GetPresentationLanguage(_result_);

                    if (_errorCode__ == Core::ERROR_NONE) {
                        result = _result_;
                    }

                    return (_errorCode__);
                });

            // Property: 'setcaptions' - brief Sets Captions ON/OFF (w/o)
            _module__.PluginHost::JSONRPC::Register<JsonData::UserSettings::SetAudioDescriptionInfo, void>(_T("setcaptions"),
                [_implementation__](const JsonData::UserSettings::SetAudioDescriptionInfo& params) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                        _errorCode__ = Core::ERROR_BAD_REQUEST;
                    }
                    else {
                        const bool _value_{params.Value};

                        _errorCode__ = _implementation__->SetCaptions(_value_);

                    }

                    return (_errorCode__);
                });

            // Property: 'getcaptions' - Gets the Captions setting (r/o)
            _module__.PluginHost::JSONRPC::Register<void, Core::JSON::Boolean>(_T("getcaptions"),
                [_implementation__](Core::JSON::Boolean& result) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    bool _result_{};

                    _errorCode__ = _implementation__->GetCaptions(_result_);

                    if (_errorCode__ == Core::ERROR_NONE) {
                        result = _result_;
                    }

                    return (_errorCode__);
                });

            // Property: 'setpreferredcaptionslanguages' - Set preferred languages for captions (w/o)
            _module__.PluginHost::JSONRPC::Register<JsonData::UserSettings::SetPreferredAudioLanguagesInfo, void>(_T("setpreferredcaptionslanguages"),
                [_implementation__](const JsonData::UserSettings::SetPreferredAudioLanguagesInfo& params) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                        _errorCode__ = Core::ERROR_BAD_REQUEST;
                    }
                    else {
                        const string _value_{params.Value};

                        _errorCode__ = _implementation__->SetPreferredCaptionsLanguages(_value_);

                    }

                    return (_errorCode__);
                });

            // Property: 'getpreferredcaptionslanguages' - Gets the current PreferredCaptionsLanguages setting (r/o)
            _module__.PluginHost::JSONRPC::Register<void, Core::JSON::String>(_T("getpreferredcaptionslanguages"),
                [_implementation__](Core::JSON::String& result) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    string _result_{};

                    _errorCode__ = _implementation__->GetPreferredCaptionsLanguages(_result_);

                    if (_errorCode__ == Core::ERROR_NONE) {
                        result = _result_;
                    }

                    return (_errorCode__);
                });

            // Property: 'setpreferredclosedcaptionservice' - Sets the PreferredClosedCaptionService (w/o)
            _module__.PluginHost::JSONRPC::Register<JsonData::UserSettings::SetPreferredAudioLanguagesInfo, void>(_T("setpreferredclosedcaptionservice"),
                [_implementation__](const JsonData::UserSettings::SetPreferredAudioLanguagesInfo& params) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                        _errorCode__ = Core::ERROR_BAD_REQUEST;
                    }
                    else {
                        const string _value_{params.Value};

                        _errorCode__ = _implementation__->SetPreferredClosedCaptionService(_value_);

                    }

                    return (_errorCode__);
                });

            // Property: 'getpreferredclosedcaptionservice' - Gets the current PreferredClosedCaptionService setting (r/o)
            _module__.PluginHost::JSONRPC::Register<void, Core::JSON::String>(_T("getpreferredclosedcaptionservice"),
                [_implementation__](Core::JSON::String& result) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    string _result_{};

                    _errorCode__ = _implementation__->GetPreferredClosedCaptionService(_result_);

                    if (_errorCode__ == Core::ERROR_NONE) {
                        result = _result_;
                    }

                    return (_errorCode__);
                });

            // Property: 'setprivacymode' - Sets the PrivacyMode (w/o)
            _module__.PluginHost::JSONRPC::Register<JsonData::UserSettings::SetPreferredAudioLanguagesInfo, void>(_T("setprivacymode"),
                [_implementation__](const JsonData::UserSettings::SetPreferredAudioLanguagesInfo& params) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                        _errorCode__ = Core::ERROR_BAD_REQUEST;
                    }
                    else {
                        const string _value_{params.Value};

                        _errorCode__ = _implementation__->SetPrivacyMode(_value_);

                    }

                    return (_errorCode__);
                });

            // Property: 'getprivacymode' - Gets the current PrivacyMode setting (r/o)
            _module__.PluginHost::JSONRPC::Register<void, Core::JSON::String>(_T("getprivacymode"),
                [_implementation__](Core::JSON::String& result) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    string _result_{};

                    _errorCode__ = _implementation__->GetPrivacyMode(_result_);

                    if (_errorCode__ == Core::ERROR_NONE) {
                        result = _result_;
                    }

                    return (_errorCode__);
                });

        }

        template<typename MODULE>
        static void Unregister(MODULE& _module__)
        {
            // Unregister methods and properties...
            _module__.PluginHost::JSONRPC::Unregister(_T("setaudiodescription"));
            _module__.PluginHost::JSONRPC::Unregister(_T("getaudiodescription"));
            _module__.PluginHost::JSONRPC::Unregister(_T("setpreferredaudiolanguages"));
            _module__.PluginHost::JSONRPC::Unregister(_T("getpreferredaudiolanguages"));
            _module__.PluginHost::JSONRPC::Unregister(_T("setpresentationlanguage"));
            _module__.PluginHost::JSONRPC::Unregister(_T("getpresentationlanguage"));
            _module__.PluginHost::JSONRPC::Unregister(_T("setcaptions"));
            _module__.PluginHost::JSONRPC::Unregister(_T("getcaptions"));
            _module__.PluginHost::JSONRPC::Unregister(_T("setpreferredcaptionslanguages"));
            _module__.PluginHost::JSONRPC::Unregister(_T("getpreferredcaptionslanguages"));
            _module__.PluginHost::JSONRPC::Unregister(_T("setpreferredclosedcaptionservice"));
            _module__.PluginHost::JSONRPC::Unregister(_T("getpreferredclosedcaptionservice"));
            _module__.PluginHost::JSONRPC::Unregister(_T("setprivacymode"));
            _module__.PluginHost::JSONRPC::Unregister(_T("getprivacymode"));
        }

        namespace Event {

            // Event: 'onaudiodescriptionchanged' - The AudioDescription setting has changed
            template<typename MODULE>
            static void OnAudioDescriptionChanged(const MODULE& module_, const JsonData::UserSettings::OnAudioDescriptionChangedParamsInfo& params, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                module_.Notify(_T("onaudiodescriptionchanged"), params, sendIfMethod_);
            }

            // Event: 'onaudiodescriptionchanged' - The AudioDescription setting has changed
            template<typename MODULE>
            static void OnAudioDescriptionChanged(const MODULE& module_, const Core::JSON::Boolean& enabled, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                JsonData::UserSettings::OnAudioDescriptionChangedParamsInfo params_;
                params_.Enabled = enabled;

                OnAudioDescriptionChanged(module_, params_, sendIfMethod_);
            }

            // Event: 'onaudiodescriptionchanged' - The AudioDescription setting has changed
            template<typename MODULE>
            static void OnAudioDescriptionChanged(const MODULE& module_, const bool enabled, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                JsonData::UserSettings::OnAudioDescriptionChangedParamsInfo params_;
                params_.Enabled = enabled;

                OnAudioDescriptionChanged(module_, params_, sendIfMethod_);
            }

            // Event: 'onpreferredaudiolanguageschanged' - The preferredLanguages setting has changed
            template<typename MODULE>
            static void OnPreferredAudioLanguagesChanged(const MODULE& module_, const JsonData::UserSettings::OnPreferredAudioLanguagesChangedParamsInfo& params, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                module_.Notify(_T("onpreferredaudiolanguageschanged"), params, sendIfMethod_);
            }

            // Event: 'onpreferredaudiolanguageschanged' - The preferredLanguages setting has changed
            template<typename MODULE>
            static void OnPreferredAudioLanguagesChanged(const MODULE& module_, const Core::JSON::String& preferredLanguages, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                JsonData::UserSettings::OnPreferredAudioLanguagesChangedParamsInfo params_;
                params_.PreferredLanguages = preferredLanguages;

                OnPreferredAudioLanguagesChanged(module_, params_, sendIfMethod_);
            }

            // Event: 'onpreferredaudiolanguageschanged' - The preferredLanguages setting has changed
            template<typename MODULE>
            static void OnPreferredAudioLanguagesChanged(const MODULE& module_, const string& preferredLanguages, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                JsonData::UserSettings::OnPreferredAudioLanguagesChangedParamsInfo params_;
                params_.PreferredLanguages = preferredLanguages;

                OnPreferredAudioLanguagesChanged(module_, params_, sendIfMethod_);
            }

            // Event: 'onpresentationlanguagechanged' - The PresentationLanguages setting has changed
            template<typename MODULE>
            static void OnPresentationLanguageChanged(const MODULE& module_, const JsonData::UserSettings::OnPresentationLanguageChangedParamsData& params, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                module_.Notify(_T("onpresentationlanguagechanged"), params, sendIfMethod_);
            }

            // Event: 'onpresentationlanguagechanged' - The PresentationLanguages setting has changed
            template<typename MODULE>
            static void OnPresentationLanguageChanged(const MODULE& module_, const Core::JSON::String& presentationLanguages, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                JsonData::UserSettings::OnPresentationLanguageChangedParamsData params_;
                params_.PresentationLanguages = presentationLanguages;

                OnPresentationLanguageChanged(module_, params_, sendIfMethod_);
            }

            // Event: 'onpresentationlanguagechanged' - The PresentationLanguages setting has changed
            template<typename MODULE>
            static void OnPresentationLanguageChanged(const MODULE& module_, const string& presentationLanguages, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                JsonData::UserSettings::OnPresentationLanguageChangedParamsData params_;
                params_.PresentationLanguages = presentationLanguages;

                OnPresentationLanguageChanged(module_, params_, sendIfMethod_);
            }

            // Event: 'oncaptionschanged' - The Captions setting has changed
            template<typename MODULE>
            static void OnCaptionsChanged(const MODULE& module_, const JsonData::UserSettings::OnAudioDescriptionChangedParamsInfo& params, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                module_.Notify(_T("oncaptionschanged"), params, sendIfMethod_);
            }

            // Event: 'oncaptionschanged' - The Captions setting has changed
            template<typename MODULE>
            static void OnCaptionsChanged(const MODULE& module_, const Core::JSON::Boolean& enabled, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                JsonData::UserSettings::OnAudioDescriptionChangedParamsInfo params_;
                params_.Enabled = enabled;

                OnCaptionsChanged(module_, params_, sendIfMethod_);
            }

            // Event: 'oncaptionschanged' - The Captions setting has changed
            template<typename MODULE>
            static void OnCaptionsChanged(const MODULE& module_, const bool enabled, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                JsonData::UserSettings::OnAudioDescriptionChangedParamsInfo params_;
                params_.Enabled = enabled;

                OnCaptionsChanged(module_, params_, sendIfMethod_);
            }

            // Event: 'onpreferredcaptionslanguageschanged' - The PreferredCaptionsLanguages setting has changed
            template<typename MODULE>
            static void OnPreferredCaptionsLanguagesChanged(const MODULE& module_, const JsonData::UserSettings::OnPreferredAudioLanguagesChangedParamsInfo& params, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                module_.Notify(_T("onpreferredcaptionslanguageschanged"), params, sendIfMethod_);
            }

            // Event: 'onpreferredcaptionslanguageschanged' - The PreferredCaptionsLanguages setting has changed
            template<typename MODULE>
            static void OnPreferredCaptionsLanguagesChanged(const MODULE& module_, const Core::JSON::String& preferredLanguages, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                JsonData::UserSettings::OnPreferredAudioLanguagesChangedParamsInfo params_;
                params_.PreferredLanguages = preferredLanguages;

                OnPreferredCaptionsLanguagesChanged(module_, params_, sendIfMethod_);
            }

            // Event: 'onpreferredcaptionslanguageschanged' - The PreferredCaptionsLanguages setting has changed
            template<typename MODULE>
            static void OnPreferredCaptionsLanguagesChanged(const MODULE& module_, const string& preferredLanguages, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                JsonData::UserSettings::OnPreferredAudioLanguagesChangedParamsInfo params_;
                params_.PreferredLanguages = preferredLanguages;

                OnPreferredCaptionsLanguagesChanged(module_, params_, sendIfMethod_);
            }

            // Event: 'onpreferredclosedcaptionservicechanged' - The PreferredClosedCaptionService setting has changed
            template<typename MODULE>
            static void OnPreferredClosedCaptionServiceChanged(const MODULE& module_, const JsonData::UserSettings::OnPreferredClosedCaptionServiceChangedParamsData& params, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                module_.Notify(_T("onpreferredclosedcaptionservicechanged"), params, sendIfMethod_);
            }

            // Event: 'onpreferredclosedcaptionservicechanged' - The PreferredClosedCaptionService setting has changed
            template<typename MODULE>
            static void OnPreferredClosedCaptionServiceChanged(const MODULE& module_, const Core::JSON::String& service, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                JsonData::UserSettings::OnPreferredClosedCaptionServiceChangedParamsData params_;
                params_.Service = service;

                OnPreferredClosedCaptionServiceChanged(module_, params_, sendIfMethod_);
            }

            // Event: 'onpreferredclosedcaptionservicechanged' - The PreferredClosedCaptionService setting has changed
            template<typename MODULE>
            static void OnPreferredClosedCaptionServiceChanged(const MODULE& module_, const string& service, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                JsonData::UserSettings::OnPreferredClosedCaptionServiceChangedParamsData params_;
                params_.Service = service;

                OnPreferredClosedCaptionServiceChanged(module_, params_, sendIfMethod_);
            }

            // Event: 'onprivacymodechanged' - The PrivacyMode setting has changed
            template<typename MODULE>
            static void OnPrivacyModeChanged(const MODULE& module_, const JsonData::UserSettings::OnPrivacyModeChangedParamsData& params, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                module_.Notify(_T("onprivacymodechanged"), params, sendIfMethod_);
            }

            // Event: 'onprivacymodechanged' - The PrivacyMode setting has changed
            template<typename MODULE>
            static void OnPrivacyModeChanged(const MODULE& module_, const Core::JSON::String& privacyMode, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                JsonData::UserSettings::OnPrivacyModeChangedParamsData params_;
                params_.PrivacyMode = privacyMode;

                OnPrivacyModeChanged(module_, params_, sendIfMethod_);
            }

            // Event: 'onprivacymodechanged' - The PrivacyMode setting has changed
            template<typename MODULE>
            static void OnPrivacyModeChanged(const MODULE& module_, const string& privacyMode, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                JsonData::UserSettings::OnPrivacyModeChangedParamsData params_;
                params_.PrivacyMode = privacyMode;

                OnPrivacyModeChanged(module_, params_, sendIfMethod_);
            }

        } // namespace Event

        POP_WARNING()
        POP_WARNING()
        POP_WARNING()

    } // namespace JUserSettings

} // namespace Exchange

} // namespace WPEFramework

