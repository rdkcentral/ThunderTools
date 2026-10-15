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
#include <ITestNamespaces.h>

namespace Thunder {
namespace TestImplementation {

    class TestNamespacesPrimaryImpl : public FunctionalTest::ITestNamespacesPrimary {
    public:
        TestNamespacesPrimaryImpl() = default;
        ~TestNamespacesPrimaryImpl() override = default;

        TestNamespacesPrimaryImpl(const TestNamespacesPrimaryImpl&) = delete;
        TestNamespacesPrimaryImpl& operator=(const TestNamespacesPrimaryImpl&) = delete;

        Core::hresult EchoPayload(const FunctionalTest::NamespacePayload& input, FunctionalTest::NamespacePayload& output) const override
        {
            output = input;
            return Core::ERROR_NONE;
        }

        Core::hresult EchoScoped(const FunctionalTest::WPEFramework::ScopedPayload& input, FunctionalTest::WPEFramework::ScopedPayload& output) const override
        {
            output = input;
            return Core::ERROR_NONE;
        }

        BEGIN_INTERFACE_MAP(TestNamespacesPrimaryImpl)
        INTERFACE_ENTRY(FunctionalTest::ITestNamespacesPrimary)
        END_INTERFACE_MAP
    };

    class TestNamespacesLegacyImpl : public WPEFramework::FunctionalTest::ITestNamespacesLegacy {
    public:
        TestNamespacesLegacyImpl() = default;
        ~TestNamespacesLegacyImpl() override = default;

        TestNamespacesLegacyImpl(const TestNamespacesLegacyImpl&) = delete;
        TestNamespacesLegacyImpl& operator=(const TestNamespacesLegacyImpl&) = delete;

        Core::hresult EchoInstance(const Core::instance_id input, Core::instance_id& output) const override
        {
            output = input;
            return Core::ERROR_NONE;
        }

        Core::hresult EchoPayload(const WPEFramework::FunctionalTest::NamespacePayload& input, WPEFramework::FunctionalTest::NamespacePayload& output) const override
        {
            output = input;
            return Core::ERROR_NONE;
        }

        BEGIN_INTERFACE_MAP(TestNamespacesLegacyImpl)
        INTERFACE_ENTRY(WPEFramework::FunctionalTest::ITestNamespacesLegacy)
        END_INTERFACE_MAP
    };

    static Factory::Registrar<FunctionalTest::ITestNamespacesPrimary, TestNamespacesPrimaryImpl> g_namespacesPrimaryRegistrar;
    static Factory::Registrar<WPEFramework::FunctionalTest::ITestNamespacesLegacy, TestNamespacesLegacyImpl> g_namespacesLegacyRegistrar;

} // namespace TestImplementation
} // namespace Thunder
