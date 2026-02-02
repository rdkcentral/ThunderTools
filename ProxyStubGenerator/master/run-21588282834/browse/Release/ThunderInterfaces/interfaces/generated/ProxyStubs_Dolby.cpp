//
// generated automatically from "IDolby.h"
//
// implements COM-RPC proxy stubs for:
//   - class Exchange::Dolby::IOutput
//   - class Exchange::Dolby::IOutput::INotification
//
// secure code enabled:
//   - instance verification enabled
//   - range verification enabled
//   - frame coherency verification enabled
//

#include "Module.h"
#include "IDolby.h"

#include <com/com.h>

namespace Thunder {

namespace ProxyStubs {

    PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    // -----------------------------------------------------------------
    // STUBS
    // -----------------------------------------------------------------

    //
    // Exchange::Dolby::IOutput interface stub definitions
    //
    // Methods:
    //  (0) virtual uint32_t Register(Exchange::Dolby::IOutput::INotification*) = 0
    //  (1) virtual uint32_t Unregister(Exchange::Dolby::IOutput::INotification*) = 0
    //  (2) virtual uint32_t AtmosMetadata(bool&) const = 0
    //  (3) virtual uint32_t SoundMode(Exchange::Dolby::IOutput::SoundModes&) const = 0
    //  (4) virtual uint32_t EnableAtmosOutput(const bool) = 0
    //  (5) virtual uint32_t Mode(const Exchange::Dolby::IOutput::Type&) = 0
    //  (6) virtual uint32_t Mode(Exchange::Dolby::IOutput::Type&) const = 0
    //

    static ProxyStub::MethodHandler ExchangeDolbyOutputStubMethods[] = {
        // (0) virtual uint32_t Register(Exchange::Dolby::IOutput::INotification*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                Exchange::Dolby::IOutput* implementation = reinterpret_cast<Exchange::Dolby::IOutput*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::Dolby::IOutput::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (sizeof(Core::instance_id))) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                Core::instance_id _parameter_435db997InstanceId__ = reader.Number<Core::instance_id>();

                Exchange::Dolby::IOutput::INotification* _parameter_435db997{};
                ProxyStub::UnknownProxy* _parameter_435db997Proxy__ = nullptr;
                if (_parameter_435db997InstanceId__ != 0) {
                    _parameter_435db997Proxy__ = RPC::Administrator::Instance().ProxyInstance(channel, _parameter_435db997InstanceId__, false, _parameter_435db997);
                    ASSERT((_parameter_435db997 != nullptr) && (_parameter_435db997Proxy__ != nullptr));
                    if ((_parameter_435db997 == nullptr) || (_parameter_435db997Proxy__ == nullptr)) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }
                }

                uint32_t result = implementation->Register(_parameter_435db997);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(result);

                if (_parameter_435db997Proxy__ != nullptr) {
                    RPC::Administrator::Instance().Release(_parameter_435db997Proxy__, message->Response());
                }

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(hresult);
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::Dolby::IOutput::ID, 0, hresult);
            }
        },

        // (1) virtual uint32_t Unregister(Exchange::Dolby::IOutput::INotification*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                Exchange::Dolby::IOutput* implementation = reinterpret_cast<Exchange::Dolby::IOutput*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::Dolby::IOutput::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (sizeof(Core::instance_id))) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                Core::instance_id _parameter_74f9f2dcInstanceId__ = reader.Number<Core::instance_id>();

                Exchange::Dolby::IOutput::INotification* _parameter_74f9f2dc{};
                ProxyStub::UnknownProxy* _parameter_74f9f2dcProxy__ = nullptr;
                if (_parameter_74f9f2dcInstanceId__ != 0) {
                    _parameter_74f9f2dcProxy__ = RPC::Administrator::Instance().ProxyInstance(channel, _parameter_74f9f2dcInstanceId__, false, _parameter_74f9f2dc);
                    ASSERT((_parameter_74f9f2dc != nullptr) && (_parameter_74f9f2dcProxy__ != nullptr));
                    if ((_parameter_74f9f2dc == nullptr) || (_parameter_74f9f2dcProxy__ == nullptr)) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }
                }

                uint32_t result = implementation->Unregister(_parameter_74f9f2dc);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(result);

                if (_parameter_74f9f2dcProxy__ != nullptr) {
                    RPC::Administrator::Instance().Release(_parameter_74f9f2dcProxy__, message->Response());
                }

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(hresult);
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::Dolby::IOutput::ID, 1, hresult);
            }
        },

        // (2) virtual uint32_t AtmosMetadata(bool&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const Exchange::Dolby::IOutput* implementation = reinterpret_cast<const Exchange::Dolby::IOutput*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::Dolby::IOutput::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                bool _supported{};

                uint32_t result = implementation->AtmosMetadata(_supported);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(result);
                writer.Boolean(_supported);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(hresult);
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::Dolby::IOutput::ID, 2, hresult);
            }
        },

        // (3) virtual uint32_t SoundMode(Exchange::Dolby::IOutput::SoundModes&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const Exchange::Dolby::IOutput* implementation = reinterpret_cast<const Exchange::Dolby::IOutput*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::Dolby::IOutput::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                Exchange::Dolby::IOutput::SoundModes _mode{};

                uint32_t result = implementation->SoundMode(_mode);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(result);
                writer.Number<Exchange::Dolby::IOutput::SoundModes>(_mode);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(hresult);
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::Dolby::IOutput::ID, 3, hresult);
            }
        },

        // (4) virtual uint32_t EnableAtmosOutput(const bool) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                Exchange::Dolby::IOutput* implementation = reinterpret_cast<Exchange::Dolby::IOutput*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::Dolby::IOutput::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (1)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const bool _enable = reader.Boolean();

                uint32_t result = implementation->EnableAtmosOutput(_enable);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(result);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(hresult);
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::Dolby::IOutput::ID, 4, hresult);
            }
        },

        // (5) virtual uint32_t Mode(const Exchange::Dolby::IOutput::Type&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                Exchange::Dolby::IOutput* implementation = reinterpret_cast<Exchange::Dolby::IOutput*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::Dolby::IOutput::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (Core::RealSize<Exchange::Dolby::IOutput::Type>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const Exchange::Dolby::IOutput::Type _mode = reader.Number<Exchange::Dolby::IOutput::Type>();

                uint32_t result = implementation->Mode(static_cast<const Exchange::Dolby::IOutput::Type&>(_mode));

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(result);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(hresult);
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::Dolby::IOutput::ID, 5, hresult);
            }
        },

        // (6) virtual uint32_t Mode(Exchange::Dolby::IOutput::Type&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const Exchange::Dolby::IOutput* implementation = reinterpret_cast<const Exchange::Dolby::IOutput*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::Dolby::IOutput::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                Exchange::Dolby::IOutput::Type _mode{};

                uint32_t result = implementation->Mode(_mode);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(result);
                writer.Number<Exchange::Dolby::IOutput::Type>(_mode);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(hresult);
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::Dolby::IOutput::ID, 6, hresult);
            }
        }
        , nullptr
    }; // ExchangeDolbyOutputStubMethods

    //
    // Exchange::Dolby::IOutput::INotification interface stub definitions
    //
    // Methods:
    //  (0) virtual void AudioModeChanged(const Exchange::Dolby::IOutput::SoundModes, const bool) = 0
    //

    static ProxyStub::MethodHandler ExchangeDolbyOutputNotificationStubMethods[] = {
        // (0) virtual void AudioModeChanged(const Exchange::Dolby::IOutput::SoundModes, const bool) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                Exchange::Dolby::IOutput::INotification* implementation = reinterpret_cast<Exchange::Dolby::IOutput::INotification*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::Dolby::IOutput::INotification::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (Core::RealSize<Exchange::Dolby::IOutput::SoundModes>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const Exchange::Dolby::IOutput::SoundModes _mode = reader.Number<Exchange::Dolby::IOutput::SoundModes>();
                if (reader.Length() < (1)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const bool _enabled = reader.Boolean();

                implementation->AudioModeChanged(_mode, _enabled);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::Dolby::IOutput::INotification::ID, 0, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        }
        , nullptr
    }; // ExchangeDolbyOutputNotificationStubMethods

    // -----------------------------------------------------------------
    // PROXIES
    // -----------------------------------------------------------------

    //
    // Exchange::Dolby::IOutput interface proxy definitions
    //
    // Methods:
    //  (0) virtual uint32_t Register(Exchange::Dolby::IOutput::INotification*) = 0
    //  (1) virtual uint32_t Unregister(Exchange::Dolby::IOutput::INotification*) = 0
    //  (2) virtual uint32_t AtmosMetadata(bool&) const = 0
    //  (3) virtual uint32_t SoundMode(Exchange::Dolby::IOutput::SoundModes&) const = 0
    //  (4) virtual uint32_t EnableAtmosOutput(const bool) = 0
    //  (5) virtual uint32_t Mode(const Exchange::Dolby::IOutput::Type&) = 0
    //  (6) virtual uint32_t Mode(Exchange::Dolby::IOutput::Type&) const = 0
    //

    class ExchangeDolbyOutputProxy final : public ProxyStub::UnknownProxyType<Exchange::Dolby::IOutput> {
    public:
        ExchangeDolbyOutputProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        uint32_t Register(Exchange::Dolby::IOutput::INotification* _parameter_435db997) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_parameter_435db997));

            const RPC::InstanceRecord passedInstances[] = { { RPC::instance_cast(_parameter_435db997), Exchange::Dolby::IOutput::INotification::ID }, { 0, 0 } };
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
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::Dolby::IOutput::ID, 0, hresult);
            }

            static_cast<const ProxyStub::UnknownProxy&>(*this).Channel()->CustomData(nullptr);

            return (hresult);
        }

        uint32_t Unregister(Exchange::Dolby::IOutput::INotification* _parameter_74f9f2dc) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_parameter_74f9f2dc));

            const RPC::InstanceRecord passedInstances[] = { { RPC::instance_cast(_parameter_74f9f2dc), Exchange::Dolby::IOutput::INotification::ID }, { 0, 0 } };
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
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::Dolby::IOutput::ID, 1, hresult);
            }

            static_cast<const ProxyStub::UnknownProxy&>(*this).Channel()->CustomData(nullptr);

            return (hresult);
        }

        uint32_t AtmosMetadata(bool& _supported) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(2));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    hresult = reader.Number<uint32_t>();
                    if ((hresult & COM_ERROR) == 0) {
                        if (reader.Length() < (1)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                        _supported = reader.Boolean();
                    }

                    return (hresult);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::Dolby::IOutput::ID, 2, hresult);
            }

            return (hresult);
        }

        uint32_t SoundMode(Exchange::Dolby::IOutput::SoundModes& _mode) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(3));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    hresult = reader.Number<uint32_t>();
                    if ((hresult & COM_ERROR) == 0) {
                        if (reader.Length() < (Core::RealSize<Exchange::Dolby::IOutput::SoundModes>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                        _mode = reader.Number<Exchange::Dolby::IOutput::SoundModes>();
                    }

                    return (hresult);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::Dolby::IOutput::ID, 3, hresult);
            }

            return (hresult);
        }

        uint32_t EnableAtmosOutput(const bool _enable) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(4));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Boolean(_enable);

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
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::Dolby::IOutput::ID, 4, hresult);
            }

            return (hresult);
        }

        uint32_t Mode(const Exchange::Dolby::IOutput::Type& _mode) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(5));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Exchange::Dolby::IOutput::Type>(_mode);

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
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::Dolby::IOutput::ID, 5, hresult);
            }

            return (hresult);
        }

        uint32_t Mode(Exchange::Dolby::IOutput::Type& _mode) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(6));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    hresult = reader.Number<uint32_t>();
                    if ((hresult & COM_ERROR) == 0) {
                        if (reader.Length() < (Core::RealSize<Exchange::Dolby::IOutput::Type>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                        _mode = reader.Number<Exchange::Dolby::IOutput::Type>();
                    }

                    return (hresult);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::Dolby::IOutput::ID, 6, hresult);
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

    }; // class ExchangeDolbyOutputProxy

    //
    // Exchange::Dolby::IOutput::INotification interface proxy definitions
    //
    // Methods:
    //  (0) virtual void AudioModeChanged(const Exchange::Dolby::IOutput::SoundModes, const bool) = 0
    //

    class ExchangeDolbyOutputNotificationProxy final : public ProxyStub::UnknownProxyType<Exchange::Dolby::IOutput::INotification> {
    public:
        ExchangeDolbyOutputNotificationProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        void AudioModeChanged(const Exchange::Dolby::IOutput::SoundModes _mode, const bool _enabled) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Exchange::Dolby::IOutput::SoundModes>(_mode);
            writer.Boolean(_enabled);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::Dolby::IOutput::INotification::ID, 0, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        }

    }; // class ExchangeDolbyOutputNotificationProxy

    POP_WARNING()
    POP_WARNING()

    // -----------------------------------------------------------------
    // REGISTRATION
    // -----------------------------------------------------------------
    namespace {

        typedef ProxyStub::UnknownStubType<Exchange::Dolby::IOutput, ExchangeDolbyOutputStubMethods> ExchangeDolbyOutputStub;
        typedef ProxyStub::UnknownStubType<Exchange::Dolby::IOutput::INotification, ExchangeDolbyOutputNotificationStubMethods> ExchangeDolbyOutputNotificationStub;

        static class Instantiation {
        public:
            Instantiation()
            {
                const RPC::SecureProxyStubType security = static_cast<RPC::SecureProxyStubType>(static_cast<std::underlying_type<RPC::SecureProxyStubType>::type>(RPC::SecureProxyStubType::PROXYSTUBS_SECURITY_SECURE) | static_cast<std::underlying_type<RPC::SecureProxyStubType>::type>(RPC::SecureProxyStubType::PROXYSTUBS_SECURITY_COHERENT));

                RPC::Administrator::Instance().Announce<Exchange::Dolby::IOutput, ExchangeDolbyOutputProxy, ExchangeDolbyOutputStub>(security);
                RPC::Administrator::Instance().Announce<Exchange::Dolby::IOutput::INotification, ExchangeDolbyOutputNotificationProxy, ExchangeDolbyOutputNotificationStub>(security);
            }
            ~Instantiation()
            {
                RPC::Administrator::Instance().Recall<Exchange::Dolby::IOutput>();
                RPC::Administrator::Instance().Recall<Exchange::Dolby::IOutput::INotification>();
            }
        } ProxyStubRegistration;

    } // namespace

} // namespace ProxyStubs

}
