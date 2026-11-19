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
#include <ITestJsonCompliant.h>

namespace Thunder {
namespace TestImplementation {

    class TestJsonCompliantImpl : public FunctionalTest::ITestJsonCompliant {
    public:
        TestJsonCompliantImpl() = default;
        ~TestJsonCompliantImpl() override = default;

        TestJsonCompliantImpl(const TestJsonCompliantImpl&) = delete;
        TestJsonCompliantImpl& operator=(const TestJsonCompliantImpl&) = delete;

        Core::hresult Ping(const string& payload, string& reply) const override
        {
            reply = payload;
            return Core::ERROR_NONE;
        }

        BEGIN_INTERFACE_MAP(TestJsonCompliantImpl)
        INTERFACE_ENTRY(FunctionalTest::ITestJsonCompliant)
        END_INTERFACE_MAP
    };

    static Factory::Registrar<FunctionalTest::ITestJsonCompliant, TestJsonCompliantImpl> g_registrar;

} // namespace TestImplementation
} // namespace Thunder
