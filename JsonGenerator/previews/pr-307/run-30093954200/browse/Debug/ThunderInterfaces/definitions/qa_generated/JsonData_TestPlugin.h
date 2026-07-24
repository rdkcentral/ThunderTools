// C++ types for Test API.
// Generated automatically from 'ITestPlugin.h'. DO NOT EDIT.

// Note: This code is inherently not thread safe. If required, proper synchronisation must be added.

#pragma once

#include <core/JSON.h>
#include <qa_interfaces/ITestPlugin.h>

namespace Thunder {

namespace JsonData {

    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    namespace TestPlugin {

        // Method params/result classes
        //

        class EchoParamsData : public Core::JSON::Container {
        public:
            EchoParamsData()
                : Core::JSON::Container()
            {
                Add(_T("input"), &Input);
            }

            EchoParamsData(const EchoParamsData&) = delete;
            EchoParamsData(EchoParamsData&&) noexcept  = delete;

            EchoParamsData& operator=(const EchoParamsData&) = delete;
            EchoParamsData& operator=(EchoParamsData&&) noexcept  = delete;

            ~EchoParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return (Input.IsSet() == true);
            }

        public:
            Core::JSON::String Input;
        }; // class EchoParamsData

        class GreetParamsData : public Core::JSON::Container {
        public:
            GreetParamsData()
                : Core::JSON::Container()
            {
                Add(_T("name"), &Name);
            }

            GreetParamsData(const GreetParamsData&) = delete;
            GreetParamsData(GreetParamsData&&) noexcept  = delete;

            GreetParamsData& operator=(const GreetParamsData&) = delete;
            GreetParamsData& operator=(GreetParamsData&&) noexcept  = delete;

            ~GreetParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return (Name.IsSet() == true);
            }

        public:
            Core::JSON::String Name;
        }; // class GreetParamsData

        class OnGreetingParamsData : public Core::JSON::Container {
        public:
            OnGreetingParamsData()
                : Core::JSON::Container()
            {
                Add(_T("message"), &Message);
            }

            OnGreetingParamsData(const OnGreetingParamsData&) = delete;
            OnGreetingParamsData(OnGreetingParamsData&&) noexcept  = delete;

            OnGreetingParamsData& operator=(const OnGreetingParamsData&) = delete;
            OnGreetingParamsData& operator=(OnGreetingParamsData&&) noexcept  = delete;

            ~OnGreetingParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return (Message.IsSet() == true);
            }

        public:
            Core::JSON::String Message;
        }; // class OnGreetingParamsData

    } // namespace TestPlugin

    POP_WARNING()

} // namespace JsonData

}

