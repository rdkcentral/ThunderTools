//
// generated automatically from "IDeviceIdentification.h"
//
// implements COM-RPC proxy stubs for:
//   - class Exchange::IDeviceIdentification
//
// secure code enabled:
//   - instance verification enabled
//   - range verification enabled
//   - frame coherency verification enabled
//

#include "Module.h"
#include "IDeviceIdentification.h"

#include <com/com.h>

namespace Thunder {

namespace ProxyStubs {

    PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    // -----------------------------------------------------------------
    // STUBS
    // -----------------------------------------------------------------

    //
    // Exchange::IDeviceIdentification interface stub definitions
    //
    // Methods:
    //  (0) virtual Core::hresult Identification(Exchange::IDeviceIdentification::DeviceInfo&) const = 0
    //

    static ProxyStub::MethodHandler ExchangeDeviceIdentificationStubMethods[] = {
        // (0) virtual Core::hresult Identification(Exchange::IDeviceIdentification::DeviceInfo&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const Exchange::IDeviceIdentification* implementation = reinterpret_cast<const Exchange::IDeviceIdentification*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::IDeviceIdentification::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                Exchange::IDeviceIdentification::DeviceInfo _info{};

                Core::hresult result = implementation->Identification(_info);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<Core::hresult>(result);
                writer.Text(_info.deviceID);
                writer.Boolean(_info.firmwareVersion.IsSet());
                if (_info.firmwareVersion.IsSet() == true) {
                    writer.Text(_info.firmwareVersion.Value());
                }
                writer.Boolean(_info.chipset.IsSet());
                if (_info.chipset.IsSet() == true) {
                    writer.Text(_info.chipset.Value());
                }

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(hresult);
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::IDeviceIdentification::ID, 0, hresult);
            }
        }
        , nullptr
    }; // ExchangeDeviceIdentificationStubMethods

    // -----------------------------------------------------------------
    // PROXIES
    // -----------------------------------------------------------------

    //
    // Exchange::IDeviceIdentification interface proxy definitions
    //
    // Methods:
    //  (0) virtual Core::hresult Identification(Exchange::IDeviceIdentification::DeviceInfo&) const = 0
    //

    class ExchangeDeviceIdentificationProxy final : public ProxyStub::UnknownProxyType<Exchange::IDeviceIdentification> {
    public:
        ExchangeDeviceIdentificationProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        Core::hresult Identification(Exchange::IDeviceIdentification::DeviceInfo& _info) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<Core::hresult>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    hresult = reader.Number<Core::hresult>();
                    if ((hresult & COM_ERROR) == 0) {
                        if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                        const uint16_t _info_deviceIDPeekedLen__ = reader.PeekNumber<uint16_t>();
                        if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint16_t>()) + _info_deviceIDPeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                        _info.deviceID = reader.Text();
                        if (reader.Length() < (1)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                        if (reader.Boolean() == true) {
                            if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                            const uint16_t _info_firmwareVersionPeekedLen__ = reader.PeekNumber<uint16_t>();
                            if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint16_t>()) + _info_firmwareVersionPeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                            _info.firmwareVersion = reader.Text();
                        }
                        if (reader.Length() < (1)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                        if (reader.Boolean() == true) {
                            if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                            const uint16_t _info_chipsetPeekedLen__ = reader.PeekNumber<uint16_t>();
                            if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint16_t>()) + _info_chipsetPeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                            _info.chipset = reader.Text();
                        }
                    }

                    return (hresult);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::IDeviceIdentification::ID, 0, hresult);
            }

            return (hresult);
        }

    }; // class ExchangeDeviceIdentificationProxy

    POP_WARNING()
    POP_WARNING()

    // -----------------------------------------------------------------
    // REGISTRATION
    // -----------------------------------------------------------------
    namespace {

        typedef ProxyStub::UnknownStubType<Exchange::IDeviceIdentification, ExchangeDeviceIdentificationStubMethods> ExchangeDeviceIdentificationStub;

        static class Instantiation {
        public:
            Instantiation()
            {
                const RPC::SecureProxyStubType security = static_cast<RPC::SecureProxyStubType>(static_cast<std::underlying_type<RPC::SecureProxyStubType>::type>(RPC::SecureProxyStubType::PROXYSTUBS_SECURITY_SECURE) | static_cast<std::underlying_type<RPC::SecureProxyStubType>::type>(RPC::SecureProxyStubType::PROXYSTUBS_SECURITY_COHERENT));

                RPC::Administrator::Instance().Announce<Exchange::IDeviceIdentification, ExchangeDeviceIdentificationProxy, ExchangeDeviceIdentificationStub>(security);
            }
            ~Instantiation()
            {
                RPC::Administrator::Instance().Recall<Exchange::IDeviceIdentification>();
            }
        } ProxyStubRegistration;

    } // namespace

} // namespace ProxyStubs

}
