//
// generated automatically from "ICOM.h"
//
// implements COM-RPC proxy stubs for:
//   - class IIteratorType<typename ELEMENT, const uint32_t> [with ELEMENT = string, INTERFACE_ID = ID_STRINGITERATOR]
//   - class IIteratorType<typename ELEMENT, const uint32_t> [with ELEMENT = uint32_t, INTERFACE_ID = ID_VALUEITERATOR]
//   - class IRemoteConnection
//   - class IRemoteConnection::INotification
//

#include "Module.h"
#include "ICOM.h"

#include <com/com.h>

namespace WPEFramework {

namespace ProxyStubs {

    using namespace RPC;

    PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    // -----------------------------------------------------------------
    // STUBS
    // -----------------------------------------------------------------

    //
    // IIteratorTypeInstance714555E4 interface stub definitions
    //
    // Methods:
    //  (0) virtual bool Next(string&) = 0
    //  (1) virtual bool Previous(string&) = 0
    //  (2) virtual void Reset(const uint32_t) = 0
    //  (3) virtual bool IsValid() const = 0
    //  (4) virtual uint32_t Count() const = 0
    //  (5) virtual string Current() const = 0
    //

    ProxyStub::MethodHandler IteratorTypeInstance714555E4StubMethods[] = {
        // (0) virtual bool Next(string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = IIteratorType<string, ID_STRINGITERATOR>;

            interface* implementation = reinterpret_cast<interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            string _info{};

            bool result = implementation->Next(_info);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Boolean(result);
            writer.Text(_info);
        },

        // (1) virtual bool Previous(string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = IIteratorType<string, ID_STRINGITERATOR>;

            interface* implementation = reinterpret_cast<interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            string _info{};

            bool result = implementation->Previous(_info);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Boolean(result);
            writer.Text(_info);
        },

        // (2) virtual void Reset(const uint32_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = IIteratorType<string, ID_STRINGITERATOR>;

            interface* implementation = reinterpret_cast<interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint32_t _position = reader.Number<uint32_t>();

            implementation->Reset(_position);
        },

        // (3) virtual bool IsValid() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = IIteratorType<string, ID_STRINGITERATOR>;

            const interface* implementation = reinterpret_cast<const interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            bool result = implementation->IsValid();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Boolean(result);
        },

        // (4) virtual uint32_t Count() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = IIteratorType<string, ID_STRINGITERATOR>;

            const interface* implementation = reinterpret_cast<const interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            uint32_t result = implementation->Count();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (5) virtual string Current() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = IIteratorType<string, ID_STRINGITERATOR>;

            const interface* implementation = reinterpret_cast<const interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            string result = implementation->Current();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Text(result);
        }
        , nullptr
    }; // IteratorTypeInstance714555E4StubMethods

    //
    // IIteratorTypeInstance1AD01D22 interface stub definitions
    //
    // Methods:
    //  (0) virtual bool Next(uint32_t&) = 0
    //  (1) virtual bool Previous(uint32_t&) = 0
    //  (2) virtual void Reset(const uint32_t) = 0
    //  (3) virtual bool IsValid() const = 0
    //  (4) virtual uint32_t Count() const = 0
    //  (5) virtual uint32_t Current() const = 0
    //

    ProxyStub::MethodHandler IteratorTypeInstance1AD01D22StubMethods[] = {
        // (0) virtual bool Next(uint32_t&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = IIteratorType<uint32_t, ID_VALUEITERATOR>;

            interface* implementation = reinterpret_cast<interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            uint32_t _info{};

            bool result = implementation->Next(_info);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Boolean(result);
            writer.Number<uint32_t>(_info);
        },

        // (1) virtual bool Previous(uint32_t&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = IIteratorType<uint32_t, ID_VALUEITERATOR>;

            interface* implementation = reinterpret_cast<interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            uint32_t _info{};

            bool result = implementation->Previous(_info);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Boolean(result);
            writer.Number<uint32_t>(_info);
        },

        // (2) virtual void Reset(const uint32_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = IIteratorType<uint32_t, ID_VALUEITERATOR>;

            interface* implementation = reinterpret_cast<interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint32_t _position = reader.Number<uint32_t>();

            implementation->Reset(_position);
        },

        // (3) virtual bool IsValid() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = IIteratorType<uint32_t, ID_VALUEITERATOR>;

            const interface* implementation = reinterpret_cast<const interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            bool result = implementation->IsValid();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Boolean(result);
        },

        // (4) virtual uint32_t Count() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = IIteratorType<uint32_t, ID_VALUEITERATOR>;

            const interface* implementation = reinterpret_cast<const interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            uint32_t result = implementation->Count();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (5) virtual uint32_t Current() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = IIteratorType<uint32_t, ID_VALUEITERATOR>;

            const interface* implementation = reinterpret_cast<const interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            uint32_t result = implementation->Current();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        }
        , nullptr
    }; // IteratorTypeInstance1AD01D22StubMethods

    //
    // IRemoteConnection interface stub definitions
    //
    // Methods:
    //  (0) virtual uint32_t Id() const = 0
    //  (1) virtual uint32_t RemoteId() const = 0
    //  (2) virtual void* Acquire(const uint32_t, const string&, const uint32_t, const uint32_t) = 0
    //  (3) virtual void Terminate() = 0
    //  (4) virtual uint32_t Launch() = 0
    //  (5) virtual void PostMortem() = 0
    //

    ProxyStub::MethodHandler RemoteConnectionStubMethods[] = {
        // (0) virtual uint32_t Id() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const IRemoteConnection* implementation = reinterpret_cast<const IRemoteConnection*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            uint32_t result = implementation->Id();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (1) virtual uint32_t RemoteId() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const IRemoteConnection* implementation = reinterpret_cast<const IRemoteConnection*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            uint32_t result = implementation->RemoteId();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (2) virtual void* Acquire(const uint32_t, const string&, const uint32_t, const uint32_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            IRemoteConnection* implementation = reinterpret_cast<IRemoteConnection*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint32_t _waitTime = reader.Number<uint32_t>();
            const string _className = reader.Text();
            const uint32_t _interfaceId = reader.Number<uint32_t>();
            const uint32_t _version = reader.Number<uint32_t>();

            void* result = implementation->Acquire(_waitTime, static_cast<const string&>(_className), _interfaceId, _version);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(result));

            RPC::Administrator::Instance().RegisterInterface(channel, result, _interfaceId);
        },

        // (3) virtual void Terminate() = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            IRemoteConnection* implementation = reinterpret_cast<IRemoteConnection*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            implementation->Terminate();
        },

        // (4) virtual uint32_t Launch() = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            IRemoteConnection* implementation = reinterpret_cast<IRemoteConnection*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            uint32_t result = implementation->Launch();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (5) virtual void PostMortem() = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            IRemoteConnection* implementation = reinterpret_cast<IRemoteConnection*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            implementation->PostMortem();
        }
        , nullptr
    }; // RemoteConnectionStubMethods

    //
    // IRemoteConnection::INotification interface stub definitions
    //
    // Methods:
    //  (0) virtual void Activated(IRemoteConnection*) = 0
    //  (1) virtual void Deactivated(IRemoteConnection*) = 0
    //  (2) virtual void Terminated(IRemoteConnection*)
    //

    ProxyStub::MethodHandler RemoteConnectionNotificationStubMethods[] = {
        // (0) virtual void Activated(IRemoteConnection*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            IRemoteConnection::INotification* implementation = reinterpret_cast<IRemoteConnection::INotification*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const Core::instance_id parameter_e6c64437Implementation = reader.Number<Core::instance_id>();

            IRemoteConnection* _parameter_e6c64437 = nullptr;
            ProxyStub::UnknownProxy* parameter_e6c64437Proxy = nullptr;
            if (parameter_e6c64437Implementation != 0) {
                parameter_e6c64437Proxy = RPC::Administrator::Instance().ProxyInstance(channel, parameter_e6c64437Implementation, false, _parameter_e6c64437);

                ASSERT((_parameter_e6c64437 != nullptr) && (parameter_e6c64437Proxy != nullptr));
            }

            implementation->Activated(_parameter_e6c64437);

            if (parameter_e6c64437Proxy != nullptr) {
                RPC::Administrator::Instance().Release(parameter_e6c64437Proxy, message->Response());
            }
        },

        // (1) virtual void Deactivated(IRemoteConnection*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            IRemoteConnection::INotification* implementation = reinterpret_cast<IRemoteConnection::INotification*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const Core::instance_id parameter_4dc20c19Implementation = reader.Number<Core::instance_id>();

            IRemoteConnection* _parameter_4dc20c19 = nullptr;
            ProxyStub::UnknownProxy* parameter_4dc20c19Proxy = nullptr;
            if (parameter_4dc20c19Implementation != 0) {
                parameter_4dc20c19Proxy = RPC::Administrator::Instance().ProxyInstance(channel, parameter_4dc20c19Implementation, false, _parameter_4dc20c19);

                ASSERT((_parameter_4dc20c19 != nullptr) && (parameter_4dc20c19Proxy != nullptr));
            }

            implementation->Deactivated(_parameter_4dc20c19);

            if (parameter_4dc20c19Proxy != nullptr) {
                RPC::Administrator::Instance().Release(parameter_4dc20c19Proxy, message->Response());
            }
        },

        // (2) virtual void Terminated(IRemoteConnection*)
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            IRemoteConnection::INotification* implementation = reinterpret_cast<IRemoteConnection::INotification*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const Core::instance_id parameter_b461cfb7Implementation = reader.Number<Core::instance_id>();

            IRemoteConnection* _parameter_b461cfb7 = nullptr;
            ProxyStub::UnknownProxy* parameter_b461cfb7Proxy = nullptr;
            if (parameter_b461cfb7Implementation != 0) {
                parameter_b461cfb7Proxy = RPC::Administrator::Instance().ProxyInstance(channel, parameter_b461cfb7Implementation, false, _parameter_b461cfb7);

                ASSERT((_parameter_b461cfb7 != nullptr) && (parameter_b461cfb7Proxy != nullptr));
            }

            implementation->Terminated(_parameter_b461cfb7);

            if (parameter_b461cfb7Proxy != nullptr) {
                RPC::Administrator::Instance().Release(parameter_b461cfb7Proxy, message->Response());
            }
        }
        , nullptr
    }; // RemoteConnectionNotificationStubMethods

    // -----------------------------------------------------------------
    // PROXIES
    // -----------------------------------------------------------------

    //
    // IIteratorTypeInstance714555E4 interface proxy definitions
    //
    // Methods:
    //  (0) virtual bool Next(string&) = 0
    //  (1) virtual bool Previous(string&) = 0
    //  (2) virtual void Reset(const uint32_t) = 0
    //  (3) virtual bool IsValid() const = 0
    //  (4) virtual uint32_t Count() const = 0
    //  (5) virtual string Current() const = 0
    //

    class IteratorTypeInstance714555E4Proxy final : public ProxyStub::UnknownProxyType<IIteratorType<string, ID_STRINGITERATOR>> {
    public:
        IteratorTypeInstance714555E4Proxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
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

        bool Next(string& _info) override
        {
            IPCMessage message(BaseClass::Message(0));

            bool result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Boolean();
            _info = reader.Text();

            return (result);
        }

        bool Previous(string& _info) override
        {
            IPCMessage message(BaseClass::Message(1));

            bool result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Boolean();
            _info = reader.Text();

            return (result);
        }

        void Reset(const uint32_t _position) override
        {
            IPCMessage message(BaseClass::Message(2));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_position);

            UnknownProxyType::Invoke(message);
        }

        bool IsValid() const override
        {
            IPCMessage message(BaseClass::Message(3));

            bool result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Boolean();

            return (result);
        }

        uint32_t Count() const override
        {
            IPCMessage message(BaseClass::Message(4));

            uint32_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint32_t>();

            return (result);
        }

        string Current() const override
        {
            IPCMessage message(BaseClass::Message(5));

            string result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Text();

            return (result);
        }

    }; // class IteratorTypeInstance714555E4Proxy

    //
    // IIteratorTypeInstance1AD01D22 interface proxy definitions
    //
    // Methods:
    //  (0) virtual bool Next(uint32_t&) = 0
    //  (1) virtual bool Previous(uint32_t&) = 0
    //  (2) virtual void Reset(const uint32_t) = 0
    //  (3) virtual bool IsValid() const = 0
    //  (4) virtual uint32_t Count() const = 0
    //  (5) virtual uint32_t Current() const = 0
    //

    class IteratorTypeInstance1AD01D22Proxy final : public ProxyStub::UnknownProxyType<IIteratorType<uint32_t, ID_VALUEITERATOR>> {
    public:
        IteratorTypeInstance1AD01D22Proxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
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

        bool Next(uint32_t& _info) override
        {
            IPCMessage message(BaseClass::Message(0));

            bool result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Boolean();
            _info = reader.Number<uint32_t>();

            return (result);
        }

        bool Previous(uint32_t& _info) override
        {
            IPCMessage message(BaseClass::Message(1));

            bool result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Boolean();
            _info = reader.Number<uint32_t>();

            return (result);
        }

        void Reset(const uint32_t _position) override
        {
            IPCMessage message(BaseClass::Message(2));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_position);

            UnknownProxyType::Invoke(message);
        }

        bool IsValid() const override
        {
            IPCMessage message(BaseClass::Message(3));

            bool result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Boolean();

            return (result);
        }

        uint32_t Count() const override
        {
            IPCMessage message(BaseClass::Message(4));

            uint32_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint32_t>();

            return (result);
        }

        uint32_t Current() const override
        {
            IPCMessage message(BaseClass::Message(5));

            uint32_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint32_t>();

            return (result);
        }

    }; // class IteratorTypeInstance1AD01D22Proxy

    //
    // IRemoteConnection interface proxy definitions
    //
    // Methods:
    //  (0) virtual uint32_t Id() const = 0
    //  (1) virtual uint32_t RemoteId() const = 0
    //  (2) virtual void* Acquire(const uint32_t, const string&, const uint32_t, const uint32_t) = 0
    //  (3) virtual void Terminate() = 0
    //  (4) virtual uint32_t Launch() = 0
    //  (5) virtual void PostMortem() = 0
    //

    class RemoteConnectionProxy final : public ProxyStub::UnknownProxyType<IRemoteConnection> {
    public:
        RemoteConnectionProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
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

        uint32_t Id() const override
        {
            IPCMessage message(BaseClass::Message(0));

            uint32_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint32_t>();

            return (result);
        }

        uint32_t RemoteId() const override
        {
            IPCMessage message(BaseClass::Message(1));

            uint32_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint32_t>();

            return (result);
        }

        void* Acquire(const uint32_t _waitTime, const string& _className, const uint32_t _interfaceId, const uint32_t _version) override
        {
            IPCMessage message(BaseClass::Message(2));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_waitTime);
            writer.Text(static_cast<const string&>(_className));
            writer.Number<uint32_t>(_interfaceId);
            writer.Number<uint32_t>(_version);

            void* result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reinterpret_cast<void*>(Interface(reader.Number<Core::instance_id>(), _interfaceId));

            return (result);
        }

        void Terminate() override
        {
            IPCMessage message(BaseClass::Message(3));

            UnknownProxyType::Invoke(message);
        }

        uint32_t Launch() override
        {
            IPCMessage message(BaseClass::Message(4));

            uint32_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint32_t>();

            return (result);
        }

        void PostMortem() override
        {
            IPCMessage message(BaseClass::Message(5));

            UnknownProxyType::Invoke(message);
        }

    }; // class RemoteConnectionProxy

    //
    // IRemoteConnection::INotification interface proxy definitions
    //
    // Methods:
    //  (0) virtual void Activated(IRemoteConnection*) = 0
    //  (1) virtual void Deactivated(IRemoteConnection*) = 0
    //  (2) virtual void Terminated(IRemoteConnection*)
    //

    class RemoteConnectionNotificationProxy final : public ProxyStub::UnknownProxyType<IRemoteConnection::INotification> {
    public:
        RemoteConnectionNotificationProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
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

        void Activated(IRemoteConnection* _parameter_e6c64437) override
        {
            IPCMessage message(BaseClass::Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_parameter_e6c64437));

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());

            Complete(reader);
        }

        void Deactivated(IRemoteConnection* _parameter_4dc20c19) override
        {
            IPCMessage message(BaseClass::Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_parameter_4dc20c19));

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());

            Complete(reader);
        }

        void Terminated(IRemoteConnection* _parameter_b461cfb7) override
        {
            IPCMessage message(BaseClass::Message(2));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_parameter_b461cfb7));

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());

            Complete(reader);
        }

    }; // class RemoteConnectionNotificationProxy

    POP_WARNING()
    POP_WARNING()

    // -----------------------------------------------------------------
    // REGISTRATION
    // -----------------------------------------------------------------

    namespace {

        typedef ProxyStub::UnknownStubType<IIteratorType<string, ID_STRINGITERATOR>, IteratorTypeInstance714555E4StubMethods> IteratorTypeInstance714555E4Stub;
        typedef ProxyStub::UnknownStubType<IIteratorType<uint32_t, ID_VALUEITERATOR>, IteratorTypeInstance1AD01D22StubMethods> IteratorTypeInstance1AD01D22Stub;
        typedef ProxyStub::UnknownStubType<IRemoteConnection, RemoteConnectionStubMethods> RemoteConnectionStub;
        typedef ProxyStub::UnknownStubType<IRemoteConnection::INotification, RemoteConnectionNotificationStubMethods> RemoteConnectionNotificationStub;

        static class Instantiation {
        public:
            Instantiation()
            {
                RPC::Administrator::Instance().Announce<IIteratorType<string, ID_STRINGITERATOR>, IteratorTypeInstance714555E4Proxy, IteratorTypeInstance714555E4Stub>();
                RPC::Administrator::Instance().Announce<IIteratorType<uint32_t, ID_VALUEITERATOR>, IteratorTypeInstance1AD01D22Proxy, IteratorTypeInstance1AD01D22Stub>();
                RPC::Administrator::Instance().Announce<IRemoteConnection, RemoteConnectionProxy, RemoteConnectionStub>();
                RPC::Administrator::Instance().Announce<IRemoteConnection::INotification, RemoteConnectionNotificationProxy, RemoteConnectionNotificationStub>();
            }
            ~Instantiation()
            {
                RPC::Administrator::Instance().Recall<IIteratorType<string, ID_STRINGITERATOR>>();
                RPC::Administrator::Instance().Recall<IIteratorType<uint32_t, ID_VALUEITERATOR>>();
                RPC::Administrator::Instance().Recall<IRemoteConnection>();
                RPC::Administrator::Instance().Recall<IRemoteConnection::INotification>();
            }
        } ProxyStubRegistration;

    } // namespace

} // namespace ProxyStubs

}
