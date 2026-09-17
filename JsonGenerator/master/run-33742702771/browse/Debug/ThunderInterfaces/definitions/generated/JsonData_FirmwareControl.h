// C++ types for Firmware Control API.
// Generated automatically from 'FirmwareControl.json'. DO NOT EDIT.

// Note: This code is inherently not thread safe. If required, proper synchronisation must be added.

#pragma once

#include <core/JSON.h>
#include <core/Enumerate.h>

namespace Thunder {

namespace JsonData {

    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    namespace FirmwareControl {

        // Common enums
        //

        // Upgrade status
        enum class StatusType : uint8_t {
            NONE,
            UPGRADESTARTED,
            DOWNLOADSTARTED,
            DOWNLOADABORTED,
            DOWNLOADCOMPLETED,
            INSTALLINITIATED,
            INSTALLNOTSTARTED,
            INSTALLABORTED,
            INSTALLSTARTED,
            UPGRADECOMPLETED,
            UPGRADECANCELLED
        };

        // Method params/result classes
        //

        class ResumeParamsData : public Core::JSON::Container {
        public:
            ResumeParamsData()
                : Core::JSON::Container()
            {
                Add(_T("name"), &Name);
                Add(_T("location"), &Location);
            }

            ResumeParamsData(const ResumeParamsData&) = delete;
            ResumeParamsData(ResumeParamsData&&) noexcept  = delete;

            ResumeParamsData& operator=(const ResumeParamsData&) = delete;
            ResumeParamsData& operator=(ResumeParamsData&&) noexcept  = delete;

            ~ResumeParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return (Name.IsSet() == true);
            }

        public:
            Core::JSON::String Name; // Name of the firmware
            Core::JSON::String Location; // Location or URL of the firmware to be upgraded
        }; // class ResumeParamsData

        class UpgradeParamsData : public Core::JSON::Container {
        public:
            // Type of the firmware
            enum class TypeType : uint8_t {
                CDL,
                RCDL
            };

            UpgradeParamsData()
                : Core::JSON::Container()
            {
                Add(_T("name"), &Name);
                Add(_T("location"), &Location);
                Add(_T("type"), &Type);
                Add(_T("progressinterval"), &Progressinterval);
                Add(_T("hmac"), &Hmac);
            }

            UpgradeParamsData(const UpgradeParamsData&) = delete;
            UpgradeParamsData(UpgradeParamsData&&) noexcept  = delete;

            UpgradeParamsData& operator=(const UpgradeParamsData&) = delete;
            UpgradeParamsData& operator=(UpgradeParamsData&&) noexcept  = delete;

            ~UpgradeParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return (Name.IsSet() == true);
            }

        public:
            Core::JSON::String Name; // Name of the firmware
            Core::JSON::String Location; // Location or URL of the firmware to be upgraded
            Core::JSON::EnumType<UpgradeParamsData::TypeType> Type; // Type of the firmware
            Core::JSON::DecUInt16 Progressinterval; // Number of seconds between progress update events (5 seconds, 10 seconds etc). 0 means invoking callback only once to report final upgrade result
            Core::JSON::String Hmac; // HMAC value of firmare
        }; // class UpgradeParamsData

        class UpgradeprogressParamsData : public Core::JSON::Container {
        public:
            // Reason of error
            enum class ErrorType : uint8_t {
                NONE,
                GENERIC,
                INVALIDPARAMETERS,
                INVALIDSTATE,
                NOENOUGHSPACE,
                OPERATIONOTSUPPORTED,
                INCORRECTHASH,
                UNAUTHENTICATED,
                UNAVAILABLE,
                TIMEDOUT,
                DOWNLOADDIRECTORYNOTEXIST,
                RESUMENOTSUPPORTED,
                INVALIDRANGE,
                UNKOWN
            };

            UpgradeprogressParamsData()
                : Core::JSON::Container()
            {
                Add(_T("status"), &Status);
                Add(_T("error"), &Error);
                Add(_T("progress"), &Progress);
            }

            UpgradeprogressParamsData(const UpgradeprogressParamsData&) = delete;
            UpgradeprogressParamsData(UpgradeprogressParamsData&&) noexcept  = delete;

            UpgradeprogressParamsData& operator=(const UpgradeprogressParamsData&) = delete;
            UpgradeprogressParamsData& operator=(UpgradeprogressParamsData&&) noexcept  = delete;

            ~UpgradeprogressParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return ((Status.IsSet() == true) && (Error.IsSet() == true) && (Progress.IsSet() == true));
            }

        public:
            Core::JSON::EnumType<StatusType> Status; // Upgrade status
            Core::JSON::EnumType<UpgradeprogressParamsData::ErrorType> Error; // Reason of error
            Core::JSON::DecUInt32 Progress; // Progress of upgrade (number of bytes transferred during download or percentage of completion during install
        }; // class UpgradeprogressParamsData

    } // namespace FirmwareControl

    POP_WARNING()

} // namespace JsonData

// Enum conversion handlers
ENUM_CONVERSION_HANDLER(JsonData::FirmwareControl::UpgradeParamsData::TypeType)
ENUM_CONVERSION_HANDLER(JsonData::FirmwareControl::StatusType)
ENUM_CONVERSION_HANDLER(JsonData::FirmwareControl::UpgradeprogressParamsData::ErrorType)

}

