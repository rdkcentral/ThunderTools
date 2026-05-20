// C++ classes for OpenCDMi API JSON-RPC API.
// Generated automatically from 'OCDM.json'. DO NOT EDIT.

// Note: This code is inherently not thread safe. If required, proper synchronisation must be added.

#pragma once

#include <core/JSON.h>
#include <core/Enumerate.h>

namespace WPEFramework {

namespace JsonData {

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

            SessionInfo& operator=(const SessionInfo& _rhs)
            {
                Drm = _rhs.Drm;
                return (*this);
            }

            bool IsValid() const
            {
                return (true);
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

            bool IsValid() const
            {
                return (true);
            }

            DrminitializationstatusParamsData(const DrminitializationstatusParamsData&) = delete;
            DrminitializationstatusParamsData& operator=(const DrminitializationstatusParamsData&) = delete;

        public:
            Core::JSON::EnumType<DrminitializationstatusParamsData::StatusType> Status; // BUSY - drm is used by another process,
                    //  SUCCESS - recovered from BUSY state after retry, FAILED - not recovered after re-trying from BUSY
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

            DrmData& operator=(const DrmData& _rhs)
            {
                Name = _rhs.Name;
                Keysystems = _rhs.Keysystems;
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
                Add(_T("keysystems"), &Keysystems);
            }

        public:
            Core::JSON::String Name; // Name of the DRM
            Core::JSON::ArrayType<Core::JSON::String> Keysystems;
        }; // class DrmData

    } // namespace OCDM

} // namespace JsonData

// Enum conversion handlers
ENUM_CONVERSION_HANDLER(JsonData::OCDM::DrminitializationstatusParamsData::StatusType)

}

