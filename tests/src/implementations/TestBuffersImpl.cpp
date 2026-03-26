/*
 * Copyright 2026 Metrological - Apache 2.0
 */

#include "TestRegistry.h"
#include <ITestBuffers.h>
#include <algorithm>
#include <cstring>

namespace Thunder {
namespace TestImplementations {

    class TestBuffersImpl : public FunctionalTest::ITestBuffers {
    public:
        TestBuffersImpl()
        {
            ::memset(_key, 0, sizeof(_key));
            ::memset(_token, 0, sizeof(_token));
        }
        ~TestBuffersImpl() override = default;

        TestBuffersImpl(const TestBuffersImpl&) = delete;
        TestBuffersImpl& operator=(const TestBuffersImpl&) = delete;

        // FIXME: ProxyStubGenerator: Fixed-size array parameters generate invalid proxy signatures
        // // ===== Fixed-size arrays =====

        // Core::hresult EchoFixed4(const uint8_t input[4], uint8_t output[4]) override
        // {
        //     ::memcpy(output, input, 4);
        //     return Core::ERROR_NONE;
        // }

        // Core::hresult EchoFixed4Words(const uint32_t input[4], uint32_t output[4]) override
        // {
        //     ::memcpy(output, input, 4 * sizeof(uint32_t));
        //     return Core::ERROR_NONE;
        // }

        // Core::hresult XorFixed8(uint8_t data[8], const uint8_t key) override
        // {
        //     for (int i = 0; i < 8; ++i) {
        //         data[i] ^= key;
        //     }
        //     return Core::ERROR_NONE;
        // }

        // Core::hresult SetKey(const uint8_t key[16]) override
        // {
        //     ::memcpy(_key, key, 16);
        //     return Core::ERROR_NONE;
        // }

        // Core::hresult GetKey(uint8_t key[16]) const override
        // {
        //     ::memcpy(key, _key, 16);
        //     return Core::ERROR_NONE;
        // }

        // Core::hresult SetToken(const uint8_t token[8]) override
        // {
        //     ::memcpy(_token, token, 8);
        //     return Core::ERROR_NONE;
        // }

        // Core::hresult GetToken(uint8_t token[8]) const override
        // {
        //     ::memcpy(token, _token, 8);
        //     return Core::ERROR_NONE;
        // }

        // ===== Input buffers with length =====

        Core::hresult SumBytes(const uint8_t* buffer, const uint16_t size, uint32_t& sum) override
        {
            sum = 0;
            for (uint16_t i = 0; i < size; ++i) {
                sum += buffer[i];
            }
            return Core::ERROR_NONE;
        }

        Core::hresult Checksum(const uint8_t* data, const uint32_t length, uint32_t& checksum) override
        {
            checksum = 0;
            for (uint32_t i = 0; i < length; ++i) {
                checksum = ((checksum << 5) + checksum) + data[i]; // djb2
            }
            return Core::ERROR_NONE;
        }

        // ===== Output buffers with maxlength =====

        Core::hresult FillSequence(uint8_t* buffer, const uint16_t maxSize, const uint8_t start, uint16_t& written) override
        {
            for (uint16_t i = 0; i < maxSize; ++i) {
                buffer[i] = static_cast<uint8_t>(start + i);
            }
            written = maxSize;
            return Core::ERROR_NONE;
        }

        Core::hresult FillPattern(uint8_t* buffer, const uint32_t capacity, const uint8_t pattern, uint32_t& written) override
        {
            ::memset(buffer, pattern, capacity);
            written = capacity;
            return Core::ERROR_NONE;
        }

        // ===== In/Out buffers =====

        Core::hresult ReverseBuffer(uint8_t* buffer, const uint16_t size) override
        {
            for (uint16_t i = 0; i < size / 2; ++i) {
                std::swap(buffer[i], buffer[size - 1 - i]);
            }
            return Core::ERROR_NONE;
        }

        Core::hresult XorBuffer(uint8_t* buffer, const uint32_t length, const uint8_t key) override
        {
            for (uint32_t i = 0; i < length; ++i) {
                buffer[i] ^= key;
            }
            return Core::ERROR_NONE;
        }

        // ===== Multi-buffer =====

        Core::hresult MergeBuffers(
            const uint8_t* input1, const uint16_t size1,
            const uint8_t* input2, const uint16_t size2,
            uint8_t* output, const uint16_t maxOutput,
            uint16_t& written) override
        {
            written = 0;
            uint16_t i1 = 0, i2 = 0;
            while (written < maxOutput && (i1 < size1 || i2 < size2)) {
                if (i1 < size1 && written < maxOutput) {
                    output[written++] = input1[i1++];
                }
                if (i2 < size2 && written < maxOutput) {
                    output[written++] = input2[i2++];
                }
            }
            return Core::ERROR_NONE;
        }

        // ===== Edge cases =====

        Core::hresult Process(const uint8_t* buffer, const uint32_t size, uint32_t& result) override
        {
            // Return size as result — exercises the empty/large buffer paths
            (void)buffer;
            result = size;
            return Core::ERROR_NONE;
        }

        BEGIN_INTERFACE_MAP(TestBuffersImpl)
        INTERFACE_ENTRY(FunctionalTest::ITestBuffers)
        END_INTERFACE_MAP

    private:
        uint8_t _key[16];
        uint8_t _token[8];
    };

    static TestRegistry::ImplementationRegistrar<FunctionalTest::ITestBuffers, TestBuffersImpl> g_buffersRegistrar;

} // namespace TestImplementations
} // namespace Thunder
