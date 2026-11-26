//
// generated automatically from "ITestUtility.h"
//
// implements COM-RPC proxy stubs for:
//   - class QualityAssurance::ITestUtility
//   - class QualityAssurance::ITestUtility::ICommand
//   - class QualityAssurance::ITestUtility::ICommand::IIterator
//

#include "Module.h"
#include "ITestUtility.h"

#include <com/com.h>

namespace Thunder {

namespace ProxyStubs {

    PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    // -----------------------------------------------------------------
    // STUBS
    // -----------------------------------------------------------------

    //
    // QualityAssurance::ITestUtility interface stub definitions
    //
    // Methods:
    //  (0) virtual QualityAssurance::ITestUtility::ICommand::IIterator* Commands() const = 0
    //  (1) virtual QualityAssurance::ITestUtility::ICommand* Command(const string&) const = 0
    //  (2) virtual uint32_t ShutdownTimeout(const uint32_t) = 0
    //

    static ProxyStub::MethodHandler QualityAssuranceTestUtilityStubMethods[] = {
        // (0) virtual QualityAssurance::ITestUtility::ICommand::IIterator* Commands() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            const QualityAssurance::ITestUtility* implementation = reinterpret_cast<const QualityAssurance::ITestUtility*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            QualityAssurance::ITestUtility::ICommand::IIterator* result = implementation->Commands();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(result));

            RPC::Administrator::Instance().RegisterInterface(channel, result);
        },

        // (1) virtual QualityAssurance::ITestUtility::ICommand* Command(const string&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            const QualityAssurance::ITestUtility* implementation = reinterpret_cast<const QualityAssurance::ITestUtility*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _name = reader.Text();

            QualityAssurance::ITestUtility::ICommand* result = implementation->Command(static_cast<const string&>(_name));

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(result));

            RPC::Administrator::Instance().RegisterInterface(channel, result);
        },

        // (2) virtual uint32_t ShutdownTimeout(const uint32_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            QualityAssurance::ITestUtility* implementation = reinterpret_cast<QualityAssurance::ITestUtility*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint32_t _timeout = reader.Number<uint32_t>();

            uint32_t result = implementation->ShutdownTimeout(_timeout);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        }
        , nullptr
    }; // QualityAssuranceTestUtilityStubMethods

    //
    // QualityAssurance::ITestUtility::ICommand interface stub definitions
    //
    // Methods:
    //  (0) virtual string Execute(const string&) = 0
    //  (1) virtual string Description() const = 0
    //  (2) virtual string Signature() const = 0
    //  (3) virtual string Name() const = 0
    //

    static ProxyStub::MethodHandler QualityAssuranceTestUtilityCommandStubMethods[] = {
        // (0) virtual string Execute(const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            QualityAssurance::ITestUtility::ICommand* implementation = reinterpret_cast<QualityAssurance::ITestUtility::ICommand*>(message->Parameters().Implementation());
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
            const QualityAssurance::ITestUtility::ICommand* implementation = reinterpret_cast<const QualityAssurance::ITestUtility::ICommand*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            string result = implementation->Description();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Text(result);
        },

        // (2) virtual string Signature() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const QualityAssurance::ITestUtility::ICommand* implementation = reinterpret_cast<const QualityAssurance::ITestUtility::ICommand*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            string result = implementation->Signature();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Text(result);
        },

        // (3) virtual string Name() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const QualityAssurance::ITestUtility::ICommand* implementation = reinterpret_cast<const QualityAssurance::ITestUtility::ICommand*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            string result = implementation->Name();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Text(result);
        }
        , nullptr
    }; // QualityAssuranceTestUtilityCommandStubMethods

    //
    // QualityAssurance::ITestUtility::ICommand::IIterator interface stub definitions
    //
    // Methods:
    //  (0) virtual void Reset() = 0
    //  (1) virtual bool IsValid() const = 0
    //  (2) virtual bool Next() = 0
    //  (3) virtual QualityAssurance::ITestUtility::ICommand* Command() const = 0
    //

    static ProxyStub::MethodHandler QualityAssuranceTestUtilityCommandIteratorStubMethods[] = {
        // (0) virtual void Reset() = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            QualityAssurance::ITestUtility::ICommand::IIterator* implementation = reinterpret_cast<QualityAssurance::ITestUtility::ICommand::IIterator*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            implementation->Reset();
        },

        // (1) virtual bool IsValid() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const QualityAssurance::ITestUtility::ICommand::IIterator* implementation = reinterpret_cast<const QualityAssurance::ITestUtility::ICommand::IIterator*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            bool result = implementation->IsValid();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Boolean(result);
        },

        // (2) virtual bool Next() = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            QualityAssurance::ITestUtility::ICommand::IIterator* implementation = reinterpret_cast<QualityAssurance::ITestUtility::ICommand::IIterator*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            bool result = implementation->Next();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Boolean(result);
        },

        // (3) virtual QualityAssurance::ITestUtility::ICommand* Command() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            const QualityAssurance::ITestUtility::ICommand::IIterator* implementation = reinterpret_cast<const QualityAssurance::ITestUtility::ICommand::IIterator*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            QualityAssurance::ITestUtility::ICommand* result = implementation->Command();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(result));

            RPC::Administrator::Instance().RegisterInterface(channel, result);
        }
        , nullptr
    }; // QualityAssuranceTestUtilityCommandIteratorStubMethods

    // -----------------------------------------------------------------
    // PROXIES
    // -----------------------------------------------------------------

    //
    // QualityAssurance::ITestUtility interface proxy definitions
    //
    // Methods:
    //  (0) virtual QualityAssurance::ITestUtility::ICommand::IIterator* Commands() const = 0
    //  (1) virtual QualityAssurance::ITestUtility::ICommand* Command(const string&) const = 0
    //  (2) virtual uint32_t ShutdownTimeout(const uint32_t) = 0
    //

    class QualityAssuranceTestUtilityProxy final : public ProxyStub::UnknownProxyType<QualityAssurance::ITestUtility> {
    public:
        QualityAssuranceTestUtilityProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        QualityAssurance::ITestUtility::ICommand::IIterator* Commands() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            QualityAssurance::ITestUtility::ICommand::IIterator* result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reinterpret_cast<QualityAssurance::ITestUtility::ICommand::IIterator*>(static_cast<const ProxyStub::UnknownProxy&>(*this).Interface(reader.Number<Core::instance_id>(), QualityAssurance::ITestUtility::ICommand::IIterator::ID));
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        QualityAssurance::ITestUtility::ICommand* Command(const string& _name) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_name);

            QualityAssurance::ITestUtility::ICommand* result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reinterpret_cast<QualityAssurance::ITestUtility::ICommand*>(static_cast<const ProxyStub::UnknownProxy&>(*this).Interface(reader.Number<Core::instance_id>(), QualityAssurance::ITestUtility::ICommand::ID));
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        uint32_t ShutdownTimeout(const uint32_t _timeout) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(2));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_timeout);

            uint32_t result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Number<uint32_t>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

    }; // class QualityAssuranceTestUtilityProxy

    //
    // QualityAssurance::ITestUtility::ICommand interface proxy definitions
    //
    // Methods:
    //  (0) virtual string Execute(const string&) = 0
    //  (1) virtual string Description() const = 0
    //  (2) virtual string Signature() const = 0
    //  (3) virtual string Name() const = 0
    //

    class QualityAssuranceTestUtilityCommandProxy final : public ProxyStub::UnknownProxyType<QualityAssurance::ITestUtility::ICommand> {
    public:
        QualityAssuranceTestUtilityCommandProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
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

        string Signature() const override
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

        string Name() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(3));

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

    }; // class QualityAssuranceTestUtilityCommandProxy

    //
    // QualityAssurance::ITestUtility::ICommand::IIterator interface proxy definitions
    //
    // Methods:
    //  (0) virtual void Reset() = 0
    //  (1) virtual bool IsValid() const = 0
    //  (2) virtual bool Next() = 0
    //  (3) virtual QualityAssurance::ITestUtility::ICommand* Command() const = 0
    //

    class QualityAssuranceTestUtilityCommandIteratorProxy final : public ProxyStub::UnknownProxyType<QualityAssurance::ITestUtility::ICommand::IIterator> {
    public:
        QualityAssuranceTestUtilityCommandIteratorProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
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

        QualityAssurance::ITestUtility::ICommand* Command() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(3));

            QualityAssurance::ITestUtility::ICommand* result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reinterpret_cast<QualityAssurance::ITestUtility::ICommand*>(static_cast<const ProxyStub::UnknownProxy&>(*this).Interface(reader.Number<Core::instance_id>(), QualityAssurance::ITestUtility::ICommand::ID));
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

    }; // class QualityAssuranceTestUtilityCommandIteratorProxy

    POP_WARNING()
    POP_WARNING()

    // -----------------------------------------------------------------
    // REGISTRATION
    // -----------------------------------------------------------------
    namespace {

        typedef ProxyStub::UnknownStubType<QualityAssurance::ITestUtility, QualityAssuranceTestUtilityStubMethods> QualityAssuranceTestUtilityStub;
        typedef ProxyStub::UnknownStubType<QualityAssurance::ITestUtility::ICommand, QualityAssuranceTestUtilityCommandStubMethods> QualityAssuranceTestUtilityCommandStub;
        typedef ProxyStub::UnknownStubType<QualityAssurance::ITestUtility::ICommand::IIterator, QualityAssuranceTestUtilityCommandIteratorStubMethods> QualityAssuranceTestUtilityCommandIteratorStub;

        static class Instantiation {
        public:
            Instantiation()
            {
                RPC::Administrator::Instance().Announce<QualityAssurance::ITestUtility, QualityAssuranceTestUtilityProxy, QualityAssuranceTestUtilityStub>();
                RPC::Administrator::Instance().Announce<QualityAssurance::ITestUtility::ICommand, QualityAssuranceTestUtilityCommandProxy, QualityAssuranceTestUtilityCommandStub>();
                RPC::Administrator::Instance().Announce<QualityAssurance::ITestUtility::ICommand::IIterator, QualityAssuranceTestUtilityCommandIteratorProxy, QualityAssuranceTestUtilityCommandIteratorStub>();
            }
            ~Instantiation()
            {
                RPC::Administrator::Instance().Recall<QualityAssurance::ITestUtility>();
                RPC::Administrator::Instance().Recall<QualityAssurance::ITestUtility::ICommand>();
                RPC::Administrator::Instance().Recall<QualityAssurance::ITestUtility::ICommand::IIterator>();
            }
        } ProxyStubRegistration;

    } // namespace

} // namespace ProxyStubs

}
