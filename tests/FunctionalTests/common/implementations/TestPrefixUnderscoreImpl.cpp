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
#include <ITestPrefixUnderscore.h>

namespace Thunder {
namespace TestImplementation {

    class TestPrefixUnderscoreImpl : public FunctionalTest::ITestPrefixUnderscore {
    public:
        TestPrefixUnderscoreImpl() = default;
        ~TestPrefixUnderscoreImpl() override = default;

        Core::hresult Echo(const uint32_t value, uint32_t& result) const override
        {
            result = value;
            return Core::ERROR_NONE;
        }

        Core::hresult Add(const uint32_t a, const uint32_t b, uint32_t& result) const override
        {
            result = a + b;
            return Core::ERROR_NONE;
        }

        BEGIN_INTERFACE_MAP(TestPrefixUnderscoreImpl)
        INTERFACE_ENTRY(FunctionalTest::ITestPrefixUnderscore)
        END_INTERFACE_MAP
    };

    static Factory::Registrar<FunctionalTest::ITestPrefixUnderscore, TestPrefixUnderscoreImpl> g_prefixUnderscoreRegistrar;

} // namespace TestImplementation
} // namespace Thunder
