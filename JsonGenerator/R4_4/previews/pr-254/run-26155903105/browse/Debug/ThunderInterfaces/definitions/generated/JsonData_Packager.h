// C++ classes for Packager API JSON-RPC API.
// Generated automatically from 'Packager.json'. DO NOT EDIT.

// Note: This code is inherently not thread safe. If required, proper synchronisation must be added.

#pragma once

#include <core/JSON.h>

namespace WPEFramework {

namespace JsonData {

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

            bool IsValid() const
            {
                return (true);
            }

            InstallParamsData(const InstallParamsData&) = delete;
            InstallParamsData& operator=(const InstallParamsData&) = delete;

        public:
            Core::JSON::String Package; // A name, an URL or a file path of the package to install
            Core::JSON::String Version; // Version of the package to install
            Core::JSON::String Architecture; // Architecture of the package to install
        }; // class InstallParamsData

    } // namespace Packager

} // namespace JsonData

}

