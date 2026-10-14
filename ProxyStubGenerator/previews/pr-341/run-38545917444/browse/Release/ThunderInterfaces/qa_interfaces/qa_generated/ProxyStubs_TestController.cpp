//
// generated automatically from "ITestController.h"
//
// implements COM-RPC proxy stubs for:
//   - class QualityAssurance::ITestController
//   - class QualityAssurance::ITestController::ITest
//   - class QualityAssurance::ITestController::ITest::IIterator
//   - class QualityAssurance::ITestController::ICategory
//   - class QualityAssurance::ITestController::ICategory::IIterator
//
// secure code enabled:
//   - instance verification enabled
//   - range verification enabled
//   - frame coherency verification enabled
//

#include "Module.h"
#include "ITestController.h"

#include <com/com.h>

namespace Thunder {

namespace ProxyStubs {

    PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    // -----------------------------------------------------------------
    // STUBS
    // -----------------------------------------------------------------

    //
    // QualityAssurance::ITestController interface stub definitions
    //
    // Methods:
    //  (0) virtual void Setup() = 0
    //  (1) virtual void TearDown() = 0
    //  (2) virtual QualityAssurance::ITestController::ICategory::IIterator* Categories() const = 0
    //  (3) virtual QualityAssurance::ITestController::ICategory* Category(const string&) const = 0
    //

    static ProxyStub::MethodHandler QualityAssuranceTestControllerStubMethods[] = {
        // (0) virtual void Setup() = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                QualityAssurance::ITestController* implementation = reinterpret_cast<QualityAssurance::ITestController*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), QualityAssurance::ITestController::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                implementation->Setup();

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", QualityAssurance::ITestController::ID, 0, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        },

        // (1) virtual void TearDown() = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                QualityAssurance::ITestController* implementation = reinterpret_cast<QualityAssurance::ITestController*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), QualityAssurance::ITestController::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                implementation->TearDown();

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", QualityAssurance::ITestController::ID, 1, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        },

        // (2) virtual QualityAssurance::ITestController::ICategory::IIterator* Categories() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const QualityAssurance::ITestController* implementation = reinterpret_cast<const QualityAssurance::ITestController*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), QualityAssurance::ITestController::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                QualityAssurance::ITestController::ICategory::IIterator* result = implementation->Categories();

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<Core::instance_id>(RPC::instance_cast(result));

                RPC::Administrator::Instance().RegisterInterface(channel, result);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", QualityAssurance::ITestController::ID, 2, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        },

        // (3) virtual QualityAssurance::ITestController::ICategory* Category(const string&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const QualityAssurance::ITestController* implementation = reinterpret_cast<const QualityAssurance::ITestController*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), QualityAssurance::ITestController::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint16_t _categoryPeekedLen__ = reader.PeekNumber<uint16_t>();
                if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint16_t>()) + _categoryPeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const string _category = reader.Text();

                QualityAssurance::ITestController::ICategory* result = implementation->Category(static_cast<const string&>(_category));

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<Core::instance_id>(RPC::instance_cast(result));

                RPC::Administrator::Instance().RegisterInterface(channel, result);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", QualityAssurance::ITestController::ID, 3, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        }
        , nullptr
    }; // QualityAssuranceTestControllerStubMethods

    //
    // QualityAssurance::ITestController::ITest interface stub definitions
    //
    // Methods:
    //  (0) virtual string Execute(const string&) = 0
    //  (1) virtual string Description() const = 0
    //  (2) virtual string Name() const = 0
    //

    static ProxyStub::MethodHandler QualityAssuranceTestControllerTestStubMethods[] = {
        // (0) virtual string Execute(const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                QualityAssurance::ITestController::ITest* implementation = reinterpret_cast<QualityAssurance::ITestController::ITest*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), QualityAssurance::ITestController::ITest::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint16_t _paramsPeekedLen__ = reader.PeekNumber<uint16_t>();
                if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint16_t>()) + _paramsPeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const string _params = reader.Text();

                string result = implementation->Execute(static_cast<const string&>(_params));

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Text(result);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", QualityAssurance::ITestController::ITest::ID, 0, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        },

        // (1) virtual string Description() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const QualityAssurance::ITestController::ITest* implementation = reinterpret_cast<const QualityAssurance::ITestController::ITest*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), QualityAssurance::ITestController::ITest::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                string result = implementation->Description();

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Text(result);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", QualityAssurance::ITestController::ITest::ID, 1, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        },

        // (2) virtual string Name() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const QualityAssurance::ITestController::ITest* implementation = reinterpret_cast<const QualityAssurance::ITestController::ITest*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), QualityAssurance::ITestController::ITest::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                string result = implementation->Name();

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Text(result);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", QualityAssurance::ITestController::ITest::ID, 2, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        }
        , nullptr
    }; // QualityAssuranceTestControllerTestStubMethods

    //
    // QualityAssurance::ITestController::ITest::IIterator interface stub definitions
    //
    // Methods:
    //  (0) virtual void Reset() = 0
    //  (1) virtual bool IsValid() const = 0
    //  (2) virtual bool Next() = 0
    //  (3) virtual QualityAssurance::ITestController::ITest* Test() const = 0
    //

    static ProxyStub::MethodHandler QualityAssuranceTestControllerTestIteratorStubMethods[] = {
        // (0) virtual void Reset() = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                QualityAssurance::ITestController::ITest::IIterator* implementation = reinterpret_cast<QualityAssurance::ITestController::ITest::IIterator*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), QualityAssurance::ITestController::ITest::IIterator::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                implementation->Reset();

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", QualityAssurance::ITestController::ITest::IIterator::ID, 0, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        },

        // (1) virtual bool IsValid() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const QualityAssurance::ITestController::ITest::IIterator* implementation = reinterpret_cast<const QualityAssurance::ITestController::ITest::IIterator*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), QualityAssurance::ITestController::ITest::IIterator::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                bool result = implementation->IsValid();

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Boolean(result);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", QualityAssurance::ITestController::ITest::IIterator::ID, 1, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        },

        // (2) virtual bool Next() = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                QualityAssurance::ITestController::ITest::IIterator* implementation = reinterpret_cast<QualityAssurance::ITestController::ITest::IIterator*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), QualityAssurance::ITestController::ITest::IIterator::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                bool result = implementation->Next();

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Boolean(result);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", QualityAssurance::ITestController::ITest::IIterator::ID, 2, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        },

        // (3) virtual QualityAssurance::ITestController::ITest* Test() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const QualityAssurance::ITestController::ITest::IIterator* implementation = reinterpret_cast<const QualityAssurance::ITestController::ITest::IIterator*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), QualityAssurance::ITestController::ITest::IIterator::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                QualityAssurance::ITestController::ITest* result = implementation->Test();

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<Core::instance_id>(RPC::instance_cast(result));

                RPC::Administrator::Instance().RegisterInterface(channel, result);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", QualityAssurance::ITestController::ITest::IIterator::ID, 3, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        }
        , nullptr
    }; // QualityAssuranceTestControllerTestIteratorStubMethods

    //
    // QualityAssurance::ITestController::ICategory interface stub definitions
    //
    // Methods:
    //  (0) virtual string Name() const = 0
    //  (1) virtual void Setup() = 0
    //  (2) virtual void TearDown() = 0
    //  (3) virtual void Register(QualityAssurance::ITestController::ITest*) = 0
    //  (4) virtual void Unregister(QualityAssurance::ITestController::ITest*) = 0
    //  (5) virtual QualityAssurance::ITestController::ITest::IIterator* Tests() const = 0
    //  (6) virtual QualityAssurance::ITestController::ITest* Test(const string&) const = 0
    //

    static ProxyStub::MethodHandler QualityAssuranceTestControllerCategoryStubMethods[] = {
        // (0) virtual string Name() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const QualityAssurance::ITestController::ICategory* implementation = reinterpret_cast<const QualityAssurance::ITestController::ICategory*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), QualityAssurance::ITestController::ICategory::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                string result = implementation->Name();

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Text(result);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", QualityAssurance::ITestController::ICategory::ID, 0, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        },

        // (1) virtual void Setup() = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                QualityAssurance::ITestController::ICategory* implementation = reinterpret_cast<QualityAssurance::ITestController::ICategory*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), QualityAssurance::ITestController::ICategory::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                implementation->Setup();

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", QualityAssurance::ITestController::ICategory::ID, 1, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        },

        // (2) virtual void TearDown() = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                QualityAssurance::ITestController::ICategory* implementation = reinterpret_cast<QualityAssurance::ITestController::ICategory*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), QualityAssurance::ITestController::ICategory::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                implementation->TearDown();

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", QualityAssurance::ITestController::ICategory::ID, 2, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        },

        // (3) virtual void Register(QualityAssurance::ITestController::ITest*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                QualityAssurance::ITestController::ICategory* implementation = reinterpret_cast<QualityAssurance::ITestController::ICategory*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), QualityAssurance::ITestController::ICategory::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (sizeof(Core::instance_id))) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                Core::instance_id _testInstanceId__ = reader.Number<Core::instance_id>();

                QualityAssurance::ITestController::ITest* _test{};
                ProxyStub::UnknownProxy* _testProxy__ = nullptr;
                if (_testInstanceId__ != 0) {
                    _testProxy__ = RPC::Administrator::Instance().ProxyInstance(channel, _testInstanceId__, false, _test);
                    ASSERT((_test != nullptr) && (_testProxy__ != nullptr));
                    if ((_test == nullptr) || (_testProxy__ == nullptr)) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }
                }

                implementation->Register(_test);

                if (_testProxy__ != nullptr) {
                    RPC::Administrator::Instance().Release(_testProxy__, message->Response());
                }

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", QualityAssurance::ITestController::ICategory::ID, 3, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        },

        // (4) virtual void Unregister(QualityAssurance::ITestController::ITest*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                QualityAssurance::ITestController::ICategory* implementation = reinterpret_cast<QualityAssurance::ITestController::ICategory*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), QualityAssurance::ITestController::ICategory::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (sizeof(Core::instance_id))) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                Core::instance_id _testInstanceId__ = reader.Number<Core::instance_id>();

                QualityAssurance::ITestController::ITest* _test{};
                ProxyStub::UnknownProxy* _testProxy__ = nullptr;
                if (_testInstanceId__ != 0) {
                    _testProxy__ = RPC::Administrator::Instance().ProxyInstance(channel, _testInstanceId__, false, _test);
                    ASSERT((_test != nullptr) && (_testProxy__ != nullptr));
                    if ((_test == nullptr) || (_testProxy__ == nullptr)) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }
                }

                implementation->Unregister(_test);

                if (_testProxy__ != nullptr) {
                    RPC::Administrator::Instance().Release(_testProxy__, message->Response());
                }

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", QualityAssurance::ITestController::ICategory::ID, 4, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        },

        // (5) virtual QualityAssurance::ITestController::ITest::IIterator* Tests() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const QualityAssurance::ITestController::ICategory* implementation = reinterpret_cast<const QualityAssurance::ITestController::ICategory*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), QualityAssurance::ITestController::ICategory::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                QualityAssurance::ITestController::ITest::IIterator* result = implementation->Tests();

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<Core::instance_id>(RPC::instance_cast(result));

                RPC::Administrator::Instance().RegisterInterface(channel, result);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", QualityAssurance::ITestController::ICategory::ID, 5, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        },

        // (6) virtual QualityAssurance::ITestController::ITest* Test(const string&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const QualityAssurance::ITestController::ICategory* implementation = reinterpret_cast<const QualityAssurance::ITestController::ICategory*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), QualityAssurance::ITestController::ICategory::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint16_t _namePeekedLen__ = reader.PeekNumber<uint16_t>();
                if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint16_t>()) + _namePeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const string _name = reader.Text();

                QualityAssurance::ITestController::ITest* result = implementation->Test(static_cast<const string&>(_name));

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<Core::instance_id>(RPC::instance_cast(result));

                RPC::Administrator::Instance().RegisterInterface(channel, result);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", QualityAssurance::ITestController::ICategory::ID, 6, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        }
        , nullptr
    }; // QualityAssuranceTestControllerCategoryStubMethods

    //
    // QualityAssurance::ITestController::ICategory::IIterator interface stub definitions
    //
    // Methods:
    //  (0) virtual void Reset() = 0
    //  (1) virtual bool IsValid() const = 0
    //  (2) virtual bool Next() = 0
    //  (3) virtual QualityAssurance::ITestController::ICategory* Category() const = 0
    //

    static ProxyStub::MethodHandler QualityAssuranceTestControllerCategoryIteratorStubMethods[] = {
        // (0) virtual void Reset() = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                QualityAssurance::ITestController::ICategory::IIterator* implementation = reinterpret_cast<QualityAssurance::ITestController::ICategory::IIterator*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), QualityAssurance::ITestController::ICategory::IIterator::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                implementation->Reset();

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", QualityAssurance::ITestController::ICategory::IIterator::ID, 0, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        },

        // (1) virtual bool IsValid() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const QualityAssurance::ITestController::ICategory::IIterator* implementation = reinterpret_cast<const QualityAssurance::ITestController::ICategory::IIterator*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), QualityAssurance::ITestController::ICategory::IIterator::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                bool result = implementation->IsValid();

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Boolean(result);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", QualityAssurance::ITestController::ICategory::IIterator::ID, 1, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        },

        // (2) virtual bool Next() = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                QualityAssurance::ITestController::ICategory::IIterator* implementation = reinterpret_cast<QualityAssurance::ITestController::ICategory::IIterator*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), QualityAssurance::ITestController::ICategory::IIterator::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                bool result = implementation->Next();

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Boolean(result);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", QualityAssurance::ITestController::ICategory::IIterator::ID, 2, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        },

        // (3) virtual QualityAssurance::ITestController::ICategory* Category() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const QualityAssurance::ITestController::ICategory::IIterator* implementation = reinterpret_cast<const QualityAssurance::ITestController::ICategory::IIterator*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), QualityAssurance::ITestController::ICategory::IIterator::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                QualityAssurance::ITestController::ICategory* result = implementation->Category();

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<Core::instance_id>(RPC::instance_cast(result));

                RPC::Administrator::Instance().RegisterInterface(channel, result);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", QualityAssurance::ITestController::ICategory::IIterator::ID, 3, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        }
        , nullptr
    }; // QualityAssuranceTestControllerCategoryIteratorStubMethods

    // -----------------------------------------------------------------
    // PROXIES
    // -----------------------------------------------------------------

    //
    // QualityAssurance::ITestController interface proxy definitions
    //
    // Methods:
    //  (0) virtual void Setup() = 0
    //  (1) virtual void TearDown() = 0
    //  (2) virtual QualityAssurance::ITestController::ICategory::IIterator* Categories() const = 0
    //  (3) virtual QualityAssurance::ITestController::ICategory* Category(const string&) const = 0
    //

    class QualityAssuranceTestControllerProxy final : public ProxyStub::UnknownProxyType<QualityAssurance::ITestController> {
    public:
        QualityAssuranceTestControllerProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        void Setup() override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", QualityAssurance::ITestController::ID, 0, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        }

        void TearDown() override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", QualityAssurance::ITestController::ID, 1, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        }

        QualityAssurance::ITestController::ICategory::IIterator* Categories() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(2));

            QualityAssurance::ITestController::ICategory::IIterator* result{};

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    result = reinterpret_cast<QualityAssurance::ITestController::ICategory::IIterator*>(static_cast<const ProxyStub::UnknownProxy&>(*this).Interface(reader.Number<Core::instance_id>(), QualityAssurance::ITestController::ICategory::IIterator::ID));

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", QualityAssurance::ITestController::ID, 2, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }

            return (result);
        }

        QualityAssurance::ITestController::ICategory* Category(const string& _category) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(3));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_category);

            QualityAssurance::ITestController::ICategory* result{};

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    result = reinterpret_cast<QualityAssurance::ITestController::ICategory*>(static_cast<const ProxyStub::UnknownProxy&>(*this).Interface(reader.Number<Core::instance_id>(), QualityAssurance::ITestController::ICategory::ID));

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", QualityAssurance::ITestController::ID, 3, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }

            return (result);
        }

    }; // class QualityAssuranceTestControllerProxy

    //
    // QualityAssurance::ITestController::ITest interface proxy definitions
    //
    // Methods:
    //  (0) virtual string Execute(const string&) = 0
    //  (1) virtual string Description() const = 0
    //  (2) virtual string Name() const = 0
    //

    class QualityAssuranceTestControllerTestProxy final : public ProxyStub::UnknownProxyType<QualityAssurance::ITestController::ITest> {
    public:
        QualityAssuranceTestControllerTestProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        string Execute(const string& _params) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_params);

            string result{};

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    const uint16_t resultPeekedLen__ = reader.PeekNumber<uint16_t>();
                    if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint16_t>()) + resultPeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    result = reader.Text();

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", QualityAssurance::ITestController::ITest::ID, 0, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }

            return (result);
        }

        string Description() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            string result{};

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    const uint16_t resultPeekedLen__ = reader.PeekNumber<uint16_t>();
                    if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint16_t>()) + resultPeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    result = reader.Text();

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", QualityAssurance::ITestController::ITest::ID, 1, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }

            return (result);
        }

        string Name() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(2));

            string result{};

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    const uint16_t resultPeekedLen__ = reader.PeekNumber<uint16_t>();
                    if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint16_t>()) + resultPeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    result = reader.Text();

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", QualityAssurance::ITestController::ITest::ID, 2, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }

            return (result);
        }

    }; // class QualityAssuranceTestControllerTestProxy

    //
    // QualityAssurance::ITestController::ITest::IIterator interface proxy definitions
    //
    // Methods:
    //  (0) virtual void Reset() = 0
    //  (1) virtual bool IsValid() const = 0
    //  (2) virtual bool Next() = 0
    //  (3) virtual QualityAssurance::ITestController::ITest* Test() const = 0
    //

    class QualityAssuranceTestControllerTestIteratorProxy final : public ProxyStub::UnknownProxyType<QualityAssurance::ITestController::ITest::IIterator> {
    public:
        QualityAssuranceTestControllerTestIteratorProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        void Reset() override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", QualityAssurance::ITestController::ITest::IIterator::ID, 0, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        }

        bool IsValid() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            bool result{};

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (1)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    result = reader.Boolean();

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", QualityAssurance::ITestController::ITest::IIterator::ID, 1, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }

            return (result);
        }

        bool Next() override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(2));

            bool result{};

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (1)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    result = reader.Boolean();

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", QualityAssurance::ITestController::ITest::IIterator::ID, 2, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }

            return (result);
        }

        QualityAssurance::ITestController::ITest* Test() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(3));

            QualityAssurance::ITestController::ITest* result{};

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    result = reinterpret_cast<QualityAssurance::ITestController::ITest*>(static_cast<const ProxyStub::UnknownProxy&>(*this).Interface(reader.Number<Core::instance_id>(), QualityAssurance::ITestController::ITest::ID));

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", QualityAssurance::ITestController::ITest::IIterator::ID, 3, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }

            return (result);
        }

    }; // class QualityAssuranceTestControllerTestIteratorProxy

    //
    // QualityAssurance::ITestController::ICategory interface proxy definitions
    //
    // Methods:
    //  (0) virtual string Name() const = 0
    //  (1) virtual void Setup() = 0
    //  (2) virtual void TearDown() = 0
    //  (3) virtual void Register(QualityAssurance::ITestController::ITest*) = 0
    //  (4) virtual void Unregister(QualityAssurance::ITestController::ITest*) = 0
    //  (5) virtual QualityAssurance::ITestController::ITest::IIterator* Tests() const = 0
    //  (6) virtual QualityAssurance::ITestController::ITest* Test(const string&) const = 0
    //

    class QualityAssuranceTestControllerCategoryProxy final : public ProxyStub::UnknownProxyType<QualityAssurance::ITestController::ICategory> {
    public:
        QualityAssuranceTestControllerCategoryProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        string Name() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            string result{};

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    const uint16_t resultPeekedLen__ = reader.PeekNumber<uint16_t>();
                    if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint16_t>()) + resultPeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    result = reader.Text();

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", QualityAssurance::ITestController::ICategory::ID, 0, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }

            return (result);
        }

        void Setup() override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", QualityAssurance::ITestController::ICategory::ID, 1, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        }

        void TearDown() override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(2));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", QualityAssurance::ITestController::ICategory::ID, 2, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        }

        void Register(QualityAssurance::ITestController::ITest* _test) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(3));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_test));

            const RPC::InstanceRecord passedInstances[] = { { RPC::instance_cast(_test), QualityAssurance::ITestController::ITest::ID }, { 0, 0 } };
            static_cast<const ProxyStub::UnknownProxy&>(*this).Channel()->CustomData(passedInstances);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());

                    const uint32_t completeResult__ = _Complete(reader);
                    if (completeResult__ != Core::ERROR_NONE) { return (completeResult__); }

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", QualityAssurance::ITestController::ICategory::ID, 3, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }

            static_cast<const ProxyStub::UnknownProxy&>(*this).Channel()->CustomData(nullptr);
        }

        void Unregister(QualityAssurance::ITestController::ITest* _test) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(4));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_test));

            const RPC::InstanceRecord passedInstances[] = { { RPC::instance_cast(_test), QualityAssurance::ITestController::ITest::ID }, { 0, 0 } };
            static_cast<const ProxyStub::UnknownProxy&>(*this).Channel()->CustomData(passedInstances);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());

                    const uint32_t completeResult__ = _Complete(reader);
                    if (completeResult__ != Core::ERROR_NONE) { return (completeResult__); }

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", QualityAssurance::ITestController::ICategory::ID, 4, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }

            static_cast<const ProxyStub::UnknownProxy&>(*this).Channel()->CustomData(nullptr);
        }

        QualityAssurance::ITestController::ITest::IIterator* Tests() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(5));

            QualityAssurance::ITestController::ITest::IIterator* result{};

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    result = reinterpret_cast<QualityAssurance::ITestController::ITest::IIterator*>(static_cast<const ProxyStub::UnknownProxy&>(*this).Interface(reader.Number<Core::instance_id>(), QualityAssurance::ITestController::ITest::IIterator::ID));

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", QualityAssurance::ITestController::ICategory::ID, 5, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }

            return (result);
        }

        QualityAssurance::ITestController::ITest* Test(const string& _name) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(6));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_name);

            QualityAssurance::ITestController::ITest* result{};

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    result = reinterpret_cast<QualityAssurance::ITestController::ITest*>(static_cast<const ProxyStub::UnknownProxy&>(*this).Interface(reader.Number<Core::instance_id>(), QualityAssurance::ITestController::ITest::ID));

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", QualityAssurance::ITestController::ICategory::ID, 6, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }

            return (result);
        }

    private:
        uint32_t _Complete(RPC::Data::Frame::Reader& reader) const
        {
            uint32_t result = Core::ERROR_NONE;

            while (reader.HasData() == true) {
                const size_t entrySize = (sizeof(Core::instance_id) + sizeof(uint32_t) + sizeof(RPC::Data::Output::mode));
                if (reader.Length() < entrySize) { result = (COM_ERROR | Core::ERROR_READ_ERROR); break; }

                const Core::instance_id implementation = reader.Number<Core::instance_id>();
                ASSERT(implementation != 0);

                const uint32_t id = reader.Number<uint32_t>();
                const RPC::Data::Output::mode how = reader.Number<RPC::Data::Output::mode>();

                if (RPC::Administrator::Instance().IsValid(static_cast<const ProxyStub::UnknownProxy&>(*this).Channel(), implementation, id) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                result = static_cast<const ProxyStub::UnknownProxy&>(*this).Complete(implementation, id, how);
                if (result != Core::ERROR_NONE) { return (COM_ERROR | result); }
            }

            return (result);
        }

    }; // class QualityAssuranceTestControllerCategoryProxy

    //
    // QualityAssurance::ITestController::ICategory::IIterator interface proxy definitions
    //
    // Methods:
    //  (0) virtual void Reset() = 0
    //  (1) virtual bool IsValid() const = 0
    //  (2) virtual bool Next() = 0
    //  (3) virtual QualityAssurance::ITestController::ICategory* Category() const = 0
    //

    class QualityAssuranceTestControllerCategoryIteratorProxy final : public ProxyStub::UnknownProxyType<QualityAssurance::ITestController::ICategory::IIterator> {
    public:
        QualityAssuranceTestControllerCategoryIteratorProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        void Reset() override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", QualityAssurance::ITestController::ICategory::IIterator::ID, 0, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        }

        bool IsValid() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            bool result{};

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (1)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    result = reader.Boolean();

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", QualityAssurance::ITestController::ICategory::IIterator::ID, 1, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }

            return (result);
        }

        bool Next() override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(2));

            bool result{};

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (1)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    result = reader.Boolean();

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", QualityAssurance::ITestController::ICategory::IIterator::ID, 2, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }

            return (result);
        }

        QualityAssurance::ITestController::ICategory* Category() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(3));

            QualityAssurance::ITestController::ICategory* result{};

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    result = reinterpret_cast<QualityAssurance::ITestController::ICategory*>(static_cast<const ProxyStub::UnknownProxy&>(*this).Interface(reader.Number<Core::instance_id>(), QualityAssurance::ITestController::ICategory::ID));

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", QualityAssurance::ITestController::ICategory::IIterator::ID, 3, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }

            return (result);
        }

    }; // class QualityAssuranceTestControllerCategoryIteratorProxy

    POP_WARNING()
    POP_WARNING()

    // -----------------------------------------------------------------
    // REGISTRATION
    // -----------------------------------------------------------------
    namespace {

        typedef ProxyStub::UnknownStubType<QualityAssurance::ITestController, QualityAssuranceTestControllerStubMethods> QualityAssuranceTestControllerStub;
        typedef ProxyStub::UnknownStubType<QualityAssurance::ITestController::ITest, QualityAssuranceTestControllerTestStubMethods> QualityAssuranceTestControllerTestStub;
        typedef ProxyStub::UnknownStubType<QualityAssurance::ITestController::ITest::IIterator, QualityAssuranceTestControllerTestIteratorStubMethods> QualityAssuranceTestControllerTestIteratorStub;
        typedef ProxyStub::UnknownStubType<QualityAssurance::ITestController::ICategory, QualityAssuranceTestControllerCategoryStubMethods> QualityAssuranceTestControllerCategoryStub;
        typedef ProxyStub::UnknownStubType<QualityAssurance::ITestController::ICategory::IIterator, QualityAssuranceTestControllerCategoryIteratorStubMethods> QualityAssuranceTestControllerCategoryIteratorStub;

        static class Instantiation {
        public:
            Instantiation()
            {
                const RPC::SecureProxyStubType security = static_cast<RPC::SecureProxyStubType>(static_cast<std::underlying_type<RPC::SecureProxyStubType>::type>(RPC::SecureProxyStubType::PROXYSTUBS_SECURITY_SECURE) | static_cast<std::underlying_type<RPC::SecureProxyStubType>::type>(RPC::SecureProxyStubType::PROXYSTUBS_SECURITY_COHERENT));

                RPC::Administrator::Instance().Announce<QualityAssurance::ITestController, QualityAssuranceTestControllerProxy, QualityAssuranceTestControllerStub>(security);
                RPC::Administrator::Instance().Announce<QualityAssurance::ITestController::ITest, QualityAssuranceTestControllerTestProxy, QualityAssuranceTestControllerTestStub>(security);
                RPC::Administrator::Instance().Announce<QualityAssurance::ITestController::ITest::IIterator, QualityAssuranceTestControllerTestIteratorProxy, QualityAssuranceTestControllerTestIteratorStub>(security);
                RPC::Administrator::Instance().Announce<QualityAssurance::ITestController::ICategory, QualityAssuranceTestControllerCategoryProxy, QualityAssuranceTestControllerCategoryStub>(security);
                RPC::Administrator::Instance().Announce<QualityAssurance::ITestController::ICategory::IIterator, QualityAssuranceTestControllerCategoryIteratorProxy, QualityAssuranceTestControllerCategoryIteratorStub>(security);
            }
            ~Instantiation()
            {
                RPC::Administrator::Instance().Recall<QualityAssurance::ITestController>();
                RPC::Administrator::Instance().Recall<QualityAssurance::ITestController::ITest>();
                RPC::Administrator::Instance().Recall<QualityAssurance::ITestController::ITest::IIterator>();
                RPC::Administrator::Instance().Recall<QualityAssurance::ITestController::ICategory>();
                RPC::Administrator::Instance().Recall<QualityAssurance::ITestController::ICategory::IIterator>();
            }
        } ProxyStubRegistration;

    } // namespace

} // namespace ProxyStubs

}
