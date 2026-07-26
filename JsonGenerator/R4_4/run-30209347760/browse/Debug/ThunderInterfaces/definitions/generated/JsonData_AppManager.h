// C++ types for AppManager API.
// Generated automatically from 'IAppManager.h'. DO NOT EDIT.

// Note: This code is inherently not thread safe. If required, proper synchronisation must be added.

#pragma once

#include <core/JSON.h>
#include <interfaces/IAppManager.h>

namespace WPEFramework {

namespace JsonData {

    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    namespace AppManager {

        // Common classes
        //

        class GetAppMetaInfoParamsInfo : public Core::JSON::Container {
        public:
            GetAppMetaInfoParamsInfo()
                : Core::JSON::Container()
            {
                Add(_T("appId"), &AppId);
                Add(_T("key"), &Key);
            }

            GetAppMetaInfoParamsInfo(const GetAppMetaInfoParamsInfo&) = delete;
            GetAppMetaInfoParamsInfo(GetAppMetaInfoParamsInfo&&) noexcept  = delete;

            GetAppMetaInfoParamsInfo& operator=(const GetAppMetaInfoParamsInfo&) = delete;
            GetAppMetaInfoParamsInfo& operator=(GetAppMetaInfoParamsInfo&&) noexcept  = delete;

            ~GetAppMetaInfoParamsInfo() = default;

        public:
            bool IsDataValid() const
            {
                return ((AppId.IsSet() == true) && (Key.IsSet() == true));
            }

        public:
            Core::JSON::String AppId;
            Core::JSON::String Key;
        }; // class GetAppMetaInfoParamsInfo

        class LaunchAppParamsInfo : public Core::JSON::Container {
        public:
            LaunchAppParamsInfo()
                : Core::JSON::Container()
            {
                Add(_T("appId"), &AppId);
                Add(_T("intent"), &Intent);
                Add(_T("launchArgs"), &LaunchArgs);
            }

            LaunchAppParamsInfo(const LaunchAppParamsInfo&) = delete;
            LaunchAppParamsInfo(LaunchAppParamsInfo&&) noexcept  = delete;

            LaunchAppParamsInfo& operator=(const LaunchAppParamsInfo&) = delete;
            LaunchAppParamsInfo& operator=(LaunchAppParamsInfo&&) noexcept  = delete;

            ~LaunchAppParamsInfo() = default;

        public:
            bool IsDataValid() const
            {
                return ((AppId.IsSet() == true) && (Intent.IsSet() == true) && (LaunchArgs.IsSet() == true));
            }

        public:
            Core::JSON::String AppId;
            Core::JSON::String Intent;
            Core::JSON::String LaunchArgs;
        }; // class LaunchAppParamsInfo

        class PrepareAppParamsInfo : public Core::JSON::Container {
        public:
            PrepareAppParamsInfo()
                : Core::JSON::Container()
            {
                Add(_T("appId"), &AppId);
            }

            PrepareAppParamsInfo(const PrepareAppParamsInfo&) = delete;
            PrepareAppParamsInfo(PrepareAppParamsInfo&&) noexcept  = delete;

            PrepareAppParamsInfo& operator=(const PrepareAppParamsInfo&) = delete;
            PrepareAppParamsInfo& operator=(PrepareAppParamsInfo&&) noexcept  = delete;

            ~PrepareAppParamsInfo() = default;

        public:
            bool IsDataValid() const
            {
                return (AppId.IsSet() == true);
            }

        public:
            Core::JSON::String AppId;
        }; // class PrepareAppParamsInfo

        // Method params/result classes
        //

        class OnAppInstalledParamsData : public Core::JSON::Container {
        public:
            OnAppInstalledParamsData()
                : Core::JSON::Container()
            {
                Add(_T("appId"), &AppId);
                Add(_T("version"), &Version);
            }

            OnAppInstalledParamsData(const OnAppInstalledParamsData&) = delete;
            OnAppInstalledParamsData(OnAppInstalledParamsData&&) noexcept  = delete;

            OnAppInstalledParamsData& operator=(const OnAppInstalledParamsData&) = delete;
            OnAppInstalledParamsData& operator=(OnAppInstalledParamsData&&) noexcept  = delete;

            ~OnAppInstalledParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return ((AppId.IsSet() == true) && (Version.IsSet() == true));
            }

        public:
            Core::JSON::String AppId; // id of the application
            Core::JSON::String Version; // The version string of the app. This is a free form non-empty string
        }; // class OnAppInstalledParamsData

        class OnAppLaunchRequestParamsData : public Core::JSON::Container {
        public:
            OnAppLaunchRequestParamsData()
                : Core::JSON::Container()
            {
                Add(_T("appId"), &AppId);
                Add(_T("intent"), &Intent);
                Add(_T("source"), &Source);
            }

            OnAppLaunchRequestParamsData(const OnAppLaunchRequestParamsData&) = delete;
            OnAppLaunchRequestParamsData(OnAppLaunchRequestParamsData&&) noexcept  = delete;

            OnAppLaunchRequestParamsData& operator=(const OnAppLaunchRequestParamsData&) = delete;
            OnAppLaunchRequestParamsData& operator=(OnAppLaunchRequestParamsData&&) noexcept  = delete;

            ~OnAppLaunchRequestParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return ((AppId.IsSet() == true) && (Intent.IsSet() == true) && (Source.IsSet() == true));
            }

        public:
            Core::JSON::String AppId; // The source of the launch request
            Core::JSON::String Intent; // intent object (JSON format)
            Core::JSON::String Source; // This event is a stop-gap and expected to be deprecated in the future. Triggered when an app launch request is received from an external component. For example DIAL launch request, or app to app launch requested from a running Firebolt app.
        }; // class OnAppLaunchRequestParamsData

        class OnAppStateChangedParamsData : public Core::JSON::Container {
        public:
            OnAppStateChangedParamsData()
                : Core::JSON::Container()
            {
                Add(_T("appId"), &AppId);
                Add(_T("state"), &State);
            }

            OnAppStateChangedParamsData(const OnAppStateChangedParamsData&) = delete;
            OnAppStateChangedParamsData(OnAppStateChangedParamsData&&) noexcept  = delete;

            OnAppStateChangedParamsData& operator=(const OnAppStateChangedParamsData&) = delete;
            OnAppStateChangedParamsData& operator=(OnAppStateChangedParamsData&&) noexcept  = delete;

            ~OnAppStateChangedParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return ((AppId.IsSet() == true) && (State.IsSet() == true));
            }

        public:
            Core::JSON::String AppId; // id of the application
            Core::JSON::String State; // Triggered whenever there is a change in the lifecycle state of a running app.
        }; // class OnAppStateChangedParamsData

        class SendMessageParamsData : public Core::JSON::Container {
        public:
            SendMessageParamsData()
                : Core::JSON::Container()
            {
                Add(_T("appId"), &AppId);
                Add(_T("messagae"), &Messagae);
            }

            SendMessageParamsData(const SendMessageParamsData&) = delete;
            SendMessageParamsData(SendMessageParamsData&&) noexcept  = delete;

            SendMessageParamsData& operator=(const SendMessageParamsData&) = delete;
            SendMessageParamsData& operator=(SendMessageParamsData&&) noexcept  = delete;

            ~SendMessageParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return ((AppId.IsSet() == true) && (Messagae.IsSet() == true));
            }

        public:
            Core::JSON::String AppId;
            Core::JSON::String Messagae;
        }; // class SendMessageParamsData

        class SetAppPropertyParamsData : public Core::JSON::Container {
        public:
            SetAppPropertyParamsData()
                : Core::JSON::Container()
            {
                Add(_T("appId"), &AppId);
                Add(_T("key"), &Key);
                Add(_T("value"), &Value);
            }

            SetAppPropertyParamsData(const SetAppPropertyParamsData&) = delete;
            SetAppPropertyParamsData(SetAppPropertyParamsData&&) noexcept  = delete;

            SetAppPropertyParamsData& operator=(const SetAppPropertyParamsData&) = delete;
            SetAppPropertyParamsData& operator=(SetAppPropertyParamsData&&) noexcept  = delete;

            ~SetAppPropertyParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return ((AppId.IsSet() == true) && (Key.IsSet() == true) && (Value.IsSet() == true));
            }

        public:
            Core::JSON::String AppId;
            Core::JSON::String Key;
            Core::JSON::String Value;
        }; // class SetAppPropertyParamsData

        class SetMaxHibernatedAppsData : public Core::JSON::Container {
        public:
            SetMaxHibernatedAppsData()
                : Core::JSON::Container()
            {
                Add(_T("maxHibernatedApps"), &MaxHibernatedApps);
            }

            SetMaxHibernatedAppsData(const SetMaxHibernatedAppsData&) = delete;
            SetMaxHibernatedAppsData(SetMaxHibernatedAppsData&&) noexcept  = delete;

            SetMaxHibernatedAppsData& operator=(const SetMaxHibernatedAppsData&) = delete;
            SetMaxHibernatedAppsData& operator=(SetMaxHibernatedAppsData&&) noexcept  = delete;

            ~SetMaxHibernatedAppsData() = default;

        public:
            bool IsDataValid() const
            {
                return (MaxHibernatedApps.IsSet() == true);
            }

        public:
            Core::JSON::DecUInt32 MaxHibernatedApps; // : maxHibernatedApps
        }; // class SetMaxHibernatedAppsData

        class SetMaxHibernatedFlashUsageData : public Core::JSON::Container {
        public:
            SetMaxHibernatedFlashUsageData()
                : Core::JSON::Container()
            {
                Add(_T("maxHibernatedFlashUsage"), &MaxHibernatedFlashUsage);
            }

            SetMaxHibernatedFlashUsageData(const SetMaxHibernatedFlashUsageData&) = delete;
            SetMaxHibernatedFlashUsageData(SetMaxHibernatedFlashUsageData&&) noexcept  = delete;

            SetMaxHibernatedFlashUsageData& operator=(const SetMaxHibernatedFlashUsageData&) = delete;
            SetMaxHibernatedFlashUsageData& operator=(SetMaxHibernatedFlashUsageData&&) noexcept  = delete;

            ~SetMaxHibernatedFlashUsageData() = default;

        public:
            bool IsDataValid() const
            {
                return (MaxHibernatedFlashUsage.IsSet() == true);
            }

        public:
            Core::JSON::DecUInt32 MaxHibernatedFlashUsage; // : maxHibernatedFlashUsage
        }; // class SetMaxHibernatedFlashUsageData

        class SetMaxInactiveAppsData : public Core::JSON::Container {
        public:
            SetMaxInactiveAppsData()
                : Core::JSON::Container()
            {
                Add(_T("maxInteractiveApps"), &MaxInteractiveApps);
            }

            SetMaxInactiveAppsData(const SetMaxInactiveAppsData&) = delete;
            SetMaxInactiveAppsData(SetMaxInactiveAppsData&&) noexcept  = delete;

            SetMaxInactiveAppsData& operator=(const SetMaxInactiveAppsData&) = delete;
            SetMaxInactiveAppsData& operator=(SetMaxInactiveAppsData&&) noexcept  = delete;

            ~SetMaxInactiveAppsData() = default;

        public:
            bool IsDataValid() const
            {
                return (MaxInteractiveApps.IsSet() == true);
            }

        public:
            Core::JSON::DecUInt32 MaxInteractiveApps; // : maxInteractiveApps
        }; // class SetMaxInactiveAppsData

        class SetMaxInactiveRamUsageData : public Core::JSON::Container {
        public:
            SetMaxInactiveRamUsageData()
                : Core::JSON::Container()
            {
                Add(_T("maxInactiveRamUsage"), &MaxInactiveRamUsage);
            }

            SetMaxInactiveRamUsageData(const SetMaxInactiveRamUsageData&) = delete;
            SetMaxInactiveRamUsageData(SetMaxInactiveRamUsageData&&) noexcept  = delete;

            SetMaxInactiveRamUsageData& operator=(const SetMaxInactiveRamUsageData&) = delete;
            SetMaxInactiveRamUsageData& operator=(SetMaxInactiveRamUsageData&&) noexcept  = delete;

            ~SetMaxInactiveRamUsageData() = default;

        public:
            bool IsDataValid() const
            {
                return (MaxInactiveRamUsage.IsSet() == true);
            }

        public:
            Core::JSON::DecUInt32 MaxInactiveRamUsage; // : maxInactiveRamUsage
        }; // class SetMaxInactiveRamUsageData

    } // namespace AppManager

    POP_WARNING()

} // namespace JsonData

}

