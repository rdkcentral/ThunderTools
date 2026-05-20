//
// generated automatically from "ITestController.h"
//
// implements COM-RPC proxy stubs for:
//   - class Exchange::ITestController
//   - class Exchange::ITestController::ITest
//   - class Exchange::ITestController::ITest::IIterator
//   - class Exchange::ITestController::ICategory
//   - class Exchange::ITestController::ICategory::IIterator
//

#include "Module.h"
#include "ITestController.h"

#include <com/com.h>

namespace WPEFramework {

namespace ProxyStubs {

    PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    // -----------------------------------------------------------------
    // STUBS
    // -----------------------------------------------------------------

    //
    // Exchange::ITestController interface stub definitions
    //
    // Methods:
    //  (0) virtual void Setup() = 0
    //  (1) virtual void TearDown() = 0
    //  (2) virtual Exchange::ITestController::ICategory::IIterator* Categories() const = 0
    //  (3) virtual Exchange::ITestController::ICategory* Category(const string&) const = 0
    //

    ProxyStub::MethodHandler ExchangeTestControllerStubMethods[] = {
        // (0) virtual void Setup() = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::ITestController* implementation = reinterpret_cast<Exchange::ITestController*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            implementation->Setup();
        },

        // (1) virtual void TearDown() = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::ITestController* implementation = reinterpret_cast<Exchange::ITestController*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            implementation->TearDown();
        },

        // (2) virtual Exchange::ITestController::ICategory::IIterator* Categories() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::ITestController* implementation = reinterpret_cast<const Exchange::ITestController*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::ITestController::ICategory::IIterator* result = implementation->Categories();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(result));

            RPC::Administrator::Instance().RegisterInterface(channel, result);
        },

        // (3) virtual Exchange::ITestController::ICategory* Category(const string&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::ITestController* implementation = reinterpret_cast<const Exchange::ITestController*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _category = reader.Text();

            Exchange::ITestController::ICategory* result = implementation->Category(static_cast<const string&>(_category));

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(result));

            RPC::Administrator::Instance().RegisterInterface(channel, result);
        }
        , nullptr
    }; // ExchangeTestControllerStubMethods

    //
    // Exchange::ITestController::ITest interface stub definitions
    //
    // Methods:
    //  (0) virtual string Execute(const string&) = 0
    //  (1) virtual string Description() const = 0
    //  (2) virtual string Name() const = 0
    //

    ProxyStub::MethodHandler ExchangeTestControllerTestStubMethods[] = {
        // (0) virtual string Execute(const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::ITestController::ITest* implementation = reinterpret_cast<Exchange::ITestController::ITest*>(message->Parameters().Implementation());
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
            const Exchange::ITestController::ITest* implementation = reinterpret_cast<const Exchange::ITestController::ITest*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            string result = implementation->Description();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Text(result);
        },

        // (2) virtual string Name() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::ITestController::ITest* implementation = reinterpret_cast<const Exchange::ITestController::ITest*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            string result = implementation->Name();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Text(result);
        }
        , nullptr
    }; // ExchangeTestControllerTestStubMethods

    //
    // Exchange::ITestController::ITest::IIterator interface stub definitions
    //
    // Methods:
    //  (0) virtual void Reset() = 0
    //  (1) virtual bool IsValid() const = 0
    //  (2) virtual bool Next() = 0
    //  (3) virtual Exchange::ITestController::ITest* Test() const = 0
    //

    ProxyStub::MethodHandler ExchangeTestControllerTestIteratorStubMethods[] = {
        // (0) virtual void Reset() = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::ITestController::ITest::IIterator* implementation = reinterpret_cast<Exchange::ITestController::ITest::IIterator*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            implementation->Reset();
        },

        // (1) virtual bool IsValid() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::ITestController::ITest::IIterator* implementation = reinterpret_cast<const Exchange::ITestController::ITest::IIterator*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            bool result = implementation->IsValid();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Boolean(result);
        },

        // (2) virtual bool Next() = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::ITestController::ITest::IIterator* implementation = reinterpret_cast<Exchange::ITestController::ITest::IIterator*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            bool result = implementation->Next();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Boolean(result);
        },

        // (3) virtual Exchange::ITestController::ITest* Test() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::ITestController::ITest::IIterator* implementation = reinterpret_cast<const Exchange::ITestController::ITest::IIterator*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::ITestController::ITest* result = implementation->Test();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(result));

            RPC::Administrator::Instance().RegisterInterface(channel, result);
        }
        , nullptr
    }; // ExchangeTestControllerTestIteratorStubMethods

    //
    // Exchange::ITestController::ICategory interface stub definitions
    //
    // Methods:
    //  (0) virtual string Name() const = 0
    //  (1) virtual void Setup() = 0
    //  (2) virtual void TearDown() = 0
    //  (3) virtual void Register(Exchange::ITestController::ITest*) = 0
    //  (4) virtual void Unregister(Exchange::ITestController::ITest*) = 0
    //  (5) virtual Exchange::ITestController::ITest::IIterator* Tests() const = 0
    //  (6) virtual Exchange::ITestController::ITest* Test(const string&) const = 0
    //

    ProxyStub::MethodHandler ExchangeTestControllerCategoryStubMethods[] = {
        // (0) virtual string Name() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::ITestController::ICategory* implementation = reinterpret_cast<const Exchange::ITestController::ICategory*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            string result = implementation->Name();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Text(result);
        },

        // (1) virtual void Setup() = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::ITestController::ICategory* implementation = reinterpret_cast<Exchange::ITestController::ICategory*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            implementation->Setup();
        },

        // (2) virtual void TearDown() = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::ITestController::ICategory* implementation = reinterpret_cast<Exchange::ITestController::ICategory*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            implementation->TearDown();
        },

        // (3) virtual void Register(Exchange::ITestController::ITest*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::ITestController::ICategory* implementation = reinterpret_cast<Exchange::ITestController::ICategory*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const Core::instance_id testImplementation = reader.Number<Core::instance_id>();

            Exchange::ITestController::ITest* _test = nullptr;
            ProxyStub::UnknownProxy* testProxy = nullptr;
            if (testImplementation != 0) {
                testProxy = RPC::Administrator::Instance().ProxyInstance(channel, testImplementation, false, _test);

                ASSERT((_test != nullptr) && (testProxy != nullptr));
            }

            implementation->Register(_test);

            if (testProxy != nullptr) {
                RPC::Administrator::Instance().Release(testProxy, message->Response());
            }
        },

        // (4) virtual void Unregister(Exchange::ITestController::ITest*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::ITestController::ICategory* implementation = reinterpret_cast<Exchange::ITestController::ICategory*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const Core::instance_id testImplementation = reader.Number<Core::instance_id>();

            Exchange::ITestController::ITest* _test = nullptr;
            ProxyStub::UnknownProxy* testProxy = nullptr;
            if (testImplementation != 0) {
                testProxy = RPC::Administrator::Instance().ProxyInstance(channel, testImplementation, false, _test);

                ASSERT((_test != nullptr) && (testProxy != nullptr));
            }

            implementation->Unregister(_test);

            if (testProxy != nullptr) {
                RPC::Administrator::Instance().Release(testProxy, message->Response());
            }
        },

        // (5) virtual Exchange::ITestController::ITest::IIterator* Tests() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::ITestController::ICategory* implementation = reinterpret_cast<const Exchange::ITestController::ICategory*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::ITestController::ITest::IIterator* result = implementation->Tests();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(result));

            RPC::Administrator::Instance().RegisterInterface(channel, result);
        },

        // (6) virtual Exchange::ITestController::ITest* Test(const string&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::ITestController::ICategory* implementation = reinterpret_cast<const Exchange::ITestController::ICategory*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _name = reader.Text();

            Exchange::ITestController::ITest* result = implementation->Test(static_cast<const string&>(_name));

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(result));

            RPC::Administrator::Instance().RegisterInterface(channel, result);
        }
        , nullptr
    }; // ExchangeTestControllerCategoryStubMethods

    //
    // Exchange::ITestController::ICategory::IIterator interface stub definitions
    //
    // Methods:
    //  (0) virtual void Reset() = 0
    //  (1) virtual bool IsValid() const = 0
    //  (2) virtual bool Next() = 0
    //  (3) virtual Exchange::ITestController::ICategory* Category() const = 0
    //

    ProxyStub::MethodHandler ExchangeTestControllerCategoryIteratorStubMethods[] = {
        // (0) virtual void Reset() = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::ITestController::ICategory::IIterator* implementation = reinterpret_cast<Exchange::ITestController::ICategory::IIterator*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            implementation->Reset();
        },

        // (1) virtual bool IsValid() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::ITestController::ICategory::IIterator* implementation = reinterpret_cast<const Exchange::ITestController::ICategory::IIterator*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            bool result = implementation->IsValid();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Boolean(result);
        },

        // (2) virtual bool Next() = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::ITestController::ICategory::IIterator* implementation = reinterpret_cast<Exchange::ITestController::ICategory::IIterator*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            bool result = implementation->Next();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Boolean(result);
        },

        // (3) virtual Exchange::ITestController::ICategory* Category() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::ITestController::ICategory::IIterator* implementation = reinterpret_cast<const Exchange::ITestController::ICategory::IIterator*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::ITestController::ICategory* result = implementation->Category();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(result));

            RPC::Administrator::Instance().RegisterInterface(channel, result);
        }
        , nullptr
    }; // ExchangeTestControllerCategoryIteratorStubMethods

    // -----------------------------------------------------------------
    // PROXIES
    // -----------------------------------------------------------------

    //
    // Exchange::ITestController interface proxy definitions
    //
    // Methods:
    //  (0) virtual void Setup() = 0
    //  (1) virtual void TearDown() = 0
    //  (2) virtual Exchange::ITestController::ICategory::IIterator* Categories() const = 0
    //  (3) virtual Exchange::ITestController::ICategory* Category(const string&) const = 0
    //

    class ExchangeTestControllerProxy final : public ProxyStub::UnknownProxyType<Exchange::ITestController> {
    public:
        ExchangeTestControllerProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        uint32_t Complete(RPC::Data::Frame::Reader& reader)
        {
            uint32_t result = Core::ERROR_NONE;

            while (reader.HasData() == true) {
                const Core::instance_id implementation = reader.Number<Core::instance_id>();
                ASSERT(implementation != 0);

                const uint32_t id = reader.Number<uint32_t>();
                const RPC::Data::Output::mode how = reader.Number<RPC::Data::Output::mode>();

                result = UnknownProxyType::Complete(implementation, id, how);
                if (result != Core::ERROR_NONE) { return (COM_ERROR | result); }
            }

            return (result);
        }

        void Setup() override
        {
            IPCMessage message(BaseClass::Message(0));

            UnknownProxyType::Invoke(message);
        }

        void TearDown() override
        {
            IPCMessage message(BaseClass::Message(1));

            UnknownProxyType::Invoke(message);
        }

        Exchange::ITestController::ICategory::IIterator* Categories() const override
        {
            IPCMessage message(BaseClass::Message(2));

            Exchange::ITestController::ICategory::IIterator* result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reinterpret_cast<Exchange::ITestController::ICategory::IIterator*>(Interface(reader.Number<Core::instance_id>(), Exchange::ITestController::ICategory::IIterator::ID));

            return (result);
        }

        Exchange::ITestController::ICategory* Category(const string& _category) const override
        {
            IPCMessage message(BaseClass::Message(3));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const string&>(_category));

            Exchange::ITestController::ICategory* result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reinterpret_cast<Exchange::ITestController::ICategory*>(Interface(reader.Number<Core::instance_id>(), Exchange::ITestController::ICategory::ID));

            return (result);
        }

    }; // class ExchangeTestControllerProxy

    //
    // Exchange::ITestController::ITest interface proxy definitions
    //
    // Methods:
    //  (0) virtual string Execute(const string&) = 0
    //  (1) virtual string Description() const = 0
    //  (2) virtual string Name() const = 0
    //

    class ExchangeTestControllerTestProxy final : public ProxyStub::UnknownProxyType<Exchange::ITestController::ITest> {
    public:
        ExchangeTestControllerTestProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        uint32_t Complete(RPC::Data::Frame::Reader& reader)
        {
            uint32_t result = Core::ERROR_NONE;

            while (reader.HasData() == true) {
                const Core::instance_id implementation = reader.Number<Core::instance_id>();
                ASSERT(implementation != 0);

                const uint32_t id = reader.Number<uint32_t>();
                const RPC::Data::Output::mode how = reader.Number<RPC::Data::Output::mode>();

                result = UnknownProxyType::Complete(implementation, id, how);
                if (result != Core::ERROR_NONE) { return (COM_ERROR | result); }
            }

            return (result);
        }

        string Execute(const string& _params) override
        {
            IPCMessage message(BaseClass::Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const string&>(_params));

            string result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Text();

            return (result);
        }

        string Description() const override
        {
            IPCMessage message(BaseClass::Message(1));

            string result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Text();

            return (result);
        }

        string Name() const override
        {
            IPCMessage message(BaseClass::Message(2));

            string result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Text();

            return (result);
        }

    }; // class ExchangeTestControllerTestProxy

    //
    // Exchange::ITestController::ITest::IIterator interface proxy definitions
    //
    // Methods:
    //  (0) virtual void Reset() = 0
    //  (1) virtual bool IsValid() const = 0
    //  (2) virtual bool Next() = 0
    //  (3) virtual Exchange::ITestController::ITest* Test() const = 0
    //

    class ExchangeTestControllerTestIteratorProxy final : public ProxyStub::UnknownProxyType<Exchange::ITestController::ITest::IIterator> {
    public:
        ExchangeTestControllerTestIteratorProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        uint32_t Complete(RPC::Data::Frame::Reader& reader)
        {
            uint32_t result = Core::ERROR_NONE;

            while (reader.HasData() == true) {
                const Core::instance_id implementation = reader.Number<Core::instance_id>();
                ASSERT(implementation != 0);

                const uint32_t id = reader.Number<uint32_t>();
                const RPC::Data::Output::mode how = reader.Number<RPC::Data::Output::mode>();

                result = UnknownProxyType::Complete(implementation, id, how);
                if (result != Core::ERROR_NONE) { return (COM_ERROR | result); }
            }

            return (result);
        }

        void Reset() override
        {
            IPCMessage message(BaseClass::Message(0));

            UnknownProxyType::Invoke(message);
        }

        bool IsValid() const override
        {
            IPCMessage message(BaseClass::Message(1));

            bool result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Boolean();

            return (result);
        }

        bool Next() override
        {
            IPCMessage message(BaseClass::Message(2));

            bool result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Boolean();

            return (result);
        }

        Exchange::ITestController::ITest* Test() const override
        {
            IPCMessage message(BaseClass::Message(3));

            Exchange::ITestController::ITest* result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reinterpret_cast<Exchange::ITestController::ITest*>(Interface(reader.Number<Core::instance_id>(), Exchange::ITestController::ITest::ID));

            return (result);
        }

    }; // class ExchangeTestControllerTestIteratorProxy

    //
    // Exchange::ITestController::ICategory interface proxy definitions
    //
    // Methods:
    //  (0) virtual string Name() const = 0
    //  (1) virtual void Setup() = 0
    //  (2) virtual void TearDown() = 0
    //  (3) virtual void Register(Exchange::ITestController::ITest*) = 0
    //  (4) virtual void Unregister(Exchange::ITestController::ITest*) = 0
    //  (5) virtual Exchange::ITestController::ITest::IIterator* Tests() const = 0
    //  (6) virtual Exchange::ITestController::ITest* Test(const string&) const = 0
    //

    class ExchangeTestControllerCategoryProxy final : public ProxyStub::UnknownProxyType<Exchange::ITestController::ICategory> {
    public:
        ExchangeTestControllerCategoryProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        uint32_t Complete(RPC::Data::Frame::Reader& reader)
        {
            uint32_t result = Core::ERROR_NONE;

            while (reader.HasData() == true) {
                const Core::instance_id implementation = reader.Number<Core::instance_id>();
                ASSERT(implementation != 0);

                const uint32_t id = reader.Number<uint32_t>();
                const RPC::Data::Output::mode how = reader.Number<RPC::Data::Output::mode>();

                result = UnknownProxyType::Complete(implementation, id, how);
                if (result != Core::ERROR_NONE) { return (COM_ERROR | result); }
            }

            return (result);
        }

        string Name() const override
        {
            IPCMessage message(BaseClass::Message(0));

            string result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Text();

            return (result);
        }

        void Setup() override
        {
            IPCMessage message(BaseClass::Message(1));

            UnknownProxyType::Invoke(message);
        }

        void TearDown() override
        {
            IPCMessage message(BaseClass::Message(2));

            UnknownProxyType::Invoke(message);
        }

        void Register(Exchange::ITestController::ITest* _test) override
        {
            IPCMessage message(BaseClass::Message(3));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_test));

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());

            Complete(reader);
        }

        void Unregister(Exchange::ITestController::ITest* _test) override
        {
            IPCMessage message(BaseClass::Message(4));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_test));

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());

            Complete(reader);
        }

        Exchange::ITestController::ITest::IIterator* Tests() const override
        {
            IPCMessage message(BaseClass::Message(5));

            Exchange::ITestController::ITest::IIterator* result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reinterpret_cast<Exchange::ITestController::ITest::IIterator*>(Interface(reader.Number<Core::instance_id>(), Exchange::ITestController::ITest::IIterator::ID));

            return (result);
        }

        Exchange::ITestController::ITest* Test(const string& _name) const override
        {
            IPCMessage message(BaseClass::Message(6));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const string&>(_name));

            Exchange::ITestController::ITest* result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reinterpret_cast<Exchange::ITestController::ITest*>(Interface(reader.Number<Core::instance_id>(), Exchange::ITestController::ITest::ID));

            return (result);
        }

    }; // class ExchangeTestControllerCategoryProxy

    //
    // Exchange::ITestController::ICategory::IIterator interface proxy definitions
    //
    // Methods:
    //  (0) virtual void Reset() = 0
    //  (1) virtual bool IsValid() const = 0
    //  (2) virtual bool Next() = 0
    //  (3) virtual Exchange::ITestController::ICategory* Category() const = 0
    //

    class ExchangeTestControllerCategoryIteratorProxy final : public ProxyStub::UnknownProxyType<Exchange::ITestController::ICategory::IIterator> {
    public:
        ExchangeTestControllerCategoryIteratorProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        uint32_t Complete(RPC::Data::Frame::Reader& reader)
        {
            uint32_t result = Core::ERROR_NONE;

            while (reader.HasData() == true) {
                const Core::instance_id implementation = reader.Number<Core::instance_id>();
                ASSERT(implementation != 0);

                const uint32_t id = reader.Number<uint32_t>();
                const RPC::Data::Output::mode how = reader.Number<RPC::Data::Output::mode>();

                result = UnknownProxyType::Complete(implementation, id, how);
                if (result != Core::ERROR_NONE) { return (COM_ERROR | result); }
            }

            return (result);
        }

        void Reset() override
        {
            IPCMessage message(BaseClass::Message(0));

            UnknownProxyType::Invoke(message);
        }

        bool IsValid() const override
        {
            IPCMessage message(BaseClass::Message(1));

            bool result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Boolean();

            return (result);
        }

        bool Next() override
        {
            IPCMessage message(BaseClass::Message(2));

            bool result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Boolean();

            return (result);
        }

        Exchange::ITestController::ICategory* Category() const override
        {
            IPCMessage message(BaseClass::Message(3));

            Exchange::ITestController::ICategory* result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reinterpret_cast<Exchange::ITestController::ICategory*>(Interface(reader.Number<Core::instance_id>(), Exchange::ITestController::ICategory::ID));

            return (result);
        }

    }; // class ExchangeTestControllerCategoryIteratorProxy

    POP_WARNING()
    POP_WARNING()

    // -----------------------------------------------------------------
    // REGISTRATION
    // -----------------------------------------------------------------

    namespace {

        typedef ProxyStub::UnknownStubType<Exchange::ITestController, ExchangeTestControllerStubMethods> ExchangeTestControllerStub;
        typedef ProxyStub::UnknownStubType<Exchange::ITestController::ITest, ExchangeTestControllerTestStubMethods> ExchangeTestControllerTestStub;
        typedef ProxyStub::UnknownStubType<Exchange::ITestController::ITest::IIterator, ExchangeTestControllerTestIteratorStubMethods> ExchangeTestControllerTestIteratorStub;
        typedef ProxyStub::UnknownStubType<Exchange::ITestController::ICategory, ExchangeTestControllerCategoryStubMethods> ExchangeTestControllerCategoryStub;
        typedef ProxyStub::UnknownStubType<Exchange::ITestController::ICategory::IIterator, ExchangeTestControllerCategoryIteratorStubMethods> ExchangeTestControllerCategoryIteratorStub;

        static class Instantiation {
        public:
            Instantiation()
            {
                RPC::Administrator::Instance().Announce<Exchange::ITestController, ExchangeTestControllerProxy, ExchangeTestControllerStub>();
                RPC::Administrator::Instance().Announce<Exchange::ITestController::ITest, ExchangeTestControllerTestProxy, ExchangeTestControllerTestStub>();
                RPC::Administrator::Instance().Announce<Exchange::ITestController::ITest::IIterator, ExchangeTestControllerTestIteratorProxy, ExchangeTestControllerTestIteratorStub>();
                RPC::Administrator::Instance().Announce<Exchange::ITestController::ICategory, ExchangeTestControllerCategoryProxy, ExchangeTestControllerCategoryStub>();
                RPC::Administrator::Instance().Announce<Exchange::ITestController::ICategory::IIterator, ExchangeTestControllerCategoryIteratorProxy, ExchangeTestControllerCategoryIteratorStub>();
            }
            ~Instantiation()
            {
                RPC::Administrator::Instance().Recall<Exchange::ITestController>();
                RPC::Administrator::Instance().Recall<Exchange::ITestController::ITest>();
                RPC::Administrator::Instance().Recall<Exchange::ITestController::ITest::IIterator>();
                RPC::Administrator::Instance().Recall<Exchange::ITestController::ICategory>();
                RPC::Administrator::Instance().Recall<Exchange::ITestController::ICategory::IIterator>();
            }
        } ProxyStubRegistration;

    } // namespace

} // namespace ProxyStubs

}
