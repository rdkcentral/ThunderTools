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

        using JSONRPC = PluginHost::JSONRPC;

        PUSH_WARNING(DISABLE_WARNING_UNUSED_FUNCTIONS)

        static void Register(JSONRPC& _module_, IAppManager* _impl_)
        {
            ASSERT(_impl_ != nullptr);

            _module_.RegisterVersion(_T("JAppManager"), Version::Major, Version::Minor, Version::Patch);

            // Register methods and properties...

            // Method: 'getLaunchableApps'
            _module_.Register<void, Core::JSON::ArrayType<Core::JSON::String>>(_T("getLaunchableApps"), 
                [_impl_](Core::JSON::ArrayType<Core::JSON::String>& result) -> uint32_t {
                    uint32_t _errorCode = Core::ERROR_NONE;

                    ::WPEFramework::RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>* _result{};

                    _errorCode = _impl_->GetLaunchableApps(_result);

                    if (_errorCode == Core::ERROR_NONE) {

                        if (_result != nullptr) {
                            string _resultItem_{};
                            while (_result->Next(_resultItem_) == true) { result.Add() = _resultItem_; }
                            _result->Release();
                        }
                    }

                    return (_errorCode);
                });

            // Method: 'getLoadedApps'
            _module_.Register<void, Core::JSON::ArrayType<Core::JSON::String>>(_T("getLoadedApps"), 
                [_impl_](Core::JSON::ArrayType<Core::JSON::String>& result) -> uint32_t {
                    uint32_t _errorCode = Core::ERROR_NONE;

                    ::WPEFramework::RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>* _result{};

                    _errorCode = _impl_->GetLoadedApps(_result);

                    if (_errorCode == Core::ERROR_NONE) {

                        if (_result != nullptr) {
                            string _resultItem_{};
                            while (_result->Next(_resultItem_) == true) { result.Add() = _resultItem_; }
                            _result->Release();
                        }
                    }

                    return (_errorCode);
                });

            // Method: 'launchApp'
            _module_.Register<JsonData::AppManager::LaunchAppParamsInfo, void>(_T("launchApp"), 
                [_impl_](const JsonData::AppManager::LaunchAppParamsInfo& params) -> uint32_t {
                    uint32_t _errorCode = Core::ERROR_NONE;

                    const string _appId{params.AppId};
                    const string _intent{params.Intent};
                    const string _launchArgs{params.LaunchArgs};

                    _errorCode = _impl_->LaunchApp(_appId, _intent, _launchArgs);

                    return (_errorCode);
                });

            // Method: 'loadApp'
            _module_.Register<JsonData::AppManager::LaunchAppParamsInfo, void>(_T("loadApp"), 
                [_impl_](const JsonData::AppManager::LaunchAppParamsInfo& params) -> uint32_t {
                    uint32_t _errorCode = Core::ERROR_NONE;

                    const string _appId{params.AppId};
                    const string _intent{params.Intent};
                    const string _launchArgs{params.LaunchArgs};

                    _errorCode = _impl_->LoadApp(_appId, _intent, _launchArgs);

                    return (_errorCode);
                });

            // Method: 'prepareApp'
            _module_.Register<JsonData::AppManager::PrepareAppParamsInfo, void>(_T("prepareApp"), 
                [_impl_](const JsonData::AppManager::PrepareAppParamsInfo& params) -> uint32_t {
                    uint32_t _errorCode = Core::ERROR_NONE;

                    const string _appId{params.AppId};

                    _errorCode = _impl_->PrepareApp(_appId);

                    return (_errorCode);
                });

            // Method: 'sendMessage'
            _module_.Register<JsonData::AppManager::SendMessageParamsData, void>(_T("sendMessage"), 
                [_impl_](const JsonData::AppManager::SendMessageParamsData& params) -> uint32_t {
                    uint32_t _errorCode = Core::ERROR_NONE;

                    const string _appId{params.AppId};
                    const string _messagae{params.Messagae};

                    _errorCode = _impl_->SendMessage(_appId, _messagae);

                    return (_errorCode);
                });

            // Method: 'closeApp'
            _module_.Register<JsonData::AppManager::PrepareAppParamsInfo, void>(_T("closeApp"), 
                [_impl_](const JsonData::AppManager::PrepareAppParamsInfo& params) -> uint32_t {
                    uint32_t _errorCode = Core::ERROR_NONE;

                    const string _appId{params.AppId};

                    _errorCode = _impl_->CloseApp(_appId);

                    return (_errorCode);
                });

            // Method: 'terminateApp'
            _module_.Register<JsonData::AppManager::PrepareAppParamsInfo, void>(_T("terminateApp"), 
                [_impl_](const JsonData::AppManager::PrepareAppParamsInfo& params) -> uint32_t {
                    uint32_t _errorCode = Core::ERROR_NONE;

                    const string _appId{params.AppId};

                    _errorCode = _impl_->TerminateApp(_appId);

                    return (_errorCode);
                });

            // Method: 'clearAppData'
            _module_.Register<JsonData::AppManager::PrepareAppParamsInfo, void>(_T("clearAppData"), 
                [_impl_](const JsonData::AppManager::PrepareAppParamsInfo& params) -> uint32_t {
                    uint32_t _errorCode = Core::ERROR_NONE;

                    const string _appId{params.AppId};

                    _errorCode = _impl_->ClearAppData(_appId);

                    return (_errorCode);
                });

            // Method: 'setAppFocus'
            _module_.Register<JsonData::AppManager::PrepareAppParamsInfo, void>(_T("setAppFocus"), 
                [_impl_](const JsonData::AppManager::PrepareAppParamsInfo& params) -> uint32_t {
                    uint32_t _errorCode = Core::ERROR_NONE;

                    const string _appId{params.AppId};

                    _errorCode = _impl_->SetAppFocus(_appId);

                    return (_errorCode);
                });

            // Method: 'getAppMetaData'
            _module_.Register<JsonData::AppManager::GetAppMetaInfoParamsInfo, void>(_T("getAppMetaData"), 
                [_impl_](const JsonData::AppManager::GetAppMetaInfoParamsInfo& params) -> uint32_t {
                    uint32_t _errorCode = Core::ERROR_NONE;

                    const string _appId{params.AppId};
                    const string _key{params.Key};

                    _errorCode = _impl_->GetAppMetaData(_appId, _key);

                    return (_errorCode);
                });

            // Method: 'getAppProperty'
            _module_.Register<JsonData::AppManager::GetAppMetaInfoParamsInfo, void>(_T("getAppProperty"), 
                [_impl_](const JsonData::AppManager::GetAppMetaInfoParamsInfo& params) -> uint32_t {
                    uint32_t _errorCode = Core::ERROR_NONE;

                    const string _appId{params.AppId};
                    const string _key{params.Key};

                    _errorCode = _impl_->GetAppProperty(_appId, _key);

                    return (_errorCode);
                });

            // Method: 'setAppProperty'
            _module_.Register<JsonData::AppManager::SetAppPropertyParamsData, void>(_T("setAppProperty"), 
                [_impl_](const JsonData::AppManager::SetAppPropertyParamsData& params) -> uint32_t {
                    uint32_t _errorCode = Core::ERROR_NONE;

                    const string _appId{params.AppId};
                    const string _key{params.Key};
                    const string _value{params.Value};

                    _errorCode = _impl_->SetAppProperty(_appId, _key, _value);

                    return (_errorCode);
                });

            // Property: 'setMaxInactiveApps' (w/o)
            _module_.Register<JsonData::AppManager::SetMaxInactiveAppsData, void>(_T("setMaxInactiveApps"), 
                [_impl_](const JsonData::AppManager::SetMaxInactiveAppsData& params) -> uint32_t {
                    uint32_t _errorCode = Core::ERROR_NONE;

                    // write-only property set
                    const uint32_t _maxInteractiveApps{params.MaxInteractiveApps};

                    _errorCode = _impl_->SetMaxInactiveApps(_maxInteractiveApps);

                    return (_errorCode);
                });

            // Property: 'getMaxInactiveApps' (r/o)
            _module_.Register<void, Core::JSON::DecUInt32>(_T("getMaxInactiveApps"), 
                [_impl_](Core::JSON::DecUInt32& result) -> uint32_t {
                    uint32_t _errorCode = Core::ERROR_NONE;

                    // read-only property get
                    uint32_t _result{};

                    _errorCode = _impl_->GetMaxInactiveApps(_result);

                    if (_errorCode == Core::ERROR_NONE) {
                        result = _result;
                    }

                    return (_errorCode);
                });

            // Property: 'setMaxHibernatedApps' (w/o)
            _module_.Register<JsonData::AppManager::SetMaxHibernatedAppsData, void>(_T("setMaxHibernatedApps"), 
                [_impl_](const JsonData::AppManager::SetMaxHibernatedAppsData& params) -> uint32_t {
                    uint32_t _errorCode = Core::ERROR_NONE;

                    // write-only property set
                    const uint32_t _maxHibernatedApps{params.MaxHibernatedApps};

                    _errorCode = _impl_->SetMaxHibernatedApps(_maxHibernatedApps);

                    return (_errorCode);
                });

            // Property: 'getMaxHibernatedApps' (r/o)
            _module_.Register<void, Core::JSON::DecUInt32>(_T("getMaxHibernatedApps"), 
                [_impl_](Core::JSON::DecUInt32& result) -> uint32_t {
                    uint32_t _errorCode = Core::ERROR_NONE;

                    // read-only property get
                    uint32_t _result{};

                    _errorCode = _impl_->GetMaxHibernatedApps(_result);

                    if (_errorCode == Core::ERROR_NONE) {
                        result = _result;
                    }

                    return (_errorCode);
                });

            // Property: 'setMaxHibernatedFlashUsage' (w/o)
            _module_.Register<JsonData::AppManager::SetMaxHibernatedFlashUsageData, void>(_T("setMaxHibernatedFlashUsage"), 
                [_impl_](const JsonData::AppManager::SetMaxHibernatedFlashUsageData& params) -> uint32_t {
                    uint32_t _errorCode = Core::ERROR_NONE;

                    // write-only property set
                    const uint32_t _maxHibernatedFlashUsage{params.MaxHibernatedFlashUsage};

                    _errorCode = _impl_->SetMaxHibernatedFlashUsage(_maxHibernatedFlashUsage);

                    return (_errorCode);
                });

            // Property: 'getMaxHibernatedFlashUsage' (r/o)
            _module_.Register<void, Core::JSON::DecUInt32>(_T("getMaxHibernatedFlashUsage"), 
                [_impl_](Core::JSON::DecUInt32& result) -> uint32_t {
                    uint32_t _errorCode = Core::ERROR_NONE;

                    // read-only property get
                    uint32_t _result{};

                    _errorCode = _impl_->GetMaxHibernatedFlashUsage(_result);

                    if (_errorCode == Core::ERROR_NONE) {
                        result = _result;
                    }

                    return (_errorCode);
                });

            // Property: 'setMaxInactiveRamUsage' (w/o)
            _module_.Register<JsonData::AppManager::SetMaxInactiveRamUsageData, void>(_T("setMaxInactiveRamUsage"), 
                [_impl_](const JsonData::AppManager::SetMaxInactiveRamUsageData& params) -> uint32_t {
                    uint32_t _errorCode = Core::ERROR_NONE;

                    // write-only property set
                    const uint32_t _maxInactiveRamUsage{params.MaxInactiveRamUsage};

                    _errorCode = _impl_->SetMaxInactiveRamUsage(_maxInactiveRamUsage);

                    return (_errorCode);
                });

            // Property: 'getMaxInactiveRamUsage' (r/o)
            _module_.Register<void, Core::JSON::DecUInt32>(_T("getMaxInactiveRamUsage"), 
                [_impl_](Core::JSON::DecUInt32& result) -> uint32_t {
                    uint32_t _errorCode = Core::ERROR_NONE;

                    // read-only property get
                    uint32_t _result{};

                    _errorCode = _impl_->GetMaxInactiveRamUsage(_result);

                    if (_errorCode == Core::ERROR_NONE) {
                        result = _result;
                    }

                    return (_errorCode);
                });

        }

        static void Unregister(JSONRPC& _module_)
        {
            // Unregister methods and properties...
            _module_.Unregister(_T("getLaunchableApps"));
            _module_.Unregister(_T("getLoadedApps"));
            _module_.Unregister(_T("launchApp"));
            _module_.Unregister(_T("loadApp"));
            _module_.Unregister(_T("prepareApp"));
            _module_.Unregister(_T("sendMessage"));
            _module_.Unregister(_T("closeApp"));
            _module_.Unregister(_T("terminateApp"));
            _module_.Unregister(_T("clearAppData"));
            _module_.Unregister(_T("setAppFocus"));
            _module_.Unregister(_T("getAppMetaData"));
            _module_.Unregister(_T("getAppProperty"));
            _module_.Unregister(_T("setAppProperty"));
            _module_.Unregister(_T("setMaxInactiveApps"));
            _module_.Unregister(_T("getMaxInactiveApps"));
            _module_.Unregister(_T("setMaxHibernatedApps"));
            _module_.Unregister(_T("getMaxHibernatedApps"));
            _module_.Unregister(_T("setMaxHibernatedFlashUsage"));
            _module_.Unregister(_T("getMaxHibernatedFlashUsage"));
            _module_.Unregister(_T("setMaxInactiveRamUsage"));
            _module_.Unregister(_T("getMaxInactiveRamUsage"));
        }

        namespace Event {

            // Event: 'onAppInstalled' - Triggered when a new launchable app is installed for the first time or a different version is installed
            static void OnAppInstalled(const JSONRPC& _module_, const JsonData::AppManager::OnAppInstalledParamsData& params)
            {
                _module_.Notify(_T("onAppInstalled"), params);
            }

            // Event: 'onAppInstalled' - Triggered when a new launchable app is installed for the first time or a different version is installed
            static void OnAppInstalled(const JSONRPC& _module_, const Core::JSON::String& appId, const Core::JSON::String& version)
            {
                JsonData::AppManager::OnAppInstalledParamsData _params_;
                _params_.AppId = appId;
                _params_.Version = version;

                OnAppInstalled(_module_, _params_);
            }

            // Event: 'onAppInstalled' - Triggered when a new launchable app is installed for the first time or a different version is installed
            static void OnAppInstalled(const JSONRPC& _module_, const string& appId, const string& version)
            {
                JsonData::AppManager::OnAppInstalledParamsData _params_;
                _params_.AppId = appId;
                _params_.Version = version;

                OnAppInstalled(_module_, _params_);
            }

            // Event: 'onAppUninstalled' - Triggered when a launchable app has been uninstalled
            static void OnAppUninstalled(const JSONRPC& _module_, const JsonData::AppManager::PrepareAppParamsInfo& params)
            {
                _module_.Notify(_T("onAppUninstalled"), params);
            }

            // Event: 'onAppUninstalled' - Triggered when a launchable app has been uninstalled
            static void OnAppUninstalled(const JSONRPC& _module_, const Core::JSON::String& appId)
            {
                JsonData::AppManager::PrepareAppParamsInfo _params_;
                _params_.AppId = appId;

                OnAppUninstalled(_module_, _params_);
            }

            // Event: 'onAppUninstalled' - Triggered when a launchable app has been uninstalled
            static void OnAppUninstalled(const JSONRPC& _module_, const string& appId)
            {
                JsonData::AppManager::PrepareAppParamsInfo _params_;
                _params_.AppId = appId;

                OnAppUninstalled(_module_, _params_);
            }

            // Event: 'onAppStateChanged' - Triggered whenever there is a change in the lifecycle state of a running app
            static void OnAppStateChanged(const JSONRPC& _module_, const JsonData::AppManager::OnAppStateChangedParamsData& params)
            {
                _module_.Notify(_T("onAppStateChanged"), params);
            }

            // Event: 'onAppStateChanged' - Triggered whenever there is a change in the lifecycle state of a running app
            static void OnAppStateChanged(const JSONRPC& _module_, const Core::JSON::String& appId, const Core::JSON::String& state)
            {
                JsonData::AppManager::OnAppStateChangedParamsData _params_;
                _params_.AppId = appId;
                _params_.State = state;

                OnAppStateChanged(_module_, _params_);
            }

            // Event: 'onAppStateChanged' - Triggered whenever there is a change in the lifecycle state of a running app
            static void OnAppStateChanged(const JSONRPC& _module_, const string& appId, const string& state)
            {
                JsonData::AppManager::OnAppStateChangedParamsData _params_;
                _params_.AppId = appId;
                _params_.State = state;

                OnAppStateChanged(_module_, _params_);
            }

            // Event: 'onAppLaunchRequest' - This event is a stop-gap and expected to be deprecated in the future
            static void OnAppLaunchRequest(const JSONRPC& _module_, const JsonData::AppManager::OnAppLaunchRequestParamsData& params)
            {
                _module_.Notify(_T("onAppLaunchRequest"), params);
            }

            // Event: 'onAppLaunchRequest' - This event is a stop-gap and expected to be deprecated in the future
            static void OnAppLaunchRequest(const JSONRPC& _module_, const Core::JSON::String& appId, const Core::JSON::String& intent,
                     const Core::JSON::String& source)
            {
                JsonData::AppManager::OnAppLaunchRequestParamsData _params_;
                _params_.AppId = appId;
                _params_.Intent = intent;
                _params_.Source = source;

                OnAppLaunchRequest(_module_, _params_);
            }

            // Event: 'onAppLaunchRequest' - This event is a stop-gap and expected to be deprecated in the future
            static void OnAppLaunchRequest(const JSONRPC& _module_, const string& appId, const string& intent, const string& source)
            {
                JsonData::AppManager::OnAppLaunchRequestParamsData _params_;
                _params_.AppId = appId;
                _params_.Intent = intent;
                _params_.Source = source;

                OnAppLaunchRequest(_module_, _params_);
            }

        } // namespace Event

        POP_WARNING()

    } // namespace JAppManager

} // namespace Exchange

} // namespace WPEFramework

