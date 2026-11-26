// C++ types for Process Containers.
// Generated automatically from 'Containers.json'. DO NOT EDIT.

// Note: This code is inherently not thread safe. If required, proper synchronisation must be added.

#pragma once

#include <core/JSON.h>

namespace Thunder {

namespace JsonData {

    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

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

            CpuData(const CpuData&) = delete;
            CpuData(CpuData&&) noexcept  = delete;

            CpuData& operator=(const CpuData&) = delete;
            CpuData& operator=(CpuData&&) noexcept  = delete;

            ~CpuData() = default;

        public:
            bool IsDataValid() const
            {
                return ((Total.IsSet() == true) && (Cores.IsSet() == true));
            }

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

            MemoryData(const MemoryData&) = delete;
            MemoryData(MemoryData&&) noexcept  = delete;

            MemoryData& operator=(const MemoryData&) = delete;
            MemoryData& operator=(MemoryData&&) noexcept  = delete;

            ~MemoryData() = default;

        public:
            bool IsDataValid() const
            {
                return ((Allocated.IsSet() == true) && (Resident.IsSet() == true) && (Shared.IsSet() == true));
            }

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

            NetworksResultDataElem(NetworksResultDataElem&& _other) noexcept
                : Core::JSON::Container()
                , Interface(std::move(_other.Interface))
                , Ips(std::move(_other.Ips))
            {
                _Init();
            }

            NetworksResultDataElem& operator=(const NetworksResultDataElem& _rhs)
            {
                Interface = _rhs.Interface;
                Ips = _rhs.Ips;
                return (*this);
            }

            NetworksResultDataElem& operator=(NetworksResultDataElem&& _rhs) noexcept
            {
                Interface = std::move(_rhs.Interface);
                Ips = std::move(_rhs.Ips);
                return (*this);
            }

            ~NetworksResultDataElem() = default;

        public:
            bool IsDataValid() const
            {
                return ((Interface.IsSet() == true) && (Ips.IsSet() == true));
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

            StartParamsData(const StartParamsData&) = delete;
            StartParamsData(StartParamsData&&) noexcept  = delete;

            StartParamsData& operator=(const StartParamsData&) = delete;
            StartParamsData& operator=(StartParamsData&&) noexcept  = delete;

            ~StartParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return ((Name.IsSet() == true) && (Command.IsSet() == true) && (Parameters.IsSet() == true));
            }

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

            StopParamsData(const StopParamsData&) = delete;
            StopParamsData(StopParamsData&&) noexcept  = delete;

            StopParamsData& operator=(const StopParamsData&) = delete;
            StopParamsData& operator=(StopParamsData&&) noexcept  = delete;

            ~StopParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return (Name.IsSet() == true);
            }

        public:
            Core::JSON::String Name; // Name of container
        }; // class StopParamsData

    } // namespace Containers

    POP_WARNING()

} // namespace JsonData

}

