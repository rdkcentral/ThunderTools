//
// generated automatically from "IAudioStream.h"
//
// implements COM-RPC proxy stubs for:
//   - class Exchange::IAudioStream
//   - class Exchange::IAudioStream::INotification
//   - class Exchange::IAudioStream::ICallback
//
// secure code enabled:
//   - instance verification enabled
//   - range verification enabled
//   - frame coherency verification enabled
//

#include "Module.h"
#include "IAudioStream.h"

#include <com/com.h>

namespace Thunder {

namespace ProxyStubs {

    PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    // -----------------------------------------------------------------
    // STUBS
    // -----------------------------------------------------------------

    //
    // Exchange::IAudioStream interface stub definitions
    //
    // Methods:
    //  (0) virtual Core::hresult Register(Exchange::IAudioStream::INotification* const) = 0
    //  (1) virtual Core::hresult Unregister(const Exchange::IAudioStream::INotification* const) = 0
    //  (2) virtual Core::hresult Callback(Exchange::IAudioStream::ICallback* const) = 0
    //  (3) virtual Core::hresult Name(string&) const = 0
    //  (4) virtual Core::hresult State(Exchange::IAudioStream::streamstate&) const = 0
    //  (5) virtual Core::hresult Capabilities(Exchange::IAudioStream::codectype&) const = 0
    //  (6) virtual Core::hresult Profile(const Exchange::IAudioStream::audioprofile&) = 0
    //  (7) virtual Core::hresult Profile(Exchange::IAudioStream::audioprofile&) const = 0
    //  (8) virtual Core::hresult Time(uint32_t&) const = 0
    //  (9) virtual Core::hresult Speed(const uint8_t) = 0
    //  (10) virtual Core::hresult Speed(uint8_t&) const = 0
    //

    static ProxyStub::MethodHandler ExchangeAudioStreamStubMethods[] = {
        // (0) virtual Core::hresult Register(Exchange::IAudioStream::INotification* const) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                Exchange::IAudioStream* implementation = reinterpret_cast<Exchange::IAudioStream*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::IAudioStream::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (sizeof(Core::instance_id))) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                Core::instance_id _notificationInstanceId__ = reader.Number<Core::instance_id>();

                Exchange::IAudioStream::INotification* _notification{};
                ProxyStub::UnknownProxy* _notificationProxy__ = nullptr;
                if (_notificationInstanceId__ != 0) {
                    _notificationProxy__ = RPC::Administrator::Instance().ProxyInstance(channel, _notificationInstanceId__, false, _notification);
                    ASSERT((_notification != nullptr) && (_notificationProxy__ != nullptr));
                    if ((_notification == nullptr) || (_notificationProxy__ == nullptr)) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }
                }

                Core::hresult result = implementation->Register(_notification);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<Core::hresult>(result);

                if (_notificationProxy__ != nullptr) {
                    RPC::Administrator::Instance().Release(_notificationProxy__, message->Response());
                }

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(hresult);
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::IAudioStream::ID, 0, hresult);
            }
        },

        // (1) virtual Core::hresult Unregister(const Exchange::IAudioStream::INotification* const) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                Exchange::IAudioStream* implementation = reinterpret_cast<Exchange::IAudioStream*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::IAudioStream::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (sizeof(Core::instance_id))) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                Core::instance_id _notificationInstanceId__ = reader.Number<Core::instance_id>();

                const Exchange::IAudioStream::INotification* _notification{};
                ProxyStub::UnknownProxy* _notificationProxy__ = nullptr;
                if (_notificationInstanceId__ != 0) {
                    _notificationProxy__ = RPC::Administrator::Instance().ProxyInstance(channel, _notificationInstanceId__, false, _notification);
                    ASSERT((_notification != nullptr) && (_notificationProxy__ != nullptr));
                    if ((_notification == nullptr) || (_notificationProxy__ == nullptr)) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }
                }

                Core::hresult result = implementation->Unregister(_notification);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<Core::hresult>(result);

                if (_notificationProxy__ != nullptr) {
                    RPC::Administrator::Instance().Release(_notificationProxy__, message->Response());
                }

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(hresult);
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::IAudioStream::ID, 1, hresult);
            }
        },

        // (2) virtual Core::hresult Callback(Exchange::IAudioStream::ICallback* const) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                Exchange::IAudioStream* implementation = reinterpret_cast<Exchange::IAudioStream*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::IAudioStream::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (sizeof(Core::instance_id))) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                Core::instance_id _callbackInstanceId__ = reader.Number<Core::instance_id>();

                Exchange::IAudioStream::ICallback* _callback{};
                ProxyStub::UnknownProxy* _callbackProxy__ = nullptr;
                if (_callbackInstanceId__ != 0) {
                    _callbackProxy__ = RPC::Administrator::Instance().ProxyInstance(channel, _callbackInstanceId__, false, _callback);
                    ASSERT((_callback != nullptr) && (_callbackProxy__ != nullptr));
                    if ((_callback == nullptr) || (_callbackProxy__ == nullptr)) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }
                }

                Core::hresult result = implementation->Callback(_callback);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<Core::hresult>(result);

                if (_callbackProxy__ != nullptr) {
                    RPC::Administrator::Instance().Release(_callbackProxy__, message->Response());
                }

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(hresult);
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::IAudioStream::ID, 2, hresult);
            }
        },

        // (3) virtual Core::hresult Name(string&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const Exchange::IAudioStream* implementation = reinterpret_cast<const Exchange::IAudioStream*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::IAudioStream::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                string _name{};

                Core::hresult result = implementation->Name(_name);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<Core::hresult>(result);
                writer.Text(_name);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(hresult);
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::IAudioStream::ID, 3, hresult);
            }
        },

        // (4) virtual Core::hresult State(Exchange::IAudioStream::streamstate&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const Exchange::IAudioStream* implementation = reinterpret_cast<const Exchange::IAudioStream*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::IAudioStream::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                Exchange::IAudioStream::streamstate _state{};

                Core::hresult result = implementation->State(_state);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<Core::hresult>(result);
                writer.Number<Exchange::IAudioStream::streamstate>(_state);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(hresult);
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::IAudioStream::ID, 4, hresult);
            }
        },

        // (5) virtual Core::hresult Capabilities(Exchange::IAudioStream::codectype&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const Exchange::IAudioStream* implementation = reinterpret_cast<const Exchange::IAudioStream*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::IAudioStream::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                Exchange::IAudioStream::codectype _caps{};

                Core::hresult result = implementation->Capabilities(_caps);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<Core::hresult>(result);
                writer.Number<Exchange::IAudioStream::codectype>(_caps);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(hresult);
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::IAudioStream::ID, 5, hresult);
            }
        },

        // (6) virtual Core::hresult Profile(const Exchange::IAudioStream::audioprofile&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                Exchange::IAudioStream* implementation = reinterpret_cast<Exchange::IAudioStream*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::IAudioStream::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                Exchange::IAudioStream::audioprofile _profile{};
                if (reader.Length() < (Core::RealSize<Exchange::IAudioStream::codectype>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                _profile.codec = reader.Number<Exchange::IAudioStream::codectype>();
                if (reader.Length() < (1)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                if (reader.Boolean() == true) {
                    if (reader.Length() < (1)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    const uint16_t _profile_codecParamsPeekedLen__ = reader.PeekNumber<uint16_t>();
                    if (reader.Length() < (static_cast<uint32_t>(1) + _profile_codecParamsPeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    _profile.codecParams = reader.Text();
                }
                if (reader.Length() < (Core::RealSize<uint8_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                _profile.channels = reader.Number<uint8_t>();
                if (reader.Length() < (Core::RealSize<uint8_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                _profile.resolution = reader.Number<uint8_t>();
                if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                _profile.sampleRate = reader.Number<uint32_t>();
                if (reader.Length() < (1)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                if (reader.Boolean() == true) {
                    if (reader.Length() < (1)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    _profile.bitRate = reader.Number<uint32_t>();
                }

                Core::hresult result = implementation->Profile(static_cast<const Exchange::IAudioStream::audioprofile&>(_profile));

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<Core::hresult>(result);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(hresult);
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::IAudioStream::ID, 6, hresult);
            }
        },

        // (7) virtual Core::hresult Profile(Exchange::IAudioStream::audioprofile&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const Exchange::IAudioStream* implementation = reinterpret_cast<const Exchange::IAudioStream*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::IAudioStream::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                Exchange::IAudioStream::audioprofile _profile{};

                Core::hresult result = implementation->Profile(_profile);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<Core::hresult>(result);
                writer.Number<Exchange::IAudioStream::codectype>(_profile.codec);
                writer.Boolean(_profile.codecParams.IsSet());
                if (_profile.codecParams.IsSet() == true) {
                    writer.Text(_profile.codecParams.Value());
                }
                writer.Number<uint8_t>(_profile.channels);
                writer.Number<uint8_t>(_profile.resolution);
                writer.Number<uint32_t>(_profile.sampleRate);
                writer.Boolean(_profile.bitRate.IsSet());
                if (_profile.bitRate.IsSet() == true) {
                    writer.Number<uint32_t>(_profile.bitRate.Value());
                }

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(hresult);
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::IAudioStream::ID, 7, hresult);
            }
        },

        // (8) virtual Core::hresult Time(uint32_t&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const Exchange::IAudioStream* implementation = reinterpret_cast<const Exchange::IAudioStream*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::IAudioStream::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                uint32_t _time{};

                Core::hresult result = implementation->Time(_time);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<Core::hresult>(result);
                writer.Number<uint32_t>(_time);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(hresult);
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::IAudioStream::ID, 8, hresult);
            }
        },

        // (9) virtual Core::hresult Speed(const uint8_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                Exchange::IAudioStream* implementation = reinterpret_cast<Exchange::IAudioStream*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::IAudioStream::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (Core::RealSize<uint8_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint8_t _speed = reader.Number<uint8_t>();

                Core::hresult result = implementation->Speed(_speed);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<Core::hresult>(result);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(hresult);
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::IAudioStream::ID, 9, hresult);
            }
        },

        // (10) virtual Core::hresult Speed(uint8_t&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const Exchange::IAudioStream* implementation = reinterpret_cast<const Exchange::IAudioStream*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::IAudioStream::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                uint8_t _speed{};

                Core::hresult result = implementation->Speed(_speed);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<Core::hresult>(result);
                writer.Number<uint8_t>(_speed);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(hresult);
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::IAudioStream::ID, 10, hresult);
            }
        }
        , nullptr
    }; // ExchangeAudioStreamStubMethods

    //
    // Exchange::IAudioStream::INotification interface stub definitions
    //
    // Methods:
    //  (0) virtual void StateChanged(const Exchange::IAudioStream::streamstate, const Core::OptionalType<Exchange::IAudioStream::audioprofile>&) = 0
    //

    static ProxyStub::MethodHandler ExchangeAudioStreamNotificationStubMethods[] = {
        // (0) virtual void StateChanged(const Exchange::IAudioStream::streamstate, const Core::OptionalType<Exchange::IAudioStream::audioprofile>&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                Exchange::IAudioStream::INotification* implementation = reinterpret_cast<Exchange::IAudioStream::INotification*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::IAudioStream::INotification::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (Core::RealSize<Exchange::IAudioStream::streamstate>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const Exchange::IAudioStream::streamstate _state = reader.Number<Exchange::IAudioStream::streamstate>();
                Core::OptionalType<Exchange::IAudioStream::audioprofile> _profile{};
                if (reader.Length() < (1)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                if (reader.Boolean() == true) {
                    Exchange::IAudioStream::audioprofile _profileObject__{};
                    if (reader.Length() < (Core::RealSize<Exchange::IAudioStream::codectype>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    _profileObject__.codec = reader.Number<Exchange::IAudioStream::codectype>();
                    if (reader.Length() < (1)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    if (reader.Boolean() == true) {
                        if (reader.Length() < (1)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                        const uint16_t _profileObject___codecParamsPeekedLen__ = reader.PeekNumber<uint16_t>();
                        if (reader.Length() < (static_cast<uint32_t>(1) + _profileObject___codecParamsPeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                        _profileObject__.codecParams = reader.Text();
                    }
                    if (reader.Length() < (Core::RealSize<uint8_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    _profileObject__.channels = reader.Number<uint8_t>();
                    if (reader.Length() < (Core::RealSize<uint8_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    _profileObject__.resolution = reader.Number<uint8_t>();
                    if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    _profileObject__.sampleRate = reader.Number<uint32_t>();
                    if (reader.Length() < (1)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    if (reader.Boolean() == true) {
                        if (reader.Length() < (1)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                        _profileObject__.bitRate = reader.Number<uint32_t>();
                    }
                    _profile = std::move(_profileObject__);
                }

                implementation->StateChanged(_state, static_cast<const Core::OptionalType<Exchange::IAudioStream::audioprofile>&>(_profile));

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::IAudioStream::INotification::ID, 0, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        }
        , nullptr
    }; // ExchangeAudioStreamNotificationStubMethods

    //
    // Exchange::IAudioStream::ICallback interface stub definitions
    //
    // Methods:
    //  (0) virtual void Data(const Core::OptionalType<uint16_t>&, const Core::OptionalType<uint32_t>&, const uint16_t, const uint8_t*) = 0
    //

    static ProxyStub::MethodHandler ExchangeAudioStreamCallbackStubMethods[] = {
        // (0) virtual void Data(const Core::OptionalType<uint16_t>&, const Core::OptionalType<uint32_t>&, const uint16_t, const uint8_t*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                Exchange::IAudioStream::ICallback* implementation = reinterpret_cast<Exchange::IAudioStream::ICallback*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::IAudioStream::ICallback::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                Core::OptionalType<uint16_t> _seq{};
                if (reader.Length() < (1)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                if (reader.Boolean() == true) {
                    if (reader.Length() < (1)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    _seq = reader.Number<uint16_t>();
                }
                Core::OptionalType<uint32_t> _timestamp{};
                if (reader.Length() < (1)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                if (reader.Boolean() == true) {
                    if (reader.Length() < (1)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    _timestamp = reader.Number<uint32_t>();
                }
                if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint16_t _dataPeekedLen__ = reader.PeekNumber<uint16_t>();
                if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint16_t>()) + _dataPeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint8_t* _data{};
                const uint16_t _length = reader.LockBuffer<uint16_t>(_data);
                reader.UnlockBuffer(_length);

                implementation->Data(static_cast<const Core::OptionalType<uint16_t>&>(_seq), static_cast<const Core::OptionalType<uint32_t>&>(_timestamp), _length, _data);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::IAudioStream::ICallback::ID, 0, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        }
        , nullptr
    }; // ExchangeAudioStreamCallbackStubMethods

    // -----------------------------------------------------------------
    // PROXIES
    // -----------------------------------------------------------------

    //
    // Exchange::IAudioStream interface proxy definitions
    //
    // Methods:
    //  (0) virtual Core::hresult Register(Exchange::IAudioStream::INotification* const) = 0
    //  (1) virtual Core::hresult Unregister(const Exchange::IAudioStream::INotification* const) = 0
    //  (2) virtual Core::hresult Callback(Exchange::IAudioStream::ICallback* const) = 0
    //  (3) virtual Core::hresult Name(string&) const = 0
    //  (4) virtual Core::hresult State(Exchange::IAudioStream::streamstate&) const = 0
    //  (5) virtual Core::hresult Capabilities(Exchange::IAudioStream::codectype&) const = 0
    //  (6) virtual Core::hresult Profile(const Exchange::IAudioStream::audioprofile&) = 0
    //  (7) virtual Core::hresult Profile(Exchange::IAudioStream::audioprofile&) const = 0
    //  (8) virtual Core::hresult Time(uint32_t&) const = 0
    //  (9) virtual Core::hresult Speed(const uint8_t) = 0
    //  (10) virtual Core::hresult Speed(uint8_t&) const = 0
    //

    class ExchangeAudioStreamProxy final : public ProxyStub::UnknownProxyType<Exchange::IAudioStream> {
    public:
        ExchangeAudioStreamProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        Core::hresult Register(Exchange::IAudioStream::INotification* const _notification) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_notification));

            const RPC::InstanceRecord passedInstances[] = { { RPC::instance_cast(_notification), Exchange::IAudioStream::INotification::ID }, { 0, 0 } };
            static_cast<const ProxyStub::UnknownProxy&>(*this).Channel()->CustomData(passedInstances);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<Core::hresult>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    hresult = reader.Number<Core::hresult>();

                    const uint32_t completeResult__ = _Complete(reader);
                    if (completeResult__ != Core::ERROR_NONE) { return (completeResult__); }

                    return (hresult);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::IAudioStream::ID, 0, hresult);
            }

            static_cast<const ProxyStub::UnknownProxy&>(*this).Channel()->CustomData(nullptr);

            return (hresult);
        }

        Core::hresult Unregister(const Exchange::IAudioStream::INotification* const _notification) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_notification));

            const RPC::InstanceRecord passedInstances[] = { { RPC::instance_cast(_notification), Exchange::IAudioStream::INotification::ID }, { 0, 0 } };
            static_cast<const ProxyStub::UnknownProxy&>(*this).Channel()->CustomData(passedInstances);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<Core::hresult>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    hresult = reader.Number<Core::hresult>();

                    const uint32_t completeResult__ = _Complete(reader);
                    if (completeResult__ != Core::ERROR_NONE) { return (completeResult__); }

                    return (hresult);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::IAudioStream::ID, 1, hresult);
            }

            static_cast<const ProxyStub::UnknownProxy&>(*this).Channel()->CustomData(nullptr);

            return (hresult);
        }

        Core::hresult Callback(Exchange::IAudioStream::ICallback* const _callback) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(2));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_callback));

            const RPC::InstanceRecord passedInstances[] = { { RPC::instance_cast(_callback), Exchange::IAudioStream::ICallback::ID }, { 0, 0 } };
            static_cast<const ProxyStub::UnknownProxy&>(*this).Channel()->CustomData(passedInstances);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<Core::hresult>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    hresult = reader.Number<Core::hresult>();

                    const uint32_t completeResult__ = _Complete(reader);
                    if (completeResult__ != Core::ERROR_NONE) { return (completeResult__); }

                    return (hresult);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::IAudioStream::ID, 2, hresult);
            }

            static_cast<const ProxyStub::UnknownProxy&>(*this).Channel()->CustomData(nullptr);

            return (hresult);
        }

        Core::hresult Name(string& _name) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(3));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<Core::hresult>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    hresult = reader.Number<Core::hresult>();
                    if ((hresult & COM_ERROR) == 0) {
                        if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                        const uint16_t _namePeekedLen__ = reader.PeekNumber<uint16_t>();
                        if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint16_t>()) + _namePeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                        _name = reader.Text();
                    }

                    return (hresult);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::IAudioStream::ID, 3, hresult);
            }

            return (hresult);
        }

        Core::hresult State(Exchange::IAudioStream::streamstate& _state) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(4));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<Core::hresult>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    hresult = reader.Number<Core::hresult>();
                    if ((hresult & COM_ERROR) == 0) {
                        if (reader.Length() < (Core::RealSize<Exchange::IAudioStream::streamstate>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                        _state = reader.Number<Exchange::IAudioStream::streamstate>();
                    }

                    return (hresult);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::IAudioStream::ID, 4, hresult);
            }

            return (hresult);
        }

        Core::hresult Capabilities(Exchange::IAudioStream::codectype& _caps) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(5));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<Core::hresult>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    hresult = reader.Number<Core::hresult>();
                    if ((hresult & COM_ERROR) == 0) {
                        if (reader.Length() < (Core::RealSize<Exchange::IAudioStream::codectype>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                        _caps = reader.Number<Exchange::IAudioStream::codectype>();
                    }

                    return (hresult);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::IAudioStream::ID, 5, hresult);
            }

            return (hresult);
        }

        Core::hresult Profile(const Exchange::IAudioStream::audioprofile& _profile) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(6));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Exchange::IAudioStream::codectype>(_profile.codec);
            writer.Boolean(_profile.codecParams.IsSet());
            if (_profile.codecParams.IsSet() == true) {
                writer.Text(_profile.codecParams.Value());
            }
            writer.Number<uint8_t>(_profile.channels);
            writer.Number<uint8_t>(_profile.resolution);
            writer.Number<uint32_t>(_profile.sampleRate);
            writer.Boolean(_profile.bitRate.IsSet());
            if (_profile.bitRate.IsSet() == true) {
                writer.Number<uint32_t>(_profile.bitRate.Value());
            }

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
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::IAudioStream::ID, 6, hresult);
            }

            return (hresult);
        }

        Core::hresult Profile(Exchange::IAudioStream::audioprofile& _profile) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(7));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<Core::hresult>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    hresult = reader.Number<Core::hresult>();
                    if ((hresult & COM_ERROR) == 0) {
                        if (reader.Length() < (Core::RealSize<Exchange::IAudioStream::codectype>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                        _profile.codec = reader.Number<Exchange::IAudioStream::codectype>();
                        if (reader.Length() < (1)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                        if (reader.Boolean() == true) {
                            if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                            const uint16_t _profile_codecParamsPeekedLen__ = reader.PeekNumber<uint16_t>();
                            if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint16_t>()) + _profile_codecParamsPeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                            _profile.codecParams = reader.Text();
                        }
                        if (reader.Length() < (Core::RealSize<uint8_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                        _profile.channels = reader.Number<uint8_t>();
                        if (reader.Length() < (Core::RealSize<uint8_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                        _profile.resolution = reader.Number<uint8_t>();
                        if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                        _profile.sampleRate = reader.Number<uint32_t>();
                        if (reader.Length() < (1)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                        if (reader.Boolean() == true) {
                            if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                            _profile.bitRate = reader.Number<uint32_t>();
                        }
                    }

                    return (hresult);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::IAudioStream::ID, 7, hresult);
            }

            return (hresult);
        }

        Core::hresult Time(uint32_t& _time) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(8));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<Core::hresult>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    hresult = reader.Number<Core::hresult>();
                    if ((hresult & COM_ERROR) == 0) {
                        if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                        _time = reader.Number<uint32_t>();
                    }

                    return (hresult);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::IAudioStream::ID, 8, hresult);
            }

            return (hresult);
        }

        Core::hresult Speed(const uint8_t _speed) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(9));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint8_t>(_speed);

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
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::IAudioStream::ID, 9, hresult);
            }

            return (hresult);
        }

        Core::hresult Speed(uint8_t& _speed) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(10));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<Core::hresult>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    hresult = reader.Number<Core::hresult>();
                    if ((hresult & COM_ERROR) == 0) {
                        if (reader.Length() < (Core::RealSize<uint8_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                        _speed = reader.Number<uint8_t>();
                    }

                    return (hresult);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::IAudioStream::ID, 10, hresult);
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

    }; // class ExchangeAudioStreamProxy

    //
    // Exchange::IAudioStream::INotification interface proxy definitions
    //
    // Methods:
    //  (0) virtual void StateChanged(const Exchange::IAudioStream::streamstate, const Core::OptionalType<Exchange::IAudioStream::audioprofile>&) = 0
    //

    class ExchangeAudioStreamNotificationProxy final : public ProxyStub::UnknownProxyType<Exchange::IAudioStream::INotification> {
    public:
        ExchangeAudioStreamNotificationProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        void StateChanged(const Exchange::IAudioStream::streamstate _state, const Core::OptionalType<Exchange::IAudioStream::audioprofile>& _profile) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Exchange::IAudioStream::streamstate>(_state);
            writer.Boolean(_profile.IsSet());
            if (_profile.IsSet() == true) {
                writer.Number<Exchange::IAudioStream::codectype>(_profile.Value().codec);
                writer.Boolean(_profile.Value().codecParams.IsSet());
                if (_profile.Value().codecParams.IsSet() == true) {
                    writer.Text(_profile.Value().codecParams.Value());
                }
                writer.Number<uint8_t>(_profile.Value().channels);
                writer.Number<uint8_t>(_profile.Value().resolution);
                writer.Number<uint32_t>(_profile.Value().sampleRate);
                writer.Boolean(_profile.Value().bitRate.IsSet());
                if (_profile.Value().bitRate.IsSet() == true) {
                    writer.Number<uint32_t>(_profile.Value().bitRate.Value());
                }
            }

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::IAudioStream::INotification::ID, 0, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        }

    }; // class ExchangeAudioStreamNotificationProxy

    //
    // Exchange::IAudioStream::ICallback interface proxy definitions
    //
    // Methods:
    //  (0) virtual void Data(const Core::OptionalType<uint16_t>&, const Core::OptionalType<uint32_t>&, const uint16_t, const uint8_t*) = 0
    //

    class ExchangeAudioStreamCallbackProxy final : public ProxyStub::UnknownProxyType<Exchange::IAudioStream::ICallback> {
    public:
        ExchangeAudioStreamCallbackProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        void Data(const Core::OptionalType<uint16_t>& _seq, const Core::OptionalType<uint32_t>& _timestamp, const uint16_t _length, const uint8_t* _data) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Boolean(_seq.IsSet());
            if (_seq.IsSet() == true) {
                writer.Number<uint16_t>(_seq.Value());
            }
            writer.Boolean(_timestamp.IsSet());
            if (_timestamp.IsSet() == true) {
                writer.Number<uint32_t>(_timestamp.Value());
            }
            writer.Buffer<uint16_t>(_length, _data);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::IAudioStream::ICallback::ID, 0, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        }

    }; // class ExchangeAudioStreamCallbackProxy

    POP_WARNING()
    POP_WARNING()

    // -----------------------------------------------------------------
    // REGISTRATION
    // -----------------------------------------------------------------
    namespace {

        typedef ProxyStub::UnknownStubType<Exchange::IAudioStream, ExchangeAudioStreamStubMethods> ExchangeAudioStreamStub;
        typedef ProxyStub::UnknownStubType<Exchange::IAudioStream::INotification, ExchangeAudioStreamNotificationStubMethods> ExchangeAudioStreamNotificationStub;
        typedef ProxyStub::UnknownStubType<Exchange::IAudioStream::ICallback, ExchangeAudioStreamCallbackStubMethods> ExchangeAudioStreamCallbackStub;

        static class Instantiation {
        public:
            Instantiation()
            {
                const RPC::SecureProxyStubType security = static_cast<RPC::SecureProxyStubType>(static_cast<std::underlying_type<RPC::SecureProxyStubType>::type>(RPC::SecureProxyStubType::PROXYSTUBS_SECURITY_SECURE) | static_cast<std::underlying_type<RPC::SecureProxyStubType>::type>(RPC::SecureProxyStubType::PROXYSTUBS_SECURITY_COHERENT));

                RPC::Administrator::Instance().Announce<Exchange::IAudioStream, ExchangeAudioStreamProxy, ExchangeAudioStreamStub>(security);
                RPC::Administrator::Instance().Announce<Exchange::IAudioStream::INotification, ExchangeAudioStreamNotificationProxy, ExchangeAudioStreamNotificationStub>(security);
                RPC::Administrator::Instance().Announce<Exchange::IAudioStream::ICallback, ExchangeAudioStreamCallbackProxy, ExchangeAudioStreamCallbackStub>(security);
            }
            ~Instantiation()
            {
                RPC::Administrator::Instance().Recall<Exchange::IAudioStream>();
                RPC::Administrator::Instance().Recall<Exchange::IAudioStream::INotification>();
                RPC::Administrator::Instance().Recall<Exchange::IAudioStream::ICallback>();
            }
        } ProxyStubRegistration;

    } // namespace

} // namespace ProxyStubs

}
