// C++ types for Input Switch API.
// Generated automatically from 'InputSwitch.json'. DO NOT EDIT.

// Note: This code is inherently not thread safe. If required, proper synchronisation must be added.

#pragma once

#include <core/JSON.h>

namespace Thunder {

namespace JsonData {

    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    namespace InputSwitch {

        // Common classes
        //

        class ChannelParamsInfo : public Core::JSON::Container {
        public:
            ChannelParamsInfo()
                : Core::JSON::Container()
            {
                _Init();
            }

            ChannelParamsInfo(const ChannelParamsInfo& _other)
                : Core::JSON::Container()
                , Name(_other.Name)
                , Enabled(_other.Enabled)
            {
                _Init();
            }

            ChannelParamsInfo(ChannelParamsInfo&& _other) noexcept
                : Core::JSON::Container()
                , Name(std::move(_other.Name))
                , Enabled(std::move(_other.Enabled))
            {
                _Init();
            }

            ChannelParamsInfo& operator=(const ChannelParamsInfo& _rhs)
            {
                Name = _rhs.Name;
                Enabled = _rhs.Enabled;
                return (*this);
            }

            ChannelParamsInfo& operator=(ChannelParamsInfo&& _rhs) noexcept
            {
                Name = std::move(_rhs.Name);
                Enabled = std::move(_rhs.Enabled);
                return (*this);
            }

            ~ChannelParamsInfo() = default;

        public:
            bool IsDataValid() const
            {
                return ((Name.IsSet() == true) && (Enabled.IsSet() == true));
            }

        private:
            void _Init()
            {
                Add(_T("name"), &Name);
                Add(_T("enabled"), &Enabled);
            }

        public:
            Core::JSON::String Name; // Callsign that is the owner of this channel
            Core::JSON::Boolean Enabled; // Enable or disable the throughput of data through this channel
        }; // class ChannelParamsInfo

        class SelectParamsInfo : public Core::JSON::Container {
        public:
            SelectParamsInfo()
                : Core::JSON::Container()
            {
                Add(_T("name"), &Name);
            }

            SelectParamsInfo(const SelectParamsInfo&) = delete;
            SelectParamsInfo(SelectParamsInfo&&) noexcept  = delete;

            SelectParamsInfo& operator=(const SelectParamsInfo&) = delete;
            SelectParamsInfo& operator=(SelectParamsInfo&&) noexcept  = delete;

            ~SelectParamsInfo() = default;

        public:
            bool IsDataValid() const
            {
                return (Name.IsSet() == true);
            }

        public:
            Core::JSON::String Name; // Callsign that is the owner of this channel
        }; // class SelectParamsInfo

        // Method params/result classes
        //

    } // namespace InputSwitch

    POP_WARNING()

} // namespace JsonData

}

