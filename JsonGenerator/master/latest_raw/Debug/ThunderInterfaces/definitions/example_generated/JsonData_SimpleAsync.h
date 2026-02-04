// C++ types for SimpleAsync API.
// Generated automatically from 'ISimpleAsync.h'. DO NOT EDIT.

// Note: This code is inherently not thread safe. If required, proper synchronisation must be added.

#pragma once

#include <core/JSON.h>
#include <example_interfaces/ISimpleAsync.h>

namespace Thunder {

namespace JsonData {

    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    namespace SimpleAsync {

        // Common classes
        //

        class BindParamsInfo : public Core::JSON::Container {
        public:
            BindParamsInfo()
                : Core::JSON::Container()
            {
                Add(_T("address"), &Address);
            }

            BindParamsInfo(const BindParamsInfo&) = delete;
            BindParamsInfo(BindParamsInfo&&) noexcept  = delete;

            BindParamsInfo& operator=(const BindParamsInfo&) = delete;
            BindParamsInfo& operator=(BindParamsInfo&&) noexcept  = delete;

            ~BindParamsInfo() = default;

        public:
            bool IsDataValid() const
            {
                return (((Address.IsSet() == true) && (Address.Value().size() >= 17 && Address.Value().size() <= 17)));
            }

        public:
            Core::JSON::String Address; // Device address
        }; // class BindParamsInfo

        class CompleteParamsInfo : public Core::JSON::Container {
        public:
            CompleteParamsInfo()
                : Core::JSON::Container()
            {
                Add(_T("address"), &Address);
                Add(_T("state"), &State);
            }

            CompleteParamsInfo(const CompleteParamsInfo&) = delete;
            CompleteParamsInfo(CompleteParamsInfo&&) noexcept  = delete;

            CompleteParamsInfo& operator=(const CompleteParamsInfo&) = delete;
            CompleteParamsInfo& operator=(CompleteParamsInfo&&) noexcept  = delete;

            ~CompleteParamsInfo() = default;

        public:
            bool IsDataValid() const
            {
                return (((Address.IsSet() == false) || (Address.Value().size() >= 17 && Address.Value().size() <= 17)) && (State.IsSet() == true));
            }

        public:
            Core::JSON::String Address; // Device address
            Core::JSON::EnumType<Example::ISimpleAsync::state> State; // Result of pairing operation
        }; // class CompleteParamsInfo

        class LinkParamsInfo : public Core::JSON::Container {
        public:
            LinkParamsInfo()
                : Core::JSON::Container()
            {
                Add(_T("address"), &Address);
            }

            LinkParamsInfo(const LinkParamsInfo&) = delete;
            LinkParamsInfo(LinkParamsInfo&&) noexcept  = delete;

            LinkParamsInfo& operator=(const LinkParamsInfo&) = delete;
            LinkParamsInfo& operator=(LinkParamsInfo&&) noexcept  = delete;

            ~LinkParamsInfo() = default;

        public:
            bool IsDataValid() const
            {
                return (((Address.IsSet() == true) && (Address.Value().size() >= 8 && Address.Value().size() <= 8)));
            }

        public:
            Core::JSON::String Address; // Device address
        }; // class LinkParamsInfo

        class MetadataInfo : public Core::JSON::Container {
        public:
            MetadataInfo()
                : Core::JSON::Container()
            {
                Add(_T("value"), &Value);
            }

            MetadataInfo(const MetadataInfo&) = delete;
            MetadataInfo(MetadataInfo&&) noexcept  = delete;

            MetadataInfo& operator=(const MetadataInfo&) = delete;
            MetadataInfo& operator=(MetadataInfo&&) noexcept  = delete;

            ~MetadataInfo() = default;

        public:
            bool IsDataValid() const
            {
                return (Value.IsSet() == true);
            }

        public:
            Core::JSON::String Value; // Device metadata
        }; // class MetadataInfo

        class Record2Info : public Core::JSON::Container {
        public:
            Record2Info()
                : Core::JSON::Container()
            {
                _Init();
            }

            Record2Info(const Record2Info& _other)
                : Core::JSON::Container()
                , Param3(_other.Param3)
                , Param4(_other.Param4)
            {
                _Init();
            }

            Record2Info(Record2Info&& _other) noexcept
                : Core::JSON::Container()
                , Param3(std::move(_other.Param3))
                , Param4(std::move(_other.Param4))
            {
                _Init();
            }

            Record2Info(const Example::ISimpleAsync::Record2& _other)
                : Core::JSON::Container()
            {
                if (_other.param3.IsSet() == true) {
                    Param3.Clear();
                    Param3.Set(true);
                    for (auto const& _element : _other.param3.Value()) { Param3.Add() = _element; }
                }
                if (_other.param4.IsSet() == true) {
                    Param4.Clear();
                    Param4.Set(true);
                    for (auto const& _element : _other.param4.Value()) { Param4.Add() = _element; }
                }
                _Init();
            }

            Record2Info(const Core::OptionalType<Example::ISimpleAsync::Record2>& _other)
                : Core::JSON::Container()
            {
                if (_other.IsSet() == true) {
                    if (_other.Value().param3.IsSet() == true) {
                        Param3.Clear();
                        for (auto const& _element : _other.Value().param3.Value()) { Param3.Add() = _element; }
                    }
                    if (_other.Value().param4.IsSet() == true) {
                        Param4.Clear();
                        for (auto const& _element : _other.Value().param4.Value()) { Param4.Add() = _element; }
                    }
                }
                _Init();
            }

            Record2Info& operator=(const Record2Info& _rhs)
            {
                if (_rhs.Param3.IsSet() == true) {
                    Param3 = _rhs.Param3;
                }
                if (_rhs.Param4.IsSet() == true) {
                    Param4 = _rhs.Param4;
                }
                return (*this);
            }

            Record2Info& operator=(Record2Info&& _rhs) noexcept
            {
                Param3 = std::move(_rhs.Param3);
                Param4 = std::move(_rhs.Param4);
                return (*this);
            }

            Record2Info& operator=(const Example::ISimpleAsync::Record2& _rhs)
            {
                if (_rhs.param3.IsSet() == true) {
                    Param3.Clear();
                    Param3.Set(true);
                    for (auto const& _element : _rhs.param3.Value()) { Param3.Add() = _element; }
                }
                if (_rhs.param4.IsSet() == true) {
                    Param4.Clear();
                    Param4.Set(true);
                    for (auto const& _element : _rhs.param4.Value()) { Param4.Add() = _element; }
                }
                return (*this);
            }

            Record2Info& operator=(const Core::OptionalType<Example::ISimpleAsync::Record2>& _rhs)
            {
                if (_rhs.IsSet() == true) {
                    if (_rhs.Value().param3.IsSet() == true) {
                        Param3.Clear();
                        for (auto const& _element : _rhs.Value().param3.Value()) { Param3.Add() = _element; }
                    }
                    if (_rhs.Value().param4.IsSet() == true) {
                        Param4.Clear();
                        for (auto const& _element : _rhs.Value().param4.Value()) { Param4.Add() = _element; }
                    }
                }
                return (*this);
            }

            operator Example::ISimpleAsync::Record2() const
            {
                Example::ISimpleAsync::Record2 _value{};
                if (Param3.IsSet() == true) {
                    {
                        auto _it = Param3.Elements();
                        while (_it.Next() == true) { _value.param3.Value().push_back(_it.Current()); }
                    }
                }
                if (Param4.IsSet() == true) {
                    {
                        auto _it = Param4.Elements();
                        while (_it.Next() == true) { _value.param4.Value().push_back(_it.Current()); }
                    }
                }
                return (_value);
            }

            ~Record2Info() = default;

        public:
            bool IsDataValid() const
            {
                return (((Param3.IsSet() == false) || (Param3.Length() <= 10)) && ((Param4.IsSet() == false) || (Param4.Length() <= 10)));
            }

        private:
            void _Init()
            {
                Add(_T("param3"), &Param3);
                Add(_T("param4"), &Param4);
            }

        public:
            Core::JSON::ArrayType<Core::JSON::String> Param3;
            Core::JSON::ArrayType<Core::JSON::String> Param4;
        }; // class Record2Info

        class SmallRecordInfo : public Core::JSON::Container {
        public:
            SmallRecordInfo()
                : Core::JSON::Container()
            {
                _Init();
            }

            SmallRecordInfo(const SmallRecordInfo& _other)
                : Core::JSON::Container()
                , Param0(_other.Param0)
                , Param1(_other.Param1)
            {
                _Init();
            }

            SmallRecordInfo(SmallRecordInfo&& _other) noexcept
                : Core::JSON::Container()
                , Param0(std::move(_other.Param0))
                , Param1(std::move(_other.Param1))
            {
                _Init();
            }

            SmallRecordInfo(const Example::ISimpleAsync::SmallRecord& _other)
                : Core::JSON::Container()
            {
                Param0 = _other.param0;
                Param1 = _other.param1;
                _Init();
            }

            SmallRecordInfo& operator=(const SmallRecordInfo& _rhs)
            {
                Param0 = _rhs.Param0;
                Param1 = _rhs.Param1;
                return (*this);
            }

            SmallRecordInfo& operator=(SmallRecordInfo&& _rhs) noexcept
            {
                Param0 = std::move(_rhs.Param0);
                Param1 = std::move(_rhs.Param1);
                return (*this);
            }

            SmallRecordInfo& operator=(const Example::ISimpleAsync::SmallRecord& _rhs)
            {
                Param0 = _rhs.param0;
                Param1 = _rhs.param1;
                return (*this);
            }

            operator Example::ISimpleAsync::SmallRecord() const
            {
                Example::ISimpleAsync::SmallRecord _value{};
                _value.param0 = Param0;
                _value.param1 = Param1;
                return (_value);
            }

            ~SmallRecordInfo() = default;

        public:
            bool IsDataValid() const
            {
                return ((Param0.IsSet() == true) && (Param1.IsSet() == true));
            }

        private:
            void _Init()
            {
                Add(_T("param0"), &Param0);
                Add(_T("param1"), &Param1);
            }

        public:
            Core::JSON::String Param0;
            Core::JSON::Boolean Param1;
        }; // class SmallRecordInfo

        class RecordInfo : public Core::JSON::Container {
        public:
            RecordInfo()
                : Core::JSON::Container()
            {
                _Init();
            }

            RecordInfo(const RecordInfo& _other)
                : Core::JSON::Container()
                , Param0(_other.Param0)
                , Param1(_other.Param1)
                , Param2(_other.Param2)
                , Param3(_other.Param3)
                , Param4(_other.Param4)
                , Param5(_other.Param5)
                , Param6(_other.Param6)
            {
                _Init();
            }

            RecordInfo(RecordInfo&& _other) noexcept
                : Core::JSON::Container()
                , Param0(std::move(_other.Param0))
                , Param1(std::move(_other.Param1))
                , Param2(std::move(_other.Param2))
                , Param3(std::move(_other.Param3))
                , Param4(std::move(_other.Param4))
                , Param5(std::move(_other.Param5))
                , Param6(std::move(_other.Param6))
            {
                _Init();
            }

            RecordInfo(const Example::ISimpleAsync::Record& _other)
                : Core::JSON::Container()
            {
                Param0 = _other.param0;
                Param1.Clear();
                Param1.Set(true);
                for (auto const& _element : _other.param1) { Param1.Add() = _element; }
                Param2.Clear();
                Param2.Set(true);
                for (auto const& _element : _other.param2) { Param2.Add() = _element; }
                if (_other.param3.IsSet() == true) {
                    Param3.Clear();
                    Param3.Set(true);
                    for (auto const& _element : _other.param3.Value()) { Param3.Add() = _element; }
                }
                if (_other.param4.IsSet() == true) {
                    Param4.Clear();
                    Param4.Set(true);
                    for (auto const& _element : _other.param4.Value()) { Param4.Add() = _element; }
                }
                Param5.Set(true);
                Param5 = _other.param5;
                if (_other.param6.IsSet() == true) {
                    Param6.Set(true);
                    Param6 = _other.param6.Value();
                }
                _Init();
            }

            RecordInfo& operator=(const RecordInfo& _rhs)
            {
                Param0 = _rhs.Param0;
                Param1 = _rhs.Param1;
                Param2 = _rhs.Param2;
                if (_rhs.Param3.IsSet() == true) {
                    Param3 = _rhs.Param3;
                }
                if (_rhs.Param4.IsSet() == true) {
                    Param4 = _rhs.Param4;
                }
                Param5 = _rhs.Param5;
                if (_rhs.Param6.IsSet() == true) {
                    Param6 = _rhs.Param6;
                }
                return (*this);
            }

            RecordInfo& operator=(RecordInfo&& _rhs) noexcept
            {
                Param0 = std::move(_rhs.Param0);
                Param1 = std::move(_rhs.Param1);
                Param2 = std::move(_rhs.Param2);
                Param3 = std::move(_rhs.Param3);
                Param4 = std::move(_rhs.Param4);
                Param5 = std::move(_rhs.Param5);
                Param6 = std::move(_rhs.Param6);
                return (*this);
            }

            RecordInfo& operator=(const Example::ISimpleAsync::Record& _rhs)
            {
                Param0 = _rhs.param0;
                Param1.Clear();
                Param1.Set(true);
                for (auto const& _element : _rhs.param1) { Param1.Add() = _element; }
                Param2.Clear();
                Param2.Set(true);
                for (auto const& _element : _rhs.param2) { Param2.Add() = _element; }
                if (_rhs.param3.IsSet() == true) {
                    Param3.Clear();
                    Param3.Set(true);
                    for (auto const& _element : _rhs.param3.Value()) { Param3.Add() = _element; }
                }
                if (_rhs.param4.IsSet() == true) {
                    Param4.Clear();
                    Param4.Set(true);
                    for (auto const& _element : _rhs.param4.Value()) { Param4.Add() = _element; }
                }
                Param5.Set(true);
                Param5 = _rhs.param5;
                if (_rhs.param6.IsSet() == true) {
                    Param6.Set(true);
                    Param6 = _rhs.param6.Value();
                }
                return (*this);
            }

            operator Example::ISimpleAsync::Record() const
            {
                Example::ISimpleAsync::Record _value{};
                _value.param0 = Param0;
                {
                    auto _it = Param1.Elements();
                    while (_it.Next() == true) { _value.param1.push_back(_it.Current()); }
                }
                {
                    auto _it = Param2.Elements();
                    while (_it.Next() == true) { _value.param2.push_back(_it.Current()); }
                }
                if (Param3.IsSet() == true) {
                    {
                        auto _it = Param3.Elements();
                        while (_it.Next() == true) { _value.param3.Value().push_back(_it.Current()); }
                    }
                }
                if (Param4.IsSet() == true) {
                    {
                        auto _it = Param4.Elements();
                        while (_it.Next() == true) { _value.param4.Value().push_back(_it.Current()); }
                    }
                }
                _value.param5 = Param5;
                if (Param6.IsSet() == true) {
                    _value.param6 = Param6;
                }
                return (_value);
            }

            ~RecordInfo() = default;

        public:
            bool IsDataValid() const
            {
                return ((Param0.IsSet() == true) && (((Param1.IsSet() == true) && (Param1.Length() <= 10))) && (((Param2.IsSet() == true) && (Param2.Length() <= 10))) && ((Param3.IsSet() == false) || (Param3.Length() <= 10)) && ((Param4.IsSet() == false) || (Param4.Length() <= 10)) && ((Param5.IsSet() == true) && (Param5.IsDataValid() == true)) && ((Param6.IsSet() == false) || (Param6.IsDataValid() == true)));
            }

        private:
            void _Init()
            {
                Add(_T("param0"), &Param0);
                Add(_T("param1"), &Param1);
                Add(_T("param2"), &Param2);
                Add(_T("param3"), &Param3);
                Add(_T("param4"), &Param4);
                Add(_T("param5"), &Param5);
                Add(_T("param6"), &Param6);
            }

        public:
            Core::JSON::String Param0;
            Core::JSON::ArrayType<Core::JSON::String> Param1;
            Core::JSON::ArrayType<Core::JSON::String> Param2;
            Core::JSON::ArrayType<Core::JSON::String> Param3;
            Core::JSON::ArrayType<Core::JSON::String> Param4;
            SmallRecordInfo Param5;
            SmallRecordInfo Param6;
        }; // class RecordInfo

        class TablesParamsInfo : public Core::JSON::Container {
        public:
            TablesParamsInfo()
                : Core::JSON::Container()
            {
                Add(_T("fill"), &Fill);
            }

            TablesParamsInfo(const TablesParamsInfo&) = delete;
            TablesParamsInfo(TablesParamsInfo&&) noexcept  = delete;

            TablesParamsInfo& operator=(const TablesParamsInfo&) = delete;
            TablesParamsInfo& operator=(TablesParamsInfo&&) noexcept  = delete;

            ~TablesParamsInfo() = default;

        public:
            bool IsDataValid() const
            {
                return (Fill.IsSet() == true);
            }

        public:
            Core::JSON::Boolean Fill;
        }; // class TablesParamsInfo

        // Method params/result classes
        //

        class BindingChangedParamsData : public Core::JSON::Container {
        public:
            BindingChangedParamsData()
                : Core::JSON::Container()
            {
                Add(_T("bound"), &Bound);
            }

            BindingChangedParamsData(const BindingChangedParamsData&) = delete;
            BindingChangedParamsData(BindingChangedParamsData&&) noexcept  = delete;

            BindingChangedParamsData& operator=(const BindingChangedParamsData&) = delete;
            BindingChangedParamsData& operator=(BindingChangedParamsData&&) noexcept  = delete;

            ~BindingChangedParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return (Bound.IsSet() == true);
            }

        public:
            Core::JSON::Boolean Bound; // Signals completion of the Connect method
        }; // class BindingChangedParamsData

        class ConnectParamsData : public Core::JSON::Container {
        public:
            ConnectParamsData()
                : Core::JSON::Container()
                , Timeout(1000)
            {
                Add(_T("address"), &Address);
                Add(_T("timeout"), &Timeout);
                Add(_T("id"), &Cb);
            }

            ConnectParamsData(const ConnectParamsData&) = delete;
            ConnectParamsData(ConnectParamsData&&) noexcept  = delete;

            ConnectParamsData& operator=(const ConnectParamsData&) = delete;
            ConnectParamsData& operator=(ConnectParamsData&&) noexcept  = delete;

            ~ConnectParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return (((Address.IsSet() == false) || (Address.Value().size() >= 17 && Address.Value().size() <= 17)) && (Cb.IsSet() == true));
            }

        public:
            Core::JSON::String Address; // Device address
            Core::JSON::DecUInt16 Timeout; // Maximum time allowed for connecting in milliseconds
            Core::JSON::String Cb; // Connects to a server
        }; // class ConnectParamsData

        class StatusChangedParamsData : public Core::JSON::Container {
        public:
            StatusChangedParamsData()
                : Core::JSON::Container()
            {
                Add(_T("address"), &Address);
                Add(_T("linked"), &Linked);
            }

            StatusChangedParamsData(const StatusChangedParamsData&) = delete;
            StatusChangedParamsData(StatusChangedParamsData&&) noexcept  = delete;

            StatusChangedParamsData& operator=(const StatusChangedParamsData&) = delete;
            StatusChangedParamsData& operator=(StatusChangedParamsData&&) noexcept  = delete;

            ~StatusChangedParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return ((((Address.IsSet() == true) && (Address.Length() >= 6 && Address.Length() <= 6))) && (Linked.IsSet() == true));
            }

        public:
            Core::JSON::ArrayType<Core::JSON::DecUInt8> Address; // Device address
            Core::JSON::Boolean Linked; // Denotes if device is linked
        }; // class StatusChangedParamsData

        class Tables2ResultData : public Core::JSON::Container {
        public:
            Tables2ResultData()
                : Core::JSON::Container()
            {
                Add(_T("stringTables"), &StringTables);
                Add(_T("intTables"), &IntTables);
            }

            Tables2ResultData(const Tables2ResultData&) = delete;
            Tables2ResultData(Tables2ResultData&&) noexcept  = delete;

            Tables2ResultData& operator=(const Tables2ResultData&) = delete;
            Tables2ResultData& operator=(Tables2ResultData&&) noexcept  = delete;

            ~Tables2ResultData() = default;

        public:
            bool IsDataValid() const
            {
                return ((((StringTables.IsSet() == true) && (StringTables.Length() <= 10))) && (((IntTables.IsSet() == true) && (IntTables.Length() <= 10))));
            }

        public:
            Core::JSON::ArrayType<Core::JSON::String> StringTables;
            Core::JSON::ArrayType<Core::JSON::DecUInt8> IntTables;
        }; // class Tables2ResultData

        class Tables5ResultData : public Core::JSON::Container {
        public:
            Tables5ResultData()
                : Core::JSON::Container()
            {
                Add(_T("stringTables"), &StringTables);
                Add(_T("intTables"), &IntTables);
            }

            Tables5ResultData(const Tables5ResultData&) = delete;
            Tables5ResultData(Tables5ResultData&&) noexcept  = delete;

            Tables5ResultData& operator=(const Tables5ResultData&) = delete;
            Tables5ResultData& operator=(Tables5ResultData&&) noexcept  = delete;

            ~Tables5ResultData() = default;

        public:
            bool IsDataValid() const
            {
                return ((StringTables.IsSet() == true) && (IntTables.IsSet() == true));
            }

        public:
            Core::JSON::ArrayType<Core::JSON::String> StringTables;
            Core::JSON::ArrayType<Core::JSON::DecUInt32> IntTables;
        }; // class Tables5ResultData

    } // namespace SimpleAsync

    POP_WARNING()

} // namespace JsonData

// Enum conversion handlers
ENUM_CONVERSION_HANDLER(Example::ISimpleAsync::state)

}

