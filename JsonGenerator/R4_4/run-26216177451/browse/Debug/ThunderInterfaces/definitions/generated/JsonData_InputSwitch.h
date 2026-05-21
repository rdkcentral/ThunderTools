// C++ classes for Input Switch API JSON-RPC API.
// Generated automatically from 'InputSwitch.json'. DO NOT EDIT.

// Note: This code is inherently not thread safe. If required, proper synchronisation must be added.

#pragma once

#include <core/JSON.h>

namespace WPEFramework {

namespace JsonData {

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

            ChannelParamsInfo& operator=(const ChannelParamsInfo& _rhs)
            {
                Name = _rhs.Name;
                Enabled = _rhs.Enabled;
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

            bool IsValid() const
            {
                return (true);
            }

            SelectParamsInfo(const SelectParamsInfo&) = delete;
            SelectParamsInfo& operator=(const SelectParamsInfo&) = delete;

        public:
            Core::JSON::String Name; // Callsign that is the owner of this channel
        }; // class SelectParamsInfo

        // Method params/result classes
        //

    } // namespace InputSwitch

} // namespace JsonData

}

