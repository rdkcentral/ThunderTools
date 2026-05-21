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

        using JSONRPC = PluginHost::JSONRPC;

        PUSH_WARNING(DISABLE_WARNING_UNUSED_FUNCTIONS)

        static void Register(JSONRPC& _module_, IUserSettings* _impl_)
        {
            ASSERT(_impl_ != nullptr);

            _module_.RegisterVersion(_T("JUserSettings"), Version::Major, Version::Minor, Version::Patch);

            // Register methods and properties...

            // Property: 'setaudiodescription' - Sets AudioDescription ON/OFF (w/o)
            _module_.Register<JsonData::UserSettings::SetAudioDescriptionInfo, void>(_T("setaudiodescription"), 
                [_impl_](const JsonData::UserSettings::SetAudioDescriptionInfo& params) -> uint32_t {
                    uint32_t _errorCode = Core::ERROR_NONE;

                    // write-only property set
                    const bool _value{params.Value};

                    _errorCode = _impl_->SetAudioDescription(_value);

                    return (_errorCode);
                });

            // Property: 'getaudiodescription' - Gets the current AudioDescription setting (r/o)
            _module_.Register<void, Core::JSON::Boolean>(_T("getaudiodescription"), 
                [_impl_](Core::JSON::Boolean& result) -> uint32_t {
                    uint32_t _errorCode = Core::ERROR_NONE;

                    // read-only property get
                    bool _result{};

                    _errorCode = _impl_->GetAudioDescription(_result);

                    if (_errorCode == Core::ERROR_NONE) {
                        result = _result;
                    }

                    return (_errorCode);
                });

            // Property: 'setpreferredaudiolanguages' - A prioritized list of ISO 639-2/B codes for the preferred audio languages,
                    //  expressed as a comma separated lists of languages of zero of more elements (w/o)
            _module_.Register<JsonData::UserSettings::SetPreferredAudioLanguagesInfo, void>(_T("setpreferredaudiolanguages"), 
                [_impl_](const JsonData::UserSettings::SetPreferredAudioLanguagesInfo& params) -> uint32_t {
                    uint32_t _errorCode = Core::ERROR_NONE;

                    // write-only property set
                    const string _value{params.Value};

                    _errorCode = _impl_->SetPreferredAudioLanguages(_value);

                    return (_errorCode);
                });

            // Property: 'getpreferredaudiolanguages' - Gets the current PreferredAudioLanguages setting (r/o)
            _module_.Register<void, Core::JSON::String>(_T("getpreferredaudiolanguages"), 
                [_impl_](Core::JSON::String& result) -> uint32_t {
                    uint32_t _errorCode = Core::ERROR_NONE;

                    // read-only property get
                    string _result{};

                    _errorCode = _impl_->GetPreferredAudioLanguages(_result);

                    if (_errorCode == Core::ERROR_NONE) {
                        result = _result;
                    }

                    return (_errorCode);
                });

            // Property: 'setpresentationlanguage' - Sets the presentationLanguages in a full BCP 47 value, including script, region, variant (w/o)
            _module_.Register<JsonData::UserSettings::SetPreferredAudioLanguagesInfo, void>(_T("setpresentationlanguage"), 
                [_impl_](const JsonData::UserSettings::SetPreferredAudioLanguagesInfo& params) -> uint32_t {
                    uint32_t _errorCode = Core::ERROR_NONE;

                    // write-only property set
                    const string _value{params.Value};

                    _errorCode = _impl_->SetPresentationLanguage(_value);

                    return (_errorCode);
                });

            // Property: 'getpresentationlanguage' - Gets the presentationLanguages (r/o)
            _module_.Register<void, Core::JSON::String>(_T("getpresentationlanguage"), 
                [_impl_](Core::JSON::String& result) -> uint32_t {
                    uint32_t _errorCode = Core::ERROR_NONE;

                    // read-only property get
                    string _result{};

                    _errorCode = _impl_->GetPresentationLanguage(_result);

                    if (_errorCode == Core::ERROR_NONE) {
                        result = _result;
                    }

                    return (_errorCode);
                });

            // Property: 'setcaptions' - brief Sets Captions ON/OFF (w/o)
            _module_.Register<JsonData::UserSettings::SetAudioDescriptionInfo, void>(_T("setcaptions"), 
                [_impl_](const JsonData::UserSettings::SetAudioDescriptionInfo& params) -> uint32_t {
                    uint32_t _errorCode = Core::ERROR_NONE;

                    // write-only property set
                    const bool _value{params.Value};

                    _errorCode = _impl_->SetCaptions(_value);

                    return (_errorCode);
                });

            // Property: 'getcaptions' - Gets the Captions setting (r/o)
            _module_.Register<void, Core::JSON::Boolean>(_T("getcaptions"), 
                [_impl_](Core::JSON::Boolean& result) -> uint32_t {
                    uint32_t _errorCode = Core::ERROR_NONE;

                    // read-only property get
                    bool _result{};

                    _errorCode = _impl_->GetCaptions(_result);

                    if (_errorCode == Core::ERROR_NONE) {
                        result = _result;
                    }

                    return (_errorCode);
                });

            // Property: 'setpreferredcaptionslanguages' - Set preferred languages for captions (w/o)
            _module_.Register<JsonData::UserSettings::SetPreferredAudioLanguagesInfo, void>(_T("setpreferredcaptionslanguages"), 
                [_impl_](const JsonData::UserSettings::SetPreferredAudioLanguagesInfo& params) -> uint32_t {
                    uint32_t _errorCode = Core::ERROR_NONE;

                    // write-only property set
                    const string _value{params.Value};

                    _errorCode = _impl_->SetPreferredCaptionsLanguages(_value);

                    return (_errorCode);
                });

            // Property: 'getpreferredcaptionslanguages' - Gets the current PreferredCaptionsLanguages setting (r/o)
            _module_.Register<void, Core::JSON::String>(_T("getpreferredcaptionslanguages"), 
                [_impl_](Core::JSON::String& result) -> uint32_t {
                    uint32_t _errorCode = Core::ERROR_NONE;

                    // read-only property get
                    string _result{};

                    _errorCode = _impl_->GetPreferredCaptionsLanguages(_result);

                    if (_errorCode == Core::ERROR_NONE) {
                        result = _result;
                    }

                    return (_errorCode);
                });

            // Property: 'setpreferredclosedcaptionservice' - Sets the PreferredClosedCaptionService (w/o)
            _module_.Register<JsonData::UserSettings::SetPreferredAudioLanguagesInfo, void>(_T("setpreferredclosedcaptionservice"), 
                [_impl_](const JsonData::UserSettings::SetPreferredAudioLanguagesInfo& params) -> uint32_t {
                    uint32_t _errorCode = Core::ERROR_NONE;

                    // write-only property set
                    const string _value{params.Value};

                    _errorCode = _impl_->SetPreferredClosedCaptionService(_value);

                    return (_errorCode);
                });

            // Property: 'getpreferredclosedcaptionservice' - Gets the current PreferredClosedCaptionService setting (r/o)
            _module_.Register<void, Core::JSON::String>(_T("getpreferredclosedcaptionservice"), 
                [_impl_](Core::JSON::String& result) -> uint32_t {
                    uint32_t _errorCode = Core::ERROR_NONE;

                    // read-only property get
                    string _result{};

                    _errorCode = _impl_->GetPreferredClosedCaptionService(_result);

                    if (_errorCode == Core::ERROR_NONE) {
                        result = _result;
                    }

                    return (_errorCode);
                });

            // Property: 'setprivacymode' - Sets the PrivacyMode (w/o)
            _module_.Register<JsonData::UserSettings::SetPreferredAudioLanguagesInfo, void>(_T("setprivacymode"), 
                [_impl_](const JsonData::UserSettings::SetPreferredAudioLanguagesInfo& params) -> uint32_t {
                    uint32_t _errorCode = Core::ERROR_NONE;

                    // write-only property set
                    const string _value{params.Value};

                    _errorCode = _impl_->SetPrivacyMode(_value);

                    return (_errorCode);
                });

            // Property: 'getprivacymode' - Gets the current PrivacyMode setting (r/o)
            _module_.Register<void, Core::JSON::String>(_T("getprivacymode"), 
                [_impl_](Core::JSON::String& result) -> uint32_t {
                    uint32_t _errorCode = Core::ERROR_NONE;

                    // read-only property get
                    string _result{};

                    _errorCode = _impl_->GetPrivacyMode(_result);

                    if (_errorCode == Core::ERROR_NONE) {
                        result = _result;
                    }

                    return (_errorCode);
                });

        }

        static void Unregister(JSONRPC& _module_)
        {
            // Unregister methods and properties...
            _module_.Unregister(_T("setaudiodescription"));
            _module_.Unregister(_T("getaudiodescription"));
            _module_.Unregister(_T("setpreferredaudiolanguages"));
            _module_.Unregister(_T("getpreferredaudiolanguages"));
            _module_.Unregister(_T("setpresentationlanguage"));
            _module_.Unregister(_T("getpresentationlanguage"));
            _module_.Unregister(_T("setcaptions"));
            _module_.Unregister(_T("getcaptions"));
            _module_.Unregister(_T("setpreferredcaptionslanguages"));
            _module_.Unregister(_T("getpreferredcaptionslanguages"));
            _module_.Unregister(_T("setpreferredclosedcaptionservice"));
            _module_.Unregister(_T("getpreferredclosedcaptionservice"));
            _module_.Unregister(_T("setprivacymode"));
            _module_.Unregister(_T("getprivacymode"));
        }

        namespace Event {

            // Event: 'onaudiodescriptionchanged' - The AudioDescription setting has changed
            static void OnAudioDescriptionChanged(const JSONRPC& _module_, const JsonData::UserSettings::OnAudioDescriptionChangedParamsInfo& params)
            {
                _module_.Notify(_T("onaudiodescriptionchanged"), params);
            }

            // Event: 'onaudiodescriptionchanged' - The AudioDescription setting has changed
            static void OnAudioDescriptionChanged(const JSONRPC& _module_, const Core::JSON::Boolean& enabled)
            {
                JsonData::UserSettings::OnAudioDescriptionChangedParamsInfo _params_;
                _params_.Enabled = enabled;

                OnAudioDescriptionChanged(_module_, _params_);
            }

            // Event: 'onaudiodescriptionchanged' - The AudioDescription setting has changed
            static void OnAudioDescriptionChanged(const JSONRPC& _module_, const bool& enabled)
            {
                JsonData::UserSettings::OnAudioDescriptionChangedParamsInfo _params_;
                _params_.Enabled = enabled;

                OnAudioDescriptionChanged(_module_, _params_);
            }

            // Event: 'onpreferredaudiolanguageschanged' - The preferredLanguages setting has changed
            static void OnPreferredAudioLanguagesChanged(const JSONRPC& _module_,
                     const JsonData::UserSettings::OnPreferredAudioLanguagesChangedParamsInfo& params)
            {
                _module_.Notify(_T("onpreferredaudiolanguageschanged"), params);
            }

            // Event: 'onpreferredaudiolanguageschanged' - The preferredLanguages setting has changed
            static void OnPreferredAudioLanguagesChanged(const JSONRPC& _module_, const Core::JSON::String& preferredLanguages)
            {
                JsonData::UserSettings::OnPreferredAudioLanguagesChangedParamsInfo _params_;
                _params_.PreferredLanguages = preferredLanguages;

                OnPreferredAudioLanguagesChanged(_module_, _params_);
            }

            // Event: 'onpreferredaudiolanguageschanged' - The preferredLanguages setting has changed
            static void OnPreferredAudioLanguagesChanged(const JSONRPC& _module_, const string& preferredLanguages)
            {
                JsonData::UserSettings::OnPreferredAudioLanguagesChangedParamsInfo _params_;
                _params_.PreferredLanguages = preferredLanguages;

                OnPreferredAudioLanguagesChanged(_module_, _params_);
            }

            // Event: 'onpresentationlanguagechanged' - The PresentationLanguages setting has changed
            static void OnPresentationLanguageChanged(const JSONRPC& _module_, const JsonData::UserSettings::OnPresentationLanguageChangedParamsData& params)
            {
                _module_.Notify(_T("onpresentationlanguagechanged"), params);
            }

            // Event: 'onpresentationlanguagechanged' - The PresentationLanguages setting has changed
            static void OnPresentationLanguageChanged(const JSONRPC& _module_, const Core::JSON::String& presentationLanguages)
            {
                JsonData::UserSettings::OnPresentationLanguageChangedParamsData _params_;
                _params_.PresentationLanguages = presentationLanguages;

                OnPresentationLanguageChanged(_module_, _params_);
            }

            // Event: 'onpresentationlanguagechanged' - The PresentationLanguages setting has changed
            static void OnPresentationLanguageChanged(const JSONRPC& _module_, const string& presentationLanguages)
            {
                JsonData::UserSettings::OnPresentationLanguageChangedParamsData _params_;
                _params_.PresentationLanguages = presentationLanguages;

                OnPresentationLanguageChanged(_module_, _params_);
            }

            // Event: 'oncaptionschanged' - The Captions setting has changed
            static void OnCaptionsChanged(const JSONRPC& _module_, const JsonData::UserSettings::OnAudioDescriptionChangedParamsInfo& params)
            {
                _module_.Notify(_T("oncaptionschanged"), params);
            }

            // Event: 'oncaptionschanged' - The Captions setting has changed
            static void OnCaptionsChanged(const JSONRPC& _module_, const Core::JSON::Boolean& enabled)
            {
                JsonData::UserSettings::OnAudioDescriptionChangedParamsInfo _params_;
                _params_.Enabled = enabled;

                OnCaptionsChanged(_module_, _params_);
            }

            // Event: 'oncaptionschanged' - The Captions setting has changed
            static void OnCaptionsChanged(const JSONRPC& _module_, const bool& enabled)
            {
                JsonData::UserSettings::OnAudioDescriptionChangedParamsInfo _params_;
                _params_.Enabled = enabled;

                OnCaptionsChanged(_module_, _params_);
            }

            // Event: 'onpreferredcaptionslanguageschanged' - The PreferredCaptionsLanguages setting has changed
            static void OnPreferredCaptionsLanguagesChanged(const JSONRPC& _module_,
                     const JsonData::UserSettings::OnPreferredAudioLanguagesChangedParamsInfo& params)
            {
                _module_.Notify(_T("onpreferredcaptionslanguageschanged"), params);
            }

            // Event: 'onpreferredcaptionslanguageschanged' - The PreferredCaptionsLanguages setting has changed
            static void OnPreferredCaptionsLanguagesChanged(const JSONRPC& _module_, const Core::JSON::String& preferredLanguages)
            {
                JsonData::UserSettings::OnPreferredAudioLanguagesChangedParamsInfo _params_;
                _params_.PreferredLanguages = preferredLanguages;

                OnPreferredCaptionsLanguagesChanged(_module_, _params_);
            }

            // Event: 'onpreferredcaptionslanguageschanged' - The PreferredCaptionsLanguages setting has changed
            static void OnPreferredCaptionsLanguagesChanged(const JSONRPC& _module_, const string& preferredLanguages)
            {
                JsonData::UserSettings::OnPreferredAudioLanguagesChangedParamsInfo _params_;
                _params_.PreferredLanguages = preferredLanguages;

                OnPreferredCaptionsLanguagesChanged(_module_, _params_);
            }

            // Event: 'onpreferredclosedcaptionservicechanged' - The PreferredClosedCaptionService setting has changed
            static void OnPreferredClosedCaptionServiceChanged(const JSONRPC& _module_,
                     const JsonData::UserSettings::OnPreferredClosedCaptionServiceChangedParamsData& params)
            {
                _module_.Notify(_T("onpreferredclosedcaptionservicechanged"), params);
            }

            // Event: 'onpreferredclosedcaptionservicechanged' - The PreferredClosedCaptionService setting has changed
            static void OnPreferredClosedCaptionServiceChanged(const JSONRPC& _module_, const Core::JSON::String& service)
            {
                JsonData::UserSettings::OnPreferredClosedCaptionServiceChangedParamsData _params_;
                _params_.Service = service;

                OnPreferredClosedCaptionServiceChanged(_module_, _params_);
            }

            // Event: 'onpreferredclosedcaptionservicechanged' - The PreferredClosedCaptionService setting has changed
            static void OnPreferredClosedCaptionServiceChanged(const JSONRPC& _module_, const string& service)
            {
                JsonData::UserSettings::OnPreferredClosedCaptionServiceChangedParamsData _params_;
                _params_.Service = service;

                OnPreferredClosedCaptionServiceChanged(_module_, _params_);
            }

            // Event: 'onprivacymodechanged' - The PrivacyMode setting has changed
            static void OnPrivacyModeChanged(const JSONRPC& _module_, const JsonData::UserSettings::OnPrivacyModeChangedParamsData& params)
            {
                _module_.Notify(_T("onprivacymodechanged"), params);
            }

            // Event: 'onprivacymodechanged' - The PrivacyMode setting has changed
            static void OnPrivacyModeChanged(const JSONRPC& _module_, const Core::JSON::String& privacyMode)
            {
                JsonData::UserSettings::OnPrivacyModeChangedParamsData _params_;
                _params_.PrivacyMode = privacyMode;

                OnPrivacyModeChanged(_module_, _params_);
            }

            // Event: 'onprivacymodechanged' - The PrivacyMode setting has changed
            static void OnPrivacyModeChanged(const JSONRPC& _module_, const string& privacyMode)
            {
                JsonData::UserSettings::OnPrivacyModeChangedParamsData _params_;
                _params_.PrivacyMode = privacyMode;

                OnPrivacyModeChanged(_module_, _params_);
            }

        } // namespace Event

        POP_WARNING()

    } // namespace JUserSettings

} // namespace Exchange

} // namespace WPEFramework

