/*
 * Copyright 2026 Metrological - Apache 2.0
 */

#include "TestRegistry.h"
#include <ITestEnums.h>

#ifdef BUILD_JSON_RPC_TESTS
#include "JsonRpcServer.h"
#include <JTestEnums.h>
#endif

namespace Thunder {
namespace TestImplementations {

    using namespace FunctionalTest;

    class TestEnumsImpl : public ITestEnums {
    public:
        TestEnumsImpl()
            : _activeColor(ITestEnums::RED)
            , _currentState(ITestEnums::IDLE)
            , _requestedPriority(ITestEnums::NORMAL)
            , _capabilities(ITestEnums::CAP_NONE)
        {
        }
        ~TestEnumsImpl() override = default;

        TestEnumsImpl(const TestEnumsImpl&) = delete;
        TestEnumsImpl& operator=(const TestEnumsImpl&) = delete;

        // ===== Properties =====

        Core::hresult ActiveColor(ITestEnums::Color& color) const override
        { color = _activeColor; return Core::ERROR_NONE; }

        Core::hresult ActiveColor(const ITestEnums::Color color) override
        { _activeColor = color; return Core::ERROR_NONE; }

        Core::hresult CurrentState(ITestEnums::State& state) const override
        { state = _currentState; return Core::ERROR_NONE; }

        Core::hresult RequestedPriority(const ITestEnums::Priority priority) override
        { _requestedPriority = priority; return Core::ERROR_NONE; }

        Core::hresult GetCapabilities(ITestEnums::Capabilities& caps) const override
        { caps = _capabilities; return Core::ERROR_NONE; }

        Core::hresult SetCapabilities(const ITestEnums::Capabilities caps) override
        { _capabilities = caps; return Core::ERROR_NONE; }

        // ===== Set methods =====

        Core::hresult SetColor(const ITestEnums::Color color) override
        { _activeColor = color; return Core::ERROR_NONE; }

        Core::hresult SetState(const ITestEnums::State state) override
        { _currentState = state; return Core::ERROR_NONE; }

        Core::hresult SetPriority(const ITestEnums::Priority priority) override
        { _requestedPriority = priority; return Core::ERROR_NONE; }

        // ===== Get methods =====

        Core::hresult GetColor(ITestEnums::Color& color) const override
        { color = _activeColor; return Core::ERROR_NONE; }

        Core::hresult GetState(ITestEnums::State& state) const override
        { state = _currentState; return Core::ERROR_NONE; }

        Core::hresult GetPriority(ITestEnums::Priority& priority) const override
        { priority = _requestedPriority; return Core::ERROR_NONE; }

        // ===== Inout =====

        Core::hresult ToggleColor(ITestEnums::Color& color) override
        {
            static const ITestEnums::Color cycle[] = { RED, GREEN, BLUE, YELLOW };
            for (int i = 0; i < 4; ++i) {
                if (color == cycle[i]) {
                    color = cycle[(i + 1) % 4];
                    return Core::ERROR_NONE;
                }
            }
            color = RED;
            return Core::ERROR_NONE;
        }

        Core::hresult NextState(ITestEnums::State& state) override
        {
            static const ITestEnums::State cycle[] = { IDLE, RUNNING, PAUSED, STOPPED, ERROR };
            for (int i = 0; i < 5; ++i) {
                if (state == cycle[i]) {
                    state = cycle[(i + 1) % 5];
                    return Core::ERROR_NONE;
                }
            }
            state = IDLE;
            return Core::ERROR_NONE;
        }

        // ===== Multi-param =====

        Core::hresult CompareColors(const ITestEnums::Color c1, const ITestEnums::Color c2, bool& equal) const override
        { equal = (c1 == c2); return Core::ERROR_NONE; }

        Core::hresult ComputeState(
            const ITestEnums::State current,
            const ITestEnums::State desired,
            ITestEnums::State& result) const override
        {
            if (current == desired) {
                result = RUNNING;
            } else {
                result = PAUSED;
            }
            return Core::ERROR_NONE;
        }

        // ===== Optional =====

        Core::hresult SetColorWithDefault(const Core::OptionalType<ITestEnums::Color>& color) override
        {
            _activeColor = color.IsSet() ? color.Value() : RED;
            return Core::ERROR_NONE;
        }

        Core::hresult AdjustPriority(
            const ITestEnums::Priority base,
            const Core::OptionalType<ITestEnums::Priority>& modifier,
            ITestEnums::Priority& result) const override
        {
            if (!modifier.IsSet()) {
                result = base;
                return Core::ERROR_NONE;
            }
            // Add raw values and clamp to valid enum values
            uint16_t adjusted = static_cast<uint16_t>(base) + static_cast<uint16_t>(modifier.Value());
            if (adjusted >= static_cast<uint16_t>(CRITICAL)) {
                result = CRITICAL;
            } else if (adjusted >= static_cast<uint16_t>(HIGH)) {
                result = HIGH;
            } else if (adjusted >= static_cast<uint16_t>(NORMAL)) {
                result = NORMAL;
            } else {
                result = LOW;
            }
            return Core::ERROR_NONE;
        }

        // ===== Edge cases =====

        Core::hresult EchoColor(const ITestEnums::Color color, ITestEnums::Color& result) const override
        { result = color; return Core::ERROR_NONE; }

        Core::hresult IsValidState(const ITestEnums::State state, bool& valid) const override
        {
            valid = (state == IDLE || state == RUNNING || state == PAUSED ||
                     state == STOPPED || state == ERROR);
            return Core::ERROR_NONE;
        }

        Core::hresult ColorToString(const ITestEnums::Color color, string& result) const override
        {
            switch (color) {
                case RED:    result = "red";    break;
                case GREEN:  result = "green";  break;
                case BLUE:   result = "blue";   break;
                case YELLOW: result = "yellow"; break;
                default:     result = "unknown"; break;
            }
            return Core::ERROR_NONE;
        }

        BEGIN_INTERFACE_MAP(TestEnumsImpl)
        INTERFACE_ENTRY(ITestEnums)
        END_INTERFACE_MAP

    private:
        ITestEnums::Color        _activeColor;
        ITestEnums::State        _currentState;
        ITestEnums::Priority     _requestedPriority;
        ITestEnums::Capabilities _capabilities;
    };

    static TestRegistry::ImplementationRegistrar<ITestEnums, TestEnumsImpl> g_enumsRegistrar;
#ifdef BUILD_JSON_RPC_TESTS
    static JsonRpcServer::JsonRpcRegistrar<FunctionalTest::ITestEnums, TestEnumsImpl> g_jsonrpc_enumsRegistrar(FunctionalTest::JTestEnums::Register<JsonRpcServer::JsonRpcServer>);
#endif
} // namespace TestImplementations
} // namespace Thunder
