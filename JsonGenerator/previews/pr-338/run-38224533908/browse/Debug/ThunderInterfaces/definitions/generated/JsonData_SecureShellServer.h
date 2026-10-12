// C++ types for SecureShell Server API.
// Generated automatically from 'SecureShellServer.json'. DO NOT EDIT.

// Note: This code is inherently not thread safe. If required, proper synchronisation must be added.

#pragma once

#include <core/JSON.h>

namespace Thunder {

namespace JsonData {

    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    namespace SecureShellServer {

        // Method params/result classes
        //

        class CloseclientsessionParamsData : public Core::JSON::Container {
        public:
            CloseclientsessionParamsData()
                : Core::JSON::Container()
            {
                Add(_T("clientpid"), &Clientpid);
            }

            CloseclientsessionParamsData(const CloseclientsessionParamsData&) = delete;
            CloseclientsessionParamsData(CloseclientsessionParamsData&&) noexcept  = delete;

            CloseclientsessionParamsData& operator=(const CloseclientsessionParamsData&) = delete;
            CloseclientsessionParamsData& operator=(CloseclientsessionParamsData&&) noexcept  = delete;

            ~CloseclientsessionParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return (Clientpid.IsSet() == true);
            }

        public:
            Core::JSON::String Clientpid; // SSH client process id
        }; // class CloseclientsessionParamsData

        class GetactivesessionsinfoResultDataElem : public Core::JSON::Container {
        public:
            GetactivesessionsinfoResultDataElem()
                : Core::JSON::Container()
            {
                _Init();
            }

            GetactivesessionsinfoResultDataElem(const GetactivesessionsinfoResultDataElem& _other)
                : Core::JSON::Container()
                , Pid(_other.Pid)
                , Ipaddress(_other.Ipaddress)
                , Timestamp(_other.Timestamp)
            {
                _Init();
            }

            GetactivesessionsinfoResultDataElem(GetactivesessionsinfoResultDataElem&& _other) noexcept
                : Core::JSON::Container()
                , Pid(std::move(_other.Pid))
                , Ipaddress(std::move(_other.Ipaddress))
                , Timestamp(std::move(_other.Timestamp))
            {
                _Init();
            }

            GetactivesessionsinfoResultDataElem& operator=(const GetactivesessionsinfoResultDataElem& _rhs)
            {
                Pid = _rhs.Pid;
                Ipaddress = _rhs.Ipaddress;
                Timestamp = _rhs.Timestamp;
                return (*this);
            }

            GetactivesessionsinfoResultDataElem& operator=(GetactivesessionsinfoResultDataElem&& _rhs) noexcept
            {
                Pid = std::move(_rhs.Pid);
                Ipaddress = std::move(_rhs.Ipaddress);
                Timestamp = std::move(_rhs.Timestamp);
                return (*this);
            }

            ~GetactivesessionsinfoResultDataElem() = default;

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
        }; // class GetactivesessionsinfoResultDataElem

    } // namespace SecureShellServer

    POP_WARNING()

} // namespace JsonData

}

