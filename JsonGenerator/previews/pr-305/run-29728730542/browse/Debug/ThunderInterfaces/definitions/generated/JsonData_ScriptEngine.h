// C++ types for ScriptEngine API.
// Generated automatically from 'IScriptEngine.h'. DO NOT EDIT.

// Note: This code is inherently not thread safe. If required, proper synchronisation must be added.

#pragma once

#include <core/JSON.h>
#include <interfaces/IScriptEngine.h>

namespace Thunder {

namespace JsonData {

    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    namespace ScriptEngine {

        // Method params/result classes
        //

        class URLChangedParamsData : public Core::JSON::Container {
        public:
            URLChangedParamsData()
                : Core::JSON::Container()
            {
                Add(_T("url"), &URL);
            }

            URLChangedParamsData(const URLChangedParamsData&) = delete;
            URLChangedParamsData(URLChangedParamsData&&) noexcept  = delete;

            URLChangedParamsData& operator=(const URLChangedParamsData&) = delete;
            URLChangedParamsData& operator=(URLChangedParamsData&&) noexcept  = delete;

            ~URLChangedParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return (URL.IsSet() == true);
            }

        public:
            Core::JSON::String URL; // Loaded URL
        }; // class URLChangedParamsData

        class URLData : public Core::JSON::Container {
        public:
            URLData()
                : Core::JSON::Container()
            {
                Add(_T("value"), &Value);
            }

            URLData(const URLData&) = delete;
            URLData(URLData&&) noexcept  = delete;

            URLData& operator=(const URLData&) = delete;
            URLData& operator=(URLData&&) noexcept  = delete;

            ~URLData() = default;

        public:
            bool IsDataValid() const
            {
                return (Value.IsSet() == true);
            }

        public:
            Core::JSON::String Value; // Script to be loaded into the engine and to be executed.
        }; // class URLData

    } // namespace ScriptEngine

    POP_WARNING()

} // namespace JsonData

}

