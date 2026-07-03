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
#include <ITestJsonUncompliantCollapsed.h>

namespace Thunder {
namespace TestImplementation {

    class TestJsonUncompliantCollapsedImpl : public FunctionalTest::ITestJsonUncompliantCollapsed {
    public:
        TestJsonUncompliantCollapsedImpl() = default;
        ~TestJsonUncompliantCollapsedImpl() override = default;

        TestJsonUncompliantCollapsedImpl(const TestJsonUncompliantCollapsedImpl&) = delete;
        TestJsonUncompliantCollapsedImpl& operator=(const TestJsonUncompliantCollapsedImpl&) = delete;

        Core::hresult PingCollapsed(const string& payload, string& reply) const override
        {
            reply = payload;
            return Core::ERROR_NONE;
        }

        Core::hresult Value(uint32_t& value) const override
        {
            value = _value;
            return Core::ERROR_NONE;
        }

        Core::hresult Value(const uint32_t value) override
        {
            _value = value;
            return Core::ERROR_NONE;
        }

        BEGIN_INTERFACE_MAP(TestJsonUncompliantCollapsedImpl)
        INTERFACE_ENTRY(FunctionalTest::ITestJsonUncompliantCollapsed)
        END_INTERFACE_MAP

    private:
        uint32_t _value{0};
    };

    static Factory::Registrar<FunctionalTest::ITestJsonUncompliantCollapsed, TestJsonUncompliantCollapsedImpl> g_registrar;

} // namespace TestImplementation
} // namespace Thunder
