// C++ types for Test Utility API.
// Generated automatically from 'TestUtility.json'. DO NOT EDIT.

// Note: This code is inherently not thread safe. If required, proper synchronisation must be added.

#pragma once

#include <core/JSON.h>
#include <core/Enumerate.h>

namespace WPEFramework {

namespace JsonData {

    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    namespace TestUtility {

        // Common enums
        //

        // Test command input parameter type
        enum class TypeType : uint8_t {
            NUMBER,
            STRING,
            BOOLEAN,
            OBJECT,
            SYMBOL
        };

        // Common classes
        //

        class InputInfo : public Core::JSON::Container {
        public:
            InputInfo()
                : Core::JSON::Container()
            {
                _Init();
            }

            InputInfo(const InputInfo& _other)
                : Core::JSON::Container()
                , Name(_other.Name)
                , Type(_other.Type)
                , Comment(_other.Comment)
            {
                _Init();
            }

            InputInfo(InputInfo&& _other) noexcept
                : Core::JSON::Container()
                , Name(std::move(_other.Name))
                , Type(std::move(_other.Type))
                , Comment(std::move(_other.Comment))
            {
                _Init();
            }

            InputInfo& operator=(const InputInfo& _rhs)
            {
                Name = _rhs.Name;
                Type = _rhs.Type;
                Comment = _rhs.Comment;
                return (*this);
            }

            InputInfo& operator=(InputInfo&& _rhs) noexcept
            {
                Name = std::move(_rhs.Name);
                Type = std::move(_rhs.Type);
                Comment = std::move(_rhs.Comment);
                return (*this);
            }

            ~InputInfo() = default;

        public:
            bool IsDataValid() const
            {
                return ((Name.IsSet() == true) && (Type.IsSet() == true) && (Comment.IsSet() == true));
            }

        private:
            void _Init()
            {
                Add(_T("name"), &Name);
                Add(_T("type"), &Type);
                Add(_T("comment"), &Comment);
            }

        public:
            Core::JSON::String Name; // Test command input parameter
            Core::JSON::EnumType<TypeType> Type; // Test command input parameter type
            Core::JSON::String Comment; // Test command input parameter description
        }; // class InputInfo

        // Method params/result classes
        //

        class DescriptionData : public Core::JSON::Container {
        public:
            DescriptionData()
                : Core::JSON::Container()
            {
                Add(_T("description"), &Description);
            }

            DescriptionData(const DescriptionData&) = delete;
            DescriptionData(DescriptionData&&) noexcept  = delete;

            DescriptionData& operator=(const DescriptionData&) = delete;
            DescriptionData& operator=(DescriptionData&&) noexcept  = delete;

            ~DescriptionData() = default;

        public:
            bool IsDataValid() const
            {
                return (Description.IsSet() == true);
            }

        public:
            Core::JSON::String Description; // Test command description
        }; // class DescriptionData

        class ParametersData : public Core::JSON::Container {
        public:
            ParametersData()
                : Core::JSON::Container()
            {
                Add(_T("input"), &Input);
                Add(_T("output"), &Output);
            }

            ParametersData(const ParametersData&) = delete;
            ParametersData(ParametersData&&) noexcept  = delete;

            ParametersData& operator=(const ParametersData&) = delete;
            ParametersData& operator=(ParametersData&&) noexcept  = delete;

            ~ParametersData() = default;

        public:
            bool IsDataValid() const
            {
                return ((Output.IsSet() == true) && (Output.IsDataValid() == true));
            }

        public:
            Core::JSON::ArrayType<InputInfo> Input;
            InputInfo Output;
        }; // class ParametersData

        class RuncrashParamsData : public Core::JSON::Container {
        public:
            RuncrashParamsData()
                : Core::JSON::Container()
            {
                Add(_T("command"), &Command);
                Add(_T("delay"), &Delay);
                Add(_T("count"), &Count);
            }

            RuncrashParamsData(const RuncrashParamsData&) = delete;
            RuncrashParamsData(RuncrashParamsData&&) noexcept  = delete;

            RuncrashParamsData& operator=(const RuncrashParamsData&) = delete;
            RuncrashParamsData& operator=(RuncrashParamsData&&) noexcept  = delete;

            ~RuncrashParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return (Command.IsSet() == true);
            }

        public:
            Core::JSON::String Command; // Test command name
            Core::JSON::DecUInt8 Delay; // Delay (in seconds) before the crash attempt (applicable for *Crash* command)
            Core::JSON::DecUInt8 Count; // How many times a Crash command will be executed consecutively (applicable for *CrashNTimes* command)
        }; // class RuncrashParamsData

        class RunmemoryParamsData : public Core::JSON::Container {
        public:
            RunmemoryParamsData()
                : Core::JSON::Container()
            {
                Add(_T("command"), &Command);
                Add(_T("size"), &Size);
            }

            RunmemoryParamsData(const RunmemoryParamsData&) = delete;
            RunmemoryParamsData(RunmemoryParamsData&&) noexcept  = delete;

            RunmemoryParamsData& operator=(const RunmemoryParamsData&) = delete;
            RunmemoryParamsData& operator=(RunmemoryParamsData&&) noexcept  = delete;

            ~RunmemoryParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return (Command.IsSet() == true);
            }

        public:
            Core::JSON::String Command; // Test command name
            Core::JSON::DecUInt32 Size; // The amount of memory in KB for allocation (applicable for *Malloc* commands)
        }; // class RunmemoryParamsData

        class RunmemoryResultData : public Core::JSON::Container {
        public:
            RunmemoryResultData()
                : Core::JSON::Container()
            {
                Add(_T("allocated"), &Allocated);
                Add(_T("size"), &Size);
                Add(_T("resident"), &Resident);
            }

            RunmemoryResultData(const RunmemoryResultData&) = delete;
            RunmemoryResultData(RunmemoryResultData&&) noexcept  = delete;

            RunmemoryResultData& operator=(const RunmemoryResultData&) = delete;
            RunmemoryResultData& operator=(RunmemoryResultData&&) noexcept  = delete;

            ~RunmemoryResultData() = default;

        public:
            bool IsDataValid() const
            {
                return ((Allocated.IsSet() == true) && (Size.IsSet() == true) && (Resident.IsSet() == true));
            }

        public:
            Core::JSON::DecUInt32 Allocated; // Already allocated memory in KB
            Core::JSON::DecUInt32 Size; // Current allocation in KB
            Core::JSON::DecUInt32 Resident; // Resident memory in KB
        }; // class RunmemoryResultData

    } // namespace TestUtility

    POP_WARNING()

} // namespace JsonData

// Enum conversion handlers
ENUM_CONVERSION_HANDLER(JsonData::TestUtility::TypeType)

}

