//
// generated automatically from "ICryptography.h"
//
// implements COM-RPC proxy stubs for:
//   - class Exchange::IRandom
//   - class Exchange::IHash
//   - class Exchange::ICipher
//   - class Exchange::IDiffieHellman
//   - class Exchange::IPersistent
//   - class Exchange::IVault
//   - class Exchange::IDeviceObjects
//   - class Exchange::ICryptography
//

#include "Module.h"
#include "ICryptography.h"

#include <com/com.h>

namespace Thunder {

namespace ProxyStubs {

    PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    // -----------------------------------------------------------------
    // STUBS
    // -----------------------------------------------------------------

    //
    // Exchange::IRandom interface stub definitions
    //
    // Methods:
    //  (0) virtual uint16_t Generate(const uint16_t, uint8_t*) const = 0
    //

    static ProxyStub::MethodHandler ExchangeRandomStubMethods[] = {
        // (0) virtual uint16_t Generate(const uint16_t, uint8_t*) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IRandom* implementation = reinterpret_cast<const Exchange::IRandom*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint16_t _length = reader.Number<uint16_t>();

            uint8_t* _data{};

            if (_length != 0) {
                _data = static_cast<uint8_t*>(ALLOCA(_length * sizeof(uint8_t)));
                ASSERT(_data != nullptr);
            }

            uint16_t result = implementation->Generate(_length, _data);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Buffer<uint16_t>(result, _data);
        }
        , nullptr
    }; // ExchangeRandomStubMethods

    //
    // Exchange::IHash interface stub definitions
    //
    // Methods:
    //  (0) virtual uint32_t Ingest(const uint32_t, const uint8_t*) = 0
    //  (1) virtual uint8_t Calculate(const uint8_t, uint8_t*) = 0
    //

    static ProxyStub::MethodHandler ExchangeHashStubMethods[] = {
        // (0) virtual uint32_t Ingest(const uint32_t, const uint8_t*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IHash* implementation = reinterpret_cast<Exchange::IHash*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            ASSERT((reader.PeekNumber<Core::UInt24>() >= 0) && (reader.PeekNumber<Core::UInt24>() <= 4194303));
            const uint8_t* _data{};
            const uint32_t _length = reader.LockBuffer<Core::UInt24>(_data);
            reader.UnlockBuffer(_length);

            uint32_t result = implementation->Ingest(_length, _data);

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
                _data = static_cast<uint8_t*>(ALLOCA(_maxLength * sizeof(uint8_t)));
                ASSERT(_data != nullptr);
            }

            uint8_t result = implementation->Calculate(_maxLength, _data);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Buffer<uint8_t>(result, _data);
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

    static ProxyStub::MethodHandler ExchangeCipherStubMethods[] = {
        // (0) virtual int32_t Encrypt(const uint8_t, const uint8_t*, const uint32_t, const uint8_t*, const uint32_t, uint8_t*) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::ICipher* implementation = reinterpret_cast<const Exchange::ICipher*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint8_t* _iv{};
            const uint8_t _ivLength = reader.LockBuffer<uint8_t>(_iv);
            reader.UnlockBuffer(_ivLength);
            ASSERT((reader.PeekNumber<Core::UInt24>() >= 0) && (reader.PeekNumber<Core::UInt24>() <= 4194303));
            const uint8_t* _input{};
            const uint32_t _inputLength = reader.LockBuffer<Core::UInt24>(_input);
            reader.UnlockBuffer(_inputLength);
            const uint32_t _maxOutputLength = reader.Number<uint32_t>();

            uint8_t* _output{};

            if (_maxOutputLength != 0) {
                ASSERT(_maxOutputLength <= 0x1000000);
                _output = static_cast<uint8_t*>(ALLOCA(_maxOutputLength * sizeof(uint8_t)));
                ASSERT(_output != nullptr);
            }

            int32_t result = implementation->Encrypt(_ivLength, _iv, _inputLength, _input, _maxOutputLength, _output);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Buffer<int32_t>((result > 0? result : 0), _output);
        },

        // (1) virtual int32_t Decrypt(const uint8_t, const uint8_t*, const uint32_t, const uint8_t*, const uint32_t, uint8_t*) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::ICipher* implementation = reinterpret_cast<const Exchange::ICipher*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint8_t* _iv{};
            const uint8_t _ivLength = reader.LockBuffer<uint8_t>(_iv);
            reader.UnlockBuffer(_ivLength);
            ASSERT((reader.PeekNumber<Core::UInt24>() >= 0) && (reader.PeekNumber<Core::UInt24>() <= 4194303));
            const uint8_t* _input{};
            const uint32_t _inputLength = reader.LockBuffer<Core::UInt24>(_input);
            reader.UnlockBuffer(_inputLength);
            const uint32_t _maxOutputLength = reader.Number<uint32_t>();

            uint8_t* _output{};

            if (_maxOutputLength != 0) {
                ASSERT(_maxOutputLength <= 0x1000000);
                _output = static_cast<uint8_t*>(ALLOCA(_maxOutputLength * sizeof(uint8_t)));
                ASSERT(_output != nullptr);
            }

            int32_t result = implementation->Decrypt(_ivLength, _iv, _inputLength, _input, _maxOutputLength, _output);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Buffer<int32_t>((result > 0? result : 0), _output);
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

    static ProxyStub::MethodHandler ExchangeDiffieHellmanStubMethods[] = {
        // (0) virtual uint32_t Generate(const uint8_t, const uint16_t, const uint8_t*, uint32_t&, uint32_t&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IDiffieHellman* implementation = reinterpret_cast<Exchange::IDiffieHellman*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint8_t _generator = reader.Number<uint8_t>();
            const uint8_t* _modulus{};
            const uint16_t _modulusSize = reader.LockBuffer<uint16_t>(_modulus);
            reader.UnlockBuffer(_modulusSize);

            uint32_t _privKeyId{};
            uint32_t _pubKeyId{};

            uint32_t result = implementation->Generate(_generator, _modulusSize, _modulus, _privKeyId, _pubKeyId);

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

    static ProxyStub::MethodHandler ExchangePersistentStubMethods[] = {
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
    //  (5) virtual uint32_t Generate(const uint16_t) = 0
    //  (6) virtual bool Delete(const uint32_t) = 0
    //  (7) virtual Exchange::IHash* HMAC(const Exchange::hashtype, const uint32_t) = 0
    //  (8) virtual Exchange::ICipher* AES(const Exchange::aesmode, const uint32_t) = 0
    //  (9) virtual Exchange::IDiffieHellman* DiffieHellman() = 0
    //

    static ProxyStub::MethodHandler ExchangeVaultStubMethods[] = {
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
            const uint16_t _length = reader.LockBuffer<uint16_t>(_blob);
            reader.UnlockBuffer(_length);

            uint32_t result = implementation->Import(_length, _blob);

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
                _blob = static_cast<uint8_t*>(ALLOCA(_maxLength * sizeof(uint8_t)));
                ASSERT(_blob != nullptr);
            }

            uint16_t result = implementation->Export(_id, _maxLength, _blob);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Buffer<uint16_t>(result, _blob);
        },

        // (3) virtual uint32_t Set(const uint16_t, const uint8_t*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IVault* implementation = reinterpret_cast<Exchange::IVault*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint8_t* _blob{};
            const uint16_t _length = reader.LockBuffer<uint16_t>(_blob);
            reader.UnlockBuffer(_length);

            uint32_t result = implementation->Set(_length, _blob);

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
                _blob = static_cast<uint8_t*>(ALLOCA(_maxLength * sizeof(uint8_t)));
                ASSERT(_blob != nullptr);
            }

            uint16_t result = implementation->Get(_id, _maxLength, _blob);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Buffer<uint16_t>(result, _blob);
        },

        // (5) virtual uint32_t Generate(const uint16_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IVault* implementation = reinterpret_cast<Exchange::IVault*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint16_t _length = reader.Number<uint16_t>();

            uint32_t result = implementation->Generate(_length);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (6) virtual bool Delete(const uint32_t) = 0
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

        // (7) virtual Exchange::IHash* HMAC(const Exchange::hashtype, const uint32_t) = 0
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

        // (8) virtual Exchange::ICipher* AES(const Exchange::aesmode, const uint32_t) = 0
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

        // (9) virtual Exchange::IDiffieHellman* DiffieHellman() = 0
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
    // Exchange::IDeviceObjects interface stub definitions
    //
    // Methods:
    //  (0) virtual uint32_t Id(const string&, Exchange::IVault*&) = 0
    //

    static ProxyStub::MethodHandler ExchangeDeviceObjectsStubMethods[] = {
        // (0) virtual uint32_t Id(const string&, Exchange::IVault*&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IDeviceObjects* implementation = reinterpret_cast<Exchange::IDeviceObjects*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _label = reader.Text();

            Exchange::IVault* _vault{};

            uint32_t result = implementation->Id(static_cast<const string&>(_label), _vault);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Number<Core::instance_id>(RPC::instance_cast(_vault));

            RPC::Administrator::Instance().RegisterInterface(channel, _vault);
        }
        , nullptr
    }; // ExchangeDeviceObjectsStubMethods

    //
    // Exchange::ICryptography interface stub definitions
    //
    // Methods:
    //  (0) virtual Exchange::IRandom* Random() = 0
    //  (1) virtual Exchange::IHash* Hash(const Exchange::hashtype) = 0
    //  (2) virtual Exchange::IVault* Vault(const Exchange::CryptographyVault) = 0
    //

    static ProxyStub::MethodHandler ExchangeCryptographyStubMethods[] = {
        // (0) virtual Exchange::IRandom* Random() = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::ICryptography* implementation = reinterpret_cast<Exchange::ICryptography*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::IRandom* result = implementation->Random();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(result));

            RPC::Administrator::Instance().RegisterInterface(channel, result);
        },

        // (1) virtual Exchange::IHash* Hash(const Exchange::hashtype) = 0
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

        // (2) virtual Exchange::IVault* Vault(const Exchange::CryptographyVault) = 0
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
    // Exchange::IRandom interface proxy definitions
    //
    // Methods:
    //  (0) virtual uint16_t Generate(const uint16_t, uint8_t*) const = 0
    //

    class ExchangeRandomProxy final : public ProxyStub::UnknownProxyType<Exchange::IRandom> {
    public:
        ExchangeRandomProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        uint16_t Generate(const uint16_t _length, uint8_t* _data) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint16_t>(_length);

            uint16_t result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Buffer<uint16_t>(_length, _data);
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

    }; // class ExchangeRandomProxy

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

        uint32_t Ingest(const uint32_t _length, const uint8_t* _data) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Buffer<Core::UInt24>(_length, _data);

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

        uint8_t Calculate(const uint8_t _maxLength, uint8_t* _data) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint8_t>(_maxLength);

            uint8_t result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Buffer<uint8_t>(_maxLength, _data);
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

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

        int32_t Encrypt(const uint8_t _ivLength, const uint8_t* _iv, const uint32_t _inputLength, const uint8_t* _input, const uint32_t _maxOutputLength, uint8_t* _output) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Buffer<uint8_t>(_ivLength, _iv);
            writer.Buffer<Core::UInt24>(_inputLength, _input);
            writer.Number<uint32_t>(_maxOutputLength);

            int32_t result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Buffer<uint32_t>(_maxOutputLength, _output);
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        int32_t Decrypt(const uint8_t _ivLength, const uint8_t* _iv, const uint32_t _inputLength, const uint8_t* _input, const uint32_t _maxOutputLength, uint8_t* _output) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Buffer<uint8_t>(_ivLength, _iv);
            writer.Buffer<Core::UInt24>(_inputLength, _input);
            writer.Number<uint32_t>(_maxOutputLength);

            int32_t result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Buffer<uint32_t>(_maxOutputLength, _output);
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

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

        uint32_t Generate(const uint8_t _generator, const uint16_t _modulusSize, const uint8_t* _modulus, uint32_t& _privKeyId, uint32_t& _pubKeyId) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint8_t>(_generator);
            writer.Buffer<uint16_t>(_modulusSize, _modulus);

            uint32_t result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Number<uint32_t>();
                _privKeyId = reader.Number<uint32_t>();
                _pubKeyId = reader.Number<uint32_t>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        uint32_t Derive(const uint32_t _privateKey, const uint32_t _peerPublicKeyId, uint32_t& _secretId) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_privateKey);
            writer.Number<uint32_t>(_peerPublicKeyId);

            uint32_t result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Number<uint32_t>();
                _secretId = reader.Number<uint32_t>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

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

        uint32_t Exists(const string& _locator, bool& _result) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_locator);

            uint32_t result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Number<uint32_t>();
                _result = reader.Boolean();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        uint32_t Load(const string& _locator, uint32_t& _id) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_locator);

            uint32_t result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Number<uint32_t>();
                _id = reader.Number<uint32_t>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        uint32_t Create(const string& _locator, const Exchange::IPersistent::keytype _keyType, uint32_t& _id) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(2));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_locator);
            writer.Number<Exchange::IPersistent::keytype>(_keyType);

            uint32_t result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Number<uint32_t>();
                _id = reader.Number<uint32_t>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        uint32_t Flush() override
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
    //  (5) virtual uint32_t Generate(const uint16_t) = 0
    //  (6) virtual bool Delete(const uint32_t) = 0
    //  (7) virtual Exchange::IHash* HMAC(const Exchange::hashtype, const uint32_t) = 0
    //  (8) virtual Exchange::ICipher* AES(const Exchange::aesmode, const uint32_t) = 0
    //  (9) virtual Exchange::IDiffieHellman* DiffieHellman() = 0
    //

    class ExchangeVaultProxy final : public ProxyStub::UnknownProxyType<Exchange::IVault> {
    public:
        ExchangeVaultProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        uint16_t Size(const uint32_t _id) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_id);

            uint16_t result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Number<uint16_t>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        uint32_t Import(const uint16_t _length, const uint8_t* _blob) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Buffer<uint16_t>(_length, _blob);

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

        uint16_t Export(const uint32_t _id, const uint16_t _maxLength, uint8_t* _blob) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(2));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_id);
            writer.Number<uint16_t>(_maxLength);

            uint16_t result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Buffer<uint16_t>(_maxLength, _blob);
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        uint32_t Set(const uint16_t _length, const uint8_t* _blob) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(3));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Buffer<uint16_t>(_length, _blob);

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

        uint16_t Get(const uint32_t _id, const uint16_t _maxLength, uint8_t* _blob) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(4));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_id);
            writer.Number<uint16_t>(_maxLength);

            uint16_t result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Buffer<uint16_t>(_maxLength, _blob);
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        uint32_t Generate(const uint16_t _length) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(5));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint16_t>(_length);

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

        bool Delete(const uint32_t _id) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(6));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_id);

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

        Exchange::IHash* HMAC(const Exchange::hashtype _hashType, const uint32_t _keyId) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(7));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Exchange::hashtype>(_hashType);
            writer.Number<uint32_t>(_keyId);

            Exchange::IHash* result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reinterpret_cast<Exchange::IHash*>(static_cast<const ProxyStub::UnknownProxy&>(*this).Interface(reader.Number<Core::instance_id>(), Exchange::IHash::ID));
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        Exchange::ICipher* AES(const Exchange::aesmode _aesMode, const uint32_t _keyId) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(8));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Exchange::aesmode>(_aesMode);
            writer.Number<uint32_t>(_keyId);

            Exchange::ICipher* result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reinterpret_cast<Exchange::ICipher*>(static_cast<const ProxyStub::UnknownProxy&>(*this).Interface(reader.Number<Core::instance_id>(), Exchange::ICipher::ID));
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        Exchange::IDiffieHellman* DiffieHellman() override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(9));

            Exchange::IDiffieHellman* result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reinterpret_cast<Exchange::IDiffieHellman*>(static_cast<const ProxyStub::UnknownProxy&>(*this).Interface(reader.Number<Core::instance_id>(), Exchange::IDiffieHellman::ID));
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

    }; // class ExchangeVaultProxy

    //
    // Exchange::IDeviceObjects interface proxy definitions
    //
    // Methods:
    //  (0) virtual uint32_t Id(const string&, Exchange::IVault*&) = 0
    //

    class ExchangeDeviceObjectsProxy final : public ProxyStub::UnknownProxyType<Exchange::IDeviceObjects> {
    public:
        ExchangeDeviceObjectsProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        uint32_t Id(const string& _label, Exchange::IVault*& _vault) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_label);

            uint32_t result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Number<uint32_t>();
                _vault = reinterpret_cast<Exchange::IVault*>(static_cast<const ProxyStub::UnknownProxy&>(*this).Interface(reader.Number<Core::instance_id>(), Exchange::IVault::ID));
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

    }; // class ExchangeDeviceObjectsProxy

    //
    // Exchange::ICryptography interface proxy definitions
    //
    // Methods:
    //  (0) virtual Exchange::IRandom* Random() = 0
    //  (1) virtual Exchange::IHash* Hash(const Exchange::hashtype) = 0
    //  (2) virtual Exchange::IVault* Vault(const Exchange::CryptographyVault) = 0
    //

    class ExchangeCryptographyProxy final : public ProxyStub::UnknownProxyType<Exchange::ICryptography> {
    public:
        ExchangeCryptographyProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        Exchange::IRandom* Random() override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            Exchange::IRandom* result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reinterpret_cast<Exchange::IRandom*>(static_cast<const ProxyStub::UnknownProxy&>(*this).Interface(reader.Number<Core::instance_id>(), Exchange::IRandom::ID));
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        Exchange::IHash* Hash(const Exchange::hashtype _hashType) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Exchange::hashtype>(_hashType);

            Exchange::IHash* result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reinterpret_cast<Exchange::IHash*>(static_cast<const ProxyStub::UnknownProxy&>(*this).Interface(reader.Number<Core::instance_id>(), Exchange::IHash::ID));
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        Exchange::IVault* Vault(const Exchange::CryptographyVault _id) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(2));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Exchange::CryptographyVault>(_id);

            Exchange::IVault* result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reinterpret_cast<Exchange::IVault*>(static_cast<const ProxyStub::UnknownProxy&>(*this).Interface(reader.Number<Core::instance_id>(), Exchange::IVault::ID));
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

    }; // class ExchangeCryptographyProxy

    POP_WARNING()
    POP_WARNING()

    // -----------------------------------------------------------------
    // REGISTRATION
    // -----------------------------------------------------------------
    namespace {

        typedef ProxyStub::UnknownStubType<Exchange::IRandom, ExchangeRandomStubMethods> ExchangeRandomStub;
        typedef ProxyStub::UnknownStubType<Exchange::IHash, ExchangeHashStubMethods> ExchangeHashStub;
        typedef ProxyStub::UnknownStubType<Exchange::ICipher, ExchangeCipherStubMethods> ExchangeCipherStub;
        typedef ProxyStub::UnknownStubType<Exchange::IDiffieHellman, ExchangeDiffieHellmanStubMethods> ExchangeDiffieHellmanStub;
        typedef ProxyStub::UnknownStubType<Exchange::IPersistent, ExchangePersistentStubMethods> ExchangePersistentStub;
        typedef ProxyStub::UnknownStubType<Exchange::IVault, ExchangeVaultStubMethods> ExchangeVaultStub;
        typedef ProxyStub::UnknownStubType<Exchange::IDeviceObjects, ExchangeDeviceObjectsStubMethods> ExchangeDeviceObjectsStub;
        typedef ProxyStub::UnknownStubType<Exchange::ICryptography, ExchangeCryptographyStubMethods> ExchangeCryptographyStub;

        static class Instantiation {
        public:
            Instantiation()
            {
                RPC::Administrator::Instance().Announce<Exchange::IRandom, ExchangeRandomProxy, ExchangeRandomStub>();
                RPC::Administrator::Instance().Announce<Exchange::IHash, ExchangeHashProxy, ExchangeHashStub>();
                RPC::Administrator::Instance().Announce<Exchange::ICipher, ExchangeCipherProxy, ExchangeCipherStub>();
                RPC::Administrator::Instance().Announce<Exchange::IDiffieHellman, ExchangeDiffieHellmanProxy, ExchangeDiffieHellmanStub>();
                RPC::Administrator::Instance().Announce<Exchange::IPersistent, ExchangePersistentProxy, ExchangePersistentStub>();
                RPC::Administrator::Instance().Announce<Exchange::IVault, ExchangeVaultProxy, ExchangeVaultStub>();
                RPC::Administrator::Instance().Announce<Exchange::IDeviceObjects, ExchangeDeviceObjectsProxy, ExchangeDeviceObjectsStub>();
                RPC::Administrator::Instance().Announce<Exchange::ICryptography, ExchangeCryptographyProxy, ExchangeCryptographyStub>();
            }
            ~Instantiation()
            {
                RPC::Administrator::Instance().Recall<Exchange::IRandom>();
                RPC::Administrator::Instance().Recall<Exchange::IHash>();
                RPC::Administrator::Instance().Recall<Exchange::ICipher>();
                RPC::Administrator::Instance().Recall<Exchange::IDiffieHellman>();
                RPC::Administrator::Instance().Recall<Exchange::IPersistent>();
                RPC::Administrator::Instance().Recall<Exchange::IVault>();
                RPC::Administrator::Instance().Recall<Exchange::IDeviceObjects>();
                RPC::Administrator::Instance().Recall<Exchange::ICryptography>();
            }
        } ProxyStubRegistration;

    } // namespace

} // namespace ProxyStubs

}
