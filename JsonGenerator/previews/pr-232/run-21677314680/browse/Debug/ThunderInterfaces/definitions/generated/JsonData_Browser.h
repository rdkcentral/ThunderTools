// C++ types for Browser API.
// Generated automatically from 'Browser.json'. DO NOT EDIT.

// Note: This code is inherently not thread safe. If required, proper synchronisation must be added.

#pragma once

#include <core/JSON.h>
#include <core/Enumerate.h>

namespace Thunder {

namespace JsonData {

    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

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

        class UrlchangeParamsData : public Core::JSON::Container {
        public:
            UrlchangeParamsData()
                : Core::JSON::Container()
            {
                Add(_T("url"), &Url);
                Add(_T("loaded"), &Loaded);
            }

            UrlchangeParamsData(const UrlchangeParamsData&) = delete;
            UrlchangeParamsData(UrlchangeParamsData&&) noexcept  = delete;

            UrlchangeParamsData& operator=(const UrlchangeParamsData&) = delete;
            UrlchangeParamsData& operator=(UrlchangeParamsData&&) noexcept  = delete;

            ~UrlchangeParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return ((Url.IsSet() == true) && (Loaded.IsSet() == true));
            }

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

            VisibilitychangeParamsData(const VisibilitychangeParamsData&) = delete;
            VisibilitychangeParamsData(VisibilitychangeParamsData&&) noexcept  = delete;

            VisibilitychangeParamsData& operator=(const VisibilitychangeParamsData&) = delete;
            VisibilitychangeParamsData& operator=(VisibilitychangeParamsData&&) noexcept  = delete;

            ~VisibilitychangeParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return (Hidden.IsSet() == true);
            }

        public:
            Core::JSON::Boolean Hidden; // Determines if the browser has been hidden (true) or made visible (false)
        }; // class VisibilitychangeParamsData

    } // namespace Browser

    POP_WARNING()

} // namespace JsonData

// Enum conversion handlers
ENUM_CONVERSION_HANDLER(JsonData::Browser::VisibilityType)

}

