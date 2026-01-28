//
// generated automatically from "INetflixSecurity.h"
//
// implements COM-RPC proxy stubs for:
//   - class Exchange::INetflixSecurity
//

#include "Module.h"
#include "INetflixSecurity.h"

#include <com/com.h>

namespace Thunder {

namespace ProxyStubs {

    PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    // -----------------------------------------------------------------
    // STUBS
    // -----------------------------------------------------------------

    //
    // Exchange::INetflixSecurity interface stub definitions
    //
    // Methods:
    //  (0) virtual std::string ESN() const = 0
    //  (1) virtual uint32_t EncryptionKey() const = 0
    //  (2) virtual uint32_t HMACKey() const = 0
    //  (3) virtual uint32_t WrappingKey() const = 0
    //  (4) virtual uint32_t DeriveKeys(const uint32_t, const uint32_t, const uint32_t, uint32_t&, uint32_t&, uint32_t&) = 0
    //

    static ProxyStub::MethodHandler ExchangeNetflixSecurityStubMethods[] = {
        // (0) virtual std::string ESN() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::INetflixSecurity* implementation = reinterpret_cast<const Exchange::INetflixSecurity*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            std::string result = implementation->ESN();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Text(result);
        },

        // (1) virtual uint32_t EncryptionKey() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::INetflixSecurity* implementation = reinterpret_cast<const Exchange::INetflixSecurity*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            uint32_t result = implementation->EncryptionKey();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (2) virtual uint32_t HMACKey() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::INetflixSecurity* implementation = reinterpret_cast<const Exchange::INetflixSecurity*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            uint32_t result = implementation->HMACKey();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (3) virtual uint32_t WrappingKey() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::INetflixSecurity* implementation = reinterpret_cast<const Exchange::INetflixSecurity*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            uint32_t result = implementation->WrappingKey();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (4) virtual uint32_t DeriveKeys(const uint32_t, const uint32_t, const uint32_t, uint32_t&, uint32_t&, uint32_t&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::INetflixSecurity* implementation = reinterpret_cast<Exchange::INetflixSecurity*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint32_t _privateDhKeyId = reader.Number<uint32_t>();
            const uint32_t _peerPublicDhKeyId = reader.Number<uint32_t>();
            const uint32_t _derivationKeyId = reader.Number<uint32_t>();

            uint32_t _encryptionKeyId{};
            uint32_t _hmacKeyId{};
            uint32_t _wrappingKeyId{};

            uint32_t result = implementation->DeriveKeys(_privateDhKeyId, _peerPublicDhKeyId, _derivationKeyId, _encryptionKeyId, _hmacKeyId, _wrappingKeyId);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Number<uint32_t>(_encryptionKeyId);
            writer.Number<uint32_t>(_hmacKeyId);
            writer.Number<uint32_t>(_wrappingKeyId);
        }
        , nullptr
    }; // ExchangeNetflixSecurityStubMethods

    // -----------------------------------------------------------------
    // PROXIES
    // -----------------------------------------------------------------

    //
    // Exchange::INetflixSecurity interface proxy definitions
    //
    // Methods:
    //  (0) virtual std::string ESN() const = 0
    //  (1) virtual uint32_t EncryptionKey() const = 0
    //  (2) virtual uint32_t HMACKey() const = 0
    //  (3) virtual uint32_t WrappingKey() const = 0
    //  (4) virtual uint32_t DeriveKeys(const uint32_t, const uint32_t, const uint32_t, uint32_t&, uint32_t&, uint32_t&) = 0
    //

    class ExchangeNetflixSecurityProxy final : public ProxyStub::UnknownProxyType<Exchange::INetflixSecurity> {
    public:
        ExchangeNetflixSecurityProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        std::string ESN() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            std::string result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Text();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        uint32_t EncryptionKey() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

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

        uint32_t HMACKey() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(2));

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

        uint32_t WrappingKey() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(3));

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

        uint32_t DeriveKeys(const uint32_t _privateDhKeyId, const uint32_t _peerPublicDhKeyId, const uint32_t _derivationKeyId, uint32_t& _encryptionKeyId, uint32_t& _hmacKeyId, uint32_t& _wrappingKeyId) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(4));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_privateDhKeyId);
            writer.Number<uint32_t>(_peerPublicDhKeyId);
            writer.Number<uint32_t>(_derivationKeyId);

            uint32_t result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Number<uint32_t>();
                _encryptionKeyId = reader.Number<uint32_t>();
                _hmacKeyId = reader.Number<uint32_t>();
                _wrappingKeyId = reader.Number<uint32_t>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

    }; // class ExchangeNetflixSecurityProxy

    POP_WARNING()
    POP_WARNING()

    // -----------------------------------------------------------------
    // REGISTRATION
    // -----------------------------------------------------------------
    namespace {

        typedef ProxyStub::UnknownStubType<Exchange::INetflixSecurity, ExchangeNetflixSecurityStubMethods> ExchangeNetflixSecurityStub;

        static class Instantiation {
        public:
            Instantiation()
            {
                RPC::Administrator::Instance().Announce<Exchange::INetflixSecurity, ExchangeNetflixSecurityProxy, ExchangeNetflixSecurityStub>();
            }
            ~Instantiation()
            {
                RPC::Administrator::Instance().Recall<Exchange::INetflixSecurity>();
            }
        } ProxyStubRegistration;

    } // namespace

} // namespace ProxyStubs

}
