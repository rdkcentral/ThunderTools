//
// generated automatically from "IStream.h"
//
// implements COM-RPC proxy stubs for:
//   - class Exchange::IStream
//   - class Exchange::IStream::IElement
//   - class Exchange::IStream::IElement::IIterator
//   - class Exchange::IStream::IControl
//   - class Exchange::IStream::IControl::IGeometry
//   - class Exchange::IStream::IControl::ICallback
//   - class Exchange::IStream::ICallback
//   - class Exchange::IPlayer
//

#include "Module.h"
#include "IStream.h"

#include <com/com.h>

namespace WPEFramework {

namespace ProxyStubs {

    PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    // -----------------------------------------------------------------
    // STUBS
    // -----------------------------------------------------------------

    //
    // Exchange::IStream interface stub definitions
    //
    // Methods:
    //  (0) virtual string Metadata() const = 0
    //  (1) virtual Exchange::IStream::streamtype Type() const = 0
    //  (2) virtual Exchange::IStream::drmtype DRM() const = 0
    //  (3) virtual Exchange::IStream::IControl* Control() = 0
    //  (4) virtual void Callback(Exchange::IStream::ICallback*)
    //  (5) virtual void Attach(Exchange::IStream::ICallback*) = 0
    //  (6) virtual uint32_t Detach(Exchange::IStream::ICallback*) = 0
    //  (7) virtual Exchange::IStream::state State() const = 0
    //  (8) virtual uint32_t Load(const string&) = 0
    //  (9) virtual uint32_t Error() const = 0
    //  (10) virtual Exchange::IStream::IElement::IIterator* Elements() = 0
    //

    ProxyStub::MethodHandler ExchangeStreamStubMethods[] = {
        // (0) virtual string Metadata() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IStream* implementation = reinterpret_cast<const Exchange::IStream*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            string result = implementation->Metadata();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Text(result);
        },

        // (1) virtual Exchange::IStream::streamtype Type() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IStream* implementation = reinterpret_cast<const Exchange::IStream*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::IStream::streamtype result = implementation->Type();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Exchange::IStream::streamtype>(result);
        },

        // (2) virtual Exchange::IStream::drmtype DRM() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IStream* implementation = reinterpret_cast<const Exchange::IStream*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::IStream::drmtype result = implementation->DRM();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Exchange::IStream::drmtype>(result);
        },

        // (3) virtual Exchange::IStream::IControl* Control() = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IStream* implementation = reinterpret_cast<Exchange::IStream*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::IStream::IControl* result = implementation->Control();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(result));

            RPC::Administrator::Instance().RegisterInterface(channel, result);
        },

        // (4) virtual void Callback(Exchange::IStream::ICallback*)
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IStream* implementation = reinterpret_cast<Exchange::IStream*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const Core::instance_id parameter_eda8e2cdImplementation = reader.Number<Core::instance_id>();

            Exchange::IStream::ICallback* _parameter_eda8e2cd = nullptr;
            ProxyStub::UnknownProxy* parameter_eda8e2cdProxy = nullptr;
            if (parameter_eda8e2cdImplementation != 0) {
                parameter_eda8e2cdProxy = RPC::Administrator::Instance().ProxyInstance(channel, parameter_eda8e2cdImplementation, false, _parameter_eda8e2cd);

                ASSERT((_parameter_eda8e2cd != nullptr) && (parameter_eda8e2cdProxy != nullptr));
            }

            implementation->Callback(_parameter_eda8e2cd);

            if (parameter_eda8e2cdProxy != nullptr) {
                RPC::Administrator::Instance().Release(parameter_eda8e2cdProxy, message->Response());
            }
        },

        // (5) virtual void Attach(Exchange::IStream::ICallback*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IStream* implementation = reinterpret_cast<Exchange::IStream*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const Core::instance_id callbackImplementation = reader.Number<Core::instance_id>();

            Exchange::IStream::ICallback* _callback = nullptr;
            ProxyStub::UnknownProxy* callbackProxy = nullptr;
            if (callbackImplementation != 0) {
                callbackProxy = RPC::Administrator::Instance().ProxyInstance(channel, callbackImplementation, false, _callback);

                ASSERT((_callback != nullptr) && (callbackProxy != nullptr));
            }

            implementation->Attach(_callback);

            if (callbackProxy != nullptr) {
                RPC::Administrator::Instance().Release(callbackProxy, message->Response());
            }
        },

        // (6) virtual uint32_t Detach(Exchange::IStream::ICallback*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IStream* implementation = reinterpret_cast<Exchange::IStream*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const Core::instance_id callbackImplementation = reader.Number<Core::instance_id>();

            Exchange::IStream::ICallback* _callback = nullptr;
            ProxyStub::UnknownProxy* callbackProxy = nullptr;
            if (callbackImplementation != 0) {
                callbackProxy = RPC::Administrator::Instance().ProxyInstance(channel, callbackImplementation, false, _callback);

                ASSERT((_callback != nullptr) && (callbackProxy != nullptr));
            }

            uint32_t result = implementation->Detach(_callback);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);

            if (callbackProxy != nullptr) {
                RPC::Administrator::Instance().Release(callbackProxy, message->Response());
            }
        },

        // (7) virtual Exchange::IStream::state State() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IStream* implementation = reinterpret_cast<const Exchange::IStream*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::IStream::state result = implementation->State();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Exchange::IStream::state>(result);
        },

        // (8) virtual uint32_t Load(const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IStream* implementation = reinterpret_cast<Exchange::IStream*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _configuration = reader.Text();

            uint32_t result = implementation->Load(static_cast<const string&>(_configuration));

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (9) virtual uint32_t Error() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IStream* implementation = reinterpret_cast<const Exchange::IStream*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            uint32_t result = implementation->Error();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (10) virtual Exchange::IStream::IElement::IIterator* Elements() = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IStream* implementation = reinterpret_cast<Exchange::IStream*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::IStream::IElement::IIterator* result = implementation->Elements();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(result));

            RPC::Administrator::Instance().RegisterInterface(channel, result);
        }
        , nullptr
    }; // ExchangeStreamStubMethods

    //
    // Exchange::IStream::IElement interface stub definitions
    //
    // Methods:
    //  (0) virtual Exchange::IStream::IElement::type Type() const = 0
    //

    ProxyStub::MethodHandler ExchangeStreamElementStubMethods[] = {
        // (0) virtual Exchange::IStream::IElement::type Type() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IStream::IElement* implementation = reinterpret_cast<const Exchange::IStream::IElement*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::IStream::IElement::type result = implementation->Type();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Exchange::IStream::IElement::type>(result);
        }
        , nullptr
    }; // ExchangeStreamElementStubMethods

    //
    // Exchange::IStream::IElement::IIterator interface stub definitions
    //
    // Methods:
    //  (0) virtual void Reset() = 0
    //  (1) virtual bool IsValid() const = 0
    //  (2) virtual bool Next() = 0
    //  (3) virtual Exchange::IStream::IElement* Current() = 0
    //

    ProxyStub::MethodHandler ExchangeStreamElementIteratorStubMethods[] = {
        // (0) virtual void Reset() = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IStream::IElement::IIterator* implementation = reinterpret_cast<Exchange::IStream::IElement::IIterator*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            implementation->Reset();
        },

        // (1) virtual bool IsValid() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IStream::IElement::IIterator* implementation = reinterpret_cast<const Exchange::IStream::IElement::IIterator*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            bool result = implementation->IsValid();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Boolean(result);
        },

        // (2) virtual bool Next() = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IStream::IElement::IIterator* implementation = reinterpret_cast<Exchange::IStream::IElement::IIterator*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            bool result = implementation->Next();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Boolean(result);
        },

        // (3) virtual Exchange::IStream::IElement* Current() = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IStream::IElement::IIterator* implementation = reinterpret_cast<Exchange::IStream::IElement::IIterator*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::IStream::IElement* result = implementation->Current();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(result));

            RPC::Administrator::Instance().RegisterInterface(channel, result);
        }
        , nullptr
    }; // ExchangeStreamElementIteratorStubMethods

    //
    // Exchange::IStream::IControl interface stub definitions
    //
    // Methods:
    //  (0) virtual RPC::IValueIterator* Speeds() const = 0
    //  (1) virtual void Speed(const int32_t) = 0
    //  (2) virtual int32_t Speed() const = 0
    //  (3) virtual void Position(const uint64_t) = 0
    //  (4) virtual uint64_t Position() const = 0
    //  (5) virtual void TimeRange(uint64_t&, uint64_t&) const = 0
    //  (6) virtual Exchange::IStream::IControl::IGeometry* Geometry() const = 0
    //  (7) virtual void Geometry(const Exchange::IStream::IControl::IGeometry*) = 0
    //  (8) virtual void Callback(Exchange::IStream::IControl::ICallback*) = 0
    //

    ProxyStub::MethodHandler ExchangeStreamControlStubMethods[] = {
        // (0) virtual RPC::IValueIterator* Speeds() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IStream::IControl* implementation = reinterpret_cast<const Exchange::IStream::IControl*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::IValueIterator* result = implementation->Speeds();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(result));

            RPC::Administrator::Instance().RegisterInterface(channel, result);
        },

        // (1) virtual void Speed(const int32_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IStream::IControl* implementation = reinterpret_cast<Exchange::IStream::IControl*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const int32_t _request = reader.Number<int32_t>();

            implementation->Speed(_request);
        },

        // (2) virtual int32_t Speed() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IStream::IControl* implementation = reinterpret_cast<const Exchange::IStream::IControl*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            int32_t result = implementation->Speed();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<int32_t>(result);
        },

        // (3) virtual void Position(const uint64_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IStream::IControl* implementation = reinterpret_cast<Exchange::IStream::IControl*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint64_t _absoluteTime = reader.Number<uint64_t>();

            implementation->Position(_absoluteTime);
        },

        // (4) virtual uint64_t Position() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IStream::IControl* implementation = reinterpret_cast<const Exchange::IStream::IControl*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            uint64_t result = implementation->Position();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint64_t>(result);
        },

        // (5) virtual void TimeRange(uint64_t&, uint64_t&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IStream::IControl* implementation = reinterpret_cast<const Exchange::IStream::IControl*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            uint64_t _begin{};
            uint64_t _end{};

            implementation->TimeRange(_begin, _end);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint64_t>(_begin);
            writer.Number<uint64_t>(_end);
        },

        // (6) virtual Exchange::IStream::IControl::IGeometry* Geometry() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IStream::IControl* implementation = reinterpret_cast<const Exchange::IStream::IControl*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::IStream::IControl::IGeometry* result = implementation->Geometry();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(result));

            RPC::Administrator::Instance().RegisterInterface(channel, result);
        },

        // (7) virtual void Geometry(const Exchange::IStream::IControl::IGeometry*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IStream::IControl* implementation = reinterpret_cast<Exchange::IStream::IControl*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const Core::instance_id settingsImplementation = reader.Number<Core::instance_id>();

            Exchange::IStream::IControl::IGeometry* _settings = nullptr;
            ProxyStub::UnknownProxy* settingsProxy = nullptr;
            if (settingsImplementation != 0) {
                settingsProxy = RPC::Administrator::Instance().ProxyInstance(channel, settingsImplementation, false, _settings);

                ASSERT((_settings != nullptr) && (settingsProxy != nullptr));
            }

            implementation->Geometry(_settings);

            if (settingsProxy != nullptr) {
                RPC::Administrator::Instance().Release(settingsProxy, message->Response());
            }
        },

        // (8) virtual void Callback(Exchange::IStream::IControl::ICallback*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IStream::IControl* implementation = reinterpret_cast<Exchange::IStream::IControl*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const Core::instance_id callbackImplementation = reader.Number<Core::instance_id>();

            Exchange::IStream::IControl::ICallback* _callback = nullptr;
            ProxyStub::UnknownProxy* callbackProxy = nullptr;
            if (callbackImplementation != 0) {
                callbackProxy = RPC::Administrator::Instance().ProxyInstance(channel, callbackImplementation, false, _callback);

                ASSERT((_callback != nullptr) && (callbackProxy != nullptr));
            }

            implementation->Callback(_callback);

            if (callbackProxy != nullptr) {
                RPC::Administrator::Instance().Release(callbackProxy, message->Response());
            }
        }
        , nullptr
    }; // ExchangeStreamControlStubMethods

    //
    // Exchange::IStream::IControl::IGeometry interface stub definitions
    //
    // Methods:
    //  (0) virtual uint32_t X() const = 0
    //  (1) virtual uint32_t Y() const = 0
    //  (2) virtual uint32_t Z() const = 0
    //  (3) virtual uint32_t Width() const = 0
    //  (4) virtual uint32_t Height() const = 0
    //

    ProxyStub::MethodHandler ExchangeStreamControlGeometryStubMethods[] = {
        // (0) virtual uint32_t X() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IStream::IControl::IGeometry* implementation = reinterpret_cast<const Exchange::IStream::IControl::IGeometry*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            uint32_t result = implementation->X();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (1) virtual uint32_t Y() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IStream::IControl::IGeometry* implementation = reinterpret_cast<const Exchange::IStream::IControl::IGeometry*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            uint32_t result = implementation->Y();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (2) virtual uint32_t Z() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IStream::IControl::IGeometry* implementation = reinterpret_cast<const Exchange::IStream::IControl::IGeometry*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            uint32_t result = implementation->Z();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (3) virtual uint32_t Width() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IStream::IControl::IGeometry* implementation = reinterpret_cast<const Exchange::IStream::IControl::IGeometry*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            uint32_t result = implementation->Width();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (4) virtual uint32_t Height() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IStream::IControl::IGeometry* implementation = reinterpret_cast<const Exchange::IStream::IControl::IGeometry*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            uint32_t result = implementation->Height();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        }
        , nullptr
    }; // ExchangeStreamControlGeometryStubMethods

    //
    // Exchange::IStream::IControl::ICallback interface stub definitions
    //
    // Methods:
    //  (0) virtual void Event(const uint32_t) = 0
    //  (1) virtual void TimeUpdate(const uint64_t) = 0
    //

    ProxyStub::MethodHandler ExchangeStreamControlCallbackStubMethods[] = {
        // (0) virtual void Event(const uint32_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IStream::IControl::ICallback* implementation = reinterpret_cast<Exchange::IStream::IControl::ICallback*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint32_t _eventid = reader.Number<uint32_t>();

            implementation->Event(_eventid);
        },

        // (1) virtual void TimeUpdate(const uint64_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IStream::IControl::ICallback* implementation = reinterpret_cast<Exchange::IStream::IControl::ICallback*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint64_t _position = reader.Number<uint64_t>();

            implementation->TimeUpdate(_position);
        }
        , nullptr
    }; // ExchangeStreamControlCallbackStubMethods

    //
    // Exchange::IStream::ICallback interface stub definitions
    //
    // Methods:
    //  (0) virtual void DRM(const uint32_t) = 0
    //  (1) virtual void StateChange(const Exchange::IStream::state) = 0
    //  (2) virtual void Event(const uint32_t) = 0
    //

    ProxyStub::MethodHandler ExchangeStreamCallbackStubMethods[] = {
        // (0) virtual void DRM(const uint32_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IStream::ICallback* implementation = reinterpret_cast<Exchange::IStream::ICallback*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint32_t _state = reader.Number<uint32_t>();

            implementation->DRM(_state);
        },

        // (1) virtual void StateChange(const Exchange::IStream::state) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IStream::ICallback* implementation = reinterpret_cast<Exchange::IStream::ICallback*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const Exchange::IStream::state _newState = reader.Number<Exchange::IStream::state>();

            implementation->StateChange(_newState);
        },

        // (2) virtual void Event(const uint32_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IStream::ICallback* implementation = reinterpret_cast<Exchange::IStream::ICallback*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint32_t _eventid = reader.Number<uint32_t>();

            implementation->Event(_eventid);
        }
        , nullptr
    }; // ExchangeStreamCallbackStubMethods

    //
    // Exchange::IPlayer interface stub definitions
    //
    // Methods:
    //  (0) virtual Exchange::IStream* CreateStream(const Exchange::IStream::streamtype) = 0
    //  (1) virtual uint32_t Configure(PluginHost::IShell*) = 0
    //

    ProxyStub::MethodHandler ExchangePlayerStubMethods[] = {
        // (0) virtual Exchange::IStream* CreateStream(const Exchange::IStream::streamtype) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IPlayer* implementation = reinterpret_cast<Exchange::IPlayer*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const Exchange::IStream::streamtype _streamType = reader.Number<Exchange::IStream::streamtype>();

            Exchange::IStream* result = implementation->CreateStream(_streamType);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(result));

            RPC::Administrator::Instance().RegisterInterface(channel, result);
        },

        // (1) virtual uint32_t Configure(PluginHost::IShell*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IPlayer* implementation = reinterpret_cast<Exchange::IPlayer*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const Core::instance_id serviceImplementation = reader.Number<Core::instance_id>();

            PluginHost::IShell* _service = nullptr;
            ProxyStub::UnknownProxy* serviceProxy = nullptr;
            if (serviceImplementation != 0) {
                serviceProxy = RPC::Administrator::Instance().ProxyInstance(channel, serviceImplementation, false, _service);

                ASSERT((_service != nullptr) && (serviceProxy != nullptr));
            }

            uint32_t result = implementation->Configure(_service);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);

            if (serviceProxy != nullptr) {
                RPC::Administrator::Instance().Release(serviceProxy, message->Response());
            }
        }
        , nullptr
    }; // ExchangePlayerStubMethods

    // -----------------------------------------------------------------
    // PROXIES
    // -----------------------------------------------------------------

    //
    // Exchange::IStream interface proxy definitions
    //
    // Methods:
    //  (0) virtual string Metadata() const = 0
    //  (1) virtual Exchange::IStream::streamtype Type() const = 0
    //  (2) virtual Exchange::IStream::drmtype DRM() const = 0
    //  (3) virtual Exchange::IStream::IControl* Control() = 0
    //  (4) virtual void Callback(Exchange::IStream::ICallback*)
    //  (5) virtual void Attach(Exchange::IStream::ICallback*) = 0
    //  (6) virtual uint32_t Detach(Exchange::IStream::ICallback*) = 0
    //  (7) virtual Exchange::IStream::state State() const = 0
    //  (8) virtual uint32_t Load(const string&) = 0
    //  (9) virtual uint32_t Error() const = 0
    //  (10) virtual Exchange::IStream::IElement::IIterator* Elements() = 0
    //

    class ExchangeStreamProxy final : public ProxyStub::UnknownProxyType<Exchange::IStream> {
    public:
        ExchangeStreamProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
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

        string Metadata() const override
        {
            IPCMessage message(BaseClass::Message(0));

            string result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Text();

            return (result);
        }

        Exchange::IStream::streamtype Type() const override
        {
            IPCMessage message(BaseClass::Message(1));

            Exchange::IStream::streamtype result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<Exchange::IStream::streamtype>();

            return (result);
        }

        Exchange::IStream::drmtype DRM() const override
        {
            IPCMessage message(BaseClass::Message(2));

            Exchange::IStream::drmtype result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<Exchange::IStream::drmtype>();

            return (result);
        }

        Exchange::IStream::IControl* Control() override
        {
            IPCMessage message(BaseClass::Message(3));

            Exchange::IStream::IControl* result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reinterpret_cast<Exchange::IStream::IControl*>(Interface(reader.Number<Core::instance_id>(), Exchange::IStream::IControl::ID));

            return (result);
        }

        void Callback(Exchange::IStream::ICallback* _parameter_eda8e2cd) override
        {
            IPCMessage message(BaseClass::Message(4));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_parameter_eda8e2cd));

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());

            Complete(reader);
        }

        void Attach(Exchange::IStream::ICallback* _callback) override
        {
            IPCMessage message(BaseClass::Message(5));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_callback));

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());

            Complete(reader);
        }

        uint32_t Detach(Exchange::IStream::ICallback* _callback) override
        {
            IPCMessage message(BaseClass::Message(6));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_callback));

            uint32_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint32_t>();

            Complete(reader);

            return (result);
        }

        Exchange::IStream::state State() const override
        {
            IPCMessage message(BaseClass::Message(7));

            Exchange::IStream::state result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<Exchange::IStream::state>();

            return (result);
        }

        uint32_t Load(const string& _configuration) override
        {
            IPCMessage message(BaseClass::Message(8));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const string&>(_configuration));

            uint32_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint32_t>();

            return (result);
        }

        uint32_t Error() const override
        {
            IPCMessage message(BaseClass::Message(9));

            uint32_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint32_t>();

            return (result);
        }

        Exchange::IStream::IElement::IIterator* Elements() override
        {
            IPCMessage message(BaseClass::Message(10));

            Exchange::IStream::IElement::IIterator* result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reinterpret_cast<Exchange::IStream::IElement::IIterator*>(Interface(reader.Number<Core::instance_id>(), Exchange::IStream::IElement::IIterator::ID));

            return (result);
        }

    }; // class ExchangeStreamProxy

    //
    // Exchange::IStream::IElement interface proxy definitions
    //
    // Methods:
    //  (0) virtual Exchange::IStream::IElement::type Type() const = 0
    //

    class ExchangeStreamElementProxy final : public ProxyStub::UnknownProxyType<Exchange::IStream::IElement> {
    public:
        ExchangeStreamElementProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
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

        Exchange::IStream::IElement::type Type() const override
        {
            IPCMessage message(BaseClass::Message(0));

            Exchange::IStream::IElement::type result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<Exchange::IStream::IElement::type>();

            return (result);
        }

    }; // class ExchangeStreamElementProxy

    //
    // Exchange::IStream::IElement::IIterator interface proxy definitions
    //
    // Methods:
    //  (0) virtual void Reset() = 0
    //  (1) virtual bool IsValid() const = 0
    //  (2) virtual bool Next() = 0
    //  (3) virtual Exchange::IStream::IElement* Current() = 0
    //

    class ExchangeStreamElementIteratorProxy final : public ProxyStub::UnknownProxyType<Exchange::IStream::IElement::IIterator> {
    public:
        ExchangeStreamElementIteratorProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
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

        Exchange::IStream::IElement* Current() override
        {
            IPCMessage message(BaseClass::Message(3));

            Exchange::IStream::IElement* result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reinterpret_cast<Exchange::IStream::IElement*>(Interface(reader.Number<Core::instance_id>(), Exchange::IStream::IElement::ID));

            return (result);
        }

    }; // class ExchangeStreamElementIteratorProxy

    //
    // Exchange::IStream::IControl interface proxy definitions
    //
    // Methods:
    //  (0) virtual RPC::IValueIterator* Speeds() const = 0
    //  (1) virtual void Speed(const int32_t) = 0
    //  (2) virtual int32_t Speed() const = 0
    //  (3) virtual void Position(const uint64_t) = 0
    //  (4) virtual uint64_t Position() const = 0
    //  (5) virtual void TimeRange(uint64_t&, uint64_t&) const = 0
    //  (6) virtual Exchange::IStream::IControl::IGeometry* Geometry() const = 0
    //  (7) virtual void Geometry(const Exchange::IStream::IControl::IGeometry*) = 0
    //  (8) virtual void Callback(Exchange::IStream::IControl::ICallback*) = 0
    //

    class ExchangeStreamControlProxy final : public ProxyStub::UnknownProxyType<Exchange::IStream::IControl> {
    public:
        ExchangeStreamControlProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
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

        RPC::IValueIterator* Speeds() const override
        {
            IPCMessage message(BaseClass::Message(0));

            RPC::IValueIterator* result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reinterpret_cast<RPC::IValueIterator*>(Interface(reader.Number<Core::instance_id>(), RPC::IValueIterator::ID));

            return (result);
        }

        void Speed(const int32_t _request) override
        {
            IPCMessage message(BaseClass::Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<int32_t>(_request);

            UnknownProxyType::Invoke(message);
        }

        int32_t Speed() const override
        {
            IPCMessage message(BaseClass::Message(2));

            int32_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<int32_t>();

            return (result);
        }

        void Position(const uint64_t _absoluteTime) override
        {
            IPCMessage message(BaseClass::Message(3));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint64_t>(_absoluteTime);

            UnknownProxyType::Invoke(message);
        }

        uint64_t Position() const override
        {
            IPCMessage message(BaseClass::Message(4));

            uint64_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint64_t>();

            return (result);
        }

        void TimeRange(uint64_t& _begin, uint64_t& _end) const override
        {
            IPCMessage message(BaseClass::Message(5));

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            _begin = reader.Number<uint64_t>();
            _end = reader.Number<uint64_t>();
        }

        Exchange::IStream::IControl::IGeometry* Geometry() const override
        {
            IPCMessage message(BaseClass::Message(6));

            Exchange::IStream::IControl::IGeometry* result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reinterpret_cast<Exchange::IStream::IControl::IGeometry*>(Interface(reader.Number<Core::instance_id>(), Exchange::IStream::IControl::IGeometry::ID));

            return (result);
        }

        void Geometry(const Exchange::IStream::IControl::IGeometry* _settings) override
        {
            IPCMessage message(BaseClass::Message(7));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_settings));

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());

            Complete(reader);
        }

        void Callback(Exchange::IStream::IControl::ICallback* _callback) override
        {
            IPCMessage message(BaseClass::Message(8));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_callback));

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());

            Complete(reader);
        }

    }; // class ExchangeStreamControlProxy

    //
    // Exchange::IStream::IControl::IGeometry interface proxy definitions
    //
    // Methods:
    //  (0) virtual uint32_t X() const = 0
    //  (1) virtual uint32_t Y() const = 0
    //  (2) virtual uint32_t Z() const = 0
    //  (3) virtual uint32_t Width() const = 0
    //  (4) virtual uint32_t Height() const = 0
    //

    class ExchangeStreamControlGeometryProxy final : public ProxyStub::UnknownProxyType<Exchange::IStream::IControl::IGeometry> {
    public:
        ExchangeStreamControlGeometryProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
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

        uint32_t X() const override
        {
            IPCMessage message(BaseClass::Message(0));

            uint32_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint32_t>();

            return (result);
        }

        uint32_t Y() const override
        {
            IPCMessage message(BaseClass::Message(1));

            uint32_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint32_t>();

            return (result);
        }

        uint32_t Z() const override
        {
            IPCMessage message(BaseClass::Message(2));

            uint32_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint32_t>();

            return (result);
        }

        uint32_t Width() const override
        {
            IPCMessage message(BaseClass::Message(3));

            uint32_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint32_t>();

            return (result);
        }

        uint32_t Height() const override
        {
            IPCMessage message(BaseClass::Message(4));

            uint32_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint32_t>();

            return (result);
        }

    }; // class ExchangeStreamControlGeometryProxy

    //
    // Exchange::IStream::IControl::ICallback interface proxy definitions
    //
    // Methods:
    //  (0) virtual void Event(const uint32_t) = 0
    //  (1) virtual void TimeUpdate(const uint64_t) = 0
    //

    class ExchangeStreamControlCallbackProxy final : public ProxyStub::UnknownProxyType<Exchange::IStream::IControl::ICallback> {
    public:
        ExchangeStreamControlCallbackProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
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

        void Event(const uint32_t _eventid) override
        {
            IPCMessage message(BaseClass::Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_eventid);

            UnknownProxyType::Invoke(message);
        }

        void TimeUpdate(const uint64_t _position) override
        {
            IPCMessage message(BaseClass::Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint64_t>(_position);

            UnknownProxyType::Invoke(message);
        }

    }; // class ExchangeStreamControlCallbackProxy

    //
    // Exchange::IStream::ICallback interface proxy definitions
    //
    // Methods:
    //  (0) virtual void DRM(const uint32_t) = 0
    //  (1) virtual void StateChange(const Exchange::IStream::state) = 0
    //  (2) virtual void Event(const uint32_t) = 0
    //

    class ExchangeStreamCallbackProxy final : public ProxyStub::UnknownProxyType<Exchange::IStream::ICallback> {
    public:
        ExchangeStreamCallbackProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
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

        void DRM(const uint32_t _state) override
        {
            IPCMessage message(BaseClass::Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_state);

            UnknownProxyType::Invoke(message);
        }

        void StateChange(const Exchange::IStream::state _newState) override
        {
            IPCMessage message(BaseClass::Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Exchange::IStream::state>(_newState);

            UnknownProxyType::Invoke(message);
        }

        void Event(const uint32_t _eventid) override
        {
            IPCMessage message(BaseClass::Message(2));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_eventid);

            UnknownProxyType::Invoke(message);
        }

    }; // class ExchangeStreamCallbackProxy

    //
    // Exchange::IPlayer interface proxy definitions
    //
    // Methods:
    //  (0) virtual Exchange::IStream* CreateStream(const Exchange::IStream::streamtype) = 0
    //  (1) virtual uint32_t Configure(PluginHost::IShell*) = 0
    //

    class ExchangePlayerProxy final : public ProxyStub::UnknownProxyType<Exchange::IPlayer> {
    public:
        ExchangePlayerProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
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

        Exchange::IStream* CreateStream(const Exchange::IStream::streamtype _streamType) override
        {
            IPCMessage message(BaseClass::Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Exchange::IStream::streamtype>(_streamType);

            Exchange::IStream* result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reinterpret_cast<Exchange::IStream*>(Interface(reader.Number<Core::instance_id>(), Exchange::IStream::ID));

            return (result);
        }

        uint32_t Configure(PluginHost::IShell* _service) override
        {
            IPCMessage message(BaseClass::Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_service));

            uint32_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint32_t>();

            Complete(reader);

            return (result);
        }

    }; // class ExchangePlayerProxy

    POP_WARNING()
    POP_WARNING()

    // -----------------------------------------------------------------
    // REGISTRATION
    // -----------------------------------------------------------------

    namespace {

        typedef ProxyStub::UnknownStubType<Exchange::IStream, ExchangeStreamStubMethods> ExchangeStreamStub;
        typedef ProxyStub::UnknownStubType<Exchange::IStream::IElement, ExchangeStreamElementStubMethods> ExchangeStreamElementStub;
        typedef ProxyStub::UnknownStubType<Exchange::IStream::IElement::IIterator, ExchangeStreamElementIteratorStubMethods> ExchangeStreamElementIteratorStub;
        typedef ProxyStub::UnknownStubType<Exchange::IStream::IControl, ExchangeStreamControlStubMethods> ExchangeStreamControlStub;
        typedef ProxyStub::UnknownStubType<Exchange::IStream::IControl::IGeometry, ExchangeStreamControlGeometryStubMethods> ExchangeStreamControlGeometryStub;
        typedef ProxyStub::UnknownStubType<Exchange::IStream::IControl::ICallback, ExchangeStreamControlCallbackStubMethods> ExchangeStreamControlCallbackStub;
        typedef ProxyStub::UnknownStubType<Exchange::IStream::ICallback, ExchangeStreamCallbackStubMethods> ExchangeStreamCallbackStub;
        typedef ProxyStub::UnknownStubType<Exchange::IPlayer, ExchangePlayerStubMethods> ExchangePlayerStub;

        static class Instantiation {
        public:
            Instantiation()
            {
                RPC::Administrator::Instance().Announce<Exchange::IStream, ExchangeStreamProxy, ExchangeStreamStub>();
                RPC::Administrator::Instance().Announce<Exchange::IStream::IElement, ExchangeStreamElementProxy, ExchangeStreamElementStub>();
                RPC::Administrator::Instance().Announce<Exchange::IStream::IElement::IIterator, ExchangeStreamElementIteratorProxy, ExchangeStreamElementIteratorStub>();
                RPC::Administrator::Instance().Announce<Exchange::IStream::IControl, ExchangeStreamControlProxy, ExchangeStreamControlStub>();
                RPC::Administrator::Instance().Announce<Exchange::IStream::IControl::IGeometry, ExchangeStreamControlGeometryProxy, ExchangeStreamControlGeometryStub>();
                RPC::Administrator::Instance().Announce<Exchange::IStream::IControl::ICallback, ExchangeStreamControlCallbackProxy, ExchangeStreamControlCallbackStub>();
                RPC::Administrator::Instance().Announce<Exchange::IStream::ICallback, ExchangeStreamCallbackProxy, ExchangeStreamCallbackStub>();
                RPC::Administrator::Instance().Announce<Exchange::IPlayer, ExchangePlayerProxy, ExchangePlayerStub>();
            }
            ~Instantiation()
            {
                RPC::Administrator::Instance().Recall<Exchange::IStream>();
                RPC::Administrator::Instance().Recall<Exchange::IStream::IElement>();
                RPC::Administrator::Instance().Recall<Exchange::IStream::IElement::IIterator>();
                RPC::Administrator::Instance().Recall<Exchange::IStream::IControl>();
                RPC::Administrator::Instance().Recall<Exchange::IStream::IControl::IGeometry>();
                RPC::Administrator::Instance().Recall<Exchange::IStream::IControl::ICallback>();
                RPC::Administrator::Instance().Recall<Exchange::IStream::ICallback>();
                RPC::Administrator::Instance().Recall<Exchange::IPlayer>();
            }
        } ProxyStubRegistration;

    } // namespace

} // namespace ProxyStubs

}
