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
#include <ITestJsonShape.h>

namespace Thunder {
namespace TestImplementation {

    class TestJsonShapeImpl : public FunctionalTest::ITestJsonShape {
    public:
        TestJsonShapeImpl() : _counter(42) {}
        ~TestJsonShapeImpl() override = default;

        TestJsonShapeImpl(const TestJsonShapeImpl&) = delete;
        TestJsonShapeImpl& operator=(const TestJsonShapeImpl&) = delete;

        Core::hresult GetWrappedCounter(uint32_t& counter) const override
        {
            counter = _counter;
            return Core::ERROR_NONE;
        }

        Core::hresult EchoExtractedList(
            const std::vector<uint32_t>& input,
            std::vector<uint32_t>& output) const override
        {
            output = input;
            return Core::ERROR_NONE;
        }

        Core::hresult EchoExtractedStruct(
            const Dimensions& in,
            Dimensions& out) const override
        {
            out = in;
            return Core::ERROR_NONE;
        }

        BEGIN_INTERFACE_MAP(TestJsonShapeImpl)
        INTERFACE_ENTRY(FunctionalTest::ITestJsonShape)
        END_INTERFACE_MAP

    private:
        uint32_t _counter;
    };

    static Factory::Registrar<FunctionalTest::ITestJsonShape, TestJsonShapeImpl> g_jsonShapeRegistrar;

} // namespace TestImplementation
} // namespace Thunder
