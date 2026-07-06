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
#include <ITestJsonUncompliantExtended.h>

namespace Thunder {
namespace TestImplementation {

    class TestJsonUncompliantExtendedImpl : public FunctionalTest::ITestJsonUncompliantExtended {
    public:
        TestJsonUncompliantExtendedImpl() = default;
        ~TestJsonUncompliantExtendedImpl() override = default;

        TestJsonUncompliantExtendedImpl(const TestJsonUncompliantExtendedImpl&) = delete;
        TestJsonUncompliantExtendedImpl& operator=(const TestJsonUncompliantExtendedImpl&) = delete;

        Core::hresult PingExtended(const string& payload, string& reply) const override
        {
            reply = payload;
            return Core::ERROR_NONE;
        }

        BEGIN_INTERFACE_MAP(TestJsonUncompliantExtendedImpl)
        INTERFACE_ENTRY(FunctionalTest::ITestJsonUncompliantExtended)
        END_INTERFACE_MAP
    };

    static Factory::Registrar<FunctionalTest::ITestJsonUncompliantExtended, TestJsonUncompliantExtendedImpl> g_registrar;

} // namespace TestImplementation
} // namespace Thunder
