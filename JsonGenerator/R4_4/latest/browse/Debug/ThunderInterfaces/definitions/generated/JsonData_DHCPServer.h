// C++ classes for DHCP Server API JSON-RPC API.
// Generated automatically from 'DHCPServer.json'. DO NOT EDIT.

// Note: This code is inherently not thread safe. If required, proper synchronisation must be added.

#pragma once

#include <core/JSON.h>

namespace WPEFramework {

namespace JsonData {

    namespace DHCPServer {

        // Common classes
        //

        class ActivateParamsInfo : public Core::JSON::Container {
        public:
            ActivateParamsInfo()
                : Core::JSON::Container()
            {
                Add(_T("interface"), &Interface);
            }

            bool IsValid() const
            {
                return (true);
            }

            ActivateParamsInfo(const ActivateParamsInfo&) = delete;
            ActivateParamsInfo& operator=(const ActivateParamsInfo&) = delete;

        public:
            Core::JSON::String Interface; // Network interface name
        }; // class ActivateParamsInfo

        // Method params/result classes
        //

        class ServerData : public Core::JSON::Container {
        public:
            class LeaseData : public Core::JSON::Container {
            public:
                LeaseData()
                    : Core::JSON::Container()
                {
                    _Init();
                }

                LeaseData(const LeaseData& _other)
                    : Core::JSON::Container()
                    , Name(_other.Name)
                    , Ip(_other.Ip)
                    , Expires(_other.Expires)
                {
                    _Init();
                }

                LeaseData& operator=(const LeaseData& _rhs)
                {
                    Name = _rhs.Name;
                    Ip = _rhs.Ip;
                    Expires = _rhs.Expires;
                    return (*this);
                }

                bool IsValid() const
                {
                    return (true);
                }

            private:
                void _Init()
                {
                    Add(_T("name"), &Name);
                    Add(_T("ip"), &Ip);
                    Add(_T("expires"), &Expires);
                }

            public:
                Core::JSON::String Name; // Client identifier (or client hardware address if identifier is absent)
                Core::JSON::String Ip; // Client IP address
                Core::JSON::String Expires; // Client IP expiration time (in ISO8601 format, empty: never expires)
            }; // class LeaseData

            ServerData()
                : Core::JSON::Container()
            {
                _Init();
            }

            ServerData(const ServerData& _other)
                : Core::JSON::Container()
                , Interface(_other.Interface)
                , Active(_other.Active)
                , Begin(_other.Begin)
                , End(_other.End)
                , Router(_other.Router)
                , Leases(_other.Leases)
            {
                _Init();
            }

            ServerData& operator=(const ServerData& _rhs)
            {
                Interface = _rhs.Interface;
                Active = _rhs.Active;
                Begin = _rhs.Begin;
                End = _rhs.End;
                Router = _rhs.Router;
                Leases = _rhs.Leases;
                return (*this);
            }

            bool IsValid() const
            {
                return (true);
            }

        private:
            void _Init()
            {
                Add(_T("interface"), &Interface);
                Add(_T("active"), &Active);
                Add(_T("begin"), &Begin);
                Add(_T("end"), &End);
                Add(_T("router"), &Router);
                Add(_T("leases"), &Leases);
            }

        public:
            Core::JSON::String Interface; // Network interface name
            Core::JSON::Boolean Active; // Denotes if server is currently active
            Core::JSON::String Begin; // IP address pool start
            Core::JSON::String End; // IP address pool end
            Core::JSON::String Router; // Router IP address
            Core::JSON::ArrayType<ServerData::LeaseData> Leases; // List of IP address leases
        }; // class ServerData

    } // namespace DHCPServer

} // namespace JsonData

}

