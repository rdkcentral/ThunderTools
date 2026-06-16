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
#include <ITestJsonTextKeep.h>

namespace Thunder {
namespace TestImplementation {

    class TestJsonTextKeepImpl : public FunctionalTest::ITestJsonTextKeep {
    public:
        TestJsonTextKeepImpl() : _buildVersion(1) {}
        ~TestJsonTextKeepImpl() override = default;

        TestJsonTextKeepImpl(const TestJsonTextKeepImpl&) = delete;
        TestJsonTextKeepImpl& operator=(const TestJsonTextKeepImpl&) = delete;

        Core::hresult EchoMixedCaseName(const uint32_t InputValue, uint32_t& OutputValue) const override
        {
            OutputValue = InputValue;
            return Core::ERROR_NONE;
        }

        Core::hresult BuildVersion(uint32_t& BuildVersion) const override
        {
            BuildVersion = _buildVersion;
            return Core::ERROR_NONE;
        }

        BEGIN_INTERFACE_MAP(TestJsonTextKeepImpl)
        INTERFACE_ENTRY(FunctionalTest::ITestJsonTextKeep)
        END_INTERFACE_MAP

    private:
        uint32_t _buildVersion;
    };

    static Factory::Registrar<FunctionalTest::ITestJsonTextKeep, TestJsonTextKeepImpl> g_registrar;

} // namespace TestImplementation
} // namespace Thunder
