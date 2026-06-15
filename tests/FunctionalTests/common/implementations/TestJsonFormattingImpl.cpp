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
#include <ITestJsonFormatting.h>

namespace Thunder {
namespace TestImplementation {

    // ===== ITestJsonTextKeep =====

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

    // ===== ITestJsonTextCase =====

    class TestJsonTextCaseImpl : public FunctionalTest::ITestJsonTextCase {
    public:
        TestJsonTextCaseImpl() = default;
        ~TestJsonTextCaseImpl() override = default;

        TestJsonTextCaseImpl(const TestJsonTextCaseImpl&) = delete;
        TestJsonTextCaseImpl& operator=(const TestJsonTextCaseImpl&) = delete;

        Core::hresult EchoCaseConvention(const uint16_t sourceValue, uint16_t& resultValue) const override
        {
            resultValue = sourceValue;
            return Core::ERROR_NONE;
        }

        BEGIN_INTERFACE_MAP(TestJsonTextCaseImpl)
        INTERFACE_ENTRY(FunctionalTest::ITestJsonTextCase)
        END_INTERFACE_MAP
    };

    // ===== ITestJsonCompliant =====

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

    // ===== ITestJsonUncompliantExtended =====

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

    // ===== ITestJsonUncompliantCollapsed =====

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

        BEGIN_INTERFACE_MAP(TestJsonUncompliantCollapsedImpl)
        INTERFACE_ENTRY(FunctionalTest::ITestJsonUncompliantCollapsed)
        END_INTERFACE_MAP
    };

    static Factory::Registrar<FunctionalTest::ITestJsonTextKeep,             TestJsonTextKeepImpl>             g_jsonTextKeepRegistrar;
    static Factory::Registrar<FunctionalTest::ITestJsonTextCase,             TestJsonTextCaseImpl>             g_jsonTextCaseRegistrar;
    static Factory::Registrar<FunctionalTest::ITestJsonCompliant,            TestJsonCompliantImpl>            g_jsonCompliantRegistrar;
    static Factory::Registrar<FunctionalTest::ITestJsonUncompliantExtended,  TestJsonUncompliantExtendedImpl>  g_jsonUncompliantExtRegistrar;
    static Factory::Registrar<FunctionalTest::ITestJsonUncompliantCollapsed, TestJsonUncompliantCollapsedImpl> g_jsonUncompliantColRegistrar;

} // namespace TestImplementation
} // namespace Thunder
