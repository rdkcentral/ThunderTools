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
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            QualityAssurance::ITestController* implementation = reinterpret_cast<QualityAssurance::ITestController*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            implementation->Setup();
        },

        // (1) virtual void TearDown() = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            QualityAssurance::ITestController* implementation = reinterpret_cast<QualityAssurance::ITestController*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            implementation->TearDown();
        },

        // (2) virtual QualityAssurance::ITestController::ICategory::IIterator* Categories() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            const QualityAssurance::ITestController* implementation = reinterpret_cast<const QualityAssurance::ITestController*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            QualityAssurance::ITestController::ICategory::IIterator* result = implementation->Categories();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(result));

            RPC::Administrator::Instance().RegisterInterface(channel, result);
        },

        // (3) virtual QualityAssurance::ITestController::ICategory* Category(const string&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            const QualityAssurance::ITestController* implementation = reinterpret_cast<const QualityAssurance::ITestController*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _category = reader.Text();

            QualityAssurance::ITestController::ICategory* result = implementation->Category(static_cast<const string&>(_category));

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(result));

            RPC::Administrator::Instance().RegisterInterface(channel, result);
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
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            QualityAssurance::ITestController::ITest* implementation = reinterpret_cast<QualityAssurance::ITestController::ITest*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _params = reader.Text();

            string result = implementation->Execute(static_cast<const string&>(_params));

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Text(result);
        },

        // (1) virtual string Description() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const QualityAssurance::ITestController::ITest* implementation = reinterpret_cast<const QualityAssurance::ITestController::ITest*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            string result = implementation->Description();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Text(result);
        },

        // (2) virtual string Name() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const QualityAssurance::ITestController::ITest* implementation = reinterpret_cast<const QualityAssurance::ITestController::ITest*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            string result = implementation->Name();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Text(result);
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
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            QualityAssurance::ITestController::ITest::IIterator* implementation = reinterpret_cast<QualityAssurance::ITestController::ITest::IIterator*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            implementation->Reset();
        },

        // (1) virtual bool IsValid() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const QualityAssurance::ITestController::ITest::IIterator* implementation = reinterpret_cast<const QualityAssurance::ITestController::ITest::IIterator*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            bool result = implementation->IsValid();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Boolean(result);
        },

        // (2) virtual bool Next() = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            QualityAssurance::ITestController::ITest::IIterator* implementation = reinterpret_cast<QualityAssurance::ITestController::ITest::IIterator*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            bool result = implementation->Next();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Boolean(result);
        },

        // (3) virtual QualityAssurance::ITestController::ITest* Test() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            const QualityAssurance::ITestController::ITest::IIterator* implementation = reinterpret_cast<const QualityAssurance::ITestController::ITest::IIterator*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            QualityAssurance::ITestController::ITest* result = implementation->Test();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(result));

            RPC::Administrator::Instance().RegisterInterface(channel, result);
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
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const QualityAssurance::ITestController::ICategory* implementation = reinterpret_cast<const QualityAssurance::ITestController::ICategory*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            string result = implementation->Name();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Text(result);
        },

        // (1) virtual void Setup() = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            QualityAssurance::ITestController::ICategory* implementation = reinterpret_cast<QualityAssurance::ITestController::ICategory*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            implementation->Setup();
        },

        // (2) virtual void TearDown() = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            QualityAssurance::ITestController::ICategory* implementation = reinterpret_cast<QualityAssurance::ITestController::ICategory*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            implementation->TearDown();
        },

        // (3) virtual void Register(QualityAssurance::ITestController::ITest*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            QualityAssurance::ITestController::ICategory* implementation = reinterpret_cast<QualityAssurance::ITestController::ICategory*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            Core::instance_id _testInstanceId__ = reader.Number<Core::instance_id>();

            QualityAssurance::ITestController::ITest* _test{};
            ProxyStub::UnknownProxy* _testProxy__ = nullptr;
            if (_testInstanceId__ != 0) {
                _testProxy__ = RPC::Administrator::Instance().ProxyInstance(channel, _testInstanceId__, false, _test);
                ASSERT((_test != nullptr) && (_testProxy__ != nullptr));
            }

            implementation->Register(_test);

            if (_testProxy__ != nullptr) {
                RPC::Administrator::Instance().Release(_testProxy__, message->Response());
            }
        },

        // (4) virtual void Unregister(QualityAssurance::ITestController::ITest*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            QualityAssurance::ITestController::ICategory* implementation = reinterpret_cast<QualityAssurance::ITestController::ICategory*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            Core::instance_id _testInstanceId__ = reader.Number<Core::instance_id>();

            QualityAssurance::ITestController::ITest* _test{};
            ProxyStub::UnknownProxy* _testProxy__ = nullptr;
            if (_testInstanceId__ != 0) {
                _testProxy__ = RPC::Administrator::Instance().ProxyInstance(channel, _testInstanceId__, false, _test);
                ASSERT((_test != nullptr) && (_testProxy__ != nullptr));
            }

            implementation->Unregister(_test);

            if (_testProxy__ != nullptr) {
                RPC::Administrator::Instance().Release(_testProxy__, message->Response());
            }
        },

        // (5) virtual QualityAssurance::ITestController::ITest::IIterator* Tests() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            const QualityAssurance::ITestController::ICategory* implementation = reinterpret_cast<const QualityAssurance::ITestController::ICategory*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            QualityAssurance::ITestController::ITest::IIterator* result = implementation->Tests();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(result));

            RPC::Administrator::Instance().RegisterInterface(channel, result);
        },

        // (6) virtual QualityAssurance::ITestController::ITest* Test(const string&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            const QualityAssurance::ITestController::ICategory* implementation = reinterpret_cast<const QualityAssurance::ITestController::ICategory*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _name = reader.Text();

            QualityAssurance::ITestController::ITest* result = implementation->Test(static_cast<const string&>(_name));

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(result));

            RPC::Administrator::Instance().RegisterInterface(channel, result);
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
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            QualityAssurance::ITestController::ICategory::IIterator* implementation = reinterpret_cast<QualityAssurance::ITestController::ICategory::IIterator*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            implementation->Reset();
        },

        // (1) virtual bool IsValid() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const QualityAssurance::ITestController::ICategory::IIterator* implementation = reinterpret_cast<const QualityAssurance::ITestController::ICategory::IIterator*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            bool result = implementation->IsValid();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Boolean(result);
        },

        // (2) virtual bool Next() = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            QualityAssurance::ITestController::ICategory::IIterator* implementation = reinterpret_cast<QualityAssurance::ITestController::ICategory::IIterator*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            bool result = implementation->Next();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Boolean(result);
        },

        // (3) virtual QualityAssurance::ITestController::ICategory* Category() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            const QualityAssurance::ITestController::ICategory::IIterator* implementation = reinterpret_cast<const QualityAssurance::ITestController::ICategory::IIterator*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            QualityAssurance::ITestController::ICategory* result = implementation->Category();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(result));

            RPC::Administrator::Instance().RegisterInterface(channel, result);
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

            static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
        }

        void TearDown() override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
        }

        QualityAssurance::ITestController::ICategory::IIterator* Categories() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(2));

            QualityAssurance::ITestController::ICategory::IIterator* result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reinterpret_cast<QualityAssurance::ITestController::ICategory::IIterator*>(static_cast<const ProxyStub::UnknownProxy&>(*this).Interface(reader.Number<Core::instance_id>(), QualityAssurance::ITestController::ICategory::IIterator::ID));
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        QualityAssurance::ITestController::ICategory* Category(const string& _category) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(3));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_category);

            QualityAssurance::ITestController::ICategory* result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reinterpret_cast<QualityAssurance::ITestController::ICategory*>(static_cast<const ProxyStub::UnknownProxy&>(*this).Interface(reader.Number<Core::instance_id>(), QualityAssurance::ITestController::ICategory::ID));
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
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

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Text();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        string Description() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            string result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Text();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        string Name() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(2));

            string result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Text();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
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

            static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
        }

        bool IsValid() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            bool result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Boolean();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        bool Next() override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(2));

            bool result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Boolean();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        QualityAssurance::ITestController::ITest* Test() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(3));

            QualityAssurance::ITestController::ITest* result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reinterpret_cast<QualityAssurance::ITestController::ITest*>(static_cast<const ProxyStub::UnknownProxy&>(*this).Interface(reader.Number<Core::instance_id>(), QualityAssurance::ITestController::ITest::ID));
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
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

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Text();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        void Setup() override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
        }

        void TearDown() override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(2));

            static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
        }

        void Register(QualityAssurance::ITestController::ITest* _test) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(3));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_test));

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());

                _Complete(reader);
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }
        }

        void Unregister(QualityAssurance::ITestController::ITest* _test) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(4));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_test));

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());

                _Complete(reader);
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }
        }

        QualityAssurance::ITestController::ITest::IIterator* Tests() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(5));

            QualityAssurance::ITestController::ITest::IIterator* result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reinterpret_cast<QualityAssurance::ITestController::ITest::IIterator*>(static_cast<const ProxyStub::UnknownProxy&>(*this).Interface(reader.Number<Core::instance_id>(), QualityAssurance::ITestController::ITest::IIterator::ID));
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        QualityAssurance::ITestController::ITest* Test(const string& _name) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(6));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_name);

            QualityAssurance::ITestController::ITest* result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reinterpret_cast<QualityAssurance::ITestController::ITest*>(static_cast<const ProxyStub::UnknownProxy&>(*this).Interface(reader.Number<Core::instance_id>(), QualityAssurance::ITestController::ITest::ID));
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

    private:
        uint32_t _Complete(RPC::Data::Frame::Reader& reader) const
        {
            uint32_t result = Core::ERROR_NONE;

            while (reader.HasData() == true) {
                const Core::instance_id implementation = reader.Number<Core::instance_id>();
                ASSERT(implementation != 0);

                const uint32_t id = reader.Number<uint32_t>();
                const RPC::Data::Output::mode how = reader.Number<RPC::Data::Output::mode>();

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

            static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
        }

        bool IsValid() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            bool result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Boolean();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        bool Next() override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(2));

            bool result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Boolean();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        QualityAssurance::ITestController::ICategory* Category() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(3));

            QualityAssurance::ITestController::ICategory* result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reinterpret_cast<QualityAssurance::ITestController::ICategory*>(static_cast<const ProxyStub::UnknownProxy&>(*this).Interface(reader.Number<Core::instance_id>(), QualityAssurance::ITestController::ICategory::ID));
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
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
                RPC::Administrator::Instance().Announce<QualityAssurance::ITestController, QualityAssuranceTestControllerProxy, QualityAssuranceTestControllerStub>();
                RPC::Administrator::Instance().Announce<QualityAssurance::ITestController::ITest, QualityAssuranceTestControllerTestProxy, QualityAssuranceTestControllerTestStub>();
                RPC::Administrator::Instance().Announce<QualityAssurance::ITestController::ITest::IIterator, QualityAssuranceTestControllerTestIteratorProxy, QualityAssuranceTestControllerTestIteratorStub>();
                RPC::Administrator::Instance().Announce<QualityAssurance::ITestController::ICategory, QualityAssuranceTestControllerCategoryProxy, QualityAssuranceTestControllerCategoryStub>();
                RPC::Administrator::Instance().Announce<QualityAssurance::ITestController::ICategory::IIterator, QualityAssuranceTestControllerCategoryIteratorProxy, QualityAssuranceTestControllerCategoryIteratorStub>();
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
