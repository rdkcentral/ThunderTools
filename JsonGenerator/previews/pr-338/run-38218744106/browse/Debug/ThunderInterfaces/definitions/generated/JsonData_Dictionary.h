// C++ types for Dictionary API.
// Generated automatically from 'IDictionary.h'. DO NOT EDIT.

// Note: This code is inherently not thread safe. If required, proper synchronisation must be added.

#pragma once

#include <core/JSON.h>
#include <interfaces/IDictionary.h>

namespace Thunder {

namespace JsonData {

    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    namespace Dictionary {

        // Method params/result classes
        //

        class GetParamsData : public Core::JSON::Container {
        public:
            GetParamsData()
                : Core::JSON::Container()
            {
                Add(_T("path"), &Path);
                Add(_T("key"), &Key);
            }

            GetParamsData(const GetParamsData&) = delete;
            GetParamsData(GetParamsData&&) noexcept  = delete;

            GetParamsData& operator=(const GetParamsData&) = delete;
            GetParamsData& operator=(GetParamsData&&) noexcept  = delete;

            ~GetParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return ((Path.IsSet() == true) && (Key.IsSet() == true));
            }

        public:
            Core::JSON::String Path; // NameSpace path to be used
            Core::JSON::String Key; // Key to be used
        }; // class GetParamsData

        class ModifiedParamsData : public Core::JSON::Container {
        public:
            ModifiedParamsData()
                : Core::JSON::Container()
            {
                Add(_T("key"), &Key);
                Add(_T("value"), &Value);
            }

            ModifiedParamsData(const ModifiedParamsData&) = delete;
            ModifiedParamsData(ModifiedParamsData&&) noexcept  = delete;

            ModifiedParamsData& operator=(const ModifiedParamsData&) = delete;
            ModifiedParamsData& operator=(ModifiedParamsData&&) noexcept  = delete;

            ~ModifiedParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return ((Key.IsSet() == true) && (Value.IsSet() == true));
            }

        public:
            Core::JSON::String Key; // Key which value changed
            Core::JSON::String Value; // Value that changed
        }; // class ModifiedParamsData

        class PathEntriesParamsData : public Core::JSON::Container {
        public:
            PathEntriesParamsData()
                : Core::JSON::Container()
            {
                Add(_T("path"), &Path);
            }

            PathEntriesParamsData(const PathEntriesParamsData&) = delete;
            PathEntriesParamsData(PathEntriesParamsData&&) noexcept  = delete;

            PathEntriesParamsData& operator=(const PathEntriesParamsData&) = delete;
            PathEntriesParamsData& operator=(PathEntriesParamsData&&) noexcept  = delete;

            ~PathEntriesParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return (Path.IsSet() == true);
            }

        public:
            Core::JSON::String Path; // Namespace path where to get the keys and/or nested namespaces for
        }; // class PathEntriesParamsData

        class PathEntryData : public Core::JSON::Container {
        public:
            PathEntryData()
                : Core::JSON::Container()
            {
                _Init();
            }

            PathEntryData(const PathEntryData& _other)
                : Core::JSON::Container()
                , Name(_other.Name)
                , Type(_other.Type)
            {
                _Init();
            }

            PathEntryData(PathEntryData&& _other) noexcept
                : Core::JSON::Container()
                , Name(std::move(_other.Name))
                , Type(std::move(_other.Type))
            {
                _Init();
            }

            PathEntryData(const Exchange::IDictionary::PathEntry& _other)
                : Core::JSON::Container()
            {
                Name = _other.name;
                Type = _other.type;
                _Init();
            }

            PathEntryData& operator=(const PathEntryData& _rhs)
            {
                Name = _rhs.Name;
                Type = _rhs.Type;
                return (*this);
            }

            PathEntryData& operator=(PathEntryData&& _rhs) noexcept
            {
                Name = std::move(_rhs.Name);
                Type = std::move(_rhs.Type);
                return (*this);
            }

            PathEntryData& operator=(const Exchange::IDictionary::PathEntry& _rhs)
            {
                Name = _rhs.name;
                Type = _rhs.type;
                return (*this);
            }

            operator Exchange::IDictionary::PathEntry() const
            {
                Exchange::IDictionary::PathEntry _value{};
                _value.name = Name;
                _value.type = Type;
                return (_value);
            }

            ~PathEntryData() = default;

        public:
            bool IsDataValid() const
            {
                return ((Name.IsSet() == true) && (Type.IsSet() == true));
            }

        private:
            void _Init()
            {
                Add(_T("name"), &Name);
                Add(_T("type"), &Type);
            }

        public:
            Core::JSON::String Name; // Name of Key or Namespace
            Core::JSON::EnumType<Exchange::IDictionary::Type> Type; // Type
        }; // class PathEntryData

        class SetParamsData : public Core::JSON::Container {
        public:
            SetParamsData()
                : Core::JSON::Container()
            {
                Add(_T("path"), &Path);
                Add(_T("key"), &Key);
                Add(_T("value"), &Value);
            }

            SetParamsData(const SetParamsData&) = delete;
            SetParamsData(SetParamsData&&) noexcept  = delete;

            SetParamsData& operator=(const SetParamsData&) = delete;
            SetParamsData& operator=(SetParamsData&&) noexcept  = delete;

            ~SetParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return ((Path.IsSet() == true) && (Key.IsSet() == true) && (Value.IsSet() == true));
            }

        public:
            Core::JSON::String Path; // NameSpace path to be used
            Core::JSON::String Key; // Key to be used
            Core::JSON::String Value; // Value to be set
        }; // class SetParamsData

    } // namespace Dictionary

    POP_WARNING()

} // namespace JsonData

// Enum conversion handlers
ENUM_CONVERSION_HANDLER(Exchange::IDictionary::Type)

}

