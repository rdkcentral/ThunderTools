// C++ types for LISA API.
// Generated automatically from 'LISA.json'. DO NOT EDIT.

// Note: This code is inherently not thread safe. If required, proper synchronisation must be added.

#pragma once

#include <core/JSON.h>

namespace Thunder {

namespace JsonData {

    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    namespace LISA {

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
            Core::JSON::String Handle; // Operation handle
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
            Core::JSON::String Type; // Application type (mime-type)
            Core::JSON::String Id; // Application ID
            Core::JSON::String Version; // Application version
        }; // class GetStorageDetailsParamsInfo

        class KeyvalueInfo : public Core::JSON::Container {
        public:
            KeyvalueInfo()
                : Core::JSON::Container()
            {
                _Init();
            }

            KeyvalueInfo(const KeyvalueInfo& _other)
                : Core::JSON::Container()
                , Key(_other.Key)
                , Value(_other.Value)
            {
                _Init();
            }

            KeyvalueInfo(KeyvalueInfo&& _other) noexcept
                : Core::JSON::Container()
                , Key(std::move(_other.Key))
                , Value(std::move(_other.Value))
            {
                _Init();
            }

            KeyvalueInfo& operator=(const KeyvalueInfo& _rhs)
            {
                Key = _rhs.Key;
                Value = _rhs.Value;
                return (*this);
            }

            KeyvalueInfo& operator=(KeyvalueInfo&& _rhs) noexcept
            {
                Key = std::move(_rhs.Key);
                Value = std::move(_rhs.Value);
                return (*this);
            }

            ~KeyvalueInfo() = default;

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
            Core::JSON::String Key; // Key property
            Core::JSON::String Value; // Value property
        }; // class KeyvalueInfo

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
            Core::JSON::String Type; // Application type (mime-type)
            Core::JSON::String Id; // Application ID
            Core::JSON::String Version; // Application version
            Core::JSON::String Key; // Metadata key
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
                Add(_T("resUrl"), &ResUrl);
            }

            DownloadParamsData(const DownloadParamsData&) = delete;
            DownloadParamsData(DownloadParamsData&&) noexcept  = delete;

            DownloadParamsData& operator=(const DownloadParamsData&) = delete;
            DownloadParamsData& operator=(DownloadParamsData&&) noexcept  = delete;

            ~DownloadParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return ((Type.IsSet() == true) && (Id.IsSet() == true) && (Version.IsSet() == true) && (ResKey.IsSet() == true) && (ResUrl.IsSet() == true));
            }

        public:
            Core::JSON::String Type; // Application type (mime-type)
            Core::JSON::String Id; // Application ID
            Core::JSON::String Version; // Application version
            Core::JSON::String ResKey; // Key to access given resource file from db entry
            Core::JSON::String ResUrl; // Url where to download a resource from
        }; // class DownloadParamsData

        class AppslistpayloadData : public Core::JSON::Container {
        public:
            class AppData : public Core::JSON::Container {
            public:
                class InstalledappData : public Core::JSON::Container {
                public:
                    InstalledappData()
                        : Core::JSON::Container()
                    {
                        _Init();
                    }

                    InstalledappData(const InstalledappData& _other)
                        : Core::JSON::Container()
                        , Version(_other.Version)
                        , AppName(_other.AppName)
                        , Category(_other.Category)
                        , Url(_other.Url)
                    {
                        _Init();
                    }

                    InstalledappData(InstalledappData&& _other) noexcept
                        : Core::JSON::Container()
                        , Version(std::move(_other.Version))
                        , AppName(std::move(_other.AppName))
                        , Category(std::move(_other.Category))
                        , Url(std::move(_other.Url))
                    {
                        _Init();
                    }

                    InstalledappData& operator=(const InstalledappData& _rhs)
                    {
                        Version = _rhs.Version;
                        AppName = _rhs.AppName;
                        if (_rhs.Category.Value().empty() == false) {
                            Category = _rhs.Category;
                        }
                        Url = _rhs.Url;
                        return (*this);
                    }

                    InstalledappData& operator=(InstalledappData&& _rhs) noexcept
                    {
                        Version = std::move(_rhs.Version);
                        AppName = std::move(_rhs.AppName);
                        Category = std::move(_rhs.Category);
                        Url = std::move(_rhs.Url);
                        return (*this);
                    }

                    ~InstalledappData() = default;

                public:
                    bool IsDataValid() const
                    {
                        return ((Version.IsSet() == true) && (AppName.IsSet() == true) && (Url.IsSet() == true));
                    }

                private:
                    void _Init()
                    {
                        Add(_T("version"), &Version);
                        Add(_T("appName"), &AppName);
                        Add(_T("category"), &Category);
                        Add(_T("url"), &Url);
                    }

                public:
                    Core::JSON::String Version; // Application version
                    Core::JSON::String AppName; // Application name
                    Core::JSON::String Category; // Application category
                    Core::JSON::String Url; // Application url
                }; // class InstalledappData

                AppData()
                    : Core::JSON::Container()
                {
                    _Init();
                }

                AppData(const AppData& _other)
                    : Core::JSON::Container()
                    , Id(_other.Id)
                    , Type(_other.Type)
                    , Installed(_other.Installed)
                {
                    _Init();
                }

                AppData(AppData&& _other) noexcept
                    : Core::JSON::Container()
                    , Id(std::move(_other.Id))
                    , Type(std::move(_other.Type))
                    , Installed(std::move(_other.Installed))
                {
                    _Init();
                }

                AppData& operator=(const AppData& _rhs)
                {
                    Id = _rhs.Id;
                    Type = _rhs.Type;
                    Installed = _rhs.Installed;
                    return (*this);
                }

                AppData& operator=(AppData&& _rhs) noexcept
                {
                    Id = std::move(_rhs.Id);
                    Type = std::move(_rhs.Type);
                    Installed = std::move(_rhs.Installed);
                    return (*this);
                }

                ~AppData() = default;

            public:
                bool IsDataValid() const
                {
                    return ((Id.IsSet() == true) && (Type.IsSet() == true) && (Installed.IsSet() == true));
                }

            private:
                void _Init()
                {
                    Add(_T("id"), &Id);
                    Add(_T("type"), &Type);
                    Add(_T("installed"), &Installed);
                }

            public:
                Core::JSON::String Id; // Application ID
                Core::JSON::String Type; // Application type (mime-type)
                Core::JSON::ArrayType<AppslistpayloadData::AppData::InstalledappData> Installed; // List of installedApp
            }; // class AppData

            AppslistpayloadData()
                : Core::JSON::Container()
            {
                Add(_T("apps"), &Apps);
            }

            AppslistpayloadData(const AppslistpayloadData&) = delete;
            AppslistpayloadData(AppslistpayloadData&&) noexcept  = delete;

            AppslistpayloadData& operator=(const AppslistpayloadData&) = delete;
            AppslistpayloadData& operator=(AppslistpayloadData&&) noexcept  = delete;

            ~AppslistpayloadData() = default;

        public:
            bool IsDataValid() const
            {
                return (Apps.IsSet() == true);
            }

        public:
            Core::JSON::ArrayType<AppslistpayloadData::AppData> Apps; // List of apps
        }; // class AppslistpayloadData

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
                return ((Type.IsSet() == true) && (Id.IsSet() == true) && (Version.IsSet() == true));
            }

        public:
            Core::JSON::String Type; // Application type (mime-type)
            Core::JSON::String Id; // Application ID
            Core::JSON::String Version; // Application version
            Core::JSON::String AppName; // Application name
            Core::JSON::String Category; // Application category
        }; // class GetListParamsData

        class LockinfoData : public Core::JSON::Container {
        public:
            LockinfoData()
                : Core::JSON::Container()
            {
                Add(_T("reason"), &Reason);
                Add(_T("owner"), &Owner);
            }

            LockinfoData(const LockinfoData&) = delete;
            LockinfoData(LockinfoData&&) noexcept  = delete;

            LockinfoData& operator=(const LockinfoData&) = delete;
            LockinfoData& operator=(LockinfoData&&) noexcept  = delete;

            ~LockinfoData() = default;

        public:
            bool IsDataValid() const
            {
                return (true);
            }

        public:
            Core::JSON::String Reason; // Reason for lock
            Core::JSON::String Owner; // Owner of lock
        }; // class LockinfoData

        class MetadatapayloadData : public Core::JSON::Container {
        public:
            MetadatapayloadData()
                : Core::JSON::Container()
            {
                Add(_T("appName"), &AppName);
                Add(_T("category"), &Category);
                Add(_T("url"), &Url);
                Add(_T("resources"), &Resources);
                Add(_T("auxMetadata"), &AuxMetadata);
            }

            MetadatapayloadData(const MetadatapayloadData&) = delete;
            MetadatapayloadData(MetadatapayloadData&&) noexcept  = delete;

            MetadatapayloadData& operator=(const MetadatapayloadData&) = delete;
            MetadatapayloadData& operator=(MetadatapayloadData&&) noexcept  = delete;

            ~MetadatapayloadData() = default;

        public:
            bool IsDataValid() const
            {
                return ((Resources.IsSet() == true) && (AuxMetadata.IsSet() == true));
            }

        public:
            Core::JSON::String AppName; // Application name
            Core::JSON::String Category; // Application category
            Core::JSON::String Url; // Application url
            Core::JSON::ArrayType<KeyvalueInfo> Resources; // List of key-value entries
            Core::JSON::ArrayType<KeyvalueInfo> AuxMetadata; // List of key-value entries
        }; // class MetadatapayloadData

        class StoragepayloadData : public Core::JSON::Container {
        public:
            class StorageData : public Core::JSON::Container {
            public:
                StorageData()
                    : Core::JSON::Container()
                {
                    Add(_T("path"), &Path);
                    Add(_T("quotaKB"), &QuotaKB);
                    Add(_T("usedKB"), &UsedKB);
                }

                StorageData(const StorageData&) = delete;
                StorageData(StorageData&&) noexcept  = delete;

                StorageData& operator=(const StorageData&) = delete;
                StorageData& operator=(StorageData&&) noexcept  = delete;

                ~StorageData() = default;

            public:
                bool IsDataValid() const
                {
                    return ((Path.IsSet() == true) && (UsedKB.IsSet() == true));
                }

            public:
                Core::JSON::String Path; // Path in local filesystem
                Core::JSON::String QuotaKB; // Number of used kilobytes of storage
                Core::JSON::String UsedKB; // Number of used kilobytes of storage
            }; // class StorageData

            StoragepayloadData()
                : Core::JSON::Container()
            {
                Add(_T("apps"), &Apps);
                Add(_T("persistent"), &Persistent);
            }

            StoragepayloadData(const StoragepayloadData&) = delete;
            StoragepayloadData(StoragepayloadData&&) noexcept  = delete;

            StoragepayloadData& operator=(const StoragepayloadData&) = delete;
            StoragepayloadData& operator=(StoragepayloadData&&) noexcept  = delete;

            ~StoragepayloadData() = default;

        public:
            bool IsDataValid() const
            {
                return (((Apps.IsSet() == true) && (Apps.IsDataValid() == true)) && ((Persistent.IsSet() == true) && (Persistent.IsDataValid() == true)));
            }

        public:
            StoragepayloadData::StorageData Apps; // Storage entry - used in results
            StorageData Persistent; // Storage entry - used in results
        }; // class StoragepayloadData

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
            Core::JSON::String Type; // Application type (mime-type)
            Core::JSON::String Id; // Application ID
            Core::JSON::String Version; // Application version
            Core::JSON::String Url; // Application url
            Core::JSON::String AppName; // Application name
            Core::JSON::String Category; // Application category
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
                return ((Type.IsSet() == true) && (Id.IsSet() == true) && (Version.IsSet() == true));
            }

        public:
            Core::JSON::String Type; // Application type (mime-type)
            Core::JSON::String Id; // Application ID
            Core::JSON::String Version; // Application version
            Core::JSON::String Reason; // Reason for lock
            Core::JSON::String Owner; // Owner of lock
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
                return ((Handle.IsSet() == true) && (Operation.IsSet() == true) && (Type.IsSet() == true) && (Id.IsSet() == true) && (Version.IsSet() == true) && (Status.IsSet() == true));
            }

        public:
            Core::JSON::String Handle; // Operation handle
            Core::JSON::String Operation; // Operation
            Core::JSON::String Type; // Application type (mime-type)
            Core::JSON::String Id; // Application ID
            Core::JSON::String Version; // Application version
            Core::JSON::String Status; // Operation status
            Core::JSON::String Details; // If error occurred this property contains details on what happened
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
            Core::JSON::String Type; // Application type (mime-type)
            Core::JSON::String Id; // Application ID
            Core::JSON::String Version; // Application version
            Core::JSON::String ResetType; // Type of the reset to perform
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
            Core::JSON::String Type; // Application type (mime-type)
            Core::JSON::String Id; // Application ID
            Core::JSON::String Version; // Application version
            Core::JSON::String Key; // Metadata key
            Core::JSON::String Value; // Metadata value
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
            Core::JSON::String Type; // Application type (mime-type)
            Core::JSON::String Id; // Application ID
            Core::JSON::String Version; // Application version
            Core::JSON::String UninstallType; // Type of the uninstall to perform
        }; // class UninstallParamsData

    } // namespace LISA

    POP_WARNING()

} // namespace JsonData

}

