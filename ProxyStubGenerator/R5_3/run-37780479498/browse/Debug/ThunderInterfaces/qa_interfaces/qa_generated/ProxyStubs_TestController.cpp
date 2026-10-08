//
// generated automatically from "ITestController.h"
//
// implements COM-RPC proxy stubs for:
//   - class ITestController
//   - class ITestController::ITest
//   - class ITestController::ITest::IIterator
//   - class ITestController::ICategory
//   - class ITestController::ICategory::IIterator
//

#include "Module.h"
#include "ITestController.h"

#include <com/com.h>

namespace Thunder {

namespace ProxyStubs {

    using namespace QualityAssurance;

    PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    // -----------------------------------------------------------------
    // STUBS
    // -----------------------------------------------------------------

    //
    // ITestController interface stub definitions
    //
    // Methods:
    //  (0) virtual void Setup() = 0
    //  (1) virtual void TearDown() = 0
    //  (2) virtual ITestController::ICategory::IIterator* Categories() const = 0
    //  (3) virtual ITestController::ICategory* Category(const string&) const = 0
    //

    static ProxyStub::MethodHandler TestControllerStubMethods[] = {
        // (0) virtual void Setup() = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            ITestController* implementation = reinterpret_cast<ITestController*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            implementation->Setup();
        },

        // (1) virtual void TearDown() = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            ITestController* implementation = reinterpret_cast<ITestController*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            implementation->TearDown();
        },

        // (2) virtual ITestController::ICategory::IIterator* Categories() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            const ITestController* implementation = reinterpret_cast<const ITestController*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            ITestController::ICategory::IIterator* result = implementation->Categories();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(result));

            RPC::Administrator::Instance().RegisterInterface(channel, result);
        },

        // (3) virtual ITestController::ICategory* Category(const string&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            const ITestController* implementation = reinterpret_cast<const ITestController*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _category = reader.Text();

            ITestController::ICategory* result = implementation->Category(static_cast<const string&>(_category));

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(result));

            RPC::Administrator::Instance().RegisterInterface(channel, result);
        }
        , nullptr
    }; // TestControllerStubMethods

    //
    // ITestController::ITest interface stub definitions
    //
    // Methods:
    //  (0) virtual string Execute(const string&) = 0
    //  (1) virtual string Description() const = 0
    //  (2) virtual string Name() const = 0
    //

    static ProxyStub::MethodHandler TestControllerTestStubMethods[] = {
        // (0) virtual string Execute(const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            ITestController::ITest* implementation = reinterpret_cast<ITestController::ITest*>(message->Parameters().Implementation());
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
            const ITestController::ITest* implementation = reinterpret_cast<const ITestController::ITest*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            string result = implementation->Description();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Text(result);
        },

        // (2) virtual string Name() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const ITestController::ITest* implementation = reinterpret_cast<const ITestController::ITest*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            string result = implementation->Name();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Text(result);
        }
        , nullptr
    }; // TestControllerTestStubMethods

    //
    // ITestController::ITest::IIterator interface stub definitions
    //
    // Methods:
    //  (0) virtual void Reset() = 0
    //  (1) virtual bool IsValid() const = 0
    //  (2) virtual bool Next() = 0
    //  (3) virtual ITestController::ITest* Test() const = 0
    //

    static ProxyStub::MethodHandler TestControllerTestIteratorStubMethods[] = {
        // (0) virtual void Reset() = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            ITestController::ITest::IIterator* implementation = reinterpret_cast<ITestController::ITest::IIterator*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            implementation->Reset();
        },

        // (1) virtual bool IsValid() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const ITestController::ITest::IIterator* implementation = reinterpret_cast<const ITestController::ITest::IIterator*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            bool result = implementation->IsValid();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Boolean(result);
        },

        // (2) virtual bool Next() = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            ITestController::ITest::IIterator* implementation = reinterpret_cast<ITestController::ITest::IIterator*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            bool result = implementation->Next();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Boolean(result);
        },

        // (3) virtual ITestController::ITest* Test() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            const ITestController::ITest::IIterator* implementation = reinterpret_cast<const ITestController::ITest::IIterator*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            ITestController::ITest* result = implementation->Test();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(result));

            RPC::Administrator::Instance().RegisterInterface(channel, result);
        }
        , nullptr
    }; // TestControllerTestIteratorStubMethods

    //
    // ITestController::ICategory interface stub definitions
    //
    // Methods:
    //  (0) virtual string Name() const = 0
    //  (1) virtual void Setup() = 0
    //  (2) virtual void TearDown() = 0
    //  (3) virtual void Register(ITestController::ITest*) = 0
    //  (4) virtual void Unregister(ITestController::ITest*) = 0
    //  (5) virtual ITestController::ITest::IIterator* Tests() const = 0
    //  (6) virtual ITestController::ITest* Test(const string&) const = 0
    //

    static ProxyStub::MethodHandler TestControllerCategoryStubMethods[] = {
        // (0) virtual string Name() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const ITestController::ICategory* implementation = reinterpret_cast<const ITestController::ICategory*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            string result = implementation->Name();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Text(result);
        },

        // (1) virtual void Setup() = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            ITestController::ICategory* implementation = reinterpret_cast<ITestController::ICategory*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            implementation->Setup();
        },

        // (2) virtual void TearDown() = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            ITestController::ICategory* implementation = reinterpret_cast<ITestController::ICategory*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            implementation->TearDown();
        },

        // (3) virtual void Register(ITestController::ITest*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            ITestController::ICategory* implementation = reinterpret_cast<ITestController::ICategory*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            Core::instance_id _testInstanceId__ = reader.Number<Core::instance_id>();

            ITestController::ITest* _test{};
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

        // (4) virtual void Unregister(ITestController::ITest*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            ITestController::ICategory* implementation = reinterpret_cast<ITestController::ICategory*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            Core::instance_id _testInstanceId__ = reader.Number<Core::instance_id>();

            ITestController::ITest* _test{};
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

        // (5) virtual ITestController::ITest::IIterator* Tests() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            const ITestController::ICategory* implementation = reinterpret_cast<const ITestController::ICategory*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            ITestController::ITest::IIterator* result = implementation->Tests();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(result));

            RPC::Administrator::Instance().RegisterInterface(channel, result);
        },

        // (6) virtual ITestController::ITest* Test(const string&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            const ITestController::ICategory* implementation = reinterpret_cast<const ITestController::ICategory*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _name = reader.Text();

            ITestController::ITest* result = implementation->Test(static_cast<const string&>(_name));

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(result));

            RPC::Administrator::Instance().RegisterInterface(channel, result);
        }
        , nullptr
    }; // TestControllerCategoryStubMethods

    //
    // ITestController::ICategory::IIterator interface stub definitions
    //
    // Methods:
    //  (0) virtual void Reset() = 0
    //  (1) virtual bool IsValid() const = 0
    //  (2) virtual bool Next() = 0
    //  (3) virtual ITestController::ICategory* Category() const = 0
    //

    static ProxyStub::MethodHandler TestControllerCategoryIteratorStubMethods[] = {
        // (0) virtual void Reset() = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            ITestController::ICategory::IIterator* implementation = reinterpret_cast<ITestController::ICategory::IIterator*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            implementation->Reset();
        },

        // (1) virtual bool IsValid() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const ITestController::ICategory::IIterator* implementation = reinterpret_cast<const ITestController::ICategory::IIterator*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            bool result = implementation->IsValid();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Boolean(result);
        },

        // (2) virtual bool Next() = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            ITestController::ICategory::IIterator* implementation = reinterpret_cast<ITestController::ICategory::IIterator*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            bool result = implementation->Next();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Boolean(result);
        },

        // (3) virtual ITestController::ICategory* Category() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            const ITestController::ICategory::IIterator* implementation = reinterpret_cast<const ITestController::ICategory::IIterator*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            ITestController::ICategory* result = implementation->Category();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(result));

            RPC::Administrator::Instance().RegisterInterface(channel, result);
        }
        , nullptr
    }; // TestControllerCategoryIteratorStubMethods

    // -----------------------------------------------------------------
    // PROXIES
    // -----------------------------------------------------------------

    //
    // ITestController interface proxy definitions
    //
    // Methods:
    //  (0) virtual void Setup() = 0
    //  (1) virtual void TearDown() = 0
    //  (2) virtual ITestController::ICategory::IIterator* Categories() const = 0
    //  (3) virtual ITestController::ICategory* Category(const string&) const = 0
    //

    class TestControllerProxy final : public ProxyStub::UnknownProxyType<ITestController> {
    public:
        TestControllerProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
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

        ITestController::ICategory::IIterator* Categories() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(2));

            ITestController::ICategory::IIterator* result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reinterpret_cast<ITestController::ICategory::IIterator*>(static_cast<const ProxyStub::UnknownProxy&>(*this).Interface(reader.Number<Core::instance_id>(), ITestController::ICategory::IIterator::ID));
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        ITestController::ICategory* Category(const string& _category) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(3));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_category);

            ITestController::ICategory* result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reinterpret_cast<ITestController::ICategory*>(static_cast<const ProxyStub::UnknownProxy&>(*this).Interface(reader.Number<Core::instance_id>(), ITestController::ICategory::ID));
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

    }; // class TestControllerProxy

    //
    // ITestController::ITest interface proxy definitions
    //
    // Methods:
    //  (0) virtual string Execute(const string&) = 0
    //  (1) virtual string Description() const = 0
    //  (2) virtual string Name() const = 0
    //

    class TestControllerTestProxy final : public ProxyStub::UnknownProxyType<ITestController::ITest> {
    public:
        TestControllerTestProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
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

    }; // class TestControllerTestProxy

    //
    // ITestController::ITest::IIterator interface proxy definitions
    //
    // Methods:
    //  (0) virtual void Reset() = 0
    //  (1) virtual bool IsValid() const = 0
    //  (2) virtual bool Next() = 0
    //  (3) virtual ITestController::ITest* Test() const = 0
    //

    class TestControllerTestIteratorProxy final : public ProxyStub::UnknownProxyType<ITestController::ITest::IIterator> {
    public:
        TestControllerTestIteratorProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
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

        ITestController::ITest* Test() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(3));

            ITestController::ITest* result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reinterpret_cast<ITestController::ITest*>(static_cast<const ProxyStub::UnknownProxy&>(*this).Interface(reader.Number<Core::instance_id>(), ITestController::ITest::ID));
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

    }; // class TestControllerTestIteratorProxy

    //
    // ITestController::ICategory interface proxy definitions
    //
    // Methods:
    //  (0) virtual string Name() const = 0
    //  (1) virtual void Setup() = 0
    //  (2) virtual void TearDown() = 0
    //  (3) virtual void Register(ITestController::ITest*) = 0
    //  (4) virtual void Unregister(ITestController::ITest*) = 0
    //  (5) virtual ITestController::ITest::IIterator* Tests() const = 0
    //  (6) virtual ITestController::ITest* Test(const string&) const = 0
    //

    class TestControllerCategoryProxy final : public ProxyStub::UnknownProxyType<ITestController::ICategory> {
    public:
        TestControllerCategoryProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
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

        void Register(ITestController::ITest* _test) override
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

        void Unregister(ITestController::ITest* _test) override
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

        ITestController::ITest::IIterator* Tests() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(5));

            ITestController::ITest::IIterator* result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reinterpret_cast<ITestController::ITest::IIterator*>(static_cast<const ProxyStub::UnknownProxy&>(*this).Interface(reader.Number<Core::instance_id>(), ITestController::ITest::IIterator::ID));
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        ITestController::ITest* Test(const string& _name) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(6));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_name);

            ITestController::ITest* result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reinterpret_cast<ITestController::ITest*>(static_cast<const ProxyStub::UnknownProxy&>(*this).Interface(reader.Number<Core::instance_id>(), ITestController::ITest::ID));
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

    }; // class TestControllerCategoryProxy

    //
    // ITestController::ICategory::IIterator interface proxy definitions
    //
    // Methods:
    //  (0) virtual void Reset() = 0
    //  (1) virtual bool IsValid() const = 0
    //  (2) virtual bool Next() = 0
    //  (3) virtual ITestController::ICategory* Category() const = 0
    //

    class TestControllerCategoryIteratorProxy final : public ProxyStub::UnknownProxyType<ITestController::ICategory::IIterator> {
    public:
        TestControllerCategoryIteratorProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
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

        ITestController::ICategory* Category() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(3));

            ITestController::ICategory* result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reinterpret_cast<ITestController::ICategory*>(static_cast<const ProxyStub::UnknownProxy&>(*this).Interface(reader.Number<Core::instance_id>(), ITestController::ICategory::ID));
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

    }; // class TestControllerCategoryIteratorProxy

    POP_WARNING()
    POP_WARNING()

    // -----------------------------------------------------------------
    // REGISTRATION
    // -----------------------------------------------------------------
    namespace {

        typedef ProxyStub::UnknownStubType<ITestController, TestControllerStubMethods> TestControllerStub;
        typedef ProxyStub::UnknownStubType<ITestController::ITest, TestControllerTestStubMethods> TestControllerTestStub;
        typedef ProxyStub::UnknownStubType<ITestController::ITest::IIterator, TestControllerTestIteratorStubMethods> TestControllerTestIteratorStub;
        typedef ProxyStub::UnknownStubType<ITestController::ICategory, TestControllerCategoryStubMethods> TestControllerCategoryStub;
        typedef ProxyStub::UnknownStubType<ITestController::ICategory::IIterator, TestControllerCategoryIteratorStubMethods> TestControllerCategoryIteratorStub;

        static class Instantiation {
        public:
            Instantiation()
            {
                RPC::Administrator::Instance().Announce<ITestController, TestControllerProxy, TestControllerStub>();
                RPC::Administrator::Instance().Announce<ITestController::ITest, TestControllerTestProxy, TestControllerTestStub>();
                RPC::Administrator::Instance().Announce<ITestController::ITest::IIterator, TestControllerTestIteratorProxy, TestControllerTestIteratorStub>();
                RPC::Administrator::Instance().Announce<ITestController::ICategory, TestControllerCategoryProxy, TestControllerCategoryStub>();
                RPC::Administrator::Instance().Announce<ITestController::ICategory::IIterator, TestControllerCategoryIteratorProxy, TestControllerCategoryIteratorStub>();
            }
            ~Instantiation()
            {
                RPC::Administrator::Instance().Recall<ITestController>();
                RPC::Administrator::Instance().Recall<ITestController::ITest>();
                RPC::Administrator::Instance().Recall<ITestController::ITest::IIterator>();
                RPC::Administrator::Instance().Recall<ITestController::ICategory>();
                RPC::Administrator::Instance().Recall<ITestController::ICategory::IIterator>();
            }
        } ProxyStubRegistration;

    } // namespace

} // namespace ProxyStubs

}
