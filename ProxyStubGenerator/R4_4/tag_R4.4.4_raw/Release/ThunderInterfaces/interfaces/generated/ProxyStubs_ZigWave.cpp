//
// generated automatically from "IZigWave.h"
//
// implements COM-RPC proxy stubs for:
//   - class Exchange::IZigWave
//

#include "Module.h"
#include "IZigWave.h"

#include <com/com.h>

namespace WPEFramework {

namespace ProxyStubs {

    PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    // -----------------------------------------------------------------
    // STUBS
    // -----------------------------------------------------------------

    //
    // Exchange::IZigWave interface stub definitions
    //
    // Methods:
    //  (0) virtual uint32_t Permutable(const uint32_t, bool&) const = 0
    //  (1) virtual uint32_t Permutable(const uint32_t, const bool) = 0
    //  (2) virtual uint32_t Device(const uint32_t, string&) const = 0
    //  (3) virtual uint32_t Devices(RPC::IValueIterator*&) const = 0
    //  (4) virtual uint32_t Bind(const uint32_t, const uint32_t) = 0
    //  (5) virtual uint32_t Unbind(const uint32_t, const uint32_t) = 0
    //

    ProxyStub::MethodHandler ExchangeZigWaveStubMethods[] = {
        // (0) virtual uint32_t Permutable(const uint32_t, bool&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IZigWave* implementation = reinterpret_cast<const Exchange::IZigWave*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint32_t _address = reader.Number<uint32_t>();

            bool _enabled{};

            uint32_t result = implementation->Permutable(_address, _enabled);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Boolean(_enabled);
        },

        // (1) virtual uint32_t Permutable(const uint32_t, const bool) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IZigWave* implementation = reinterpret_cast<Exchange::IZigWave*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint32_t _address = reader.Number<uint32_t>();
            const bool _enabled = reader.Boolean();

            uint32_t result = implementation->Permutable(_address, _enabled);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (2) virtual uint32_t Device(const uint32_t, string&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IZigWave* implementation = reinterpret_cast<const Exchange::IZigWave*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint32_t _id = reader.Number<uint32_t>();

            string _metadata{};

            uint32_t result = implementation->Device(_id, _metadata);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Text(_metadata);
        },

        // (3) virtual uint32_t Devices(RPC::IValueIterator*&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IZigWave* implementation = reinterpret_cast<const Exchange::IZigWave*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::IValueIterator* _devices{};

            uint32_t result = implementation->Devices(_devices);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Number<Core::instance_id>(RPC::instance_cast(_devices));

            RPC::Administrator::Instance().RegisterInterface(channel, _devices);
        },

        // (4) virtual uint32_t Bind(const uint32_t, const uint32_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IZigWave* implementation = reinterpret_cast<Exchange::IZigWave*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint32_t _source = reader.Number<uint32_t>();
            const uint32_t _destination = reader.Number<uint32_t>();

            uint32_t result = implementation->Bind(_source, _destination);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (5) virtual uint32_t Unbind(const uint32_t, const uint32_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IZigWave* implementation = reinterpret_cast<Exchange::IZigWave*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint32_t _source = reader.Number<uint32_t>();
            const uint32_t _destination = reader.Number<uint32_t>();

            uint32_t result = implementation->Unbind(_source, _destination);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        }
        , nullptr
    }; // ExchangeZigWaveStubMethods

    // -----------------------------------------------------------------
    // PROXIES
    // -----------------------------------------------------------------

    //
    // Exchange::IZigWave interface proxy definitions
    //
    // Methods:
    //  (0) virtual uint32_t Permutable(const uint32_t, bool&) const = 0
    //  (1) virtual uint32_t Permutable(const uint32_t, const bool) = 0
    //  (2) virtual uint32_t Device(const uint32_t, string&) const = 0
    //  (3) virtual uint32_t Devices(RPC::IValueIterator*&) const = 0
    //  (4) virtual uint32_t Bind(const uint32_t, const uint32_t) = 0
    //  (5) virtual uint32_t Unbind(const uint32_t, const uint32_t) = 0
    //

    class ExchangeZigWaveProxy final : public ProxyStub::UnknownProxyType<Exchange::IZigWave> {
    public:
        ExchangeZigWaveProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
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

        uint32_t Permutable(const uint32_t _address, bool& _enabled) const override
        {
            IPCMessage message(BaseClass::Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_address);

            Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
                if ((hresult & COM_ERROR) == 0) {
                    _enabled = reader.Boolean();
                }
            } else {
                hresult |= COM_ERROR;
            }

            return (hresult);
        }

        uint32_t Permutable(const uint32_t _address, const bool _enabled) override
        {
            IPCMessage message(BaseClass::Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_address);
            writer.Boolean(_enabled);

            Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
            } else {
                hresult |= COM_ERROR;
            }

            return (hresult);
        }

        uint32_t Device(const uint32_t _id, string& _metadata) const override
        {
            IPCMessage message(BaseClass::Message(2));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_id);

            Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
                if ((hresult & COM_ERROR) == 0) {
                    _metadata = reader.Text();
                }
            } else {
                hresult |= COM_ERROR;
            }

            return (hresult);
        }

        uint32_t Devices(RPC::IValueIterator*& _devices) const override
        {
            IPCMessage message(BaseClass::Message(3));

            Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
                if ((hresult & COM_ERROR) == 0) {
                    _devices = reinterpret_cast<RPC::IValueIterator*>(Interface(reader.Number<Core::instance_id>(), RPC::IValueIterator::ID));
                }
            } else {
                hresult |= COM_ERROR;
            }

            return (hresult);
        }

        uint32_t Bind(const uint32_t _source, const uint32_t _destination) override
        {
            IPCMessage message(BaseClass::Message(4));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_source);
            writer.Number<uint32_t>(_destination);

            Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
            } else {
                hresult |= COM_ERROR;
            }

            return (hresult);
        }

        uint32_t Unbind(const uint32_t _source, const uint32_t _destination) override
        {
            IPCMessage message(BaseClass::Message(5));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_source);
            writer.Number<uint32_t>(_destination);

            Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
            } else {
                hresult |= COM_ERROR;
            }

            return (hresult);
        }

    }; // class ExchangeZigWaveProxy

    POP_WARNING()
    POP_WARNING()

    // -----------------------------------------------------------------
    // REGISTRATION
    // -----------------------------------------------------------------

    namespace {

        typedef ProxyStub::UnknownStubType<Exchange::IZigWave, ExchangeZigWaveStubMethods> ExchangeZigWaveStub;

        static class Instantiation {
        public:
            Instantiation()
            {
                RPC::Administrator::Instance().Announce<Exchange::IZigWave, ExchangeZigWaveProxy, ExchangeZigWaveStub>();
            }
            ~Instantiation()
            {
                RPC::Administrator::Instance().Recall<Exchange::IZigWave>();
            }
        } ProxyStubRegistration;

    } // namespace

} // namespace ProxyStubs

}
