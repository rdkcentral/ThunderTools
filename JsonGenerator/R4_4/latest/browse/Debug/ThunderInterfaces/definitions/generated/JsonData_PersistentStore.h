// C++ classes for PertsistentStore API JSON-RPC API.
// Generated automatically from 'PersistentStore.json'. DO NOT EDIT.

// Note: This code is inherently not thread safe. If required, proper synchronisation must be added.

#pragma once

#include <core/JSON.h>
#include <core/Enumerate.h>

namespace WPEFramework {

namespace JsonData {

    namespace PersistentStore {

        // Common enums
        //

        // Deletes a key from the specified namespace
        enum class ScopeType : uint8_t {
            DEVICE,
            ACCOUNT
        };

        // Common classes
        //

        class DeleteKeyParamsInfo : public Core::JSON::Container {
        public:
            DeleteKeyParamsInfo()
                : Core::JSON::Container()
            {
                Add(_T("namespace"), &Namespace);
                Add(_T("key"), &Key);
                Add(_T("scope"), &Scope);
            }

            bool IsValid() const
            {
                return (true);
            }

            DeleteKeyParamsInfo(const DeleteKeyParamsInfo&) = delete;
            DeleteKeyParamsInfo& operator=(const DeleteKeyParamsInfo&) = delete;

        public:
            Core::JSON::String Namespace; // Deletes a key from the specified namespace
            Core::JSON::String Key; // Deletes a key from the specified namespace
            Core::JSON::EnumType<ScopeType> Scope; // Deletes a key from the specified namespace
        }; // class DeleteKeyParamsInfo

        class DeleteKeyResultInfo : public Core::JSON::Container {
        public:
            DeleteKeyResultInfo()
                : Core::JSON::Container()
            {
                Add(_T("success"), &Success);
            }

            bool IsValid() const
            {
                return (true);
            }

            DeleteKeyResultInfo(const DeleteKeyResultInfo&) = delete;
            DeleteKeyResultInfo& operator=(const DeleteKeyResultInfo&) = delete;

        public:
            Core::JSON::Boolean Success; // Deletes a key from the specified namespace
        }; // class DeleteKeyResultInfo

        class DeleteNamespaceParamsInfo : public Core::JSON::Container {
        public:
            DeleteNamespaceParamsInfo()
                : Core::JSON::Container()
            {
                Add(_T("namespace"), &Namespace);
                Add(_T("scope"), &Scope);
            }

            bool IsValid() const
            {
                return (true);
            }

            DeleteNamespaceParamsInfo(const DeleteNamespaceParamsInfo&) = delete;
            DeleteNamespaceParamsInfo& operator=(const DeleteNamespaceParamsInfo&) = delete;

        public:
            Core::JSON::String Namespace; // Deletes the specified namespace
            Core::JSON::EnumType<ScopeType> Scope; // Deletes the specified namespace
        }; // class DeleteNamespaceParamsInfo

        class GetNamespacesParamsInfo : public Core::JSON::Container {
        public:
            GetNamespacesParamsInfo()
                : Core::JSON::Container()
            {
                Add(_T("scope"), &Scope);
            }

            bool IsValid() const
            {
                return (true);
            }

            GetNamespacesParamsInfo(const GetNamespacesParamsInfo&) = delete;
            GetNamespacesParamsInfo& operator=(const GetNamespacesParamsInfo&) = delete;

        public:
            Core::JSON::EnumType<ScopeType> Scope; // Returns the namespaces
        }; // class GetNamespacesParamsInfo

        // Method params/result classes
        //

        class GetKeysResultData : public Core::JSON::Container {
        public:
            GetKeysResultData()
                : Core::JSON::Container()
            {
                Add(_T("keys"), &Keys);
                Add(_T("success"), &Success);
            }

            bool IsValid() const
            {
                return (true);
            }

            GetKeysResultData(const GetKeysResultData&) = delete;
            GetKeysResultData& operator=(const GetKeysResultData&) = delete;

        public:
            Core::JSON::ArrayType<Core::JSON::String> Keys; // Returns the keys that are stored in the specified namespace
            Core::JSON::Boolean Success; // Returns the keys that are stored in the specified namespace
        }; // class GetKeysResultData

        class GetNamespaceStorageLimitResultData : public Core::JSON::Container {
        public:
            GetNamespaceStorageLimitResultData()
                : Core::JSON::Container()
            {
                Add(_T("storageLimit"), &StorageLimit);
            }

            bool IsValid() const
            {
                return (true);
            }

            GetNamespaceStorageLimitResultData(const GetNamespaceStorageLimitResultData&) = delete;
            GetNamespaceStorageLimitResultData& operator=(const GetNamespaceStorageLimitResultData&) = delete;

        public:
            Core::JSON::DecUInt32 StorageLimit; // Returns the storage limit for a given namespace
        }; // class GetNamespaceStorageLimitResultData

        class GetNamespacesResultData : public Core::JSON::Container {
        public:
            GetNamespacesResultData()
                : Core::JSON::Container()
            {
                Add(_T("namespaces"), &Namespaces);
                Add(_T("success"), &Success);
            }

            bool IsValid() const
            {
                return (true);
            }

            GetNamespacesResultData(const GetNamespacesResultData&) = delete;
            GetNamespacesResultData& operator=(const GetNamespacesResultData&) = delete;

        public:
            Core::JSON::ArrayType<Core::JSON::String> Namespaces; // Returns the namespaces
            Core::JSON::Boolean Success; // Returns the namespaces
        }; // class GetNamespacesResultData

        class GetStorageSizesResultData : public Core::JSON::Container {
        public:
            class StorageListDataElem : public Core::JSON::Container {
            public:
                StorageListDataElem()
                    : Core::JSON::Container()
                {
                    _Init();
                }

                StorageListDataElem(const StorageListDataElem& _other)
                    : Core::JSON::Container()
                    , Namespace(_other.Namespace)
                    , Size(_other.Size)
                {
                    _Init();
                }

                StorageListDataElem& operator=(const StorageListDataElem& _rhs)
                {
                    Namespace = _rhs.Namespace;
                    Size = _rhs.Size;
                    return (*this);
                }

                bool IsValid() const
                {
                    return (true);
                }

            private:
                void _Init()
                {
                    Add(_T("namespace"), &Namespace);
                    Add(_T("size"), &Size);
                }

            public:
                Core::JSON::String Namespace;
                Core::JSON::DecUInt32 Size;
            }; // class StorageListDataElem

            GetStorageSizesResultData()
                : Core::JSON::Container()
            {
                Add(_T("storageList"), &StorageList);
            }

            bool IsValid() const
            {
                return (true);
            }

            GetStorageSizesResultData(const GetStorageSizesResultData&) = delete;
            GetStorageSizesResultData& operator=(const GetStorageSizesResultData&) = delete;

        public:
            Core::JSON::ArrayType<GetStorageSizesResultData::StorageListDataElem> StorageList; // Returns the size occupied by each namespace
        }; // class GetStorageSizesResultData

        class GetValueResultData : public Core::JSON::Container {
        public:
            GetValueResultData()
                : Core::JSON::Container()
            {
                Add(_T("value"), &Value);
                Add(_T("success"), &Success);
                Add(_T("ttl"), &Ttl);
            }

            bool IsValid() const
            {
                return (true);
            }

            GetValueResultData(const GetValueResultData&) = delete;
            GetValueResultData& operator=(const GetValueResultData&) = delete;

        public:
            Core::JSON::String Value; // Returns the value of a key from the specified namespace
            Core::JSON::Boolean Success; // Returns the value of a key from the specified namespace
            Core::JSON::DecUInt32 Ttl; // Returns the value of a key from the specified namespace
        }; // class GetValueResultData

        class OnValueChangedParamsData : public Core::JSON::Container {
        public:
            OnValueChangedParamsData()
                : Core::JSON::Container()
            {
                Add(_T("namespace"), &Namespace);
                Add(_T("key"), &Key);
                Add(_T("value"), &Value);
                Add(_T("scope"), &Scope);
            }

            bool IsValid() const
            {
                return (true);
            }

            OnValueChangedParamsData(const OnValueChangedParamsData&) = delete;
            OnValueChangedParamsData& operator=(const OnValueChangedParamsData&) = delete;

        public:
            Core::JSON::String Namespace; // Triggered whenever any of the values stored are changed using setValue
            Core::JSON::String Key; // Triggered whenever any of the values stored are changed using setValue
            Core::JSON::String Value; // Triggered whenever any of the values stored are changed using setValue
            Core::JSON::EnumType<ScopeType> Scope; // Triggered whenever any of the values stored are changed using setValue
        }; // class OnValueChangedParamsData

        class SetNamespaceStorageLimitParamsData : public Core::JSON::Container {
        public:
            SetNamespaceStorageLimitParamsData()
                : Core::JSON::Container()
            {
                Add(_T("namespace"), &Namespace);
                Add(_T("storageLimit"), &StorageLimit);
                Add(_T("scope"), &Scope);
            }

            bool IsValid() const
            {
                return (true);
            }

            SetNamespaceStorageLimitParamsData(const SetNamespaceStorageLimitParamsData&) = delete;
            SetNamespaceStorageLimitParamsData& operator=(const SetNamespaceStorageLimitParamsData&) = delete;

        public:
            Core::JSON::String Namespace; // Sets the storage limit for a given namespace
            Core::JSON::DecUInt32 StorageLimit; // Sets the storage limit for a given namespace
            Core::JSON::EnumType<ScopeType> Scope; // Sets the storage limit for a given namespace
        }; // class SetNamespaceStorageLimitParamsData

        class SetValueParamsData : public Core::JSON::Container {
        public:
            SetValueParamsData()
                : Core::JSON::Container()
            {
                Add(_T("namespace"), &Namespace);
                Add(_T("key"), &Key);
                Add(_T("value"), &Value);
                Add(_T("scope"), &Scope);
                Add(_T("ttl"), &Ttl);
            }

            bool IsValid() const
            {
                return (true);
            }

            SetValueParamsData(const SetValueParamsData&) = delete;
            SetValueParamsData& operator=(const SetValueParamsData&) = delete;

        public:
            Core::JSON::String Namespace; // Sets the value of a key in the the specified namespace
            Core::JSON::String Key; // Sets the value of a key in the the specified namespace
            Core::JSON::String Value; // Sets the value of a key in the the specified namespace
            Core::JSON::EnumType<ScopeType> Scope; // Sets the value of a key in the the specified namespace
            Core::JSON::DecUInt32 Ttl; // Sets the value of a key in the the specified namespace
        }; // class SetValueParamsData

    } // namespace PersistentStore

} // namespace JsonData

// Enum conversion handlers
ENUM_CONVERSION_HANDLER(JsonData::PersistentStore::ScopeType)

}

