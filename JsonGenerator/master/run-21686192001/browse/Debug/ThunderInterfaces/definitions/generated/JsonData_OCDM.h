// C++ types for OpenCDMi API.
// Generated automatically from 'OCDM.json'. DO NOT EDIT.

// Note: This code is inherently not thread safe. If required, proper synchronisation must be added.

#pragma once

#include <core/JSON.h>
#include <core/Enumerate.h>

namespace Thunder {

namespace JsonData {

    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    namespace OCDM {

        // Common classes
        //

        class SessionInfo : public Core::JSON::Container {
        public:
            SessionInfo()
                : Core::JSON::Container()
            {
                _Init();
            }

            SessionInfo(const SessionInfo& _other)
                : Core::JSON::Container()
                , Drm(_other.Drm)
            {
                _Init();
            }

            SessionInfo(SessionInfo&& _other) noexcept
                : Core::JSON::Container()
                , Drm(std::move(_other.Drm))
            {
                _Init();
            }

            SessionInfo& operator=(const SessionInfo& _rhs)
            {
                Drm = _rhs.Drm;
                return (*this);
            }

            SessionInfo& operator=(SessionInfo&& _rhs) noexcept
            {
                Drm = std::move(_rhs.Drm);
                return (*this);
            }

            ~SessionInfo() = default;

        public:
            bool IsDataValid() const
            {
                return (Drm.IsSet() == true);
            }

        private:
            void _Init()
            {
                Add(_T("drm"), &Drm);
            }

        public:
            Core::JSON::String Drm; // Name of the DRM system
        }; // class SessionInfo

        // Method params/result classes
        //

        class DrminitializationstatusParamsData : public Core::JSON::Container {
        public:
            // BUSY - drm is used by another process, SUCCESS - recovered from BUSY state after retry, FAILED - not recovered after re-trying from BUSY
            enum class StatusType : uint8_t {
                BUSY,
                SUCCESS,
                FAILED
            };

            DrminitializationstatusParamsData()
                : Core::JSON::Container()
            {
                Add(_T("status"), &Status);
                Add(_T("drm"), &Drm);
            }

            DrminitializationstatusParamsData(const DrminitializationstatusParamsData&) = delete;
            DrminitializationstatusParamsData(DrminitializationstatusParamsData&&) noexcept  = delete;

            DrminitializationstatusParamsData& operator=(const DrminitializationstatusParamsData&) = delete;
            DrminitializationstatusParamsData& operator=(DrminitializationstatusParamsData&&) noexcept  = delete;

            ~DrminitializationstatusParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return ((Status.IsSet() == true) && (Drm.IsSet() == true));
            }

        public:
            Core::JSON::EnumType<DrminitializationstatusParamsData::StatusType> Status; // BUSY - drm is used by another process, SUCCESS - recovered from BUSY state after retry, FAILED - not recovered after re-trying from BUSY
            Core::JSON::String Drm; // Name of the DRM system
        }; // class DrminitializationstatusParamsData

        class DrmData : public Core::JSON::Container {
        public:
            DrmData()
                : Core::JSON::Container()
            {
                _Init();
            }

            DrmData(const DrmData& _other)
                : Core::JSON::Container()
                , Name(_other.Name)
                , Keysystems(_other.Keysystems)
            {
                _Init();
            }

            DrmData(DrmData&& _other) noexcept
                : Core::JSON::Container()
                , Name(std::move(_other.Name))
                , Keysystems(std::move(_other.Keysystems))
            {
                _Init();
            }

            DrmData& operator=(const DrmData& _rhs)
            {
                Name = _rhs.Name;
                Keysystems = _rhs.Keysystems;
                return (*this);
            }

            DrmData& operator=(DrmData&& _rhs) noexcept
            {
                Name = std::move(_rhs.Name);
                Keysystems = std::move(_rhs.Keysystems);
                return (*this);
            }

            ~DrmData() = default;

        public:
            bool IsDataValid() const
            {
                return ((Name.IsSet() == true) && (Keysystems.IsSet() == true));
            }

        private:
            void _Init()
            {
                Add(_T("name"), &Name);
                Add(_T("keysystems"), &Keysystems);
            }

        public:
            Core::JSON::String Name; // Name of the DRM
            Core::JSON::ArrayType<Core::JSON::String> Keysystems; // Key system identifier list
        }; // class DrmData

    } // namespace OCDM

    POP_WARNING()

} // namespace JsonData

// Enum conversion handlers
ENUM_CONVERSION_HANDLER(JsonData::OCDM::DrminitializationstatusParamsData::StatusType)

}

