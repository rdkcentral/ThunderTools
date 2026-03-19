//
// generated automatically from "INetworkControl.h"
//
// implements COM-RPC proxy stubs for:
//   - class RPC::IIteratorType<typename ELEMENT, const uint32_t INTERFACE_ID> [with ELEMENT = Exchange::INetworkControl::NetworkInfo, INTERFACE_ID = Exchange::ID_NETWORKCONTROL_NETWORK_INFO_ITERATOR] [[iterator]]
//   - class RPC::IIteratorType<typename ELEMENT, const uint32_t INTERFACE_ID> [with ELEMENT = string, INTERFACE_ID = RPC::ID_STRINGITERATOR] [[iterator]]
//   - class Exchange::INetworkControl
//   - class Exchange::INetworkControl::INotification
//
// secure code enabled:
//   - instance verification enabled
//   - range verification enabled
//   - frame coherency verification enabled
//

#include "Module.h"
#include "INetworkControl.h"

#include <com/com.h>

namespace Thunder {

namespace ProxyStubs {

    PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    // -----------------------------------------------------------------
    // STUBS
    // -----------------------------------------------------------------

    //
    // RPC::IIteratorTypeInstance_4841f294117251fd interface stub definitions
    //
    // Methods:
    //  (0) virtual bool Next(Exchange::INetworkControl::NetworkInfo&) = 0
    //  (1) virtual bool Previous(Exchange::INetworkControl::NetworkInfo&) = 0
    //  (2) virtual void Reset(const uint32_t) = 0
    //  (3) virtual bool IsValid() const = 0
    //  (4) virtual uint32_t Count() const = 0
    //  (5) virtual Exchange::INetworkControl::NetworkInfo Current() const = 0
    //

    static ProxyStub::MethodHandler RPCIteratorTypeInstance_4841f294117251fdStubMethods[] = {
        // (0) virtual bool Next(Exchange::INetworkControl::NetworkInfo&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                using interface = RPC::IIteratorType<Exchange::INetworkControl::NetworkInfo, Exchange::ID_NETWORKCONTROL_NETWORK_INFO_ITERATOR>;

                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                interface* implementation = reinterpret_cast<interface*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), interface::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                Exchange::INetworkControl::NetworkInfo _info{};

                bool result = implementation->Next(_info);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Boolean(result);
                writer.Text(_info.address);
                writer.Text(_info.defaultGateway);
                writer.Number<uint8_t>(_info.mask);
                writer.Number<Exchange::INetworkControl::ModeType>(_info.mode);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", RPC::IIteratorType<Exchange::INetworkControl::NetworkInfo, Exchange::ID_NETWORKCONTROL_NETWORK_INFO_ITERATOR>::ID, 0, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        },

        // (1) virtual bool Previous(Exchange::INetworkControl::NetworkInfo&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                using interface = RPC::IIteratorType<Exchange::INetworkControl::NetworkInfo, Exchange::ID_NETWORKCONTROL_NETWORK_INFO_ITERATOR>;

                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                interface* implementation = reinterpret_cast<interface*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), interface::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                Exchange::INetworkControl::NetworkInfo _info{};

                bool result = implementation->Previous(_info);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Boolean(result);
                writer.Text(_info.address);
                writer.Text(_info.defaultGateway);
                writer.Number<uint8_t>(_info.mask);
                writer.Number<Exchange::INetworkControl::ModeType>(_info.mode);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", RPC::IIteratorType<Exchange::INetworkControl::NetworkInfo, Exchange::ID_NETWORKCONTROL_NETWORK_INFO_ITERATOR>::ID, 1, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        },

        // (2) virtual void Reset(const uint32_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                using interface = RPC::IIteratorType<Exchange::INetworkControl::NetworkInfo, Exchange::ID_NETWORKCONTROL_NETWORK_INFO_ITERATOR>;

                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                interface* implementation = reinterpret_cast<interface*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), interface::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint32_t _position = reader.Number<uint32_t>();

                implementation->Reset(_position);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", RPC::IIteratorType<Exchange::INetworkControl::NetworkInfo, Exchange::ID_NETWORKCONTROL_NETWORK_INFO_ITERATOR>::ID, 2, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        },

        // (3) virtual bool IsValid() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                using interface = RPC::IIteratorType<Exchange::INetworkControl::NetworkInfo, Exchange::ID_NETWORKCONTROL_NETWORK_INFO_ITERATOR>;

                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const interface* implementation = reinterpret_cast<const interface*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), interface::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                bool result = implementation->IsValid();

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Boolean(result);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", RPC::IIteratorType<Exchange::INetworkControl::NetworkInfo, Exchange::ID_NETWORKCONTROL_NETWORK_INFO_ITERATOR>::ID, 3, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        },

        // (4) virtual uint32_t Count() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                using interface = RPC::IIteratorType<Exchange::INetworkControl::NetworkInfo, Exchange::ID_NETWORKCONTROL_NETWORK_INFO_ITERATOR>;

                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const interface* implementation = reinterpret_cast<const interface*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), interface::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                uint32_t result = implementation->Count();

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(result);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", RPC::IIteratorType<Exchange::INetworkControl::NetworkInfo, Exchange::ID_NETWORKCONTROL_NETWORK_INFO_ITERATOR>::ID, 4, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        },

        // (5) virtual Exchange::INetworkControl::NetworkInfo Current() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                using interface = RPC::IIteratorType<Exchange::INetworkControl::NetworkInfo, Exchange::ID_NETWORKCONTROL_NETWORK_INFO_ITERATOR>;

                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const interface* implementation = reinterpret_cast<const interface*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), interface::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                Exchange::INetworkControl::NetworkInfo result = implementation->Current();

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Text(result.address);
                writer.Text(result.defaultGateway);
                writer.Number<uint8_t>(result.mask);
                writer.Number<Exchange::INetworkControl::ModeType>(result.mode);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", RPC::IIteratorType<Exchange::INetworkControl::NetworkInfo, Exchange::ID_NETWORKCONTROL_NETWORK_INFO_ITERATOR>::ID, 5, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        }
        , nullptr
    }; // RPCIteratorTypeInstance_4841f294117251fdStubMethods

    //
    // RPC::IIteratorTypeInstance_b3acff3685df4032 interface stub definitions
    //
    // Methods:
    //  (0) virtual bool Next(string&) = 0
    //  (1) virtual bool Previous(string&) = 0
    //  (2) virtual void Reset(const uint32_t) = 0
    //  (3) virtual bool IsValid() const = 0
    //  (4) virtual uint32_t Count() const = 0
    //  (5) virtual string Current() const = 0
    //

    static ProxyStub::MethodHandler RPCIteratorTypeInstance_b3acff3685df4032StubMethods[] = {
        // (0) virtual bool Next(string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                using interface = RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>;

                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                interface* implementation = reinterpret_cast<interface*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), interface::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                string _info{};

                bool result = implementation->Next(_info);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Boolean(result);
                writer.Text(_info);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>::ID, 0, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        },

        // (1) virtual bool Previous(string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                using interface = RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>;

                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                interface* implementation = reinterpret_cast<interface*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), interface::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                string _info{};

                bool result = implementation->Previous(_info);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Boolean(result);
                writer.Text(_info);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>::ID, 1, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        },

        // (2) virtual void Reset(const uint32_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                using interface = RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>;

                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                interface* implementation = reinterpret_cast<interface*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), interface::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint32_t _position = reader.Number<uint32_t>();

                implementation->Reset(_position);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>::ID, 2, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        },

        // (3) virtual bool IsValid() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                using interface = RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>;

                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const interface* implementation = reinterpret_cast<const interface*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), interface::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                bool result = implementation->IsValid();

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Boolean(result);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>::ID, 3, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        },

        // (4) virtual uint32_t Count() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                using interface = RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>;

                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const interface* implementation = reinterpret_cast<const interface*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), interface::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                uint32_t result = implementation->Count();

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(result);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>::ID, 4, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        },

        // (5) virtual string Current() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                using interface = RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>;

                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const interface* implementation = reinterpret_cast<const interface*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), interface::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                string result = implementation->Current();

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Text(result);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>::ID, 5, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        }
        , nullptr
    }; // RPCIteratorTypeInstance_b3acff3685df4032StubMethods

    //
    // Exchange::INetworkControl interface stub definitions
    //
    // Methods:
    //  (0) virtual uint32_t Register(Exchange::INetworkControl::INotification*) = 0
    //  (1) virtual uint32_t Unregister(Exchange::INetworkControl::INotification*) = 0
    //  (2) virtual uint32_t Interfaces(Exchange::INetworkControl::IStringIterator*&) const = 0
    //  (3) virtual uint32_t Status(const string&, Exchange::INetworkControl::StatusType&) const = 0
    //  (4) virtual uint32_t Network(const string&, Exchange::INetworkControl::INetworkInfoIterator*&) const = 0
    //  (5) virtual uint32_t Network(const string&, Exchange::INetworkControl::INetworkInfoIterator* const&) = 0
    //  (6) virtual uint32_t DNS(Exchange::INetworkControl::IStringIterator*&) const = 0
    //  (7) virtual uint32_t DNS(Exchange::INetworkControl::IStringIterator* const&) = 0
    //  (8) virtual uint32_t Up(const string&, bool&) const = 0
    //  (9) virtual uint32_t Up(const string&, const bool) = 0
    //  (10) virtual uint32_t Flush(const string&) = 0
    //

    static ProxyStub::MethodHandler ExchangeNetworkControlStubMethods[] = {
        // (0) virtual uint32_t Register(Exchange::INetworkControl::INotification*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                Exchange::INetworkControl* implementation = reinterpret_cast<Exchange::INetworkControl*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::INetworkControl::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (sizeof(Core::instance_id))) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                Core::instance_id _sinkInstanceId__ = reader.Number<Core::instance_id>();

                Exchange::INetworkControl::INotification* _sink{};
                ProxyStub::UnknownProxy* _sinkProxy__ = nullptr;
                if (_sinkInstanceId__ != 0) {
                    _sinkProxy__ = RPC::Administrator::Instance().ProxyInstance(channel, _sinkInstanceId__, false, _sink);
                    ASSERT((_sink != nullptr) && (_sinkProxy__ != nullptr));
                    if ((_sink == nullptr) || (_sinkProxy__ == nullptr)) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }
                }

                uint32_t result = implementation->Register(_sink);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(result);

                if (_sinkProxy__ != nullptr) {
                    RPC::Administrator::Instance().Release(_sinkProxy__, message->Response());
                }

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(hresult);
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::INetworkControl::ID, 0, hresult);
            }
        },

        // (1) virtual uint32_t Unregister(Exchange::INetworkControl::INotification*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                Exchange::INetworkControl* implementation = reinterpret_cast<Exchange::INetworkControl*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::INetworkControl::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (sizeof(Core::instance_id))) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                Core::instance_id _sinkInstanceId__ = reader.Number<Core::instance_id>();

                Exchange::INetworkControl::INotification* _sink{};
                ProxyStub::UnknownProxy* _sinkProxy__ = nullptr;
                if (_sinkInstanceId__ != 0) {
                    _sinkProxy__ = RPC::Administrator::Instance().ProxyInstance(channel, _sinkInstanceId__, false, _sink);
                    ASSERT((_sink != nullptr) && (_sinkProxy__ != nullptr));
                    if ((_sink == nullptr) || (_sinkProxy__ == nullptr)) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }
                }

                uint32_t result = implementation->Unregister(_sink);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(result);

                if (_sinkProxy__ != nullptr) {
                    RPC::Administrator::Instance().Release(_sinkProxy__, message->Response());
                }

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(hresult);
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::INetworkControl::ID, 1, hresult);
            }
        },

        // (2) virtual uint32_t Interfaces(Exchange::INetworkControl::IStringIterator*&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const Exchange::INetworkControl* implementation = reinterpret_cast<const Exchange::INetworkControl*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::INetworkControl::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                Exchange::INetworkControl::IStringIterator* _interfaces{};

                uint32_t result = implementation->Interfaces(_interfaces);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(result);
                writer.Number<Core::instance_id>(RPC::instance_cast(_interfaces));

                RPC::Administrator::Instance().RegisterInterface(channel, _interfaces);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(hresult);
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::INetworkControl::ID, 2, hresult);
            }
        },

        // (3) virtual uint32_t Status(const string&, Exchange::INetworkControl::StatusType&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const Exchange::INetworkControl* implementation = reinterpret_cast<const Exchange::INetworkControl*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::INetworkControl::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint16_t _interfacePeekedLen__ = reader.PeekNumber<uint16_t>();
                if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint16_t>()) + _interfacePeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const string _interface = reader.Text();

                Exchange::INetworkControl::StatusType _status{};

                uint32_t result = implementation->Status(static_cast<const string&>(_interface), _status);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(result);
                writer.Number<Exchange::INetworkControl::StatusType>(_status);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(hresult);
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::INetworkControl::ID, 3, hresult);
            }
        },

        // (4) virtual uint32_t Network(const string&, Exchange::INetworkControl::INetworkInfoIterator*&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const Exchange::INetworkControl* implementation = reinterpret_cast<const Exchange::INetworkControl*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::INetworkControl::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint16_t _interfacePeekedLen__ = reader.PeekNumber<uint16_t>();
                if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint16_t>()) + _interfacePeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const string _interface = reader.Text();

                Exchange::INetworkControl::INetworkInfoIterator* _networkInfo{};

                uint32_t result = implementation->Network(static_cast<const string&>(_interface), _networkInfo);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(result);
                writer.Number<Core::instance_id>(RPC::instance_cast(_networkInfo));

                RPC::Administrator::Instance().RegisterInterface(channel, _networkInfo);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(hresult);
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::INetworkControl::ID, 4, hresult);
            }
        },

        // (5) virtual uint32_t Network(const string&, Exchange::INetworkControl::INetworkInfoIterator* const&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                Exchange::INetworkControl* implementation = reinterpret_cast<Exchange::INetworkControl*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::INetworkControl::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint16_t _interfacePeekedLen__ = reader.PeekNumber<uint16_t>();
                if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint16_t>()) + _interfacePeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const string _interface = reader.Text();
                if (reader.Length() < (sizeof(Core::instance_id))) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                Core::instance_id _networkInfoInstanceId__ = reader.Number<Core::instance_id>();

                Exchange::INetworkControl::INetworkInfoIterator* _networkInfo{};
                ProxyStub::UnknownProxy* _networkInfoProxy__ = nullptr;
                if (_networkInfoInstanceId__ != 0) {
                    _networkInfoProxy__ = RPC::Administrator::Instance().ProxyInstance(channel, _networkInfoInstanceId__, false, _networkInfo);
                    ASSERT((_networkInfo != nullptr) && (_networkInfoProxy__ != nullptr));
                    if ((_networkInfo == nullptr) || (_networkInfoProxy__ == nullptr)) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }
                }

                uint32_t result = implementation->Network(static_cast<const string&>(_interface), static_cast<Exchange::INetworkControl::INetworkInfoIterator* const&>(_networkInfo));

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(result);

                if (_networkInfoProxy__ != nullptr) {
                    RPC::Administrator::Instance().Release(_networkInfoProxy__, message->Response());
                }

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(hresult);
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::INetworkControl::ID, 5, hresult);
            }
        },

        // (6) virtual uint32_t DNS(Exchange::INetworkControl::IStringIterator*&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const Exchange::INetworkControl* implementation = reinterpret_cast<const Exchange::INetworkControl*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::INetworkControl::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                Exchange::INetworkControl::IStringIterator* _dns{};

                uint32_t result = implementation->DNS(_dns);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(result);
                writer.Number<Core::instance_id>(RPC::instance_cast(_dns));

                RPC::Administrator::Instance().RegisterInterface(channel, _dns);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(hresult);
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::INetworkControl::ID, 6, hresult);
            }
        },

        // (7) virtual uint32_t DNS(Exchange::INetworkControl::IStringIterator* const&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                Exchange::INetworkControl* implementation = reinterpret_cast<Exchange::INetworkControl*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::INetworkControl::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (sizeof(Core::instance_id))) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                Core::instance_id _dnsInstanceId__ = reader.Number<Core::instance_id>();

                Exchange::INetworkControl::IStringIterator* _dns{};
                ProxyStub::UnknownProxy* _dnsProxy__ = nullptr;
                if (_dnsInstanceId__ != 0) {
                    _dnsProxy__ = RPC::Administrator::Instance().ProxyInstance(channel, _dnsInstanceId__, false, _dns);
                    ASSERT((_dns != nullptr) && (_dnsProxy__ != nullptr));
                    if ((_dns == nullptr) || (_dnsProxy__ == nullptr)) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }
                }

                uint32_t result = implementation->DNS(static_cast<Exchange::INetworkControl::IStringIterator* const&>(_dns));

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(result);

                if (_dnsProxy__ != nullptr) {
                    RPC::Administrator::Instance().Release(_dnsProxy__, message->Response());
                }

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(hresult);
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::INetworkControl::ID, 7, hresult);
            }
        },

        // (8) virtual uint32_t Up(const string&, bool&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const Exchange::INetworkControl* implementation = reinterpret_cast<const Exchange::INetworkControl*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::INetworkControl::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint16_t _interfacePeekedLen__ = reader.PeekNumber<uint16_t>();
                if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint16_t>()) + _interfacePeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const string _interface = reader.Text();

                bool _up{};

                uint32_t result = implementation->Up(static_cast<const string&>(_interface), _up);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(result);
                writer.Boolean(_up);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(hresult);
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::INetworkControl::ID, 8, hresult);
            }
        },

        // (9) virtual uint32_t Up(const string&, const bool) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                Exchange::INetworkControl* implementation = reinterpret_cast<Exchange::INetworkControl*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::INetworkControl::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint16_t _interfacePeekedLen__ = reader.PeekNumber<uint16_t>();
                if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint16_t>()) + _interfacePeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const string _interface = reader.Text();
                if (reader.Length() < (1)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const bool _up = reader.Boolean();

                uint32_t result = implementation->Up(static_cast<const string&>(_interface), _up);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(result);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(hresult);
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::INetworkControl::ID, 9, hresult);
            }
        },

        // (10) virtual uint32_t Flush(const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                Exchange::INetworkControl* implementation = reinterpret_cast<Exchange::INetworkControl*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::INetworkControl::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint16_t _interfacePeekedLen__ = reader.PeekNumber<uint16_t>();
                if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint16_t>()) + _interfacePeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const string _interface = reader.Text();

                uint32_t result = implementation->Flush(static_cast<const string&>(_interface));

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(result);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(hresult);
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::INetworkControl::ID, 10, hresult);
            }
        }
        , nullptr
    }; // ExchangeNetworkControlStubMethods

    //
    // Exchange::INetworkControl::INotification interface stub definitions
    //
    // Methods:
    //  (0) virtual void Update(const string&) = 0
    //

    static ProxyStub::MethodHandler ExchangeNetworkControlNotificationStubMethods[] = {
        // (0) virtual void Update(const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                Exchange::INetworkControl::INotification* implementation = reinterpret_cast<Exchange::INetworkControl::INotification*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::INetworkControl::INotification::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint16_t _interfaceNamePeekedLen__ = reader.PeekNumber<uint16_t>();
                if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint16_t>()) + _interfaceNamePeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const string _interfaceName = reader.Text();

                implementation->Update(static_cast<const string&>(_interfaceName));

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::INetworkControl::INotification::ID, 0, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        }
        , nullptr
    }; // ExchangeNetworkControlNotificationStubMethods

    // -----------------------------------------------------------------
    // PROXIES
    // -----------------------------------------------------------------

    //
    // RPC::IIteratorTypeInstance_4841f294117251fd interface proxy definitions
    //
    // Methods:
    //  (0) virtual bool Next(Exchange::INetworkControl::NetworkInfo&) = 0
    //  (1) virtual bool Previous(Exchange::INetworkControl::NetworkInfo&) = 0
    //  (2) virtual void Reset(const uint32_t) = 0
    //  (3) virtual bool IsValid() const = 0
    //  (4) virtual uint32_t Count() const = 0
    //  (5) virtual Exchange::INetworkControl::NetworkInfo Current() const = 0
    //

    class RPCIteratorTypeInstance_4841f294117251fdProxy final : public ProxyStub::UnknownProxyType<RPC::IIteratorType<Exchange::INetworkControl::NetworkInfo, Exchange::ID_NETWORKCONTROL_NETWORK_INFO_ITERATOR>> {
    public:
        RPCIteratorTypeInstance_4841f294117251fdProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        bool Next(Exchange::INetworkControl::NetworkInfo& _info) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            bool result{};

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (1)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    result = reader.Boolean();
                    if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    const uint16_t _info_addressPeekedLen__ = reader.PeekNumber<uint16_t>();
                    if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint16_t>()) + _info_addressPeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    _info.address = reader.Text();
                    if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    const uint16_t _info_defaultGatewayPeekedLen__ = reader.PeekNumber<uint16_t>();
                    if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint16_t>()) + _info_defaultGatewayPeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    _info.defaultGateway = reader.Text();
                    if (reader.Length() < (Core::RealSize<uint8_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    _info.mask = reader.Number<uint8_t>();
                    if (reader.Length() < (Core::RealSize<Exchange::INetworkControl::ModeType>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    _info.mode = reader.Number<Exchange::INetworkControl::ModeType>();

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", RPC::IIteratorType<Exchange::INetworkControl::NetworkInfo, Exchange::ID_NETWORKCONTROL_NETWORK_INFO_ITERATOR>::ID, 0, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }

            return (result);
        }

        bool Previous(Exchange::INetworkControl::NetworkInfo& _info) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            bool result{};

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (1)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    result = reader.Boolean();
                    if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    const uint16_t _info_addressPeekedLen__ = reader.PeekNumber<uint16_t>();
                    if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint16_t>()) + _info_addressPeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    _info.address = reader.Text();
                    if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    const uint16_t _info_defaultGatewayPeekedLen__ = reader.PeekNumber<uint16_t>();
                    if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint16_t>()) + _info_defaultGatewayPeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    _info.defaultGateway = reader.Text();
                    if (reader.Length() < (Core::RealSize<uint8_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    _info.mask = reader.Number<uint8_t>();
                    if (reader.Length() < (Core::RealSize<Exchange::INetworkControl::ModeType>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    _info.mode = reader.Number<Exchange::INetworkControl::ModeType>();

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", RPC::IIteratorType<Exchange::INetworkControl::NetworkInfo, Exchange::ID_NETWORKCONTROL_NETWORK_INFO_ITERATOR>::ID, 1, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }

            return (result);
        }

        void Reset(const uint32_t _position) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(2));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_position);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", RPC::IIteratorType<Exchange::INetworkControl::NetworkInfo, Exchange::ID_NETWORKCONTROL_NETWORK_INFO_ITERATOR>::ID, 2, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        }

        bool IsValid() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(3));

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
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", RPC::IIteratorType<Exchange::INetworkControl::NetworkInfo, Exchange::ID_NETWORKCONTROL_NETWORK_INFO_ITERATOR>::ID, 3, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }

            return (result);
        }

        uint32_t Count() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(4));

            uint32_t result{};

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    result = reader.Number<uint32_t>();

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", RPC::IIteratorType<Exchange::INetworkControl::NetworkInfo, Exchange::ID_NETWORKCONTROL_NETWORK_INFO_ITERATOR>::ID, 4, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }

            return (result);
        }

        Exchange::INetworkControl::NetworkInfo Current() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(5));

            Exchange::INetworkControl::NetworkInfo result{};

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    const uint16_t result_addressPeekedLen__ = reader.PeekNumber<uint16_t>();
                    if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint16_t>()) + result_addressPeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    result.address = reader.Text();
                    if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    const uint16_t result_defaultGatewayPeekedLen__ = reader.PeekNumber<uint16_t>();
                    if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint16_t>()) + result_defaultGatewayPeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    result.defaultGateway = reader.Text();
                    if (reader.Length() < (Core::RealSize<uint8_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    result.mask = reader.Number<uint8_t>();
                    if (reader.Length() < (Core::RealSize<Exchange::INetworkControl::ModeType>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    result.mode = reader.Number<Exchange::INetworkControl::ModeType>();

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", RPC::IIteratorType<Exchange::INetworkControl::NetworkInfo, Exchange::ID_NETWORKCONTROL_NETWORK_INFO_ITERATOR>::ID, 5, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }

            return (result);
        }

    }; // class RPCIteratorTypeInstance_4841f294117251fdProxy

    //
    // RPC::IIteratorTypeInstance_b3acff3685df4032 interface proxy definitions
    //
    // Methods:
    //  (0) virtual bool Next(string&) = 0
    //  (1) virtual bool Previous(string&) = 0
    //  (2) virtual void Reset(const uint32_t) = 0
    //  (3) virtual bool IsValid() const = 0
    //  (4) virtual uint32_t Count() const = 0
    //  (5) virtual string Current() const = 0
    //

    class RPCIteratorTypeInstance_b3acff3685df4032Proxy final : public ProxyStub::UnknownProxyType<RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>> {
    public:
        RPCIteratorTypeInstance_b3acff3685df4032Proxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        bool Next(string& _info) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            bool result{};

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (1)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    result = reader.Boolean();
                    if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    const uint16_t _infoPeekedLen__ = reader.PeekNumber<uint16_t>();
                    if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint16_t>()) + _infoPeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    _info = reader.Text();

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>::ID, 0, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }

            return (result);
        }

        bool Previous(string& _info) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            bool result{};

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (1)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    result = reader.Boolean();
                    if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    const uint16_t _infoPeekedLen__ = reader.PeekNumber<uint16_t>();
                    if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint16_t>()) + _infoPeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    _info = reader.Text();

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>::ID, 1, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }

            return (result);
        }

        void Reset(const uint32_t _position) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(2));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_position);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>::ID, 2, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        }

        bool IsValid() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(3));

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
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>::ID, 3, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }

            return (result);
        }

        uint32_t Count() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(4));

            uint32_t result{};

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    result = reader.Number<uint32_t>();

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>::ID, 4, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }

            return (result);
        }

        string Current() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(5));

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
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>::ID, 5, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }

            return (result);
        }

    }; // class RPCIteratorTypeInstance_b3acff3685df4032Proxy

    //
    // Exchange::INetworkControl interface proxy definitions
    //
    // Methods:
    //  (0) virtual uint32_t Register(Exchange::INetworkControl::INotification*) = 0
    //  (1) virtual uint32_t Unregister(Exchange::INetworkControl::INotification*) = 0
    //  (2) virtual uint32_t Interfaces(Exchange::INetworkControl::IStringIterator*&) const = 0
    //  (3) virtual uint32_t Status(const string&, Exchange::INetworkControl::StatusType&) const = 0
    //  (4) virtual uint32_t Network(const string&, Exchange::INetworkControl::INetworkInfoIterator*&) const = 0
    //  (5) virtual uint32_t Network(const string&, Exchange::INetworkControl::INetworkInfoIterator* const&) = 0
    //  (6) virtual uint32_t DNS(Exchange::INetworkControl::IStringIterator*&) const = 0
    //  (7) virtual uint32_t DNS(Exchange::INetworkControl::IStringIterator* const&) = 0
    //  (8) virtual uint32_t Up(const string&, bool&) const = 0
    //  (9) virtual uint32_t Up(const string&, const bool) = 0
    //  (10) virtual uint32_t Flush(const string&) = 0
    //

    class ExchangeNetworkControlProxy final : public ProxyStub::UnknownProxyType<Exchange::INetworkControl> {
    public:
        ExchangeNetworkControlProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        uint32_t Register(Exchange::INetworkControl::INotification* _sink) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_sink));

            const RPC::InstanceRecord passedInstances[] = { { RPC::instance_cast(_sink), Exchange::INetworkControl::INotification::ID }, { 0, 0 } };
            static_cast<const ProxyStub::UnknownProxy&>(*this).Channel()->CustomData(passedInstances);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    hresult = reader.Number<uint32_t>();

                    const uint32_t completeResult__ = _Complete(reader);
                    if (completeResult__ != Core::ERROR_NONE) { return (completeResult__); }

                    return (hresult);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::INetworkControl::ID, 0, hresult);
            }

            static_cast<const ProxyStub::UnknownProxy&>(*this).Channel()->CustomData(nullptr);

            return (hresult);
        }

        uint32_t Unregister(Exchange::INetworkControl::INotification* _sink) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_sink));

            const RPC::InstanceRecord passedInstances[] = { { RPC::instance_cast(_sink), Exchange::INetworkControl::INotification::ID }, { 0, 0 } };
            static_cast<const ProxyStub::UnknownProxy&>(*this).Channel()->CustomData(passedInstances);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    hresult = reader.Number<uint32_t>();

                    const uint32_t completeResult__ = _Complete(reader);
                    if (completeResult__ != Core::ERROR_NONE) { return (completeResult__); }

                    return (hresult);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::INetworkControl::ID, 1, hresult);
            }

            static_cast<const ProxyStub::UnknownProxy&>(*this).Channel()->CustomData(nullptr);

            return (hresult);
        }

        uint32_t Interfaces(Exchange::INetworkControl::IStringIterator*& _interfaces) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(2));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    hresult = reader.Number<uint32_t>();
                    if ((hresult & COM_ERROR) == 0) {
                        _interfaces = reinterpret_cast<Exchange::INetworkControl::IStringIterator*>(static_cast<const ProxyStub::UnknownProxy&>(*this).Interface(reader.Number<Core::instance_id>(), Exchange::INetworkControl::IStringIterator::ID));
                    }

                    return (hresult);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::INetworkControl::ID, 2, hresult);
            }

            return (hresult);
        }

        uint32_t Status(const string& _interface, Exchange::INetworkControl::StatusType& _status) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(3));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_interface);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    hresult = reader.Number<uint32_t>();
                    if ((hresult & COM_ERROR) == 0) {
                        if (reader.Length() < (Core::RealSize<Exchange::INetworkControl::StatusType>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                        _status = reader.Number<Exchange::INetworkControl::StatusType>();
                    }

                    return (hresult);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::INetworkControl::ID, 3, hresult);
            }

            return (hresult);
        }

        uint32_t Network(const string& _interface, Exchange::INetworkControl::INetworkInfoIterator*& _networkInfo) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(4));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_interface);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    hresult = reader.Number<uint32_t>();
                    if ((hresult & COM_ERROR) == 0) {
                        _networkInfo = reinterpret_cast<Exchange::INetworkControl::INetworkInfoIterator*>(static_cast<const ProxyStub::UnknownProxy&>(*this).Interface(reader.Number<Core::instance_id>(), Exchange::INetworkControl::INetworkInfoIterator::ID));
                    }

                    return (hresult);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::INetworkControl::ID, 4, hresult);
            }

            return (hresult);
        }

        uint32_t Network(const string& _interface, Exchange::INetworkControl::INetworkInfoIterator* const& _networkInfo) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(5));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_interface);
            writer.Number<Core::instance_id>(RPC::instance_cast(_networkInfo));

            const RPC::InstanceRecord passedInstances[] = { { RPC::instance_cast(_networkInfo), Exchange::INetworkControl::INetworkInfoIterator::ID }, { 0, 0 } };
            static_cast<const ProxyStub::UnknownProxy&>(*this).Channel()->CustomData(passedInstances);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    hresult = reader.Number<uint32_t>();

                    const uint32_t completeResult__ = _Complete(reader);
                    if (completeResult__ != Core::ERROR_NONE) { return (completeResult__); }

                    return (hresult);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::INetworkControl::ID, 5, hresult);
            }

            static_cast<const ProxyStub::UnknownProxy&>(*this).Channel()->CustomData(nullptr);

            return (hresult);
        }

        uint32_t DNS(Exchange::INetworkControl::IStringIterator*& _dns) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(6));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    hresult = reader.Number<uint32_t>();
                    if ((hresult & COM_ERROR) == 0) {
                        _dns = reinterpret_cast<Exchange::INetworkControl::IStringIterator*>(static_cast<const ProxyStub::UnknownProxy&>(*this).Interface(reader.Number<Core::instance_id>(), Exchange::INetworkControl::IStringIterator::ID));
                    }

                    return (hresult);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::INetworkControl::ID, 6, hresult);
            }

            return (hresult);
        }

        uint32_t DNS(Exchange::INetworkControl::IStringIterator* const& _dns) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(7));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_dns));

            const RPC::InstanceRecord passedInstances[] = { { RPC::instance_cast(_dns), Exchange::INetworkControl::IStringIterator::ID }, { 0, 0 } };
            static_cast<const ProxyStub::UnknownProxy&>(*this).Channel()->CustomData(passedInstances);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    hresult = reader.Number<uint32_t>();

                    const uint32_t completeResult__ = _Complete(reader);
                    if (completeResult__ != Core::ERROR_NONE) { return (completeResult__); }

                    return (hresult);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::INetworkControl::ID, 7, hresult);
            }

            static_cast<const ProxyStub::UnknownProxy&>(*this).Channel()->CustomData(nullptr);

            return (hresult);
        }

        uint32_t Up(const string& _interface, bool& _up) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(8));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_interface);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    hresult = reader.Number<uint32_t>();
                    if ((hresult & COM_ERROR) == 0) {
                        if (reader.Length() < (1)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                        _up = reader.Boolean();
                    }

                    return (hresult);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::INetworkControl::ID, 8, hresult);
            }

            return (hresult);
        }

        uint32_t Up(const string& _interface, const bool _up) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(9));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_interface);
            writer.Boolean(_up);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    hresult = reader.Number<uint32_t>();

                    return (hresult);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::INetworkControl::ID, 9, hresult);
            }

            return (hresult);
        }

        uint32_t Flush(const string& _interface) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(10));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_interface);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    hresult = reader.Number<uint32_t>();

                    return (hresult);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::INetworkControl::ID, 10, hresult);
            }

            return (hresult);
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

    }; // class ExchangeNetworkControlProxy

    //
    // Exchange::INetworkControl::INotification interface proxy definitions
    //
    // Methods:
    //  (0) virtual void Update(const string&) = 0
    //

    class ExchangeNetworkControlNotificationProxy final : public ProxyStub::UnknownProxyType<Exchange::INetworkControl::INotification> {
    public:
        ExchangeNetworkControlNotificationProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        void Update(const string& _interfaceName) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_interfaceName);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::INetworkControl::INotification::ID, 0, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        }

    }; // class ExchangeNetworkControlNotificationProxy

    POP_WARNING()
    POP_WARNING()

    // -----------------------------------------------------------------
    // REGISTRATION
    // -----------------------------------------------------------------
    namespace {

        typedef ProxyStub::UnknownStubType<RPC::IIteratorType<Exchange::INetworkControl::NetworkInfo, Exchange::ID_NETWORKCONTROL_NETWORK_INFO_ITERATOR>, RPCIteratorTypeInstance_4841f294117251fdStubMethods> RPCIteratorTypeInstance_4841f294117251fdStub;
        typedef ProxyStub::UnknownStubType<RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>, RPCIteratorTypeInstance_b3acff3685df4032StubMethods> RPCIteratorTypeInstance_b3acff3685df4032Stub;
        typedef ProxyStub::UnknownStubType<Exchange::INetworkControl, ExchangeNetworkControlStubMethods> ExchangeNetworkControlStub;
        typedef ProxyStub::UnknownStubType<Exchange::INetworkControl::INotification, ExchangeNetworkControlNotificationStubMethods> ExchangeNetworkControlNotificationStub;

        static class Instantiation {
        public:
            Instantiation()
            {
                const RPC::SecureProxyStubType security = static_cast<RPC::SecureProxyStubType>(static_cast<std::underlying_type<RPC::SecureProxyStubType>::type>(RPC::SecureProxyStubType::PROXYSTUBS_SECURITY_SECURE) | static_cast<std::underlying_type<RPC::SecureProxyStubType>::type>(RPC::SecureProxyStubType::PROXYSTUBS_SECURITY_COHERENT));

                RPC::Administrator::Instance().Announce<RPC::IIteratorType<Exchange::INetworkControl::NetworkInfo, Exchange::ID_NETWORKCONTROL_NETWORK_INFO_ITERATOR>, RPCIteratorTypeInstance_4841f294117251fdProxy, RPCIteratorTypeInstance_4841f294117251fdStub>(security);
                RPC::Administrator::Instance().Announce<RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>, RPCIteratorTypeInstance_b3acff3685df4032Proxy, RPCIteratorTypeInstance_b3acff3685df4032Stub>(security);
                RPC::Administrator::Instance().Announce<Exchange::INetworkControl, ExchangeNetworkControlProxy, ExchangeNetworkControlStub>(security);
                RPC::Administrator::Instance().Announce<Exchange::INetworkControl::INotification, ExchangeNetworkControlNotificationProxy, ExchangeNetworkControlNotificationStub>(security);
            }
            ~Instantiation()
            {
                RPC::Administrator::Instance().Recall<RPC::IIteratorType<Exchange::INetworkControl::NetworkInfo, Exchange::ID_NETWORKCONTROL_NETWORK_INFO_ITERATOR>>();
                RPC::Administrator::Instance().Recall<RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>>();
                RPC::Administrator::Instance().Recall<Exchange::INetworkControl>();
                RPC::Administrator::Instance().Recall<Exchange::INetworkControl::INotification>();
            }
        } ProxyStubRegistration;

    } // namespace

} // namespace ProxyStubs

}
