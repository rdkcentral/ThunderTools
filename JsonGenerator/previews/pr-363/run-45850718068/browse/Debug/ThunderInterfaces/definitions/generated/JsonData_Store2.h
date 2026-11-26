// C++ types for Store2 API.
// Generated automatically from 'IStore2.h'. DO NOT EDIT.

// Note: This code is inherently not thread safe. If required, proper synchronisation must be added.

#pragma once

#include <core/JSON.h>
#include <interfaces/IStore2.h>

namespace Thunder {

namespace JsonData {

    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    namespace Store2 {

        // Common classes
        //

        class GetValueParamsInfo : public Core::JSON::Container {
        public:
            GetValueParamsInfo()
                : Core::JSON::Container()
            {
                Add(_T("scope"), &Scope);
                Add(_T("namespace"), &Ns);
                Add(_T("key"), &Key);
            }

            GetValueParamsInfo(const GetValueParamsInfo&) = delete;
            GetValueParamsInfo(GetValueParamsInfo&&) noexcept  = delete;

            GetValueParamsInfo& operator=(const GetValueParamsInfo&) = delete;
            GetValueParamsInfo& operator=(GetValueParamsInfo&&) noexcept  = delete;

            ~GetValueParamsInfo() = default;

        public:
            bool IsDataValid() const
            {
                return ((Scope.IsSet() == true) && (Ns.IsSet() == true) && (Key.IsSet() == true));
            }

        public:
            Core::JSON::EnumType<Exchange::IStore2::ScopeType> Scope;
            Core::JSON::String Ns;
            Core::JSON::String Key;
        }; // class GetValueParamsInfo

        // Method params/result classes
        //

        class DeleteNamespaceParamsData : public Core::JSON::Container {
        public:
            DeleteNamespaceParamsData()
                : Core::JSON::Container()
            {
                Add(_T("scope"), &Scope);
                Add(_T("namespace"), &Ns);
            }

            DeleteNamespaceParamsData(const DeleteNamespaceParamsData&) = delete;
            DeleteNamespaceParamsData(DeleteNamespaceParamsData&&) noexcept  = delete;

            DeleteNamespaceParamsData& operator=(const DeleteNamespaceParamsData&) = delete;
            DeleteNamespaceParamsData& operator=(DeleteNamespaceParamsData&&) noexcept  = delete;

            ~DeleteNamespaceParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return ((Scope.IsSet() == true) && (Ns.IsSet() == true));
            }

        public:
            Core::JSON::EnumType<Exchange::IStore2::ScopeType> Scope;
            Core::JSON::String Ns;
        }; // class DeleteNamespaceParamsData

        class GetValueResultData : public Core::JSON::Container {
        public:
            GetValueResultData()
                : Core::JSON::Container()
            {
                Add(_T("value"), &Value);
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
                return ((Value.IsSet() == true) && (Ttl.IsSet() == true));
            }

        public:
            Core::JSON::String Value;
            Core::JSON::DecUInt32 Ttl;
        }; // class GetValueResultData

        class SetValueParamsData : public Core::JSON::Container {
        public:
            SetValueParamsData()
                : Core::JSON::Container()
            {
                Add(_T("scope"), &Scope);
                Add(_T("namespace"), &Ns);
                Add(_T("key"), &Key);
                Add(_T("value"), &Value);
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
                return ((Scope.IsSet() == true) && (Ns.IsSet() == true) && (Key.IsSet() == true) && (Value.IsSet() == true) && (Ttl.IsSet() == true));
            }

        public:
            Core::JSON::EnumType<Exchange::IStore2::ScopeType> Scope;
            Core::JSON::String Ns;
            Core::JSON::String Key;
            Core::JSON::String Value;
            Core::JSON::DecUInt32 Ttl;
        }; // class SetValueParamsData

        class ValueChangedParamsData : public Core::JSON::Container {
        public:
            ValueChangedParamsData()
                : Core::JSON::Container()
            {
                Add(_T("scope"), &Scope);
                Add(_T("namespace"), &Ns);
                Add(_T("key"), &Key);
                Add(_T("value"), &Value);
            }

            ValueChangedParamsData(const ValueChangedParamsData&) = delete;
            ValueChangedParamsData(ValueChangedParamsData&&) noexcept  = delete;

            ValueChangedParamsData& operator=(const ValueChangedParamsData&) = delete;
            ValueChangedParamsData& operator=(ValueChangedParamsData&&) noexcept  = delete;

            ~ValueChangedParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return ((Scope.IsSet() == true) && (Ns.IsSet() == true) && (Key.IsSet() == true) && (Value.IsSet() == true));
            }

        public:
            Core::JSON::EnumType<Exchange::IStore2::ScopeType> Scope;
            Core::JSON::String Ns;
            Core::JSON::String Key;
            Core::JSON::String Value;
        }; // class ValueChangedParamsData

    } // namespace Store2

    POP_WARNING()

} // namespace JsonData

// Enum conversion handlers
ENUM_CONVERSION_HANDLER(Exchange::IStore2::ScopeType)

}

