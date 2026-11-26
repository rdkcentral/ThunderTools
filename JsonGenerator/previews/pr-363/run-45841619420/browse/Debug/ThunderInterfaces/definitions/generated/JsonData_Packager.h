// C++ types for Packager API.
// Generated automatically from 'IPackager.h'. DO NOT EDIT.

// Note: This code is inherently not thread safe. If required, proper synchronisation must be added.

#pragma once

#include <core/JSON.h>
#include <interfaces/IPackager.h>

namespace Thunder {

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
                Add(_T("name"), &Name);
                Add(_T("version"), &Version);
                Add(_T("arch"), &Arch);
            }

            InstallParamsData(const InstallParamsData&) = delete;
            InstallParamsData(InstallParamsData&&) noexcept  = delete;

            InstallParamsData& operator=(const InstallParamsData&) = delete;
            InstallParamsData& operator=(InstallParamsData&&) noexcept  = delete;

            ~InstallParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return ((Name.IsSet() == true) && (Version.IsSet() == true) && (Arch.IsSet() == true));
            }

        public:
            Core::JSON::String Name; // Name, URL or file path of the package to install
            Core::JSON::String Version; // Version of the package to install
            Core::JSON::String Arch; // Architecture of the package to install
        }; // class InstallParamsData

    } // namespace Packager

    POP_WARNING()

} // namespace JsonData

}

