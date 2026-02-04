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
// secure code enabled:
//   - instance verification enabled
//   - range verification enabled
//   - frame coherency verification enabled
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
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const Exchange::IRandom* implementation = reinterpret_cast<const Exchange::IRandom*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::IRandom::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint16_t _length = reader.Number<uint16_t>();

                uint8_t* _data{};

                if (_length != 0) {
                    _data = static_cast<uint8_t*>(ALLOCA(_length * sizeof(uint8_t)));
                    ASSERT(_data != nullptr);
                    if (_data == nullptr) { return (Core::ERROR_GENERAL); }
                }

                uint16_t result = implementation->Generate(_length, _data);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Buffer<uint16_t>(result, _data);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::IRandom::ID, 0, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
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
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                Exchange::IHash* implementation = reinterpret_cast<Exchange::IHash*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::IHash::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (Core::RealSize<Core::UInt24>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const Core::UInt24 _dataPeekedLen__ = reader.PeekNumber<Core::UInt24>();
                ASSERT((_dataPeekedLen__ >= 0) && (_dataPeekedLen__ <= 4194303));
                if (!((_dataPeekedLen__ >= 0) && (_dataPeekedLen__ <= 4194303))) { return (COM_ERROR | Core::ERROR_INVALID_RANGE); }
                if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<Core::UInt24>()) + _dataPeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint8_t* _data{};
                const uint32_t _length = reader.LockBuffer<Core::UInt24>(_data);
                reader.UnlockBuffer(_length);

                uint32_t result = implementation->Ingest(_length, _data);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(result);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::IHash::ID, 0, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        },

        // (1) virtual uint8_t Calculate(const uint8_t, uint8_t*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                Exchange::IHash* implementation = reinterpret_cast<Exchange::IHash*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::IHash::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (Core::RealSize<uint8_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint8_t _maxLength = reader.Number<uint8_t>();

                uint8_t* _data{};

                if (_maxLength != 0) {
                    _data = static_cast<uint8_t*>(ALLOCA(_maxLength * sizeof(uint8_t)));
                    ASSERT(_data != nullptr);
                    if (_data == nullptr) { return (Core::ERROR_GENERAL); }
                }

                uint8_t result = implementation->Calculate(_maxLength, _data);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Buffer<uint8_t>(result, _data);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::IHash::ID, 1, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
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
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const Exchange::ICipher* implementation = reinterpret_cast<const Exchange::ICipher*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::ICipher::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (Core::RealSize<uint8_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint8_t _ivPeekedLen__ = reader.PeekNumber<uint8_t>();
                if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint8_t>()) + _ivPeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint8_t* _iv{};
                const uint8_t _ivLength = reader.LockBuffer<uint8_t>(_iv);
                reader.UnlockBuffer(_ivLength);
                if (reader.Length() < (Core::RealSize<Core::UInt24>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const Core::UInt24 _inputPeekedLen__ = reader.PeekNumber<Core::UInt24>();
                ASSERT((_inputPeekedLen__ >= 0) && (_inputPeekedLen__ <= 4194303));
                if (!((_inputPeekedLen__ >= 0) && (_inputPeekedLen__ <= 4194303))) { return (COM_ERROR | Core::ERROR_INVALID_RANGE); }
                if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<Core::UInt24>()) + _inputPeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint8_t* _input{};
                const uint32_t _inputLength = reader.LockBuffer<Core::UInt24>(_input);
                reader.UnlockBuffer(_inputLength);
                if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint32_t _maxOutputLength = reader.Number<uint32_t>();

                uint8_t* _output{};

                if (_maxOutputLength != 0) {
                    ASSERT(_maxOutputLength <= 0x1000000);
                    if (_maxOutputLength > 0x1000000) { return (Core::ERROR_BAD_REQUEST); }

                    _output = static_cast<uint8_t*>(ALLOCA(_maxOutputLength * sizeof(uint8_t)));
                    ASSERT(_output != nullptr);
                    if (_output == nullptr) { return (Core::ERROR_GENERAL); }
                }

                int32_t result = implementation->Encrypt(_ivLength, _iv, _inputLength, _input, _maxOutputLength, _output);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Buffer<int32_t>((result > 0? result : 0), _output);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::ICipher::ID, 0, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        },

        // (1) virtual int32_t Decrypt(const uint8_t, const uint8_t*, const uint32_t, const uint8_t*, const uint32_t, uint8_t*) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const Exchange::ICipher* implementation = reinterpret_cast<const Exchange::ICipher*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::ICipher::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (Core::RealSize<uint8_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint8_t _ivPeekedLen__ = reader.PeekNumber<uint8_t>();
                if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint8_t>()) + _ivPeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint8_t* _iv{};
                const uint8_t _ivLength = reader.LockBuffer<uint8_t>(_iv);
                reader.UnlockBuffer(_ivLength);
                if (reader.Length() < (Core::RealSize<Core::UInt24>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const Core::UInt24 _inputPeekedLen__ = reader.PeekNumber<Core::UInt24>();
                ASSERT((_inputPeekedLen__ >= 0) && (_inputPeekedLen__ <= 4194303));
                if (!((_inputPeekedLen__ >= 0) && (_inputPeekedLen__ <= 4194303))) { return (COM_ERROR | Core::ERROR_INVALID_RANGE); }
                if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<Core::UInt24>()) + _inputPeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint8_t* _input{};
                const uint32_t _inputLength = reader.LockBuffer<Core::UInt24>(_input);
                reader.UnlockBuffer(_inputLength);
                if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint32_t _maxOutputLength = reader.Number<uint32_t>();

                uint8_t* _output{};

                if (_maxOutputLength != 0) {
                    ASSERT(_maxOutputLength <= 0x1000000);
                    if (_maxOutputLength > 0x1000000) { return (Core::ERROR_BAD_REQUEST); }

                    _output = static_cast<uint8_t*>(ALLOCA(_maxOutputLength * sizeof(uint8_t)));
                    ASSERT(_output != nullptr);
                    if (_output == nullptr) { return (Core::ERROR_GENERAL); }
                }

                int32_t result = implementation->Decrypt(_ivLength, _iv, _inputLength, _input, _maxOutputLength, _output);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Buffer<int32_t>((result > 0? result : 0), _output);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::ICipher::ID, 1, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
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
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                Exchange::IDiffieHellman* implementation = reinterpret_cast<Exchange::IDiffieHellman*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::IDiffieHellman::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (Core::RealSize<uint8_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint8_t _generator = reader.Number<uint8_t>();
                if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint16_t _modulusPeekedLen__ = reader.PeekNumber<uint16_t>();
                if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint16_t>()) + _modulusPeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
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

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::IDiffieHellman::ID, 0, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        },

        // (1) virtual uint32_t Derive(const uint32_t, const uint32_t, uint32_t&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                Exchange::IDiffieHellman* implementation = reinterpret_cast<Exchange::IDiffieHellman*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::IDiffieHellman::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint32_t _privateKey = reader.Number<uint32_t>();
                if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint32_t _peerPublicKeyId = reader.Number<uint32_t>();

                uint32_t _secretId{};

                uint32_t result = implementation->Derive(_privateKey, _peerPublicKeyId, _secretId);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(result);
                writer.Number<uint32_t>(_secretId);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::IDiffieHellman::ID, 1, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
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
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const Exchange::IPersistent* implementation = reinterpret_cast<const Exchange::IPersistent*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::IPersistent::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint16_t _locatorPeekedLen__ = reader.PeekNumber<uint16_t>();
                if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint16_t>()) + _locatorPeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const string _locator = reader.Text();

                bool _result{};

                uint32_t result = implementation->Exists(static_cast<const string&>(_locator), _result);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(result);
                writer.Boolean(_result);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::IPersistent::ID, 0, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        },

        // (1) virtual uint32_t Load(const string&, uint32_t&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                Exchange::IPersistent* implementation = reinterpret_cast<Exchange::IPersistent*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::IPersistent::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint16_t _locatorPeekedLen__ = reader.PeekNumber<uint16_t>();
                if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint16_t>()) + _locatorPeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const string _locator = reader.Text();

                uint32_t _id{};

                uint32_t result = implementation->Load(static_cast<const string&>(_locator), _id);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(result);
                writer.Number<uint32_t>(_id);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::IPersistent::ID, 1, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        },

        // (2) virtual uint32_t Create(const string&, const Exchange::IPersistent::keytype, uint32_t&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                Exchange::IPersistent* implementation = reinterpret_cast<Exchange::IPersistent*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::IPersistent::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint16_t _locatorPeekedLen__ = reader.PeekNumber<uint16_t>();
                if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint16_t>()) + _locatorPeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const string _locator = reader.Text();
                if (reader.Length() < (Core::RealSize<Exchange::IPersistent::keytype>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const Exchange::IPersistent::keytype _keyType = reader.Number<Exchange::IPersistent::keytype>();

                uint32_t _id{};

                uint32_t result = implementation->Create(static_cast<const string&>(_locator), _keyType, _id);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(result);
                writer.Number<uint32_t>(_id);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::IPersistent::ID, 2, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        },

        // (3) virtual uint32_t Flush() = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                Exchange::IPersistent* implementation = reinterpret_cast<Exchange::IPersistent*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::IPersistent::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                uint32_t result = implementation->Flush();

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(result);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::IPersistent::ID, 3, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
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
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const Exchange::IVault* implementation = reinterpret_cast<const Exchange::IVault*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::IVault::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint32_t _id = reader.Number<uint32_t>();

                uint16_t result = implementation->Size(_id);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint16_t>(result);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::IVault::ID, 0, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        },

        // (1) virtual uint32_t Import(const uint16_t, const uint8_t*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                Exchange::IVault* implementation = reinterpret_cast<Exchange::IVault*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::IVault::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint16_t _blobPeekedLen__ = reader.PeekNumber<uint16_t>();
                if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint16_t>()) + _blobPeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint8_t* _blob{};
                const uint16_t _length = reader.LockBuffer<uint16_t>(_blob);
                reader.UnlockBuffer(_length);

                uint32_t result = implementation->Import(_length, _blob);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(result);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::IVault::ID, 1, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        },

        // (2) virtual uint16_t Export(const uint32_t, const uint16_t, uint8_t*) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const Exchange::IVault* implementation = reinterpret_cast<const Exchange::IVault*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::IVault::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint32_t _id = reader.Number<uint32_t>();
                if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint16_t _maxLength = reader.Number<uint16_t>();

                uint8_t* _blob{};

                if (_maxLength != 0) {
                    _blob = static_cast<uint8_t*>(ALLOCA(_maxLength * sizeof(uint8_t)));
                    ASSERT(_blob != nullptr);
                    if (_blob == nullptr) { return (Core::ERROR_GENERAL); }
                }

                uint16_t result = implementation->Export(_id, _maxLength, _blob);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Buffer<uint16_t>(result, _blob);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::IVault::ID, 2, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        },

        // (3) virtual uint32_t Set(const uint16_t, const uint8_t*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                Exchange::IVault* implementation = reinterpret_cast<Exchange::IVault*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::IVault::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint16_t _blobPeekedLen__ = reader.PeekNumber<uint16_t>();
                if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint16_t>()) + _blobPeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint8_t* _blob{};
                const uint16_t _length = reader.LockBuffer<uint16_t>(_blob);
                reader.UnlockBuffer(_length);

                uint32_t result = implementation->Set(_length, _blob);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(result);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::IVault::ID, 3, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        },

        // (4) virtual uint16_t Get(const uint32_t, const uint16_t, uint8_t*) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const Exchange::IVault* implementation = reinterpret_cast<const Exchange::IVault*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::IVault::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint32_t _id = reader.Number<uint32_t>();
                if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint16_t _maxLength = reader.Number<uint16_t>();

                uint8_t* _blob{};

                if (_maxLength != 0) {
                    _blob = static_cast<uint8_t*>(ALLOCA(_maxLength * sizeof(uint8_t)));
                    ASSERT(_blob != nullptr);
                    if (_blob == nullptr) { return (Core::ERROR_GENERAL); }
                }

                uint16_t result = implementation->Get(_id, _maxLength, _blob);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Buffer<uint16_t>(result, _blob);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::IVault::ID, 4, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        },

        // (5) virtual uint32_t Generate(const uint16_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                Exchange::IVault* implementation = reinterpret_cast<Exchange::IVault*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::IVault::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint16_t _length = reader.Number<uint16_t>();

                uint32_t result = implementation->Generate(_length);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(result);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::IVault::ID, 5, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        },

        // (6) virtual bool Delete(const uint32_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                Exchange::IVault* implementation = reinterpret_cast<Exchange::IVault*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::IVault::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint32_t _id = reader.Number<uint32_t>();

                bool result = implementation->Delete(_id);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Boolean(result);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::IVault::ID, 6, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        },

        // (7) virtual Exchange::IHash* HMAC(const Exchange::hashtype, const uint32_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                Exchange::IVault* implementation = reinterpret_cast<Exchange::IVault*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::IVault::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (Core::RealSize<Exchange::hashtype>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const Exchange::hashtype _hashType = reader.Number<Exchange::hashtype>();
                if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint32_t _keyId = reader.Number<uint32_t>();

                Exchange::IHash* result = implementation->HMAC(_hashType, _keyId);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<Core::instance_id>(RPC::instance_cast(result));

                RPC::Administrator::Instance().RegisterInterface(channel, result);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::IVault::ID, 7, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        },

        // (8) virtual Exchange::ICipher* AES(const Exchange::aesmode, const uint32_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                Exchange::IVault* implementation = reinterpret_cast<Exchange::IVault*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::IVault::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (Core::RealSize<Exchange::aesmode>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const Exchange::aesmode _aesMode = reader.Number<Exchange::aesmode>();
                if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint32_t _keyId = reader.Number<uint32_t>();

                Exchange::ICipher* result = implementation->AES(_aesMode, _keyId);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<Core::instance_id>(RPC::instance_cast(result));

                RPC::Administrator::Instance().RegisterInterface(channel, result);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::IVault::ID, 8, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        },

        // (9) virtual Exchange::IDiffieHellman* DiffieHellman() = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                Exchange::IVault* implementation = reinterpret_cast<Exchange::IVault*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::IVault::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                Exchange::IDiffieHellman* result = implementation->DiffieHellman();

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<Core::instance_id>(RPC::instance_cast(result));

                RPC::Administrator::Instance().RegisterInterface(channel, result);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::IVault::ID, 9, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
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
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                Exchange::IDeviceObjects* implementation = reinterpret_cast<Exchange::IDeviceObjects*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::IDeviceObjects::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint16_t _labelPeekedLen__ = reader.PeekNumber<uint16_t>();
                if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint16_t>()) + _labelPeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const string _label = reader.Text();

                Exchange::IVault* _vault{};

                uint32_t result = implementation->Id(static_cast<const string&>(_label), _vault);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(result);
                writer.Number<Core::instance_id>(RPC::instance_cast(_vault));

                RPC::Administrator::Instance().RegisterInterface(channel, _vault);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::IDeviceObjects::ID, 0, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
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
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                Exchange::ICryptography* implementation = reinterpret_cast<Exchange::ICryptography*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::ICryptography::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                Exchange::IRandom* result = implementation->Random();

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<Core::instance_id>(RPC::instance_cast(result));

                RPC::Administrator::Instance().RegisterInterface(channel, result);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::ICryptography::ID, 0, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        },

        // (1) virtual Exchange::IHash* Hash(const Exchange::hashtype) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                Exchange::ICryptography* implementation = reinterpret_cast<Exchange::ICryptography*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::ICryptography::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (Core::RealSize<Exchange::hashtype>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const Exchange::hashtype _hashType = reader.Number<Exchange::hashtype>();

                Exchange::IHash* result = implementation->Hash(_hashType);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<Core::instance_id>(RPC::instance_cast(result));

                RPC::Administrator::Instance().RegisterInterface(channel, result);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::ICryptography::ID, 1, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        },

        // (2) virtual Exchange::IVault* Vault(const Exchange::CryptographyVault) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                Exchange::ICryptography* implementation = reinterpret_cast<Exchange::ICryptography*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::ICryptography::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (Core::RealSize<Exchange::CryptographyVault>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const Exchange::CryptographyVault _id = reader.Number<Exchange::CryptographyVault>();

                Exchange::IVault* result = implementation->Vault(_id);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<Core::instance_id>(RPC::instance_cast(result));

                RPC::Administrator::Instance().RegisterInterface(channel, result);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::ICryptography::ID, 2, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
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

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    const uint16_t _dataPeekedLen__ = reader.PeekNumber<uint16_t>();
                    if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint16_t>()) + _dataPeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    result = reader.Buffer<uint16_t>(_length, _data);

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::IRandom::ID, 0, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
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
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::IHash::ID, 0, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }

            return (result);
        }

        uint8_t Calculate(const uint8_t _maxLength, uint8_t* _data) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint8_t>(_maxLength);

            uint8_t result{};

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<uint8_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    const uint8_t _dataPeekedLen__ = reader.PeekNumber<uint8_t>();
                    if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint8_t>()) + _dataPeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    result = reader.Buffer<uint8_t>(_maxLength, _data);

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::IHash::ID, 1, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
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

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<int32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    const int32_t _outputPeekedLen__ = reader.PeekNumber<int32_t>();
                    if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<int32_t>()) + _outputPeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    result = reader.Buffer<uint32_t>(_maxOutputLength, _output);

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::ICipher::ID, 0, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
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

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<int32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    const int32_t _outputPeekedLen__ = reader.PeekNumber<int32_t>();
                    if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<int32_t>()) + _outputPeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    result = reader.Buffer<uint32_t>(_maxOutputLength, _output);

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::ICipher::ID, 1, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
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

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    result = reader.Number<uint32_t>();
                    if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    _privKeyId = reader.Number<uint32_t>();
                    if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    _pubKeyId = reader.Number<uint32_t>();

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::IDiffieHellman::ID, 0, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
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

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    result = reader.Number<uint32_t>();
                    if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    _secretId = reader.Number<uint32_t>();

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::IDiffieHellman::ID, 1, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
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

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    result = reader.Number<uint32_t>();
                    if (reader.Length() < (1)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    _result = reader.Boolean();

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::IPersistent::ID, 0, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }

            return (result);
        }

        uint32_t Load(const string& _locator, uint32_t& _id) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_locator);

            uint32_t result{};

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    result = reader.Number<uint32_t>();
                    if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    _id = reader.Number<uint32_t>();

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::IPersistent::ID, 1, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
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

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    result = reader.Number<uint32_t>();
                    if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    _id = reader.Number<uint32_t>();

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::IPersistent::ID, 2, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }

            return (result);
        }

        uint32_t Flush() override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(3));

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
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::IPersistent::ID, 3, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
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

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    result = reader.Number<uint16_t>();

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::IVault::ID, 0, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }

            return (result);
        }

        uint32_t Import(const uint16_t _length, const uint8_t* _blob) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Buffer<uint16_t>(_length, _blob);

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
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::IVault::ID, 1, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
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

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    const uint16_t _blobPeekedLen__ = reader.PeekNumber<uint16_t>();
                    if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint16_t>()) + _blobPeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    result = reader.Buffer<uint16_t>(_maxLength, _blob);

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::IVault::ID, 2, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }

            return (result);
        }

        uint32_t Set(const uint16_t _length, const uint8_t* _blob) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(3));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Buffer<uint16_t>(_length, _blob);

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
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::IVault::ID, 3, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
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

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    const uint16_t _blobPeekedLen__ = reader.PeekNumber<uint16_t>();
                    if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint16_t>()) + _blobPeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    result = reader.Buffer<uint16_t>(_maxLength, _blob);

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::IVault::ID, 4, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }

            return (result);
        }

        uint32_t Generate(const uint16_t _length) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(5));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint16_t>(_length);

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
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::IVault::ID, 5, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }

            return (result);
        }

        bool Delete(const uint32_t _id) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(6));

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
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::IVault::ID, 6, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
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

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    result = reinterpret_cast<Exchange::IHash*>(static_cast<const ProxyStub::UnknownProxy&>(*this).Interface(reader.Number<Core::instance_id>(), Exchange::IHash::ID));

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::IVault::ID, 7, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
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

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    result = reinterpret_cast<Exchange::ICipher*>(static_cast<const ProxyStub::UnknownProxy&>(*this).Interface(reader.Number<Core::instance_id>(), Exchange::ICipher::ID));

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::IVault::ID, 8, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }

            return (result);
        }

        Exchange::IDiffieHellman* DiffieHellman() override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(9));

            Exchange::IDiffieHellman* result{};

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    result = reinterpret_cast<Exchange::IDiffieHellman*>(static_cast<const ProxyStub::UnknownProxy&>(*this).Interface(reader.Number<Core::instance_id>(), Exchange::IDiffieHellman::ID));

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::IVault::ID, 9, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
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

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    result = reader.Number<uint32_t>();
                    _vault = reinterpret_cast<Exchange::IVault*>(static_cast<const ProxyStub::UnknownProxy&>(*this).Interface(reader.Number<Core::instance_id>(), Exchange::IVault::ID));

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::IDeviceObjects::ID, 0, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
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

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    result = reinterpret_cast<Exchange::IRandom*>(static_cast<const ProxyStub::UnknownProxy&>(*this).Interface(reader.Number<Core::instance_id>(), Exchange::IRandom::ID));

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::ICryptography::ID, 0, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }

            return (result);
        }

        Exchange::IHash* Hash(const Exchange::hashtype _hashType) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Exchange::hashtype>(_hashType);

            Exchange::IHash* result{};

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    result = reinterpret_cast<Exchange::IHash*>(static_cast<const ProxyStub::UnknownProxy&>(*this).Interface(reader.Number<Core::instance_id>(), Exchange::IHash::ID));

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::ICryptography::ID, 1, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }

            return (result);
        }

        Exchange::IVault* Vault(const Exchange::CryptographyVault _id) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(2));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Exchange::CryptographyVault>(_id);

            Exchange::IVault* result{};

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    result = reinterpret_cast<Exchange::IVault*>(static_cast<const ProxyStub::UnknownProxy&>(*this).Interface(reader.Number<Core::instance_id>(), Exchange::IVault::ID));

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::ICryptography::ID, 2, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
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
                const RPC::SecureProxyStubType security = static_cast<RPC::SecureProxyStubType>(static_cast<std::underlying_type<RPC::SecureProxyStubType>::type>(RPC::SecureProxyStubType::PROXYSTUBS_SECURITY_SECURE) | static_cast<std::underlying_type<RPC::SecureProxyStubType>::type>(RPC::SecureProxyStubType::PROXYSTUBS_SECURITY_COHERENT));

                RPC::Administrator::Instance().Announce<Exchange::IRandom, ExchangeRandomProxy, ExchangeRandomStub>(security);
                RPC::Administrator::Instance().Announce<Exchange::IHash, ExchangeHashProxy, ExchangeHashStub>(security);
                RPC::Administrator::Instance().Announce<Exchange::ICipher, ExchangeCipherProxy, ExchangeCipherStub>(security);
                RPC::Administrator::Instance().Announce<Exchange::IDiffieHellman, ExchangeDiffieHellmanProxy, ExchangeDiffieHellmanStub>(security);
                RPC::Administrator::Instance().Announce<Exchange::IPersistent, ExchangePersistentProxy, ExchangePersistentStub>(security);
                RPC::Administrator::Instance().Announce<Exchange::IVault, ExchangeVaultProxy, ExchangeVaultStub>(security);
                RPC::Administrator::Instance().Announce<Exchange::IDeviceObjects, ExchangeDeviceObjectsProxy, ExchangeDeviceObjectsStub>(security);
                RPC::Administrator::Instance().Announce<Exchange::ICryptography, ExchangeCryptographyProxy, ExchangeCryptographyStub>(security);
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
