//
// generated automatically from "IWatermark.h"
//
// implements COM-RPC proxy stubs for:
//   - class Exchange::IWatermark
//   - class Exchange::IWatermark::INotification
//
// secure code enabled:
//   - instance verification enabled
//   - range verification enabled
//   - frame coherency verification enabled
//

#include "Module.h"
#include "IWatermark.h"

#include <com/com.h>

namespace Thunder {

namespace ProxyStubs {

    PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    // -----------------------------------------------------------------
    // STUBS
    // -----------------------------------------------------------------

    //
    // Exchange::IWatermark interface stub definitions
    //
    // Methods:
    //  (0) virtual uint32_t Initialize(string, bool) = 0
    //  (1) virtual uint32_t Deinitialize() = 0
    //  (2) virtual uint32_t Register(Exchange::IWatermark::INotification*) = 0
    //  (3) virtual uint32_t Unregister(Exchange::IWatermark::INotification*) = 0
    //  (4) virtual bool ShowWatermark(const bool) = 0
    //  (5) virtual bool CreateWatermark(uint32_t, uint32_t) = 0
    //  (6) virtual bool UpdateWatermark(uint32_t, uint32_t, uint32_t) = 0
    //  (7) virtual bool AdjustWatermark(uint32_t, uint32_t) = 0
    //  (8) virtual bool DeleteWatermark(uint32_t) = 0
    //  (9) virtual Exchange::PalettedImageData GetPalettedWatermark(uint32_t) = 0
    //  (10) virtual bool ModifyPalettedWatermark(uint32_t, Exchange::PalettedImageData) = 0
    //

    static ProxyStub::MethodHandler ExchangeWatermarkStubMethods[] = {
        // (0) virtual uint32_t Initialize(string, bool) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                Exchange::IWatermark* implementation = reinterpret_cast<Exchange::IWatermark*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::IWatermark::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint16_t _waylandDisplayPeekedLen__ = reader.PeekNumber<uint16_t>();
                if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint16_t>()) + _waylandDisplayPeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                string _waylandDisplay = reader.Text();
                if (reader.Length() < (1)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                bool _synchronized = reader.Boolean();

                uint32_t result = implementation->Initialize(_waylandDisplay, _synchronized);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(result);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::IWatermark::ID, 0, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        },

        // (1) virtual uint32_t Deinitialize() = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                Exchange::IWatermark* implementation = reinterpret_cast<Exchange::IWatermark*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::IWatermark::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                uint32_t result = implementation->Deinitialize();

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(result);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::IWatermark::ID, 1, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        },

        // (2) virtual uint32_t Register(Exchange::IWatermark::INotification*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                Exchange::IWatermark* implementation = reinterpret_cast<Exchange::IWatermark*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::IWatermark::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (sizeof(Core::instance_id))) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                Core::instance_id _notificationInstanceId__ = reader.Number<Core::instance_id>();

                Exchange::IWatermark::INotification* _notification{};
                ProxyStub::UnknownProxy* _notificationProxy__ = nullptr;
                if (_notificationInstanceId__ != 0) {
                    _notificationProxy__ = RPC::Administrator::Instance().ProxyInstance(channel, _notificationInstanceId__, false, _notification);
                    ASSERT((_notification != nullptr) && (_notificationProxy__ != nullptr));
                    if ((_notification == nullptr) || (_notificationProxy__ == nullptr)) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }
                }

                uint32_t result = implementation->Register(_notification);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(result);

                if (_notificationProxy__ != nullptr) {
                    RPC::Administrator::Instance().Release(_notificationProxy__, message->Response());
                }

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::IWatermark::ID, 2, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        },

        // (3) virtual uint32_t Unregister(Exchange::IWatermark::INotification*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                Exchange::IWatermark* implementation = reinterpret_cast<Exchange::IWatermark*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::IWatermark::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (sizeof(Core::instance_id))) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                Core::instance_id _notificationInstanceId__ = reader.Number<Core::instance_id>();

                Exchange::IWatermark::INotification* _notification{};
                ProxyStub::UnknownProxy* _notificationProxy__ = nullptr;
                if (_notificationInstanceId__ != 0) {
                    _notificationProxy__ = RPC::Administrator::Instance().ProxyInstance(channel, _notificationInstanceId__, false, _notification);
                    ASSERT((_notification != nullptr) && (_notificationProxy__ != nullptr));
                    if ((_notification == nullptr) || (_notificationProxy__ == nullptr)) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }
                }

                uint32_t result = implementation->Unregister(_notification);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(result);

                if (_notificationProxy__ != nullptr) {
                    RPC::Administrator::Instance().Release(_notificationProxy__, message->Response());
                }

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::IWatermark::ID, 3, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        },

        // (4) virtual bool ShowWatermark(const bool) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                Exchange::IWatermark* implementation = reinterpret_cast<Exchange::IWatermark*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::IWatermark::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (1)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const bool _show = reader.Boolean();

                bool result = implementation->ShowWatermark(_show);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Boolean(result);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::IWatermark::ID, 4, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        },

        // (5) virtual bool CreateWatermark(uint32_t, uint32_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                Exchange::IWatermark* implementation = reinterpret_cast<Exchange::IWatermark*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::IWatermark::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                uint32_t _id = reader.Number<uint32_t>();
                if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                uint32_t _zorder = reader.Number<uint32_t>();

                bool result = implementation->CreateWatermark(_id, _zorder);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Boolean(result);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::IWatermark::ID, 5, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        },

        // (6) virtual bool UpdateWatermark(uint32_t, uint32_t, uint32_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                Exchange::IWatermark* implementation = reinterpret_cast<Exchange::IWatermark*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::IWatermark::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                uint32_t _id = reader.Number<uint32_t>();
                if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                uint32_t _key = reader.Number<uint32_t>();
                if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                uint32_t _size = reader.Number<uint32_t>();

                bool result = implementation->UpdateWatermark(_id, _key, _size);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Boolean(result);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::IWatermark::ID, 6, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        },

        // (7) virtual bool AdjustWatermark(uint32_t, uint32_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                Exchange::IWatermark* implementation = reinterpret_cast<Exchange::IWatermark*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::IWatermark::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                uint32_t _id = reader.Number<uint32_t>();
                if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                uint32_t _zorder = reader.Number<uint32_t>();

                bool result = implementation->AdjustWatermark(_id, _zorder);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Boolean(result);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::IWatermark::ID, 7, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        },

        // (8) virtual bool DeleteWatermark(uint32_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                Exchange::IWatermark* implementation = reinterpret_cast<Exchange::IWatermark*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::IWatermark::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                uint32_t _id = reader.Number<uint32_t>();

                bool result = implementation->DeleteWatermark(_id);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Boolean(result);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::IWatermark::ID, 8, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        },

        // (9) virtual Exchange::PalettedImageData GetPalettedWatermark(uint32_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                Exchange::IWatermark* implementation = reinterpret_cast<Exchange::IWatermark*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::IWatermark::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                uint32_t _id = reader.Number<uint32_t>();

                Exchange::PalettedImageData result = implementation->GetPalettedWatermark(_id);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(result.imageKey);
                writer.Number<uint32_t>(result.imageWidth);
                writer.Number<uint32_t>(result.imageHeight);
                writer.Number<uint32_t>(result.clutKey);
                writer.Number<uint32_t>(result.clutSize);
                writer.Text(result.clutType);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::IWatermark::ID, 9, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        },

        // (10) virtual bool ModifyPalettedWatermark(uint32_t, Exchange::PalettedImageData) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                Exchange::IWatermark* implementation = reinterpret_cast<Exchange::IWatermark*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::IWatermark::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                uint32_t _id = reader.Number<uint32_t>();
                Exchange::PalettedImageData _data{};
                if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                _data.imageKey = reader.Number<uint32_t>();
                if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                _data.imageWidth = reader.Number<uint32_t>();
                if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                _data.imageHeight = reader.Number<uint32_t>();
                if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                _data.clutKey = reader.Number<uint32_t>();
                if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                _data.clutSize = reader.Number<uint32_t>();
                if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint16_t _data_clutTypePeekedLen__ = reader.PeekNumber<uint16_t>();
                if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint16_t>()) + _data_clutTypePeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                _data.clutType = reader.Text();

                bool result = implementation->ModifyPalettedWatermark(_id, _data);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Boolean(result);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::IWatermark::ID, 10, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        }
        , nullptr
    }; // ExchangeWatermarkStubMethods

    //
    // Exchange::IWatermark::INotification interface stub definitions
    //
    // Methods:
    //  (0) virtual void WatermarkEvent(const string&, const string&) = 0
    //

    static ProxyStub::MethodHandler ExchangeWatermarkNotificationStubMethods[] = {
        // (0) virtual void WatermarkEvent(const string&, const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                Exchange::IWatermark::INotification* implementation = reinterpret_cast<Exchange::IWatermark::INotification*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::IWatermark::INotification::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint16_t _eventNamePeekedLen__ = reader.PeekNumber<uint16_t>();
                if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint16_t>()) + _eventNamePeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const string _eventName = reader.Text();
                if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint16_t _parametersJsonPeekedLen__ = reader.PeekNumber<uint16_t>();
                if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint16_t>()) + _parametersJsonPeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const string _parametersJson = reader.Text();

                implementation->WatermarkEvent(static_cast<const string&>(_eventName), static_cast<const string&>(_parametersJson));

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::IWatermark::INotification::ID, 0, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        }
        , nullptr
    }; // ExchangeWatermarkNotificationStubMethods

    // -----------------------------------------------------------------
    // PROXIES
    // -----------------------------------------------------------------

    //
    // Exchange::IWatermark interface proxy definitions
    //
    // Methods:
    //  (0) virtual uint32_t Initialize(string, bool) = 0
    //  (1) virtual uint32_t Deinitialize() = 0
    //  (2) virtual uint32_t Register(Exchange::IWatermark::INotification*) = 0
    //  (3) virtual uint32_t Unregister(Exchange::IWatermark::INotification*) = 0
    //  (4) virtual bool ShowWatermark(const bool) = 0
    //  (5) virtual bool CreateWatermark(uint32_t, uint32_t) = 0
    //  (6) virtual bool UpdateWatermark(uint32_t, uint32_t, uint32_t) = 0
    //  (7) virtual bool AdjustWatermark(uint32_t, uint32_t) = 0
    //  (8) virtual bool DeleteWatermark(uint32_t) = 0
    //  (9) virtual Exchange::PalettedImageData GetPalettedWatermark(uint32_t) = 0
    //  (10) virtual bool ModifyPalettedWatermark(uint32_t, Exchange::PalettedImageData) = 0
    //

    class ExchangeWatermarkProxy final : public ProxyStub::UnknownProxyType<Exchange::IWatermark> {
    public:
        ExchangeWatermarkProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        uint32_t Initialize(string _waylandDisplay, bool _synchronized) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_waylandDisplay);
            writer.Boolean(_synchronized);

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
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::IWatermark::ID, 0, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }

            return (result);
        }

        uint32_t Deinitialize() override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

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
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::IWatermark::ID, 1, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }

            return (result);
        }

        uint32_t Register(Exchange::IWatermark::INotification* _notification) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(2));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_notification));

            const RPC::InstanceRecord passedInstances[] = { { RPC::instance_cast(_notification), Exchange::IWatermark::INotification::ID }, { 0, 0 } };
            static_cast<const ProxyStub::UnknownProxy&>(*this).Channel()->CustomData(passedInstances);

            uint32_t result{};

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    result = reader.Number<uint32_t>();

                    const uint32_t completeResult__ = _Complete(reader);
                    if (completeResult__ != Core::ERROR_NONE) { return (completeResult__); }

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::IWatermark::ID, 2, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }

            static_cast<const ProxyStub::UnknownProxy&>(*this).Channel()->CustomData(nullptr);

            return (result);
        }

        uint32_t Unregister(Exchange::IWatermark::INotification* _notification) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(3));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_notification));

            const RPC::InstanceRecord passedInstances[] = { { RPC::instance_cast(_notification), Exchange::IWatermark::INotification::ID }, { 0, 0 } };
            static_cast<const ProxyStub::UnknownProxy&>(*this).Channel()->CustomData(passedInstances);

            uint32_t result{};

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    result = reader.Number<uint32_t>();

                    const uint32_t completeResult__ = _Complete(reader);
                    if (completeResult__ != Core::ERROR_NONE) { return (completeResult__); }

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::IWatermark::ID, 3, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }

            static_cast<const ProxyStub::UnknownProxy&>(*this).Channel()->CustomData(nullptr);

            return (result);
        }

        bool ShowWatermark(const bool _show) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(4));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Boolean(_show);

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
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::IWatermark::ID, 4, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }

            return (result);
        }

        bool CreateWatermark(uint32_t _id, uint32_t _zorder) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(5));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_id);
            writer.Number<uint32_t>(_zorder);

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
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::IWatermark::ID, 5, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }

            return (result);
        }

        bool UpdateWatermark(uint32_t _id, uint32_t _key, uint32_t _size) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(6));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_id);
            writer.Number<uint32_t>(_key);
            writer.Number<uint32_t>(_size);

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
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::IWatermark::ID, 6, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }

            return (result);
        }

        bool AdjustWatermark(uint32_t _id, uint32_t _zorder) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(7));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_id);
            writer.Number<uint32_t>(_zorder);

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
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::IWatermark::ID, 7, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }

            return (result);
        }

        bool DeleteWatermark(uint32_t _id) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(8));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_id);

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
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::IWatermark::ID, 8, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }

            return (result);
        }

        Exchange::PalettedImageData GetPalettedWatermark(uint32_t _id) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(9));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_id);

            Exchange::PalettedImageData result{};

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    result.imageKey = reader.Number<uint32_t>();
                    if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    result.imageWidth = reader.Number<uint32_t>();
                    if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    result.imageHeight = reader.Number<uint32_t>();
                    if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    result.clutKey = reader.Number<uint32_t>();
                    if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    result.clutSize = reader.Number<uint32_t>();
                    if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    const uint16_t result_clutTypePeekedLen__ = reader.PeekNumber<uint16_t>();
                    if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint16_t>()) + result_clutTypePeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    result.clutType = reader.Text();

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::IWatermark::ID, 9, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }

            return (result);
        }

        bool ModifyPalettedWatermark(uint32_t _id, Exchange::PalettedImageData _data) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(10));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_id);
            writer.Number<uint32_t>(_data.imageKey);
            writer.Number<uint32_t>(_data.imageWidth);
            writer.Number<uint32_t>(_data.imageHeight);
            writer.Number<uint32_t>(_data.clutKey);
            writer.Number<uint32_t>(_data.clutSize);
            writer.Text(_data.clutType);

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
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::IWatermark::ID, 10, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }

            return (result);
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

    }; // class ExchangeWatermarkProxy

    //
    // Exchange::IWatermark::INotification interface proxy definitions
    //
    // Methods:
    //  (0) virtual void WatermarkEvent(const string&, const string&) = 0
    //

    class ExchangeWatermarkNotificationProxy final : public ProxyStub::UnknownProxyType<Exchange::IWatermark::INotification> {
    public:
        ExchangeWatermarkNotificationProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        void WatermarkEvent(const string& _eventName, const string& _parametersJson) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_eventName);
            writer.Text(_parametersJson);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::IWatermark::INotification::ID, 0, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        }

    }; // class ExchangeWatermarkNotificationProxy

    POP_WARNING()
    POP_WARNING()

    // -----------------------------------------------------------------
    // REGISTRATION
    // -----------------------------------------------------------------
    namespace {

        typedef ProxyStub::UnknownStubType<Exchange::IWatermark, ExchangeWatermarkStubMethods> ExchangeWatermarkStub;
        typedef ProxyStub::UnknownStubType<Exchange::IWatermark::INotification, ExchangeWatermarkNotificationStubMethods> ExchangeWatermarkNotificationStub;

        static class Instantiation {
        public:
            Instantiation()
            {
                const RPC::SecureProxyStubType security = static_cast<RPC::SecureProxyStubType>(static_cast<std::underlying_type<RPC::SecureProxyStubType>::type>(RPC::SecureProxyStubType::PROXYSTUBS_SECURITY_SECURE) | static_cast<std::underlying_type<RPC::SecureProxyStubType>::type>(RPC::SecureProxyStubType::PROXYSTUBS_SECURITY_COHERENT));

                RPC::Administrator::Instance().Announce<Exchange::IWatermark, ExchangeWatermarkProxy, ExchangeWatermarkStub>(security);
                RPC::Administrator::Instance().Announce<Exchange::IWatermark::INotification, ExchangeWatermarkNotificationProxy, ExchangeWatermarkNotificationStub>(security);
            }
            ~Instantiation()
            {
                RPC::Administrator::Instance().Recall<Exchange::IWatermark>();
                RPC::Administrator::Instance().Recall<Exchange::IWatermark::INotification>();
            }
        } ProxyStubRegistration;

    } // namespace

} // namespace ProxyStubs

}
