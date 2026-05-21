// C++ classes for Trace Control API JSON-RPC API.
// Generated automatically from 'TraceControl.json'. DO NOT EDIT.

// Note: This code is inherently not thread safe. If required, proper synchronisation must be added.

#pragma once

#include <core/JSON.h>
#include <core/Enumerate.h>

namespace WPEFramework {

namespace JsonData {

    namespace TraceControl {

        // Common enums
        //

        // State value
        enum class StateType : uint8_t {
            ENABLED,
            DISABLED,
            TRISTATED
        };

        // Common classes
        //

        class TraceInfo : public Core::JSON::Container {
        public:
            TraceInfo()
                : Core::JSON::Container()
            {
                _Init();
            }

            TraceInfo(const TraceInfo& _other)
                : Core::JSON::Container()
                , Module(_other.Module)
                , Category(_other.Category)
                , State(_other.State)
            {
                _Init();
            }

            TraceInfo& operator=(const TraceInfo& _rhs)
            {
                Module = _rhs.Module;
                Category = _rhs.Category;
                State = _rhs.State;
                return (*this);
            }

            bool IsValid() const
            {
                return (true);
            }

        private:
            void _Init()
            {
                Add(_T("module"), &Module);
                Add(_T("category"), &Category);
                Add(_T("state"), &State);
            }

        public:
            Core::JSON::String Module; // Module name
            Core::JSON::String Category; // Category name
            Core::JSON::EnumType<StateType> State; // State value
        }; // class TraceInfo

        // Method params/result classes
        //

        class StatusParamsData : public Core::JSON::Container {
        public:
            StatusParamsData()
                : Core::JSON::Container()
            {
                Add(_T("module"), &Module);
                Add(_T("category"), &Category);
            }

            bool IsValid() const
            {
                return (true);
            }

            StatusParamsData(const StatusParamsData&) = delete;
            StatusParamsData& operator=(const StatusParamsData&) = delete;

        public:
            Core::JSON::String Module; // Module name
            Core::JSON::String Category; // Category name
        }; // class StatusParamsData

        class StatusResultData : public Core::JSON::Container {
        public:
            class RemoteData : public Core::JSON::Container {
            public:
                RemoteData()
                    : Core::JSON::Container()
                {
                    Add(_T("port"), &Port);
                    Add(_T("binding"), &Binding);
                }

                bool IsValid() const
                {
                    return (true);
                }

                RemoteData(const RemoteData&) = delete;
                RemoteData& operator=(const RemoteData&) = delete;

            public:
                Core::JSON::DecUInt16 Port; // Config attribute (port)
                Core::JSON::String Binding; // Config attribute (binding)
            }; // class RemoteData

            StatusResultData()
                : Core::JSON::Container()
            {
                Add(_T("console"), &Console);
                Add(_T("remote"), &Remote);
                Add(_T("settings"), &Settings);
            }

            bool IsValid() const
            {
                return (true);
            }

            StatusResultData(const StatusResultData&) = delete;
            StatusResultData& operator=(const StatusResultData&) = delete;

        public:
            Core::JSON::Boolean Console; // Config attribute (Console)
            StatusResultData::RemoteData Remote; // Retrieves general information
            Core::JSON::ArrayType<TraceInfo> Settings; // Retrieves general information
        }; // class StatusResultData

    } // namespace TraceControl

} // namespace JsonData

// Enum conversion handlers
ENUM_CONVERSION_HANDLER(JsonData::TraceControl::StateType)

}

