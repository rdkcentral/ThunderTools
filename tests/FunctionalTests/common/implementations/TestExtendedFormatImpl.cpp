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
#include <ITestExtendedFormat.h>

namespace Thunder {
namespace TestImplementation {

    class TestExtendedFormatImpl : public FunctionalTest::ITestExtendedFormat {
    public:
        TestExtendedFormatImpl()
            : _volume(50)
            , _name("DefaultDevice")
        {
        }

        ~TestExtendedFormatImpl() override = default;

        TestExtendedFormatImpl(const TestExtendedFormatImpl&) = delete;
        TestExtendedFormatImpl& operator=(const TestExtendedFormatImpl&) = delete;

        Core::hresult EchoMethod(const uint32_t value, uint32_t& result) const override
        {
            result = value;
            return Core::ERROR_NONE;
        }

        Core::hresult AddMethod(const uint32_t a, const uint32_t b, uint32_t& result) const override
        {
            result = a + b;
            return Core::ERROR_NONE;
        }

        Core::hresult Volume(uint32_t& volume) const override
        {
            volume = _volume;
            return Core::ERROR_NONE;
        }

        Core::hresult Volume(const uint32_t volume) override
        {
            _volume = volume;
            return Core::ERROR_NONE;
        }

        Core::hresult Name(string& name) const override
        {
            name = _name;
            return Core::ERROR_NONE;
        }

        BEGIN_INTERFACE_MAP(TestExtendedFormatImpl)
        INTERFACE_ENTRY(FunctionalTest::ITestExtendedFormat)
        END_INTERFACE_MAP

    private:
        uint32_t _volume;
        string _name;
    };

    static Factory::Registrar<FunctionalTest::ITestExtendedFormat, TestExtendedFormatImpl> g_extendedFormatRegistrar;

} // namespace TestImplementation
} // namespace Thunder
