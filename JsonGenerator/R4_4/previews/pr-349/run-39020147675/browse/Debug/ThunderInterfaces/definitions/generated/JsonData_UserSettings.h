// C++ types for UserSettings API.
// Generated automatically from 'IUserSettings.h'. DO NOT EDIT.

// Note: This code is inherently not thread safe. If required, proper synchronisation must be added.

#pragma once

#include <core/JSON.h>
#include <interfaces/IUserSettings.h>

namespace WPEFramework {

namespace JsonData {

    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    namespace UserSettings {

        // Common classes
        //

        class OnAudioDescriptionChangedParamsInfo : public Core::JSON::Container {
        public:
            OnAudioDescriptionChangedParamsInfo()
                : Core::JSON::Container()
            {
                Add(_T("enabled"), &Enabled);
            }

            OnAudioDescriptionChangedParamsInfo(const OnAudioDescriptionChangedParamsInfo&) = delete;
            OnAudioDescriptionChangedParamsInfo(OnAudioDescriptionChangedParamsInfo&&) noexcept  = delete;

            OnAudioDescriptionChangedParamsInfo& operator=(const OnAudioDescriptionChangedParamsInfo&) = delete;
            OnAudioDescriptionChangedParamsInfo& operator=(OnAudioDescriptionChangedParamsInfo&&) noexcept  = delete;

            ~OnAudioDescriptionChangedParamsInfo() = default;

        public:
            bool IsDataValid() const
            {
                return (Enabled.IsSet() == true);
            }

        public:
            Core::JSON::Boolean Enabled; // Enabled/Disabled.
        }; // class OnAudioDescriptionChangedParamsInfo

        class OnPreferredAudioLanguagesChangedParamsInfo : public Core::JSON::Container {
        public:
            OnPreferredAudioLanguagesChangedParamsInfo()
                : Core::JSON::Container()
            {
                Add(_T("preferredlanguages"), &PreferredLanguages);
            }

            OnPreferredAudioLanguagesChangedParamsInfo(const OnPreferredAudioLanguagesChangedParamsInfo&) = delete;
            OnPreferredAudioLanguagesChangedParamsInfo(OnPreferredAudioLanguagesChangedParamsInfo&&) noexcept  = delete;

            OnPreferredAudioLanguagesChangedParamsInfo& operator=(const OnPreferredAudioLanguagesChangedParamsInfo&) = delete;
            OnPreferredAudioLanguagesChangedParamsInfo& operator=(OnPreferredAudioLanguagesChangedParamsInfo&&) noexcept  = delete;

            ~OnPreferredAudioLanguagesChangedParamsInfo() = default;

        public:
            bool IsDataValid() const
            {
                return (PreferredLanguages.IsSet() == true);
            }

        public:
            Core::JSON::String PreferredLanguages; // PreferredLanguages.
        }; // class OnPreferredAudioLanguagesChangedParamsInfo

        class SetAudioDescriptionInfo : public Core::JSON::Container {
        public:
            SetAudioDescriptionInfo()
                : Core::JSON::Container()
            {
                Add(_T("value"), &Value);
            }

            SetAudioDescriptionInfo(const SetAudioDescriptionInfo&) = delete;
            SetAudioDescriptionInfo(SetAudioDescriptionInfo&&) noexcept  = delete;

            SetAudioDescriptionInfo& operator=(const SetAudioDescriptionInfo&) = delete;
            SetAudioDescriptionInfo& operator=(SetAudioDescriptionInfo&&) noexcept  = delete;

            ~SetAudioDescriptionInfo() = default;

        public:
            bool IsDataValid() const
            {
                return (Value.IsSet() == true);
            }

        public:
            Core::JSON::Boolean Value; // Enabled/Disabled
        }; // class SetAudioDescriptionInfo

        class SetPreferredAudioLanguagesInfo : public Core::JSON::Container {
        public:
            SetPreferredAudioLanguagesInfo()
                : Core::JSON::Container()
            {
                Add(_T("value"), &Value);
            }

            SetPreferredAudioLanguagesInfo(const SetPreferredAudioLanguagesInfo&) = delete;
            SetPreferredAudioLanguagesInfo(SetPreferredAudioLanguagesInfo&&) noexcept  = delete;

            SetPreferredAudioLanguagesInfo& operator=(const SetPreferredAudioLanguagesInfo&) = delete;
            SetPreferredAudioLanguagesInfo& operator=(SetPreferredAudioLanguagesInfo&&) noexcept  = delete;

            ~SetPreferredAudioLanguagesInfo() = default;

        public:
            bool IsDataValid() const
            {
                return (Value.IsSet() == true);
            }

        public:
            Core::JSON::String Value; // PreferredLanguages
        }; // class SetPreferredAudioLanguagesInfo

        // Method params/result classes
        //

        class OnPreferredClosedCaptionServiceChangedParamsData : public Core::JSON::Container {
        public:
            OnPreferredClosedCaptionServiceChangedParamsData()
                : Core::JSON::Container()
            {
                Add(_T("service"), &Service);
            }

            OnPreferredClosedCaptionServiceChangedParamsData(const OnPreferredClosedCaptionServiceChangedParamsData&) = delete;
            OnPreferredClosedCaptionServiceChangedParamsData(OnPreferredClosedCaptionServiceChangedParamsData&&) noexcept  = delete;

            OnPreferredClosedCaptionServiceChangedParamsData& operator=(const OnPreferredClosedCaptionServiceChangedParamsData&) = delete;
            OnPreferredClosedCaptionServiceChangedParamsData& operator=(OnPreferredClosedCaptionServiceChangedParamsData&&) noexcept  = delete;

            ~OnPreferredClosedCaptionServiceChangedParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return (Service.IsSet() == true);
            }

        public:
            Core::JSON::String Service; // "CC[1-4]", "TEXT[1-4]", "SERVICE[1-64]".
        }; // class OnPreferredClosedCaptionServiceChangedParamsData

        class OnPresentationLanguageChangedParamsData : public Core::JSON::Container {
        public:
            OnPresentationLanguageChangedParamsData()
                : Core::JSON::Container()
            {
                Add(_T("presentationlanguages"), &PresentationLanguages);
            }

            OnPresentationLanguageChangedParamsData(const OnPresentationLanguageChangedParamsData&) = delete;
            OnPresentationLanguageChangedParamsData(OnPresentationLanguageChangedParamsData&&) noexcept  = delete;

            OnPresentationLanguageChangedParamsData& operator=(const OnPresentationLanguageChangedParamsData&) = delete;
            OnPresentationLanguageChangedParamsData& operator=(OnPresentationLanguageChangedParamsData&&) noexcept  = delete;

            ~OnPresentationLanguageChangedParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return (PresentationLanguages.IsSet() == true);
            }

        public:
            Core::JSON::String PresentationLanguages; // PresentationLanguages.
        }; // class OnPresentationLanguageChangedParamsData

        class OnPrivacyModeChangedParamsData : public Core::JSON::Container {
        public:
            OnPrivacyModeChangedParamsData()
                : Core::JSON::Container()
            {
                Add(_T("privacymode"), &PrivacyMode);
            }

            OnPrivacyModeChangedParamsData(const OnPrivacyModeChangedParamsData&) = delete;
            OnPrivacyModeChangedParamsData(OnPrivacyModeChangedParamsData&&) noexcept  = delete;

            OnPrivacyModeChangedParamsData& operator=(const OnPrivacyModeChangedParamsData&) = delete;
            OnPrivacyModeChangedParamsData& operator=(OnPrivacyModeChangedParamsData&&) noexcept  = delete;

            ~OnPrivacyModeChangedParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return (PrivacyMode.IsSet() == true);
            }

        public:
            Core::JSON::String PrivacyMode; // "SHARE", "DO_NOT_SHARE".
        }; // class OnPrivacyModeChangedParamsData

    } // namespace UserSettings

    POP_WARNING()

} // namespace JsonData

}

