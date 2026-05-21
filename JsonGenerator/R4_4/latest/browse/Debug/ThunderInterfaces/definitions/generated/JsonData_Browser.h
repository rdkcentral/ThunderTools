// C++ classes for Browser API JSON-RPC API.
// Generated automatically from 'Browser.json'. DO NOT EDIT.

// Note: This code is inherently not thread safe. If required, proper synchronisation must be added.

#pragma once

#include <core/JSON.h>
#include <core/Enumerate.h>

namespace WPEFramework {

namespace JsonData {

    namespace Browser {

        // Common enums
        //

        // Current browser visibility
        enum class VisibilityType : uint8_t {
            VISIBLE,
            HIDDEN
        };

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

        class UrlchangeParamsData : public Core::JSON::Container {
        public:
            UrlchangeParamsData()
                : Core::JSON::Container()
            {
                Add(_T("url"), &Url);
                Add(_T("loaded"), &Loaded);
            }

            bool IsValid() const
            {
                return (true);
            }

            UrlchangeParamsData(const UrlchangeParamsData&) = delete;
            UrlchangeParamsData& operator=(const UrlchangeParamsData&) = delete;

        public:
            Core::JSON::String Url; // The URL that has been loaded or requested
            Core::JSON::Boolean Loaded; // Determines if the URL has just been loaded (true) or if URL change has been requested (false)
        }; // class UrlchangeParamsData

        class VisibilitychangeParamsData : public Core::JSON::Container {
        public:
            VisibilitychangeParamsData()
                : Core::JSON::Container()
            {
                Add(_T("hidden"), &Hidden);
            }

            bool IsValid() const
            {
                return (true);
            }

            VisibilitychangeParamsData(const VisibilitychangeParamsData&) = delete;
            VisibilitychangeParamsData& operator=(const VisibilitychangeParamsData&) = delete;

        public:
            Core::JSON::Boolean Hidden; // Determines if the browser has been hidden (true) or made visible (false)
        }; // class VisibilitychangeParamsData

    } // namespace Browser

} // namespace JsonData

// Enum conversion handlers
ENUM_CONVERSION_HANDLER(JsonData::Browser::VisibilityType)

}

