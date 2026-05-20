//
// generated automatically from "ICryptography.h"
//
// implements COM-RPC proxy stubs for:
//   - class Exchange::IHash
//   - class Exchange::ICipher
//   - class Exchange::IDiffieHellman
//   - class Exchange::IPersistent
//   - class Exchange::IVault
//   - class Exchange::ICryptography
//

#include "Module.h"
#include "ICryptography.h"

#include <com/com.h>

namespace WPEFramework {

namespace ProxyStubs {

    PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    // -----------------------------------------------------------------
    // STUBS
    // -----------------------------------------------------------------

    //
    // Exchange::IHash interface stub definitions
    //
    // Methods:
    //  (0) virtual uint32_t Ingest(const uint32_t, const uint8_t*) = 0
    //  (1) virtual uint8_t Calculate(const uint8_t, uint8_t*) = 0
    //

    ProxyStub::MethodHandler ExchangeHashStubMethods[] = {
        // (0) virtual uint32_t Ingest(const uint32_t, const uint8_t*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IHash* implementation = reinterpret_cast<Exchange::IHash*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint8_t* _data{};
            const uint32_t dataLen = reader.LockBuffer<uint32_t>(_data);
            reader.UnlockBuffer(dataLen);

            uint32_t result = implementation->Ingest(dataLen, _data);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (1) virtual uint8_t Calculate(const uint8_t, uint8_t*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IHash* implementation = reinterpret_cast<Exchange::IHash*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint8_t _maxLength = reader.Number<uint8_t>();

            uint8_t* _data{};

            if (_maxLength != 0) {
                _data = static_cast<uint8_t*>(ALLOCA(_maxLength));
            }

            uint8_t result = implementation->Calculate(_maxLength, _data);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint8_t>(result);
            writer.Buffer<uint8_t>(_maxLength, _data);
        }
        , nullptr
    }; // ExchangeHashStubMethods

    //
    // Exchange::ICipher interface stub definitions
    //
    // Methods:
    //  (0) virtual int32_t Encrypt(const uint8_t, const uint8_t*, const uint32_t, const uint8_t*, const uint32_t, uint8_t*) const = 0
    //  (1) virtual int32_t Decrypt(const uint8_t, const uint8_t*, const uint32_t, const uint8_t*, const uint32_t, uint8_t*) const = 0
    //

    ProxyStub::MethodHandler ExchangeCipherStubMethods[] = {
        // (0) virtual int32_t Encrypt(const uint8_t, const uint8_t*, const uint32_t, const uint8_t*, const uint32_t, uint8_t*) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::ICipher* implementation = reinterpret_cast<const Exchange::ICipher*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint8_t* _iv{};
            const uint8_t ivLen = reader.LockBuffer<uint8_t>(_iv);
            reader.UnlockBuffer(ivLen);
            const uint8_t* _input{};
            const uint32_t inputLen = reader.LockBuffer<uint32_t>(_input);
            reader.UnlockBuffer(inputLen);
            const uint32_t _maxOutputLength = reader.Number<uint32_t>();

            uint8_t* _output{};

            if (_maxOutputLength != 0) {
                ASSERT(_maxOutputLength <= 0x1000000);
                _output = static_cast<uint8_t*>(ALLOCA(_maxOutputLength));
            }

            int32_t result = implementation->Encrypt(ivLen, _iv, inputLen, _input, _maxOutputLength, _output);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<int32_t>(result);
            writer.Buffer<uint32_t>(_maxOutputLength, _output);
        },

        // (1) virtual int32_t Decrypt(const uint8_t, const uint8_t*, const uint32_t, const uint8_t*, const uint32_t, uint8_t*) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::ICipher* implementation = reinterpret_cast<const Exchange::ICipher*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint8_t* _iv{};
            const uint8_t ivLen = reader.LockBuffer<uint8_t>(_iv);
            reader.UnlockBuffer(ivLen);
            const uint8_t* _input{};
            const uint32_t inputLen = reader.LockBuffer<uint32_t>(_input);
            reader.UnlockBuffer(inputLen);
            const uint32_t _maxOutputLength = reader.Number<uint32_t>();

            uint8_t* _output{};

            if (_maxOutputLength != 0) {
                ASSERT(_maxOutputLength <= 0x1000000);
                _output = static_cast<uint8_t*>(ALLOCA(_maxOutputLength));
            }

            int32_t result = implementation->Decrypt(ivLen, _iv, inputLen, _input, _maxOutputLength, _output);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<int32_t>(result);
            writer.Buffer<uint32_t>(_maxOutputLength, _output);
        }
        , nullptr
    }; // ExchangeCipherStubMethods

    //
    // Exchange::IDiffieHellman interface stub definitions
    //
    // Methods:
    //  (0) virtual uint32_t Generate(const uint8_t, const uint16_t, const uint8_t*, uint32_t&, uint32_t&) = 0
    //  (1) virtual uint32_t Derive(const uint32_t, const uint32_t, uint32_t&) = 0
    //

    ProxyStub::MethodHandler ExchangeDiffieHellmanStubMethods[] = {
        // (0) virtual uint32_t Generate(const uint8_t, const uint16_t, const uint8_t*, uint32_t&, uint32_t&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IDiffieHellman* implementation = reinterpret_cast<Exchange::IDiffieHellman*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint8_t _generator = reader.Number<uint8_t>();
            const uint8_t* _modulus{};
            const uint16_t modulusLen = reader.LockBuffer<uint16_t>(_modulus);
            reader.UnlockBuffer(modulusLen);

            uint32_t _privKeyId{};
            uint32_t _pubKeyId{};

            uint32_t result = implementation->Generate(_generator, modulusLen, _modulus, _privKeyId, _pubKeyId);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Number<uint32_t>(_privKeyId);
            writer.Number<uint32_t>(_pubKeyId);
        },

        // (1) virtual uint32_t Derive(const uint32_t, const uint32_t, uint32_t&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IDiffieHellman* implementation = reinterpret_cast<Exchange::IDiffieHellman*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint32_t _privateKey = reader.Number<uint32_t>();
            const uint32_t _peerPublicKeyId = reader.Number<uint32_t>();

            uint32_t _secretId{};

            uint32_t result = implementation->Derive(_privateKey, _peerPublicKeyId, _secretId);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Number<uint32_t>(_secretId);
        }
        , nullptr
    }; // ExchangeDiffieHellmanStubMethods

    //
    // Exchange::IPersistent interface stub definitions
    //
    // Methods:
    //  (0) virtual uint32_t Exists(const string&, bool&) const = 0
    //  (1) virtual uint32_t Load(const string&, uint32_t&) = 0
    //  (2) virtual uint32_t Create(const string&, const Exchange::IPersistent::keytype, uint32_t&) = 0
    //  (3) virtual uint32_t Flush() = 0
    //

    ProxyStub::MethodHandler ExchangePersistentStubMethods[] = {
        // (0) virtual uint32_t Exists(const string&, bool&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IPersistent* implementation = reinterpret_cast<const Exchange::IPersistent*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _locator = reader.Text();

            bool _result{};

            uint32_t result = implementation->Exists(static_cast<const string&>(_locator), _result);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Boolean(_result);
        },

        // (1) virtual uint32_t Load(const string&, uint32_t&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IPersistent* implementation = reinterpret_cast<Exchange::IPersistent*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _locator = reader.Text();

            uint32_t _id{};

            uint32_t result = implementation->Load(static_cast<const string&>(_locator), _id);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Number<uint32_t>(_id);
        },

        // (2) virtual uint32_t Create(const string&, const Exchange::IPersistent::keytype, uint32_t&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IPersistent* implementation = reinterpret_cast<Exchange::IPersistent*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _locator = reader.Text();
            const Exchange::IPersistent::keytype _keyType = reader.Number<Exchange::IPersistent::keytype>();

            uint32_t _id{};

            uint32_t result = implementation->Create(static_cast<const string&>(_locator), _keyType, _id);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Number<uint32_t>(_id);
        },

        // (3) virtual uint32_t Flush() = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IPersistent* implementation = reinterpret_cast<Exchange::IPersistent*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            uint32_t result = implementation->Flush();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        }
        , nullptr
    }; // ExchangePersistentStubMethods

    //
    // Exchange::IVault interface stub definitions
    //
    // Methods:
    //  (0) virtual uint16_t Size(const uint32_t) const = 0
    //  (1) virtual uint32_t Import(const uint16_t, const uint8_t*) = 0
    //  (2) virtual uint16_t Export(const uint32_t, const uint16_t, uint8_t*) const = 0
    //  (3) virtual uint32_t Set(const uint16_t, const uint8_t*) = 0
    //  (4) virtual uint16_t Get(const uint32_t, const uint16_t, uint8_t*) const = 0
    //  (5) virtual bool Delete(const uint32_t) = 0
    //  (6) virtual Exchange::IHash* HMAC(const Exchange::hashtype, const uint32_t) = 0
    //  (7) virtual Exchange::ICipher* AES(const Exchange::aesmode, const uint32_t) = 0
    //  (8) virtual Exchange::IDiffieHellman* DiffieHellman() = 0
    //

    ProxyStub::MethodHandler ExchangeVaultStubMethods[] = {
        // (0) virtual uint16_t Size(const uint32_t) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IVault* implementation = reinterpret_cast<const Exchange::IVault*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint32_t _id = reader.Number<uint32_t>();

            uint16_t result = implementation->Size(_id);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint16_t>(result);
        },

        // (1) virtual uint32_t Import(const uint16_t, const uint8_t*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IVault* implementation = reinterpret_cast<Exchange::IVault*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint8_t* _blob{};
            const uint16_t blobLen = reader.LockBuffer<uint16_t>(_blob);
            reader.UnlockBuffer(blobLen);

            uint32_t result = implementation->Import(blobLen, _blob);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (2) virtual uint16_t Export(const uint32_t, const uint16_t, uint8_t*) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IVault* implementation = reinterpret_cast<const Exchange::IVault*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint32_t _id = reader.Number<uint32_t>();
            const uint16_t _maxLength = reader.Number<uint16_t>();

            uint8_t* _blob{};

            if (_maxLength != 0) {
                _blob = static_cast<uint8_t*>(ALLOCA(_maxLength));
            }

            uint16_t result = implementation->Export(_id, _maxLength, _blob);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint16_t>(result);
            writer.Buffer<uint16_t>(_maxLength, _blob);
        },

        // (3) virtual uint32_t Set(const uint16_t, const uint8_t*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IVault* implementation = reinterpret_cast<Exchange::IVault*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint8_t* _blob{};
            const uint16_t blobLen = reader.LockBuffer<uint16_t>(_blob);
            reader.UnlockBuffer(blobLen);

            uint32_t result = implementation->Set(blobLen, _blob);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (4) virtual uint16_t Get(const uint32_t, const uint16_t, uint8_t*) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IVault* implementation = reinterpret_cast<const Exchange::IVault*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint32_t _id = reader.Number<uint32_t>();
            const uint16_t _maxLength = reader.Number<uint16_t>();

            uint8_t* _blob{};

            if (_maxLength != 0) {
                _blob = static_cast<uint8_t*>(ALLOCA(_maxLength));
            }

            uint16_t result = implementation->Get(_id, _maxLength, _blob);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint16_t>(result);
            writer.Buffer<uint16_t>(_maxLength, _blob);
        },

        // (5) virtual bool Delete(const uint32_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IVault* implementation = reinterpret_cast<Exchange::IVault*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint32_t _id = reader.Number<uint32_t>();

            bool result = implementation->Delete(_id);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Boolean(result);
        },

        // (6) virtual Exchange::IHash* HMAC(const Exchange::hashtype, const uint32_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IVault* implementation = reinterpret_cast<Exchange::IVault*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const Exchange::hashtype _hashType = reader.Number<Exchange::hashtype>();
            const uint32_t _keyId = reader.Number<uint32_t>();

            Exchange::IHash* result = implementation->HMAC(_hashType, _keyId);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(result));

            RPC::Administrator::Instance().RegisterInterface(channel, result);
        },

        // (7) virtual Exchange::ICipher* AES(const Exchange::aesmode, const uint32_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IVault* implementation = reinterpret_cast<Exchange::IVault*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const Exchange::aesmode _aesMode = reader.Number<Exchange::aesmode>();
            const uint32_t _keyId = reader.Number<uint32_t>();

            Exchange::ICipher* result = implementation->AES(_aesMode, _keyId);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(result));

            RPC::Administrator::Instance().RegisterInterface(channel, result);
        },

        // (8) virtual Exchange::IDiffieHellman* DiffieHellman() = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IVault* implementation = reinterpret_cast<Exchange::IVault*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::IDiffieHellman* result = implementation->DiffieHellman();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(result));

            RPC::Administrator::Instance().RegisterInterface(channel, result);
        }
        , nullptr
    }; // ExchangeVaultStubMethods

    //
    // Exchange::ICryptography interface stub definitions
    //
    // Methods:
    //  (0) virtual Exchange::IHash* Hash(const Exchange::hashtype) = 0
    //  (1) virtual Exchange::IVault* Vault(const Exchange::CryptographyVault) = 0
    //

    ProxyStub::MethodHandler ExchangeCryptographyStubMethods[] = {
        // (0) virtual Exchange::IHash* Hash(const Exchange::hashtype) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::ICryptography* implementation = reinterpret_cast<Exchange::ICryptography*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const Exchange::hashtype _hashType = reader.Number<Exchange::hashtype>();

            Exchange::IHash* result = implementation->Hash(_hashType);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(result));

            RPC::Administrator::Instance().RegisterInterface(channel, result);
        },

        // (1) virtual Exchange::IVault* Vault(const Exchange::CryptographyVault) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::ICryptography* implementation = reinterpret_cast<Exchange::ICryptography*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const Exchange::CryptographyVault _id = reader.Number<Exchange::CryptographyVault>();

            Exchange::IVault* result = implementation->Vault(_id);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(result));

            RPC::Administrator::Instance().RegisterInterface(channel, result);
        }
        , nullptr
    }; // ExchangeCryptographyStubMethods

    // -----------------------------------------------------------------
    // PROXIES
    // -----------------------------------------------------------------

    //
    // Exchange::IHash interface proxy definitions
    //
    // Methods:
    //  (0) virtual uint32_t Ingest(const uint32_t, const uint8_t*) = 0
    //  (1) virtual uint8_t Calculate(const uint8_t, uint8_t*) = 0
    //

    class ExchangeHashProxy final : public ProxyStub::UnknownProxyType<Exchange::IHash> {
    public:
        ExchangeHashProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
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

        uint32_t Ingest(const uint32_t dataLen, const uint8_t* _data) override
        {
            IPCMessage message(BaseClass::Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Buffer<uint32_t>(dataLen, _data);

            uint32_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint32_t>();

            return (result);
        }

        uint8_t Calculate(const uint8_t _maxLength, uint8_t* _data) override
        {
            IPCMessage message(BaseClass::Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint8_t>(_maxLength);

            uint8_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint8_t>();
            reader.Buffer<uint8_t>(_maxLength, _data);

            return (result);
        }

    }; // class ExchangeHashProxy

    //
    // Exchange::ICipher interface proxy definitions
    //
    // Methods:
    //  (0) virtual int32_t Encrypt(const uint8_t, const uint8_t*, const uint32_t, const uint8_t*, const uint32_t, uint8_t*) const = 0
    //  (1) virtual int32_t Decrypt(const uint8_t, const uint8_t*, const uint32_t, const uint8_t*, const uint32_t, uint8_t*) const = 0
    //

    class ExchangeCipherProxy final : public ProxyStub::UnknownProxyType<Exchange::ICipher> {
    public:
        ExchangeCipherProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
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

        int32_t Encrypt(const uint8_t ivLen, const uint8_t* _iv, const uint32_t inputLen, const uint8_t* _input, const uint32_t _maxOutputLength, uint8_t* _output) const override
        {
            IPCMessage message(BaseClass::Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Buffer<uint8_t>(ivLen, _iv);
            writer.Buffer<uint32_t>(inputLen, _input);
            writer.Number<uint32_t>(_maxOutputLength);

            int32_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<int32_t>();
            reader.Buffer<uint32_t>(_maxOutputLength, _output);

            return (result);
        }

        int32_t Decrypt(const uint8_t ivLen, const uint8_t* _iv, const uint32_t inputLen, const uint8_t* _input, const uint32_t _maxOutputLength, uint8_t* _output) const override
        {
            IPCMessage message(BaseClass::Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Buffer<uint8_t>(ivLen, _iv);
            writer.Buffer<uint32_t>(inputLen, _input);
            writer.Number<uint32_t>(_maxOutputLength);

            int32_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<int32_t>();
            reader.Buffer<uint32_t>(_maxOutputLength, _output);

            return (result);
        }

    }; // class ExchangeCipherProxy

    //
    // Exchange::IDiffieHellman interface proxy definitions
    //
    // Methods:
    //  (0) virtual uint32_t Generate(const uint8_t, const uint16_t, const uint8_t*, uint32_t&, uint32_t&) = 0
    //  (1) virtual uint32_t Derive(const uint32_t, const uint32_t, uint32_t&) = 0
    //

    class ExchangeDiffieHellmanProxy final : public ProxyStub::UnknownProxyType<Exchange::IDiffieHellman> {
    public:
        ExchangeDiffieHellmanProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
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

        uint32_t Generate(const uint8_t _generator, const uint16_t modulusLen, const uint8_t* _modulus, uint32_t& _privKeyId, uint32_t& _pubKeyId) override
        {
            IPCMessage message(BaseClass::Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint8_t>(_generator);
            writer.Buffer<uint16_t>(modulusLen, _modulus);

            uint32_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint32_t>();
            _privKeyId = reader.Number<uint32_t>();
            _pubKeyId = reader.Number<uint32_t>();

            return (result);
        }

        uint32_t Derive(const uint32_t _privateKey, const uint32_t _peerPublicKeyId, uint32_t& _secretId) override
        {
            IPCMessage message(BaseClass::Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_privateKey);
            writer.Number<uint32_t>(_peerPublicKeyId);

            uint32_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint32_t>();
            _secretId = reader.Number<uint32_t>();

            return (result);
        }

    }; // class ExchangeDiffieHellmanProxy

    //
    // Exchange::IPersistent interface proxy definitions
    //
    // Methods:
    //  (0) virtual uint32_t Exists(const string&, bool&) const = 0
    //  (1) virtual uint32_t Load(const string&, uint32_t&) = 0
    //  (2) virtual uint32_t Create(const string&, const Exchange::IPersistent::keytype, uint32_t&) = 0
    //  (3) virtual uint32_t Flush() = 0
    //

    class ExchangePersistentProxy final : public ProxyStub::UnknownProxyType<Exchange::IPersistent> {
    public:
        ExchangePersistentProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
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

        uint32_t Exists(const string& _locator, bool& _result) const override
        {
            IPCMessage message(BaseClass::Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const string&>(_locator));

            uint32_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint32_t>();
            _result = reader.Boolean();

            return (result);
        }

        uint32_t Load(const string& _locator, uint32_t& _id) override
        {
            IPCMessage message(BaseClass::Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const string&>(_locator));

            uint32_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint32_t>();
            _id = reader.Number<uint32_t>();

            return (result);
        }

        uint32_t Create(const string& _locator, const Exchange::IPersistent::keytype _keyType, uint32_t& _id) override
        {
            IPCMessage message(BaseClass::Message(2));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const string&>(_locator));
            writer.Number<Exchange::IPersistent::keytype>(_keyType);

            uint32_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint32_t>();
            _id = reader.Number<uint32_t>();

            return (result);
        }

        uint32_t Flush() override
        {
            IPCMessage message(BaseClass::Message(3));

            uint32_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint32_t>();

            return (result);
        }

    }; // class ExchangePersistentProxy

    //
    // Exchange::IVault interface proxy definitions
    //
    // Methods:
    //  (0) virtual uint16_t Size(const uint32_t) const = 0
    //  (1) virtual uint32_t Import(const uint16_t, const uint8_t*) = 0
    //  (2) virtual uint16_t Export(const uint32_t, const uint16_t, uint8_t*) const = 0
    //  (3) virtual uint32_t Set(const uint16_t, const uint8_t*) = 0
    //  (4) virtual uint16_t Get(const uint32_t, const uint16_t, uint8_t*) const = 0
    //  (5) virtual bool Delete(const uint32_t) = 0
    //  (6) virtual Exchange::IHash* HMAC(const Exchange::hashtype, const uint32_t) = 0
    //  (7) virtual Exchange::ICipher* AES(const Exchange::aesmode, const uint32_t) = 0
    //  (8) virtual Exchange::IDiffieHellman* DiffieHellman() = 0
    //

    class ExchangeVaultProxy final : public ProxyStub::UnknownProxyType<Exchange::IVault> {
    public:
        ExchangeVaultProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
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

        uint16_t Size(const uint32_t _id) const override
        {
            IPCMessage message(BaseClass::Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_id);

            uint16_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint16_t>();

            return (result);
        }

        uint32_t Import(const uint16_t blobLen, const uint8_t* _blob) override
        {
            IPCMessage message(BaseClass::Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Buffer<uint16_t>(blobLen, _blob);

            uint32_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint32_t>();

            return (result);
        }

        uint16_t Export(const uint32_t _id, const uint16_t _maxLength, uint8_t* _blob) const override
        {
            IPCMessage message(BaseClass::Message(2));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_id);
            writer.Number<uint16_t>(_maxLength);

            uint16_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint16_t>();
            reader.Buffer<uint16_t>(_maxLength, _blob);

            return (result);
        }

        uint32_t Set(const uint16_t blobLen, const uint8_t* _blob) override
        {
            IPCMessage message(BaseClass::Message(3));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Buffer<uint16_t>(blobLen, _blob);

            uint32_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint32_t>();

            return (result);
        }

        uint16_t Get(const uint32_t _id, const uint16_t _maxLength, uint8_t* _blob) const override
        {
            IPCMessage message(BaseClass::Message(4));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_id);
            writer.Number<uint16_t>(_maxLength);

            uint16_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint16_t>();
            reader.Buffer<uint16_t>(_maxLength, _blob);

            return (result);
        }

        bool Delete(const uint32_t _id) override
        {
            IPCMessage message(BaseClass::Message(5));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_id);

            bool result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Boolean();

            return (result);
        }

        Exchange::IHash* HMAC(const Exchange::hashtype _hashType, const uint32_t _keyId) override
        {
            IPCMessage message(BaseClass::Message(6));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Exchange::hashtype>(_hashType);
            writer.Number<uint32_t>(_keyId);

            Exchange::IHash* result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reinterpret_cast<Exchange::IHash*>(Interface(reader.Number<Core::instance_id>(), Exchange::IHash::ID));

            return (result);
        }

        Exchange::ICipher* AES(const Exchange::aesmode _aesMode, const uint32_t _keyId) override
        {
            IPCMessage message(BaseClass::Message(7));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Exchange::aesmode>(_aesMode);
            writer.Number<uint32_t>(_keyId);

            Exchange::ICipher* result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reinterpret_cast<Exchange::ICipher*>(Interface(reader.Number<Core::instance_id>(), Exchange::ICipher::ID));

            return (result);
        }

        Exchange::IDiffieHellman* DiffieHellman() override
        {
            IPCMessage message(BaseClass::Message(8));

            Exchange::IDiffieHellman* result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reinterpret_cast<Exchange::IDiffieHellman*>(Interface(reader.Number<Core::instance_id>(), Exchange::IDiffieHellman::ID));

            return (result);
        }

    }; // class ExchangeVaultProxy

    //
    // Exchange::ICryptography interface proxy definitions
    //
    // Methods:
    //  (0) virtual Exchange::IHash* Hash(const Exchange::hashtype) = 0
    //  (1) virtual Exchange::IVault* Vault(const Exchange::CryptographyVault) = 0
    //

    class ExchangeCryptographyProxy final : public ProxyStub::UnknownProxyType<Exchange::ICryptography> {
    public:
        ExchangeCryptographyProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
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

        Exchange::IHash* Hash(const Exchange::hashtype _hashType) override
        {
            IPCMessage message(BaseClass::Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Exchange::hashtype>(_hashType);

            Exchange::IHash* result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reinterpret_cast<Exchange::IHash*>(Interface(reader.Number<Core::instance_id>(), Exchange::IHash::ID));

            return (result);
        }

        Exchange::IVault* Vault(const Exchange::CryptographyVault _id) override
        {
            IPCMessage message(BaseClass::Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Exchange::CryptographyVault>(_id);

            Exchange::IVault* result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reinterpret_cast<Exchange::IVault*>(Interface(reader.Number<Core::instance_id>(), Exchange::IVault::ID));

            return (result);
        }

    }; // class ExchangeCryptographyProxy

    POP_WARNING()
    POP_WARNING()

    // -----------------------------------------------------------------
    // REGISTRATION
    // -----------------------------------------------------------------

    namespace {

        typedef ProxyStub::UnknownStubType<Exchange::IHash, ExchangeHashStubMethods> ExchangeHashStub;
        typedef ProxyStub::UnknownStubType<Exchange::ICipher, ExchangeCipherStubMethods> ExchangeCipherStub;
        typedef ProxyStub::UnknownStubType<Exchange::IDiffieHellman, ExchangeDiffieHellmanStubMethods> ExchangeDiffieHellmanStub;
        typedef ProxyStub::UnknownStubType<Exchange::IPersistent, ExchangePersistentStubMethods> ExchangePersistentStub;
        typedef ProxyStub::UnknownStubType<Exchange::IVault, ExchangeVaultStubMethods> ExchangeVaultStub;
        typedef ProxyStub::UnknownStubType<Exchange::ICryptography, ExchangeCryptographyStubMethods> ExchangeCryptographyStub;

        static class Instantiation {
        public:
            Instantiation()
            {
                RPC::Administrator::Instance().Announce<Exchange::IHash, ExchangeHashProxy, ExchangeHashStub>();
                RPC::Administrator::Instance().Announce<Exchange::ICipher, ExchangeCipherProxy, ExchangeCipherStub>();
                RPC::Administrator::Instance().Announce<Exchange::IDiffieHellman, ExchangeDiffieHellmanProxy, ExchangeDiffieHellmanStub>();
                RPC::Administrator::Instance().Announce<Exchange::IPersistent, ExchangePersistentProxy, ExchangePersistentStub>();
                RPC::Administrator::Instance().Announce<Exchange::IVault, ExchangeVaultProxy, ExchangeVaultStub>();
                RPC::Administrator::Instance().Announce<Exchange::ICryptography, ExchangeCryptographyProxy, ExchangeCryptographyStub>();
            }
            ~Instantiation()
            {
                RPC::Administrator::Instance().Recall<Exchange::IHash>();
                RPC::Administrator::Instance().Recall<Exchange::ICipher>();
                RPC::Administrator::Instance().Recall<Exchange::IDiffieHellman>();
                RPC::Administrator::Instance().Recall<Exchange::IPersistent>();
                RPC::Administrator::Instance().Recall<Exchange::IVault>();
                RPC::Administrator::Instance().Recall<Exchange::ICryptography>();
            }
        } ProxyStubRegistration;

    } // namespace

} // namespace ProxyStubs

}
