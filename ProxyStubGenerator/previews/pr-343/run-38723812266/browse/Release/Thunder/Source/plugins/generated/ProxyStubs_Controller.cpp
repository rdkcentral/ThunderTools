//
// generated automatically from "IController.h"
//
// implements COM-RPC proxy stubs for:
//   - class Exchange::Controller::ISystem
//   - class Exchange::Controller::IDiscovery
//   - class Exchange::Controller::IConfiguration
//   - class Exchange::Controller::ILifeTime
//   - class Exchange::Controller::ILifeTime::INotification
//   - class Exchange::Controller::IShells
//   - class Exchange::Controller::IShells::INotification
//   - class Exchange::Controller::ISubsystems
//   - class Exchange::Controller::ISubsystems::INotification
//   - class Exchange::Controller::IEvents
//   - class Exchange::Controller::IEvents::INotification
//   - class Exchange::Controller::IMetadata
//
// secure code enabled:
//   - instance verification enabled
//   - range verification enabled
//   - frame coherency verification enabled
//

#include "Module.h"
#include "IController.h"

#include <com/com.h>

namespace Thunder {

namespace ProxyStubs {

    PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    // -----------------------------------------------------------------
    // STUBS
    // -----------------------------------------------------------------

    //
    // Exchange::Controller::ISystem interface stub definitions
    //
    // Methods:
    //  (0) virtual Core::hresult Reboot() = 0
    //  (1) virtual Core::hresult Delete(const string&) = 0
    //  (2) virtual Core::hresult Clone(const string&, const string&, string&) = 0
    //  (3) virtual Core::hresult Destroy(const string&) = 0
    //  (4) virtual Core::hresult Environment(const string&, string&) const = 0
    //

    static ProxyStub::MethodHandler ExchangeControllerSystemStubMethods[] = {
        // (0) virtual Core::hresult Reboot() = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                Exchange::Controller::ISystem* implementation = reinterpret_cast<Exchange::Controller::ISystem*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::Controller::ISystem::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                Core::hresult result = implementation->Reboot();

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<Core::hresult>(result);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(hresult);
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::Controller::ISystem::ID, 0, hresult);
            }
        },

        // (1) virtual Core::hresult Delete(const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                Exchange::Controller::ISystem* implementation = reinterpret_cast<Exchange::Controller::ISystem*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::Controller::ISystem::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint16_t _pathPeekedLen__ = reader.PeekNumber<uint16_t>();
                if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint16_t>()) + _pathPeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const string _path = reader.Text();

                Core::hresult result = implementation->Delete(static_cast<const string&>(_path));

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<Core::hresult>(result);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(hresult);
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::Controller::ISystem::ID, 1, hresult);
            }
        },

        // (2) virtual Core::hresult Clone(const string&, const string&, string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                Exchange::Controller::ISystem* implementation = reinterpret_cast<Exchange::Controller::ISystem*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::Controller::ISystem::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint16_t _callsignPeekedLen__ = reader.PeekNumber<uint16_t>();
                if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint16_t>()) + _callsignPeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const string _callsign = reader.Text();
                if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint16_t _newcallsignPeekedLen__ = reader.PeekNumber<uint16_t>();
                if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint16_t>()) + _newcallsignPeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const string _newcallsign = reader.Text();

                string _response{};

                Core::hresult result = implementation->Clone(static_cast<const string&>(_callsign), static_cast<const string&>(_newcallsign), _response);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<Core::hresult>(result);
                writer.Text(_response);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(hresult);
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::Controller::ISystem::ID, 2, hresult);
            }
        },

        // (3) virtual Core::hresult Destroy(const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                Exchange::Controller::ISystem* implementation = reinterpret_cast<Exchange::Controller::ISystem*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::Controller::ISystem::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint16_t _callsignPeekedLen__ = reader.PeekNumber<uint16_t>();
                if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint16_t>()) + _callsignPeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const string _callsign = reader.Text();

                Core::hresult result = implementation->Destroy(static_cast<const string&>(_callsign));

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<Core::hresult>(result);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(hresult);
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::Controller::ISystem::ID, 3, hresult);
            }
        },

        // (4) virtual Core::hresult Environment(const string&, string&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const Exchange::Controller::ISystem* implementation = reinterpret_cast<const Exchange::Controller::ISystem*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::Controller::ISystem::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint16_t _variablePeekedLen__ = reader.PeekNumber<uint16_t>();
                if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint16_t>()) + _variablePeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const string _variable = reader.Text();

                string _value{};

                Core::hresult result = implementation->Environment(static_cast<const string&>(_variable), _value);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<Core::hresult>(result);
                writer.Text(_value);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(hresult);
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::Controller::ISystem::ID, 4, hresult);
            }
        }
        , nullptr
    }; // ExchangeControllerSystemStubMethods

    //
    // Exchange::Controller::IDiscovery interface stub definitions
    //
    // Methods:
    //  (0) virtual Core::hresult StartDiscovery(const Core::OptionalType<uint8_t>&) = 0
    //  (1) virtual Core::hresult DiscoveryResults(Exchange::Controller::IDiscovery::Data::IDiscoveryResultsIterator*&) const = 0
    //

    static ProxyStub::MethodHandler ExchangeControllerDiscoveryStubMethods[] = {
        // (0) virtual Core::hresult StartDiscovery(const Core::OptionalType<uint8_t>&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                Exchange::Controller::IDiscovery* implementation = reinterpret_cast<Exchange::Controller::IDiscovery*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::Controller::IDiscovery::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                Core::OptionalType<uint8_t> _ttl{};
                if (reader.Length() < (1)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                if (reader.Boolean() == true) {
                    if (reader.Length() < (1)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    _ttl = reader.Number<uint8_t>();
                    ASSERT((static_cast<const Core::OptionalType<uint8_t>&>(_ttl) >= 1) && (static_cast<const Core::OptionalType<uint8_t>&>(_ttl) <= 255));
                    if (!((static_cast<const Core::OptionalType<uint8_t>&>(_ttl) >= 1) && (static_cast<const Core::OptionalType<uint8_t>&>(_ttl) <= 255))) { return (COM_ERROR | Core::ERROR_INVALID_RANGE); }
                }

                Core::hresult result = implementation->StartDiscovery(static_cast<const Core::OptionalType<uint8_t>&>(_ttl));

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<Core::hresult>(result);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(hresult);
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::Controller::IDiscovery::ID, 0, hresult);
            }
        },

        // (1) virtual Core::hresult DiscoveryResults(Exchange::Controller::IDiscovery::Data::IDiscoveryResultsIterator*&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const Exchange::Controller::IDiscovery* implementation = reinterpret_cast<const Exchange::Controller::IDiscovery*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::Controller::IDiscovery::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                Exchange::Controller::IDiscovery::Data::IDiscoveryResultsIterator* _results{};

                Core::hresult result = implementation->DiscoveryResults(_results);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<Core::hresult>(result);
                writer.Number<Core::instance_id>(RPC::instance_cast(_results));

                RPC::Administrator::Instance().RegisterInterface(channel, _results);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(hresult);
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::Controller::IDiscovery::ID, 1, hresult);
            }
        }
        , nullptr
    }; // ExchangeControllerDiscoveryStubMethods

    //
    // Exchange::Controller::IConfiguration interface stub definitions
    //
    // Methods:
    //  (0) virtual Core::hresult Persist(const Core::OptionalType<string>&) = 0
    //  (1) virtual Core::hresult Restore(const Core::OptionalType<string>&) = 0
    //  (2) virtual Core::hresult Configuration(const Core::OptionalType<string>&, string&) const = 0
    //  (3) virtual Core::hresult Configuration(const string&, const string&) = 0
    //  (4) virtual Core::hresult Attribute(const Core::OptionalType<Exchange::Controller::IConfiguration::attribute>&, string&) const = 0
    //  (5) virtual Core::hresult Attribute(const Exchange::Controller::IConfiguration::attribute, const string&) = 0
    //

    static ProxyStub::MethodHandler ExchangeControllerConfigurationStubMethods[] = {
        // (0) virtual Core::hresult Persist(const Core::OptionalType<string>&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                Exchange::Controller::IConfiguration* implementation = reinterpret_cast<Exchange::Controller::IConfiguration*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::Controller::IConfiguration::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                Core::OptionalType<string> _callsign{};
                if (reader.Length() < (1)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                if (reader.Boolean() == true) {
                    if (reader.Length() < (1)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    const uint16_t _callsignPeekedLen__ = reader.PeekNumber<uint16_t>();
                    if (reader.Length() < (static_cast<uint32_t>(1) + _callsignPeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    _callsign = reader.Text();
                }

                Core::hresult result = implementation->Persist(static_cast<const Core::OptionalType<string>&>(_callsign));

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<Core::hresult>(result);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(hresult);
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::Controller::IConfiguration::ID, 0, hresult);
            }
        },

        // (1) virtual Core::hresult Restore(const Core::OptionalType<string>&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                Exchange::Controller::IConfiguration* implementation = reinterpret_cast<Exchange::Controller::IConfiguration*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::Controller::IConfiguration::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                Core::OptionalType<string> _callsign{};
                if (reader.Length() < (1)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                if (reader.Boolean() == true) {
                    if (reader.Length() < (1)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    const uint16_t _callsignPeekedLen__ = reader.PeekNumber<uint16_t>();
                    if (reader.Length() < (static_cast<uint32_t>(1) + _callsignPeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    _callsign = reader.Text();
                }

                Core::hresult result = implementation->Restore(static_cast<const Core::OptionalType<string>&>(_callsign));

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<Core::hresult>(result);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(hresult);
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::Controller::IConfiguration::ID, 1, hresult);
            }
        },

        // (2) virtual Core::hresult Configuration(const Core::OptionalType<string>&, string&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const Exchange::Controller::IConfiguration* implementation = reinterpret_cast<const Exchange::Controller::IConfiguration*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::Controller::IConfiguration::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                Core::OptionalType<string> _callsign{};
                if (reader.Length() < (1)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                if (reader.Boolean() == true) {
                    if (reader.Length() < (1)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    const uint16_t _callsignPeekedLen__ = reader.PeekNumber<uint16_t>();
                    if (reader.Length() < (static_cast<uint32_t>(1) + _callsignPeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    _callsign = reader.Text();
                }

                string _configuration{};

                Core::hresult result = implementation->Configuration(static_cast<const Core::OptionalType<string>&>(_callsign), _configuration);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<Core::hresult>(result);
                writer.Text(_configuration);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(hresult);
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::Controller::IConfiguration::ID, 2, hresult);
            }
        },

        // (3) virtual Core::hresult Configuration(const string&, const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                Exchange::Controller::IConfiguration* implementation = reinterpret_cast<Exchange::Controller::IConfiguration*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::Controller::IConfiguration::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint16_t _callsignPeekedLen__ = reader.PeekNumber<uint16_t>();
                if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint16_t>()) + _callsignPeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const string _callsign = reader.Text();
                if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint16_t _configurationPeekedLen__ = reader.PeekNumber<uint16_t>();
                if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint16_t>()) + _configurationPeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const string _configuration = reader.Text();

                Core::hresult result = implementation->Configuration(static_cast<const string&>(_callsign), static_cast<const string&>(_configuration));

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<Core::hresult>(result);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(hresult);
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::Controller::IConfiguration::ID, 3, hresult);
            }
        },

        // (4) virtual Core::hresult Attribute(const Core::OptionalType<Exchange::Controller::IConfiguration::attribute>&, string&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const Exchange::Controller::IConfiguration* implementation = reinterpret_cast<const Exchange::Controller::IConfiguration*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::Controller::IConfiguration::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                Core::OptionalType<Exchange::Controller::IConfiguration::attribute> _attribute{};
                if (reader.Length() < (1)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                if (reader.Boolean() == true) {
                    if (reader.Length() < (1)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    _attribute = reader.Number<Exchange::Controller::IConfiguration::attribute>();
                }

                string _value{};

                Core::hresult result = implementation->Attribute(static_cast<const Core::OptionalType<Exchange::Controller::IConfiguration::attribute>&>(_attribute), _value);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<Core::hresult>(result);
                writer.Text(_value);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(hresult);
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::Controller::IConfiguration::ID, 4, hresult);
            }
        },

        // (5) virtual Core::hresult Attribute(const Exchange::Controller::IConfiguration::attribute, const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                Exchange::Controller::IConfiguration* implementation = reinterpret_cast<Exchange::Controller::IConfiguration*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::Controller::IConfiguration::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (Core::RealSize<Exchange::Controller::IConfiguration::attribute>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const Exchange::Controller::IConfiguration::attribute _attribute = reader.Number<Exchange::Controller::IConfiguration::attribute>();
                if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint16_t _valuePeekedLen__ = reader.PeekNumber<uint16_t>();
                if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint16_t>()) + _valuePeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const string _value = reader.Text();

                Core::hresult result = implementation->Attribute(_attribute, static_cast<const string&>(_value));

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<Core::hresult>(result);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(hresult);
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::Controller::IConfiguration::ID, 5, hresult);
            }
        }
        , nullptr
    }; // ExchangeControllerConfigurationStubMethods

    //
    // Exchange::Controller::ILifeTime interface stub definitions
    //
    // Methods:
    //  (0) virtual Core::hresult Register(Exchange::Controller::ILifeTime::INotification*, const Core::OptionalType<string>&) = 0
    //  (1) virtual Core::hresult Unregister(Exchange::Controller::ILifeTime::INotification*, const Core::OptionalType<string>&) = 0
    //  (2) virtual Core::hresult Activate(const string&) = 0
    //  (3) virtual Core::hresult Deactivate(const string&) = 0
    //  (4) virtual Core::hresult Unavailable(const string&) = 0
    //  (5) virtual Core::hresult Hibernate(const string&, const uint32_t) = 0
    //  (6) virtual Core::hresult Suspend(const string&) = 0
    //  (7) virtual Core::hresult Resume(const string&) = 0
    //

    static ProxyStub::MethodHandler ExchangeControllerLifeTimeStubMethods[] = {
        // (0) virtual Core::hresult Register(Exchange::Controller::ILifeTime::INotification*, const Core::OptionalType<string>&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                Exchange::Controller::ILifeTime* implementation = reinterpret_cast<Exchange::Controller::ILifeTime*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::Controller::ILifeTime::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (sizeof(Core::instance_id))) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                Core::instance_id _sinkInstanceId__ = reader.Number<Core::instance_id>();
                Core::OptionalType<string> _callsign{};
                if (reader.Length() < (1)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                if (reader.Boolean() == true) {
                    if (reader.Length() < (1)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    const uint16_t _callsignPeekedLen__ = reader.PeekNumber<uint16_t>();
                    if (reader.Length() < (static_cast<uint32_t>(1) + _callsignPeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    _callsign = reader.Text();
                }

                Exchange::Controller::ILifeTime::INotification* _sink{};
                ProxyStub::UnknownProxy* _sinkProxy__ = nullptr;
                if (_sinkInstanceId__ != 0) {
                    _sinkProxy__ = RPC::Administrator::Instance().ProxyInstance(channel, _sinkInstanceId__, false, _sink);
                    ASSERT((_sink != nullptr) && (_sinkProxy__ != nullptr));
                    if ((_sink == nullptr) || (_sinkProxy__ == nullptr)) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }
                }

                Core::hresult result = implementation->Register(_sink, static_cast<const Core::OptionalType<string>&>(_callsign));

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<Core::hresult>(result);

                if (_sinkProxy__ != nullptr) {
                    RPC::Administrator::Instance().Release(_sinkProxy__, message->Response());
                }

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(hresult);
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::Controller::ILifeTime::ID, 0, hresult);
            }
        },

        // (1) virtual Core::hresult Unregister(Exchange::Controller::ILifeTime::INotification*, const Core::OptionalType<string>&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                Exchange::Controller::ILifeTime* implementation = reinterpret_cast<Exchange::Controller::ILifeTime*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::Controller::ILifeTime::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (sizeof(Core::instance_id))) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                Core::instance_id _sinkInstanceId__ = reader.Number<Core::instance_id>();
                Core::OptionalType<string> _callsign{};
                if (reader.Length() < (1)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                if (reader.Boolean() == true) {
                    if (reader.Length() < (1)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    const uint16_t _callsignPeekedLen__ = reader.PeekNumber<uint16_t>();
                    if (reader.Length() < (static_cast<uint32_t>(1) + _callsignPeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    _callsign = reader.Text();
                }

                Exchange::Controller::ILifeTime::INotification* _sink{};
                ProxyStub::UnknownProxy* _sinkProxy__ = nullptr;
                if (_sinkInstanceId__ != 0) {
                    _sinkProxy__ = RPC::Administrator::Instance().ProxyInstance(channel, _sinkInstanceId__, false, _sink);
                    ASSERT((_sink != nullptr) && (_sinkProxy__ != nullptr));
                    if ((_sink == nullptr) || (_sinkProxy__ == nullptr)) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }
                }

                Core::hresult result = implementation->Unregister(_sink, static_cast<const Core::OptionalType<string>&>(_callsign));

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<Core::hresult>(result);

                if (_sinkProxy__ != nullptr) {
                    RPC::Administrator::Instance().Release(_sinkProxy__, message->Response());
                }

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(hresult);
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::Controller::ILifeTime::ID, 1, hresult);
            }
        },

        // (2) virtual Core::hresult Activate(const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                Exchange::Controller::ILifeTime* implementation = reinterpret_cast<Exchange::Controller::ILifeTime*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::Controller::ILifeTime::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint16_t _callsignPeekedLen__ = reader.PeekNumber<uint16_t>();
                if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint16_t>()) + _callsignPeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const string _callsign = reader.Text();

                Core::hresult result = implementation->Activate(static_cast<const string&>(_callsign));

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<Core::hresult>(result);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(hresult);
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::Controller::ILifeTime::ID, 2, hresult);
            }
        },

        // (3) virtual Core::hresult Deactivate(const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                Exchange::Controller::ILifeTime* implementation = reinterpret_cast<Exchange::Controller::ILifeTime*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::Controller::ILifeTime::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint16_t _callsignPeekedLen__ = reader.PeekNumber<uint16_t>();
                if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint16_t>()) + _callsignPeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const string _callsign = reader.Text();

                Core::hresult result = implementation->Deactivate(static_cast<const string&>(_callsign));

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<Core::hresult>(result);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(hresult);
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::Controller::ILifeTime::ID, 3, hresult);
            }
        },

        // (4) virtual Core::hresult Unavailable(const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                Exchange::Controller::ILifeTime* implementation = reinterpret_cast<Exchange::Controller::ILifeTime*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::Controller::ILifeTime::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint16_t _callsignPeekedLen__ = reader.PeekNumber<uint16_t>();
                if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint16_t>()) + _callsignPeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const string _callsign = reader.Text();

                Core::hresult result = implementation->Unavailable(static_cast<const string&>(_callsign));

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<Core::hresult>(result);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(hresult);
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::Controller::ILifeTime::ID, 4, hresult);
            }
        },

        // (5) virtual Core::hresult Hibernate(const string&, const uint32_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                Exchange::Controller::ILifeTime* implementation = reinterpret_cast<Exchange::Controller::ILifeTime*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::Controller::ILifeTime::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint16_t _callsignPeekedLen__ = reader.PeekNumber<uint16_t>();
                if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint16_t>()) + _callsignPeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const string _callsign = reader.Text();
                if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint32_t _timeout = reader.Number<uint32_t>();

                Core::hresult result = implementation->Hibernate(static_cast<const string&>(_callsign), _timeout);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<Core::hresult>(result);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(hresult);
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::Controller::ILifeTime::ID, 5, hresult);
            }
        },

        // (6) virtual Core::hresult Suspend(const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                Exchange::Controller::ILifeTime* implementation = reinterpret_cast<Exchange::Controller::ILifeTime*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::Controller::ILifeTime::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint16_t _callsignPeekedLen__ = reader.PeekNumber<uint16_t>();
                if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint16_t>()) + _callsignPeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const string _callsign = reader.Text();

                Core::hresult result = implementation->Suspend(static_cast<const string&>(_callsign));

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<Core::hresult>(result);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(hresult);
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::Controller::ILifeTime::ID, 6, hresult);
            }
        },

        // (7) virtual Core::hresult Resume(const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                Exchange::Controller::ILifeTime* implementation = reinterpret_cast<Exchange::Controller::ILifeTime*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::Controller::ILifeTime::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint16_t _callsignPeekedLen__ = reader.PeekNumber<uint16_t>();
                if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint16_t>()) + _callsignPeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const string _callsign = reader.Text();

                Core::hresult result = implementation->Resume(static_cast<const string&>(_callsign));

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<Core::hresult>(result);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(hresult);
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::Controller::ILifeTime::ID, 7, hresult);
            }
        }
        , nullptr
    }; // ExchangeControllerLifeTimeStubMethods

    //
    // Exchange::Controller::ILifeTime::INotification interface stub definitions
    //
    // Methods:
    //  (0) virtual void StateChange(const string&, const PluginHost::IShell::state&, const PluginHost::IShell::reason&) = 0
    //  (1) virtual void StateControlStateChange(const string&, const Exchange::Controller::ILifeTime::state&) = 0
    //

    static ProxyStub::MethodHandler ExchangeControllerLifeTimeNotificationStubMethods[] = {
        // (0) virtual void StateChange(const string&, const PluginHost::IShell::state&, const PluginHost::IShell::reason&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                Exchange::Controller::ILifeTime::INotification* implementation = reinterpret_cast<Exchange::Controller::ILifeTime::INotification*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::Controller::ILifeTime::INotification::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint16_t _callsignPeekedLen__ = reader.PeekNumber<uint16_t>();
                if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint16_t>()) + _callsignPeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const string _callsign = reader.Text();
                if (reader.Length() < (Core::RealSize<PluginHost::IShell::state>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const PluginHost::IShell::state _state = reader.Number<PluginHost::IShell::state>();
                if (reader.Length() < (Core::RealSize<PluginHost::IShell::reason>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const PluginHost::IShell::reason _reason = reader.Number<PluginHost::IShell::reason>();

                implementation->StateChange(static_cast<const string&>(_callsign), static_cast<const PluginHost::IShell::state&>(_state), static_cast<const PluginHost::IShell::reason&>(_reason));

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::Controller::ILifeTime::INotification::ID, 0, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        },

        // (1) virtual void StateControlStateChange(const string&, const Exchange::Controller::ILifeTime::state&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                Exchange::Controller::ILifeTime::INotification* implementation = reinterpret_cast<Exchange::Controller::ILifeTime::INotification*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::Controller::ILifeTime::INotification::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint16_t _callsignPeekedLen__ = reader.PeekNumber<uint16_t>();
                if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint16_t>()) + _callsignPeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const string _callsign = reader.Text();
                if (reader.Length() < (Core::RealSize<Exchange::Controller::ILifeTime::state>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const Exchange::Controller::ILifeTime::state _state = reader.Number<Exchange::Controller::ILifeTime::state>();

                implementation->StateControlStateChange(static_cast<const string&>(_callsign), static_cast<const Exchange::Controller::ILifeTime::state&>(_state));

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::Controller::ILifeTime::INotification::ID, 1, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        }
        , nullptr
    }; // ExchangeControllerLifeTimeNotificationStubMethods

    //
    // Exchange::Controller::IShells interface stub definitions
    //
    // Methods:
    //  (0) virtual Core::hresult Register(Exchange::Controller::IShells::INotification*) = 0
    //  (1) virtual Core::hresult Unregister(Exchange::Controller::IShells::INotification*) = 0
    //

    static ProxyStub::MethodHandler ExchangeControllerShellsStubMethods[] = {
        // (0) virtual Core::hresult Register(Exchange::Controller::IShells::INotification*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                Exchange::Controller::IShells* implementation = reinterpret_cast<Exchange::Controller::IShells*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::Controller::IShells::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (sizeof(Core::instance_id))) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                Core::instance_id _sinkInstanceId__ = reader.Number<Core::instance_id>();

                Exchange::Controller::IShells::INotification* _sink{};
                ProxyStub::UnknownProxy* _sinkProxy__ = nullptr;
                if (_sinkInstanceId__ != 0) {
                    _sinkProxy__ = RPC::Administrator::Instance().ProxyInstance(channel, _sinkInstanceId__, false, _sink);
                    ASSERT((_sink != nullptr) && (_sinkProxy__ != nullptr));
                    if ((_sink == nullptr) || (_sinkProxy__ == nullptr)) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }
                }

                Core::hresult result = implementation->Register(_sink);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<Core::hresult>(result);

                if (_sinkProxy__ != nullptr) {
                    RPC::Administrator::Instance().Release(_sinkProxy__, message->Response());
                }

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(hresult);
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::Controller::IShells::ID, 0, hresult);
            }
        },

        // (1) virtual Core::hresult Unregister(Exchange::Controller::IShells::INotification*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                Exchange::Controller::IShells* implementation = reinterpret_cast<Exchange::Controller::IShells*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::Controller::IShells::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (sizeof(Core::instance_id))) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                Core::instance_id _sinkInstanceId__ = reader.Number<Core::instance_id>();

                Exchange::Controller::IShells::INotification* _sink{};
                ProxyStub::UnknownProxy* _sinkProxy__ = nullptr;
                if (_sinkInstanceId__ != 0) {
                    _sinkProxy__ = RPC::Administrator::Instance().ProxyInstance(channel, _sinkInstanceId__, false, _sink);
                    ASSERT((_sink != nullptr) && (_sinkProxy__ != nullptr));
                    if ((_sink == nullptr) || (_sinkProxy__ == nullptr)) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }
                }

                Core::hresult result = implementation->Unregister(_sink);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<Core::hresult>(result);

                if (_sinkProxy__ != nullptr) {
                    RPC::Administrator::Instance().Release(_sinkProxy__, message->Response());
                }

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(hresult);
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::Controller::IShells::ID, 1, hresult);
            }
        }
        , nullptr
    }; // ExchangeControllerShellsStubMethods

    //
    // Exchange::Controller::IShells::INotification interface stub definitions
    //
    // Methods:
    //  (0) virtual void Created(const string&, PluginHost::IShell*) = 0
    //  (1) virtual void Destroy(const string&, PluginHost::IShell*) = 0
    //

    static ProxyStub::MethodHandler ExchangeControllerShellsNotificationStubMethods[] = {
        // (0) virtual void Created(const string&, PluginHost::IShell*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                Exchange::Controller::IShells::INotification* implementation = reinterpret_cast<Exchange::Controller::IShells::INotification*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::Controller::IShells::INotification::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint16_t _callsignPeekedLen__ = reader.PeekNumber<uint16_t>();
                if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint16_t>()) + _callsignPeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const string _callsign = reader.Text();
                if (reader.Length() < (sizeof(Core::instance_id))) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                Core::instance_id _pluginInstanceId__ = reader.Number<Core::instance_id>();

                PluginHost::IShell* _plugin{};
                ProxyStub::UnknownProxy* _pluginProxy__ = nullptr;
                if (_pluginInstanceId__ != 0) {
                    _pluginProxy__ = RPC::Administrator::Instance().ProxyInstance(channel, _pluginInstanceId__, false, _plugin);
                    ASSERT((_plugin != nullptr) && (_pluginProxy__ != nullptr));
                    if ((_plugin == nullptr) || (_pluginProxy__ == nullptr)) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }
                }

                implementation->Created(static_cast<const string&>(_callsign), _plugin);

                if (_pluginProxy__ != nullptr) {
                    RPC::Administrator::Instance().Release(_pluginProxy__, message->Response());
                }

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::Controller::IShells::INotification::ID, 0, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        },

        // (1) virtual void Destroy(const string&, PluginHost::IShell*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                Exchange::Controller::IShells::INotification* implementation = reinterpret_cast<Exchange::Controller::IShells::INotification*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::Controller::IShells::INotification::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint16_t _callsignPeekedLen__ = reader.PeekNumber<uint16_t>();
                if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint16_t>()) + _callsignPeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const string _callsign = reader.Text();
                if (reader.Length() < (sizeof(Core::instance_id))) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                Core::instance_id _pluginInstanceId__ = reader.Number<Core::instance_id>();

                PluginHost::IShell* _plugin{};
                ProxyStub::UnknownProxy* _pluginProxy__ = nullptr;
                if (_pluginInstanceId__ != 0) {
                    _pluginProxy__ = RPC::Administrator::Instance().ProxyInstance(channel, _pluginInstanceId__, false, _plugin);
                    ASSERT((_plugin != nullptr) && (_pluginProxy__ != nullptr));
                    if ((_plugin == nullptr) || (_pluginProxy__ == nullptr)) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }
                }

                implementation->Destroy(static_cast<const string&>(_callsign), _plugin);

                if (_pluginProxy__ != nullptr) {
                    RPC::Administrator::Instance().Release(_pluginProxy__, message->Response());
                }

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::Controller::IShells::INotification::ID, 1, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        }
        , nullptr
    }; // ExchangeControllerShellsNotificationStubMethods

    //
    // Exchange::Controller::ISubsystems interface stub definitions
    //
    // Methods:
    //  (0) virtual Core::hresult Subsystems(Exchange::Controller::ISubsystems::ISubsystemsIterator*&) const = 0
    //

    static ProxyStub::MethodHandler ExchangeControllerSubsystemsStubMethods[] = {
        // (0) virtual Core::hresult Subsystems(Exchange::Controller::ISubsystems::ISubsystemsIterator*&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const Exchange::Controller::ISubsystems* implementation = reinterpret_cast<const Exchange::Controller::ISubsystems*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::Controller::ISubsystems::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                Exchange::Controller::ISubsystems::ISubsystemsIterator* _subsystems{};

                Core::hresult result = implementation->Subsystems(_subsystems);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<Core::hresult>(result);
                writer.Number<Core::instance_id>(RPC::instance_cast(_subsystems));

                RPC::Administrator::Instance().RegisterInterface(channel, _subsystems);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(hresult);
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::Controller::ISubsystems::ID, 0, hresult);
            }
        }
        , nullptr
    }; // ExchangeControllerSubsystemsStubMethods

    //
    // Exchange::Controller::ISubsystems::INotification interface stub definitions
    //
    // Methods:
    //  (0) virtual void SubsystemChange(Exchange::Controller::ISubsystems::ISubsystemsIterator* const) = 0
    //

    static ProxyStub::MethodHandler ExchangeControllerSubsystemsNotificationStubMethods[] = {
        // (0) virtual void SubsystemChange(Exchange::Controller::ISubsystems::ISubsystemsIterator* const) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                Exchange::Controller::ISubsystems::INotification* implementation = reinterpret_cast<Exchange::Controller::ISubsystems::INotification*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::Controller::ISubsystems::INotification::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (sizeof(Core::instance_id))) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                Core::instance_id _subsystemsInstanceId__ = reader.Number<Core::instance_id>();

                Exchange::Controller::ISubsystems::ISubsystemsIterator* _subsystems{};
                ProxyStub::UnknownProxy* _subsystemsProxy__ = nullptr;
                if (_subsystemsInstanceId__ != 0) {
                    _subsystemsProxy__ = RPC::Administrator::Instance().ProxyInstance(channel, _subsystemsInstanceId__, false, _subsystems);
                    ASSERT((_subsystems != nullptr) && (_subsystemsProxy__ != nullptr));
                    if ((_subsystems == nullptr) || (_subsystemsProxy__ == nullptr)) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }
                }

                implementation->SubsystemChange(_subsystems);

                if (_subsystemsProxy__ != nullptr) {
                    RPC::Administrator::Instance().Release(_subsystemsProxy__, message->Response());
                }

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::Controller::ISubsystems::INotification::ID, 0, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        }
        , nullptr
    }; // ExchangeControllerSubsystemsNotificationStubMethods

    //
    // Exchange::Controller::IEvents::INotification interface stub definitions
    //
    // Methods:
    //  (0) virtual void ForwardMessage(const string&, const Core::OptionalType<string>&, const Core::OptionalType<string>&) = 0
    //

    static ProxyStub::MethodHandler ExchangeControllerEventsNotificationStubMethods[] = {
        // (0) virtual void ForwardMessage(const string&, const Core::OptionalType<string>&, const Core::OptionalType<string>&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                Exchange::Controller::IEvents::INotification* implementation = reinterpret_cast<Exchange::Controller::IEvents::INotification*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::Controller::IEvents::INotification::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint16_t _eventPeekedLen__ = reader.PeekNumber<uint16_t>();
                if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint16_t>()) + _eventPeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const string _event = reader.Text();
                Core::OptionalType<string> _callsign{};
                if (reader.Length() < (1)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                if (reader.Boolean() == true) {
                    if (reader.Length() < (1)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    const uint16_t _callsignPeekedLen__ = reader.PeekNumber<uint16_t>();
                    if (reader.Length() < (static_cast<uint32_t>(1) + _callsignPeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    _callsign = reader.Text();
                }
                Core::OptionalType<string> _params{};
                if (reader.Length() < (1)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                if (reader.Boolean() == true) {
                    if (reader.Length() < (1)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    const uint16_t _paramsPeekedLen__ = reader.PeekNumber<uint16_t>();
                    if (reader.Length() < (static_cast<uint32_t>(1) + _paramsPeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    _params = reader.Text();
                }

                implementation->ForwardMessage(static_cast<const string&>(_event), static_cast<const Core::OptionalType<string>&>(_callsign), static_cast<const Core::OptionalType<string>&>(_params));

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::Controller::IEvents::INotification::ID, 0, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        }
        , nullptr
    }; // ExchangeControllerEventsNotificationStubMethods

    //
    // Exchange::Controller::IMetadata interface stub definitions
    //
    // Methods:
    //  (0) virtual Core::hresult Services(const Core::OptionalType<string>&, Exchange::Controller::IMetadata::Data::IServicesIterator*&) const = 0
    //  (1) virtual Core::hresult Links(Exchange::Controller::IMetadata::Data::ILinksIterator*&) const = 0
    //  (2) virtual Core::hresult Proxies(const Core::OptionalType<string>&, Exchange::Controller::IMetadata::Data::IProxiesIterator*&) const = 0
    //  (3) virtual Core::hresult Framework(Exchange::Controller::IMetadata::Data::Version&) const = 0
    //  (4) virtual Core::hresult Threads(Exchange::Controller::IMetadata::Data::IThreadsIterator*&) const = 0
    //  (5) virtual Core::hresult PendingRequests(Exchange::Controller::IMetadata::Data::IPendingRequestsIterator*&) const = 0
    //  (6) virtual Core::hresult CallStack(const uint8_t, Exchange::Controller::IMetadata::Data::ICallStackIterator*&) const = 0
    //  (7) virtual Core::hresult BuildInfo(Exchange::Controller::IMetadata::Data::BuildInfo&) const = 0
    //

    static ProxyStub::MethodHandler ExchangeControllerMetadataStubMethods[] = {
        // (0) virtual Core::hresult Services(const Core::OptionalType<string>&, Exchange::Controller::IMetadata::Data::IServicesIterator*&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const Exchange::Controller::IMetadata* implementation = reinterpret_cast<const Exchange::Controller::IMetadata*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::Controller::IMetadata::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                Core::OptionalType<string> _callsign{};
                if (reader.Length() < (1)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                if (reader.Boolean() == true) {
                    if (reader.Length() < (1)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    const uint16_t _callsignPeekedLen__ = reader.PeekNumber<uint16_t>();
                    if (reader.Length() < (static_cast<uint32_t>(1) + _callsignPeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    _callsign = reader.Text();
                }

                Exchange::Controller::IMetadata::Data::IServicesIterator* _services{};

                Core::hresult result = implementation->Services(static_cast<const Core::OptionalType<string>&>(_callsign), _services);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<Core::hresult>(result);
                writer.Number<Core::instance_id>(RPC::instance_cast(_services));

                RPC::Administrator::Instance().RegisterInterface(channel, _services);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(hresult);
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::Controller::IMetadata::ID, 0, hresult);
            }
        },

        // (1) virtual Core::hresult Links(Exchange::Controller::IMetadata::Data::ILinksIterator*&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const Exchange::Controller::IMetadata* implementation = reinterpret_cast<const Exchange::Controller::IMetadata*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::Controller::IMetadata::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                Exchange::Controller::IMetadata::Data::ILinksIterator* _links{};

                Core::hresult result = implementation->Links(_links);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<Core::hresult>(result);
                writer.Number<Core::instance_id>(RPC::instance_cast(_links));

                RPC::Administrator::Instance().RegisterInterface(channel, _links);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(hresult);
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::Controller::IMetadata::ID, 1, hresult);
            }
        },

        // (2) virtual Core::hresult Proxies(const Core::OptionalType<string>&, Exchange::Controller::IMetadata::Data::IProxiesIterator*&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const Exchange::Controller::IMetadata* implementation = reinterpret_cast<const Exchange::Controller::IMetadata*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::Controller::IMetadata::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                Core::OptionalType<string> _linkID{};
                if (reader.Length() < (1)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                if (reader.Boolean() == true) {
                    if (reader.Length() < (1)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    const uint16_t _linkIDPeekedLen__ = reader.PeekNumber<uint16_t>();
                    if (reader.Length() < (static_cast<uint32_t>(1) + _linkIDPeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    _linkID = reader.Text();
                }

                Exchange::Controller::IMetadata::Data::IProxiesIterator* _proxies{};

                Core::hresult result = implementation->Proxies(static_cast<const Core::OptionalType<string>&>(_linkID), _proxies);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<Core::hresult>(result);
                writer.Number<Core::instance_id>(RPC::instance_cast(_proxies));

                RPC::Administrator::Instance().RegisterInterface(channel, _proxies);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(hresult);
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::Controller::IMetadata::ID, 2, hresult);
            }
        },

        // (3) virtual Core::hresult Framework(Exchange::Controller::IMetadata::Data::Version&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const Exchange::Controller::IMetadata* implementation = reinterpret_cast<const Exchange::Controller::IMetadata*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::Controller::IMetadata::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                Exchange::Controller::IMetadata::Data::Version _version{};

                Core::hresult result = implementation->Framework(_version);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<Core::hresult>(result);
                writer.Text<uint8_t>(_version.Hash);
                writer.Number<uint8_t>(_version.Major);
                writer.Number<uint8_t>(_version.Minor);
                writer.Number<uint8_t>(_version.Patch);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(hresult);
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::Controller::IMetadata::ID, 3, hresult);
            }
        },

        // (4) virtual Core::hresult Threads(Exchange::Controller::IMetadata::Data::IThreadsIterator*&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const Exchange::Controller::IMetadata* implementation = reinterpret_cast<const Exchange::Controller::IMetadata*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::Controller::IMetadata::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                Exchange::Controller::IMetadata::Data::IThreadsIterator* _threads{};

                Core::hresult result = implementation->Threads(_threads);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<Core::hresult>(result);
                writer.Number<Core::instance_id>(RPC::instance_cast(_threads));

                RPC::Administrator::Instance().RegisterInterface(channel, _threads);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(hresult);
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::Controller::IMetadata::ID, 4, hresult);
            }
        },

        // (5) virtual Core::hresult PendingRequests(Exchange::Controller::IMetadata::Data::IPendingRequestsIterator*&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const Exchange::Controller::IMetadata* implementation = reinterpret_cast<const Exchange::Controller::IMetadata*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::Controller::IMetadata::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                Exchange::Controller::IMetadata::Data::IPendingRequestsIterator* _requests{};

                Core::hresult result = implementation->PendingRequests(_requests);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<Core::hresult>(result);
                writer.Number<Core::instance_id>(RPC::instance_cast(_requests));

                RPC::Administrator::Instance().RegisterInterface(channel, _requests);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(hresult);
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::Controller::IMetadata::ID, 5, hresult);
            }
        },

        // (6) virtual Core::hresult CallStack(const uint8_t, Exchange::Controller::IMetadata::Data::ICallStackIterator*&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const Exchange::Controller::IMetadata* implementation = reinterpret_cast<const Exchange::Controller::IMetadata*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::Controller::IMetadata::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (Core::RealSize<uint8_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint8_t _thread = reader.Number<uint8_t>();

                Exchange::Controller::IMetadata::Data::ICallStackIterator* _callstack{};

                Core::hresult result = implementation->CallStack(_thread, _callstack);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<Core::hresult>(result);
                writer.Number<Core::instance_id>(RPC::instance_cast(_callstack));

                RPC::Administrator::Instance().RegisterInterface(channel, _callstack);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(hresult);
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::Controller::IMetadata::ID, 6, hresult);
            }
        },

        // (7) virtual Core::hresult BuildInfo(Exchange::Controller::IMetadata::Data::BuildInfo&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const Exchange::Controller::IMetadata* implementation = reinterpret_cast<const Exchange::Controller::IMetadata*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::Controller::IMetadata::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                Exchange::Controller::IMetadata::Data::BuildInfo _buildInfo{};

                Core::hresult result = implementation->BuildInfo(_buildInfo);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<Core::hresult>(result);
                writer.Number<Exchange::Controller::IMetadata::Data::BuildInfo::systemtype>(_buildInfo.SystemType);
                writer.Number<Exchange::Controller::IMetadata::Data::BuildInfo::buildtype>(_buildInfo.BuildType);
                writer.Boolean(_buildInfo.Extensions.IsSet());
                if (_buildInfo.Extensions.IsSet() == true) {
                    writer.Number<Exchange::Controller::IMetadata::Data::BuildInfo::extensiontype>(_buildInfo.Extensions.Value());
                }
                writer.Boolean(_buildInfo.Messaging);
                writer.Boolean(_buildInfo.ExceptionCatching);
                writer.Boolean(_buildInfo.DeadlockDetection);
                writer.Boolean(_buildInfo.WCharSupport);
                writer.Number<uint8_t>(_buildInfo.InstanceIDBits);
                writer.Boolean(_buildInfo.TraceLevel.IsSet());
                if (_buildInfo.TraceLevel.IsSet() == true) {
                    writer.Number<uint8_t>(_buildInfo.TraceLevel.Value());
                }
                writer.Number<uint8_t>(_buildInfo.ThreadPoolCount);
                writer.Number<uint32_t>(_buildInfo.COMRPCTimeOut);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(hresult);
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::Controller::IMetadata::ID, 7, hresult);
            }
        }
        , nullptr
    }; // ExchangeControllerMetadataStubMethods

    // -----------------------------------------------------------------
    // PROXIES
    // -----------------------------------------------------------------

    //
    // Exchange::Controller::ISystem interface proxy definitions
    //
    // Methods:
    //  (0) virtual Core::hresult Reboot() = 0
    //  (1) virtual Core::hresult Delete(const string&) = 0
    //  (2) virtual Core::hresult Clone(const string&, const string&, string&) = 0
    //  (3) virtual Core::hresult Destroy(const string&) = 0
    //  (4) virtual Core::hresult Environment(const string&, string&) const = 0
    //

    class ExchangeControllerSystemProxy final : public ProxyStub::UnknownProxyType<Exchange::Controller::ISystem> {
    public:
        ExchangeControllerSystemProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        Core::hresult Reboot() override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

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
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::Controller::ISystem::ID, 0, hresult);
            }

            return (hresult);
        }

        Core::hresult Delete(const string& _path) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_path);

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
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::Controller::ISystem::ID, 1, hresult);
            }

            return (hresult);
        }

        Core::hresult Clone(const string& _callsign, const string& _newcallsign, string& _response) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(2));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_callsign);
            writer.Text(_newcallsign);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<Core::hresult>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    hresult = reader.Number<Core::hresult>();
                    if ((hresult & COM_ERROR) == 0) {
                        if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                        const uint16_t _responsePeekedLen__ = reader.PeekNumber<uint16_t>();
                        if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint16_t>()) + _responsePeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                        _response = reader.Text();
                    }

                    return (hresult);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::Controller::ISystem::ID, 2, hresult);
            }

            return (hresult);
        }

        Core::hresult Destroy(const string& _callsign) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(3));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_callsign);

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
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::Controller::ISystem::ID, 3, hresult);
            }

            return (hresult);
        }

        Core::hresult Environment(const string& _variable, string& _value) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(4));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_variable);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<Core::hresult>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    hresult = reader.Number<Core::hresult>();
                    if ((hresult & COM_ERROR) == 0) {
                        if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                        const uint16_t _valuePeekedLen__ = reader.PeekNumber<uint16_t>();
                        if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint16_t>()) + _valuePeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                        _value = reader.Text();
                    }

                    return (hresult);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::Controller::ISystem::ID, 4, hresult);
            }

            return (hresult);
        }

    }; // class ExchangeControllerSystemProxy

    //
    // Exchange::Controller::IDiscovery interface proxy definitions
    //
    // Methods:
    //  (0) virtual Core::hresult StartDiscovery(const Core::OptionalType<uint8_t>&) = 0
    //  (1) virtual Core::hresult DiscoveryResults(Exchange::Controller::IDiscovery::Data::IDiscoveryResultsIterator*&) const = 0
    //

    class ExchangeControllerDiscoveryProxy final : public ProxyStub::UnknownProxyType<Exchange::Controller::IDiscovery> {
    public:
        ExchangeControllerDiscoveryProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        Core::hresult StartDiscovery(const Core::OptionalType<uint8_t>& _ttl) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Boolean(_ttl.IsSet());
            if (_ttl.IsSet() == true) {
                writer.Number<uint8_t>(_ttl.Value());
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
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::Controller::IDiscovery::ID, 0, hresult);
            }

            return (hresult);
        }

        Core::hresult DiscoveryResults(Exchange::Controller::IDiscovery::Data::IDiscoveryResultsIterator*& _results) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<Core::hresult>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    hresult = reader.Number<Core::hresult>();
                    if ((hresult & COM_ERROR) == 0) {
                        _results = reinterpret_cast<Exchange::Controller::IDiscovery::Data::IDiscoveryResultsIterator*>(static_cast<const ProxyStub::UnknownProxy&>(*this).Interface(reader.Number<Core::instance_id>(), Exchange::Controller::IDiscovery::Data::IDiscoveryResultsIterator::ID));
                    }

                    return (hresult);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::Controller::IDiscovery::ID, 1, hresult);
            }

            return (hresult);
        }

    }; // class ExchangeControllerDiscoveryProxy

    //
    // Exchange::Controller::IConfiguration interface proxy definitions
    //
    // Methods:
    //  (0) virtual Core::hresult Persist(const Core::OptionalType<string>&) = 0
    //  (1) virtual Core::hresult Restore(const Core::OptionalType<string>&) = 0
    //  (2) virtual Core::hresult Configuration(const Core::OptionalType<string>&, string&) const = 0
    //  (3) virtual Core::hresult Configuration(const string&, const string&) = 0
    //  (4) virtual Core::hresult Attribute(const Core::OptionalType<Exchange::Controller::IConfiguration::attribute>&, string&) const = 0
    //  (5) virtual Core::hresult Attribute(const Exchange::Controller::IConfiguration::attribute, const string&) = 0
    //

    class ExchangeControllerConfigurationProxy final : public ProxyStub::UnknownProxyType<Exchange::Controller::IConfiguration> {
    public:
        ExchangeControllerConfigurationProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        Core::hresult Persist(const Core::OptionalType<string>& _callsign) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Boolean(_callsign.IsSet());
            if (_callsign.IsSet() == true) {
                writer.Text(_callsign.Value());
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
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::Controller::IConfiguration::ID, 0, hresult);
            }

            return (hresult);
        }

        Core::hresult Restore(const Core::OptionalType<string>& _callsign) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Boolean(_callsign.IsSet());
            if (_callsign.IsSet() == true) {
                writer.Text(_callsign.Value());
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
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::Controller::IConfiguration::ID, 1, hresult);
            }

            return (hresult);
        }

        Core::hresult Configuration(const Core::OptionalType<string>& _callsign, string& _configuration) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(2));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Boolean(_callsign.IsSet());
            if (_callsign.IsSet() == true) {
                writer.Text(_callsign.Value());
            }

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<Core::hresult>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    hresult = reader.Number<Core::hresult>();
                    if ((hresult & COM_ERROR) == 0) {
                        if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                        const uint16_t _configurationPeekedLen__ = reader.PeekNumber<uint16_t>();
                        if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint16_t>()) + _configurationPeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                        _configuration = reader.Text();
                    }

                    return (hresult);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::Controller::IConfiguration::ID, 2, hresult);
            }

            return (hresult);
        }

        Core::hresult Configuration(const string& _callsign, const string& _configuration) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(3));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_callsign);
            writer.Text(_configuration);

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
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::Controller::IConfiguration::ID, 3, hresult);
            }

            return (hresult);
        }

        Core::hresult Attribute(const Core::OptionalType<Exchange::Controller::IConfiguration::attribute>& _attribute, string& _value) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(4));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Boolean(_attribute.IsSet());
            if (_attribute.IsSet() == true) {
                writer.Number<Exchange::Controller::IConfiguration::attribute>(_attribute.Value());
            }

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<Core::hresult>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    hresult = reader.Number<Core::hresult>();
                    if ((hresult & COM_ERROR) == 0) {
                        if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                        const uint16_t _valuePeekedLen__ = reader.PeekNumber<uint16_t>();
                        if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint16_t>()) + _valuePeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                        _value = reader.Text();
                    }

                    return (hresult);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::Controller::IConfiguration::ID, 4, hresult);
            }

            return (hresult);
        }

        Core::hresult Attribute(const Exchange::Controller::IConfiguration::attribute _attribute, const string& _value) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(5));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Exchange::Controller::IConfiguration::attribute>(_attribute);
            writer.Text(_value);

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
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::Controller::IConfiguration::ID, 5, hresult);
            }

            return (hresult);
        }

    }; // class ExchangeControllerConfigurationProxy

    //
    // Exchange::Controller::ILifeTime interface proxy definitions
    //
    // Methods:
    //  (0) virtual Core::hresult Register(Exchange::Controller::ILifeTime::INotification*, const Core::OptionalType<string>&) = 0
    //  (1) virtual Core::hresult Unregister(Exchange::Controller::ILifeTime::INotification*, const Core::OptionalType<string>&) = 0
    //  (2) virtual Core::hresult Activate(const string&) = 0
    //  (3) virtual Core::hresult Deactivate(const string&) = 0
    //  (4) virtual Core::hresult Unavailable(const string&) = 0
    //  (5) virtual Core::hresult Hibernate(const string&, const uint32_t) = 0
    //  (6) virtual Core::hresult Suspend(const string&) = 0
    //  (7) virtual Core::hresult Resume(const string&) = 0
    //

    class ExchangeControllerLifeTimeProxy final : public ProxyStub::UnknownProxyType<Exchange::Controller::ILifeTime> {
    public:
        ExchangeControllerLifeTimeProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        Core::hresult Register(Exchange::Controller::ILifeTime::INotification* _sink, const Core::OptionalType<string>& _callsign) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_sink));
            writer.Boolean(_callsign.IsSet());
            if (_callsign.IsSet() == true) {
                writer.Text(_callsign.Value());
            }

            const RPC::InstanceRecord passedInstances[] = { { RPC::instance_cast(_sink), Exchange::Controller::ILifeTime::INotification::ID }, { 0, 0 } };
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
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::Controller::ILifeTime::ID, 0, hresult);
            }

            static_cast<const ProxyStub::UnknownProxy&>(*this).Channel()->CustomData(nullptr);

            return (hresult);
        }

        Core::hresult Unregister(Exchange::Controller::ILifeTime::INotification* _sink, const Core::OptionalType<string>& _callsign) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_sink));
            writer.Boolean(_callsign.IsSet());
            if (_callsign.IsSet() == true) {
                writer.Text(_callsign.Value());
            }

            const RPC::InstanceRecord passedInstances[] = { { RPC::instance_cast(_sink), Exchange::Controller::ILifeTime::INotification::ID }, { 0, 0 } };
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
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::Controller::ILifeTime::ID, 1, hresult);
            }

            static_cast<const ProxyStub::UnknownProxy&>(*this).Channel()->CustomData(nullptr);

            return (hresult);
        }

        Core::hresult Activate(const string& _callsign) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(2));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_callsign);

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
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::Controller::ILifeTime::ID, 2, hresult);
            }

            return (hresult);
        }

        Core::hresult Deactivate(const string& _callsign) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(3));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_callsign);

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
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::Controller::ILifeTime::ID, 3, hresult);
            }

            return (hresult);
        }

        Core::hresult Unavailable(const string& _callsign) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(4));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_callsign);

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
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::Controller::ILifeTime::ID, 4, hresult);
            }

            return (hresult);
        }

        Core::hresult Hibernate(const string& _callsign, const uint32_t _timeout) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(5));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_callsign);
            writer.Number<uint32_t>(_timeout);

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
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::Controller::ILifeTime::ID, 5, hresult);
            }

            return (hresult);
        }

        Core::hresult Suspend(const string& _callsign) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(6));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_callsign);

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
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::Controller::ILifeTime::ID, 6, hresult);
            }

            return (hresult);
        }

        Core::hresult Resume(const string& _callsign) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(7));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_callsign);

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
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::Controller::ILifeTime::ID, 7, hresult);
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

    }; // class ExchangeControllerLifeTimeProxy

    //
    // Exchange::Controller::ILifeTime::INotification interface proxy definitions
    //
    // Methods:
    //  (0) virtual void StateChange(const string&, const PluginHost::IShell::state&, const PluginHost::IShell::reason&) = 0
    //  (1) virtual void StateControlStateChange(const string&, const Exchange::Controller::ILifeTime::state&) = 0
    //

    class ExchangeControllerLifeTimeNotificationProxy final : public ProxyStub::UnknownProxyType<Exchange::Controller::ILifeTime::INotification> {
    public:
        ExchangeControllerLifeTimeNotificationProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        void StateChange(const string& _callsign, const PluginHost::IShell::state& _state, const PluginHost::IShell::reason& _reason) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_callsign);
            writer.Number<PluginHost::IShell::state>(_state);
            writer.Number<PluginHost::IShell::reason>(_reason);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::Controller::ILifeTime::INotification::ID, 0, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        }

        void StateControlStateChange(const string& _callsign, const Exchange::Controller::ILifeTime::state& _state) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_callsign);
            writer.Number<Exchange::Controller::ILifeTime::state>(_state);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::Controller::ILifeTime::INotification::ID, 1, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        }

    }; // class ExchangeControllerLifeTimeNotificationProxy

    //
    // Exchange::Controller::IShells interface proxy definitions
    //
    // Methods:
    //  (0) virtual Core::hresult Register(Exchange::Controller::IShells::INotification*) = 0
    //  (1) virtual Core::hresult Unregister(Exchange::Controller::IShells::INotification*) = 0
    //

    class ExchangeControllerShellsProxy final : public ProxyStub::UnknownProxyType<Exchange::Controller::IShells> {
    public:
        ExchangeControllerShellsProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        Core::hresult Register(Exchange::Controller::IShells::INotification* _sink) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_sink));

            const RPC::InstanceRecord passedInstances[] = { { RPC::instance_cast(_sink), Exchange::Controller::IShells::INotification::ID }, { 0, 0 } };
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
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::Controller::IShells::ID, 0, hresult);
            }

            static_cast<const ProxyStub::UnknownProxy&>(*this).Channel()->CustomData(nullptr);

            return (hresult);
        }

        Core::hresult Unregister(Exchange::Controller::IShells::INotification* _sink) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_sink));

            const RPC::InstanceRecord passedInstances[] = { { RPC::instance_cast(_sink), Exchange::Controller::IShells::INotification::ID }, { 0, 0 } };
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
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::Controller::IShells::ID, 1, hresult);
            }

            static_cast<const ProxyStub::UnknownProxy&>(*this).Channel()->CustomData(nullptr);

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

    }; // class ExchangeControllerShellsProxy

    //
    // Exchange::Controller::IShells::INotification interface proxy definitions
    //
    // Methods:
    //  (0) virtual void Created(const string&, PluginHost::IShell*) = 0
    //  (1) virtual void Destroy(const string&, PluginHost::IShell*) = 0
    //

    class ExchangeControllerShellsNotificationProxy final : public ProxyStub::UnknownProxyType<Exchange::Controller::IShells::INotification> {
    public:
        ExchangeControllerShellsNotificationProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        void Created(const string& _callsign, PluginHost::IShell* _plugin) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_callsign);
            writer.Number<Core::instance_id>(RPC::instance_cast(_plugin));

            const RPC::InstanceRecord passedInstances[] = { { RPC::instance_cast(_plugin), PluginHost::IShell::ID }, { 0, 0 } };
            static_cast<const ProxyStub::UnknownProxy&>(*this).Channel()->CustomData(passedInstances);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());

                    const uint32_t completeResult__ = _Complete(reader);
                    if (completeResult__ != Core::ERROR_NONE) { return (completeResult__); }

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::Controller::IShells::INotification::ID, 0, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }

            static_cast<const ProxyStub::UnknownProxy&>(*this).Channel()->CustomData(nullptr);
        }

        void Destroy(const string& _callsign, PluginHost::IShell* _plugin) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_callsign);
            writer.Number<Core::instance_id>(RPC::instance_cast(_plugin));

            const RPC::InstanceRecord passedInstances[] = { { RPC::instance_cast(_plugin), PluginHost::IShell::ID }, { 0, 0 } };
            static_cast<const ProxyStub::UnknownProxy&>(*this).Channel()->CustomData(passedInstances);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());

                    const uint32_t completeResult__ = _Complete(reader);
                    if (completeResult__ != Core::ERROR_NONE) { return (completeResult__); }

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::Controller::IShells::INotification::ID, 1, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }

            static_cast<const ProxyStub::UnknownProxy&>(*this).Channel()->CustomData(nullptr);
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

    }; // class ExchangeControllerShellsNotificationProxy

    //
    // Exchange::Controller::ISubsystems interface proxy definitions
    //
    // Methods:
    //  (0) virtual Core::hresult Subsystems(Exchange::Controller::ISubsystems::ISubsystemsIterator*&) const = 0
    //

    class ExchangeControllerSubsystemsProxy final : public ProxyStub::UnknownProxyType<Exchange::Controller::ISubsystems> {
    public:
        ExchangeControllerSubsystemsProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        Core::hresult Subsystems(Exchange::Controller::ISubsystems::ISubsystemsIterator*& _subsystems) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<Core::hresult>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    hresult = reader.Number<Core::hresult>();
                    if ((hresult & COM_ERROR) == 0) {
                        _subsystems = reinterpret_cast<Exchange::Controller::ISubsystems::ISubsystemsIterator*>(static_cast<const ProxyStub::UnknownProxy&>(*this).Interface(reader.Number<Core::instance_id>(), Exchange::Controller::ISubsystems::ISubsystemsIterator::ID));
                    }

                    return (hresult);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::Controller::ISubsystems::ID, 0, hresult);
            }

            return (hresult);
        }

    }; // class ExchangeControllerSubsystemsProxy

    //
    // Exchange::Controller::ISubsystems::INotification interface proxy definitions
    //
    // Methods:
    //  (0) virtual void SubsystemChange(Exchange::Controller::ISubsystems::ISubsystemsIterator* const) = 0
    //

    class ExchangeControllerSubsystemsNotificationProxy final : public ProxyStub::UnknownProxyType<Exchange::Controller::ISubsystems::INotification> {
    public:
        ExchangeControllerSubsystemsNotificationProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        void SubsystemChange(Exchange::Controller::ISubsystems::ISubsystemsIterator* const _subsystems) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_subsystems));

            const RPC::InstanceRecord passedInstances[] = { { RPC::instance_cast(_subsystems), Exchange::Controller::ISubsystems::ISubsystemsIterator::ID }, { 0, 0 } };
            static_cast<const ProxyStub::UnknownProxy&>(*this).Channel()->CustomData(passedInstances);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());

                    const uint32_t completeResult__ = _Complete(reader);
                    if (completeResult__ != Core::ERROR_NONE) { return (completeResult__); }

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::Controller::ISubsystems::INotification::ID, 0, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }

            static_cast<const ProxyStub::UnknownProxy&>(*this).Channel()->CustomData(nullptr);
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

    }; // class ExchangeControllerSubsystemsNotificationProxy

    //
    // Exchange::Controller::IEvents::INotification interface proxy definitions
    //
    // Methods:
    //  (0) virtual void ForwardMessage(const string&, const Core::OptionalType<string>&, const Core::OptionalType<string>&) = 0
    //

    class ExchangeControllerEventsNotificationProxy final : public ProxyStub::UnknownProxyType<Exchange::Controller::IEvents::INotification> {
    public:
        ExchangeControllerEventsNotificationProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        void ForwardMessage(const string& _event, const Core::OptionalType<string>& _callsign, const Core::OptionalType<string>& _params) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_event);
            writer.Boolean(_callsign.IsSet());
            if (_callsign.IsSet() == true) {
                writer.Text(_callsign.Value());
            }
            writer.Boolean(_params.IsSet());
            if (_params.IsSet() == true) {
                writer.Text(_params.Value());
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
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::Controller::IEvents::INotification::ID, 0, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        }

    }; // class ExchangeControllerEventsNotificationProxy

    //
    // Exchange::Controller::IMetadata interface proxy definitions
    //
    // Methods:
    //  (0) virtual Core::hresult Services(const Core::OptionalType<string>&, Exchange::Controller::IMetadata::Data::IServicesIterator*&) const = 0
    //  (1) virtual Core::hresult Links(Exchange::Controller::IMetadata::Data::ILinksIterator*&) const = 0
    //  (2) virtual Core::hresult Proxies(const Core::OptionalType<string>&, Exchange::Controller::IMetadata::Data::IProxiesIterator*&) const = 0
    //  (3) virtual Core::hresult Framework(Exchange::Controller::IMetadata::Data::Version&) const = 0
    //  (4) virtual Core::hresult Threads(Exchange::Controller::IMetadata::Data::IThreadsIterator*&) const = 0
    //  (5) virtual Core::hresult PendingRequests(Exchange::Controller::IMetadata::Data::IPendingRequestsIterator*&) const = 0
    //  (6) virtual Core::hresult CallStack(const uint8_t, Exchange::Controller::IMetadata::Data::ICallStackIterator*&) const = 0
    //  (7) virtual Core::hresult BuildInfo(Exchange::Controller::IMetadata::Data::BuildInfo&) const = 0
    //

    class ExchangeControllerMetadataProxy final : public ProxyStub::UnknownProxyType<Exchange::Controller::IMetadata> {
    public:
        ExchangeControllerMetadataProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        Core::hresult Services(const Core::OptionalType<string>& _callsign, Exchange::Controller::IMetadata::Data::IServicesIterator*& _services) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Boolean(_callsign.IsSet());
            if (_callsign.IsSet() == true) {
                writer.Text(_callsign.Value());
            }

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<Core::hresult>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    hresult = reader.Number<Core::hresult>();
                    if ((hresult & COM_ERROR) == 0) {
                        _services = reinterpret_cast<Exchange::Controller::IMetadata::Data::IServicesIterator*>(static_cast<const ProxyStub::UnknownProxy&>(*this).Interface(reader.Number<Core::instance_id>(), Exchange::Controller::IMetadata::Data::IServicesIterator::ID));
                    }

                    return (hresult);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::Controller::IMetadata::ID, 0, hresult);
            }

            return (hresult);
        }

        Core::hresult Links(Exchange::Controller::IMetadata::Data::ILinksIterator*& _links) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<Core::hresult>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    hresult = reader.Number<Core::hresult>();
                    if ((hresult & COM_ERROR) == 0) {
                        _links = reinterpret_cast<Exchange::Controller::IMetadata::Data::ILinksIterator*>(static_cast<const ProxyStub::UnknownProxy&>(*this).Interface(reader.Number<Core::instance_id>(), Exchange::Controller::IMetadata::Data::ILinksIterator::ID));
                    }

                    return (hresult);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::Controller::IMetadata::ID, 1, hresult);
            }

            return (hresult);
        }

        Core::hresult Proxies(const Core::OptionalType<string>& _linkID, Exchange::Controller::IMetadata::Data::IProxiesIterator*& _proxies) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(2));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Boolean(_linkID.IsSet());
            if (_linkID.IsSet() == true) {
                writer.Text(_linkID.Value());
            }

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<Core::hresult>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    hresult = reader.Number<Core::hresult>();
                    if ((hresult & COM_ERROR) == 0) {
                        _proxies = reinterpret_cast<Exchange::Controller::IMetadata::Data::IProxiesIterator*>(static_cast<const ProxyStub::UnknownProxy&>(*this).Interface(reader.Number<Core::instance_id>(), Exchange::Controller::IMetadata::Data::IProxiesIterator::ID));
                    }

                    return (hresult);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::Controller::IMetadata::ID, 2, hresult);
            }

            return (hresult);
        }

        Core::hresult Framework(Exchange::Controller::IMetadata::Data::Version& _version) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(3));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<Core::hresult>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    hresult = reader.Number<Core::hresult>();
                    if ((hresult & COM_ERROR) == 0) {
                        if (reader.Length() < (Core::RealSize<uint8_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                        const uint8_t _version_HashPeekedLen__ = reader.PeekNumber<uint8_t>();
                        ASSERT((_version_HashPeekedLen__ >= 64) && (_version_HashPeekedLen__ <= 64));
                        if (!((_version_HashPeekedLen__ >= 64) && (_version_HashPeekedLen__ <= 64))) { return (COM_ERROR | Core::ERROR_INVALID_RANGE); }
                        if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint8_t>()) + _version_HashPeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                        _version.Hash = reader.Text<uint8_t>();
                        if (reader.Length() < (Core::RealSize<uint8_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                        _version.Major = reader.Number<uint8_t>();
                        if (reader.Length() < (Core::RealSize<uint8_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                        _version.Minor = reader.Number<uint8_t>();
                        if (reader.Length() < (Core::RealSize<uint8_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                        _version.Patch = reader.Number<uint8_t>();
                    }

                    return (hresult);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::Controller::IMetadata::ID, 3, hresult);
            }

            return (hresult);
        }

        Core::hresult Threads(Exchange::Controller::IMetadata::Data::IThreadsIterator*& _threads) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(4));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<Core::hresult>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    hresult = reader.Number<Core::hresult>();
                    if ((hresult & COM_ERROR) == 0) {
                        _threads = reinterpret_cast<Exchange::Controller::IMetadata::Data::IThreadsIterator*>(static_cast<const ProxyStub::UnknownProxy&>(*this).Interface(reader.Number<Core::instance_id>(), Exchange::Controller::IMetadata::Data::IThreadsIterator::ID));
                    }

                    return (hresult);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::Controller::IMetadata::ID, 4, hresult);
            }

            return (hresult);
        }

        Core::hresult PendingRequests(Exchange::Controller::IMetadata::Data::IPendingRequestsIterator*& _requests) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(5));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<Core::hresult>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    hresult = reader.Number<Core::hresult>();
                    if ((hresult & COM_ERROR) == 0) {
                        _requests = reinterpret_cast<Exchange::Controller::IMetadata::Data::IPendingRequestsIterator*>(static_cast<const ProxyStub::UnknownProxy&>(*this).Interface(reader.Number<Core::instance_id>(), Exchange::Controller::IMetadata::Data::IPendingRequestsIterator::ID));
                    }

                    return (hresult);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::Controller::IMetadata::ID, 5, hresult);
            }

            return (hresult);
        }

        Core::hresult CallStack(const uint8_t _thread, Exchange::Controller::IMetadata::Data::ICallStackIterator*& _callstack) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(6));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint8_t>(_thread);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<Core::hresult>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    hresult = reader.Number<Core::hresult>();
                    if ((hresult & COM_ERROR) == 0) {
                        _callstack = reinterpret_cast<Exchange::Controller::IMetadata::Data::ICallStackIterator*>(static_cast<const ProxyStub::UnknownProxy&>(*this).Interface(reader.Number<Core::instance_id>(), Exchange::Controller::IMetadata::Data::ICallStackIterator::ID));
                    }

                    return (hresult);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::Controller::IMetadata::ID, 6, hresult);
            }

            return (hresult);
        }

        Core::hresult BuildInfo(Exchange::Controller::IMetadata::Data::BuildInfo& _buildInfo) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(7));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<Core::hresult>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    hresult = reader.Number<Core::hresult>();
                    if ((hresult & COM_ERROR) == 0) {
                        if (reader.Length() < (Core::RealSize<Exchange::Controller::IMetadata::Data::BuildInfo::systemtype>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                        _buildInfo.SystemType = reader.Number<Exchange::Controller::IMetadata::Data::BuildInfo::systemtype>();
                        if (reader.Length() < (Core::RealSize<Exchange::Controller::IMetadata::Data::BuildInfo::buildtype>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                        _buildInfo.BuildType = reader.Number<Exchange::Controller::IMetadata::Data::BuildInfo::buildtype>();
                        if (reader.Length() < (1)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                        if (reader.Boolean() == true) {
                            if (reader.Length() < (Core::RealSize<Exchange::Controller::IMetadata::Data::BuildInfo::extensiontype>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                            _buildInfo.Extensions = reader.Number<Exchange::Controller::IMetadata::Data::BuildInfo::extensiontype>();
                        }
                        else {
                            _buildInfo.Extensions = Core::OptionalType<Exchange::Controller::IMetadata::Data::BuildInfo::extensiontype>();
                        }
                        if (reader.Length() < (1)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                        _buildInfo.Messaging = reader.Boolean();
                        if (reader.Length() < (1)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                        _buildInfo.ExceptionCatching = reader.Boolean();
                        if (reader.Length() < (1)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                        _buildInfo.DeadlockDetection = reader.Boolean();
                        if (reader.Length() < (1)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                        _buildInfo.WCharSupport = reader.Boolean();
                        if (reader.Length() < (Core::RealSize<uint8_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                        _buildInfo.InstanceIDBits = reader.Number<uint8_t>();
                        if (reader.Length() < (1)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                        if (reader.Boolean() == true) {
                            if (reader.Length() < (Core::RealSize<uint8_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                            _buildInfo.TraceLevel = reader.Number<uint8_t>();
                        }
                        else {
                            _buildInfo.TraceLevel = Core::OptionalType<uint8_t>();
                        }
                        if (reader.Length() < (Core::RealSize<uint8_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                        _buildInfo.ThreadPoolCount = reader.Number<uint8_t>();
                        if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                        _buildInfo.COMRPCTimeOut = reader.Number<uint32_t>();
                    }

                    return (hresult);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::Controller::IMetadata::ID, 7, hresult);
            }

            return (hresult);
        }

    }; // class ExchangeControllerMetadataProxy

    POP_WARNING()
    POP_WARNING()

    // -----------------------------------------------------------------
    // REGISTRATION
    // -----------------------------------------------------------------
    namespace {

        typedef ProxyStub::UnknownStubType<Exchange::Controller::ISystem, ExchangeControllerSystemStubMethods> ExchangeControllerSystemStub;
        typedef ProxyStub::UnknownStubType<Exchange::Controller::IDiscovery, ExchangeControllerDiscoveryStubMethods> ExchangeControllerDiscoveryStub;
        typedef ProxyStub::UnknownStubType<Exchange::Controller::IConfiguration, ExchangeControllerConfigurationStubMethods> ExchangeControllerConfigurationStub;
        typedef ProxyStub::UnknownStubType<Exchange::Controller::ILifeTime, ExchangeControllerLifeTimeStubMethods> ExchangeControllerLifeTimeStub;
        typedef ProxyStub::UnknownStubType<Exchange::Controller::ILifeTime::INotification, ExchangeControllerLifeTimeNotificationStubMethods> ExchangeControllerLifeTimeNotificationStub;
        typedef ProxyStub::UnknownStubType<Exchange::Controller::IShells, ExchangeControllerShellsStubMethods> ExchangeControllerShellsStub;
        typedef ProxyStub::UnknownStubType<Exchange::Controller::IShells::INotification, ExchangeControllerShellsNotificationStubMethods> ExchangeControllerShellsNotificationStub;
        typedef ProxyStub::UnknownStubType<Exchange::Controller::ISubsystems, ExchangeControllerSubsystemsStubMethods> ExchangeControllerSubsystemsStub;
        typedef ProxyStub::UnknownStubType<Exchange::Controller::ISubsystems::INotification, ExchangeControllerSubsystemsNotificationStubMethods> ExchangeControllerSubsystemsNotificationStub;
        typedef ProxyStub::UnknownStubType<Exchange::Controller::IEvents::INotification, ExchangeControllerEventsNotificationStubMethods> ExchangeControllerEventsNotificationStub;
        typedef ProxyStub::UnknownStubType<Exchange::Controller::IMetadata, ExchangeControllerMetadataStubMethods> ExchangeControllerMetadataStub;

        static class Instantiation {
        public:
            Instantiation()
            {
                const RPC::SecureProxyStubType security = static_cast<RPC::SecureProxyStubType>(static_cast<std::underlying_type<RPC::SecureProxyStubType>::type>(RPC::SecureProxyStubType::PROXYSTUBS_SECURITY_SECURE) | static_cast<std::underlying_type<RPC::SecureProxyStubType>::type>(RPC::SecureProxyStubType::PROXYSTUBS_SECURITY_COHERENT));

                RPC::Administrator::Instance().Announce<Exchange::Controller::ISystem, ExchangeControllerSystemProxy, ExchangeControllerSystemStub>(security);
                RPC::Administrator::Instance().Announce<Exchange::Controller::IDiscovery, ExchangeControllerDiscoveryProxy, ExchangeControllerDiscoveryStub>(security);
                RPC::Administrator::Instance().Announce<Exchange::Controller::IConfiguration, ExchangeControllerConfigurationProxy, ExchangeControllerConfigurationStub>(security);
                RPC::Administrator::Instance().Announce<Exchange::Controller::ILifeTime, ExchangeControllerLifeTimeProxy, ExchangeControllerLifeTimeStub>(security);
                RPC::Administrator::Instance().Announce<Exchange::Controller::ILifeTime::INotification, ExchangeControllerLifeTimeNotificationProxy, ExchangeControllerLifeTimeNotificationStub>(security);
                RPC::Administrator::Instance().Announce<Exchange::Controller::IShells, ExchangeControllerShellsProxy, ExchangeControllerShellsStub>(security);
                RPC::Administrator::Instance().Announce<Exchange::Controller::IShells::INotification, ExchangeControllerShellsNotificationProxy, ExchangeControllerShellsNotificationStub>(security);
                RPC::Administrator::Instance().Announce<Exchange::Controller::ISubsystems, ExchangeControllerSubsystemsProxy, ExchangeControllerSubsystemsStub>(security);
                RPC::Administrator::Instance().Announce<Exchange::Controller::ISubsystems::INotification, ExchangeControllerSubsystemsNotificationProxy, ExchangeControllerSubsystemsNotificationStub>(security);
                RPC::Administrator::Instance().Announce<Exchange::Controller::IEvents::INotification, ExchangeControllerEventsNotificationProxy, ExchangeControllerEventsNotificationStub>(security);
                RPC::Administrator::Instance().Announce<Exchange::Controller::IMetadata, ExchangeControllerMetadataProxy, ExchangeControllerMetadataStub>(security);
            }
            ~Instantiation()
            {
                RPC::Administrator::Instance().Recall<Exchange::Controller::ISystem>();
                RPC::Administrator::Instance().Recall<Exchange::Controller::IDiscovery>();
                RPC::Administrator::Instance().Recall<Exchange::Controller::IConfiguration>();
                RPC::Administrator::Instance().Recall<Exchange::Controller::ILifeTime>();
                RPC::Administrator::Instance().Recall<Exchange::Controller::ILifeTime::INotification>();
                RPC::Administrator::Instance().Recall<Exchange::Controller::IShells>();
                RPC::Administrator::Instance().Recall<Exchange::Controller::IShells::INotification>();
                RPC::Administrator::Instance().Recall<Exchange::Controller::ISubsystems>();
                RPC::Administrator::Instance().Recall<Exchange::Controller::ISubsystems::INotification>();
                RPC::Administrator::Instance().Recall<Exchange::Controller::IEvents::INotification>();
                RPC::Administrator::Instance().Recall<Exchange::Controller::IMetadata>();
            }
        } ProxyStubRegistration;

    } // namespace

} // namespace ProxyStubs

}
