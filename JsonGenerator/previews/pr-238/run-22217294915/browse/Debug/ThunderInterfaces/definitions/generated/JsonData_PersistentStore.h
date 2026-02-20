// C++ types for PertsistentStore API.
// Generated automatically from 'PersistentStore.json'. DO NOT EDIT.

// Note: This code is inherently not thread safe. If required, proper synchronisation must be added.

#pragma once

#include <core/JSON.h>
#include <core/Enumerate.h>

namespace Thunder {

namespace JsonData {

    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    namespace PersistentStore {

        // Common enums
        //

        // Scope
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

            DeleteKeyParamsInfo(const DeleteKeyParamsInfo&) = delete;
            DeleteKeyParamsInfo(DeleteKeyParamsInfo&&) noexcept  = delete;

            DeleteKeyParamsInfo& operator=(const DeleteKeyParamsInfo&) = delete;
            DeleteKeyParamsInfo& operator=(DeleteKeyParamsInfo&&) noexcept  = delete;

            ~DeleteKeyParamsInfo() = default;

        public:
            bool IsDataValid() const
            {
                return ((Namespace.IsSet() == true) && (Key.IsSet() == true));
            }

        public:
            Core::JSON::String Namespace; // Namespace
            Core::JSON::String Key; // Key
            Core::JSON::EnumType<ScopeType> Scope; // Scope
        }; // class DeleteKeyParamsInfo

        class DeleteKeyResultInfo : public Core::JSON::Container {
        public:
            DeleteKeyResultInfo()
                : Core::JSON::Container()
            {
                Add(_T("success"), &Success);
            }

            DeleteKeyResultInfo(const DeleteKeyResultInfo&) = delete;
            DeleteKeyResultInfo(DeleteKeyResultInfo&&) noexcept  = delete;

            DeleteKeyResultInfo& operator=(const DeleteKeyResultInfo&) = delete;
            DeleteKeyResultInfo& operator=(DeleteKeyResultInfo&&) noexcept  = delete;

            ~DeleteKeyResultInfo() = default;

        public:
            bool IsDataValid() const
            {
                return (Success.IsSet() == true);
            }

        public:
            Core::JSON::Boolean Success; // Legacy parameter (always true)
        }; // class DeleteKeyResultInfo

        class DeleteNamespaceParamsInfo : public Core::JSON::Container {
        public:
            DeleteNamespaceParamsInfo()
                : Core::JSON::Container()
            {
                Add(_T("namespace"), &Namespace);
                Add(_T("scope"), &Scope);
            }

            DeleteNamespaceParamsInfo(const DeleteNamespaceParamsInfo&) = delete;
            DeleteNamespaceParamsInfo(DeleteNamespaceParamsInfo&&) noexcept  = delete;

            DeleteNamespaceParamsInfo& operator=(const DeleteNamespaceParamsInfo&) = delete;
            DeleteNamespaceParamsInfo& operator=(DeleteNamespaceParamsInfo&&) noexcept  = delete;

            ~DeleteNamespaceParamsInfo() = default;

        public:
            bool IsDataValid() const
            {
                return (Namespace.IsSet() == true);
            }

        public:
            Core::JSON::String Namespace; // Namespace
            Core::JSON::EnumType<ScopeType> Scope; // Scope
        }; // class DeleteNamespaceParamsInfo

        class GetNamespacesParamsInfo : public Core::JSON::Container {
        public:
            GetNamespacesParamsInfo()
                : Core::JSON::Container()
            {
                Add(_T("scope"), &Scope);
            }

            GetNamespacesParamsInfo(const GetNamespacesParamsInfo&) = delete;
            GetNamespacesParamsInfo(GetNamespacesParamsInfo&&) noexcept  = delete;

            GetNamespacesParamsInfo& operator=(const GetNamespacesParamsInfo&) = delete;
            GetNamespacesParamsInfo& operator=(GetNamespacesParamsInfo&&) noexcept  = delete;

            ~GetNamespacesParamsInfo() = default;

        public:
            bool IsDataValid() const
            {
                return (true);
            }

        public:
            Core::JSON::EnumType<ScopeType> Scope; // Scope
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

            GetKeysResultData(const GetKeysResultData&) = delete;
            GetKeysResultData(GetKeysResultData&&) noexcept  = delete;

            GetKeysResultData& operator=(const GetKeysResultData&) = delete;
            GetKeysResultData& operator=(GetKeysResultData&&) noexcept  = delete;

            ~GetKeysResultData() = default;

        public:
            bool IsDataValid() const
            {
                return ((Keys.IsSet() == true) && (Success.IsSet() == true));
            }

        public:
            Core::JSON::ArrayType<Core::JSON::String> Keys; // Returns the keys that are stored in the specified namespace
            Core::JSON::Boolean Success; // Legacy parameter (always true)
        }; // class GetKeysResultData

        class GetNamespaceStorageLimitResultData : public Core::JSON::Container {
        public:
            GetNamespaceStorageLimitResultData()
                : Core::JSON::Container()
            {
                Add(_T("storageLimit"), &StorageLimit);
            }

            GetNamespaceStorageLimitResultData(const GetNamespaceStorageLimitResultData&) = delete;
            GetNamespaceStorageLimitResultData(GetNamespaceStorageLimitResultData&&) noexcept  = delete;

            GetNamespaceStorageLimitResultData& operator=(const GetNamespaceStorageLimitResultData&) = delete;
            GetNamespaceStorageLimitResultData& operator=(GetNamespaceStorageLimitResultData&&) noexcept  = delete;

            ~GetNamespaceStorageLimitResultData() = default;

        public:
            bool IsDataValid() const
            {
                return (StorageLimit.IsSet() == true);
            }

        public:
            Core::JSON::DecUInt32 StorageLimit; // Size in bytes
        }; // class GetNamespaceStorageLimitResultData

        class GetNamespacesResultData : public Core::JSON::Container {
        public:
            GetNamespacesResultData()
                : Core::JSON::Container()
            {
                Add(_T("namespaces"), &Namespaces);
                Add(_T("success"), &Success);
            }

            GetNamespacesResultData(const GetNamespacesResultData&) = delete;
            GetNamespacesResultData(GetNamespacesResultData&&) noexcept  = delete;

            GetNamespacesResultData& operator=(const GetNamespacesResultData&) = delete;
            GetNamespacesResultData& operator=(GetNamespacesResultData&&) noexcept  = delete;

            ~GetNamespacesResultData() = default;

        public:
            bool IsDataValid() const
            {
                return ((Namespaces.IsSet() == true) && (Success.IsSet() == true));
            }

        public:
            Core::JSON::ArrayType<Core::JSON::String> Namespaces; // Returns the namespaces
            Core::JSON::Boolean Success; // Legacy parameter (always true)
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

                StorageListDataElem(StorageListDataElem&& _other) noexcept
                    : Core::JSON::Container()
                    , Namespace(std::move(_other.Namespace))
                    , Size(std::move(_other.Size))
                {
                    _Init();
                }

                StorageListDataElem& operator=(const StorageListDataElem& _rhs)
                {
                    Namespace = _rhs.Namespace;
                    Size = _rhs.Size;
                    return (*this);
                }

                StorageListDataElem& operator=(StorageListDataElem&& _rhs) noexcept
                {
                    Namespace = std::move(_rhs.Namespace);
                    Size = std::move(_rhs.Size);
                    return (*this);
                }

                ~StorageListDataElem() = default;

            public:
                bool IsDataValid() const
                {
                    return ((Namespace.IsSet() == true) && (Size.IsSet() == true));
                }

            private:
                void _Init()
                {
                    Add(_T("namespace"), &Namespace);
                    Add(_T("size"), &Size);
                }

            public:
                Core::JSON::String Namespace; // Namespace
                Core::JSON::DecUInt32 Size; // Size in bytes
            }; // class StorageListDataElem

            GetStorageSizesResultData()
                : Core::JSON::Container()
            {
                Add(_T("storageList"), &StorageList);
            }

            GetStorageSizesResultData(const GetStorageSizesResultData&) = delete;
            GetStorageSizesResultData(GetStorageSizesResultData&&) noexcept  = delete;

            GetStorageSizesResultData& operator=(const GetStorageSizesResultData&) = delete;
            GetStorageSizesResultData& operator=(GetStorageSizesResultData&&) noexcept  = delete;

            ~GetStorageSizesResultData() = default;

        public:
            bool IsDataValid() const
            {
                return (StorageList.IsSet() == true);
            }

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

            GetValueResultData(const GetValueResultData&) = delete;
            GetValueResultData(GetValueResultData&&) noexcept  = delete;

            GetValueResultData& operator=(const GetValueResultData&) = delete;
            GetValueResultData& operator=(GetValueResultData&&) noexcept  = delete;

            ~GetValueResultData() = default;

        public:
            bool IsDataValid() const
            {
                return ((Value.IsSet() == true) && (Success.IsSet() == true));
            }

        public:
            Core::JSON::String Value; // Value
            Core::JSON::Boolean Success; // Legacy parameter (always true)
            Core::JSON::DecUInt32 Ttl; // Time in seconds
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

            OnValueChangedParamsData(const OnValueChangedParamsData&) = delete;
            OnValueChangedParamsData(OnValueChangedParamsData&&) noexcept  = delete;

            OnValueChangedParamsData& operator=(const OnValueChangedParamsData&) = delete;
            OnValueChangedParamsData& operator=(OnValueChangedParamsData&&) noexcept  = delete;

            ~OnValueChangedParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return ((Namespace.IsSet() == true) && (Key.IsSet() == true) && (Value.IsSet() == true) && (Scope.IsSet() == true));
            }

        public:
            Core::JSON::String Namespace; // Namespace
            Core::JSON::String Key; // Key
            Core::JSON::String Value; // Value
            Core::JSON::EnumType<ScopeType> Scope; // Scope
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

            SetNamespaceStorageLimitParamsData(const SetNamespaceStorageLimitParamsData&) = delete;
            SetNamespaceStorageLimitParamsData(SetNamespaceStorageLimitParamsData&&) noexcept  = delete;

            SetNamespaceStorageLimitParamsData& operator=(const SetNamespaceStorageLimitParamsData&) = delete;
            SetNamespaceStorageLimitParamsData& operator=(SetNamespaceStorageLimitParamsData&&) noexcept  = delete;

            ~SetNamespaceStorageLimitParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return ((Namespace.IsSet() == true) && (StorageLimit.IsSet() == true));
            }

        public:
            Core::JSON::String Namespace; // Namespace
            Core::JSON::DecUInt32 StorageLimit; // Size in bytes
            Core::JSON::EnumType<ScopeType> Scope; // Scope
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

            SetValueParamsData(const SetValueParamsData&) = delete;
            SetValueParamsData(SetValueParamsData&&) noexcept  = delete;

            SetValueParamsData& operator=(const SetValueParamsData&) = delete;
            SetValueParamsData& operator=(SetValueParamsData&&) noexcept  = delete;

            ~SetValueParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return ((Namespace.IsSet() == true) && (Key.IsSet() == true) && (Value.IsSet() == true));
            }

        public:
            Core::JSON::String Namespace; // Namespace
            Core::JSON::String Key; // Key
            Core::JSON::String Value; // Value
            Core::JSON::EnumType<ScopeType> Scope; // Scope
            Core::JSON::DecUInt32 Ttl; // Time in seconds
        }; // class SetValueParamsData

    } // namespace PersistentStore

    POP_WARNING()

} // namespace JsonData

// Enum conversion handlers
ENUM_CONVERSION_HANDLER(JsonData::PersistentStore::ScopeType)

}

