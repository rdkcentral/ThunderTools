//
// generated automatically from "IPerformance.h"
//
// implements COM-RPC proxy stubs for:
//   - class Exchange::IPerformance
//

#include "Module.h"
#include "IPerformance.h"

#include <com/com.h>

namespace Thunder {

namespace ProxyStubs {

    PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    // -----------------------------------------------------------------
    // STUBS
    // -----------------------------------------------------------------

    //
    // Exchange::IPerformance interface stub definitions
    //
    // Methods:
    //  (0) virtual uint32_t Send(const uint16_t, const uint8_t*) = 0
    //  (1) virtual uint32_t Receive(uint16_t&, uint8_t*) const = 0
    //  (2) virtual uint32_t Exchange(uint16_t&, uint8_t*, const uint16_t) = 0
    //

    static ProxyStub::MethodHandler ExchangePerformanceStubMethods[] = {
        // (0) virtual uint32_t Send(const uint16_t, const uint8_t*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IPerformance* implementation = reinterpret_cast<Exchange::IPerformance*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint8_t* _buffer{};
            const uint16_t _sendSize = reader.LockBuffer<uint16_t>(_buffer);
            reader.UnlockBuffer(_sendSize);

            uint32_t result = implementation->Send(_sendSize, _buffer);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (1) virtual uint32_t Receive(uint16_t&, uint8_t*) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IPerformance* implementation = reinterpret_cast<const Exchange::IPerformance*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            uint16_t _bufferSize = reader.Number<uint16_t>();

            uint8_t* _buffer{};

            if (_bufferSize != 0) {
                _buffer = static_cast<uint8_t*>(ALLOCA(_bufferSize * sizeof(uint8_t)));
                ASSERT(_buffer != nullptr);
            }

            uint32_t result = implementation->Receive(_bufferSize, _buffer);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Buffer<uint16_t>((_buffer == nullptr? 0 : _bufferSize), _buffer);
            writer.Number<uint16_t>(_bufferSize);
        },

        // (2) virtual uint32_t Exchange(uint16_t&, uint8_t*, const uint16_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IPerformance* implementation = reinterpret_cast<Exchange::IPerformance*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            uint8_t* _buffer{};
            uint16_t _bufferSize = reader.LockBuffer<uint16_t>(const_cast<const uint8_t*&>(_buffer));
            reader.UnlockBuffer(_bufferSize);
            const uint16_t _maxBufferSize = reader.Number<uint16_t>();

            if (_maxBufferSize != 0) {
                if (_maxBufferSize > _bufferSize) {
                    void* tempBuffer{};

                    tempBuffer = static_cast<uint8_t*>(ALLOCA(_maxBufferSize * sizeof(uint8_t)));
                    ASSERT(tempBuffer != nullptr);

                    if (tempBuffer != nullptr) {
                        ::memcpy(tempBuffer, _buffer, _bufferSize);
                    }

                    _buffer = static_cast<uint8_t*>(tempBuffer);
                }
            }

            uint32_t result = implementation->Exchange(_bufferSize, _buffer, _maxBufferSize);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Buffer<uint16_t>(_bufferSize, _buffer);
        }
        , nullptr
    }; // ExchangePerformanceStubMethods

    // -----------------------------------------------------------------
    // PROXIES
    // -----------------------------------------------------------------

    //
    // Exchange::IPerformance interface proxy definitions
    //
    // Methods:
    //  (0) virtual uint32_t Send(const uint16_t, const uint8_t*) = 0
    //  (1) virtual uint32_t Receive(uint16_t&, uint8_t*) const = 0
    //  (2) virtual uint32_t Exchange(uint16_t&, uint8_t*, const uint16_t) = 0
    //

    class ExchangePerformanceProxy final : public ProxyStub::UnknownProxyType<Exchange::IPerformance> {
    public:
        ExchangePerformanceProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        uint32_t Send(const uint16_t _sendSize, const uint8_t* _buffer) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Buffer<uint16_t>(_sendSize, _buffer);

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

        uint32_t Receive(uint16_t& _bufferSize, uint8_t* _buffer) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint16_t>(_bufferSize);

            uint32_t result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Number<uint32_t>();
                reader.Buffer<uint16_t>(_bufferSize, _buffer);
                _bufferSize = reader.Number<uint16_t>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        uint32_t Exchange(uint16_t& _bufferSize, uint8_t* _buffer, const uint16_t _maxBufferSize) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(2));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Buffer<uint16_t>(_bufferSize, _buffer);
            writer.Number<uint16_t>(_maxBufferSize);

            uint32_t result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Number<uint32_t>();
                _bufferSize = reader.Buffer<uint16_t>(_maxBufferSize, _buffer);
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

    }; // class ExchangePerformanceProxy

    POP_WARNING()
    POP_WARNING()

    // -----------------------------------------------------------------
    // REGISTRATION
    // -----------------------------------------------------------------
    namespace {

        typedef ProxyStub::UnknownStubType<Exchange::IPerformance, ExchangePerformanceStubMethods> ExchangePerformanceStub;

        static class Instantiation {
        public:
            Instantiation()
            {
                RPC::Administrator::Instance().Announce<Exchange::IPerformance, ExchangePerformanceProxy, ExchangePerformanceStub>();
            }
            ~Instantiation()
            {
                RPC::Administrator::Instance().Recall<Exchange::IPerformance>();
            }
        } ProxyStubRegistration;

    } // namespace

} // namespace ProxyStubs

}
