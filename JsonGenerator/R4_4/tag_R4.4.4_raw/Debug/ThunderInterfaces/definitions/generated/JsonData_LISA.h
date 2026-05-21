// C++ classes for LISA API JSON-RPC API.
// Generated automatically from 'LISA.json'. DO NOT EDIT.

// Note: This code is inherently not thread safe. If required, proper synchronisation must be added.

#pragma once

#include <core/JSON.h>

namespace WPEFramework {

namespace JsonData {

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

            bool IsValid() const
            {
                return (true);
            }

            CancelParamsInfo(const CancelParamsInfo&) = delete;
            CancelParamsInfo& operator=(const CancelParamsInfo&) = delete;

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

            bool IsValid() const
            {
                return (true);
            }

            GetStorageDetailsParamsInfo(const GetStorageDetailsParamsInfo&) = delete;
            GetStorageDetailsParamsInfo& operator=(const GetStorageDetailsParamsInfo&) = delete;

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

            KeyvalueInfo& operator=(const KeyvalueInfo& _rhs)
            {
                Key = _rhs.Key;
                Value = _rhs.Value;
                return (*this);
            }

            bool IsValid() const
            {
                return (true);
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

            bool IsValid() const
            {
                return (true);
            }

            ClearAuxMetadataParamsData(const ClearAuxMetadataParamsData&) = delete;
            ClearAuxMetadataParamsData& operator=(const ClearAuxMetadataParamsData&) = delete;

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

            bool IsValid() const
            {
                return (true);
            }

            DownloadParamsData(const DownloadParamsData&) = delete;
            DownloadParamsData& operator=(const DownloadParamsData&) = delete;

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

                    InstalledappData& operator=(const InstalledappData& _rhs)
                    {
                        Version = _rhs.Version;
                        AppName = _rhs.AppName;
                        Category = _rhs.Category;
                        Url = _rhs.Url;
                        return (*this);
                    }

                    bool IsValid() const
                    {
                        return (true);
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

                AppData& operator=(const AppData& _rhs)
                {
                    Id = _rhs.Id;
                    Type = _rhs.Type;
                    Installed = _rhs.Installed;
                    return (*this);
                }

                bool IsValid() const
                {
                    return (true);
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
                Core::JSON::ArrayType<AppslistpayloadData::AppData::InstalledappData> Installed;
            }; // class AppData

            AppslistpayloadData()
                : Core::JSON::Container()
            {
                Add(_T("apps"), &Apps);
            }

            bool IsValid() const
            {
                return (true);
            }

            AppslistpayloadData(const AppslistpayloadData&) = delete;
            AppslistpayloadData& operator=(const AppslistpayloadData&) = delete;

        public:
            Core::JSON::ArrayType<AppslistpayloadData::AppData> Apps;
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

            bool IsValid() const
            {
                return (true);
            }

            GetListParamsData(const GetListParamsData&) = delete;
            GetListParamsData& operator=(const GetListParamsData&) = delete;

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

            bool IsValid() const
            {
                return (true);
            }

            LockinfoData(const LockinfoData&) = delete;
            LockinfoData& operator=(const LockinfoData&) = delete;

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

            bool IsValid() const
            {
                return (true);
            }

            MetadatapayloadData(const MetadatapayloadData&) = delete;
            MetadatapayloadData& operator=(const MetadatapayloadData&) = delete;

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

                bool IsValid() const
                {
                    return (true);
                }

                StorageData(const StorageData&) = delete;
                StorageData& operator=(const StorageData&) = delete;

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

            bool IsValid() const
            {
                return (true);
            }

            StoragepayloadData(const StoragepayloadData&) = delete;
            StoragepayloadData& operator=(const StoragepayloadData&) = delete;

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

            bool IsValid() const
            {
                return (true);
            }

            InstallParamsData(const InstallParamsData&) = delete;
            InstallParamsData& operator=(const InstallParamsData&) = delete;

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

            bool IsValid() const
            {
                return (true);
            }

            LockParamsData(const LockParamsData&) = delete;
            LockParamsData& operator=(const LockParamsData&) = delete;

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

            bool IsValid() const
            {
                return (true);
            }

            OperationStatusParamsData(const OperationStatusParamsData&) = delete;
            OperationStatusParamsData& operator=(const OperationStatusParamsData&) = delete;

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

            bool IsValid() const
            {
                return (true);
            }

            ResetParamsData(const ResetParamsData&) = delete;
            ResetParamsData& operator=(const ResetParamsData&) = delete;

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

            bool IsValid() const
            {
                return (true);
            }

            SetAuxMetadataParamsData(const SetAuxMetadataParamsData&) = delete;
            SetAuxMetadataParamsData& operator=(const SetAuxMetadataParamsData&) = delete;

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

            bool IsValid() const
            {
                return (true);
            }

            UninstallParamsData(const UninstallParamsData&) = delete;
            UninstallParamsData& operator=(const UninstallParamsData&) = delete;

        public:
            Core::JSON::String Type; // Application type (mime-type)
            Core::JSON::String Id; // Application ID
            Core::JSON::String Version; // Application version
            Core::JSON::String UninstallType; // Type of the uninstall to perform
        }; // class UninstallParamsData

    } // namespace LISA

} // namespace JsonData

}

