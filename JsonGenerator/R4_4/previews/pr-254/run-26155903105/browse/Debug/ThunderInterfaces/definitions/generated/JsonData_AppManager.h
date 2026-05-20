// C++ classes for AppManager API JSON-RPC API.
// Generated automatically from 'IAppManager.h'. DO NOT EDIT.

// Note: This code is inherently not thread safe. If required, proper synchronisation must be added.

#pragma once

#include <core/JSON.h>
#include <interfaces/IAppManager.h>

namespace WPEFramework {

namespace JsonData {

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

            bool IsValid() const
            {
                return (true);
            }

            GetAppMetaInfoParamsInfo(const GetAppMetaInfoParamsInfo&) = delete;
            GetAppMetaInfoParamsInfo& operator=(const GetAppMetaInfoParamsInfo&) = delete;

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

            bool IsValid() const
            {
                return (true);
            }

            LaunchAppParamsInfo(const LaunchAppParamsInfo&) = delete;
            LaunchAppParamsInfo& operator=(const LaunchAppParamsInfo&) = delete;

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

            bool IsValid() const
            {
                return (true);
            }

            PrepareAppParamsInfo(const PrepareAppParamsInfo&) = delete;
            PrepareAppParamsInfo& operator=(const PrepareAppParamsInfo&) = delete;

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

            bool IsValid() const
            {
                return (true);
            }

            OnAppInstalledParamsData(const OnAppInstalledParamsData&) = delete;
            OnAppInstalledParamsData& operator=(const OnAppInstalledParamsData&) = delete;

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

            bool IsValid() const
            {
                return (true);
            }

            OnAppLaunchRequestParamsData(const OnAppLaunchRequestParamsData&) = delete;
            OnAppLaunchRequestParamsData& operator=(const OnAppLaunchRequestParamsData&) = delete;

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

            bool IsValid() const
            {
                return (true);
            }

            OnAppStateChangedParamsData(const OnAppStateChangedParamsData&) = delete;
            OnAppStateChangedParamsData& operator=(const OnAppStateChangedParamsData&) = delete;

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

            bool IsValid() const
            {
                return (true);
            }

            SendMessageParamsData(const SendMessageParamsData&) = delete;
            SendMessageParamsData& operator=(const SendMessageParamsData&) = delete;

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

            bool IsValid() const
            {
                return (true);
            }

            SetAppPropertyParamsData(const SetAppPropertyParamsData&) = delete;
            SetAppPropertyParamsData& operator=(const SetAppPropertyParamsData&) = delete;

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

            bool IsValid() const
            {
                return (true);
            }

            SetMaxHibernatedAppsData(const SetMaxHibernatedAppsData&) = delete;
            SetMaxHibernatedAppsData& operator=(const SetMaxHibernatedAppsData&) = delete;

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

            bool IsValid() const
            {
                return (true);
            }

            SetMaxHibernatedFlashUsageData(const SetMaxHibernatedFlashUsageData&) = delete;
            SetMaxHibernatedFlashUsageData& operator=(const SetMaxHibernatedFlashUsageData&) = delete;

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

            bool IsValid() const
            {
                return (true);
            }

            SetMaxInactiveAppsData(const SetMaxInactiveAppsData&) = delete;
            SetMaxInactiveAppsData& operator=(const SetMaxInactiveAppsData&) = delete;

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

            bool IsValid() const
            {
                return (true);
            }

            SetMaxInactiveRamUsageData(const SetMaxInactiveRamUsageData&) = delete;
            SetMaxInactiveRamUsageData& operator=(const SetMaxInactiveRamUsageData&) = delete;

        public:
            Core::JSON::DecUInt32 MaxInactiveRamUsage; // : maxInactiveRamUsage
        }; // class SetMaxInactiveRamUsageData

    } // namespace AppManager

} // namespace JsonData

}

