// C++ classes for Provisioning API JSON-RPC API.
// Generated automatically from 'Provisioning.json'. DO NOT EDIT.

// Note: This code is inherently not thread safe. If required, proper synchronisation must be added.

#pragma once

#include <core/JSON.h>

namespace WPEFramework {

namespace JsonData {

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

            bool IsValid() const
            {
                return (true);
            }

            IndexParamsData(const IndexParamsData&) = delete;
            IndexParamsData& operator=(const IndexParamsData&) = delete;

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

            bool IsValid() const
            {
                return (true);
            }

            ProvisioningchangeParamsData(const ProvisioningchangeParamsData&) = delete;
            ProvisioningchangeParamsData& operator=(const ProvisioningchangeParamsData&) = delete;

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

            bool IsValid() const
            {
                return (true);
            }

            StateData(const StateData&) = delete;
            StateData& operator=(const StateData&) = delete;

        public:
            Core::JSON::String Id; // Provision ID value
            Core::JSON::DecUInt32 Status; // Provision status
            Core::JSON::ArrayType<Core::JSON::String> Tokens; // List of provisioned systems
        }; // class StateData

    } // namespace Provisioning

} // namespace JsonData

}

