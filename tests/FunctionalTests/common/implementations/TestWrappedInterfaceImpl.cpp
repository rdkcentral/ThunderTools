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
#include <ITestWrappedInterface.h>

namespace Thunder {
namespace TestImplementation {

    class TestWrappedInterfaceImpl : public FunctionalTest::ITestWrappedInterface {
    public:
        TestWrappedInterfaceImpl() = default;
        ~TestWrappedInterfaceImpl() override = default;

        Core::hresult GetCounter(uint32_t& counter) const override
        {
            counter = 42;
            return Core::ERROR_NONE;
        }

        Core::hresult GetName(string& name) const override
        {
            name = "WrappedDevice";
            return Core::ERROR_NONE;
        }

        Core::hresult Echo(const uint32_t value, uint32_t& result) const override
        {
            result = value;
            return Core::ERROR_NONE;
        }

        BEGIN_INTERFACE_MAP(TestWrappedInterfaceImpl)
        INTERFACE_ENTRY(FunctionalTest::ITestWrappedInterface)
        END_INTERFACE_MAP
    };

    static Factory::Registrar<FunctionalTest::ITestWrappedInterface, TestWrappedInterfaceImpl> g_wrappedInterfaceRegistrar;

} // namespace TestImplementation
} // namespace Thunder
