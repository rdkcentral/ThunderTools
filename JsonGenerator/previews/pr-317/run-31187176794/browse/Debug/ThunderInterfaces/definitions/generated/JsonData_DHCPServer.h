// C++ types for DHCP Server API.
// Generated automatically from 'DHCPServer.json'. DO NOT EDIT.

// Note: This code is inherently not thread safe. If required, proper synchronisation must be added.

#pragma once

#include <core/JSON.h>

namespace Thunder {

namespace JsonData {

    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

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

            ActivateParamsInfo(const ActivateParamsInfo&) = delete;
            ActivateParamsInfo(ActivateParamsInfo&&) noexcept  = delete;

            ActivateParamsInfo& operator=(const ActivateParamsInfo&) = delete;
            ActivateParamsInfo& operator=(ActivateParamsInfo&&) noexcept  = delete;

            ~ActivateParamsInfo() = default;

        public:
            bool IsDataValid() const
            {
                return (Interface.IsSet() == true);
            }

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

                LeaseData(LeaseData&& _other) noexcept
                    : Core::JSON::Container()
                    , Name(std::move(_other.Name))
                    , Ip(std::move(_other.Ip))
                    , Expires(std::move(_other.Expires))
                {
                    _Init();
                }

                LeaseData& operator=(const LeaseData& _rhs)
                {
                    Name = _rhs.Name;
                    Ip = _rhs.Ip;
                    if (_rhs.Expires.Value().empty() == false) {
                        Expires = _rhs.Expires;
                    }
                    return (*this);
                }

                LeaseData& operator=(LeaseData&& _rhs) noexcept
                {
                    Name = std::move(_rhs.Name);
                    Ip = std::move(_rhs.Ip);
                    Expires = std::move(_rhs.Expires);
                    return (*this);
                }

                ~LeaseData() = default;

            public:
                bool IsDataValid() const
                {
                    return ((Name.IsSet() == true) && (Ip.IsSet() == true));
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

            ServerData(ServerData&& _other) noexcept
                : Core::JSON::Container()
                , Interface(std::move(_other.Interface))
                , Active(std::move(_other.Active))
                , Begin(std::move(_other.Begin))
                , End(std::move(_other.End))
                , Router(std::move(_other.Router))
                , Leases(std::move(_other.Leases))
            {
                _Init();
            }

            ServerData& operator=(const ServerData& _rhs)
            {
                Interface = _rhs.Interface;
                Active = _rhs.Active;
                if (_rhs.Begin.Value().empty() == false) {
                    Begin = _rhs.Begin;
                }
                if (_rhs.End.Value().empty() == false) {
                    End = _rhs.End;
                }
                if (_rhs.Router.Value().empty() == false) {
                    Router = _rhs.Router;
                }
                Leases = _rhs.Leases;
                return (*this);
            }

            ServerData& operator=(ServerData&& _rhs) noexcept
            {
                Interface = std::move(_rhs.Interface);
                Active = std::move(_rhs.Active);
                Begin = std::move(_rhs.Begin);
                End = std::move(_rhs.End);
                Router = std::move(_rhs.Router);
                Leases = std::move(_rhs.Leases);
                return (*this);
            }

            ~ServerData() = default;

        public:
            bool IsDataValid() const
            {
                return ((Interface.IsSet() == true) && (Active.IsSet() == true));
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

    POP_WARNING()

} // namespace JsonData

}

