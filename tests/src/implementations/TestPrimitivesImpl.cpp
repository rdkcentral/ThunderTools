/*
 * Copyright 2026 Metrological - Apache 2.0
 */

#include "TestRegistry.h"
#include <ITestPrimitives.h>
#include <cstring>

#ifdef BUILD_JSON_RPC_TESTS
#include "JsonRpcServer.h"
#include <JTestPrimitives.h>
#endif

namespace Thunder {
namespace TestImplementations {

    class TestPrimitivesImpl : public FunctionalTest::ITestPrimitives {
    public:
        TestPrimitivesImpl() = default;
        ~TestPrimitivesImpl() override = default;

        TestPrimitivesImpl(const TestPrimitivesImpl&) = delete;
        TestPrimitivesImpl& operator=(const TestPrimitivesImpl&) = delete;

        Core::hresult EchoInt8(const int8_t input, int8_t& output) override
        { output = input; return Core::ERROR_NONE; }

        Core::hresult EchoInt16(const int16_t input, int16_t& output) override
        { output = input; return Core::ERROR_NONE; }

        Core::hresult EchoInt24(const int24_t input, int24_t& output) override
        { output = input; return Core::ERROR_NONE; }

        Core::hresult EchoInt32(const int32_t input, int32_t& output) override
        { output = input; return Core::ERROR_NONE; }

        Core::hresult EchoInt64(const int64_t input, int64_t& output) override
        { output = input; return Core::ERROR_NONE; }

        Core::hresult EchoUInt8(const uint8_t input, uint8_t& output) override
        { output = input; return Core::ERROR_NONE; }

        Core::hresult EchoUInt16(const uint16_t input, uint16_t& output) override
        { output = input; return Core::ERROR_NONE; }

        Core::hresult EchoUInt24(const Core::UInt24 input, Core::UInt24& output) override
        { output = input; return Core::ERROR_NONE; }

        Core::hresult EchoUInt32(const uint32_t input, uint32_t& output) override
        { output = input; return Core::ERROR_NONE; }

        Core::hresult EchoUInt64(const uint64_t input, uint64_t& output) override
        { output = input; return Core::ERROR_NONE; }

        Core::hresult EchoFloat(const float input, float& output) override
        { output = input; return Core::ERROR_NONE; }

        Core::hresult EchoDouble(const double input, double& output) override
        { output = input; return Core::ERROR_NONE; }

        Core::hresult EchoBool(const bool input, bool& output) override
        { output = input; return Core::ERROR_NONE; }

        Core::hresult EchoInstanceId(const Core::instance_id input, Core::instance_id& output) override
        { output = input; return Core::ERROR_NONE; }

        Core::hresult EchoTime(const Core::Time input, Core::Time& output) override
        { output = input; return Core::ERROR_NONE; }

        Core::hresult EchoMACAddress(const Core::MACAddress input, Core::MACAddress& output) override
        { output = input; return Core::ERROR_NONE; }

        Core::hresult EchoString(const string& input, string& output) override
        { output = input; return Core::ERROR_NONE; }

        // maxLength: capacity in, bytes written out
        // Core::hresult EchoCharPtr(const char* input, char* output, uint8_t& maxLength) override
        // {
        //     if (input == nullptr || output == nullptr) {
        //         return Core::ERROR_INVALID_INPUT_LENGTH;
        //     }
        //     uint8_t len = static_cast<uint8_t>(::strnlen(input, maxLength));
        //     ::memcpy(output, input, len);
        //     maxLength = len;
        //     return Core::ERROR_NONE;
        // }

        BEGIN_INTERFACE_MAP(TestPrimitivesImpl)
        INTERFACE_ENTRY(FunctionalTest::ITestPrimitives)
        END_INTERFACE_MAP
    };

    static TestRegistry::ImplementationRegistrar<FunctionalTest::ITestPrimitives, TestPrimitivesImpl> g_primitivesRegistrar;

#ifdef BUILD_JSON_RPC_TESTS
    static JsonRpcServer::JsonRpcRegistrar<FunctionalTest::ITestPrimitives, TestPrimitivesImpl> g_jsonrpc_primitivesRegistrar(FunctionalTest::JTestPrimitives::Register<JsonRpcServer::JsonRpcServer>);
#endif

} // namespace TestImplementations
} // namespace Thunder
