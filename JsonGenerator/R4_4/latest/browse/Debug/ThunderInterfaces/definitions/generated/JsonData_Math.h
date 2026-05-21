// C++ classes for Math API JSON-RPC API.
// Generated automatically from 'IMath.h'. DO NOT EDIT.

// Note: This code is inherently not thread safe. If required, proper synchronisation must be added.

#pragma once

#include <core/JSON.h>
#include <interfaces/IMath.h>

namespace WPEFramework {

namespace JsonData {

    namespace Math {

        // Common classes
        //

        class AddParamsInfo : public Core::JSON::Container {
        public:
            AddParamsInfo()
                : Core::JSON::Container()
            {
                Add(_T("a"), &A);
                Add(_T("b"), &B);
            }

            bool IsValid() const
            {
                return (true);
            }

            AddParamsInfo(const AddParamsInfo&) = delete;
            AddParamsInfo& operator=(const AddParamsInfo&) = delete;

        public:
            Core::JSON::DecUInt16 A;
            Core::JSON::DecUInt16 B;
        }; // class AddParamsInfo

        // Method params/result classes
        //

    } // namespace Math

} // namespace JsonData

}

