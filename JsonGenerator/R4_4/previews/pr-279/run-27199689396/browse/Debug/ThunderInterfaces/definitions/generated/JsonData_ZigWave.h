// C++ types for ZigWave API.
// Generated automatically from 'IZigWave.h'. DO NOT EDIT.

// Note: This code is inherently not thread safe. If required, proper synchronisation must be added.

#pragma once

#include <core/JSON.h>
#include <interfaces/IZigWave.h>

namespace WPEFramework {

namespace JsonData {

    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    namespace ZigWave {

        // Common classes
        //

        class BindParamsInfo : public Core::JSON::Container {
        public:
            BindParamsInfo()
                : Core::JSON::Container()
            {
                Add(_T("source"), &Source);
                Add(_T("destination"), &Destination);
            }

            BindParamsInfo(const BindParamsInfo&) = delete;
            BindParamsInfo(BindParamsInfo&&) noexcept  = delete;

            BindParamsInfo& operator=(const BindParamsInfo&) = delete;
            BindParamsInfo& operator=(BindParamsInfo&&) noexcept  = delete;

            ~BindParamsInfo() = default;

        public:
            bool IsDataValid() const
            {
                return ((Source.IsSet() == true) && (Destination.IsSet() == true));
            }

        public:
            Core::JSON::DecUInt32 Source; // Bind the *out* from the soure to the *in* of the destination
            Core::JSON::DecUInt32 Destination; // Bind the *out* from the soure to the *in* of the destination
        }; // class BindParamsInfo

        class PermutableInfo : public Core::JSON::Container {
        public:
            PermutableInfo()
                : Core::JSON::Container()
            {
                Add(_T("value"), &Value);
            }

            PermutableInfo(const PermutableInfo&) = delete;
            PermutableInfo(PermutableInfo&&) noexcept  = delete;

            PermutableInfo& operator=(const PermutableInfo&) = delete;
            PermutableInfo& operator=(PermutableInfo&&) noexcept  = delete;

            ~PermutableInfo() = default;

        public:
            bool IsDataValid() const
            {
                return (Value.IsSet() == true);
            }

        public:
            Core::JSON::Boolean Value; // To allow new devices to the network, the controller should be placed into an accepting mode. By enabling this mode, the controller can accept new devices.
        }; // class PermutableInfo

        // Method params/result classes
        //

    } // namespace ZigWave

    POP_WARNING()

} // namespace JsonData

}

