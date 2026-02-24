// C++ types for MessageControl API.
// Generated automatically from 'IMessageControl.h'. DO NOT EDIT.

// Note: This code is inherently not thread safe. If required, proper synchronisation must be added.

#pragma once

#include <core/JSON.h>
#include <interfaces/IMessageControl.h>

namespace Thunder {

namespace JsonData {

    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    namespace MessageControl {

        // Common classes
        //

        class ControlInfo : public Core::JSON::Container {
        public:
            ControlInfo()
                : Core::JSON::Container()
            {
                _Init();
            }

            ControlInfo(const ControlInfo& _other)
                : Core::JSON::Container()
                , Type(_other.Type)
                , Category(_other.Category)
                , Module(_other.Module)
                , Enabled(_other.Enabled)
            {
                _Init();
            }

            ControlInfo(ControlInfo&& _other) noexcept
                : Core::JSON::Container()
                , Type(std::move(_other.Type))
                , Category(std::move(_other.Category))
                , Module(std::move(_other.Module))
                , Enabled(std::move(_other.Enabled))
            {
                _Init();
            }

            ControlInfo(const Exchange::IMessageControl::Control& _other)
                : Core::JSON::Container()
            {
                Type = _other.type;
                Category = _other.category;
                Module = _other.module;
                Enabled = _other.enabled;
                _Init();
            }

            ControlInfo& operator=(const ControlInfo& _rhs)
            {
                Type = _rhs.Type;
                Category = _rhs.Category;
                Module = _rhs.Module;
                Enabled = _rhs.Enabled;
                return (*this);
            }

            ControlInfo& operator=(ControlInfo&& _rhs) noexcept
            {
                Type = std::move(_rhs.Type);
                Category = std::move(_rhs.Category);
                Module = std::move(_rhs.Module);
                Enabled = std::move(_rhs.Enabled);
                return (*this);
            }

            ControlInfo& operator=(const Exchange::IMessageControl::Control& _rhs)
            {
                Type = _rhs.type;
                Category = _rhs.category;
                Module = _rhs.module;
                Enabled = _rhs.enabled;
                return (*this);
            }

            operator Exchange::IMessageControl::Control() const
            {
                Exchange::IMessageControl::Control _value{};
                _value.type = Type;
                _value.category = Category;
                _value.module = Module;
                _value.enabled = Enabled;
                return (_value);
            }

            ~ControlInfo() = default;

        public:
            bool IsDataValid() const
            {
                return ((Type.IsSet() == true) && (Category.IsSet() == true) && (Module.IsSet() == true) && (Enabled.IsSet() == true));
            }

        private:
            void _Init()
            {
                Add(_T("type"), &Type);
                Add(_T("category"), &Category);
                Add(_T("module"), &Module);
                Add(_T("enabled"), &Enabled);
            }

        public:
            Core::JSON::EnumType<Exchange::IMessageControl::messagetype> Type; // Type of message
            Core::JSON::String Category; // Name of the message category
            Core::JSON::String Module; // Name of the module the message is originating from
            Core::JSON::Boolean Enabled; // Denotes if the control is enabled (true) or disabled (false)
        }; // class ControlInfo

        // Method params/result classes
        //

    } // namespace MessageControl

    POP_WARNING()

} // namespace JsonData

// Enum conversion handlers
ENUM_CONVERSION_HANDLER(Exchange::IMessageControl::messagetype)

}

