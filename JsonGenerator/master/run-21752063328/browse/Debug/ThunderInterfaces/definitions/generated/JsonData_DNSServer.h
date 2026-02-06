// C++ types for DNSServer API.
// Generated automatically from 'IDNSServer.h'. DO NOT EDIT.

// Note: This code is inherently not thread safe. If required, proper synchronisation must be added.

#pragma once

#include <core/JSON.h>
#include <interfaces/IDNSServer.h>

namespace Thunder {

namespace JsonData {

    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    namespace DNSServer {

        // Common classes
        //

        class RecordInfo : public Core::JSON::Container {
        public:
            RecordInfo()
                : Core::JSON::Container()
            {
                _Init();
            }

            RecordInfo(const RecordInfo& _other)
                : Core::JSON::Container()
                , Type(_other.Type)
                , Key(_other.Key)
                , Value(_other.Value)
                , TTL(_other.TTL)
                , Priority(_other.Priority)
            {
                _Init();
            }

            RecordInfo(RecordInfo&& _other) noexcept
                : Core::JSON::Container()
                , Type(std::move(_other.Type))
                , Key(std::move(_other.Key))
                , Value(std::move(_other.Value))
                , TTL(std::move(_other.TTL))
                , Priority(std::move(_other.Priority))
            {
                _Init();
            }

            RecordInfo(const Exchange::IDNSServer::Record& _other)
                : Core::JSON::Container()
            {
                Type = _other.Type;
                Key = _other.Key;
                Value = _other.Value;
                TTL = _other.TTL;
                Priority = _other.Priority;
                _Init();
            }

            RecordInfo& operator=(const RecordInfo& _rhs)
            {
                Type = _rhs.Type;
                Key = _rhs.Key;
                Value = _rhs.Value;
                TTL = _rhs.TTL;
                Priority = _rhs.Priority;
                return (*this);
            }

            RecordInfo& operator=(RecordInfo&& _rhs) noexcept
            {
                Type = std::move(_rhs.Type);
                Key = std::move(_rhs.Key);
                Value = std::move(_rhs.Value);
                TTL = std::move(_rhs.TTL);
                Priority = std::move(_rhs.Priority);
                return (*this);
            }

            RecordInfo& operator=(const Exchange::IDNSServer::Record& _rhs)
            {
                Type = _rhs.Type;
                Key = _rhs.Key;
                Value = _rhs.Value;
                TTL = _rhs.TTL;
                Priority = _rhs.Priority;
                return (*this);
            }

            operator Exchange::IDNSServer::Record() const
            {
                Exchange::IDNSServer::Record _value{};
                _value.Type = Type;
                _value.Key = Key;
                _value.Value = Value;
                _value.TTL = TTL;
                _value.Priority = Priority;
                return (_value);
            }

            ~RecordInfo() = default;

        public:
            bool IsDataValid() const
            {
                return ((Type.IsSet() == true) && (Key.IsSet() == true) && (Value.IsSet() == true) && (TTL.IsSet() == true) && (Priority.IsSet() == true));
            }

        private:
            void _Init()
            {
                Add(_T("type"), &Type);
                Add(_T("key"), &Key);
                Add(_T("value"), &Value);
                Add(_T("ttl"), &TTL);
                Add(_T("priority"), &Priority);
            }

        public:
            Core::JSON::EnumType<Exchange::IDNSServer::Record::type> Type;
            Core::JSON::String Key;
            Core::JSON::String Value;
            Core::JSON::DecUInt32 TTL;
            Core::JSON::DecUInt8 Priority;
        }; // class RecordInfo

        // Method params/result classes
        //

        class AddParamsData : public Core::JSON::Container {
        public:
            AddParamsData()
                : Core::JSON::Container()
            {
                Add(_T("entry"), &Entry);
            }

            AddParamsData(const AddParamsData&) = delete;
            AddParamsData(AddParamsData&&) noexcept  = delete;

            AddParamsData& operator=(const AddParamsData&) = delete;
            AddParamsData& operator=(AddParamsData&&) noexcept  = delete;

            ~AddParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return ((Entry.IsSet() == true) && (Entry.IsDataValid() == true));
            }

        public:
            RecordInfo Entry;
        }; // class AddParamsData

        class CountByTypeParamsData : public Core::JSON::Container {
        public:
            CountByTypeParamsData()
                : Core::JSON::Container()
            {
                Add(_T("designator"), &Designator);
                Add(_T("kind"), &Kind);
            }

            CountByTypeParamsData(const CountByTypeParamsData&) = delete;
            CountByTypeParamsData(CountByTypeParamsData&&) noexcept  = delete;

            CountByTypeParamsData& operator=(const CountByTypeParamsData&) = delete;
            CountByTypeParamsData& operator=(CountByTypeParamsData&&) noexcept  = delete;

            ~CountByTypeParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return ((Designator.IsSet() == true) && (Kind.IsSet() == true));
            }

        public:
            Core::JSON::String Designator;
            Core::JSON::EnumType<Exchange::IDNSServer::Record::type> Kind;
        }; // class CountByTypeParamsData

        class FindByKeyParamsData : public Core::JSON::Container {
        public:
            FindByKeyParamsData()
                : Core::JSON::Container()
            {
                Add(_T("designator"), &Designator);
                Add(_T("key"), &Key);
            }

            FindByKeyParamsData(const FindByKeyParamsData&) = delete;
            FindByKeyParamsData(FindByKeyParamsData&&) noexcept  = delete;

            FindByKeyParamsData& operator=(const FindByKeyParamsData&) = delete;
            FindByKeyParamsData& operator=(FindByKeyParamsData&&) noexcept  = delete;

            ~FindByKeyParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return ((Designator.IsSet() == true) && (Key.IsSet() == true));
            }

        public:
            Core::JSON::String Designator;
            Core::JSON::String Key;
        }; // class FindByKeyParamsData

        class FindByTypeParamsData : public Core::JSON::Container {
        public:
            FindByTypeParamsData()
                : Core::JSON::Container()
            {
                Add(_T("designator"), &Designator);
                Add(_T("kind"), &Kind);
                Add(_T("index"), &Index);
            }

            FindByTypeParamsData(const FindByTypeParamsData&) = delete;
            FindByTypeParamsData(FindByTypeParamsData&&) noexcept  = delete;

            FindByTypeParamsData& operator=(const FindByTypeParamsData&) = delete;
            FindByTypeParamsData& operator=(FindByTypeParamsData&&) noexcept  = delete;

            ~FindByTypeParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return ((Designator.IsSet() == true) && (Kind.IsSet() == true) && (Index.IsSet() == true));
            }

        public:
            Core::JSON::String Designator;
            Core::JSON::EnumType<Exchange::IDNSServer::Record::type> Kind;
            Core::JSON::DecUInt8 Index;
        }; // class FindByTypeParamsData

        class RemoveParamsData : public Core::JSON::Container {
        public:
            RemoveParamsData()
                : Core::JSON::Container()
            {
                Add(_T("record"), &Record);
            }

            RemoveParamsData(const RemoveParamsData&) = delete;
            RemoveParamsData(RemoveParamsData&&) noexcept  = delete;

            RemoveParamsData& operator=(const RemoveParamsData&) = delete;
            RemoveParamsData& operator=(RemoveParamsData&&) noexcept  = delete;

            ~RemoveParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return ((Record.IsSet() == true) && (Record.IsDataValid() == true));
            }

        public:
            RecordInfo Record;
        }; // class RemoveParamsData

    } // namespace DNSServer

    POP_WARNING()

} // namespace JsonData

// Enum conversion handlers
ENUM_CONVERSION_HANDLER(Exchange::IDNSServer::Record::type)

}

