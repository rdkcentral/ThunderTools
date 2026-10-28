// C++ types for SimpleRichError API.
// Generated automatically from 'ISimpleRichError.h'. DO NOT EDIT.

// Note: This code is inherently not thread safe. If required, proper synchronisation must be added.

#pragma once

#include <core/JSON.h>
#include <interfaces/ISimpleRichError.h>

namespace WPEFramework {

namespace JsonData {

    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    namespace SimpleRichError {

        // Method params/result classes
        //

        class ErrorData : public Core::JSON::Container {
        public:
            class DiagnosticData : public Core::JSON::Container {
            public:
                DiagnosticData()
                    : Core::JSON::Container()
                {
                    _Init();
                }

                DiagnosticData(const DiagnosticData& _other)
                    : Core::JSON::Container()
                    , Reason(_other.Reason)
                    , Water_temperature(_other.Water_temperature)
                    , Water_level(_other.Water_level)
                    , Brew_pressure(_other.Brew_pressure)
                    , Info(_other.Info)
                {
                    _Init();
                }

                DiagnosticData(DiagnosticData&& _other) noexcept
                    : Core::JSON::Container()
                    , Reason(std::move(_other.Reason))
                    , Water_temperature(std::move(_other.Water_temperature))
                    , Water_level(std::move(_other.Water_level))
                    , Brew_pressure(std::move(_other.Brew_pressure))
                    , Info(std::move(_other.Info))
                {
                    _Init();
                }

                DiagnosticData(const Exchange::ISimpleRichError::Diagnostic& _other)
                    : Core::JSON::Container()
                {
                    Reason = _other.reason;
                    Water_temperature = _other.water_temperature;
                    Water_level = _other.water_level;
                    Brew_pressure = _other.brew_pressure;
                    if (_other.info.IsSet() == true) {
                        Info = _other.info.Value();
                    }
                    _Init();
                }

                DiagnosticData(const Core::OptionalType<Exchange::ISimpleRichError::Diagnostic>& _other)
                    : Core::JSON::Container()
                {
                    if (_other.IsSet() == true) {
                        Reason = _other.Value().reason;
                        Water_temperature = _other.Value().water_temperature;
                        Water_level = _other.Value().water_level;
                        Brew_pressure = _other.Value().brew_pressure;
                        if (_other.Value().info.IsSet() == true) {
                            Info = _other.Value().info.Value();
                        }
                    }
                    _Init();
                }

                DiagnosticData& operator=(const DiagnosticData& _rhs)
                {
                    Reason = _rhs.Reason;
                    Water_temperature = _rhs.Water_temperature;
                    Water_level = _rhs.Water_level;
                    Brew_pressure = _rhs.Brew_pressure;
                    if (_rhs.Info.IsSet() == true) {
                        Info = _rhs.Info;
                    }
                    return (*this);
                }

                DiagnosticData& operator=(DiagnosticData&& _rhs) noexcept
                {
                    Reason = std::move(_rhs.Reason);
                    Water_temperature = std::move(_rhs.Water_temperature);
                    Water_level = std::move(_rhs.Water_level);
                    Brew_pressure = std::move(_rhs.Brew_pressure);
                    Info = std::move(_rhs.Info);
                    return (*this);
                }

                DiagnosticData& operator=(const Exchange::ISimpleRichError::Diagnostic& _rhs)
                {
                    Reason = _rhs.reason;
                    Water_temperature = _rhs.water_temperature;
                    Water_level = _rhs.water_level;
                    Brew_pressure = _rhs.brew_pressure;
                    if (_rhs.info.IsSet() == true) {
                        Info = _rhs.info.Value();
                    }
                    return (*this);
                }

                DiagnosticData& operator=(const Core::OptionalType<Exchange::ISimpleRichError::Diagnostic>& _rhs)
                {
                    if (_rhs.IsSet() == true) {
                        Reason = _rhs.Value().reason;
                        Water_temperature = _rhs.Value().water_temperature;
                        Water_level = _rhs.Value().water_level;
                        Brew_pressure = _rhs.Value().brew_pressure;
                        if (_rhs.Value().info.IsSet() == true) {
                            Info = _rhs.Value().info.Value();
                        }
                    }
                    return (*this);
                }

                operator Exchange::ISimpleRichError::Diagnostic() const
                {
                    Exchange::ISimpleRichError::Diagnostic _value{};
                    _value.reason = Reason;
                    _value.water_temperature = Water_temperature;
                    _value.water_level = Water_level;
                    _value.brew_pressure = Brew_pressure;
                    if (Info.IsSet() == true) {
                        _value.info = Info;
                    }
                    return (_value);
                }

                ~DiagnosticData() = default;

            public:
                bool IsDataValid() const
                {
                    return ((Reason.IsSet() == true) && (Water_temperature.IsSet() == true) && (Water_level.IsSet() == true) && (Brew_pressure.IsSet() == true));
                }

            private:
                void _Init()
                {
                    Add(_T("reason"), &Reason);
                    Add(_T("water_temperature"), &Water_temperature);
                    Add(_T("water_level"), &Water_level);
                    Add(_T("brew_pressure"), &Brew_pressure);
                    Add(_T("info"), &Info);
                }

            public:
                Core::JSON::EnumType<Exchange::ISimpleRichError::Diagnostic::failreason> Reason;
                Core::JSON::DecUInt8 Water_temperature;
                Core::JSON::DecUInt8 Water_level;
                Core::JSON::DecUInt8 Brew_pressure;
                Core::JSON::String Info;
            }; // class DiagnosticData

            ErrorData()
                : Core::JSON::Container()
            {
                _Init();
            }

            ErrorData(const ErrorData& _other)
                : Core::JSON::Container()
                , Code(_other.Code)
                , Message(_other.Message)
                , Data(_other.Data)
            {
                _Init();
            }

            ErrorData(ErrorData&& _other) noexcept
                : Core::JSON::Container()
                , Code(std::move(_other.Code))
                , Message(std::move(_other.Message))
                , Data(std::move(_other.Data))
            {
                _Init();
            }

            ErrorData(const Exchange::ISimpleRichError::Error& _other)
                : Core::JSON::Container()
            {
                if (_other.code.IsSet() == true) {
                    Code = _other.code.Value();
                }
                if (_other.message.IsSet() == true) {
                    Message = _other.message.Value();
                }
                if (_other.data.IsSet() == true) {
                    Data.Set(true);
                    Data = _other.data.Value();
                }
                _Init();
            }

            ErrorData(const Core::OptionalType<Exchange::ISimpleRichError::Error>& _other)
                : Core::JSON::Container()
            {
                if (_other.IsSet() == true) {
                    if (_other.Value().code.IsSet() == true) {
                        Code = _other.Value().code.Value();
                    }
                    if (_other.Value().message.IsSet() == true) {
                        Message = _other.Value().message.Value();
                    }
                    if (_other.Value().data.IsSet() == true) {
                        Data = _other.Value().data.Value();
                    }
                }
                _Init();
            }

            ErrorData& operator=(const ErrorData& _rhs)
            {
                if (_rhs.Code.IsSet() == true) {
                    Code = _rhs.Code;
                }
                if (_rhs.Message.IsSet() == true) {
                    Message = _rhs.Message;
                }
                if (_rhs.Data.IsSet() == true) {
                    Data = _rhs.Data;
                }
                return (*this);
            }

            ErrorData& operator=(ErrorData&& _rhs) noexcept
            {
                Code = std::move(_rhs.Code);
                Message = std::move(_rhs.Message);
                Data = std::move(_rhs.Data);
                return (*this);
            }

            ErrorData& operator=(const Exchange::ISimpleRichError::Error& _rhs)
            {
                if (_rhs.code.IsSet() == true) {
                    Code = _rhs.code.Value();
                }
                if (_rhs.message.IsSet() == true) {
                    Message = _rhs.message.Value();
                }
                if (_rhs.data.IsSet() == true) {
                    Data.Set(true);
                    Data = _rhs.data.Value();
                }
                return (*this);
            }

            ErrorData& operator=(const Core::OptionalType<Exchange::ISimpleRichError::Error>& _rhs)
            {
                if (_rhs.IsSet() == true) {
                    if (_rhs.Value().code.IsSet() == true) {
                        Code = _rhs.Value().code.Value();
                    }
                    if (_rhs.Value().message.IsSet() == true) {
                        Message = _rhs.Value().message.Value();
                    }
                    if (_rhs.Value().data.IsSet() == true) {
                        Data = _rhs.Value().data.Value();
                    }
                }
                return (*this);
            }

            operator Exchange::ISimpleRichError::Error() const
            {
                Exchange::ISimpleRichError::Error _value{};
                if (Code.IsSet() == true) {
                    _value.code = Code;
                }
                if (Message.IsSet() == true) {
                    _value.message = Message;
                }
                if (Data.IsSet() == true) {
                    _value.data = Data;
                }
                return (_value);
            }

            ~ErrorData() = default;

        public:
            bool IsDataValid() const
            {
                return ((Data.IsSet() == false) || (Data.IsDataValid() == true));
            }

        private:
            void _Init()
            {
                Add(_T("code"), &Code);
                Add(_T("message"), &Message);
                Add(_T("data"), &Data);
            }

        public:
            Core::JSON::DecSInt32 Code; // Type of the error
            Core::JSON::String Message; // A short message describing the error
            ErrorData::DiagnosticData Data; // additional information about the error
        }; // class ErrorData

        class MakeCoffeeParamsData : public Core::JSON::Container {
        public:
            MakeCoffeeParamsData()
                : Core::JSON::Container()
            {
                Add(_T("type"), &Type);
            }

            MakeCoffeeParamsData(const MakeCoffeeParamsData&) = delete;
            MakeCoffeeParamsData(MakeCoffeeParamsData&&) noexcept  = delete;

            MakeCoffeeParamsData& operator=(const MakeCoffeeParamsData&) = delete;
            MakeCoffeeParamsData& operator=(MakeCoffeeParamsData&&) noexcept  = delete;

            ~MakeCoffeeParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return (Type.IsSet() == true);
            }

        public:
            Core::JSON::EnumType<Exchange::ISimpleRichError::coffeetype> Type; // kind of drink to make
        }; // class MakeCoffeeParamsData

        class ErrorDetailsInstance445be54d48a2e629Data : public Core::JSON::Container {
        public:
            ErrorDetailsInstance445be54d48a2e629Data()
                : Core::JSON::Container()
            {
                _Init();
            }

            ErrorDetailsInstance445be54d48a2e629Data(const ErrorDetailsInstance445be54d48a2e629Data& _other)
                : Core::JSON::Container()
                , Code(_other.Code)
                , Message(_other.Message)
            {
                _Init();
            }

            ErrorDetailsInstance445be54d48a2e629Data(ErrorDetailsInstance445be54d48a2e629Data&& _other) noexcept
                : Core::JSON::Container()
                , Code(std::move(_other.Code))
                , Message(std::move(_other.Message))
            {
                _Init();
            }

            ErrorDetailsInstance445be54d48a2e629Data(const Core::ErrorDetails<void>& _other)
                : Core::JSON::Container()
            {
                if (_other.code.IsSet() == true) {
                    Code = _other.code.Value();
                }
                if (_other.message.IsSet() == true) {
                    Message = _other.message.Value();
                }
                _Init();
            }

            ErrorDetailsInstance445be54d48a2e629Data(const Core::OptionalType<Core::ErrorDetails<void>>& _other)
                : Core::JSON::Container()
            {
                if (_other.IsSet() == true) {
                    if (_other.Value().code.IsSet() == true) {
                        Code = _other.Value().code.Value();
                    }
                    if (_other.Value().message.IsSet() == true) {
                        Message = _other.Value().message.Value();
                    }
                }
                _Init();
            }

            ErrorDetailsInstance445be54d48a2e629Data& operator=(const ErrorDetailsInstance445be54d48a2e629Data& _rhs)
            {
                if (_rhs.Code.IsSet() == true) {
                    Code = _rhs.Code;
                }
                if (_rhs.Message.IsSet() == true) {
                    Message = _rhs.Message;
                }
                return (*this);
            }

            ErrorDetailsInstance445be54d48a2e629Data& operator=(ErrorDetailsInstance445be54d48a2e629Data&& _rhs) noexcept
            {
                Code = std::move(_rhs.Code);
                Message = std::move(_rhs.Message);
                return (*this);
            }

            ErrorDetailsInstance445be54d48a2e629Data& operator=(const Core::ErrorDetails<void>& _rhs)
            {
                if (_rhs.code.IsSet() == true) {
                    Code = _rhs.code.Value();
                }
                if (_rhs.message.IsSet() == true) {
                    Message = _rhs.message.Value();
                }
                return (*this);
            }

            ErrorDetailsInstance445be54d48a2e629Data& operator=(const Core::OptionalType<Core::ErrorDetails<void>>& _rhs)
            {
                if (_rhs.IsSet() == true) {
                    if (_rhs.Value().code.IsSet() == true) {
                        Code = _rhs.Value().code.Value();
                    }
                    if (_rhs.Value().message.IsSet() == true) {
                        Message = _rhs.Value().message.Value();
                    }
                }
                return (*this);
            }

            operator Core::ErrorDetails<void>() const
            {
                Core::ErrorDetails<void> _value{};
                if (Code.IsSet() == true) {
                    _value.code = Code;
                }
                if (Message.IsSet() == true) {
                    _value.message = Message;
                }
                return (_value);
            }

            ~ErrorDetailsInstance445be54d48a2e629Data() = default;

        public:
            bool IsDataValid() const
            {
                return (true);
            }

        private:
            void _Init()
            {
                Add(_T("code"), &Code);
                Add(_T("message"), &Message);
            }

        public:
            Core::JSON::DecSInt32 Code; // Type of the error
            Core::JSON::String Message; // A short message describing the error
        }; // class ErrorDetailsInstance445be54d48a2e629Data

    } // namespace SimpleRichError

    POP_WARNING()

} // namespace JsonData

// Enum conversion handlers
ENUM_CONVERSION_HANDLER(Exchange::ISimpleRichError::coffeetype)
ENUM_CONVERSION_HANDLER(Exchange::ISimpleRichError::Diagnostic::failreason)

}

