// C++ classes for UserSettings API JSON-RPC API.
// Generated automatically from 'IUserSettings.h'. DO NOT EDIT.

// Note: This code is inherently not thread safe. If required, proper synchronisation must be added.

#pragma once

#include <core/JSON.h>
#include <interfaces/IUserSettings.h>

namespace WPEFramework {

namespace JsonData {

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

            bool IsValid() const
            {
                return (true);
            }

            OnAudioDescriptionChangedParamsInfo(const OnAudioDescriptionChangedParamsInfo&) = delete;
            OnAudioDescriptionChangedParamsInfo& operator=(const OnAudioDescriptionChangedParamsInfo&) = delete;

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

            bool IsValid() const
            {
                return (true);
            }

            OnPreferredAudioLanguagesChangedParamsInfo(const OnPreferredAudioLanguagesChangedParamsInfo&) = delete;
            OnPreferredAudioLanguagesChangedParamsInfo& operator=(const OnPreferredAudioLanguagesChangedParamsInfo&) = delete;

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

            bool IsValid() const
            {
                return (true);
            }

            SetAudioDescriptionInfo(const SetAudioDescriptionInfo&) = delete;
            SetAudioDescriptionInfo& operator=(const SetAudioDescriptionInfo&) = delete;

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

            bool IsValid() const
            {
                return (true);
            }

            SetPreferredAudioLanguagesInfo(const SetPreferredAudioLanguagesInfo&) = delete;
            SetPreferredAudioLanguagesInfo& operator=(const SetPreferredAudioLanguagesInfo&) = delete;

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

            bool IsValid() const
            {
                return (true);
            }

            OnPreferredClosedCaptionServiceChangedParamsData(const OnPreferredClosedCaptionServiceChangedParamsData&) = delete;
            OnPreferredClosedCaptionServiceChangedParamsData& operator=(const OnPreferredClosedCaptionServiceChangedParamsData&) = delete;

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

            bool IsValid() const
            {
                return (true);
            }

            OnPresentationLanguageChangedParamsData(const OnPresentationLanguageChangedParamsData&) = delete;
            OnPresentationLanguageChangedParamsData& operator=(const OnPresentationLanguageChangedParamsData&) = delete;

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

            bool IsValid() const
            {
                return (true);
            }

            OnPrivacyModeChangedParamsData(const OnPrivacyModeChangedParamsData&) = delete;
            OnPrivacyModeChangedParamsData& operator=(const OnPrivacyModeChangedParamsData&) = delete;

        public:
            Core::JSON::String PrivacyMode; // "SHARE", "DO_NOT_SHARE".
        }; // class OnPrivacyModeChangedParamsData

    } // namespace UserSettings

} // namespace JsonData

}

