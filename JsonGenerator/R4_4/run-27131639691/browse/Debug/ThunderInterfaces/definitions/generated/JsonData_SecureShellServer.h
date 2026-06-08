// C++ types for SecureShell Server API.
// Generated automatically from 'SecureShellServer.json'. DO NOT EDIT.

// Note: This code is inherently not thread safe. If required, proper synchronisation must be added.

#pragma once

#include <core/JSON.h>

namespace WPEFramework {

namespace JsonData {

    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    namespace SecureShellServer {

        // Method params/result classes
        //

        class Close_client_sessionParamsData : public Core::JSON::Container {
        public:
            Close_client_sessionParamsData()
                : Core::JSON::Container()
            {
                Add(_T("clientpid"), &Clientpid);
            }

            Close_client_sessionParamsData(const Close_client_sessionParamsData&) = delete;
            Close_client_sessionParamsData(Close_client_sessionParamsData&&) noexcept  = delete;

            Close_client_sessionParamsData& operator=(const Close_client_sessionParamsData&) = delete;
            Close_client_sessionParamsData& operator=(Close_client_sessionParamsData&&) noexcept  = delete;

            ~Close_client_sessionParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return (Clientpid.IsSet() == true);
            }

        public:
            Core::JSON::String Clientpid; // SSH client process id
        }; // class Close_client_sessionParamsData

        class Get_active_sessions_infoResultDataElem : public Core::JSON::Container {
        public:
            Get_active_sessions_infoResultDataElem()
                : Core::JSON::Container()
            {
                _Init();
            }

            Get_active_sessions_infoResultDataElem(const Get_active_sessions_infoResultDataElem& _other)
                : Core::JSON::Container()
                , Pid(_other.Pid)
                , Ipaddress(_other.Ipaddress)
                , Timestamp(_other.Timestamp)
            {
                _Init();
            }

            Get_active_sessions_infoResultDataElem(Get_active_sessions_infoResultDataElem&& _other) noexcept
                : Core::JSON::Container()
                , Pid(std::move(_other.Pid))
                , Ipaddress(std::move(_other.Ipaddress))
                , Timestamp(std::move(_other.Timestamp))
            {
                _Init();
            }

            Get_active_sessions_infoResultDataElem& operator=(const Get_active_sessions_infoResultDataElem& _rhs)
            {
                Pid = _rhs.Pid;
                Ipaddress = _rhs.Ipaddress;
                Timestamp = _rhs.Timestamp;
                return (*this);
            }

            Get_active_sessions_infoResultDataElem& operator=(Get_active_sessions_infoResultDataElem&& _rhs) noexcept
            {
                Pid = std::move(_rhs.Pid);
                Ipaddress = std::move(_rhs.Ipaddress);
                Timestamp = std::move(_rhs.Timestamp);
                return (*this);
            }

            ~Get_active_sessions_infoResultDataElem() = default;

        public:
            bool IsDataValid() const
            {
                return ((Pid.IsSet() == true) && (Ipaddress.IsSet() == true) && (Timestamp.IsSet() == true));
            }

        private:
            void _Init()
            {
                Add(_T("pid"), &Pid);
                Add(_T("ipaddress"), &Ipaddress);
                Add(_T("timestamp"), &Timestamp);
            }

        public:
            Core::JSON::DecUInt64 Pid; // SSH client process ID
            Core::JSON::String Ipaddress; // SSH client connected from this IP address
            Core::JSON::String Timestamp; // SSH client connected at this timestamp
        }; // class Get_active_sessions_infoResultDataElem

    } // namespace SecureShellServer

    POP_WARNING()

} // namespace JsonData

}

