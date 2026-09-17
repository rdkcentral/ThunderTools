// C++ types for PackageManager API.
// Generated automatically from 'IPackageManager.h'. DO NOT EDIT.

// Note: This code is inherently not thread safe. If required, proper synchronisation must be added.

#pragma once

#include <core/JSON.h>
#include <interfaces/IPackageManager.h>

namespace Thunder {

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
            Core::JSON::String Handle; // Handle of the currently progressing operation (i.e, install/uninstal/download)
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
            Core::JSON::String Type; // Type of the package
            Core::JSON::String Id; // Id of the package
            Core::JSON::String Version; // Version of the package
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
            Core::JSON::String Key; // Key
            Core::JSON::String Value; // Value
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
            Core::JSON::String Type; // Type of the package
            Core::JSON::String Id; // Id of the package
            Core::JSON::String Version; // Version of the package
            Core::JSON::String Key; // Key used to clear arbitrary meta data
        }; // class ClearAuxMetadataParamsData

        class DownloadParamsData : public Core::JSON::Container {
        public:
            DownloadParamsData()
                : Core::JSON::Container()
            {
                Add(_T("type"), &Type);
                Add(_T("id"), &Id);
                Add(_T("version"), &Version);
                Add(_T("resKey"), &ResKey);
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
            Core::JSON::String Type; // Type of the package
            Core::JSON::String Id; // Id of the package
            Core::JSON::String Version; // Version of the package
            Core::JSON::String ResKey; // Resorce Key
            Core::JSON::String Url; // URL used to download package
        }; // class DownloadParamsData

        class GetListParamsData : public Core::JSON::Container {
        public:
            GetListParamsData()
                : Core::JSON::Container()
            {
                Add(_T("type"), &Type);
                Add(_T("id"), &Id);
                Add(_T("version"), &Version);
                Add(_T("appName"), &AppName);
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
            Core::JSON::String Type; // Type of the package
            Core::JSON::String Id; // Id of the package
            Core::JSON::String Version; // Version of the package
            Core::JSON::String AppName; // Application Name
            Core::JSON::String Category; // Category of the package
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
            Core::JSON::String Id; // Unique identifier of the package
            Core::JSON::String Version; // Version of the package
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
            Core::JSON::String Reason; // Reason of Locking
            Core::JSON::String Owner; // Owner of Locking
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
                    Add(_T("appName"), &AppName);
                    Add(_T("type"), &Type);
                    Add(_T("category"), &Category);
                    Add(_T("url"), &Url);
                }

            public:
                Core::JSON::String AppName; // Name of the application
                Core::JSON::String Type; // Type of the package
                Core::JSON::String Category; // Category of the package
                Core::JSON::String Url; // URL used for operation
            }; // class MetadataPayloadData

            GetMetadataResultData()
                : Core::JSON::Container()
            {
                Add(_T("metadata"), &Metadata);
                Add(_T("resources"), &Resources);
                Add(_T("auxMetadata"), &AuxMetadata);
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
            GetMetadataResultData::MetadataPayloadData Metadata; // Payload of meta data
            Core::JSON::ArrayType<KeyValueInfo> Resources; // Resources
            Core::JSON::ArrayType<KeyValueInfo> AuxMetadata; // Arbitrary metadata
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
                    Add(_T("quotaKB"), &QuotaKB);
                    Add(_T("usedKB"), &UsedKB);
                }

            public:
                Core::JSON::String Path; // Path of Storage
                Core::JSON::String QuotaKB; // Total Space allowed in KB
                Core::JSON::String UsedKB; // Used Space in KB
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
            StorageInfoData::StorageDetailsData Apps; // Storage details of application
            StorageDetailsData Persistent; // Storage details of persistent
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
                Add(_T("appName"), &AppName);
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
            Core::JSON::String Type; // Type of the package
            Core::JSON::String Id; // Id of the package
            Core::JSON::String Version; // Version of the package
            Core::JSON::String Url; // URL used to install package
            Core::JSON::String AppName; // Application Name
            Core::JSON::String Category; // Category of the package
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
            Core::JSON::String Type; // Type of the package
            Core::JSON::String Id; // Id of the package
            Core::JSON::String Version; // Version of the package
            Core::JSON::String Reason; // Reason to lock the application
            Core::JSON::String Owner; // Owner used to lock
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
            Core::JSON::String Handle; // Handle of the currently progressing operation (i.e, install/uninstal/download)
            Core::JSON::String Operation; // Type of the operation
            Core::JSON::String Type; // Type of the package
            Core::JSON::String Id; // Id of the package
            Core::JSON::String Version; // Version of the package
            Core::JSON::String Status; // Current status of the operation
            Core::JSON::String Details; // Details about the operation
        }; // class OperationStatusParamsData

        class ResetParamsData : public Core::JSON::Container {
        public:
            ResetParamsData()
                : Core::JSON::Container()
            {
                Add(_T("type"), &Type);
                Add(_T("id"), &Id);
                Add(_T("version"), &Version);
                Add(_T("resetType"), &ResetType);
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
            Core::JSON::String Type; // Type of the package
            Core::JSON::String Id; // Id of the package
            Core::JSON::String Version; // Version of the package
            Core::JSON::String ResetType; // Type of Reset
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
            Core::JSON::String Type; // Type of the package
            Core::JSON::String Id; // Id of the package
            Core::JSON::String Version; // Version of the package
            Core::JSON::String Key; // Key used to set arbitrary meta data
            Core::JSON::String Value; // Value of given key
        }; // class SetAuxMetadataParamsData

        class UninstallParamsData : public Core::JSON::Container {
        public:
            UninstallParamsData()
                : Core::JSON::Container()
            {
                Add(_T("type"), &Type);
                Add(_T("id"), &Id);
                Add(_T("version"), &Version);
                Add(_T("uninstallType"), &UninstallType);
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
            Core::JSON::String Type; // Type of the package
            Core::JSON::String Id; // Id of the package
            Core::JSON::String Version; // Version of the package
            Core::JSON::String UninstallType; // Type of uninstall
        }; // class UninstallParamsData

    } // namespace PackageManager

    POP_WARNING()

} // namespace JsonData

}

