// Generated automatically from 'IPackageManager.h'. DO NOT EDIT.

#pragma once
#include "Module.h"
#include "JsonData_PackageManager.h"
#include <interfaces/IPackageManager.h>

namespace Thunder {

namespace Exchange {

    namespace JPackageManager {

        namespace Version {

            constexpr uint8_t Major = 1;
            constexpr uint8_t Minor = 0;
            constexpr uint8_t Patch = 0;

        } // namespace Version

        PUSH_WARNING(DISABLE_WARNING_UNUSED_FUNCTIONS)
        PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
        PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

        template<typename MODULE>
        static void Register(MODULE& _module__, IPackageManager* _implementation__)
        {
            ASSERT(_implementation__ != nullptr);

            _module__.PluginHost::JSONRPC::RegisterVersion(_T("JPackageManager"), Version::Major, Version::Minor, Version::Patch);

            // Register methods and properties...

            // Method: 'install' - Download the application bundle
            _module__.PluginHost::JSONRPC::template Register<JsonData::PackageManager::InstallParamsData, Core::JSON::String>(_T("install"),
                [_implementation__](const JsonData::PackageManager::InstallParamsData& params, Core::JSON::String& handle) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                        _errorCode__ = Core::ERROR_BAD_REQUEST;
                    }
                    else {
                        const string _type_{params.Type};
                        const string _id_{params.Id};
                        const string _version_{params.Version};
                        const string _url_{params.Url};
                        const string _appName_{params.AppName};
                        const string _category_{params.Category};
                        string _handle_{};

                        _errorCode__ = _implementation__->Install(_type_, _id_, _version_, _url_, _appName_, _category_, _handle_);

                        if (_errorCode__ == Core::ERROR_NONE) {
                            handle = _handle_;
                        }
                    }

                    return (_errorCode__);
                });

            // Method: 'uninstall' - Uninstall the application
            _module__.PluginHost::JSONRPC::template Register<JsonData::PackageManager::UninstallParamsData, Core::JSON::String>(_T("uninstall"),
                [_implementation__](const JsonData::PackageManager::UninstallParamsData& params, Core::JSON::String& handle) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                        _errorCode__ = Core::ERROR_BAD_REQUEST;
                    }
                    else {
                        const string _type_{params.Type};
                        const string _id_{params.Id};
                        const string _version_{params.Version};
                        const string _uninstallType_{params.UninstallType};
                        string _handle_{};

                        _errorCode__ = _implementation__->Uninstall(_type_, _id_, _version_, _uninstallType_, _handle_);

                        if (_errorCode__ == Core::ERROR_NONE) {
                            handle = _handle_;
                        }
                    }

                    return (_errorCode__);
                });

            // Method: 'download' - Download arbitrary application's resource file
            _module__.PluginHost::JSONRPC::template Register<JsonData::PackageManager::DownloadParamsData, Core::JSON::String>(_T("download"),
                [_implementation__](const JsonData::PackageManager::DownloadParamsData& params, Core::JSON::String& handle) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                        _errorCode__ = Core::ERROR_BAD_REQUEST;
                    }
                    else {
                        const string _type_{params.Type};
                        const string _id_{params.Id};
                        const string _version_{params.Version};
                        const string _resKey_{params.ResKey};
                        const string _url_{params.Url};
                        string _handle_{};

                        _errorCode__ = _implementation__->Download(_type_, _id_, _version_, _resKey_, _url_, _handle_);

                        if (_errorCode__ == Core::ERROR_NONE) {
                            handle = _handle_;
                        }
                    }

                    return (_errorCode__);
                });

            // Method: 'reset' - Delete persistent data stored locally
            _module__.PluginHost::JSONRPC::template Register<JsonData::PackageManager::ResetParamsData, void>(_T("reset"),
                [_implementation__](const JsonData::PackageManager::ResetParamsData& params) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                        _errorCode__ = Core::ERROR_BAD_REQUEST;
                    }
                    else {
                        const string _type_{params.Type};
                        const string _id_{params.Id};
                        const string _version_{params.Version};
                        const string _resetType_{params.ResetType};

                        _errorCode__ = _implementation__->Reset(_type_, _id_, _version_, _resetType_);

                    }

                    return (_errorCode__);
                });

            // Method: 'getStorageDetails' - Information on the storage usage
            _module__.PluginHost::JSONRPC::template Register<JsonData::PackageManager::GetStorageDetailsParamsInfo, JsonData::PackageManager::StorageInfoData>(_T("getStorageDetails"),
                [_implementation__](const JsonData::PackageManager::GetStorageDetailsParamsInfo& params, JsonData::PackageManager::StorageInfoData& storageinfo) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                        _errorCode__ = Core::ERROR_BAD_REQUEST;
                    }
                    else {
                        const string _type_{params.Type};
                        const string _id_{params.Id};
                        const string _version_{params.Version};
                        Exchange::IPackageManager::StorageInfo _storageinfo_{};

                        _errorCode__ = _implementation__->GetStorageDetails(_type_, _id_, _version_, _storageinfo_);

                        if (_errorCode__ == Core::ERROR_NONE) {
                            storageinfo.Set(true);
                            storageinfo = _storageinfo_;
                        }
                    }

                    return (_errorCode__);
                });

            // Method: 'setAuxMetadata' - Set an arbitrary metadata
            _module__.PluginHost::JSONRPC::template Register<JsonData::PackageManager::SetAuxMetadataParamsData, void>(_T("setAuxMetadata"),
                [_implementation__](const JsonData::PackageManager::SetAuxMetadataParamsData& params) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                        _errorCode__ = Core::ERROR_BAD_REQUEST;
                    }
                    else {
                        const string _type_{params.Type};
                        const string _id_{params.Id};
                        const string _version_{params.Version};
                        const string _key_{params.Key};
                        const string _value_{params.Value};

                        _errorCode__ = _implementation__->SetAuxMetadata(_type_, _id_, _version_, _key_, _value_);

                    }

                    return (_errorCode__);
                });

            // Method: 'clearAuxMetadata' - Clears an arbitrary metadata
            _module__.PluginHost::JSONRPC::template Register<JsonData::PackageManager::ClearAuxMetadataParamsData, void>(_T("clearAuxMetadata"),
                [_implementation__](const JsonData::PackageManager::ClearAuxMetadataParamsData& params) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                        _errorCode__ = Core::ERROR_BAD_REQUEST;
                    }
                    else {
                        const string _type_{params.Type};
                        const string _id_{params.Id};
                        const string _version_{params.Version};
                        const string _key_{params.Key};

                        _errorCode__ = _implementation__->ClearAuxMetadata(_type_, _id_, _version_, _key_);

                    }

                    return (_errorCode__);
                });

            // Method: 'getMetadata' - Get application metadata
            _module__.PluginHost::JSONRPC::template Register<JsonData::PackageManager::GetStorageDetailsParamsInfo, JsonData::PackageManager::GetMetadataResultData>(_T("getMetadata"),
                [_implementation__](const JsonData::PackageManager::GetStorageDetailsParamsInfo& params, JsonData::PackageManager::GetMetadataResultData& result) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                        _errorCode__ = Core::ERROR_BAD_REQUEST;
                    }
                    else {
                        const string _type_{params.Type};
                        const string _id_{params.Id};
                        const string _version_{params.Version};
                        Exchange::IPackageManager::MetadataPayload _metadata_{};
                        ::Thunder::RPC::IIteratorType<IPackageManager::KeyValue, ID_PACKAGEMANAGER_KEY_VALUE_ITERATOR>* _resources_{};
                        ::Thunder::RPC::IIteratorType<IPackageManager::KeyValue, ID_PACKAGEMANAGER_KEY_VALUE_ITERATOR>* _auxMetadata_{};

                        _errorCode__ = _implementation__->GetMetadata(_type_, _id_, _version_, _metadata_, _resources_, _auxMetadata_);

                        if (_errorCode__ == Core::ERROR_NONE) {
                            result.Metadata.Set(true);
                            result.Metadata = _metadata_;
                            result.Resources.Set(true);

                            if (_resources_ != nullptr) {
                                Exchange::IPackageManager::KeyValue _resourcesItem__{};
                                while (_resources_->Next(_resourcesItem__) == true) { result.Resources.Add() = _resourcesItem__; }
                                _resources_->Release();
                            }
                            result.AuxMetadata.Set(true);

                            if (_auxMetadata_ != nullptr) {
                                Exchange::IPackageManager::KeyValue _auxMetadataItem__{};
                                while (_auxMetadata_->Next(_auxMetadataItem__) == true) { result.AuxMetadata.Add() = _auxMetadataItem__; }
                                _auxMetadata_->Release();
                            }
                        }
                    }

                    return (_errorCode__);
                });

            // Method: 'cancel' - Cancel asynchronous request
            _module__.PluginHost::JSONRPC::template Register<JsonData::PackageManager::CancelParamsInfo, void>(_T("cancel"),
                [_implementation__](const JsonData::PackageManager::CancelParamsInfo& params) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                        _errorCode__ = Core::ERROR_BAD_REQUEST;
                    }
                    else {
                        const string _handle_{params.Handle};

                        _errorCode__ = _implementation__->Cancel(_handle_);

                    }

                    return (_errorCode__);
                });

            // Method: 'getProgress' - Estimated progress of a request
            _module__.PluginHost::JSONRPC::template Register<JsonData::PackageManager::CancelParamsInfo, Core::JSON::DecUInt32>(_T("getProgress"),
                [_implementation__](const JsonData::PackageManager::CancelParamsInfo& params, Core::JSON::DecUInt32& progress) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                        _errorCode__ = Core::ERROR_BAD_REQUEST;
                    }
                    else {
                        const string _handle_{params.Handle};
                        uint32_t _progress_{};

                        _errorCode__ = _implementation__->GetProgress(_handle_, _progress_);

                        if (_errorCode__ == Core::ERROR_NONE) {
                            progress = _progress_;
                        }
                    }

                    return (_errorCode__);
                });

            // Method: 'getList' - List installed applications
            _module__.PluginHost::JSONRPC::template Register<JsonData::PackageManager::GetListParamsData, Core::JSON::ArrayType<JsonData::PackageManager::PackageKeyData>>(_T("getList"),
                [_implementation__](const JsonData::PackageManager::GetListParamsData& params, Core::JSON::ArrayType<JsonData::PackageManager::PackageKeyData>& installedIds) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                        _errorCode__ = Core::ERROR_BAD_REQUEST;
                    }
                    else {
                        const string _type_{params.Type};
                        const string _id_{params.Id};
                        const string _version_{params.Version};
                        const string _appName_{params.AppName};
                        const string _category_{params.Category};
                        ::Thunder::RPC::IIteratorType<IPackageManager::PackageKey, ID_PACKAGEMANAGER_PACKAGE_KEY_ITERATOR>* _installedIds_{};

                        _errorCode__ = _implementation__->GetList(_type_, _id_, _version_, _appName_, _category_, _installedIds_);

                        if (_errorCode__ == Core::ERROR_NONE) {
                            installedIds.Set(true);

                            if (_installedIds_ != nullptr) {
                                Exchange::IPackageManager::PackageKey _resultItem__{};
                                while (_installedIds_->Next(_resultItem__) == true) { installedIds.Add() = _resultItem__; }
                                _installedIds_->Release();
                            }
                        }
                    }

                    return (_errorCode__);
                });

            // Method: 'lock' - Lock the application
            _module__.PluginHost::JSONRPC::template Register<JsonData::PackageManager::LockParamsData, Core::JSON::String>(_T("lock"),
                [_implementation__](const JsonData::PackageManager::LockParamsData& params, Core::JSON::String& handle) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                        _errorCode__ = Core::ERROR_BAD_REQUEST;
                    }
                    else {
                        const string _type_{params.Type};
                        const string _id_{params.Id};
                        const string _version_{params.Version};
                        const string _reason_{params.Reason};
                        const string _owner_{params.Owner};
                        string _handle_{};

                        _errorCode__ = _implementation__->Lock(_type_, _id_, _version_, _reason_, _owner_, _handle_);

                        if (_errorCode__ == Core::ERROR_NONE) {
                            handle = _handle_;
                        }
                    }

                    return (_errorCode__);
                });

            // Method: 'unlock' - Unlock application
            _module__.PluginHost::JSONRPC::template Register<JsonData::PackageManager::CancelParamsInfo, void>(_T("unlock"),
                [_implementation__](const JsonData::PackageManager::CancelParamsInfo& params) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                        _errorCode__ = Core::ERROR_BAD_REQUEST;
                    }
                    else {
                        const string _handle_{params.Handle};

                        _errorCode__ = _implementation__->Unlock(_handle_);

                    }

                    return (_errorCode__);
                });

            // Method: 'getLockInfo' - Get lock info
            _module__.PluginHost::JSONRPC::template Register<JsonData::PackageManager::GetStorageDetailsParamsInfo, JsonData::PackageManager::LockInfoData>(_T("getLockInfo"),
                [_implementation__](const JsonData::PackageManager::GetStorageDetailsParamsInfo& params, JsonData::PackageManager::LockInfoData& result) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                        _errorCode__ = Core::ERROR_BAD_REQUEST;
                    }
                    else {
                        const string _type_{params.Type};
                        const string _id_{params.Id};
                        const string _version_{params.Version};
                        Exchange::IPackageManager::LockInfo _result_{};

                        _errorCode__ = _implementation__->GetLockInfo(_type_, _id_, _version_, _result_);

                        if (_errorCode__ == Core::ERROR_NONE) {
                            result.Set(true);
                            result = _result_;
                        }
                    }

                    return (_errorCode__);
                });

        }

        template<typename MODULE>
        static void Unregister(MODULE& _module__)
        {
            // Unregister methods and properties...
            _module__.PluginHost::JSONRPC::Unregister(_T("install"));
            _module__.PluginHost::JSONRPC::Unregister(_T("uninstall"));
            _module__.PluginHost::JSONRPC::Unregister(_T("download"));
            _module__.PluginHost::JSONRPC::Unregister(_T("reset"));
            _module__.PluginHost::JSONRPC::Unregister(_T("getStorageDetails"));
            _module__.PluginHost::JSONRPC::Unregister(_T("setAuxMetadata"));
            _module__.PluginHost::JSONRPC::Unregister(_T("clearAuxMetadata"));
            _module__.PluginHost::JSONRPC::Unregister(_T("getMetadata"));
            _module__.PluginHost::JSONRPC::Unregister(_T("cancel"));
            _module__.PluginHost::JSONRPC::Unregister(_T("getProgress"));
            _module__.PluginHost::JSONRPC::Unregister(_T("getList"));
            _module__.PluginHost::JSONRPC::Unregister(_T("lock"));
            _module__.PluginHost::JSONRPC::Unregister(_T("unlock"));
            _module__.PluginHost::JSONRPC::Unregister(_T("getLockInfo"));
        }

        namespace Event {

            // Event: 'operationStatus' - Completion of asynchronous operation
            template<typename MODULE>
            static void OperationStatus(const MODULE& module_, const JsonData::PackageManager::OperationStatusParamsData& params, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                module_.Notify(_T("operationStatus"), params, sendIfMethod_);
            }

            // Event: 'operationStatus' - Completion of asynchronous operation
            template<typename MODULE>
            static void OperationStatus(const MODULE& module_, const Core::JSON::String& handle, const Core::JSON::String& operation, const Core::JSON::String& type, const Core::JSON::String& id, const Core::JSON::String& version, const Core::JSON::String& status, const Core::JSON::String& details, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                JsonData::PackageManager::OperationStatusParamsData params_;
                params_.Handle = handle;
                params_.Operation = operation;
                params_.Type = type;
                params_.Id = id;
                params_.Version = version;
                params_.Status = status;
                params_.Details = details;

                OperationStatus(module_, params_, sendIfMethod_);
            }

            // Event: 'operationStatus' - Completion of asynchronous operation
            template<typename MODULE>
            static void OperationStatus(const MODULE& module_, const string& handle, const string& operation, const string& type, const string& id, const string& version, const string& status, const string& details, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                JsonData::PackageManager::OperationStatusParamsData params_;
                params_.Handle = handle;
                params_.Operation = operation;
                params_.Type = type;
                params_.Id = id;
                params_.Version = version;
                params_.Status = status;
                params_.Details = details;

                OperationStatus(module_, params_, sendIfMethod_);
            }

        } // namespace Event

        POP_WARNING()
        POP_WARNING()
        POP_WARNING()

    } // namespace JPackageManager

} // namespace Exchange

} // namespace Thunder

