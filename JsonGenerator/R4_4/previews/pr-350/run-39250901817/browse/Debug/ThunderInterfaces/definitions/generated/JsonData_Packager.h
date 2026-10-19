// C++ types for Packager API.
// Generated automatically from 'Packager.json'. DO NOT EDIT.

// Note: This code is inherently not thread safe. If required, proper synchronisation must be added.

#pragma once

#include <core/JSON.h>

namespace WPEFramework {

namespace JsonData {

    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    namespace Packager {

        // Method params/result classes
        //

        class InstallParamsData : public Core::JSON::Container {
        public:
            InstallParamsData()
                : Core::JSON::Container()
            {
                Add(_T("package"), &Package);
                Add(_T("version"), &Version);
                Add(_T("architecture"), &Architecture);
            }

            InstallParamsData(const InstallParamsData&) = delete;
            InstallParamsData(InstallParamsData&&) noexcept  = delete;

            InstallParamsData& operator=(const InstallParamsData&) = delete;
            InstallParamsData& operator=(InstallParamsData&&) noexcept  = delete;

            ~InstallParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return (Package.IsSet() == true);
            }

        public:
            Core::JSON::String Package; // A name, an URL or a file path of the package to install
            Core::JSON::String Version; // Version of the package to install
            Core::JSON::String Architecture; // Architecture of the package to install
        }; // class InstallParamsData

    } // namespace Packager

    POP_WARNING()

} // namespace JsonData

}

