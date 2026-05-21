// C++ classes for Process Containers JSON-RPC API.
// Generated automatically from 'Containers.json'. DO NOT EDIT.

// Note: This code is inherently not thread safe. If required, proper synchronisation must be added.

#pragma once

#include <core/JSON.h>

namespace WPEFramework {

namespace JsonData {

    namespace Containers {

        // Method params/result classes
        //

        class CpuData : public Core::JSON::Container {
        public:
            CpuData()
                : Core::JSON::Container()
            {
                Add(_T("total"), &Total);
                Add(_T("cores"), &Cores);
            }

            bool IsValid() const
            {
                return (true);
            }

            CpuData(const CpuData&) = delete;
            CpuData& operator=(const CpuData&) = delete;

        public:
            Core::JSON::DecUInt64 Total; // CPU-time spent on container, in nanoseconds
            Core::JSON::ArrayType<Core::JSON::DecUInt64> Cores; // Time spent on each cpu core, in nanoseconds
        }; // class CpuData

        class MemoryData : public Core::JSON::Container {
        public:
            MemoryData()
                : Core::JSON::Container()
            {
                Add(_T("allocated"), &Allocated);
                Add(_T("resident"), &Resident);
                Add(_T("shared"), &Shared);
            }

            bool IsValid() const
            {
                return (true);
            }

            MemoryData(const MemoryData&) = delete;
            MemoryData& operator=(const MemoryData&) = delete;

        public:
            Core::JSON::DecUInt64 Allocated; // Memory allocated by container
            Core::JSON::DecUInt64 Resident; // Resident memory of the container
            Core::JSON::DecUInt64 Shared; // Shared memory in the container
        }; // class MemoryData

        class NetworksResultDataElem : public Core::JSON::Container {
        public:
            NetworksResultDataElem()
                : Core::JSON::Container()
            {
                _Init();
            }

            NetworksResultDataElem(const NetworksResultDataElem& _other)
                : Core::JSON::Container()
                , Interface(_other.Interface)
                , Ips(_other.Ips)
            {
                _Init();
            }

            NetworksResultDataElem& operator=(const NetworksResultDataElem& _rhs)
            {
                Interface = _rhs.Interface;
                Ips = _rhs.Ips;
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
                Add(_T("ips"), &Ips);
            }

        public:
            Core::JSON::String Interface; // Interface name
            Core::JSON::ArrayType<Core::JSON::String> Ips; // List of ip addresses
        }; // class NetworksResultDataElem

        class StartParamsData : public Core::JSON::Container {
        public:
            StartParamsData()
                : Core::JSON::Container()
            {
                Add(_T("name"), &Name);
                Add(_T("command"), &Command);
                Add(_T("parameters"), &Parameters);
            }

            bool IsValid() const
            {
                return (true);
            }

            StartParamsData(const StartParamsData&) = delete;
            StartParamsData& operator=(const StartParamsData&) = delete;

        public:
            Core::JSON::String Name; // Name of container
            Core::JSON::String Command; // Command that will be started in the container
            Core::JSON::ArrayType<Core::JSON::String> Parameters; // List of parameters supplied to command
        }; // class StartParamsData

        class StopParamsData : public Core::JSON::Container {
        public:
            StopParamsData()
                : Core::JSON::Container()
            {
                Add(_T("name"), &Name);
            }

            bool IsValid() const
            {
                return (true);
            }

            StopParamsData(const StopParamsData&) = delete;
            StopParamsData& operator=(const StopParamsData&) = delete;

        public:
            Core::JSON::String Name; // Name of container
        }; // class StopParamsData

    } // namespace Containers

} // namespace JsonData

}

