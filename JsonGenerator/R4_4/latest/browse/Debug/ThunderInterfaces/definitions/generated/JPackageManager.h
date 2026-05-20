// Generated automatically from 'IPackageManager.h'. DO NOT EDIT.

#pragma once

#include "Module.h"
#include "JsonData_PackageManager.h"
#include <interfaces/IPackageManager.h>

namespace WPEFramework {

namespace Exchange {

    namespace JPackageManager {

        namespace Version {

            constexpr uint8_t Major = 1;
            constexpr uint8_t Minor = 0;
            constexpr uint8_t Patch = 0;

        } // namespace Version

        using JSONRPC = PluginHost::JSONRPC;

        PUSH_WARNING(DISABLE_WARNING_UNUSED_FUNCTIONS)

        static void Register(JSONRPC& _module_, IPackageManager* _impl_)
        {
            ASSERT(_impl_ != nullptr);

            _module_.RegisterVersion(_T("JPackageManager"), Version::Major, Version::Minor, Version::Patch);

            // Register methods and properties...

            // Method: 'install' - Download the application bundle
            _module_.Register<JsonData::PackageManager::InstallParamsData, Core::JSON::String>(_T("install"), 
                [_impl_](const JsonData::PackageManager::InstallParamsData& params, Core::JSON::String& handle) -> uint32_t {
                    uint32_t _errorCode = Core::ERROR_NONE;

                    const string _type{params.Type};
                    const string _id{params.Id};
                    const string _version{params.Version};
                    const string _url{params.Url};
                    const string _appName{params.AppName};
                    const string _category{params.Category};
                    string _handle{};

                    _errorCode = _impl_->Install(_type, _id, _version, _url, _appName, _category, _handle);

                    if (_errorCode == Core::ERROR_NONE) {
                        handle = _handle;
                    }

                    return (_errorCode);
                });

            // Method: 'uninstall' - Uninstall the application
            _module_.Register<JsonData::PackageManager::UninstallParamsData, Core::JSON::String>(_T("uninstall"), 
                [_impl_](const JsonData::PackageManager::UninstallParamsData& params, Core::JSON::String& handle) -> uint32_t {
                    uint32_t _errorCode = Core::ERROR_NONE;

                    const string _type{params.Type};
                    const string _id{params.Id};
                    const string _version{params.Version};
                    const string _uninstallType{params.UninstallType};
                    string _handle{};

                    _errorCode = _impl_->Uninstall(_type, _id, _version, _uninstallType, _handle);

                    if (_errorCode == Core::ERROR_NONE) {
                        handle = _handle;
                    }

                    return (_errorCode);
                });

            // Method: 'download' - Download arbitrary application's resource file
            _module_.Register<JsonData::PackageManager::DownloadParamsData, Core::JSON::String>(_T("download"), 
                [_impl_](const JsonData::PackageManager::DownloadParamsData& params, Core::JSON::String& handle) -> uint32_t {
                    uint32_t _errorCode = Core::ERROR_NONE;

                    const string _type{params.Type};
                    const string _id{params.Id};
                    const string _version{params.Version};
                    const string _resKey{params.ResKey};
                    const string _url{params.Url};
                    string _handle{};

                    _errorCode = _impl_->Download(_type, _id, _version, _resKey, _url, _handle);

                    if (_errorCode == Core::ERROR_NONE) {
                        handle = _handle;
                    }

                    return (_errorCode);
                });

            // Method: 'reset' - Delete persistent data stored locally
            _module_.Register<JsonData::PackageManager::ResetParamsData, void>(_T("reset"), 
                [_impl_](const JsonData::PackageManager::ResetParamsData& params) -> uint32_t {
                    uint32_t _errorCode = Core::ERROR_NONE;

                    const string _type{params.Type};
                    const string _id{params.Id};
                    const string _version{params.Version};
                    const string _resetType{params.ResetType};

                    _errorCode = _impl_->Reset(_type, _id, _version, _resetType);

                    return (_errorCode);
                });

            // Method: 'getstoragedetails' - Information on the storage usage
            _module_.Register<JsonData::PackageManager::GetStorageDetailsParamsInfo, JsonData::PackageManager::StorageInfoData>(_T("getstoragedetails"), 
                [_impl_](const JsonData::PackageManager::GetStorageDetailsParamsInfo& params,
                         JsonData::PackageManager::StorageInfoData& storageinfo) -> uint32_t {
                    uint32_t _errorCode = Core::ERROR_NONE;

                    const string _type{params.Type};
                    const string _id{params.Id};
                    const string _version{params.Version};
                    Exchange::IPackageManager::StorageInfo _storageinfo{};

                    _errorCode = _impl_->GetStorageDetails(_type, _id, _version, _storageinfo);

                    if (_errorCode == Core::ERROR_NONE) {
                        storageinfo = _storageinfo;
                    }

                    return (_errorCode);
                });

            // Method: 'setauxmetadata' - Set an arbitrary metadata
            _module_.Register<JsonData::PackageManager::SetAuxMetadataParamsData, void>(_T("setauxmetadata"), 
                [_impl_](const JsonData::PackageManager::SetAuxMetadataParamsData& params) -> uint32_t {
                    uint32_t _errorCode = Core::ERROR_NONE;

                    const string _type{params.Type};
                    const string _id{params.Id};
                    const string _version{params.Version};
                    const string _key{params.Key};
                    const string _value{params.Value};

                    _errorCode = _impl_->SetAuxMetadata(_type, _id, _version, _key, _value);

                    return (_errorCode);
                });

            // Method: 'clearauxmetadata' - Clears an arbitrary metadata
            _module_.Register<JsonData::PackageManager::ClearAuxMetadataParamsData, void>(_T("clearauxmetadata"), 
                [_impl_](const JsonData::PackageManager::ClearAuxMetadataParamsData& params) -> uint32_t {
                    uint32_t _errorCode = Core::ERROR_NONE;

                    const string _type{params.Type};
                    const string _id{params.Id};
                    const string _version{params.Version};
                    const string _key{params.Key};

                    _errorCode = _impl_->ClearAuxMetadata(_type, _id, _version, _key);

                    return (_errorCode);
                });

            // Method: 'getmetadata' - Get application metadata
            _module_.Register<JsonData::PackageManager::GetStorageDetailsParamsInfo, JsonData::PackageManager::GetMetadataResultData>(_T("getmetadata"), 
                [_impl_](const JsonData::PackageManager::GetStorageDetailsParamsInfo& params,
                         JsonData::PackageManager::GetMetadataResultData& result) -> uint32_t {
                    uint32_t _errorCode = Core::ERROR_NONE;

                    const string _type{params.Type};
                    const string _id{params.Id};
                    const string _version{params.Version};
                    Exchange::IPackageManager::MetadataPayload _metadata{};
                    ::WPEFramework::RPC::IIteratorType<IPackageManager::KeyValue, ID_PACKAGEMANAGER_KEY_VALUE_ITERATOR>* _resources{};
                    ::WPEFramework::RPC::IIteratorType<IPackageManager::KeyValue, ID_PACKAGEMANAGER_KEY_VALUE_ITERATOR>* _auxMetadata{};

                    _errorCode = _impl_->GetMetadata(_type, _id, _version, _metadata, _resources, _auxMetadata);

                    if (_errorCode == Core::ERROR_NONE) {
                        result.Metadata = _metadata;

                        if (_resources != nullptr) {
                            Exchange::IPackageManager::KeyValue _resourcesItem_{};
                            while (_resources->Next(_resourcesItem_) == true) { result.Resources.Add() = _resourcesItem_; }
                            _resources->Release();
                        }

                        if (_auxMetadata != nullptr) {
                            Exchange::IPackageManager::KeyValue _auxmetadataItem_{};
                            while (_auxMetadata->Next(_auxmetadataItem_) == true) { result.AuxMetadata.Add() = _auxmetadataItem_; }
                            _auxMetadata->Release();
                        }
                    }

                    return (_errorCode);
                });

            // Method: 'cancel' - Cancel asynchronous request
            _module_.Register<JsonData::PackageManager::CancelParamsInfo, void>(_T("cancel"), 
                [_impl_](const JsonData::PackageManager::CancelParamsInfo& params) -> uint32_t {
                    uint32_t _errorCode = Core::ERROR_NONE;

                    const string _handle{params.Handle};

                    _errorCode = _impl_->Cancel(_handle);

                    return (_errorCode);
                });

            // Method: 'getprogress' - Estimated progress of a request
            _module_.Register<JsonData::PackageManager::CancelParamsInfo, Core::JSON::DecUInt32>(_T("getprogress"), 
                [_impl_](const JsonData::PackageManager::CancelParamsInfo& params, Core::JSON::DecUInt32& progress) -> uint32_t {
                    uint32_t _errorCode = Core::ERROR_NONE;

                    const string _handle{params.Handle};
                    uint32_t _progress{};

                    _errorCode = _impl_->GetProgress(_handle, _progress);

                    if (_errorCode == Core::ERROR_NONE) {
                        progress = _progress;
                    }

                    return (_errorCode);
                });

            // Method: 'getlist' - List installed applications
            _module_.Register<JsonData::PackageManager::GetListParamsData, Core::JSON::ArrayType<JsonData::PackageManager::PackageKeyData>>(_T("getlist"), 
                [_impl_](const JsonData::PackageManager::GetListParamsData& params,
                         Core::JSON::ArrayType<JsonData::PackageManager::PackageKeyData>& installedIds) -> uint32_t {
                    uint32_t _errorCode = Core::ERROR_NONE;

                    const string _type{params.Type};
                    const string _id{params.Id};
                    const string _version{params.Version};
                    const string _appName{params.AppName};
                    const string _category{params.Category};
                    ::WPEFramework::RPC::IIteratorType<IPackageManager::PackageKey, ID_PACKAGEMANAGER_PACKAGE_KEY_ITERATOR>* _installedIds{};

                    _errorCode = _impl_->GetList(_type, _id, _version, _appName, _category, _installedIds);

                    if (_errorCode == Core::ERROR_NONE) {

                        if (_installedIds != nullptr) {
                            Exchange::IPackageManager::PackageKey _resultItem_{};
                            while (_installedIds->Next(_resultItem_) == true) { installedIds.Add() = _resultItem_; }
                            _installedIds->Release();
                        }
                    }

                    return (_errorCode);
                });

            // Method: 'lock' - Lock the application
            _module_.Register<JsonData::PackageManager::LockParamsData, Core::JSON::String>(_T("lock"), 
                [_impl_](const JsonData::PackageManager::LockParamsData& params, Core::JSON::String& handle) -> uint32_t {
                    uint32_t _errorCode = Core::ERROR_NONE;

                    const string _type{params.Type};
                    const string _id{params.Id};
                    const string _version{params.Version};
                    const string _reason{params.Reason};
                    const string _owner{params.Owner};
                    string _handle{};

                    _errorCode = _impl_->Lock(_type, _id, _version, _reason, _owner, _handle);

                    if (_errorCode == Core::ERROR_NONE) {
                        handle = _handle;
                    }

                    return (_errorCode);
                });

            // Method: 'unlock' - Unlock application
            _module_.Register<JsonData::PackageManager::CancelParamsInfo, void>(_T("unlock"), 
                [_impl_](const JsonData::PackageManager::CancelParamsInfo& params) -> uint32_t {
                    uint32_t _errorCode = Core::ERROR_NONE;

                    const string _handle{params.Handle};

                    _errorCode = _impl_->Unlock(_handle);

                    return (_errorCode);
                });

            // Method: 'getlockinfo' - Get lock info
            _module_.Register<JsonData::PackageManager::GetStorageDetailsParamsInfo, JsonData::PackageManager::LockInfoData>(_T("getlockinfo"), 
                [_impl_](const JsonData::PackageManager::GetStorageDetailsParamsInfo& params, JsonData::PackageManager::LockInfoData& result) -> uint32_t {
                    uint32_t _errorCode = Core::ERROR_NONE;

                    const string _type{params.Type};
                    const string _id{params.Id};
                    const string _version{params.Version};
                    Exchange::IPackageManager::LockInfo _result{};

                    _errorCode = _impl_->GetLockInfo(_type, _id, _version, _result);

                    if (_errorCode == Core::ERROR_NONE) {
                        result = _result;
                    }

                    return (_errorCode);
                });

        }

        static void Unregister(JSONRPC& _module_)
        {
            // Unregister methods and properties...
            _module_.Unregister(_T("install"));
            _module_.Unregister(_T("uninstall"));
            _module_.Unregister(_T("download"));
            _module_.Unregister(_T("reset"));
            _module_.Unregister(_T("getstoragedetails"));
            _module_.Unregister(_T("setauxmetadata"));
            _module_.Unregister(_T("clearauxmetadata"));
            _module_.Unregister(_T("getmetadata"));
            _module_.Unregister(_T("cancel"));
            _module_.Unregister(_T("getprogress"));
            _module_.Unregister(_T("getlist"));
            _module_.Unregister(_T("lock"));
            _module_.Unregister(_T("unlock"));
            _module_.Unregister(_T("getlockinfo"));
        }

        namespace Event {

            // Event: 'operationstatus' - Completion of asynchronous operation
            static void OperationStatus(const JSONRPC& _module_, const JsonData::PackageManager::OperationStatusParamsData& params)
            {
                _module_.Notify(_T("operationstatus"), params);
            }

            // Event: 'operationstatus' - Completion of asynchronous operation
            static void OperationStatus(const JSONRPC& _module_, const Core::JSON::String& handle, const Core::JSON::String& operation,
                     const Core::JSON::String& type, const Core::JSON::String& id, const Core::JSON::String& version, const Core::JSON::String& status,
                     const Core::JSON::String& details)
            {
                JsonData::PackageManager::OperationStatusParamsData _params_;
                _params_.Handle = handle;
                _params_.Operation = operation;
                _params_.Type = type;
                _params_.Id = id;
                _params_.Version = version;
                _params_.Status = status;
                _params_.Details = details;

                OperationStatus(_module_, _params_);
            }

            // Event: 'operationstatus' - Completion of asynchronous operation
            static void OperationStatus(const JSONRPC& _module_, const string& handle, const string& operation, const string& type, const string& id,
                     const string& version, const string& status, const string& details)
            {
                JsonData::PackageManager::OperationStatusParamsData _params_;
                _params_.Handle = handle;
                _params_.Operation = operation;
                _params_.Type = type;
                _params_.Id = id;
                _params_.Version = version;
                _params_.Status = status;
                _params_.Details = details;

                OperationStatus(_module_, _params_);
            }

        } // namespace Event

        POP_WARNING()

    } // namespace JPackageManager

} // namespace Exchange

} // namespace WPEFramework

