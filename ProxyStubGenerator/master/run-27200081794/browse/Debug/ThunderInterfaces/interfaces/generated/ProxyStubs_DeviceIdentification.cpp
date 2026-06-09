//
// generated automatically from "IDeviceIdentification.h"
//
// implements COM-RPC proxy stubs for:
//   - class Exchange::IDeviceIdentification
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
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IDeviceIdentification* implementation = reinterpret_cast<const Exchange::IDeviceIdentification*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

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
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
                _info.deviceID = reader.Text();
                if (reader.Boolean() == true) {
                    _info.firmwareVersion = reader.Text();
                }
                if (reader.Boolean() == true) {
                    _info.chipset = reader.Text();
                }
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
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
                RPC::Administrator::Instance().Announce<Exchange::IDeviceIdentification, ExchangeDeviceIdentificationProxy, ExchangeDeviceIdentificationStub>();
            }
            ~Instantiation()
            {
                RPC::Administrator::Instance().Recall<Exchange::IDeviceIdentification>();
            }
        } ProxyStubRegistration;

    } // namespace

} // namespace ProxyStubs

}
