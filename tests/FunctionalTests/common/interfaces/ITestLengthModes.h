/*
 * If not stated otherwise in this file or this component's LICENSE file the
 * following copyright and licenses apply:
 *
 * Copyright 2026 Metrological
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once

#include "Ids.h"
#include "Module.h"

namespace Thunder {
namespace FunctionalTest {

    // Exercises less-common @length modes that are not covered in existing
    // functional interfaces.
    // @json 1.0.0
    struct EXTERNAL ITestLengthModes : virtual public Core::IUnknown {
        enum { ID = ID_TEST_LENGTH_MODES };

        // @brief Echoes exactly one byte, exercising the length:1 output annotation
        //        which signals that the output buffer holds exactly one element.
        // @param input  Input single-byte value.
        // @param output Receives the echoed byte.
        // @retval ERROR_NONE Echo completed.
        virtual Core::hresult EchoSingleByte(
            const uint8_t input /* @in */,
            uint8_t output[] /* @out @length:1 @maxlength:1 */) const = 0;

        // @brief Returns a fixed 4-byte payload using the length:return annotation to convey the written byte count.
        //        Intended to cover the length:return annotation in a signature where the return type
        //        carries the produced byte count.
        //
        //        NOTE: returning uint16_t instead of Core::hresult is a deliberate trade-off for
        //        test coverage of the length:return code path, not an oversight. The downside is
        //        that callers lose the ability to detect transport-level failures: there is no
        //        hresult channel through which such errors can be signalled.
        // @param output  Receives payload bytes.
        // @param maxSize Maximum writable bytes in output.
        // @retval Payload byte count written to output.
        virtual uint16_t ReadPayload(
            uint8_t output[] /* @out @length:return @maxlength:maxSize */,
            const uint16_t maxSize /* @in */) const = 0;
    };

} // namespace FunctionalTest
} // namespace Thunder
