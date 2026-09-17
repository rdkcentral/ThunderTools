// C++ types for Provisioning API.
// Generated automatically from 'Provisioning.json'. DO NOT EDIT.

// Note: This code is inherently not thread safe. If required, proper synchronisation must be added.

#pragma once

#include <core/JSON.h>

namespace Thunder {

namespace JsonData {

    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    namespace Provisioning {

        // Method params/result classes
        //

        class IndexParamsData : public Core::JSON::Container {
        public:
            IndexParamsData()
                : Core::JSON::Container()
            {
                Add(_T("label"), &Label);
                Add(_T("index"), &Index);
            }

            IndexParamsData(const IndexParamsData&) = delete;
            IndexParamsData(IndexParamsData&&) noexcept  = delete;

            IndexParamsData& operator=(const IndexParamsData&) = delete;
            IndexParamsData& operator=(IndexParamsData&&) noexcept  = delete;

            ~IndexParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return ((Label.IsSet() == true) && (Index.IsSet() == true));
            }

        public:
            Core::JSON::String Label; // The label name for which the index should be changed
            Core::JSON::DecUInt32 Index; // Index to be used for the key
        }; // class IndexParamsData

        class ProvisioningchangeParamsData : public Core::JSON::Container {
        public:
            ProvisioningchangeParamsData()
                : Core::JSON::Container()
            {
                Add(_T("status"), &Status);
            }

            ProvisioningchangeParamsData(const ProvisioningchangeParamsData&) = delete;
            ProvisioningchangeParamsData(ProvisioningchangeParamsData&&) noexcept  = delete;

            ProvisioningchangeParamsData& operator=(const ProvisioningchangeParamsData&) = delete;
            ProvisioningchangeParamsData& operator=(ProvisioningchangeParamsData&&) noexcept  = delete;

            ~ProvisioningchangeParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return (Status.IsSet() == true);
            }

        public:
            Core::JSON::DecUInt32 Status; // Provision status
        }; // class ProvisioningchangeParamsData

        class StateData : public Core::JSON::Container {
        public:
            StateData()
                : Core::JSON::Container()
            {
                Add(_T("id"), &Id);
                Add(_T("status"), &Status);
                Add(_T("tokens"), &Tokens);
            }

            StateData(const StateData&) = delete;
            StateData(StateData&&) noexcept  = delete;

            StateData& operator=(const StateData&) = delete;
            StateData& operator=(StateData&&) noexcept  = delete;

            ~StateData() = default;

        public:
            bool IsDataValid() const
            {
                return ((Id.IsSet() == true) && (Status.IsSet() == true) && (Tokens.IsSet() == true));
            }

        public:
            Core::JSON::String Id; // Provision ID value
            Core::JSON::DecUInt32 Status; // Provision status
            Core::JSON::ArrayType<Core::JSON::String> Tokens; // List of provisioned systems
        }; // class StateData

    } // namespace Provisioning

    POP_WARNING()

} // namespace JsonData

}

