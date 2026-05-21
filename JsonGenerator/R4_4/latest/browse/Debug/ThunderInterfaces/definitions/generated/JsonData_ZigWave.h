// C++ classes for ZigWave API JSON-RPC API.
// Generated automatically from 'IZigWave.h'. DO NOT EDIT.

// Note: This code is inherently not thread safe. If required, proper synchronisation must be added.

#pragma once

#include <core/JSON.h>
#include <interfaces/IZigWave.h>

namespace WPEFramework {

namespace JsonData {

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

            bool IsValid() const
            {
                return (true);
            }

            BindParamsInfo(const BindParamsInfo&) = delete;
            BindParamsInfo& operator=(const BindParamsInfo&) = delete;

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

            bool IsValid() const
            {
                return (true);
            }

            PermutableInfo(const PermutableInfo&) = delete;
            PermutableInfo& operator=(const PermutableInfo&) = delete;

        public:
            Core::JSON::Boolean Value; // To allow new devices to the network, the controller should be placed into an accepting mode. By enabling this mode,
                    //  the controller can accept new devices.
        }; // class PermutableInfo

        // Method params/result classes
        //

    } // namespace ZigWave

} // namespace JsonData

}

