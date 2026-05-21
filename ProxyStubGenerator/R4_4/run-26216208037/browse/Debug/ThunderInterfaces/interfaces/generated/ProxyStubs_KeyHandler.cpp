//
// generated automatically from "IKeyHandler.h"
//
// implements COM-RPC proxy stubs for:
//   - class Exchange::IKeyHandler
//   - class Exchange::IWheelHandler
//   - class Exchange::IPointerHandler
//   - class Exchange::ITouchHandler
//   - class Exchange::IKeyProducer
//   - class Exchange::IWheelProducer
//   - class Exchange::IPointerProducer
//   - class Exchange::ITouchProducer
//

#include "Module.h"
#include "IKeyHandler.h"

#include <com/com.h>

namespace WPEFramework {

namespace ProxyStubs {

    PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    // -----------------------------------------------------------------
    // STUBS
    // -----------------------------------------------------------------

    //
    // Exchange::IKeyHandler interface stub definitions
    //
    // Methods:
    //  (0) virtual uint32_t KeyEvent(const bool, const uint32_t, const string&) = 0
    //  (1) virtual void ProducerEvent(const string&, const Exchange::ProducerEvents) = 0
    //  (2) virtual Exchange::IKeyProducer* Producer(const string&) = 0
    //

    ProxyStub::MethodHandler ExchangeKeyHandlerStubMethods[] = {
        // (0) virtual uint32_t KeyEvent(const bool, const uint32_t, const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IKeyHandler* implementation = reinterpret_cast<Exchange::IKeyHandler*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const bool _pressed = reader.Boolean();
            const uint32_t _code = reader.Number<uint32_t>();
            const string _table = reader.Text();

            uint32_t result = implementation->KeyEvent(_pressed, _code, static_cast<const string&>(_table));

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (1) virtual void ProducerEvent(const string&, const Exchange::ProducerEvents) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IKeyHandler* implementation = reinterpret_cast<Exchange::IKeyHandler*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _producerName = reader.Text();
            const Exchange::ProducerEvents _event = reader.Number<Exchange::ProducerEvents>();

            implementation->ProducerEvent(static_cast<const string&>(_producerName), _event);
        },

        // (2) virtual Exchange::IKeyProducer* Producer(const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IKeyHandler* implementation = reinterpret_cast<Exchange::IKeyHandler*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _name = reader.Text();

            Exchange::IKeyProducer* result = implementation->Producer(static_cast<const string&>(_name));

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(result));

            RPC::Administrator::Instance().RegisterInterface(channel, result);
        }
        , nullptr
    }; // ExchangeKeyHandlerStubMethods

    //
    // Exchange::IWheelHandler interface stub definitions
    //
    // Methods:
    //  (0) virtual uint32_t AxisEvent(const int16_t, const int16_t) = 0
    //  (1) virtual Exchange::IWheelProducer* WheelProducer(const string&) = 0
    //

    ProxyStub::MethodHandler ExchangeWheelHandlerStubMethods[] = {
        // (0) virtual uint32_t AxisEvent(const int16_t, const int16_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IWheelHandler* implementation = reinterpret_cast<Exchange::IWheelHandler*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const int16_t _x = reader.Number<int16_t>();
            const int16_t _y = reader.Number<int16_t>();

            uint32_t result = implementation->AxisEvent(_x, _y);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (1) virtual Exchange::IWheelProducer* WheelProducer(const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IWheelHandler* implementation = reinterpret_cast<Exchange::IWheelHandler*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _name = reader.Text();

            Exchange::IWheelProducer* result = implementation->WheelProducer(static_cast<const string&>(_name));

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(result));

            RPC::Administrator::Instance().RegisterInterface(channel, result);
        }
        , nullptr
    }; // ExchangeWheelHandlerStubMethods

    //
    // Exchange::IPointerHandler interface stub definitions
    //
    // Methods:
    //  (0) virtual uint32_t PointerMotionEvent(const int16_t, const int16_t) = 0
    //  (1) virtual uint32_t PointerButtonEvent(const bool, const uint8_t) = 0
    //  (2) virtual Exchange::IPointerProducer* PointerProducer(const string&) = 0
    //

    ProxyStub::MethodHandler ExchangePointerHandlerStubMethods[] = {
        // (0) virtual uint32_t PointerMotionEvent(const int16_t, const int16_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IPointerHandler* implementation = reinterpret_cast<Exchange::IPointerHandler*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const int16_t _x = reader.Number<int16_t>();
            const int16_t _y = reader.Number<int16_t>();

            uint32_t result = implementation->PointerMotionEvent(_x, _y);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (1) virtual uint32_t PointerButtonEvent(const bool, const uint8_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IPointerHandler* implementation = reinterpret_cast<Exchange::IPointerHandler*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const bool _pressed = reader.Boolean();
            const uint8_t _button = reader.Number<uint8_t>();

            uint32_t result = implementation->PointerButtonEvent(_pressed, _button);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (2) virtual Exchange::IPointerProducer* PointerProducer(const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IPointerHandler* implementation = reinterpret_cast<Exchange::IPointerHandler*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _name = reader.Text();

            Exchange::IPointerProducer* result = implementation->PointerProducer(static_cast<const string&>(_name));

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(result));

            RPC::Administrator::Instance().RegisterInterface(channel, result);
        }
        , nullptr
    }; // ExchangePointerHandlerStubMethods

    //
    // Exchange::ITouchHandler interface stub definitions
    //
    // Methods:
    //  (0) virtual uint32_t TouchEvent(const uint8_t, const Exchange::ITouchHandler::touchstate, const uint16_t, const uint16_t) = 0
    //  (1) virtual Exchange::ITouchProducer* TouchProducer(const string&) = 0
    //

    ProxyStub::MethodHandler ExchangeTouchHandlerStubMethods[] = {
        // (0) virtual uint32_t TouchEvent(const uint8_t, const Exchange::ITouchHandler::touchstate, const uint16_t, const uint16_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::ITouchHandler* implementation = reinterpret_cast<Exchange::ITouchHandler*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint8_t _index = reader.Number<uint8_t>();
            const Exchange::ITouchHandler::touchstate _state = reader.Number<Exchange::ITouchHandler::touchstate>();
            const uint16_t _x = reader.Number<uint16_t>();
            const uint16_t _y = reader.Number<uint16_t>();

            uint32_t result = implementation->TouchEvent(_index, _state, _x, _y);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (1) virtual Exchange::ITouchProducer* TouchProducer(const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::ITouchHandler* implementation = reinterpret_cast<Exchange::ITouchHandler*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _name = reader.Text();

            Exchange::ITouchProducer* result = implementation->TouchProducer(static_cast<const string&>(_name));

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(result));

            RPC::Administrator::Instance().RegisterInterface(channel, result);
        }
        , nullptr
    }; // ExchangeTouchHandlerStubMethods

    //
    // Exchange::IKeyProducer interface stub definitions
    //
    // Methods:
    //  (0) virtual string Name() const = 0
    //  (1) virtual uint32_t Callback(Exchange::IKeyHandler*) = 0
    //  (2) virtual uint32_t Error() const = 0
    //  (3) virtual string MetaData() const = 0
    //  (4) virtual void Configure(const string&) = 0
    //  (5) virtual bool Pair() = 0
    //  (6) virtual bool Unpair(string) = 0
    //

    ProxyStub::MethodHandler ExchangeKeyProducerStubMethods[] = {
        // (0) virtual string Name() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IKeyProducer* implementation = reinterpret_cast<const Exchange::IKeyProducer*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            string result = implementation->Name();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Text(result);
        },

        // (1) virtual uint32_t Callback(Exchange::IKeyHandler*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IKeyProducer* implementation = reinterpret_cast<Exchange::IKeyProducer*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const Core::instance_id callbackImplementation = reader.Number<Core::instance_id>();

            Exchange::IKeyHandler* _callback = nullptr;
            ProxyStub::UnknownProxy* callbackProxy = nullptr;
            if (callbackImplementation != 0) {
                callbackProxy = RPC::Administrator::Instance().ProxyInstance(channel, callbackImplementation, false, _callback);

                ASSERT((_callback != nullptr) && (callbackProxy != nullptr));
            }

            uint32_t result = implementation->Callback(_callback);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);

            if (callbackProxy != nullptr) {
                RPC::Administrator::Instance().Release(callbackProxy, message->Response());
            }
        },

        // (2) virtual uint32_t Error() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IKeyProducer* implementation = reinterpret_cast<const Exchange::IKeyProducer*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            uint32_t result = implementation->Error();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (3) virtual string MetaData() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IKeyProducer* implementation = reinterpret_cast<const Exchange::IKeyProducer*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            string result = implementation->MetaData();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Text(result);
        },

        // (4) virtual void Configure(const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IKeyProducer* implementation = reinterpret_cast<Exchange::IKeyProducer*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _settings = reader.Text();

            implementation->Configure(static_cast<const string&>(_settings));
        },

        // (5) virtual bool Pair() = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IKeyProducer* implementation = reinterpret_cast<Exchange::IKeyProducer*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            bool result = implementation->Pair();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Boolean(result);
        },

        // (6) virtual bool Unpair(string) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IKeyProducer* implementation = reinterpret_cast<Exchange::IKeyProducer*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            string _bindingId = reader.Text();

            bool result = implementation->Unpair(_bindingId);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Boolean(result);
        }
        , nullptr
    }; // ExchangeKeyProducerStubMethods

    //
    // Exchange::IWheelProducer interface stub definitions
    //
    // Methods:
    //  (0) virtual string Name() const = 0
    //  (1) virtual uint32_t Callback(Exchange::IWheelHandler*) = 0
    //  (2) virtual uint32_t Error() const = 0
    //  (3) virtual string MetaData() const = 0
    //  (4) virtual void Configure(const string&) = 0
    //

    ProxyStub::MethodHandler ExchangeWheelProducerStubMethods[] = {
        // (0) virtual string Name() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IWheelProducer* implementation = reinterpret_cast<const Exchange::IWheelProducer*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            string result = implementation->Name();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Text(result);
        },

        // (1) virtual uint32_t Callback(Exchange::IWheelHandler*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IWheelProducer* implementation = reinterpret_cast<Exchange::IWheelProducer*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const Core::instance_id callbackImplementation = reader.Number<Core::instance_id>();

            Exchange::IWheelHandler* _callback = nullptr;
            ProxyStub::UnknownProxy* callbackProxy = nullptr;
            if (callbackImplementation != 0) {
                callbackProxy = RPC::Administrator::Instance().ProxyInstance(channel, callbackImplementation, false, _callback);

                ASSERT((_callback != nullptr) && (callbackProxy != nullptr));
            }

            uint32_t result = implementation->Callback(_callback);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);

            if (callbackProxy != nullptr) {
                RPC::Administrator::Instance().Release(callbackProxy, message->Response());
            }
        },

        // (2) virtual uint32_t Error() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IWheelProducer* implementation = reinterpret_cast<const Exchange::IWheelProducer*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            uint32_t result = implementation->Error();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (3) virtual string MetaData() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IWheelProducer* implementation = reinterpret_cast<const Exchange::IWheelProducer*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            string result = implementation->MetaData();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Text(result);
        },

        // (4) virtual void Configure(const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IWheelProducer* implementation = reinterpret_cast<Exchange::IWheelProducer*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _settings = reader.Text();

            implementation->Configure(static_cast<const string&>(_settings));
        }
        , nullptr
    }; // ExchangeWheelProducerStubMethods

    //
    // Exchange::IPointerProducer interface stub definitions
    //
    // Methods:
    //  (0) virtual string Name() const = 0
    //  (1) virtual uint32_t Callback(Exchange::IPointerHandler*) = 0
    //  (2) virtual uint32_t Error() const = 0
    //  (3) virtual string MetaData() const = 0
    //  (4) virtual void Configure(const string&) = 0
    //

    ProxyStub::MethodHandler ExchangePointerProducerStubMethods[] = {
        // (0) virtual string Name() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IPointerProducer* implementation = reinterpret_cast<const Exchange::IPointerProducer*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            string result = implementation->Name();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Text(result);
        },

        // (1) virtual uint32_t Callback(Exchange::IPointerHandler*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IPointerProducer* implementation = reinterpret_cast<Exchange::IPointerProducer*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const Core::instance_id callbackImplementation = reader.Number<Core::instance_id>();

            Exchange::IPointerHandler* _callback = nullptr;
            ProxyStub::UnknownProxy* callbackProxy = nullptr;
            if (callbackImplementation != 0) {
                callbackProxy = RPC::Administrator::Instance().ProxyInstance(channel, callbackImplementation, false, _callback);

                ASSERT((_callback != nullptr) && (callbackProxy != nullptr));
            }

            uint32_t result = implementation->Callback(_callback);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);

            if (callbackProxy != nullptr) {
                RPC::Administrator::Instance().Release(callbackProxy, message->Response());
            }
        },

        // (2) virtual uint32_t Error() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IPointerProducer* implementation = reinterpret_cast<const Exchange::IPointerProducer*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            uint32_t result = implementation->Error();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (3) virtual string MetaData() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IPointerProducer* implementation = reinterpret_cast<const Exchange::IPointerProducer*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            string result = implementation->MetaData();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Text(result);
        },

        // (4) virtual void Configure(const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IPointerProducer* implementation = reinterpret_cast<Exchange::IPointerProducer*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _settings = reader.Text();

            implementation->Configure(static_cast<const string&>(_settings));
        }
        , nullptr
    }; // ExchangePointerProducerStubMethods

    //
    // Exchange::ITouchProducer interface stub definitions
    //
    // Methods:
    //  (0) virtual string Name() const = 0
    //  (1) virtual uint32_t Callback(Exchange::ITouchHandler*) = 0
    //  (2) virtual uint32_t Error() const = 0
    //  (3) virtual string MetaData() const = 0
    //  (4) virtual void Configure(const string&) = 0
    //

    ProxyStub::MethodHandler ExchangeTouchProducerStubMethods[] = {
        // (0) virtual string Name() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::ITouchProducer* implementation = reinterpret_cast<const Exchange::ITouchProducer*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            string result = implementation->Name();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Text(result);
        },

        // (1) virtual uint32_t Callback(Exchange::ITouchHandler*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::ITouchProducer* implementation = reinterpret_cast<Exchange::ITouchProducer*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const Core::instance_id callbackImplementation = reader.Number<Core::instance_id>();

            Exchange::ITouchHandler* _callback = nullptr;
            ProxyStub::UnknownProxy* callbackProxy = nullptr;
            if (callbackImplementation != 0) {
                callbackProxy = RPC::Administrator::Instance().ProxyInstance(channel, callbackImplementation, false, _callback);

                ASSERT((_callback != nullptr) && (callbackProxy != nullptr));
            }

            uint32_t result = implementation->Callback(_callback);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);

            if (callbackProxy != nullptr) {
                RPC::Administrator::Instance().Release(callbackProxy, message->Response());
            }
        },

        // (2) virtual uint32_t Error() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::ITouchProducer* implementation = reinterpret_cast<const Exchange::ITouchProducer*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            uint32_t result = implementation->Error();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (3) virtual string MetaData() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::ITouchProducer* implementation = reinterpret_cast<const Exchange::ITouchProducer*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            string result = implementation->MetaData();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Text(result);
        },

        // (4) virtual void Configure(const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::ITouchProducer* implementation = reinterpret_cast<Exchange::ITouchProducer*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _settings = reader.Text();

            implementation->Configure(static_cast<const string&>(_settings));
        }
        , nullptr
    }; // ExchangeTouchProducerStubMethods

    // -----------------------------------------------------------------
    // PROXIES
    // -----------------------------------------------------------------

    //
    // Exchange::IKeyHandler interface proxy definitions
    //
    // Methods:
    //  (0) virtual uint32_t KeyEvent(const bool, const uint32_t, const string&) = 0
    //  (1) virtual void ProducerEvent(const string&, const Exchange::ProducerEvents) = 0
    //  (2) virtual Exchange::IKeyProducer* Producer(const string&) = 0
    //

    class ExchangeKeyHandlerProxy final : public ProxyStub::UnknownProxyType<Exchange::IKeyHandler> {
    public:
        ExchangeKeyHandlerProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
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

        uint32_t KeyEvent(const bool _pressed, const uint32_t _code, const string& _table) override
        {
            IPCMessage message(BaseClass::Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Boolean(_pressed);
            writer.Number<uint32_t>(_code);
            writer.Text(static_cast<const string&>(_table));

            uint32_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint32_t>();

            return (result);
        }

        void ProducerEvent(const string& _producerName, const Exchange::ProducerEvents _event) override
        {
            IPCMessage message(BaseClass::Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const string&>(_producerName));
            writer.Number<Exchange::ProducerEvents>(_event);

            UnknownProxyType::Invoke(message);
        }

        Exchange::IKeyProducer* Producer(const string& _name) override
        {
            IPCMessage message(BaseClass::Message(2));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const string&>(_name));

            Exchange::IKeyProducer* result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reinterpret_cast<Exchange::IKeyProducer*>(Interface(reader.Number<Core::instance_id>(), Exchange::IKeyProducer::ID));

            return (result);
        }

    }; // class ExchangeKeyHandlerProxy

    //
    // Exchange::IWheelHandler interface proxy definitions
    //
    // Methods:
    //  (0) virtual uint32_t AxisEvent(const int16_t, const int16_t) = 0
    //  (1) virtual Exchange::IWheelProducer* WheelProducer(const string&) = 0
    //

    class ExchangeWheelHandlerProxy final : public ProxyStub::UnknownProxyType<Exchange::IWheelHandler> {
    public:
        ExchangeWheelHandlerProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
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

        uint32_t AxisEvent(const int16_t _x, const int16_t _y) override
        {
            IPCMessage message(BaseClass::Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<int16_t>(_x);
            writer.Number<int16_t>(_y);

            uint32_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint32_t>();

            return (result);
        }

        Exchange::IWheelProducer* WheelProducer(const string& _name) override
        {
            IPCMessage message(BaseClass::Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const string&>(_name));

            Exchange::IWheelProducer* result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reinterpret_cast<Exchange::IWheelProducer*>(Interface(reader.Number<Core::instance_id>(), Exchange::IWheelProducer::ID));

            return (result);
        }

    }; // class ExchangeWheelHandlerProxy

    //
    // Exchange::IPointerHandler interface proxy definitions
    //
    // Methods:
    //  (0) virtual uint32_t PointerMotionEvent(const int16_t, const int16_t) = 0
    //  (1) virtual uint32_t PointerButtonEvent(const bool, const uint8_t) = 0
    //  (2) virtual Exchange::IPointerProducer* PointerProducer(const string&) = 0
    //

    class ExchangePointerHandlerProxy final : public ProxyStub::UnknownProxyType<Exchange::IPointerHandler> {
    public:
        ExchangePointerHandlerProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
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

        uint32_t PointerMotionEvent(const int16_t _x, const int16_t _y) override
        {
            IPCMessage message(BaseClass::Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<int16_t>(_x);
            writer.Number<int16_t>(_y);

            uint32_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint32_t>();

            return (result);
        }

        uint32_t PointerButtonEvent(const bool _pressed, const uint8_t _button) override
        {
            IPCMessage message(BaseClass::Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Boolean(_pressed);
            writer.Number<uint8_t>(_button);

            uint32_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint32_t>();

            return (result);
        }

        Exchange::IPointerProducer* PointerProducer(const string& _name) override
        {
            IPCMessage message(BaseClass::Message(2));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const string&>(_name));

            Exchange::IPointerProducer* result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reinterpret_cast<Exchange::IPointerProducer*>(Interface(reader.Number<Core::instance_id>(), Exchange::IPointerProducer::ID));

            return (result);
        }

    }; // class ExchangePointerHandlerProxy

    //
    // Exchange::ITouchHandler interface proxy definitions
    //
    // Methods:
    //  (0) virtual uint32_t TouchEvent(const uint8_t, const Exchange::ITouchHandler::touchstate, const uint16_t, const uint16_t) = 0
    //  (1) virtual Exchange::ITouchProducer* TouchProducer(const string&) = 0
    //

    class ExchangeTouchHandlerProxy final : public ProxyStub::UnknownProxyType<Exchange::ITouchHandler> {
    public:
        ExchangeTouchHandlerProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
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

        uint32_t TouchEvent(const uint8_t _index, const Exchange::ITouchHandler::touchstate _state, const uint16_t _x, const uint16_t _y) override
        {
            IPCMessage message(BaseClass::Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint8_t>(_index);
            writer.Number<Exchange::ITouchHandler::touchstate>(_state);
            writer.Number<uint16_t>(_x);
            writer.Number<uint16_t>(_y);

            uint32_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint32_t>();

            return (result);
        }

        Exchange::ITouchProducer* TouchProducer(const string& _name) override
        {
            IPCMessage message(BaseClass::Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const string&>(_name));

            Exchange::ITouchProducer* result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reinterpret_cast<Exchange::ITouchProducer*>(Interface(reader.Number<Core::instance_id>(), Exchange::ITouchProducer::ID));

            return (result);
        }

    }; // class ExchangeTouchHandlerProxy

    //
    // Exchange::IKeyProducer interface proxy definitions
    //
    // Methods:
    //  (0) virtual string Name() const = 0
    //  (1) virtual uint32_t Callback(Exchange::IKeyHandler*) = 0
    //  (2) virtual uint32_t Error() const = 0
    //  (3) virtual string MetaData() const = 0
    //  (4) virtual void Configure(const string&) = 0
    //  (5) virtual bool Pair() = 0
    //  (6) virtual bool Unpair(string) = 0
    //

    class ExchangeKeyProducerProxy final : public ProxyStub::UnknownProxyType<Exchange::IKeyProducer> {
    public:
        ExchangeKeyProducerProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
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

        uint32_t Callback(Exchange::IKeyHandler* _callback) override
        {
            IPCMessage message(BaseClass::Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_callback));

            uint32_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint32_t>();

            Complete(reader);

            return (result);
        }

        uint32_t Error() const override
        {
            IPCMessage message(BaseClass::Message(2));

            uint32_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint32_t>();

            return (result);
        }

        string MetaData() const override
        {
            IPCMessage message(BaseClass::Message(3));

            string result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Text();

            return (result);
        }

        void Configure(const string& _settings) override
        {
            IPCMessage message(BaseClass::Message(4));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const string&>(_settings));

            UnknownProxyType::Invoke(message);
        }

        bool Pair() override
        {
            IPCMessage message(BaseClass::Message(5));

            bool result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Boolean();

            return (result);
        }

        bool Unpair(string _bindingId) override
        {
            IPCMessage message(BaseClass::Message(6));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_bindingId);

            bool result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Boolean();

            return (result);
        }

    }; // class ExchangeKeyProducerProxy

    //
    // Exchange::IWheelProducer interface proxy definitions
    //
    // Methods:
    //  (0) virtual string Name() const = 0
    //  (1) virtual uint32_t Callback(Exchange::IWheelHandler*) = 0
    //  (2) virtual uint32_t Error() const = 0
    //  (3) virtual string MetaData() const = 0
    //  (4) virtual void Configure(const string&) = 0
    //

    class ExchangeWheelProducerProxy final : public ProxyStub::UnknownProxyType<Exchange::IWheelProducer> {
    public:
        ExchangeWheelProducerProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
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

        uint32_t Callback(Exchange::IWheelHandler* _callback) override
        {
            IPCMessage message(BaseClass::Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_callback));

            uint32_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint32_t>();

            Complete(reader);

            return (result);
        }

        uint32_t Error() const override
        {
            IPCMessage message(BaseClass::Message(2));

            uint32_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint32_t>();

            return (result);
        }

        string MetaData() const override
        {
            IPCMessage message(BaseClass::Message(3));

            string result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Text();

            return (result);
        }

        void Configure(const string& _settings) override
        {
            IPCMessage message(BaseClass::Message(4));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const string&>(_settings));

            UnknownProxyType::Invoke(message);
        }

    }; // class ExchangeWheelProducerProxy

    //
    // Exchange::IPointerProducer interface proxy definitions
    //
    // Methods:
    //  (0) virtual string Name() const = 0
    //  (1) virtual uint32_t Callback(Exchange::IPointerHandler*) = 0
    //  (2) virtual uint32_t Error() const = 0
    //  (3) virtual string MetaData() const = 0
    //  (4) virtual void Configure(const string&) = 0
    //

    class ExchangePointerProducerProxy final : public ProxyStub::UnknownProxyType<Exchange::IPointerProducer> {
    public:
        ExchangePointerProducerProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
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

        uint32_t Callback(Exchange::IPointerHandler* _callback) override
        {
            IPCMessage message(BaseClass::Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_callback));

            uint32_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint32_t>();

            Complete(reader);

            return (result);
        }

        uint32_t Error() const override
        {
            IPCMessage message(BaseClass::Message(2));

            uint32_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint32_t>();

            return (result);
        }

        string MetaData() const override
        {
            IPCMessage message(BaseClass::Message(3));

            string result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Text();

            return (result);
        }

        void Configure(const string& _settings) override
        {
            IPCMessage message(BaseClass::Message(4));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const string&>(_settings));

            UnknownProxyType::Invoke(message);
        }

    }; // class ExchangePointerProducerProxy

    //
    // Exchange::ITouchProducer interface proxy definitions
    //
    // Methods:
    //  (0) virtual string Name() const = 0
    //  (1) virtual uint32_t Callback(Exchange::ITouchHandler*) = 0
    //  (2) virtual uint32_t Error() const = 0
    //  (3) virtual string MetaData() const = 0
    //  (4) virtual void Configure(const string&) = 0
    //

    class ExchangeTouchProducerProxy final : public ProxyStub::UnknownProxyType<Exchange::ITouchProducer> {
    public:
        ExchangeTouchProducerProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
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

        uint32_t Callback(Exchange::ITouchHandler* _callback) override
        {
            IPCMessage message(BaseClass::Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_callback));

            uint32_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint32_t>();

            Complete(reader);

            return (result);
        }

        uint32_t Error() const override
        {
            IPCMessage message(BaseClass::Message(2));

            uint32_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint32_t>();

            return (result);
        }

        string MetaData() const override
        {
            IPCMessage message(BaseClass::Message(3));

            string result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Text();

            return (result);
        }

        void Configure(const string& _settings) override
        {
            IPCMessage message(BaseClass::Message(4));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const string&>(_settings));

            UnknownProxyType::Invoke(message);
        }

    }; // class ExchangeTouchProducerProxy

    POP_WARNING()
    POP_WARNING()

    // -----------------------------------------------------------------
    // REGISTRATION
    // -----------------------------------------------------------------

    namespace {

        typedef ProxyStub::UnknownStubType<Exchange::IKeyHandler, ExchangeKeyHandlerStubMethods> ExchangeKeyHandlerStub;
        typedef ProxyStub::UnknownStubType<Exchange::IWheelHandler, ExchangeWheelHandlerStubMethods> ExchangeWheelHandlerStub;
        typedef ProxyStub::UnknownStubType<Exchange::IPointerHandler, ExchangePointerHandlerStubMethods> ExchangePointerHandlerStub;
        typedef ProxyStub::UnknownStubType<Exchange::ITouchHandler, ExchangeTouchHandlerStubMethods> ExchangeTouchHandlerStub;
        typedef ProxyStub::UnknownStubType<Exchange::IKeyProducer, ExchangeKeyProducerStubMethods> ExchangeKeyProducerStub;
        typedef ProxyStub::UnknownStubType<Exchange::IWheelProducer, ExchangeWheelProducerStubMethods> ExchangeWheelProducerStub;
        typedef ProxyStub::UnknownStubType<Exchange::IPointerProducer, ExchangePointerProducerStubMethods> ExchangePointerProducerStub;
        typedef ProxyStub::UnknownStubType<Exchange::ITouchProducer, ExchangeTouchProducerStubMethods> ExchangeTouchProducerStub;

        static class Instantiation {
        public:
            Instantiation()
            {
                RPC::Administrator::Instance().Announce<Exchange::IKeyHandler, ExchangeKeyHandlerProxy, ExchangeKeyHandlerStub>();
                RPC::Administrator::Instance().Announce<Exchange::IWheelHandler, ExchangeWheelHandlerProxy, ExchangeWheelHandlerStub>();
                RPC::Administrator::Instance().Announce<Exchange::IPointerHandler, ExchangePointerHandlerProxy, ExchangePointerHandlerStub>();
                RPC::Administrator::Instance().Announce<Exchange::ITouchHandler, ExchangeTouchHandlerProxy, ExchangeTouchHandlerStub>();
                RPC::Administrator::Instance().Announce<Exchange::IKeyProducer, ExchangeKeyProducerProxy, ExchangeKeyProducerStub>();
                RPC::Administrator::Instance().Announce<Exchange::IWheelProducer, ExchangeWheelProducerProxy, ExchangeWheelProducerStub>();
                RPC::Administrator::Instance().Announce<Exchange::IPointerProducer, ExchangePointerProducerProxy, ExchangePointerProducerStub>();
                RPC::Administrator::Instance().Announce<Exchange::ITouchProducer, ExchangeTouchProducerProxy, ExchangeTouchProducerStub>();
            }
            ~Instantiation()
            {
                RPC::Administrator::Instance().Recall<Exchange::IKeyHandler>();
                RPC::Administrator::Instance().Recall<Exchange::IWheelHandler>();
                RPC::Administrator::Instance().Recall<Exchange::IPointerHandler>();
                RPC::Administrator::Instance().Recall<Exchange::ITouchHandler>();
                RPC::Administrator::Instance().Recall<Exchange::IKeyProducer>();
                RPC::Administrator::Instance().Recall<Exchange::IWheelProducer>();
                RPC::Administrator::Instance().Recall<Exchange::IPointerProducer>();
                RPC::Administrator::Instance().Recall<Exchange::ITouchProducer>();
            }
        } ProxyStubRegistration;

    } // namespace

} // namespace ProxyStubs

}
