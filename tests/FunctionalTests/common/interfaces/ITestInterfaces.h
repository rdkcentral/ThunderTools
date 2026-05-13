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

// @stubgen:include <com/ICOM.h>

namespace Thunder {
namespace FunctionalTest {

    // Tests three COM-RPC stub generator control patterns:
    //
    //  1. @ interface — dynamically typed interface pointer passing via void* + uint32_t ID.
    //     The generator emits QueryInterface/AddRef/Release in the proxy instead of a raw
    //     pointer copy. This is the same mechanism used by RPC::IRemoteConnection::Acquire.
    //
    //  2. @ stub — method is present in the stub (server side) but NOT in the proxy (client
    //     side). Used for server-only housekeeping methods that clients should never call.
    //
    //  3. @ omit — method is excluded from BOTH stub and proxy. The virtual slot is preserved
    //     in the vtable but the generator emits no marshalling code for it at all.
    struct EXTERNAL ITestInterfacePointers : virtual public Core::IUnknown {
        enum { ID = ID_TEST_INTERFACE_POINTERS };

        // ===== @ interface: void* return value =====
        // Pattern from RPC::IRemoteConnection::Acquire.
        // @interface:interfaceId on the void* return tells the generator which uint32_t
        // parameter carries the requested interface ID. The proxy calls QueryInterface
        // on the raw pointer and returns the correctly typed result.

        // @brief Acquires an interface by ID.
        // @param interfaceId ID of the interface to acquire (e.g. ITestEnums::ID).
        // @retval ERROR_UNAVAILABLE Interface not available.
        virtual void* /* @interface:interfaceId */ Acquire(const uint32_t interfaceId) = 0;

        // @brief Relinquishes a previously acquired interface.
        virtual Core::hresult Relinquish(const uint32_t interfaceId) = 0;

        // ===== @ interface: void* output parameter =====
        // Same mechanism but as an @ out parameter rather than a return value.
        // Exercises the output-parameter code path in the proxy (distinct from the
        // return-value path above).

        // @brief Acquires an interface into an output parameter.
        // @param interfaceId ID of the interface to acquire.
        // @param instance Acquired interface pointer.
        // @retval ERROR_UNAVAILABLE Interface not available.
        virtual Core::hresult Obtain(
            const uint32_t interfaceId,
            void*& instance /* @out @interface:interfaceId */) = 0;

        // ===== @ interface: void* input parameter =====
        // Passing a dynamically typed interface pointer INTO a method.
        // The proxy calls AddRef before serialising and the stub calls Release on arrival.

        // @brief Submits an interface instance to the server.
        // @param interfaceId ID of the submitted interface.
        // @param instance Interface pointer to submit.
        // virtual Core::hresult Submit(
        //     const uint32_t interfaceId,
        //     void* const instance /* @ in @ interface:interfaceId */) = 0;

        // ===== @ stub =====
        // This method appears in the stub (server-side deserialisation) but NOT in the
        // proxy (client-side serialisation). Useful for internal server housekeeping
        // that must exist in the vtable but must never be called cross-process.
        //
        // The generator emits a stub entry so the server can implement it, but skips
        // the proxy entirely — any client attempting to call it gets a link error.

        // @stub
        // @brief Server-only reset; not callable from a proxy client.
        virtual Core::hresult Reset() = 0;

        // ===== @ omit =====
        // This method is excluded from BOTH stub and proxy. The vtable slot is
        // preserved so the ABI is stable, but the generator emits no marshalling code
        // whatsoever. Typically used for methods that are implemented locally on both
        // sides and must never cross the process boundary.

        // @omit
        // @json:omit
        // @stubgen:omit
        // FIXME: ProxyStub code skips this method, but the virtual functions still need to be implemented on both sides to preserve the vtable layout. 
        //        As a fix just give it a default implementation here in the interface
        //        
        // @brief Local-only helper; no stub or proxy code generated.
        virtual Core::hresult LocalOnly(VARIABLE_IS_NOT_USED const uint32_t hint) {return Core::ERROR_NOT_SUPPORTED;} /* =0 */ ;
    };

} // namespace FunctionalTest
} // namespace Thunder