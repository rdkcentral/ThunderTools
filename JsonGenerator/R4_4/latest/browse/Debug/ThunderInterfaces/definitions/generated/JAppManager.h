// Generated automatically from 'IAppManager.h'. DO NOT EDIT.

#pragma once
#include "Module.h"
#include "JsonData_AppManager.h"
#include <interfaces/IAppManager.h>

namespace WPEFramework {

namespace Exchange {

    namespace JAppManager {

        namespace Version {

            constexpr uint8_t Major = 1;
            constexpr uint8_t Minor = 0;
            constexpr uint8_t Patch = 0;

        } // namespace Version

        PUSH_WARNING(DISABLE_WARNING_UNUSED_FUNCTIONS)
        PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
        PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

        template<typename MODULE>
        static void Register(MODULE& _module__, IAppManager* _implementation__)
        {
            ASSERT(_implementation__ != nullptr);

            _module__.PluginHost::JSONRPC::RegisterVersion(_T("JAppManager"), Version::Major, Version::Minor, Version::Patch);

            // Register methods and properties...

            // Method: 'getLaunchableApps'
            _module__.PluginHost::JSONRPC::Register<void, Core::JSON::ArrayType<Core::JSON::String>>(_T("getLaunchableApps"),
                [_implementation__](Core::JSON::ArrayType<Core::JSON::String>& result) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    ::WPEFramework::RPC::IIteratorType<string, ::WPEFramework::RPC::ID_STRINGITERATOR>* _result_{};

                    _errorCode__ = _implementation__->GetLaunchableApps(_result_);

                    if (_errorCode__ == Core::ERROR_NONE) {
                        result.Set(true);

                        if (_result_ != nullptr) {
                            string _resultItem__{};
                            while (_result_->Next(_resultItem__) == true) { result.Add() = _resultItem__; }
                            _result_->Release();
                        }
                    }

                    return (_errorCode__);
                });

            // Method: 'getLoadedApps'
            _module__.PluginHost::JSONRPC::Register<void, Core::JSON::ArrayType<Core::JSON::String>>(_T("getLoadedApps"),
                [_implementation__](Core::JSON::ArrayType<Core::JSON::String>& result) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    ::WPEFramework::RPC::IIteratorType<string, ::WPEFramework::RPC::ID_STRINGITERATOR>* _result_{};

                    _errorCode__ = _implementation__->GetLoadedApps(_result_);

                    if (_errorCode__ == Core::ERROR_NONE) {
                        result.Set(true);

                        if (_result_ != nullptr) {
                            string _resultItem__{};
                            while (_result_->Next(_resultItem__) == true) { result.Add() = _resultItem__; }
                            _result_->Release();
                        }
                    }

                    return (_errorCode__);
                });

            // Method: 'launchApp'
            _module__.PluginHost::JSONRPC::Register<JsonData::AppManager::LaunchAppParamsInfo, void>(_T("launchApp"),
                [_implementation__](const JsonData::AppManager::LaunchAppParamsInfo& params) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                        _errorCode__ = Core::ERROR_BAD_REQUEST;
                    }
                    else {
                        const string _appId_{params.AppId};
                        const string _intent_{params.Intent};
                        const string _launchArgs_{params.LaunchArgs};

                        _errorCode__ = _implementation__->LaunchApp(_appId_, _intent_, _launchArgs_);

                    }

                    return (_errorCode__);
                });

            // Method: 'loadApp'
            _module__.PluginHost::JSONRPC::Register<JsonData::AppManager::LaunchAppParamsInfo, void>(_T("loadApp"),
                [_implementation__](const JsonData::AppManager::LaunchAppParamsInfo& params) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                        _errorCode__ = Core::ERROR_BAD_REQUEST;
                    }
                    else {
                        const string _appId_{params.AppId};
                        const string _intent_{params.Intent};
                        const string _launchArgs_{params.LaunchArgs};

                        _errorCode__ = _implementation__->LoadApp(_appId_, _intent_, _launchArgs_);

                    }

                    return (_errorCode__);
                });

            // Method: 'prepareApp'
            _module__.PluginHost::JSONRPC::Register<JsonData::AppManager::PrepareAppParamsInfo, void>(_T("prepareApp"),
                [_implementation__](const JsonData::AppManager::PrepareAppParamsInfo& params) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                        _errorCode__ = Core::ERROR_BAD_REQUEST;
                    }
                    else {
                        const string _appId_{params.AppId};

                        _errorCode__ = _implementation__->PrepareApp(_appId_);

                    }

                    return (_errorCode__);
                });

            // Method: 'sendMessage'
            _module__.PluginHost::JSONRPC::Register<JsonData::AppManager::SendMessageParamsData, void>(_T("sendMessage"),
                [_implementation__](const JsonData::AppManager::SendMessageParamsData& params) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                        _errorCode__ = Core::ERROR_BAD_REQUEST;
                    }
                    else {
                        const string _appId_{params.AppId};
                        const string _messagae_{params.Messagae};

                        _errorCode__ = _implementation__->SendMessage(_appId_, _messagae_);

                    }

                    return (_errorCode__);
                });

            // Method: 'closeApp'
            _module__.PluginHost::JSONRPC::Register<JsonData::AppManager::PrepareAppParamsInfo, void>(_T("closeApp"),
                [_implementation__](const JsonData::AppManager::PrepareAppParamsInfo& params) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                        _errorCode__ = Core::ERROR_BAD_REQUEST;
                    }
                    else {
                        const string _appId_{params.AppId};

                        _errorCode__ = _implementation__->CloseApp(_appId_);

                    }

                    return (_errorCode__);
                });

            // Method: 'terminateApp'
            _module__.PluginHost::JSONRPC::Register<JsonData::AppManager::PrepareAppParamsInfo, void>(_T("terminateApp"),
                [_implementation__](const JsonData::AppManager::PrepareAppParamsInfo& params) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                        _errorCode__ = Core::ERROR_BAD_REQUEST;
                    }
                    else {
                        const string _appId_{params.AppId};

                        _errorCode__ = _implementation__->TerminateApp(_appId_);

                    }

                    return (_errorCode__);
                });

            // Method: 'clearAppData'
            _module__.PluginHost::JSONRPC::Register<JsonData::AppManager::PrepareAppParamsInfo, void>(_T("clearAppData"),
                [_implementation__](const JsonData::AppManager::PrepareAppParamsInfo& params) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                        _errorCode__ = Core::ERROR_BAD_REQUEST;
                    }
                    else {
                        const string _appId_{params.AppId};

                        _errorCode__ = _implementation__->ClearAppData(_appId_);

                    }

                    return (_errorCode__);
                });

            // Method: 'setAppFocus'
            _module__.PluginHost::JSONRPC::Register<JsonData::AppManager::PrepareAppParamsInfo, void>(_T("setAppFocus"),
                [_implementation__](const JsonData::AppManager::PrepareAppParamsInfo& params) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                        _errorCode__ = Core::ERROR_BAD_REQUEST;
                    }
                    else {
                        const string _appId_{params.AppId};

                        _errorCode__ = _implementation__->SetAppFocus(_appId_);

                    }

                    return (_errorCode__);
                });

            // Method: 'getAppMetaData'
            _module__.PluginHost::JSONRPC::Register<JsonData::AppManager::GetAppMetaInfoParamsInfo, void>(_T("getAppMetaData"),
                [_implementation__](const JsonData::AppManager::GetAppMetaInfoParamsInfo& params) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                        _errorCode__ = Core::ERROR_BAD_REQUEST;
                    }
                    else {
                        const string _appId_{params.AppId};
                        const string _key_{params.Key};

                        _errorCode__ = _implementation__->GetAppMetaData(_appId_, _key_);

                    }

                    return (_errorCode__);
                });

            // Method: 'getAppProperty'
            _module__.PluginHost::JSONRPC::Register<JsonData::AppManager::GetAppMetaInfoParamsInfo, void>(_T("getAppProperty"),
                [_implementation__](const JsonData::AppManager::GetAppMetaInfoParamsInfo& params) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                        _errorCode__ = Core::ERROR_BAD_REQUEST;
                    }
                    else {
                        const string _appId_{params.AppId};
                        const string _key_{params.Key};

                        _errorCode__ = _implementation__->GetAppProperty(_appId_, _key_);

                    }

                    return (_errorCode__);
                });

            // Method: 'setAppProperty'
            _module__.PluginHost::JSONRPC::Register<JsonData::AppManager::SetAppPropertyParamsData, void>(_T("setAppProperty"),
                [_implementation__](const JsonData::AppManager::SetAppPropertyParamsData& params) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                        _errorCode__ = Core::ERROR_BAD_REQUEST;
                    }
                    else {
                        const string _appId_{params.AppId};
                        const string _key_{params.Key};
                        const string _value_{params.Value};

                        _errorCode__ = _implementation__->SetAppProperty(_appId_, _key_, _value_);

                    }

                    return (_errorCode__);
                });

            // Property: 'setMaxInactiveApps' (w/o)
            _module__.PluginHost::JSONRPC::Register<JsonData::AppManager::SetMaxInactiveAppsData, void>(_T("setMaxInactiveApps"),
                [_implementation__](const JsonData::AppManager::SetMaxInactiveAppsData& params) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                        _errorCode__ = Core::ERROR_BAD_REQUEST;
                    }
                    else {
                        const uint32_t _maxInteractiveApps_{params.MaxInteractiveApps};

                        _errorCode__ = _implementation__->SetMaxInactiveApps(_maxInteractiveApps_);

                    }

                    return (_errorCode__);
                });

            // Property: 'getMaxInactiveApps' (r/o)
            _module__.PluginHost::JSONRPC::Register<void, Core::JSON::DecUInt32>(_T("getMaxInactiveApps"),
                [_implementation__](Core::JSON::DecUInt32& result) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    uint32_t _result_{};

                    _errorCode__ = _implementation__->GetMaxInactiveApps(_result_);

                    if (_errorCode__ == Core::ERROR_NONE) {
                        result = _result_;
                    }

                    return (_errorCode__);
                });

            // Property: 'setMaxHibernatedApps' (w/o)
            _module__.PluginHost::JSONRPC::Register<JsonData::AppManager::SetMaxHibernatedAppsData, void>(_T("setMaxHibernatedApps"),
                [_implementation__](const JsonData::AppManager::SetMaxHibernatedAppsData& params) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                        _errorCode__ = Core::ERROR_BAD_REQUEST;
                    }
                    else {
                        const uint32_t _maxHibernatedApps_{params.MaxHibernatedApps};

                        _errorCode__ = _implementation__->SetMaxHibernatedApps(_maxHibernatedApps_);

                    }

                    return (_errorCode__);
                });

            // Property: 'getMaxHibernatedApps' (r/o)
            _module__.PluginHost::JSONRPC::Register<void, Core::JSON::DecUInt32>(_T("getMaxHibernatedApps"),
                [_implementation__](Core::JSON::DecUInt32& result) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    uint32_t _result_{};

                    _errorCode__ = _implementation__->GetMaxHibernatedApps(_result_);

                    if (_errorCode__ == Core::ERROR_NONE) {
                        result = _result_;
                    }

                    return (_errorCode__);
                });

            // Property: 'setMaxHibernatedFlashUsage' (w/o)
            _module__.PluginHost::JSONRPC::Register<JsonData::AppManager::SetMaxHibernatedFlashUsageData, void>(_T("setMaxHibernatedFlashUsage"),
                [_implementation__](const JsonData::AppManager::SetMaxHibernatedFlashUsageData& params) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                        _errorCode__ = Core::ERROR_BAD_REQUEST;
                    }
                    else {
                        const uint32_t _maxHibernatedFlashUsage_{params.MaxHibernatedFlashUsage};

                        _errorCode__ = _implementation__->SetMaxHibernatedFlashUsage(_maxHibernatedFlashUsage_);

                    }

                    return (_errorCode__);
                });

            // Property: 'getMaxHibernatedFlashUsage' (r/o)
            _module__.PluginHost::JSONRPC::Register<void, Core::JSON::DecUInt32>(_T("getMaxHibernatedFlashUsage"),
                [_implementation__](Core::JSON::DecUInt32& result) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    uint32_t _result_{};

                    _errorCode__ = _implementation__->GetMaxHibernatedFlashUsage(_result_);

                    if (_errorCode__ == Core::ERROR_NONE) {
                        result = _result_;
                    }

                    return (_errorCode__);
                });

            // Property: 'setMaxInactiveRamUsage' (w/o)
            _module__.PluginHost::JSONRPC::Register<JsonData::AppManager::SetMaxInactiveRamUsageData, void>(_T("setMaxInactiveRamUsage"),
                [_implementation__](const JsonData::AppManager::SetMaxInactiveRamUsageData& params) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                        _errorCode__ = Core::ERROR_BAD_REQUEST;
                    }
                    else {
                        const uint32_t _maxInactiveRamUsage_{params.MaxInactiveRamUsage};

                        _errorCode__ = _implementation__->SetMaxInactiveRamUsage(_maxInactiveRamUsage_);

                    }

                    return (_errorCode__);
                });

            // Property: 'getMaxInactiveRamUsage' (r/o)
            _module__.PluginHost::JSONRPC::Register<void, Core::JSON::DecUInt32>(_T("getMaxInactiveRamUsage"),
                [_implementation__](Core::JSON::DecUInt32& result) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    uint32_t _result_{};

                    _errorCode__ = _implementation__->GetMaxInactiveRamUsage(_result_);

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
            _module__.PluginHost::JSONRPC::Unregister(_T("getLaunchableApps"));
            _module__.PluginHost::JSONRPC::Unregister(_T("getLoadedApps"));
            _module__.PluginHost::JSONRPC::Unregister(_T("launchApp"));
            _module__.PluginHost::JSONRPC::Unregister(_T("loadApp"));
            _module__.PluginHost::JSONRPC::Unregister(_T("prepareApp"));
            _module__.PluginHost::JSONRPC::Unregister(_T("sendMessage"));
            _module__.PluginHost::JSONRPC::Unregister(_T("closeApp"));
            _module__.PluginHost::JSONRPC::Unregister(_T("terminateApp"));
            _module__.PluginHost::JSONRPC::Unregister(_T("clearAppData"));
            _module__.PluginHost::JSONRPC::Unregister(_T("setAppFocus"));
            _module__.PluginHost::JSONRPC::Unregister(_T("getAppMetaData"));
            _module__.PluginHost::JSONRPC::Unregister(_T("getAppProperty"));
            _module__.PluginHost::JSONRPC::Unregister(_T("setAppProperty"));
            _module__.PluginHost::JSONRPC::Unregister(_T("setMaxInactiveApps"));
            _module__.PluginHost::JSONRPC::Unregister(_T("getMaxInactiveApps"));
            _module__.PluginHost::JSONRPC::Unregister(_T("setMaxHibernatedApps"));
            _module__.PluginHost::JSONRPC::Unregister(_T("getMaxHibernatedApps"));
            _module__.PluginHost::JSONRPC::Unregister(_T("setMaxHibernatedFlashUsage"));
            _module__.PluginHost::JSONRPC::Unregister(_T("getMaxHibernatedFlashUsage"));
            _module__.PluginHost::JSONRPC::Unregister(_T("setMaxInactiveRamUsage"));
            _module__.PluginHost::JSONRPC::Unregister(_T("getMaxInactiveRamUsage"));
        }

        namespace Event {

            // Event: 'onAppInstalled' - Triggered when a new launchable app is installed for the first time or a different version is installed
            template<typename MODULE>
            static void OnAppInstalled(const MODULE& module_, const JsonData::AppManager::OnAppInstalledParamsData& params, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                module_.Notify(_T("onAppInstalled"), params, sendIfMethod_);
            }

            // Event: 'onAppInstalled' - Triggered when a new launchable app is installed for the first time or a different version is installed
            template<typename MODULE>
            static void OnAppInstalled(const MODULE& module_, const Core::JSON::String& appId, const Core::JSON::String& version, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                JsonData::AppManager::OnAppInstalledParamsData params_;
                params_.AppId = appId;
                params_.Version = version;

                OnAppInstalled(module_, params_, sendIfMethod_);
            }

            // Event: 'onAppInstalled' - Triggered when a new launchable app is installed for the first time or a different version is installed
            template<typename MODULE>
            static void OnAppInstalled(const MODULE& module_, const string& appId, const string& version, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                JsonData::AppManager::OnAppInstalledParamsData params_;
                params_.AppId = appId;
                params_.Version = version;

                OnAppInstalled(module_, params_, sendIfMethod_);
            }

            // Event: 'onAppUninstalled' - Triggered when a launchable app has been uninstalled
            template<typename MODULE>
            static void OnAppUninstalled(const MODULE& module_, const JsonData::AppManager::PrepareAppParamsInfo& params, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                module_.Notify(_T("onAppUninstalled"), params, sendIfMethod_);
            }

            // Event: 'onAppUninstalled' - Triggered when a launchable app has been uninstalled
            template<typename MODULE>
            static void OnAppUninstalled(const MODULE& module_, const Core::JSON::String& appId, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                JsonData::AppManager::PrepareAppParamsInfo params_;
                params_.AppId = appId;

                OnAppUninstalled(module_, params_, sendIfMethod_);
            }

            // Event: 'onAppUninstalled' - Triggered when a launchable app has been uninstalled
            template<typename MODULE>
            static void OnAppUninstalled(const MODULE& module_, const string& appId, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                JsonData::AppManager::PrepareAppParamsInfo params_;
                params_.AppId = appId;

                OnAppUninstalled(module_, params_, sendIfMethod_);
            }

            // Event: 'onAppStateChanged' - Triggered whenever there is a change in the lifecycle state of a running app
            template<typename MODULE>
            static void OnAppStateChanged(const MODULE& module_, const JsonData::AppManager::OnAppStateChangedParamsData& params, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                module_.Notify(_T("onAppStateChanged"), params, sendIfMethod_);
            }

            // Event: 'onAppStateChanged' - Triggered whenever there is a change in the lifecycle state of a running app
            template<typename MODULE>
            static void OnAppStateChanged(const MODULE& module_, const Core::JSON::String& appId, const Core::JSON::String& state, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                JsonData::AppManager::OnAppStateChangedParamsData params_;
                params_.AppId = appId;
                params_.State = state;

                OnAppStateChanged(module_, params_, sendIfMethod_);
            }

            // Event: 'onAppStateChanged' - Triggered whenever there is a change in the lifecycle state of a running app
            template<typename MODULE>
            static void OnAppStateChanged(const MODULE& module_, const string& appId, const string& state, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                JsonData::AppManager::OnAppStateChangedParamsData params_;
                params_.AppId = appId;
                params_.State = state;

                OnAppStateChanged(module_, params_, sendIfMethod_);
            }

            // Event: 'onAppLaunchRequest' - This event is a stop-gap and expected to be deprecated in the future
            template<typename MODULE>
            static void OnAppLaunchRequest(const MODULE& module_, const JsonData::AppManager::OnAppLaunchRequestParamsData& params, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                module_.Notify(_T("onAppLaunchRequest"), params, sendIfMethod_);
            }

            // Event: 'onAppLaunchRequest' - This event is a stop-gap and expected to be deprecated in the future
            template<typename MODULE>
            static void OnAppLaunchRequest(const MODULE& module_, const Core::JSON::String& appId, const Core::JSON::String& intent, const Core::JSON::String& source, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                JsonData::AppManager::OnAppLaunchRequestParamsData params_;
                params_.AppId = appId;
                params_.Intent = intent;
                params_.Source = source;

                OnAppLaunchRequest(module_, params_, sendIfMethod_);
            }

            // Event: 'onAppLaunchRequest' - This event is a stop-gap and expected to be deprecated in the future
            template<typename MODULE>
            static void OnAppLaunchRequest(const MODULE& module_, const string& appId, const string& intent, const string& source, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                JsonData::AppManager::OnAppLaunchRequestParamsData params_;
                params_.AppId = appId;
                params_.Intent = intent;
                params_.Source = source;

                OnAppLaunchRequest(module_, params_, sendIfMethod_);
            }

        } // namespace Event

        POP_WARNING()
        POP_WARNING()
        POP_WARNING()

    } // namespace JAppManager

} // namespace Exchange

} // namespace WPEFramework

