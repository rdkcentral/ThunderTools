// C++ types for PackageManager API.
// Generated automatically from 'IPackageManager.h'. DO NOT EDIT.

// Note: This code is inherently not thread safe. If required, proper synchronisation must be added.

#pragma once

#include <core/JSON.h>
#include <interfaces/IPackageManager.h>

namespace WPEFramework {

namespace JsonData {

    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    namespace PackageManager {

        // Common classes
        //

        class CancelParamsInfo : public Core::JSON::Container {
        public:
            CancelParamsInfo()
                : Core::JSON::Container()
            {
                Add(_T("handle"), &Handle);
            }

            CancelParamsInfo(const CancelParamsInfo&) = delete;
            CancelParamsInfo(CancelParamsInfo&&) noexcept  = delete;

            CancelParamsInfo& operator=(const CancelParamsInfo&) = delete;
            CancelParamsInfo& operator=(CancelParamsInfo&&) noexcept  = delete;

            ~CancelParamsInfo() = default;

        public:
            bool IsDataValid() const
            {
                return (Handle.IsSet() == true);
            }

        public:
            Core::JSON::String Handle; // Cancel asynchronous request.
        }; // class CancelParamsInfo

        class GetStorageDetailsParamsInfo : public Core::JSON::Container {
        public:
            GetStorageDetailsParamsInfo()
                : Core::JSON::Container()
            {
                Add(_T("type"), &Type);
                Add(_T("id"), &Id);
                Add(_T("version"), &Version);
            }

            GetStorageDetailsParamsInfo(const GetStorageDetailsParamsInfo&) = delete;
            GetStorageDetailsParamsInfo(GetStorageDetailsParamsInfo&&) noexcept  = delete;

            GetStorageDetailsParamsInfo& operator=(const GetStorageDetailsParamsInfo&) = delete;
            GetStorageDetailsParamsInfo& operator=(GetStorageDetailsParamsInfo&&) noexcept  = delete;

            ~GetStorageDetailsParamsInfo() = default;

        public:
            bool IsDataValid() const
            {
                return ((Type.IsSet() == true) && (Id.IsSet() == true) && (Version.IsSet() == true));
            }

        public:
            Core::JSON::String Type; // Information on the storage usage.
            Core::JSON::String Id; // Information on the storage usage.
            Core::JSON::String Version; // Information on the storage usage.
        }; // class GetStorageDetailsParamsInfo

        class KeyValueInfo : public Core::JSON::Container {
        public:
            KeyValueInfo()
                : Core::JSON::Container()
            {
                _Init();
            }

            KeyValueInfo(const KeyValueInfo& _other)
                : Core::JSON::Container()
                , Key(_other.Key)
                , Value(_other.Value)
            {
                _Init();
            }

            KeyValueInfo(KeyValueInfo&& _other) noexcept
                : Core::JSON::Container()
                , Key(std::move(_other.Key))
                , Value(std::move(_other.Value))
            {
                _Init();
            }

            KeyValueInfo(const Exchange::IPackageManager::KeyValue& _other)
                : Core::JSON::Container()
            {
                Key = _other.key;
                Value = _other.value;
                _Init();
            }

            KeyValueInfo& operator=(const KeyValueInfo& _rhs)
            {
                Key = _rhs.Key;
                Value = _rhs.Value;
                return (*this);
            }

            KeyValueInfo& operator=(KeyValueInfo&& _rhs) noexcept
            {
                Key = std::move(_rhs.Key);
                Value = std::move(_rhs.Value);
                return (*this);
            }

            KeyValueInfo& operator=(const Exchange::IPackageManager::KeyValue& _rhs)
            {
                Key = _rhs.key;
                Value = _rhs.value;
                return (*this);
            }

            operator Exchange::IPackageManager::KeyValue() const
            {
                Exchange::IPackageManager::KeyValue _value{};
                _value.key = Key;
                _value.value = Value;
                return (_value);
            }

            ~KeyValueInfo() = default;

        public:
            bool IsDataValid() const
            {
                return ((Key.IsSet() == true) && (Value.IsSet() == true));
            }

        private:
            void _Init()
            {
                Add(_T("key"), &Key);
                Add(_T("value"), &Value);
            }

        public:
            Core::JSON::String Key;
            Core::JSON::String Value;
        }; // class KeyValueInfo

        // Method params/result classes
        //

        class ClearAuxMetadataParamsData : public Core::JSON::Container {
        public:
            ClearAuxMetadataParamsData()
                : Core::JSON::Container()
            {
                Add(_T("type"), &Type);
                Add(_T("id"), &Id);
                Add(_T("version"), &Version);
                Add(_T("key"), &Key);
            }

            ClearAuxMetadataParamsData(const ClearAuxMetadataParamsData&) = delete;
            ClearAuxMetadataParamsData(ClearAuxMetadataParamsData&&) noexcept  = delete;

            ClearAuxMetadataParamsData& operator=(const ClearAuxMetadataParamsData&) = delete;
            ClearAuxMetadataParamsData& operator=(ClearAuxMetadataParamsData&&) noexcept  = delete;

            ~ClearAuxMetadataParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return ((Type.IsSet() == true) && (Id.IsSet() == true) && (Version.IsSet() == true) && (Key.IsSet() == true));
            }

        public:
            Core::JSON::String Type; // Clears an arbitrary metadata.
            Core::JSON::String Id; // Clears an arbitrary metadata.
            Core::JSON::String Version; // Clears an arbitrary metadata.
            Core::JSON::String Key; // Clears an arbitrary metadata.
        }; // class ClearAuxMetadataParamsData

        class DownloadParamsData : public Core::JSON::Container {
        public:
            DownloadParamsData()
                : Core::JSON::Container()
            {
                Add(_T("type"), &Type);
                Add(_T("id"), &Id);
                Add(_T("version"), &Version);
                Add(_T("reskey"), &ResKey);
                Add(_T("url"), &Url);
            }

            DownloadParamsData(const DownloadParamsData&) = delete;
            DownloadParamsData(DownloadParamsData&&) noexcept  = delete;

            DownloadParamsData& operator=(const DownloadParamsData&) = delete;
            DownloadParamsData& operator=(DownloadParamsData&&) noexcept  = delete;

            ~DownloadParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return ((Type.IsSet() == true) && (Id.IsSet() == true) && (Version.IsSet() == true) && (ResKey.IsSet() == true) && (Url.IsSet() == true));
            }

        public:
            Core::JSON::String Type; // Download arbitrary application's resource file.
            Core::JSON::String Id; // Download arbitrary application's resource file.
            Core::JSON::String Version; // Download arbitrary application's resource file.
            Core::JSON::String ResKey; // Download arbitrary application's resource file.
            Core::JSON::String Url; // Download arbitrary application's resource file.
        }; // class DownloadParamsData

        class GetListParamsData : public Core::JSON::Container {
        public:
            GetListParamsData()
                : Core::JSON::Container()
            {
                Add(_T("type"), &Type);
                Add(_T("id"), &Id);
                Add(_T("version"), &Version);
                Add(_T("appname"), &AppName);
                Add(_T("category"), &Category);
            }

            GetListParamsData(const GetListParamsData&) = delete;
            GetListParamsData(GetListParamsData&&) noexcept  = delete;

            GetListParamsData& operator=(const GetListParamsData&) = delete;
            GetListParamsData& operator=(GetListParamsData&&) noexcept  = delete;

            ~GetListParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return ((Type.IsSet() == true) && (Id.IsSet() == true) && (Version.IsSet() == true) && (AppName.IsSet() == true) && (Category.IsSet() == true));
            }

        public:
            Core::JSON::String Type; // List installed applications.
            Core::JSON::String Id; // List installed applications.
            Core::JSON::String Version; // List installed applications.
            Core::JSON::String AppName; // List installed applications.
            Core::JSON::String Category; // List installed applications.
        }; // class GetListParamsData

        class PackageKeyData : public Core::JSON::Container {
        public:
            PackageKeyData()
                : Core::JSON::Container()
            {
                _Init();
            }

            PackageKeyData(const PackageKeyData& _other)
                : Core::JSON::Container()
                , Id(_other.Id)
                , Version(_other.Version)
            {
                _Init();
            }

            PackageKeyData(PackageKeyData&& _other) noexcept
                : Core::JSON::Container()
                , Id(std::move(_other.Id))
                , Version(std::move(_other.Version))
            {
                _Init();
            }

            PackageKeyData(const Exchange::IPackageManager::PackageKey& _other)
                : Core::JSON::Container()
            {
                Id = _other.id;
                Version = _other.version;
                _Init();
            }

            PackageKeyData& operator=(const PackageKeyData& _rhs)
            {
                Id = _rhs.Id;
                Version = _rhs.Version;
                return (*this);
            }

            PackageKeyData& operator=(PackageKeyData&& _rhs) noexcept
            {
                Id = std::move(_rhs.Id);
                Version = std::move(_rhs.Version);
                return (*this);
            }

            PackageKeyData& operator=(const Exchange::IPackageManager::PackageKey& _rhs)
            {
                Id = _rhs.id;
                Version = _rhs.version;
                return (*this);
            }

            operator Exchange::IPackageManager::PackageKey() const
            {
                Exchange::IPackageManager::PackageKey _value{};
                _value.id = Id;
                _value.version = Version;
                return (_value);
            }

            ~PackageKeyData() = default;

        public:
            bool IsDataValid() const
            {
                return ((Id.IsSet() == true) && (Version.IsSet() == true));
            }

        private:
            void _Init()
            {
                Add(_T("id"), &Id);
                Add(_T("version"), &Version);
            }

        public:
            Core::JSON::String Id;
            Core::JSON::String Version;
        }; // class PackageKeyData

        class LockInfoData : public Core::JSON::Container {
        public:
            LockInfoData()
                : Core::JSON::Container()
            {
                _Init();
            }

            LockInfoData(const LockInfoData& _other)
                : Core::JSON::Container()
                , Reason(_other.Reason)
                , Owner(_other.Owner)
            {
                _Init();
            }

            LockInfoData(LockInfoData&& _other) noexcept
                : Core::JSON::Container()
                , Reason(std::move(_other.Reason))
                , Owner(std::move(_other.Owner))
            {
                _Init();
            }

            LockInfoData(const Exchange::IPackageManager::LockInfo& _other)
                : Core::JSON::Container()
            {
                Reason = _other.reason;
                Owner = _other.owner;
                _Init();
            }

            LockInfoData& operator=(const LockInfoData& _rhs)
            {
                Reason = _rhs.Reason;
                Owner = _rhs.Owner;
                return (*this);
            }

            LockInfoData& operator=(LockInfoData&& _rhs) noexcept
            {
                Reason = std::move(_rhs.Reason);
                Owner = std::move(_rhs.Owner);
                return (*this);
            }

            LockInfoData& operator=(const Exchange::IPackageManager::LockInfo& _rhs)
            {
                Reason = _rhs.reason;
                Owner = _rhs.owner;
                return (*this);
            }

            operator Exchange::IPackageManager::LockInfo() const
            {
                Exchange::IPackageManager::LockInfo _value{};
                _value.reason = Reason;
                _value.owner = Owner;
                return (_value);
            }

            ~LockInfoData() = default;

        public:
            bool IsDataValid() const
            {
                return ((Reason.IsSet() == true) && (Owner.IsSet() == true));
            }

        private:
            void _Init()
            {
                Add(_T("reason"), &Reason);
                Add(_T("owner"), &Owner);
            }

        public:
            Core::JSON::String Reason; // Get lock info.
            Core::JSON::String Owner; // Get lock info.
        }; // class LockInfoData

        class GetMetadataResultData : public Core::JSON::Container {
        public:
            class MetadataPayloadData : public Core::JSON::Container {
            public:
                MetadataPayloadData()
                    : Core::JSON::Container()
                {
                    _Init();
                }

                MetadataPayloadData(const MetadataPayloadData& _other)
                    : Core::JSON::Container()
                    , AppName(_other.AppName)
                    , Type(_other.Type)
                    , Category(_other.Category)
                    , Url(_other.Url)
                {
                    _Init();
                }

                MetadataPayloadData(MetadataPayloadData&& _other) noexcept
                    : Core::JSON::Container()
                    , AppName(std::move(_other.AppName))
                    , Type(std::move(_other.Type))
                    , Category(std::move(_other.Category))
                    , Url(std::move(_other.Url))
                {
                    _Init();
                }

                MetadataPayloadData(const Exchange::IPackageManager::MetadataPayload& _other)
                    : Core::JSON::Container()
                {
                    AppName = _other.appName;
                    Type = _other.type;
                    Category = _other.category;
                    Url = _other.url;
                    _Init();
                }

                MetadataPayloadData& operator=(const MetadataPayloadData& _rhs)
                {
                    AppName = _rhs.AppName;
                    Type = _rhs.Type;
                    Category = _rhs.Category;
                    Url = _rhs.Url;
                    return (*this);
                }

                MetadataPayloadData& operator=(MetadataPayloadData&& _rhs) noexcept
                {
                    AppName = std::move(_rhs.AppName);
                    Type = std::move(_rhs.Type);
                    Category = std::move(_rhs.Category);
                    Url = std::move(_rhs.Url);
                    return (*this);
                }

                MetadataPayloadData& operator=(const Exchange::IPackageManager::MetadataPayload& _rhs)
                {
                    AppName = _rhs.appName;
                    Type = _rhs.type;
                    Category = _rhs.category;
                    Url = _rhs.url;
                    return (*this);
                }

                operator Exchange::IPackageManager::MetadataPayload() const
                {
                    Exchange::IPackageManager::MetadataPayload _value{};
                    _value.appName = AppName;
                    _value.type = Type;
                    _value.category = Category;
                    _value.url = Url;
                    return (_value);
                }

                ~MetadataPayloadData() = default;

            public:
                bool IsDataValid() const
                {
                    return ((AppName.IsSet() == true) && (Type.IsSet() == true) && (Category.IsSet() == true) && (Url.IsSet() == true));
                }

            private:
                void _Init()
                {
                    Add(_T("appname"), &AppName);
                    Add(_T("type"), &Type);
                    Add(_T("category"), &Category);
                    Add(_T("url"), &Url);
                }

            public:
                Core::JSON::String AppName;
                Core::JSON::String Type;
                Core::JSON::String Category;
                Core::JSON::String Url;
            }; // class MetadataPayloadData

            GetMetadataResultData()
                : Core::JSON::Container()
            {
                Add(_T("metadata"), &Metadata);
                Add(_T("resources"), &Resources);
                Add(_T("auxmetadata"), &AuxMetadata);
            }

            GetMetadataResultData(const GetMetadataResultData&) = delete;
            GetMetadataResultData(GetMetadataResultData&&) noexcept  = delete;

            GetMetadataResultData& operator=(const GetMetadataResultData&) = delete;
            GetMetadataResultData& operator=(GetMetadataResultData&&) noexcept  = delete;

            ~GetMetadataResultData() = default;

        public:
            bool IsDataValid() const
            {
                return (((Metadata.IsSet() == true) && (Metadata.IsDataValid() == true)) && (Resources.IsSet() == true) && (AuxMetadata.IsSet() == true));
            }

        public:
            GetMetadataResultData::MetadataPayloadData Metadata; // Get application metadata.
            Core::JSON::ArrayType<KeyValueInfo> Resources; // Get application metadata.
            Core::JSON::ArrayType<KeyValueInfo> AuxMetadata; // Get application metadata.
        }; // class GetMetadataResultData

        class StorageInfoData : public Core::JSON::Container {
        public:
            class StorageDetailsData : public Core::JSON::Container {
            public:
                StorageDetailsData()
                    : Core::JSON::Container()
                {
                    _Init();
                }

                StorageDetailsData(const StorageDetailsData& _other)
                    : Core::JSON::Container()
                    , Path(_other.Path)
                    , QuotaKB(_other.QuotaKB)
                    , UsedKB(_other.UsedKB)
                {
                    _Init();
                }

                StorageDetailsData(StorageDetailsData&& _other) noexcept
                    : Core::JSON::Container()
                    , Path(std::move(_other.Path))
                    , QuotaKB(std::move(_other.QuotaKB))
                    , UsedKB(std::move(_other.UsedKB))
                {
                    _Init();
                }

                StorageDetailsData(const Exchange::IPackageManager::StorageInfo::StorageDetails& _other)
                    : Core::JSON::Container()
                {
                    Path = _other.path;
                    QuotaKB = _other.quotaKB;
                    UsedKB = _other.usedKB;
                    _Init();
                }

                StorageDetailsData& operator=(const StorageDetailsData& _rhs)
                {
                    Path = _rhs.Path;
                    QuotaKB = _rhs.QuotaKB;
                    UsedKB = _rhs.UsedKB;
                    return (*this);
                }

                StorageDetailsData& operator=(StorageDetailsData&& _rhs) noexcept
                {
                    Path = std::move(_rhs.Path);
                    QuotaKB = std::move(_rhs.QuotaKB);
                    UsedKB = std::move(_rhs.UsedKB);
                    return (*this);
                }

                StorageDetailsData& operator=(const Exchange::IPackageManager::StorageInfo::StorageDetails& _rhs)
                {
                    Path = _rhs.path;
                    QuotaKB = _rhs.quotaKB;
                    UsedKB = _rhs.usedKB;
                    return (*this);
                }

                operator Exchange::IPackageManager::StorageInfo::StorageDetails() const
                {
                    Exchange::IPackageManager::StorageInfo::StorageDetails _value{};
                    _value.path = Path;
                    _value.quotaKB = QuotaKB;
                    _value.usedKB = UsedKB;
                    return (_value);
                }

                ~StorageDetailsData() = default;

            public:
                bool IsDataValid() const
                {
                    return ((Path.IsSet() == true) && (QuotaKB.IsSet() == true) && (UsedKB.IsSet() == true));
                }

            private:
                void _Init()
                {
                    Add(_T("path"), &Path);
                    Add(_T("quotakb"), &QuotaKB);
                    Add(_T("usedkb"), &UsedKB);
                }

            public:
                Core::JSON::String Path;
                Core::JSON::String QuotaKB;
                Core::JSON::String UsedKB;
            }; // class StorageDetailsData

            StorageInfoData()
                : Core::JSON::Container()
            {
                _Init();
            }

            StorageInfoData(const StorageInfoData& _other)
                : Core::JSON::Container()
                , Apps(_other.Apps)
                , Persistent(_other.Persistent)
            {
                _Init();
            }

            StorageInfoData(StorageInfoData&& _other) noexcept
                : Core::JSON::Container()
                , Apps(std::move(_other.Apps))
                , Persistent(std::move(_other.Persistent))
            {
                _Init();
            }

            StorageInfoData(const Exchange::IPackageManager::StorageInfo& _other)
                : Core::JSON::Container()
            {
                Apps.Set(true);
                Apps = _other.apps;
                Persistent.Set(true);
                Persistent = _other.persistent;
                _Init();
            }

            StorageInfoData& operator=(const StorageInfoData& _rhs)
            {
                Apps = _rhs.Apps;
                Persistent = _rhs.Persistent;
                return (*this);
            }

            StorageInfoData& operator=(StorageInfoData&& _rhs) noexcept
            {
                Apps = std::move(_rhs.Apps);
                Persistent = std::move(_rhs.Persistent);
                return (*this);
            }

            StorageInfoData& operator=(const Exchange::IPackageManager::StorageInfo& _rhs)
            {
                Apps.Set(true);
                Apps = _rhs.apps;
                Persistent.Set(true);
                Persistent = _rhs.persistent;
                return (*this);
            }

            operator Exchange::IPackageManager::StorageInfo() const
            {
                Exchange::IPackageManager::StorageInfo _value{};
                _value.apps = Apps;
                _value.persistent = Persistent;
                return (_value);
            }

            ~StorageInfoData() = default;

        public:
            bool IsDataValid() const
            {
                return (((Apps.IsSet() == true) && (Apps.IsDataValid() == true)) && ((Persistent.IsSet() == true) && (Persistent.IsDataValid() == true)));
            }

        private:
            void _Init()
            {
                Add(_T("apps"), &Apps);
                Add(_T("persistent"), &Persistent);
            }

        public:
            StorageInfoData::StorageDetailsData Apps; // Information on the storage usage.
            StorageDetailsData Persistent; // Information on the storage usage.
        }; // class StorageInfoData

        class InstallParamsData : public Core::JSON::Container {
        public:
            InstallParamsData()
                : Core::JSON::Container()
            {
                Add(_T("type"), &Type);
                Add(_T("id"), &Id);
                Add(_T("version"), &Version);
                Add(_T("url"), &Url);
                Add(_T("appname"), &AppName);
                Add(_T("category"), &Category);
            }

            InstallParamsData(const InstallParamsData&) = delete;
            InstallParamsData(InstallParamsData&&) noexcept  = delete;

            InstallParamsData& operator=(const InstallParamsData&) = delete;
            InstallParamsData& operator=(InstallParamsData&&) noexcept  = delete;

            ~InstallParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return ((Type.IsSet() == true) && (Id.IsSet() == true) && (Version.IsSet() == true) && (Url.IsSet() == true) && (AppName.IsSet() == true) && (Category.IsSet() == true));
            }

        public:
            Core::JSON::String Type; // Download the application bundle.
            Core::JSON::String Id; // Download the application bundle.
            Core::JSON::String Version; // Download the application bundle.
            Core::JSON::String Url; // Download the application bundle.
            Core::JSON::String AppName; // Download the application bundle.
            Core::JSON::String Category; // Download the application bundle.
        }; // class InstallParamsData

        class LockParamsData : public Core::JSON::Container {
        public:
            LockParamsData()
                : Core::JSON::Container()
            {
                Add(_T("type"), &Type);
                Add(_T("id"), &Id);
                Add(_T("version"), &Version);
                Add(_T("reason"), &Reason);
                Add(_T("owner"), &Owner);
            }

            LockParamsData(const LockParamsData&) = delete;
            LockParamsData(LockParamsData&&) noexcept  = delete;

            LockParamsData& operator=(const LockParamsData&) = delete;
            LockParamsData& operator=(LockParamsData&&) noexcept  = delete;

            ~LockParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return ((Type.IsSet() == true) && (Id.IsSet() == true) && (Version.IsSet() == true) && (Reason.IsSet() == true) && (Owner.IsSet() == true));
            }

        public:
            Core::JSON::String Type; // Lock the application. Preventing uninstallation.
            Core::JSON::String Id; // Lock the application. Preventing uninstallation.
            Core::JSON::String Version; // Lock the application. Preventing uninstallation.
            Core::JSON::String Reason; // Lock the application. Preventing uninstallation.
            Core::JSON::String Owner; // Lock the application. Preventing uninstallation.
        }; // class LockParamsData

        class OperationStatusParamsData : public Core::JSON::Container {
        public:
            OperationStatusParamsData()
                : Core::JSON::Container()
            {
                Add(_T("handle"), &Handle);
                Add(_T("operation"), &Operation);
                Add(_T("type"), &Type);
                Add(_T("id"), &Id);
                Add(_T("version"), &Version);
                Add(_T("status"), &Status);
                Add(_T("details"), &Details);
            }

            OperationStatusParamsData(const OperationStatusParamsData&) = delete;
            OperationStatusParamsData(OperationStatusParamsData&&) noexcept  = delete;

            OperationStatusParamsData& operator=(const OperationStatusParamsData&) = delete;
            OperationStatusParamsData& operator=(OperationStatusParamsData&&) noexcept  = delete;

            ~OperationStatusParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return ((Handle.IsSet() == true) && (Operation.IsSet() == true) && (Type.IsSet() == true) && (Id.IsSet() == true) && (Version.IsSet() == true) && (Status.IsSet() == true) && (Details.IsSet() == true));
            }

        public:
            Core::JSON::String Handle; // Completion of asynchronous operation.
            Core::JSON::String Operation; // Completion of asynchronous operation.
            Core::JSON::String Type; // Completion of asynchronous operation.
            Core::JSON::String Id; // Completion of asynchronous operation.
            Core::JSON::String Version; // Completion of asynchronous operation.
            Core::JSON::String Status; // Completion of asynchronous operation.
            Core::JSON::String Details; // Completion of asynchronous operation.
        }; // class OperationStatusParamsData

        class ResetParamsData : public Core::JSON::Container {
        public:
            ResetParamsData()
                : Core::JSON::Container()
            {
                Add(_T("type"), &Type);
                Add(_T("id"), &Id);
                Add(_T("version"), &Version);
                Add(_T("resettype"), &ResetType);
            }

            ResetParamsData(const ResetParamsData&) = delete;
            ResetParamsData(ResetParamsData&&) noexcept  = delete;

            ResetParamsData& operator=(const ResetParamsData&) = delete;
            ResetParamsData& operator=(ResetParamsData&&) noexcept  = delete;

            ~ResetParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return ((Type.IsSet() == true) && (Id.IsSet() == true) && (Version.IsSet() == true) && (ResetType.IsSet() == true));
            }

        public:
            Core::JSON::String Type; // Delete persistent data stored locally.
            Core::JSON::String Id; // Delete persistent data stored locally.
            Core::JSON::String Version; // Delete persistent data stored locally.
            Core::JSON::String ResetType; // Delete persistent data stored locally.
        }; // class ResetParamsData

        class SetAuxMetadataParamsData : public Core::JSON::Container {
        public:
            SetAuxMetadataParamsData()
                : Core::JSON::Container()
            {
                Add(_T("type"), &Type);
                Add(_T("id"), &Id);
                Add(_T("version"), &Version);
                Add(_T("key"), &Key);
                Add(_T("value"), &Value);
            }

            SetAuxMetadataParamsData(const SetAuxMetadataParamsData&) = delete;
            SetAuxMetadataParamsData(SetAuxMetadataParamsData&&) noexcept  = delete;

            SetAuxMetadataParamsData& operator=(const SetAuxMetadataParamsData&) = delete;
            SetAuxMetadataParamsData& operator=(SetAuxMetadataParamsData&&) noexcept  = delete;

            ~SetAuxMetadataParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return ((Type.IsSet() == true) && (Id.IsSet() == true) && (Version.IsSet() == true) && (Key.IsSet() == true) && (Value.IsSet() == true));
            }

        public:
            Core::JSON::String Type; // Set an arbitrary metadata.
            Core::JSON::String Id; // Set an arbitrary metadata.
            Core::JSON::String Version; // Set an arbitrary metadata.
            Core::JSON::String Key; // Set an arbitrary metadata.
            Core::JSON::String Value; // Set an arbitrary metadata.
        }; // class SetAuxMetadataParamsData

        class UninstallParamsData : public Core::JSON::Container {
        public:
            UninstallParamsData()
                : Core::JSON::Container()
            {
                Add(_T("type"), &Type);
                Add(_T("id"), &Id);
                Add(_T("version"), &Version);
                Add(_T("uninstalltype"), &UninstallType);
            }

            UninstallParamsData(const UninstallParamsData&) = delete;
            UninstallParamsData(UninstallParamsData&&) noexcept  = delete;

            UninstallParamsData& operator=(const UninstallParamsData&) = delete;
            UninstallParamsData& operator=(UninstallParamsData&&) noexcept  = delete;

            ~UninstallParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return ((Type.IsSet() == true) && (Id.IsSet() == true) && (Version.IsSet() == true) && (UninstallType.IsSet() == true));
            }

        public:
            Core::JSON::String Type; // Uninstall the application.
            Core::JSON::String Id; // Uninstall the application.
            Core::JSON::String Version; // Uninstall the application.
            Core::JSON::String UninstallType; // Uninstall the application.
        }; // class UninstallParamsData

    } // namespace PackageManager

    POP_WARNING()

} // namespace JsonData

}

