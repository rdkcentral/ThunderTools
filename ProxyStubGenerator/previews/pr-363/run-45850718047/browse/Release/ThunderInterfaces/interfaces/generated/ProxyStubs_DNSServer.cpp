//
// generated automatically from "IDNSServer.h"
//
// implements COM-RPC proxy stubs for:
//   - class Exchange::IDNSServer
//
// secure code enabled:
//   - instance verification enabled
//   - range verification enabled
//   - frame coherency verification enabled
//

#include "Module.h"
#include "IDNSServer.h"

#include <com/com.h>

namespace Thunder {

namespace ProxyStubs {

    PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    // -----------------------------------------------------------------
    // STUBS
    // -----------------------------------------------------------------

    //
    // Exchange::IDNSServer interface stub definitions
    //
    // Methods:
    //  (0) virtual Core::hresult FindByKey(const string&, const string&, Exchange::IDNSServer::Record&) = 0
    //  (1) virtual Core::hresult CountByType(const string&, const Exchange::IDNSServer::Record::type, uint8_t&) = 0
    //  (2) virtual Core::hresult FindByType(const string&, const Exchange::IDNSServer::Record::type, const uint8_t, Exchange::IDNSServer::Record&) = 0
    //  (3) virtual Core::hresult Add(const Exchange::IDNSServer::Record&) = 0
    //  (4) virtual Core::hresult Remove(const Exchange::IDNSServer::Record&) = 0
    //

    static ProxyStub::MethodHandler ExchangeDNSServerStubMethods[] = {
        // (0) virtual Core::hresult FindByKey(const string&, const string&, Exchange::IDNSServer::Record&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                Exchange::IDNSServer* implementation = reinterpret_cast<Exchange::IDNSServer*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::IDNSServer::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint16_t _designatorPeekedLen__ = reader.PeekNumber<uint16_t>();
                if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint16_t>()) + _designatorPeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const string _designator = reader.Text();
                if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint16_t _keyPeekedLen__ = reader.PeekNumber<uint16_t>();
                if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint16_t>()) + _keyPeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const string _key = reader.Text();

                Exchange::IDNSServer::Record _entry{};

                Core::hresult result = implementation->FindByKey(static_cast<const string&>(_designator), static_cast<const string&>(_key), _entry);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<Core::hresult>(result);
                writer.Number<Exchange::IDNSServer::Record::type>(_entry.Type);
                writer.Text(_entry.Key);
                writer.Text(_entry.Value);
                writer.Number<uint32_t>(_entry.TTL);
                writer.Number<uint8_t>(_entry.Priority);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(hresult);
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::IDNSServer::ID, 0, hresult);
            }
        },

        // (1) virtual Core::hresult CountByType(const string&, const Exchange::IDNSServer::Record::type, uint8_t&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                Exchange::IDNSServer* implementation = reinterpret_cast<Exchange::IDNSServer*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::IDNSServer::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint16_t _designatorPeekedLen__ = reader.PeekNumber<uint16_t>();
                if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint16_t>()) + _designatorPeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const string _designator = reader.Text();
                if (reader.Length() < (Core::RealSize<Exchange::IDNSServer::Record::type>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const Exchange::IDNSServer::Record::type _kind = reader.Number<Exchange::IDNSServer::Record::type>();

                uint8_t _index{};

                Core::hresult result = implementation->CountByType(static_cast<const string&>(_designator), _kind, _index);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<Core::hresult>(result);
                writer.Number<uint8_t>(_index);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(hresult);
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::IDNSServer::ID, 1, hresult);
            }
        },

        // (2) virtual Core::hresult FindByType(const string&, const Exchange::IDNSServer::Record::type, const uint8_t, Exchange::IDNSServer::Record&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                Exchange::IDNSServer* implementation = reinterpret_cast<Exchange::IDNSServer*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::IDNSServer::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint16_t _designatorPeekedLen__ = reader.PeekNumber<uint16_t>();
                if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint16_t>()) + _designatorPeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const string _designator = reader.Text();
                if (reader.Length() < (Core::RealSize<Exchange::IDNSServer::Record::type>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const Exchange::IDNSServer::Record::type _kind = reader.Number<Exchange::IDNSServer::Record::type>();
                if (reader.Length() < (Core::RealSize<uint8_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint8_t _index = reader.Number<uint8_t>();

                Exchange::IDNSServer::Record _entry{};

                Core::hresult result = implementation->FindByType(static_cast<const string&>(_designator), _kind, _index, _entry);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<Core::hresult>(result);
                writer.Number<Exchange::IDNSServer::Record::type>(_entry.Type);
                writer.Text(_entry.Key);
                writer.Text(_entry.Value);
                writer.Number<uint32_t>(_entry.TTL);
                writer.Number<uint8_t>(_entry.Priority);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(hresult);
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::IDNSServer::ID, 2, hresult);
            }
        },

        // (3) virtual Core::hresult Add(const Exchange::IDNSServer::Record&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                Exchange::IDNSServer* implementation = reinterpret_cast<Exchange::IDNSServer*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::IDNSServer::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                Exchange::IDNSServer::Record _entry{};
                if (reader.Length() < (Core::RealSize<Exchange::IDNSServer::Record::type>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                _entry.Type = reader.Number<Exchange::IDNSServer::Record::type>();
                if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint16_t _entry_KeyPeekedLen__ = reader.PeekNumber<uint16_t>();
                if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint16_t>()) + _entry_KeyPeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                _entry.Key = reader.Text();
                if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint16_t _entry_ValuePeekedLen__ = reader.PeekNumber<uint16_t>();
                if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint16_t>()) + _entry_ValuePeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                _entry.Value = reader.Text();
                if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                _entry.TTL = reader.Number<uint32_t>();
                if (reader.Length() < (Core::RealSize<uint8_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                _entry.Priority = reader.Number<uint8_t>();

                Core::hresult result = implementation->Add(static_cast<const Exchange::IDNSServer::Record&>(_entry));

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<Core::hresult>(result);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(hresult);
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::IDNSServer::ID, 3, hresult);
            }
        },

        // (4) virtual Core::hresult Remove(const Exchange::IDNSServer::Record&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                Exchange::IDNSServer* implementation = reinterpret_cast<Exchange::IDNSServer*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::IDNSServer::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                Exchange::IDNSServer::Record _record{};
                if (reader.Length() < (Core::RealSize<Exchange::IDNSServer::Record::type>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                _record.Type = reader.Number<Exchange::IDNSServer::Record::type>();
                if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint16_t _record_KeyPeekedLen__ = reader.PeekNumber<uint16_t>();
                if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint16_t>()) + _record_KeyPeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                _record.Key = reader.Text();
                if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint16_t _record_ValuePeekedLen__ = reader.PeekNumber<uint16_t>();
                if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint16_t>()) + _record_ValuePeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                _record.Value = reader.Text();
                if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                _record.TTL = reader.Number<uint32_t>();
                if (reader.Length() < (Core::RealSize<uint8_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                _record.Priority = reader.Number<uint8_t>();

                Core::hresult result = implementation->Remove(static_cast<const Exchange::IDNSServer::Record&>(_record));

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<Core::hresult>(result);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(hresult);
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::IDNSServer::ID, 4, hresult);
            }
        }
        , nullptr
    }; // ExchangeDNSServerStubMethods

    // -----------------------------------------------------------------
    // PROXIES
    // -----------------------------------------------------------------

    //
    // Exchange::IDNSServer interface proxy definitions
    //
    // Methods:
    //  (0) virtual Core::hresult FindByKey(const string&, const string&, Exchange::IDNSServer::Record&) = 0
    //  (1) virtual Core::hresult CountByType(const string&, const Exchange::IDNSServer::Record::type, uint8_t&) = 0
    //  (2) virtual Core::hresult FindByType(const string&, const Exchange::IDNSServer::Record::type, const uint8_t, Exchange::IDNSServer::Record&) = 0
    //  (3) virtual Core::hresult Add(const Exchange::IDNSServer::Record&) = 0
    //  (4) virtual Core::hresult Remove(const Exchange::IDNSServer::Record&) = 0
    //

    class ExchangeDNSServerProxy final : public ProxyStub::UnknownProxyType<Exchange::IDNSServer> {
    public:
        ExchangeDNSServerProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        Core::hresult FindByKey(const string& _designator, const string& _key, Exchange::IDNSServer::Record& _entry) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_designator);
            writer.Text(_key);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<Core::hresult>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    hresult = reader.Number<Core::hresult>();
                    if ((hresult & COM_ERROR) == 0) {
                        if (reader.Length() < (Core::RealSize<Exchange::IDNSServer::Record::type>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                        _entry.Type = reader.Number<Exchange::IDNSServer::Record::type>();
                        if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                        const uint16_t _entry_KeyPeekedLen__ = reader.PeekNumber<uint16_t>();
                        if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint16_t>()) + _entry_KeyPeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                        _entry.Key = reader.Text();
                        if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                        const uint16_t _entry_ValuePeekedLen__ = reader.PeekNumber<uint16_t>();
                        if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint16_t>()) + _entry_ValuePeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                        _entry.Value = reader.Text();
                        if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                        _entry.TTL = reader.Number<uint32_t>();
                        if (reader.Length() < (Core::RealSize<uint8_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                        _entry.Priority = reader.Number<uint8_t>();
                    }

                    return (hresult);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::IDNSServer::ID, 0, hresult);
            }

            return (hresult);
        }

        Core::hresult CountByType(const string& _designator, const Exchange::IDNSServer::Record::type _kind, uint8_t& _index) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_designator);
            writer.Number<Exchange::IDNSServer::Record::type>(_kind);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<Core::hresult>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    hresult = reader.Number<Core::hresult>();
                    if ((hresult & COM_ERROR) == 0) {
                        if (reader.Length() < (Core::RealSize<uint8_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                        _index = reader.Number<uint8_t>();
                    }

                    return (hresult);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::IDNSServer::ID, 1, hresult);
            }

            return (hresult);
        }

        Core::hresult FindByType(const string& _designator, const Exchange::IDNSServer::Record::type _kind, const uint8_t _index, Exchange::IDNSServer::Record& _entry) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(2));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_designator);
            writer.Number<Exchange::IDNSServer::Record::type>(_kind);
            writer.Number<uint8_t>(_index);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<Core::hresult>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    hresult = reader.Number<Core::hresult>();
                    if ((hresult & COM_ERROR) == 0) {
                        if (reader.Length() < (Core::RealSize<Exchange::IDNSServer::Record::type>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                        _entry.Type = reader.Number<Exchange::IDNSServer::Record::type>();
                        if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                        const uint16_t _entry_KeyPeekedLen__ = reader.PeekNumber<uint16_t>();
                        if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint16_t>()) + _entry_KeyPeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                        _entry.Key = reader.Text();
                        if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                        const uint16_t _entry_ValuePeekedLen__ = reader.PeekNumber<uint16_t>();
                        if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint16_t>()) + _entry_ValuePeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                        _entry.Value = reader.Text();
                        if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                        _entry.TTL = reader.Number<uint32_t>();
                        if (reader.Length() < (Core::RealSize<uint8_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                        _entry.Priority = reader.Number<uint8_t>();
                    }

                    return (hresult);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::IDNSServer::ID, 2, hresult);
            }

            return (hresult);
        }

        Core::hresult Add(const Exchange::IDNSServer::Record& _entry) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(3));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Exchange::IDNSServer::Record::type>(_entry.Type);
            writer.Text(_entry.Key);
            writer.Text(_entry.Value);
            writer.Number<uint32_t>(_entry.TTL);
            writer.Number<uint8_t>(_entry.Priority);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<Core::hresult>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    hresult = reader.Number<Core::hresult>();

                    return (hresult);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::IDNSServer::ID, 3, hresult);
            }

            return (hresult);
        }

        Core::hresult Remove(const Exchange::IDNSServer::Record& _record) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(4));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Exchange::IDNSServer::Record::type>(_record.Type);
            writer.Text(_record.Key);
            writer.Text(_record.Value);
            writer.Number<uint32_t>(_record.TTL);
            writer.Number<uint8_t>(_record.Priority);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<Core::hresult>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    hresult = reader.Number<Core::hresult>();

                    return (hresult);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::IDNSServer::ID, 4, hresult);
            }

            return (hresult);
        }

    }; // class ExchangeDNSServerProxy

    POP_WARNING()
    POP_WARNING()

    // -----------------------------------------------------------------
    // REGISTRATION
    // -----------------------------------------------------------------
    namespace {

        typedef ProxyStub::UnknownStubType<Exchange::IDNSServer, ExchangeDNSServerStubMethods> ExchangeDNSServerStub;

        static class Instantiation {
        public:
            Instantiation()
            {
                const RPC::SecureProxyStubType security = static_cast<RPC::SecureProxyStubType>(static_cast<std::underlying_type<RPC::SecureProxyStubType>::type>(RPC::SecureProxyStubType::PROXYSTUBS_SECURITY_SECURE) | static_cast<std::underlying_type<RPC::SecureProxyStubType>::type>(RPC::SecureProxyStubType::PROXYSTUBS_SECURITY_COHERENT));

                RPC::Administrator::Instance().Announce<Exchange::IDNSServer, ExchangeDNSServerProxy, ExchangeDNSServerStub>(security);
            }
            ~Instantiation()
            {
                RPC::Administrator::Instance().Recall<Exchange::IDNSServer>();
            }
        } ProxyStubRegistration;

    } // namespace

} // namespace ProxyStubs

}
