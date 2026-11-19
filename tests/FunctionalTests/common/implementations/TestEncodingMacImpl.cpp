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
#include <ITestEncodingMac.h>
#include <cstring>
#include <algorithm>

namespace Thunder {
namespace TestImplementation {

    class TestEncodingMacImpl : public FunctionalTest::ITestEncodingMac {
    public:
        TestEncodingMacImpl() { memset(_mac, 0, sizeof(_mac)); }
        ~TestEncodingMacImpl() override = default;

        TestEncodingMacImpl(const TestEncodingMacImpl&) = delete;
        TestEncodingMacImpl& operator=(const TestEncodingMacImpl&) = delete;

        Core::hresult SetMacAddress(const uint8_t mac[]) override
        {
            memcpy(_mac, mac, 6);
            return Core::ERROR_NONE;
        }

        Core::hresult GetMacAddress(uint8_t mac[]) const override
        {
            memcpy(mac, _mac, 6);
            return Core::ERROR_NONE;
        }

        Core::hresult EchoMacAddress(const uint8_t input[], uint8_t output[]) const override
        {
            memcpy(output, input, 6);
            return Core::ERROR_NONE;
        }

        Core::hresult SetVariableMac(const uint8_t data[], const uint16_t size) override
        {
            if (size > 32) return Core::ERROR_BAD_REQUEST;
            memcpy(_varMac, data, size);
            _varMacSize = size;
            return Core::ERROR_NONE;
        }

        Core::hresult GetVariableMac(uint8_t data[], const uint16_t maxSize, uint16_t& written) override
        {
            written = std::min(maxSize, _varMacSize);
            memcpy(data, _varMac, written);
            return Core::ERROR_NONE;
        }

        BEGIN_INTERFACE_MAP(TestEncodingMacImpl)
        INTERFACE_ENTRY(FunctionalTest::ITestEncodingMac)
        END_INTERFACE_MAP

    private:
        uint8_t _mac[6];
        uint8_t _varMac[32] = {};
        uint16_t _varMacSize = 0;
    };

    static Factory::Registrar<FunctionalTest::ITestEncodingMac, TestEncodingMacImpl> g_encodingMacRegistrar;

} // namespace TestImplementation
} // namespace Thunder
