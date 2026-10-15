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

#include <gtest/gtest.h>
#include "TestHarness.h"
#include <ITestNamespaces.h>

using namespace Thunder;

// Both interfaces come from one header and one ProxyStubGenerator pass
// ("NAMESPACE Thunder WPEFramework"). If the generator only handled one namespace,
// or mixed up the two NamespacePayload types, the proxy for one of them would be
// missing (Open() fails) or the generated code would not compile.

class TestNamespacesPrimary : public Testing::TestHarness<FunctionalTest::ITestNamespacesPrimary> {};
class TestNamespacesLegacy : public Testing::TestHarness<WPEFramework::FunctionalTest::ITestNamespacesLegacy> {};

TEST_F(TestNamespacesPrimary, EchoPayload)
{
    FunctionalTest::NamespacePayload input{};
    input.value = 0xDEADBEEF;
    input.tag = 42;

    FunctionalTest::NamespacePayload output{};
    EXPECT_EQ(_proxy->EchoPayload(input, output), Core::ERROR_NONE);
    EXPECT_EQ(output.value, input.value);
    EXPECT_EQ(output.tag, input.tag);
}

TEST_F(TestNamespacesLegacy, EchoInstanceQualifiedThroughLegacyName)
{
    const Core::instance_id input = static_cast<Core::instance_id>(0x12345678);
    Core::instance_id output = 0;
    EXPECT_EQ(_proxy->EchoInstance(input, output), Core::ERROR_NONE);
    EXPECT_EQ(output, input);
}

TEST_F(TestNamespacesLegacy, EchoPayloadOfOwnNamespace)
{
    WPEFramework::FunctionalTest::NamespacePayload input{};
    input.text = _T("legacy namespace payload");
    input.flag = true;

    WPEFramework::FunctionalTest::NamespacePayload output{};
    EXPECT_EQ(_proxy->EchoPayload(input, output), Core::ERROR_NONE);
    EXPECT_EQ(output.text, input.text);
    EXPECT_EQ(output.flag, input.flag);
}
