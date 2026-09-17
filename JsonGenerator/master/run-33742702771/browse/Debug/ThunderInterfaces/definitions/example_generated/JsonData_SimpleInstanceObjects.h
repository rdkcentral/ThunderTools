// C++ types for SimpleInstanceObjects API.
// Generated automatically from 'ISimpleInstanceObjects.h'. DO NOT EDIT.

// Note: This code is inherently not thread safe. If required, proper synchronisation must be added.

#pragma once

#include <core/JSON.h>
#include <example_interfaces/ISimpleInstanceObjects.h>

namespace Thunder {

namespace JsonData {

    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    namespace SimpleInstanceObjects {

        // Method params/result classes
        //

        class AcquireParamsData : public Core::JSON::Container {
        public:
            AcquireParamsData()
                : Core::JSON::Container()
            {
                Add(_T("name"), &Name);
            }

            AcquireParamsData(const AcquireParamsData&) = delete;
            AcquireParamsData(AcquireParamsData&&) noexcept  = delete;

            AcquireParamsData& operator=(const AcquireParamsData&) = delete;
            AcquireParamsData& operator=(AcquireParamsData&&) noexcept  = delete;

            ~AcquireParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return (Name.IsSet() == true);
            }

        public:
            Core::JSON::String Name; // Name of the device to acquire
        }; // class AcquireParamsData

        class NameChangedParamsData : public Core::JSON::Container {
        public:
            NameChangedParamsData()
                : Core::JSON::Container()
            {
                Add(_T("state"), &State);
            }

            NameChangedParamsData(const NameChangedParamsData&) = delete;
            NameChangedParamsData(NameChangedParamsData&&) noexcept  = delete;

            NameChangedParamsData& operator=(const NameChangedParamsData&) = delete;
            NameChangedParamsData& operator=(NameChangedParamsData&&) noexcept  = delete;

            ~NameChangedParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return (State.IsSet() == true);
            }

        public:
            Core::JSON::String State; // New name of the device
        }; // class NameChangedParamsData

        class NameData : public Core::JSON::Container {
        public:
            NameData()
                : Core::JSON::Container()
            {
                Add(_T("value"), &Value);
            }

            NameData(const NameData&) = delete;
            NameData(NameData&&) noexcept  = delete;

            NameData& operator=(const NameData&) = delete;
            NameData& operator=(NameData&&) noexcept  = delete;

            ~NameData() = default;

        public:
            bool IsDataValid() const
            {
                return (Value.IsSet() == true);
            }

        public:
            Core::JSON::String Value; // Name of the device
        }; // class NameData

        class PinChangedParamsData : public Core::JSON::Container {
        public:
            PinChangedParamsData()
                : Core::JSON::Container()
            {
                Add(_T("pin"), &Pin);
                Add(_T("high"), &High);
            }

            PinChangedParamsData(const PinChangedParamsData&) = delete;
            PinChangedParamsData(PinChangedParamsData&&) noexcept  = delete;

            PinChangedParamsData& operator=(const PinChangedParamsData&) = delete;
            PinChangedParamsData& operator=(PinChangedParamsData&&) noexcept  = delete;

            ~PinChangedParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return (High.IsSet() == true);
            }

        public:
            Core::JSON::DecUInt8 Pin; // Signals pin state changes
            Core::JSON::Boolean High; // Signals pin state changes
        }; // class PinChangedParamsData

        class PinData : public Core::JSON::Container {
        public:
            PinData()
                : Core::JSON::Container()
            {
                Add(_T("value"), &Value);
            }

            PinData(const PinData&) = delete;
            PinData(PinData&&) noexcept  = delete;

            PinData& operator=(const PinData&) = delete;
            PinData& operator=(PinData&&) noexcept  = delete;

            ~PinData() = default;

        public:
            bool IsDataValid() const
            {
                return (Value.IsSet() == true);
            }

        public:
            Core::JSON::Boolean Value; // A pin
        }; // class PinData

        class RelinquishParamsData : public Core::JSON::Container {
        public:
            RelinquishParamsData()
                : Core::JSON::Container()
            {
                Add(_T("device"), &Device);
            }

            RelinquishParamsData(const RelinquishParamsData&) = delete;
            RelinquishParamsData(RelinquishParamsData&&) noexcept  = delete;

            RelinquishParamsData& operator=(const RelinquishParamsData&) = delete;
            RelinquishParamsData& operator=(RelinquishParamsData&&) noexcept  = delete;

            ~RelinquishParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return (Device.IsSet() == true);
            }

        public:
            Core::JSON::DecUInt32 Device; // Device instance to relinquish
        }; // class RelinquishParamsData

        class StateChangedParamsData : public Core::JSON::Container {
        public:
            StateChangedParamsData()
                : Core::JSON::Container()
            {
                Add(_T("state"), &State);
            }

            StateChangedParamsData(const StateChangedParamsData&) = delete;
            StateChangedParamsData(StateChangedParamsData&&) noexcept  = delete;

            StateChangedParamsData& operator=(const StateChangedParamsData&) = delete;
            StateChangedParamsData& operator=(StateChangedParamsData&&) noexcept  = delete;

            ~StateChangedParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return (State.IsSet() == true);
            }

        public:
            Core::JSON::EnumType<Example::ISimpleInstanceObjects::state> State; // New state of the device
        }; // class StateChangedParamsData

    } // namespace SimpleInstanceObjects

    POP_WARNING()

} // namespace JsonData

// Enum conversion handlers
ENUM_CONVERSION_HANDLER(Example::ISimpleInstanceObjects::state)

}

