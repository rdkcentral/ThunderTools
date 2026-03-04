/*
 * Copyright 2026 Metrological - Apache 2.0
 */

#include "TestRegistry.h"
#include <ITestOptionals.h>
#include <cctype>
#include <cstdlib>
#include <cerrno>
#include <algorithm>

namespace Thunder {
namespace TestImplementations {

    class TestOptionalsImpl : public FunctionalTest::ITestOptionals {
    public:
        TestOptionalsImpl() = default;
        ~TestOptionalsImpl() override = default;

        TestOptionalsImpl(const TestOptionalsImpl&) = delete;
        TestOptionalsImpl& operator=(const TestOptionalsImpl&) = delete;

        Core::hresult Add(const uint32_t a, const Core::OptionalType<uint32_t>& b, uint32_t& result) override
        {
            result = a + (b.IsSet() ? b.Value() : 0u);
            return Core::ERROR_NONE;
        }

        Core::hresult Multiply(const int32_t value, const Core::OptionalType<int32_t>& multiplier, int32_t& result) override
        {
            result = value * (multiplier.IsSet() ? multiplier.Value() : 1);
            return Core::ERROR_NONE;
        }

        Core::hresult Concatenate(const string& first, const Core::OptionalType<string>& second, string& result) override
        {
            result = first + (second.IsSet() ? second.Value() : string{});
            return Core::ERROR_NONE;
        }

        Core::hresult Divide(
            const uint32_t dividend, const uint32_t divisor,
            uint32_t& quotient, Core::OptionalType<uint32_t>& remainder) override
        {
            if (divisor == 0) {
                return Core::ERROR_BAD_REQUEST;
            }
            quotient = dividend / divisor;
            if (remainder.IsSet()) {
                remainder = dividend % divisor;
            }
            return Core::ERROR_NONE;
        }

        Core::hresult ParseInt(const string& text, int32_t& value, Core::OptionalType<bool>& success) override
        {
            char* end = nullptr;
            errno = 0;
            long parsed = ::strtol(text.c_str(), &end, 10);
            bool ok = (errno == 0) && (end != text.c_str()) && (*end == '\0');
            value = ok ? static_cast<int32_t>(parsed) : 0;
            if (success.IsSet()) {
                success = ok;
            }
            return Core::ERROR_NONE;
        }

        Core::hresult Format(
            const string& text,
            const Core::OptionalType<string>& prefix,
            const Core::OptionalType<string>& suffix,
            string& result) override
        {
            result  = (prefix.IsSet() ? prefix.Value() : string{});
            result += text;
            result += (suffix.IsSet() ? suffix.Value() : string{});
            return Core::ERROR_NONE;
        }

        Core::hresult Calculate(
            const int32_t value,
            const Core::OptionalType<int32_t>& min,
            const Core::OptionalType<int32_t>& max,
            int32_t& result) override
        {
            result = value;
            if (min.IsSet() && result < min.Value()) result = min.Value();
            if (max.IsSet() && result > max.Value()) result = max.Value();
            return Core::ERROR_NONE;
        }

        Core::hresult ProcessOptionalBuffer(
            const uint8_t* input, const uint16_t inputSize,
            uint8_t* output, const uint16_t maxOutputSize,
            uint16_t& written) override
        {
            written = 0;
            if (maxOutputSize == 0) {
                return Core::ERROR_NONE;
            }
            written = std::min(inputSize, maxOutputSize);
            for (uint16_t i = 0; i < written; ++i) {
                output[i] = static_cast<uint8_t>(~input[i]); // invert bytes as a simple transform
            }
            return Core::ERROR_NONE;
        }

        Core::hresult AllOptional(
            const Core::OptionalType<uint32_t>& a,
            const Core::OptionalType<uint32_t>& b,
            const Core::OptionalType<uint32_t>& c,
            uint32_t& result) override
        {
            result  = (a.IsSet() ? a.Value() : 0u);
            result += (b.IsSet() ? b.Value() : 0u);
            result += (c.IsSet() ? c.Value() : 0u);
            return Core::ERROR_NONE;
        }

        Core::hresult WithDefault(
            const string& value,
            const Core::OptionalType<bool>& uppercase,
            string& result) override
        {
            result = value;
            if (uppercase.IsSet() && uppercase.Value() == true) {
                for (char& c : result) {
                    c = static_cast<char>(::toupper(static_cast<unsigned char>(c)));
                }
            }
            return Core::ERROR_NONE;
        }

        BEGIN_INTERFACE_MAP(TestOptionalsImpl)
        INTERFACE_ENTRY(FunctionalTest::ITestOptionals)
        END_INTERFACE_MAP
    };

    static TestRegistry::ImplementationRegistrar<FunctionalTest::ITestOptionals, TestOptionalsImpl> g_optionalsRegistrar;

} // namespace TestImplementations
} // namespace Thunder
