// C++ classes for WebKit Browser API JSON-RPC API.
// Generated automatically from 'WebKitBrowser.json'. DO NOT EDIT.

// Note: This code is inherently not thread safe. If required, proper synchronisation must be added.

#pragma once

#include <core/JSON.h>

namespace WPEFramework {

namespace JsonData {

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

            bool IsValid() const
            {
                return (true);
            }

            DeleteParamsData(const DeleteParamsData&) = delete;
            DeleteParamsData& operator=(const DeleteParamsData&) = delete;

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

            HeadersData& operator=(const HeadersData& _rhs)
            {
                Name = _rhs.Name;
                Value = _rhs.Value;
                return (*this);
            }

            bool IsValid() const
            {
                return (true);
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

} // namespace JsonData

}

