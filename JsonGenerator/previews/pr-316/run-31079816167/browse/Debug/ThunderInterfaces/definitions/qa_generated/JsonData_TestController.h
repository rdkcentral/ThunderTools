// C++ types for Test Controller API.
// Generated automatically from 'TestController.json'. DO NOT EDIT.

// Note: This code is inherently not thread safe. If required, proper synchronisation must be added.

#pragma once

#include <core/JSON.h>

namespace Thunder {

namespace JsonData {

    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    namespace TestController {

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
            Core::JSON::String Description; // Test description
        }; // class DescriptionData

        class RunParamsData : public Core::JSON::Container {
        public:
            RunParamsData()
                : Core::JSON::Container()
            {
                Add(_T("category"), &Category);
                Add(_T("test"), &Test);
                Add(_T("args"), &Args);
            }

            RunParamsData(const RunParamsData&) = delete;
            RunParamsData(RunParamsData&&) noexcept  = delete;

            RunParamsData& operator=(const RunParamsData&) = delete;
            RunParamsData& operator=(RunParamsData&&) noexcept  = delete;

            ~RunParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return ((Category.IsSet() == true) && (Test.IsSet() == true) && (Args.IsSet() == true));
            }

        public:
            Core::JSON::String Category; // Test category name, if omitted: all tests are executed
            Core::JSON::String Test; // Test name, if omitted: all tests of category are executed
            Core::JSON::String Args; // The test arguments in JSON format
        }; // class RunParamsData

        class RunResultDataElem : public Core::JSON::Container {
        public:
            RunResultDataElem()
                : Core::JSON::Container()
            {
                _Init();
            }

            RunResultDataElem(const RunResultDataElem& _other)
                : Core::JSON::Container()
                , Test(_other.Test)
                , Status(_other.Status)
            {
                _Init();
            }

            RunResultDataElem(RunResultDataElem&& _other) noexcept
                : Core::JSON::Container()
                , Test(std::move(_other.Test))
                , Status(std::move(_other.Status))
            {
                _Init();
            }

            RunResultDataElem& operator=(const RunResultDataElem& _rhs)
            {
                Test = _rhs.Test;
                Status = _rhs.Status;
                return (*this);
            }

            RunResultDataElem& operator=(RunResultDataElem&& _rhs) noexcept
            {
                Test = std::move(_rhs.Test);
                Status = std::move(_rhs.Status);
                return (*this);
            }

            ~RunResultDataElem() = default;

        public:
            bool IsDataValid() const
            {
                return ((Test.IsSet() == true) && (Status.IsSet() == true));
            }

        private:
            void _Init()
            {
                Add(_T("test"), &Test);
                Add(_T("status"), &Status);
            }

        public:
            Core::JSON::String Test; // Test name
            Core::JSON::String Status; // Test status
        }; // class RunResultDataElem

    } // namespace TestController

    POP_WARNING()

} // namespace JsonData

}

