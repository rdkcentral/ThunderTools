/*
 * Copyright 2026 Metrological - Apache 2.0
 *
 * The generator emits ASSERT() checks for @restrict ranges in the stub.
 * These implementations trust that the proxy/stub has already validated;
 * they store the last-written value and answer query helpers.
 */

#include "TestRegistry.h"
#include <ITestRestrictions.h>
#include <cmath>
#include <algorithm>

namespace Thunder {
namespace TestImplementations {

    using namespace FunctionalTest;

    class TestRestrictionsImpl : public ITestRestrictions {
    public:
        TestRestrictionsImpl()
            : _percentage(0)
            , _temperature(0)
            , _ratio(0.0f)
            , _voltage(0.0)
            , _decibels(0.0f)
            , _frequency(20.0)
            , _port(0)
        {
        }
        ~TestRestrictionsImpl() override = default;

        TestRestrictionsImpl(const TestRestrictionsImpl&) = delete;
        TestRestrictionsImpl& operator=(const TestRestrictionsImpl&) = delete;

        // ===== Unsigned integers =====

        Core::hresult SetFixedValue(const uint8_t value) override
        {
            if (value != 42) return Core::ERROR_INVALID_INPUT_LENGTH;
            return Core::ERROR_NONE;
        }

        Core::hresult SetPercentage(const uint8_t percent) override
        {
            if (percent > 100) return Core::ERROR_INVALID_INPUT_LENGTH;
            _percentage = percent;
            return Core::ERROR_NONE;
        }

        Core::hresult SetByte(const uint8_t value, uint8_t& result) override
        { result = value; return Core::ERROR_NONE; }

        // ===== Signed integers =====

        Core::hresult SetTemperature(const int8_t temp) override
        {
            if (temp < -40 || temp > 125) return Core::ERROR_INVALID_INPUT_LENGTH;
            _temperature = temp;
            return Core::ERROR_NONE;
        }

        Core::hresult SetNegative(const int16_t value) override
        {
            if (value < -1000 || value > -1) return Core::ERROR_INVALID_INPUT_LENGTH;
            return Core::ERROR_NONE;
        }

        Core::hresult SetPositiveSigned(const int16_t value) override
        {
            if (value < 1 || value > 1000) return Core::ERROR_INVALID_INPUT_LENGTH;
            return Core::ERROR_NONE;
        }

        Core::hresult SetOffset(const int16_t offset) override
        {
            if (offset < -127 || offset > 127) return Core::ERROR_INVALID_INPUT_LENGTH;
            return Core::ERROR_NONE;
        }

        // ===== Floating point =====

        Core::hresult SetRatio(const float ratio) override
        {
            if (ratio < 0.0f || ratio > 1.0f) return Core::ERROR_INVALID_INPUT_LENGTH;
            _ratio = ratio;
            return Core::ERROR_NONE;
        }

        Core::hresult SetVoltage(const double volts) override
        {
            if (volts < 0.0 || volts > 240.0) return Core::ERROR_INVALID_INPUT_LENGTH;
            _voltage = volts;
            return Core::ERROR_NONE;
        }

        Core::hresult SetDecibels(const float db) override
        {
            if (db < -100.0f || db > 0.0f) return Core::ERROR_INVALID_INPUT_LENGTH;
            _decibels = db;
            return Core::ERROR_NONE;
        }

        Core::hresult SetFrequency(const double hz) override
        {
            if (hz < 20.0 || hz > 20000.0) return Core::ERROR_INVALID_INPUT_LENGTH;
            _frequency = hz;
            return Core::ERROR_NONE;
        }

        // ===== Strings =====

        Core::hresult SetName(const string& name) override
        {
            if (name.empty() || name.size() > 64) return Core::ERROR_INVALID_INPUT_LENGTH;
            _name = name;
            return Core::ERROR_NONE;
        }

        Core::hresult SetUsername(const string& username) override
        {
            if (username.empty()) return Core::ERROR_INVALID_INPUT_LENGTH;
            _username = username;
            return Core::ERROR_NONE;
        }

        // ===== Multi-param =====

        Core::hresult ClampedAdd(const int8_t a, const int8_t b, int16_t& result) const override
        {
            if (a < -100 || a > 100) return Core::ERROR_INVALID_INPUT_LENGTH;
            if (b < -100 || b > 100) return Core::ERROR_INVALID_INPUT_LENGTH;
            result = static_cast<int16_t>(a) + static_cast<int16_t>(b);
            return Core::ERROR_NONE;
        }

        Core::hresult Configure(const uint8_t mode, const uint16_t timeout, const float gain) override
        {
            if (mode > 3) return Core::ERROR_INVALID_INPUT_LENGTH;
            if (timeout < 100 || timeout > 30000) return Core::ERROR_INVALID_INPUT_LENGTH;
            if (gain < 0.0f || gain > 10.0f) return Core::ERROR_INVALID_INPUT_LENGTH;
            return Core::ERROR_NONE;
        }

        // ===== Reference params with restrictions =====

        Core::hresult GetRange(uint8_t& min, uint8_t& max) const override
        { min = 0; max = 100; return Core::ERROR_NONE; }

        Core::hresult ClampValue(int16_t& value) override
        {
            if (value < -1000) value = -1000;
            if (value >  1000) value =  1000;
            return Core::ERROR_NONE;
        }

        Core::hresult GetPercentage(uint8_t& value) const override
        { value = _percentage; return Core::ERROR_NONE; }

        Core::hresult GetRatio(float& value) const override
        { value = _ratio; return Core::ERROR_NONE; }

        // ===== Edge cases =====

        Core::hresult SetPageSize(const uint16_t size) override
        {
            if (size != 4096) return Core::ERROR_INVALID_INPUT_LENGTH;
            return Core::ERROR_NONE;
        }

        Core::hresult SetPort(const Core::OptionalType<uint16_t>& port) override
        {
            if (port.IsSet()) {
                if (port.Value() < 1)
                    return Core::ERROR_INVALID_INPUT_LENGTH;
                _port = port.Value();
            }
            return Core::ERROR_NONE;
        }

        // ===== Validation helpers =====

        Core::hresult IsValidPercentage(const uint8_t value, bool& valid) const override
        { valid = (value <= 100); return Core::ERROR_NONE; }

        Core::hresult IsValidTemperature(const int32_t temp, bool& valid) const override
        { valid = (temp >= -40 && temp <= 125); return Core::ERROR_NONE; }

        Core::hresult IsValidRatio(const float ratio, bool& valid) const override
        { valid = (ratio >= 0.0f && ratio <= 1.0f); return Core::ERROR_NONE; }

        Core::hresult GetPercentageRange(uint8_t& min, uint8_t& max) const override
        { min = 0; max = 100; return Core::ERROR_NONE; }

        Core::hresult GetTemperatureRange(int32_t& min, int32_t& max) const override
        { min = -40; max = 125; return Core::ERROR_NONE; }

        BEGIN_INTERFACE_MAP(TestRestrictionsImpl)
        INTERFACE_ENTRY(ITestRestrictions)
        END_INTERFACE_MAP

    private:
        uint8_t  _percentage;
        int8_t   _temperature;
        float    _ratio;
        double   _voltage;
        float    _decibels;
        double   _frequency;
        uint16_t _port;
        string   _name;
        string   _username;
    };

    static TestRegistry::ImplementationRegistrar<ITestRestrictions, TestRestrictionsImpl> g_restrictionsRegistrar;

} // namespace TestImplementations
} // namespace Thunder
