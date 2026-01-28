//
// generated automatically from "IDisplayInfo.h"
//
// implements COM-RPC proxy stubs for:
//   - class RPC::IIteratorType<typename ELEMENT, const uint32_t INTERFACE_ID> [with ELEMENT = Exchange::IHDRProperties::HDRType, INTERFACE_ID = Exchange::ID_HDR_ITERATOR] [[iterator]]
//   - class RPC::IIteratorType<typename ELEMENT, const uint32_t INTERFACE_ID> [with ELEMENT = Exchange::IDisplayProperties::ColorimetryType, INTERFACE_ID = Exchange::ID_COLORIMETRY_ITERATOR] [[iterator]]
//   - class Exchange::IGraphicsProperties
//   - class Exchange::IConnectionProperties
//   - class Exchange::IConnectionProperties::INotification
//   - class Exchange::IHDRProperties
//   - class Exchange::IDisplayProperties
//

#include "Module.h"
#include "IDisplayInfo.h"

#include <com/com.h>

namespace Thunder {

namespace ProxyStubs {

    PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    // -----------------------------------------------------------------
    // STUBS
    // -----------------------------------------------------------------

    //
    // RPC::IIteratorTypeInstance_c5a5fda69b531db1 interface stub definitions
    //
    // Methods:
    //  (0) virtual bool Next(Exchange::IHDRProperties::HDRType&) = 0
    //  (1) virtual bool Previous(Exchange::IHDRProperties::HDRType&) = 0
    //  (2) virtual void Reset(const uint32_t) = 0
    //  (3) virtual bool IsValid() const = 0
    //  (4) virtual uint32_t Count() const = 0
    //  (5) virtual Exchange::IHDRProperties::HDRType Current() const = 0
    //

    static ProxyStub::MethodHandler RPCIteratorTypeInstance_c5a5fda69b531db1StubMethods[] = {
        // (0) virtual bool Next(Exchange::IHDRProperties::HDRType&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<Exchange::IHDRProperties::HDRType, Exchange::ID_HDR_ITERATOR>;

            interface* implementation = reinterpret_cast<interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::IHDRProperties::HDRType _info{};

            bool result = implementation->Next(_info);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Boolean(result);
            writer.Number<Exchange::IHDRProperties::HDRType>(_info);
        },

        // (1) virtual bool Previous(Exchange::IHDRProperties::HDRType&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<Exchange::IHDRProperties::HDRType, Exchange::ID_HDR_ITERATOR>;

            interface* implementation = reinterpret_cast<interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::IHDRProperties::HDRType _info{};

            bool result = implementation->Previous(_info);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Boolean(result);
            writer.Number<Exchange::IHDRProperties::HDRType>(_info);
        },

        // (2) virtual void Reset(const uint32_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<Exchange::IHDRProperties::HDRType, Exchange::ID_HDR_ITERATOR>;

            interface* implementation = reinterpret_cast<interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint32_t _position = reader.Number<uint32_t>();

            implementation->Reset(_position);
        },

        // (3) virtual bool IsValid() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<Exchange::IHDRProperties::HDRType, Exchange::ID_HDR_ITERATOR>;

            const interface* implementation = reinterpret_cast<const interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            bool result = implementation->IsValid();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Boolean(result);
        },

        // (4) virtual uint32_t Count() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<Exchange::IHDRProperties::HDRType, Exchange::ID_HDR_ITERATOR>;

            const interface* implementation = reinterpret_cast<const interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            uint32_t result = implementation->Count();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (5) virtual Exchange::IHDRProperties::HDRType Current() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<Exchange::IHDRProperties::HDRType, Exchange::ID_HDR_ITERATOR>;

            const interface* implementation = reinterpret_cast<const interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::IHDRProperties::HDRType result = implementation->Current();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Exchange::IHDRProperties::HDRType>(result);
        }
        , nullptr
    }; // RPCIteratorTypeInstance_c5a5fda69b531db1StubMethods

    //
    // RPC::IIteratorTypeInstance_99f5823ba8ab8d2e interface stub definitions
    //
    // Methods:
    //  (0) virtual bool Next(Exchange::IDisplayProperties::ColorimetryType&) = 0
    //  (1) virtual bool Previous(Exchange::IDisplayProperties::ColorimetryType&) = 0
    //  (2) virtual void Reset(const uint32_t) = 0
    //  (3) virtual bool IsValid() const = 0
    //  (4) virtual uint32_t Count() const = 0
    //  (5) virtual Exchange::IDisplayProperties::ColorimetryType Current() const = 0
    //

    static ProxyStub::MethodHandler RPCIteratorTypeInstance_99f5823ba8ab8d2eStubMethods[] = {
        // (0) virtual bool Next(Exchange::IDisplayProperties::ColorimetryType&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<Exchange::IDisplayProperties::ColorimetryType, Exchange::ID_COLORIMETRY_ITERATOR>;

            interface* implementation = reinterpret_cast<interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::IDisplayProperties::ColorimetryType _info{};

            bool result = implementation->Next(_info);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Boolean(result);
            writer.Number<Exchange::IDisplayProperties::ColorimetryType>(_info);
        },

        // (1) virtual bool Previous(Exchange::IDisplayProperties::ColorimetryType&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<Exchange::IDisplayProperties::ColorimetryType, Exchange::ID_COLORIMETRY_ITERATOR>;

            interface* implementation = reinterpret_cast<interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::IDisplayProperties::ColorimetryType _info{};

            bool result = implementation->Previous(_info);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Boolean(result);
            writer.Number<Exchange::IDisplayProperties::ColorimetryType>(_info);
        },

        // (2) virtual void Reset(const uint32_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<Exchange::IDisplayProperties::ColorimetryType, Exchange::ID_COLORIMETRY_ITERATOR>;

            interface* implementation = reinterpret_cast<interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint32_t _position = reader.Number<uint32_t>();

            implementation->Reset(_position);
        },

        // (3) virtual bool IsValid() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<Exchange::IDisplayProperties::ColorimetryType, Exchange::ID_COLORIMETRY_ITERATOR>;

            const interface* implementation = reinterpret_cast<const interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            bool result = implementation->IsValid();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Boolean(result);
        },

        // (4) virtual uint32_t Count() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<Exchange::IDisplayProperties::ColorimetryType, Exchange::ID_COLORIMETRY_ITERATOR>;

            const interface* implementation = reinterpret_cast<const interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            uint32_t result = implementation->Count();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (5) virtual Exchange::IDisplayProperties::ColorimetryType Current() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<Exchange::IDisplayProperties::ColorimetryType, Exchange::ID_COLORIMETRY_ITERATOR>;

            const interface* implementation = reinterpret_cast<const interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::IDisplayProperties::ColorimetryType result = implementation->Current();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Exchange::IDisplayProperties::ColorimetryType>(result);
        }
        , nullptr
    }; // RPCIteratorTypeInstance_99f5823ba8ab8d2eStubMethods

    //
    // Exchange::IGraphicsProperties interface stub definitions
    //
    // Methods:
    //  (0) virtual uint32_t TotalGpuRam(uint64_t&) const = 0
    //  (1) virtual uint32_t FreeGpuRam(uint64_t&) const = 0
    //

    static ProxyStub::MethodHandler ExchangeGraphicsPropertiesStubMethods[] = {
        // (0) virtual uint32_t TotalGpuRam(uint64_t&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IGraphicsProperties* implementation = reinterpret_cast<const Exchange::IGraphicsProperties*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            uint64_t _total{};

            uint32_t result = implementation->TotalGpuRam(_total);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Number<uint64_t>(_total);
        },

        // (1) virtual uint32_t FreeGpuRam(uint64_t&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IGraphicsProperties* implementation = reinterpret_cast<const Exchange::IGraphicsProperties*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            uint64_t _free{};

            uint32_t result = implementation->FreeGpuRam(_free);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Number<uint64_t>(_free);
        }
        , nullptr
    }; // ExchangeGraphicsPropertiesStubMethods

    //
    // Exchange::IConnectionProperties interface stub definitions
    //
    // Methods:
    //  (0) virtual uint32_t Register(Exchange::IConnectionProperties::INotification*) = 0
    //  (1) virtual uint32_t Unregister(Exchange::IConnectionProperties::INotification*) = 0
    //  (2) virtual uint32_t IsAudioPassthrough(bool&) const = 0
    //  (3) virtual uint32_t Connected(bool&) const = 0
    //  (4) virtual uint32_t Width(uint32_t&) const = 0
    //  (5) virtual uint32_t Height(uint32_t&) const = 0
    //  (6) virtual uint32_t VerticalFreq(uint32_t&) const = 0
    //  (7) virtual uint32_t EDID(uint16_t&, uint8_t*) const = 0
    //  (8) virtual uint32_t WidthInCentimeters(uint8_t&) const = 0
    //  (9) virtual uint32_t HeightInCentimeters(uint8_t&) const = 0
    //  (10) virtual uint32_t HDCPProtection(Exchange::IConnectionProperties::HDCPProtectionType&) const = 0
    //  (11) virtual uint32_t HDCPProtection(const Exchange::IConnectionProperties::HDCPProtectionType) = 0
    //  (12) virtual uint32_t PortName(string&) const = 0
    //

    static ProxyStub::MethodHandler ExchangeConnectionPropertiesStubMethods[] = {
        // (0) virtual uint32_t Register(Exchange::IConnectionProperties::INotification*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IConnectionProperties* implementation = reinterpret_cast<Exchange::IConnectionProperties*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            Core::instance_id _parameter_2ab6979aInstanceId__ = reader.Number<Core::instance_id>();

            Exchange::IConnectionProperties::INotification* _parameter_2ab6979a{};
            ProxyStub::UnknownProxy* _parameter_2ab6979aProxy__ = nullptr;
            if (_parameter_2ab6979aInstanceId__ != 0) {
                _parameter_2ab6979aProxy__ = RPC::Administrator::Instance().ProxyInstance(channel, _parameter_2ab6979aInstanceId__, false, _parameter_2ab6979a);
                ASSERT((_parameter_2ab6979a != nullptr) && (_parameter_2ab6979aProxy__ != nullptr));
            }

            uint32_t result = implementation->Register(_parameter_2ab6979a);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);

            if (_parameter_2ab6979aProxy__ != nullptr) {
                RPC::Administrator::Instance().Release(_parameter_2ab6979aProxy__, message->Response());
            }
        },

        // (1) virtual uint32_t Unregister(Exchange::IConnectionProperties::INotification*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IConnectionProperties* implementation = reinterpret_cast<Exchange::IConnectionProperties*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            Core::instance_id _parameter_5f14092cInstanceId__ = reader.Number<Core::instance_id>();

            Exchange::IConnectionProperties::INotification* _parameter_5f14092c{};
            ProxyStub::UnknownProxy* _parameter_5f14092cProxy__ = nullptr;
            if (_parameter_5f14092cInstanceId__ != 0) {
                _parameter_5f14092cProxy__ = RPC::Administrator::Instance().ProxyInstance(channel, _parameter_5f14092cInstanceId__, false, _parameter_5f14092c);
                ASSERT((_parameter_5f14092c != nullptr) && (_parameter_5f14092cProxy__ != nullptr));
            }

            uint32_t result = implementation->Unregister(_parameter_5f14092c);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);

            if (_parameter_5f14092cProxy__ != nullptr) {
                RPC::Administrator::Instance().Release(_parameter_5f14092cProxy__, message->Response());
            }
        },

        // (2) virtual uint32_t IsAudioPassthrough(bool&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IConnectionProperties* implementation = reinterpret_cast<const Exchange::IConnectionProperties*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            bool _passthru{};

            uint32_t result = implementation->IsAudioPassthrough(_passthru);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Boolean(_passthru);
        },

        // (3) virtual uint32_t Connected(bool&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IConnectionProperties* implementation = reinterpret_cast<const Exchange::IConnectionProperties*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            bool _isconnected{};

            uint32_t result = implementation->Connected(_isconnected);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Boolean(_isconnected);
        },

        // (4) virtual uint32_t Width(uint32_t&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IConnectionProperties* implementation = reinterpret_cast<const Exchange::IConnectionProperties*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            uint32_t _width{};

            uint32_t result = implementation->Width(_width);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Number<uint32_t>(_width);
        },

        // (5) virtual uint32_t Height(uint32_t&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IConnectionProperties* implementation = reinterpret_cast<const Exchange::IConnectionProperties*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            uint32_t _height{};

            uint32_t result = implementation->Height(_height);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Number<uint32_t>(_height);
        },

        // (6) virtual uint32_t VerticalFreq(uint32_t&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IConnectionProperties* implementation = reinterpret_cast<const Exchange::IConnectionProperties*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            uint32_t _vf{};

            uint32_t result = implementation->VerticalFreq(_vf);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Number<uint32_t>(_vf);
        },

        // (7) virtual uint32_t EDID(uint16_t&, uint8_t*) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IConnectionProperties* implementation = reinterpret_cast<const Exchange::IConnectionProperties*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            uint16_t _length = reader.Number<uint16_t>();

            uint8_t* _data{};

            if (_length != 0) {
                _data = static_cast<uint8_t*>(ALLOCA(_length * sizeof(uint8_t)));
                ASSERT(_data != nullptr);
            }

            uint32_t result = implementation->EDID(_length, _data);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Buffer<uint16_t>((_data == nullptr? 0 : _length), _data);
            writer.Number<uint16_t>(_length);
        },

        // (8) virtual uint32_t WidthInCentimeters(uint8_t&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IConnectionProperties* implementation = reinterpret_cast<const Exchange::IConnectionProperties*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            uint8_t _width{};

            uint32_t result = implementation->WidthInCentimeters(_width);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Number<uint8_t>(_width);
        },

        // (9) virtual uint32_t HeightInCentimeters(uint8_t&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IConnectionProperties* implementation = reinterpret_cast<const Exchange::IConnectionProperties*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            uint8_t _height{};

            uint32_t result = implementation->HeightInCentimeters(_height);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Number<uint8_t>(_height);
        },

        // (10) virtual uint32_t HDCPProtection(Exchange::IConnectionProperties::HDCPProtectionType&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IConnectionProperties* implementation = reinterpret_cast<const Exchange::IConnectionProperties*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::IConnectionProperties::HDCPProtectionType _value{};

            uint32_t result = implementation->HDCPProtection(_value);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Number<Exchange::IConnectionProperties::HDCPProtectionType>(_value);
        },

        // (11) virtual uint32_t HDCPProtection(const Exchange::IConnectionProperties::HDCPProtectionType) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IConnectionProperties* implementation = reinterpret_cast<Exchange::IConnectionProperties*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const Exchange::IConnectionProperties::HDCPProtectionType _value = reader.Number<Exchange::IConnectionProperties::HDCPProtectionType>();

            uint32_t result = implementation->HDCPProtection(_value);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (12) virtual uint32_t PortName(string&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IConnectionProperties* implementation = reinterpret_cast<const Exchange::IConnectionProperties*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            string _name{};

            uint32_t result = implementation->PortName(_name);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Text(_name);
        }
        , nullptr
    }; // ExchangeConnectionPropertiesStubMethods

    //
    // Exchange::IConnectionProperties::INotification interface stub definitions
    //
    // Methods:
    //  (0) virtual void Updated(const Exchange::IConnectionProperties::INotification::Source) = 0
    //

    static ProxyStub::MethodHandler ExchangeConnectionPropertiesNotificationStubMethods[] = {
        // (0) virtual void Updated(const Exchange::IConnectionProperties::INotification::Source) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IConnectionProperties::INotification* implementation = reinterpret_cast<Exchange::IConnectionProperties::INotification*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const Exchange::IConnectionProperties::INotification::Source _event = reader.Number<Exchange::IConnectionProperties::INotification::Source>();

            implementation->Updated(_event);
        }
        , nullptr
    }; // ExchangeConnectionPropertiesNotificationStubMethods

    //
    // Exchange::IHDRProperties interface stub definitions
    //
    // Methods:
    //  (0) virtual uint32_t TVCapabilities(Exchange::IHDRProperties::IHDRIterator*&) const = 0
    //  (1) virtual uint32_t STBCapabilities(Exchange::IHDRProperties::IHDRIterator*&) const = 0
    //  (2) virtual uint32_t HDRSetting(Exchange::IHDRProperties::HDRType&) const = 0
    //

    static ProxyStub::MethodHandler ExchangeHDRPropertiesStubMethods[] = {
        // (0) virtual uint32_t TVCapabilities(Exchange::IHDRProperties::IHDRIterator*&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IHDRProperties* implementation = reinterpret_cast<const Exchange::IHDRProperties*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::IHDRProperties::IHDRIterator* _type{};

            uint32_t result = implementation->TVCapabilities(_type);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Number<Core::instance_id>(RPC::instance_cast(_type));

            RPC::Administrator::Instance().RegisterInterface(channel, _type);
        },

        // (1) virtual uint32_t STBCapabilities(Exchange::IHDRProperties::IHDRIterator*&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IHDRProperties* implementation = reinterpret_cast<const Exchange::IHDRProperties*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::IHDRProperties::IHDRIterator* _type{};

            uint32_t result = implementation->STBCapabilities(_type);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Number<Core::instance_id>(RPC::instance_cast(_type));

            RPC::Administrator::Instance().RegisterInterface(channel, _type);
        },

        // (2) virtual uint32_t HDRSetting(Exchange::IHDRProperties::HDRType&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IHDRProperties* implementation = reinterpret_cast<const Exchange::IHDRProperties*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::IHDRProperties::HDRType _type{};

            uint32_t result = implementation->HDRSetting(_type);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Number<Exchange::IHDRProperties::HDRType>(_type);
        }
        , nullptr
    }; // ExchangeHDRPropertiesStubMethods

    //
    // Exchange::IDisplayProperties interface stub definitions
    //
    // Methods:
    //  (0) virtual uint32_t ColorSpace(Exchange::IDisplayProperties::ColourSpaceType&) const = 0
    //  (1) virtual uint32_t FrameRate(Exchange::IDisplayProperties::FrameRateType&) const = 0
    //  (2) virtual uint32_t ColourDepth(Exchange::IDisplayProperties::ColourDepthType&) const = 0
    //  (3) virtual uint32_t Colorimetry(Exchange::IDisplayProperties::IColorimetryIterator*&) const = 0
    //  (4) virtual uint32_t QuantizationRange(Exchange::IDisplayProperties::QuantizationRangeType&) const = 0
    //  (5) virtual uint32_t EOTF(Exchange::IDisplayProperties::EotfType&) const = 0
    //

    static ProxyStub::MethodHandler ExchangeDisplayPropertiesStubMethods[] = {
        // (0) virtual uint32_t ColorSpace(Exchange::IDisplayProperties::ColourSpaceType&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IDisplayProperties* implementation = reinterpret_cast<const Exchange::IDisplayProperties*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::IDisplayProperties::ColourSpaceType _cs{};

            uint32_t result = implementation->ColorSpace(_cs);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Number<Exchange::IDisplayProperties::ColourSpaceType>(_cs);
        },

        // (1) virtual uint32_t FrameRate(Exchange::IDisplayProperties::FrameRateType&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IDisplayProperties* implementation = reinterpret_cast<const Exchange::IDisplayProperties*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::IDisplayProperties::FrameRateType _rate{};

            uint32_t result = implementation->FrameRate(_rate);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Number<Exchange::IDisplayProperties::FrameRateType>(_rate);
        },

        // (2) virtual uint32_t ColourDepth(Exchange::IDisplayProperties::ColourDepthType&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IDisplayProperties* implementation = reinterpret_cast<const Exchange::IDisplayProperties*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::IDisplayProperties::ColourDepthType _colour{};

            uint32_t result = implementation->ColourDepth(_colour);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Number<Exchange::IDisplayProperties::ColourDepthType>(_colour);
        },

        // (3) virtual uint32_t Colorimetry(Exchange::IDisplayProperties::IColorimetryIterator*&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IDisplayProperties* implementation = reinterpret_cast<const Exchange::IDisplayProperties*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::IDisplayProperties::IColorimetryIterator* _colorimetry{};

            uint32_t result = implementation->Colorimetry(_colorimetry);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Number<Core::instance_id>(RPC::instance_cast(_colorimetry));

            RPC::Administrator::Instance().RegisterInterface(channel, _colorimetry);
        },

        // (4) virtual uint32_t QuantizationRange(Exchange::IDisplayProperties::QuantizationRangeType&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IDisplayProperties* implementation = reinterpret_cast<const Exchange::IDisplayProperties*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::IDisplayProperties::QuantizationRangeType _qr{};

            uint32_t result = implementation->QuantizationRange(_qr);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Number<Exchange::IDisplayProperties::QuantizationRangeType>(_qr);
        },

        // (5) virtual uint32_t EOTF(Exchange::IDisplayProperties::EotfType&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IDisplayProperties* implementation = reinterpret_cast<const Exchange::IDisplayProperties*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::IDisplayProperties::EotfType _eotf{};

            uint32_t result = implementation->EOTF(_eotf);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Number<Exchange::IDisplayProperties::EotfType>(_eotf);
        }
        , nullptr
    }; // ExchangeDisplayPropertiesStubMethods

    // -----------------------------------------------------------------
    // PROXIES
    // -----------------------------------------------------------------

    //
    // RPC::IIteratorTypeInstance_c5a5fda69b531db1 interface proxy definitions
    //
    // Methods:
    //  (0) virtual bool Next(Exchange::IHDRProperties::HDRType&) = 0
    //  (1) virtual bool Previous(Exchange::IHDRProperties::HDRType&) = 0
    //  (2) virtual void Reset(const uint32_t) = 0
    //  (3) virtual bool IsValid() const = 0
    //  (4) virtual uint32_t Count() const = 0
    //  (5) virtual Exchange::IHDRProperties::HDRType Current() const = 0
    //

    class RPCIteratorTypeInstance_c5a5fda69b531db1Proxy final : public ProxyStub::UnknownProxyType<RPC::IIteratorType<Exchange::IHDRProperties::HDRType, Exchange::ID_HDR_ITERATOR>> {
    public:
        RPCIteratorTypeInstance_c5a5fda69b531db1Proxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        bool Next(Exchange::IHDRProperties::HDRType& _info) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            bool result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Boolean();
                _info = reader.Number<Exchange::IHDRProperties::HDRType>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        bool Previous(Exchange::IHDRProperties::HDRType& _info) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            bool result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Boolean();
                _info = reader.Number<Exchange::IHDRProperties::HDRType>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        void Reset(const uint32_t _position) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(2));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_position);

            static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
        }

        bool IsValid() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(3));

            bool result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Boolean();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        uint32_t Count() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(4));

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

        Exchange::IHDRProperties::HDRType Current() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(5));

            Exchange::IHDRProperties::HDRType result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Number<Exchange::IHDRProperties::HDRType>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

    }; // class RPCIteratorTypeInstance_c5a5fda69b531db1Proxy

    //
    // RPC::IIteratorTypeInstance_99f5823ba8ab8d2e interface proxy definitions
    //
    // Methods:
    //  (0) virtual bool Next(Exchange::IDisplayProperties::ColorimetryType&) = 0
    //  (1) virtual bool Previous(Exchange::IDisplayProperties::ColorimetryType&) = 0
    //  (2) virtual void Reset(const uint32_t) = 0
    //  (3) virtual bool IsValid() const = 0
    //  (4) virtual uint32_t Count() const = 0
    //  (5) virtual Exchange::IDisplayProperties::ColorimetryType Current() const = 0
    //

    class RPCIteratorTypeInstance_99f5823ba8ab8d2eProxy final : public ProxyStub::UnknownProxyType<RPC::IIteratorType<Exchange::IDisplayProperties::ColorimetryType, Exchange::ID_COLORIMETRY_ITERATOR>> {
    public:
        RPCIteratorTypeInstance_99f5823ba8ab8d2eProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        bool Next(Exchange::IDisplayProperties::ColorimetryType& _info) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            bool result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Boolean();
                _info = reader.Number<Exchange::IDisplayProperties::ColorimetryType>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        bool Previous(Exchange::IDisplayProperties::ColorimetryType& _info) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            bool result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Boolean();
                _info = reader.Number<Exchange::IDisplayProperties::ColorimetryType>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        void Reset(const uint32_t _position) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(2));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_position);

            static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
        }

        bool IsValid() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(3));

            bool result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Boolean();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        uint32_t Count() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(4));

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

        Exchange::IDisplayProperties::ColorimetryType Current() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(5));

            Exchange::IDisplayProperties::ColorimetryType result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Number<Exchange::IDisplayProperties::ColorimetryType>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

    }; // class RPCIteratorTypeInstance_99f5823ba8ab8d2eProxy

    //
    // Exchange::IGraphicsProperties interface proxy definitions
    //
    // Methods:
    //  (0) virtual uint32_t TotalGpuRam(uint64_t&) const = 0
    //  (1) virtual uint32_t FreeGpuRam(uint64_t&) const = 0
    //

    class ExchangeGraphicsPropertiesProxy final : public ProxyStub::UnknownProxyType<Exchange::IGraphicsProperties> {
    public:
        ExchangeGraphicsPropertiesProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        uint32_t TotalGpuRam(uint64_t& _total) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
                _total = reader.Number<uint64_t>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        uint32_t FreeGpuRam(uint64_t& _free) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
                _free = reader.Number<uint64_t>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

    }; // class ExchangeGraphicsPropertiesProxy

    //
    // Exchange::IConnectionProperties interface proxy definitions
    //
    // Methods:
    //  (0) virtual uint32_t Register(Exchange::IConnectionProperties::INotification*) = 0
    //  (1) virtual uint32_t Unregister(Exchange::IConnectionProperties::INotification*) = 0
    //  (2) virtual uint32_t IsAudioPassthrough(bool&) const = 0
    //  (3) virtual uint32_t Connected(bool&) const = 0
    //  (4) virtual uint32_t Width(uint32_t&) const = 0
    //  (5) virtual uint32_t Height(uint32_t&) const = 0
    //  (6) virtual uint32_t VerticalFreq(uint32_t&) const = 0
    //  (7) virtual uint32_t EDID(uint16_t&, uint8_t*) const = 0
    //  (8) virtual uint32_t WidthInCentimeters(uint8_t&) const = 0
    //  (9) virtual uint32_t HeightInCentimeters(uint8_t&) const = 0
    //  (10) virtual uint32_t HDCPProtection(Exchange::IConnectionProperties::HDCPProtectionType&) const = 0
    //  (11) virtual uint32_t HDCPProtection(const Exchange::IConnectionProperties::HDCPProtectionType) = 0
    //  (12) virtual uint32_t PortName(string&) const = 0
    //

    class ExchangeConnectionPropertiesProxy final : public ProxyStub::UnknownProxyType<Exchange::IConnectionProperties> {
    public:
        ExchangeConnectionPropertiesProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        uint32_t Register(Exchange::IConnectionProperties::INotification* _parameter_2ab6979a) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_parameter_2ab6979a));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();

                _Complete(reader);
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        uint32_t Unregister(Exchange::IConnectionProperties::INotification* _parameter_5f14092c) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_parameter_5f14092c));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();

                _Complete(reader);
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        uint32_t IsAudioPassthrough(bool& _passthru) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(2));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
                _passthru = reader.Boolean();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        uint32_t Connected(bool& _isconnected) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(3));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
                _isconnected = reader.Boolean();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        uint32_t Width(uint32_t& _width) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(4));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
                _width = reader.Number<uint32_t>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        uint32_t Height(uint32_t& _height) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(5));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
                _height = reader.Number<uint32_t>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        uint32_t VerticalFreq(uint32_t& _vf) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(6));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
                _vf = reader.Number<uint32_t>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        uint32_t EDID(uint16_t& _length, uint8_t* _data) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(7));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint16_t>(_length);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
                reader.Buffer<uint16_t>(_length, _data);
                _length = reader.Number<uint16_t>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        uint32_t WidthInCentimeters(uint8_t& _width) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(8));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
                _width = reader.Number<uint8_t>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        uint32_t HeightInCentimeters(uint8_t& _height) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(9));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
                _height = reader.Number<uint8_t>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        uint32_t HDCPProtection(Exchange::IConnectionProperties::HDCPProtectionType& _value) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(10));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
                _value = reader.Number<Exchange::IConnectionProperties::HDCPProtectionType>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        uint32_t HDCPProtection(const Exchange::IConnectionProperties::HDCPProtectionType _value) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(11));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Exchange::IConnectionProperties::HDCPProtectionType>(_value);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        uint32_t PortName(string& _name) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(12));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
                _name = reader.Text();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

    private:
        uint32_t _Complete(RPC::Data::Frame::Reader& reader) const
        {
            uint32_t result = Core::ERROR_NONE;

            while (reader.HasData() == true) {
                const Core::instance_id implementation = reader.Number<Core::instance_id>();
                ASSERT(implementation != 0);

                const uint32_t id = reader.Number<uint32_t>();
                const RPC::Data::Output::mode how = reader.Number<RPC::Data::Output::mode>();

                result = static_cast<const ProxyStub::UnknownProxy&>(*this).Complete(implementation, id, how);
                if (result != Core::ERROR_NONE) { return (COM_ERROR | result); }
            }

            return (result);
        }

    }; // class ExchangeConnectionPropertiesProxy

    //
    // Exchange::IConnectionProperties::INotification interface proxy definitions
    //
    // Methods:
    //  (0) virtual void Updated(const Exchange::IConnectionProperties::INotification::Source) = 0
    //

    class ExchangeConnectionPropertiesNotificationProxy final : public ProxyStub::UnknownProxyType<Exchange::IConnectionProperties::INotification> {
    public:
        ExchangeConnectionPropertiesNotificationProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        void Updated(const Exchange::IConnectionProperties::INotification::Source _event) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Exchange::IConnectionProperties::INotification::Source>(_event);

            static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
        }

    }; // class ExchangeConnectionPropertiesNotificationProxy

    //
    // Exchange::IHDRProperties interface proxy definitions
    //
    // Methods:
    //  (0) virtual uint32_t TVCapabilities(Exchange::IHDRProperties::IHDRIterator*&) const = 0
    //  (1) virtual uint32_t STBCapabilities(Exchange::IHDRProperties::IHDRIterator*&) const = 0
    //  (2) virtual uint32_t HDRSetting(Exchange::IHDRProperties::HDRType&) const = 0
    //

    class ExchangeHDRPropertiesProxy final : public ProxyStub::UnknownProxyType<Exchange::IHDRProperties> {
    public:
        ExchangeHDRPropertiesProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        uint32_t TVCapabilities(Exchange::IHDRProperties::IHDRIterator*& _type) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
                _type = reinterpret_cast<Exchange::IHDRProperties::IHDRIterator*>(static_cast<const ProxyStub::UnknownProxy&>(*this).Interface(reader.Number<Core::instance_id>(), Exchange::IHDRProperties::IHDRIterator::ID));
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        uint32_t STBCapabilities(Exchange::IHDRProperties::IHDRIterator*& _type) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
                _type = reinterpret_cast<Exchange::IHDRProperties::IHDRIterator*>(static_cast<const ProxyStub::UnknownProxy&>(*this).Interface(reader.Number<Core::instance_id>(), Exchange::IHDRProperties::IHDRIterator::ID));
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        uint32_t HDRSetting(Exchange::IHDRProperties::HDRType& _type) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(2));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
                _type = reader.Number<Exchange::IHDRProperties::HDRType>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

    }; // class ExchangeHDRPropertiesProxy

    //
    // Exchange::IDisplayProperties interface proxy definitions
    //
    // Methods:
    //  (0) virtual uint32_t ColorSpace(Exchange::IDisplayProperties::ColourSpaceType&) const = 0
    //  (1) virtual uint32_t FrameRate(Exchange::IDisplayProperties::FrameRateType&) const = 0
    //  (2) virtual uint32_t ColourDepth(Exchange::IDisplayProperties::ColourDepthType&) const = 0
    //  (3) virtual uint32_t Colorimetry(Exchange::IDisplayProperties::IColorimetryIterator*&) const = 0
    //  (4) virtual uint32_t QuantizationRange(Exchange::IDisplayProperties::QuantizationRangeType&) const = 0
    //  (5) virtual uint32_t EOTF(Exchange::IDisplayProperties::EotfType&) const = 0
    //

    class ExchangeDisplayPropertiesProxy final : public ProxyStub::UnknownProxyType<Exchange::IDisplayProperties> {
    public:
        ExchangeDisplayPropertiesProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        uint32_t ColorSpace(Exchange::IDisplayProperties::ColourSpaceType& _cs) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
                _cs = reader.Number<Exchange::IDisplayProperties::ColourSpaceType>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        uint32_t FrameRate(Exchange::IDisplayProperties::FrameRateType& _rate) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
                _rate = reader.Number<Exchange::IDisplayProperties::FrameRateType>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        uint32_t ColourDepth(Exchange::IDisplayProperties::ColourDepthType& _colour) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(2));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
                _colour = reader.Number<Exchange::IDisplayProperties::ColourDepthType>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        uint32_t Colorimetry(Exchange::IDisplayProperties::IColorimetryIterator*& _colorimetry) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(3));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
                _colorimetry = reinterpret_cast<Exchange::IDisplayProperties::IColorimetryIterator*>(static_cast<const ProxyStub::UnknownProxy&>(*this).Interface(reader.Number<Core::instance_id>(), Exchange::IDisplayProperties::IColorimetryIterator::ID));
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        uint32_t QuantizationRange(Exchange::IDisplayProperties::QuantizationRangeType& _qr) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(4));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
                _qr = reader.Number<Exchange::IDisplayProperties::QuantizationRangeType>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        uint32_t EOTF(Exchange::IDisplayProperties::EotfType& _eotf) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(5));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
                _eotf = reader.Number<Exchange::IDisplayProperties::EotfType>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

    }; // class ExchangeDisplayPropertiesProxy

    POP_WARNING()
    POP_WARNING()

    // -----------------------------------------------------------------
    // REGISTRATION
    // -----------------------------------------------------------------
    namespace {

        typedef ProxyStub::UnknownStubType<RPC::IIteratorType<Exchange::IHDRProperties::HDRType, Exchange::ID_HDR_ITERATOR>, RPCIteratorTypeInstance_c5a5fda69b531db1StubMethods> RPCIteratorTypeInstance_c5a5fda69b531db1Stub;
        typedef ProxyStub::UnknownStubType<RPC::IIteratorType<Exchange::IDisplayProperties::ColorimetryType, Exchange::ID_COLORIMETRY_ITERATOR>, RPCIteratorTypeInstance_99f5823ba8ab8d2eStubMethods> RPCIteratorTypeInstance_99f5823ba8ab8d2eStub;
        typedef ProxyStub::UnknownStubType<Exchange::IGraphicsProperties, ExchangeGraphicsPropertiesStubMethods> ExchangeGraphicsPropertiesStub;
        typedef ProxyStub::UnknownStubType<Exchange::IConnectionProperties, ExchangeConnectionPropertiesStubMethods> ExchangeConnectionPropertiesStub;
        typedef ProxyStub::UnknownStubType<Exchange::IConnectionProperties::INotification, ExchangeConnectionPropertiesNotificationStubMethods> ExchangeConnectionPropertiesNotificationStub;
        typedef ProxyStub::UnknownStubType<Exchange::IHDRProperties, ExchangeHDRPropertiesStubMethods> ExchangeHDRPropertiesStub;
        typedef ProxyStub::UnknownStubType<Exchange::IDisplayProperties, ExchangeDisplayPropertiesStubMethods> ExchangeDisplayPropertiesStub;

        static class Instantiation {
        public:
            Instantiation()
            {
                RPC::Administrator::Instance().Announce<RPC::IIteratorType<Exchange::IHDRProperties::HDRType, Exchange::ID_HDR_ITERATOR>, RPCIteratorTypeInstance_c5a5fda69b531db1Proxy, RPCIteratorTypeInstance_c5a5fda69b531db1Stub>();
                RPC::Administrator::Instance().Announce<RPC::IIteratorType<Exchange::IDisplayProperties::ColorimetryType, Exchange::ID_COLORIMETRY_ITERATOR>, RPCIteratorTypeInstance_99f5823ba8ab8d2eProxy, RPCIteratorTypeInstance_99f5823ba8ab8d2eStub>();
                RPC::Administrator::Instance().Announce<Exchange::IGraphicsProperties, ExchangeGraphicsPropertiesProxy, ExchangeGraphicsPropertiesStub>();
                RPC::Administrator::Instance().Announce<Exchange::IConnectionProperties, ExchangeConnectionPropertiesProxy, ExchangeConnectionPropertiesStub>();
                RPC::Administrator::Instance().Announce<Exchange::IConnectionProperties::INotification, ExchangeConnectionPropertiesNotificationProxy, ExchangeConnectionPropertiesNotificationStub>();
                RPC::Administrator::Instance().Announce<Exchange::IHDRProperties, ExchangeHDRPropertiesProxy, ExchangeHDRPropertiesStub>();
                RPC::Administrator::Instance().Announce<Exchange::IDisplayProperties, ExchangeDisplayPropertiesProxy, ExchangeDisplayPropertiesStub>();
            }
            ~Instantiation()
            {
                RPC::Administrator::Instance().Recall<RPC::IIteratorType<Exchange::IHDRProperties::HDRType, Exchange::ID_HDR_ITERATOR>>();
                RPC::Administrator::Instance().Recall<RPC::IIteratorType<Exchange::IDisplayProperties::ColorimetryType, Exchange::ID_COLORIMETRY_ITERATOR>>();
                RPC::Administrator::Instance().Recall<Exchange::IGraphicsProperties>();
                RPC::Administrator::Instance().Recall<Exchange::IConnectionProperties>();
                RPC::Administrator::Instance().Recall<Exchange::IConnectionProperties::INotification>();
                RPC::Administrator::Instance().Recall<Exchange::IHDRProperties>();
                RPC::Administrator::Instance().Recall<Exchange::IDisplayProperties>();
            }
        } ProxyStubRegistration;

    } // namespace

} // namespace ProxyStubs

}
