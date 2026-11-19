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

#include <ImplementationFactory.h>
#include <ITestLengthModes.h>
#include <algorithm>

namespace Thunder {
namespace TestImplementation {

    class TestLengthModesImpl : public FunctionalTest::ITestLengthModes {
    public:
        TestLengthModesImpl() = default;
        ~TestLengthModesImpl() override = default;

        TestLengthModesImpl(const TestLengthModesImpl&) = delete;
        TestLengthModesImpl& operator=(const TestLengthModesImpl&) = delete;

        Core::hresult EchoSingleByte(const uint8_t input, uint8_t output[]) const override
        {
            output[0] = input;
            return Core::ERROR_NONE;
        }

        uint16_t ReadPayload(uint8_t output[], const uint16_t maxSize) const override
        {
            static const uint8_t pattern[] = { 0xDE, 0xAD, 0xBE, 0xEF };
            static const uint16_t patternSize = static_cast<uint16_t>(sizeof(pattern));
            const uint16_t count = std::min(maxSize, patternSize);
            for (uint16_t i = 0; i < count; ++i) {
                output[i] = pattern[i];
            }
            return count;
        }

        BEGIN_INTERFACE_MAP(TestLengthModesImpl)
        INTERFACE_ENTRY(FunctionalTest::ITestLengthModes)
        END_INTERFACE_MAP
    };

    static Factory::Registrar<FunctionalTest::ITestLengthModes, TestLengthModesImpl> g_lengthModesRegistrar;

} // namespace TestImplementation
} // namespace Thunder
