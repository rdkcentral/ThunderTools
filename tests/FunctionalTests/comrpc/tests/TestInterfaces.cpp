/*
 * Copyright 2026 Metrological - Apache 2.0
 */

#include <gtest/gtest.h>
#include "TestHarness.h"
#include <ITestInterfaces.h>

using namespace Thunder;
using namespace Thunder::FunctionalTest;

class TestInterfaces : public Testing::TestHarness<ITestInterfacePointers> {};

// ===== @interface: void* return value =====

TEST_F(TestInterfaces, Acquire_KnownId_ReturnsNonNull) {
    // The impl returns 'this' for its own ID.
    // The proxy calls QueryInterface with that ID on the server-side instance.
    void* iface = _proxy->Acquire(ITestInterfacePointers::ID);
    EXPECT_NE(iface, nullptr);
    if (iface != nullptr) {
        // Relinquish the acquired interface via the typed Relinquish method
        _proxy->Relinquish(ITestInterfacePointers::ID);
        static_cast<Core::IUnknown*>(iface)->Release();
    }
}

TEST_F(TestInterfaces, Acquire_UnknownId_ReturnsNull) {
    void* iface = _proxy->Acquire(0xDEADBEEF);
    EXPECT_EQ(iface, nullptr);
}

// ===== @interface: void* output parameter =====

TEST_F(TestInterfaces, Obtain_KnownId_Succeeds) {
    void* instance = nullptr;
    Core::hresult hr = _proxy->Obtain(ITestInterfacePointers::ID, instance);
    EXPECT_EQ(hr, Core::ERROR_NONE);
    EXPECT_NE(instance, nullptr);
    if (instance != nullptr) {
        static_cast<Core::IUnknown*>(instance)->Release();
    }
}

TEST_F(TestInterfaces, Obtain_UnknownId_ReturnsUnavailable) {
    void* instance = nullptr;
    Core::hresult hr = _proxy->Obtain(0xDEADBEEF, instance);
    EXPECT_EQ(hr, Core::ERROR_UNAVAILABLE);
    EXPECT_EQ(instance, nullptr);
}

// ===== @stub: proxy returns error, server impl succeeds =====

TEST_F(TestInterfaces, Reset_ProxyReturnsUnavailable) {
    // @stub means: proxy side has a stub that returns COM_ERROR|ERROR_UNAVAILABLE
    // without making an IPC call. We just verify the call doesn't crash and
    // returns an error (the proxy stub returns COM_ERROR | ERROR_UNAVAILABLE).
    Core::hresult hr = _proxy->Reset();
    EXPECT_NE(hr, Core::ERROR_NONE);
}

// ===== @omit: LocalOnly is not testable cross-process =====
// No test for LocalOnly — @omit means no proxy code is generated.
// Calling _proxy->LocalOnly() would invoke the base class no-op or be a local call only.
// This is validated at compile/link time: the proxy class simply does not override LocalOnly().
