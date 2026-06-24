//
// generated automatically from "IDNSServer.h"
//
// implements COM-RPC proxy stubs for:
//   - class Exchange::IDNSServer
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
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IDNSServer* implementation = reinterpret_cast<Exchange::IDNSServer*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _designator = reader.Text();
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
        },

        // (1) virtual Core::hresult CountByType(const string&, const Exchange::IDNSServer::Record::type, uint8_t&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IDNSServer* implementation = reinterpret_cast<Exchange::IDNSServer*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _designator = reader.Text();
            const Exchange::IDNSServer::Record::type _kind = reader.Number<Exchange::IDNSServer::Record::type>();

            uint8_t _index{};

            Core::hresult result = implementation->CountByType(static_cast<const string&>(_designator), _kind, _index);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
            writer.Number<uint8_t>(_index);
        },

        // (2) virtual Core::hresult FindByType(const string&, const Exchange::IDNSServer::Record::type, const uint8_t, Exchange::IDNSServer::Record&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IDNSServer* implementation = reinterpret_cast<Exchange::IDNSServer*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _designator = reader.Text();
            const Exchange::IDNSServer::Record::type _kind = reader.Number<Exchange::IDNSServer::Record::type>();
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
        },

        // (3) virtual Core::hresult Add(const Exchange::IDNSServer::Record&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IDNSServer* implementation = reinterpret_cast<Exchange::IDNSServer*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            Exchange::IDNSServer::Record _entry{};
            _entry.Type = reader.Number<Exchange::IDNSServer::Record::type>();
            _entry.Key = reader.Text();
            _entry.Value = reader.Text();
            _entry.TTL = reader.Number<uint32_t>();
            _entry.Priority = reader.Number<uint8_t>();

            Core::hresult result = implementation->Add(static_cast<const Exchange::IDNSServer::Record&>(_entry));

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
        },

        // (4) virtual Core::hresult Remove(const Exchange::IDNSServer::Record&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IDNSServer* implementation = reinterpret_cast<Exchange::IDNSServer*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            Exchange::IDNSServer::Record _record{};
            _record.Type = reader.Number<Exchange::IDNSServer::Record::type>();
            _record.Key = reader.Text();
            _record.Value = reader.Text();
            _record.TTL = reader.Number<uint32_t>();
            _record.Priority = reader.Number<uint8_t>();

            Core::hresult result = implementation->Remove(static_cast<const Exchange::IDNSServer::Record&>(_record));

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
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
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
                _entry.Type = reader.Number<Exchange::IDNSServer::Record::type>();
                _entry.Key = reader.Text();
                _entry.Value = reader.Text();
                _entry.TTL = reader.Number<uint32_t>();
                _entry.Priority = reader.Number<uint8_t>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
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
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
                _index = reader.Number<uint8_t>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
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
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
                _entry.Type = reader.Number<Exchange::IDNSServer::Record::type>();
                _entry.Key = reader.Text();
                _entry.Value = reader.Text();
                _entry.TTL = reader.Number<uint32_t>();
                _entry.Priority = reader.Number<uint8_t>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
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
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
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
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
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
                RPC::Administrator::Instance().Announce<Exchange::IDNSServer, ExchangeDNSServerProxy, ExchangeDNSServerStub>();
            }
            ~Instantiation()
            {
                RPC::Administrator::Instance().Recall<Exchange::IDNSServer>();
            }
        } ProxyStubRegistration;

    } // namespace

} // namespace ProxyStubs

}
