// C++ types for WebKit Browser API.
// Generated automatically from 'WebKitBrowser.json'. DO NOT EDIT.

// Note: This code is inherently not thread safe. If required, proper synchronisation must be added.

#pragma once

#include <core/JSON.h>

namespace WPEFramework {

namespace JsonData {

    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    namespace WebKitBrowser {

        // Method params/result classes
        //

        class DeleteParamsData : public Core::JSON::Container {
        public:
            DeleteParamsData()
                : Core::JSON::Container()
            {
                Add(_T("path"), &Path);
            }

            DeleteParamsData(const DeleteParamsData&) = delete;
            DeleteParamsData(DeleteParamsData&&) noexcept  = delete;

            DeleteParamsData& operator=(const DeleteParamsData&) = delete;
            DeleteParamsData& operator=(DeleteParamsData&&) noexcept  = delete;

            ~DeleteParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return (Path.IsSet() == true);
            }

        public:
            Core::JSON::String Path; // Path to directory (within the persistent storage) to delete contents of
        }; // class DeleteParamsData

        class HeadersData : public Core::JSON::Container {
        public:
            HeadersData()
                : Core::JSON::Container()
            {
                _Init();
            }

            HeadersData(const HeadersData& _other)
                : Core::JSON::Container()
                , Name(_other.Name)
                , Value(_other.Value)
            {
                _Init();
            }

            HeadersData(HeadersData&& _other) noexcept
                : Core::JSON::Container()
                , Name(std::move(_other.Name))
                , Value(std::move(_other.Value))
            {
                _Init();
            }

            HeadersData& operator=(const HeadersData& _rhs)
            {
                Name = _rhs.Name;
                Value = _rhs.Value;
                return (*this);
            }

            HeadersData& operator=(HeadersData&& _rhs) noexcept
            {
                Name = std::move(_rhs.Name);
                Value = std::move(_rhs.Value);
                return (*this);
            }

            ~HeadersData() = default;

        public:
            bool IsDataValid() const
            {
                return ((Name.IsSet() == true) && (Value.IsSet() == true));
            }

        private:
            void _Init()
            {
                Add(_T("name"), &Name);
                Add(_T("value"), &Value);
            }

        public:
            Core::JSON::String Name; // Header name
            Core::JSON::String Value; // Header value
        }; // class HeadersData

    } // namespace WebKitBrowser

    POP_WARNING()

} // namespace JsonData

}

