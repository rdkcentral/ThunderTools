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

#pragma once

#include "Module.h"
#include "Ids.h"

// One header with interfaces in two top-level namespaces, generated in a single
// ProxyStubGenerator pass with "NAMESPACE Thunder WPEFramework".
//
// WPEFramework is the legacy name of the framework namespace. Thunder keeps it as a
// compatibility namespace (namespace WPEFramework { using namespace Thunder; }), so
// WPEFramework::FunctionalTest below is a namespace of its own, not the same as
// Thunder::FunctionalTest. This covers:
//   - finding interfaces of more than one requested namespace in one header,
//   - a type with the same short name in both namespaces (NamespacePayload),
//   - a framework type qualified through the legacy name (WPEFramework::Core::...).

namespace Thunder {

namespace FunctionalTest {

    struct NamespacePayload {
        uint32_t value;
        uint16_t tag;
    };

    struct EXTERNAL ITestNamespacesPrimary : virtual public Core::IUnknown {
        enum { ID = ID_TEST_NAMESPACES_PRIMARY };

        virtual Core::hresult EchoPayload(const NamespacePayload& input /* @in */, NamespacePayload& output /* @out */) const = 0;
    };

} // namespace FunctionalTest

} // namespace Thunder

namespace WPEFramework {

namespace FunctionalTest {

    // Same short name as Thunder::FunctionalTest::NamespacePayload, different layout.
    struct NamespacePayload {
        string text;
        bool flag;
    };

    struct EXTERNAL ITestNamespacesLegacy : virtual public Core::IUnknown {
        enum { ID = Thunder::FunctionalTest::ID_TEST_NAMESPACES_LEGACY };

        // Framework type qualified through the legacy namespace name.
        virtual Core::hresult EchoInstance(const WPEFramework::Core::instance_id input /* @in */, WPEFramework::Core::instance_id& output /* @out */) const = 0;

        virtual Core::hresult EchoPayload(const NamespacePayload& input /* @in */, NamespacePayload& output /* @out */) const = 0;
    };

} // namespace FunctionalTest

} // namespace WPEFramework
