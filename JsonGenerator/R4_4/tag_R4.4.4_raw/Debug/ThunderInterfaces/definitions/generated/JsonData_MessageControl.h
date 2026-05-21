// C++ classes for MessageControl API JSON-RPC API.
// Generated automatically from 'IMessageControl.h'. DO NOT EDIT.

// Note: This code is inherently not thread safe. If required, proper synchronisation must be added.

#pragma once

#include <core/JSON.h>
#include <interfaces/IMessageControl.h>

namespace WPEFramework {

namespace JsonData {

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

            ControlInfo& operator=(const ControlInfo& _rhs)
            {
                Type = _rhs.Type;
                Category = _rhs.Category;
                Module = _rhs.Module;
                Enabled = _rhs.Enabled;
                return (*this);
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

            bool IsValid() const
            {
                return (true);
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

} // namespace JsonData

// Enum conversion handlers
ENUM_CONVERSION_HANDLER(Exchange::IMessageControl::messagetype)

}

