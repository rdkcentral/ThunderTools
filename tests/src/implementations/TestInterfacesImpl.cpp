/*
 * Copyright 2026 Metrological - Apache 2.0
 *
 * Acquire/Obtain return 'this' cast to void* when the requested interfaceId
 * matches ITestInterfacePointers::ID. The proxy will call QueryInterface on
 * the server-side instance for that ID, which succeeds because the impl is in
 * INTERFACE_MAP. Any other ID returns nullptr / ERROR_UNAVAILABLE.
 *
 * Reset() is @stub: server side exists, proxy returns COM_ERROR|ERROR_UNAVAILABLE.
 * LocalOnly() is @omit: no marshalling code generated at all.
 */

#include "TestRegistry.h"
#include <ITestInterfaces.h>

namespace Thunder {
namespace TestImplementations {

    using namespace FunctionalTest;

    class TestInterfacesImpl : public ITestInterfacePointers {
    public:
        TestInterfacesImpl() = default;
        ~TestInterfacesImpl() override = default;

        TestInterfacesImpl(const TestInterfacesImpl&) = delete;
        TestInterfacesImpl& operator=(const TestInterfacesImpl&) = delete;

        // ===== @interface: void* return =====
        // Returns this as ITestInterfacePointers when asked, nullptr otherwise.
        void* Acquire(const uint32_t interfaceId) override
        {
            if (interfaceId == ITestInterfacePointers::ID) {
                AddRef();
                return static_cast<ITestInterfacePointers*>(this);
            }
            return nullptr;
        }

        Core::hresult Relinquish(const uint32_t interfaceId) override
        {
            if (interfaceId == ITestInterfacePointers::ID) {
                ITestInterfacePointers::Release();
                return Core::ERROR_NONE;
            }
            return Core::ERROR_NOT_EXIST;
        }

        // ===== @interface: void* output parameter =====
        Core::hresult Obtain(const uint32_t interfaceId, void*& instance) override
        {
            if (interfaceId == ITestInterfacePointers::ID) {
                AddRef();
                instance = static_cast<ITestInterfacePointers*>(this);
                return Core::ERROR_NONE;
            }
            instance = nullptr;
            return Core::ERROR_UNAVAILABLE;
        }

        // ===== @stub: server-side only =====
        // Called from the stub; proxy returns COM_ERROR|ERROR_UNAVAILABLE without reaching here.
        Core::hresult Reset() override
        {
            return Core::ERROR_NONE;
        }

        // ===== @omit: no marshalling code generated =====
        // Vtable slot preserved; never called cross-process.
        Core::hresult LocalOnly(const uint32_t hint) override
        {
            (void)hint;
            return Core::ERROR_NONE;
        }

        BEGIN_INTERFACE_MAP(TestInterfacesImpl)
        INTERFACE_ENTRY(ITestInterfacePointers)
        END_INTERFACE_MAP
    };

    static TestRegistry::ImplementationRegistrar<ITestInterfacePointers, TestInterfacesImpl> g_interfacesRegistrar;

} // namespace TestImplementations
} // namespace Thunder
