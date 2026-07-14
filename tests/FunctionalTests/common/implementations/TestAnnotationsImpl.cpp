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
#include <ITestAnnotations.h>
#include <algorithm>
#include <vector>
#include <mutex>

namespace Thunder {
namespace TestImplementation {

    class TestAnnotationsImpl : public FunctionalTest::ITestAnnotations {
    public:
        TestAnnotationsImpl()
            : _connectionState(FunctionalTest::ITestAnnotations::DISCONNECTED)
            , _features(FunctionalTest::ITestAnnotations::FEAT_NONE)
            , _payloadSize(0)
            , _tokenSize(0)
        {
            ::memset(_payload, 0, sizeof(_payload));
            ::memset(_token, 0, sizeof(_token));
        }

        ~TestAnnotationsImpl() override = default;

        TestAnnotationsImpl(const TestAnnotationsImpl&) = delete;
        TestAnnotationsImpl& operator=(const TestAnnotationsImpl&) = delete;

        Core::hresult DeprecatedEcho(const uint32_t value, uint32_t& result) const override
        {
            result = value;
            return Core::ERROR_NONE;
        }

        Core::hresult ObsoleteEcho(const uint32_t value, uint32_t& result) const override
        {
            result = value;
            return Core::ERROR_NONE;
        }

        Core::hresult EchoWithAlt(const uint32_t value, uint32_t& result) const override
        {
            result = value;
            return Core::ERROR_NONE;
        }

        Core::hresult Add(const uint32_t a, const uint32_t b, uint32_t& result) const override
        {
            result = a + b;
            return Core::ERROR_NONE;
        }

        Core::hresult Subtract(const uint32_t a, const uint32_t b, uint32_t& result) const override
        {
            result = a - b;
            return Core::ERROR_NONE;
        }

        Core::hresult EchoDeviceInfo(const DeviceInfo& input, DeviceInfo& output) const override
        {
            output = input;
            return Core::ERROR_NONE;
        }

        Core::hresult SetConnectionState(const ConnectionState state) override
        {
            _connectionState = state;
            return Core::ERROR_NONE;
        }

        Core::hresult GetConnectionState(ConnectionState& state) const override
        {
            state = _connectionState;
            return Core::ERROR_NONE;
        }

        Core::hresult SetFeatures(const Features features) override
        {
            _features = features;
            return Core::ERROR_NONE;
        }

        Core::hresult GetFeatures(Features& features) const override
        {
            features = _features;
            return Core::ERROR_NONE;
        }

        Core::hresult SetPayloadBase64(const uint8_t data[], const uint16_t size) override
        {
            if (size > 256) {
                return Core::ERROR_BAD_REQUEST;
            }
            ::memcpy(_payload, data, size);
            _payloadSize = size;
            return Core::ERROR_NONE;
        }

        Core::hresult GetPayloadBase64(uint8_t data[], const uint16_t maxSize, uint16_t& written) override
        {
            written = std::min(maxSize, _payloadSize);
            ::memcpy(data, _payload, written);
            return Core::ERROR_NONE;
        }

        Core::hresult SetTokenHex(const uint8_t data[], const uint16_t size) override
        {
            if (size > 64) {
                return Core::ERROR_BAD_REQUEST;
            }
            ::memcpy(_token, data, size);
            _tokenSize = size;
            return Core::ERROR_NONE;
        }

        Core::hresult GetTokenHex(uint8_t data[], const uint16_t maxSize, uint16_t& written) override
        {
            written = std::min(maxSize, _tokenSize);
            ::memcpy(data, _token, written);
            return Core::ERROR_NONE;
        }

        Core::hresult EchoPoints(const std::vector<Point>& input, std::vector<Point>& output) const override
        {
            output = input;
            return Core::ERROR_NONE;
        }

        Core::hresult FormatText(const string& text, const Core::OptionalType<bool>& uppercase, string& result) override
        {
            result = text;
            if (uppercase.IsSet() && uppercase.Value()) {
                std::transform(result.begin(), result.end(), result.begin(), ::toupper);
            }
            return Core::ERROR_NONE;
        }

        // --- Empty parameter list (C5) ---
        Core::hresult Ping() const override
        {
            return Core::ERROR_NONE;
        }

        // --- Events ---
        Core::hresult Register(INotification* notification) override
        {
            std::lock_guard<std::mutex> lock(_mutex);
            _notification = notification;
            if (_notification) {
                _notification->AddRef();
                // statuslistener: deliver current features immediately on registration
                _notification->OnFeaturesChanged(_features);
            }
            return Core::ERROR_NONE;
        }

        Core::hresult Unregister(INotification* notification) override
        {
            std::lock_guard<std::mutex> lock(_mutex);
            if (_notification == notification) {
                _notification->Release();
                _notification = nullptr;
            }
            return Core::ERROR_NONE;
        }

        Core::hresult TriggerPortEvent(const uint8_t port, const ConnectionState state) override
        {
            std::lock_guard<std::mutex> lock(_mutex);
            if (_notification) {
                _notification->OnPortStateChanged(port, state);
            }
            return Core::ERROR_NONE;
        }

        Core::hresult TriggerFeaturesEvent(const Features features) override
        {
            std::lock_guard<std::mutex> lock(_mutex);
            if (_notification) {
                _notification->OnFeaturesChanged(features);
            }
            return Core::ERROR_NONE;
        }

        BEGIN_INTERFACE_MAP(TestAnnotationsImpl)
        INTERFACE_ENTRY(FunctionalTest::ITestAnnotations)
        END_INTERFACE_MAP

    private:
        ConnectionState _connectionState;
        Features _features;
        uint8_t _payload[256];
        uint16_t _payloadSize;
        uint8_t _token[64];
        uint16_t _tokenSize;
        INotification* _notification = nullptr;
        mutable std::mutex _mutex;
    };

    static Factory::Registrar<FunctionalTest::ITestAnnotations, TestAnnotationsImpl> g_annotationsRegistrar;

} // namespace TestImplementation
} // namespace Thunder
