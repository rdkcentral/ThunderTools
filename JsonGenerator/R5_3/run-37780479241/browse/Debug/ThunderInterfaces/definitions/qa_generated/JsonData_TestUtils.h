// C++ types for TestUtils API.
// Generated automatically from 'ITestAutomation.h'. DO NOT EDIT.

// Note: This code is inherently not thread safe. If required, proper synchronisation must be added.

#pragma once

#include <core/JSON.h>
#include <qa_interfaces/ITestAutomation.h>

namespace Thunder {

namespace JsonData {

    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    namespace TestUtils {

        // Method params/result classes
        //

    } // namespace TestUtils

    POP_WARNING()

} // namespace JsonData

// Enum conversion handlers
ENUM_CONVERSION_HANDLER(QualityAssurance::ITestTextOptions::EnumTextOptions)
ENUM_CONVERSION_HANDLER(QualityAssurance::ITestTextOptions::ITestLegacy::EnumTextOptions)
ENUM_CONVERSION_HANDLER(QualityAssurance::ITestTextOptions::ITestKeep::EnumTextOptions)
ENUM_CONVERSION_HANDLER(QualityAssurance::ITestTextOptions::ITestCustom::EnumTextOptions)

}

