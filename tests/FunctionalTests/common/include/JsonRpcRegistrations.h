#pragma once

#include <plugins/JSONRPC.h>

namespace Thunder {
namespace Test {
    class JsonRPCRegister : public PluginHost::JSONRPCSupportsEventStatus {
    public:
        JsonRPCRegister() = default;
        ~JsonRPCRegister() = default;

        BEGIN_INTERFACE_MAP(JsonRPCRegister)
        INTERFACE_ENTRY(PluginHost::IDispatcher)
        END_INTERFACE_MAP

        uint32_t AddRef() const override
        {
            return Core::ERROR_COMPOSIT_OBJECT;
        }

        uint32_t Release() const override
        {
            return Core::ERROR_COMPOSIT_OBJECT;
        }
        
    };

    void RegisterJsonRpcInterfaces(JsonRPCRegister& registar);
    void UnregisterJsonRpcInterfaces(JsonRPCRegister& registar);
} // namespace Test
} // namespace Thunder
