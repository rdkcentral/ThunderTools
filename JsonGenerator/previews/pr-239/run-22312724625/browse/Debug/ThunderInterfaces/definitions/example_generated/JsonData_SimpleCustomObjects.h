// C++ types for SimpleCustomObjects API.
// Generated automatically from 'ISimpleCustomObjects.h'. DO NOT EDIT.

// Note: This code is inherently not thread safe. If required, proper synchronisation must be added.

#pragma once

#include <core/JSON.h>
#include <example_interfaces/ISimpleCustomObjects.h>

namespace Thunder {

namespace JsonData {

    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    namespace SimpleCustomObjects {

        // Common classes
        //

        class AddedParamsInfo : public Core::JSON::Container {
        public:
            AddedParamsInfo()
                : Core::JSON::Container()
            {
                Add(_T("accessory"), &Accessory);
            }

            AddedParamsInfo(const AddedParamsInfo&) = delete;
            AddedParamsInfo(AddedParamsInfo&&) noexcept  = delete;

            AddedParamsInfo& operator=(const AddedParamsInfo&) = delete;
            AddedParamsInfo& operator=(AddedParamsInfo&&) noexcept  = delete;

            ~AddedParamsInfo() = default;

        public:
            bool IsDataValid() const
            {
                return (Accessory.IsSet() == true);
            }

        public:
            Core::JSON::String Accessory; // Accessory instance
        }; // class AddedParamsInfo

        // Method params/result classes
        //

        class NameChangedParamsData : public Core::JSON::Container {
        public:
            NameChangedParamsData()
                : Core::JSON::Container()
            {
                Add(_T("name"), &Name);
            }

            NameChangedParamsData(const NameChangedParamsData&) = delete;
            NameChangedParamsData(NameChangedParamsData&&) noexcept  = delete;

            NameChangedParamsData& operator=(const NameChangedParamsData&) = delete;
            NameChangedParamsData& operator=(NameChangedParamsData&&) noexcept  = delete;

            ~NameChangedParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return (Name.IsSet() == true);
            }

        public:
            Core::JSON::String Name; // Name of the accessory
        }; // class NameChangedParamsData

        class NameData : public Core::JSON::Container {
        public:
            NameData()
                : Core::JSON::Container()
            {
                Add(_T("value"), &Value);
            }

            NameData(const NameData&) = delete;
            NameData(NameData&&) noexcept  = delete;

            NameData& operator=(const NameData&) = delete;
            NameData& operator=(NameData&&) noexcept  = delete;

            ~NameData() = default;

        public:
            bool IsDataValid() const
            {
                return (Value.IsSet() == true);
            }

        public:
            Core::JSON::String Value; // Name of the accessory
        }; // class NameData

        class PinData : public Core::JSON::Container {
        public:
            PinData()
                : Core::JSON::Container()
            {
                Add(_T("value"), &Value);
            }

            PinData(const PinData&) = delete;
            PinData(PinData&&) noexcept  = delete;

            PinData& operator=(const PinData&) = delete;
            PinData& operator=(PinData&&) noexcept  = delete;

            ~PinData() = default;

        public:
            bool IsDataValid() const
            {
                return (Value.IsSet() == true);
            }

        public:
            Core::JSON::Boolean Value; // Pin state
        }; // class PinData

    } // namespace SimpleCustomObjects

    POP_WARNING()

} // namespace JsonData

}

