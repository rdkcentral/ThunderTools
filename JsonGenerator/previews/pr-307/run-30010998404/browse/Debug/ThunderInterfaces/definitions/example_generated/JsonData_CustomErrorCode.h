// C++ types for CustomErrorCode API.
// Generated automatically from 'ICustomErrorCode.h'. DO NOT EDIT.

// Note: This code is inherently not thread safe. If required, proper synchronisation must be added.

#pragma once

#include <core/JSON.h>
#include <example_interfaces/ICustomErrorCode.h>

namespace Thunder {

namespace JsonData {

    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    namespace CustomErrorCode {

        // Method params/result classes
        //

        class TriggerCustomErrorParamsData : public Core::JSON::Container {
        public:
            TriggerCustomErrorParamsData()
                : Core::JSON::Container()
            {
                Add(_T("errorcode"), &Errorcode);
            }

            TriggerCustomErrorParamsData(const TriggerCustomErrorParamsData&) = delete;
            TriggerCustomErrorParamsData(TriggerCustomErrorParamsData&&) noexcept  = delete;

            TriggerCustomErrorParamsData& operator=(const TriggerCustomErrorParamsData&) = delete;
            TriggerCustomErrorParamsData& operator=(TriggerCustomErrorParamsData&&) noexcept  = delete;

            ~TriggerCustomErrorParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return (Errorcode.IsSet() == true);
            }

        public:
            Core::JSON::DecSInt32 Errorcode;
        }; // class TriggerCustomErrorParamsData

        class TriggerNonCustomErrorParamsData : public Core::JSON::Container {
        public:
            TriggerNonCustomErrorParamsData()
                : Core::JSON::Container()
            {
                Add(_T("errorcode"), &Errorcode);
            }

            TriggerNonCustomErrorParamsData(const TriggerNonCustomErrorParamsData&) = delete;
            TriggerNonCustomErrorParamsData(TriggerNonCustomErrorParamsData&&) noexcept  = delete;

            TriggerNonCustomErrorParamsData& operator=(const TriggerNonCustomErrorParamsData&) = delete;
            TriggerNonCustomErrorParamsData& operator=(TriggerNonCustomErrorParamsData&&) noexcept  = delete;

            ~TriggerNonCustomErrorParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return (Errorcode.IsSet() == true);
            }

        public:
            Core::JSON::DecUInt32 Errorcode;
        }; // class TriggerNonCustomErrorParamsData

    } // namespace CustomErrorCode

    POP_WARNING()

} // namespace JsonData

}

