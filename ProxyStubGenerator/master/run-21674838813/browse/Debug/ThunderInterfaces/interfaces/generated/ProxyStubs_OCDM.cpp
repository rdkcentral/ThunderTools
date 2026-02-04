//
// generated automatically from "IOCDM.h"
//
// implements COM-RPC proxy stubs for:
//   - class RPC::IIteratorType<typename ELEMENT, const uint32_t INTERFACE_ID> [with ELEMENT = string, INTERFACE_ID = RPC::ID_STRINGITERATOR] [[iterator]]
//   - class Exchange::IOpenCDM
//   - class Exchange::ISession
//   - class Exchange::ISession::ICallback
//   - class Exchange::ISessionExt
//   - class Exchange::IAccessorOCDM
//

#include "Module.h"
#include "IOCDM.h"

#include <com/com.h>

namespace Thunder {

namespace ProxyStubs {

    PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    // -----------------------------------------------------------------
    // STUBS
    // -----------------------------------------------------------------

    //
    // RPC::IIteratorTypeInstance_b3acff3685df4032 interface stub definitions
    //
    // Methods:
    //  (0) virtual bool Next(string&) = 0
    //  (1) virtual bool Previous(string&) = 0
    //  (2) virtual void Reset(const uint32_t) = 0
    //  (3) virtual bool IsValid() const = 0
    //  (4) virtual uint32_t Count() const = 0
    //  (5) virtual string Current() const = 0
    //

    static ProxyStub::MethodHandler RPCIteratorTypeInstance_b3acff3685df4032StubMethods[] = {
        // (0) virtual bool Next(string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>;

            interface* implementation = reinterpret_cast<interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            string _info{};

            bool result = implementation->Next(_info);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Boolean(result);
            writer.Text(_info);
        },

        // (1) virtual bool Previous(string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>;

            interface* implementation = reinterpret_cast<interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            string _info{};

            bool result = implementation->Previous(_info);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Boolean(result);
            writer.Text(_info);
        },

        // (2) virtual void Reset(const uint32_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>;

            interface* implementation = reinterpret_cast<interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint32_t _position = reader.Number<uint32_t>();

            implementation->Reset(_position);
        },

        // (3) virtual bool IsValid() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>;

            const interface* implementation = reinterpret_cast<const interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            bool result = implementation->IsValid();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Boolean(result);
        },

        // (4) virtual uint32_t Count() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>;

            const interface* implementation = reinterpret_cast<const interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            uint32_t result = implementation->Count();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (5) virtual string Current() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>;

            const interface* implementation = reinterpret_cast<const interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            string result = implementation->Current();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Text(result);
        }
        , nullptr
    }; // RPCIteratorTypeInstance_b3acff3685df4032StubMethods

    //
    // Exchange::IOpenCDM interface stub definitions
    //
    // Methods:
    //  (0) virtual Core::hresult Systems(Exchange::IOpenCDM::IStringIterator*&) const = 0
    //  (1) virtual Core::hresult Designators(const string&, Exchange::IOpenCDM::IStringIterator*&) const = 0
    //

    static ProxyStub::MethodHandler ExchangeOpenCDMStubMethods[] = {
        // (0) virtual Core::hresult Systems(Exchange::IOpenCDM::IStringIterator*&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IOpenCDM* implementation = reinterpret_cast<const Exchange::IOpenCDM*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::IOpenCDM::IStringIterator* _keySystems{};

            Core::hresult result = implementation->Systems(_keySystems);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
            writer.Number<Core::instance_id>(RPC::instance_cast(_keySystems));

            RPC::Administrator::Instance().RegisterInterface(channel, _keySystems);
        },

        // (1) virtual Core::hresult Designators(const string&, Exchange::IOpenCDM::IStringIterator*&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IOpenCDM* implementation = reinterpret_cast<const Exchange::IOpenCDM*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _keySystem = reader.Text();

            Exchange::IOpenCDM::IStringIterator* _designators{};

            Core::hresult result = implementation->Designators(static_cast<const string&>(_keySystem), _designators);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
            writer.Number<Core::instance_id>(RPC::instance_cast(_designators));

            RPC::Administrator::Instance().RegisterInterface(channel, _designators);
        }
        , nullptr
    }; // ExchangeOpenCDMStubMethods

    //
    // Exchange::ISession interface stub definitions
    //
    // Methods:
    //  (0) virtual Exchange::OCDM_RESULT Load() = 0
    //  (1) virtual void Update(const uint8_t*, const uint16_t) = 0
    //  (2) virtual Exchange::OCDM_RESULT Remove() = 0
    //  (3) virtual string Metadata() const = 0
    //  (4) virtual Exchange::OCDM_RESULT Metricdata(uint32_t&, uint8_t*) const = 0
    //  (5) virtual Exchange::ISession::KeyStatus Status() const = 0
    //  (6) virtual Exchange::ISession::KeyStatus Status(const uint8_t*, const uint8_t) const = 0
    //  (7) virtual Exchange::OCDM_RESULT CreateSessionBuffer(string&) = 0
    //  (8) virtual string BufferId() const = 0
    //  (9) virtual string SessionId() const = 0
    //  (10) virtual void Close() = 0
    //  (11) virtual void ResetOutputProtection() = 0
    //  (12) virtual void Revoke(Exchange::ISession::ICallback*) = 0
    //  (13) virtual Exchange::OCDM_RESULT SetParameter(const string&, const string&)
    //

    static ProxyStub::MethodHandler ExchangeSessionStubMethods[] = {
        // (0) virtual Exchange::OCDM_RESULT Load() = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::ISession* implementation = reinterpret_cast<Exchange::ISession*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::OCDM_RESULT result = implementation->Load();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Exchange::OCDM_RESULT>(result);
        },

        // (1) virtual void Update(const uint8_t*, const uint16_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::ISession* implementation = reinterpret_cast<Exchange::ISession*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint8_t* _keyMessage{};
            const uint16_t _keyLength = reader.LockBuffer<uint16_t>(_keyMessage);
            reader.UnlockBuffer(_keyLength);

            implementation->Update(_keyMessage, _keyLength);
        },

        // (2) virtual Exchange::OCDM_RESULT Remove() = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::ISession* implementation = reinterpret_cast<Exchange::ISession*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::OCDM_RESULT result = implementation->Remove();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Exchange::OCDM_RESULT>(result);
        },

        // (3) virtual string Metadata() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::ISession* implementation = reinterpret_cast<const Exchange::ISession*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            string result = implementation->Metadata();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Text(result);
        },

        // (4) virtual Exchange::OCDM_RESULT Metricdata(uint32_t&, uint8_t*) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::ISession* implementation = reinterpret_cast<const Exchange::ISession*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            uint32_t _bufferSize = reader.Number<uint32_t>();

            uint8_t* _buffer{};

            if (_bufferSize != 0) {
                ASSERT(_bufferSize <= 0x1000000);
                _buffer = static_cast<uint8_t*>(ALLOCA(_bufferSize * sizeof(uint8_t)));
                ASSERT(_buffer != nullptr);
            }

            Exchange::OCDM_RESULT result = implementation->Metricdata(_bufferSize, _buffer);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Exchange::OCDM_RESULT>(result);
            writer.Buffer<uint32_t>((_buffer == nullptr? 0 : _bufferSize), _buffer);
            writer.Number<uint32_t>(_bufferSize);
        },

        // (5) virtual Exchange::ISession::KeyStatus Status() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::ISession* implementation = reinterpret_cast<const Exchange::ISession*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::ISession::KeyStatus result = implementation->Status();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Exchange::ISession::KeyStatus>(result);
        },

        // (6) virtual Exchange::ISession::KeyStatus Status(const uint8_t*, const uint8_t) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::ISession* implementation = reinterpret_cast<const Exchange::ISession*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint8_t* _keyID{};
            const uint8_t _keyIDLength = reader.LockBuffer<uint8_t>(_keyID);
            reader.UnlockBuffer(_keyIDLength);

            Exchange::ISession::KeyStatus result = implementation->Status(_keyID, _keyIDLength);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Exchange::ISession::KeyStatus>(result);
        },

        // (7) virtual Exchange::OCDM_RESULT CreateSessionBuffer(string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::ISession* implementation = reinterpret_cast<Exchange::ISession*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            string _bufferID{};

            Exchange::OCDM_RESULT result = implementation->CreateSessionBuffer(_bufferID);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Exchange::OCDM_RESULT>(result);
            writer.Text(_bufferID);
        },

        // (8) virtual string BufferId() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::ISession* implementation = reinterpret_cast<const Exchange::ISession*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            string result = implementation->BufferId();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Text(result);
        },

        // (9) virtual string SessionId() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::ISession* implementation = reinterpret_cast<const Exchange::ISession*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            string result = implementation->SessionId();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Text(result);
        },

        // (10) virtual void Close() = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::ISession* implementation = reinterpret_cast<Exchange::ISession*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            implementation->Close();
        },

        // (11) virtual void ResetOutputProtection() = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::ISession* implementation = reinterpret_cast<Exchange::ISession*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            implementation->ResetOutputProtection();
        },

        // (12) virtual void Revoke(Exchange::ISession::ICallback*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::ISession* implementation = reinterpret_cast<Exchange::ISession*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            Core::instance_id _callbackInstanceId__ = reader.Number<Core::instance_id>();

            Exchange::ISession::ICallback* _callback{};
            ProxyStub::UnknownProxy* _callbackProxy__ = nullptr;
            if (_callbackInstanceId__ != 0) {
                _callbackProxy__ = RPC::Administrator::Instance().ProxyInstance(channel, _callbackInstanceId__, false, _callback);
                ASSERT((_callback != nullptr) && (_callbackProxy__ != nullptr));
            }

            implementation->Revoke(_callback);

            if (_callbackProxy__ != nullptr) {
                RPC::Administrator::Instance().Release(_callbackProxy__, message->Response());
            }
        },

        // (13) virtual Exchange::OCDM_RESULT SetParameter(const string&, const string&)
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::ISession* implementation = reinterpret_cast<Exchange::ISession*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _parameter_1 = reader.Text();
            const string _parameter_2 = reader.Text();

            Exchange::OCDM_RESULT result = implementation->SetParameter(static_cast<const string&>(_parameter_1), static_cast<const string&>(_parameter_2));

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Exchange::OCDM_RESULT>(result);
        }
        , nullptr
    }; // ExchangeSessionStubMethods

    //
    // Exchange::ISession::ICallback interface stub definitions
    //
    // Methods:
    //  (0) virtual void OnKeyMessage(const uint8_t*, const uint16_t, const string&) = 0
    //  (1) virtual void OnError(const int16_t, const Exchange::OCDM_RESULT, const string&) = 0
    //  (2) virtual void OnKeyStatusUpdate(const uint8_t*, const uint8_t, const Exchange::ISession::KeyStatus) = 0
    //  (3) virtual void OnKeyStatusesUpdated() const = 0
    //

    static ProxyStub::MethodHandler ExchangeSessionCallbackStubMethods[] = {
        // (0) virtual void OnKeyMessage(const uint8_t*, const uint16_t, const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::ISession::ICallback* implementation = reinterpret_cast<Exchange::ISession::ICallback*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint8_t* _keyMessage{};
            const uint16_t _keyLength = reader.LockBuffer<uint16_t>(_keyMessage);
            reader.UnlockBuffer(_keyLength);
            const string _URL = reader.Text();

            implementation->OnKeyMessage(_keyMessage, _keyLength, static_cast<const string&>(_URL));
        },

        // (1) virtual void OnError(const int16_t, const Exchange::OCDM_RESULT, const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::ISession::ICallback* implementation = reinterpret_cast<Exchange::ISession::ICallback*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const int16_t _error = reader.Number<int16_t>();
            const Exchange::OCDM_RESULT _sysError = reader.Number<Exchange::OCDM_RESULT>();
            const string _errorMessage = reader.Text();

            implementation->OnError(_error, _sysError, static_cast<const string&>(_errorMessage));
        },

        // (2) virtual void OnKeyStatusUpdate(const uint8_t*, const uint8_t, const Exchange::ISession::KeyStatus) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::ISession::ICallback* implementation = reinterpret_cast<Exchange::ISession::ICallback*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint8_t* _keyID{};
            const uint8_t _keyIDLength = reader.LockBuffer<uint8_t>(_keyID);
            reader.UnlockBuffer(_keyIDLength);
            const Exchange::ISession::KeyStatus _status = reader.Number<Exchange::ISession::KeyStatus>();

            implementation->OnKeyStatusUpdate(_keyID, _keyIDLength, _status);
        },

        // (3) virtual void OnKeyStatusesUpdated() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::ISession::ICallback* implementation = reinterpret_cast<const Exchange::ISession::ICallback*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            implementation->OnKeyStatusesUpdated();
        }
        , nullptr
    }; // ExchangeSessionCallbackStubMethods

    //
    // Exchange::ISessionExt interface stub definitions
    //
    // Methods:
    //  (0) virtual uint32_t SessionIdExt() const = 0
    //  (1) virtual string BufferIdExt() const = 0
    //  (2) virtual Exchange::OCDM_RESULT SetDrmHeader(const uint8_t*, uint16_t) = 0
    //  (3) virtual Exchange::OCDM_RESULT GetChallengeDataExt(uint8_t*, uint16_t&, uint32_t) = 0
    //  (4) virtual Exchange::OCDM_RESULT CancelChallengeDataExt() = 0
    //  (5) virtual Exchange::OCDM_RESULT StoreLicenseData(const uint8_t*, uint16_t, uint8_t*) = 0
    //  (6) virtual Exchange::OCDM_RESULT SelectKeyId(const uint8_t, const uint8_t*) = 0
    //  (7) virtual Exchange::OCDM_RESULT CleanDecryptContext() = 0
    //

    static ProxyStub::MethodHandler ExchangeSessionExtStubMethods[] = {
        // (0) virtual uint32_t SessionIdExt() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::ISessionExt* implementation = reinterpret_cast<const Exchange::ISessionExt*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            uint32_t result = implementation->SessionIdExt();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (1) virtual string BufferIdExt() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::ISessionExt* implementation = reinterpret_cast<const Exchange::ISessionExt*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            string result = implementation->BufferIdExt();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Text(result);
        },

        // (2) virtual Exchange::OCDM_RESULT SetDrmHeader(const uint8_t*, uint16_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::ISessionExt* implementation = reinterpret_cast<Exchange::ISessionExt*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint8_t* _drmHeader{};
            uint16_t _drmHeaderLength = reader.LockBuffer<uint16_t>(_drmHeader);
            reader.UnlockBuffer(_drmHeaderLength);

            Exchange::OCDM_RESULT result = implementation->SetDrmHeader(_drmHeader, _drmHeaderLength);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Exchange::OCDM_RESULT>(result);
        },

        // (3) virtual Exchange::OCDM_RESULT GetChallengeDataExt(uint8_t*, uint16_t&, uint32_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::ISessionExt* implementation = reinterpret_cast<Exchange::ISessionExt*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            uint16_t _challengeSize = reader.Number<uint16_t>();
            uint32_t _isLDL = reader.Number<uint32_t>();

            uint8_t* _challenge{};

            if (_challengeSize != 0) {
                _challenge = static_cast<uint8_t*>(ALLOCA(_challengeSize * sizeof(uint8_t)));
                ASSERT(_challenge != nullptr);
            }

            Exchange::OCDM_RESULT result = implementation->GetChallengeDataExt(_challenge, _challengeSize, _isLDL);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Exchange::OCDM_RESULT>(result);
            writer.Buffer<uint16_t>((_challenge == nullptr? 0 : _challengeSize), _challenge);
            writer.Number<uint16_t>(_challengeSize);
        },

        // (4) virtual Exchange::OCDM_RESULT CancelChallengeDataExt() = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::ISessionExt* implementation = reinterpret_cast<Exchange::ISessionExt*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::OCDM_RESULT result = implementation->CancelChallengeDataExt();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Exchange::OCDM_RESULT>(result);
        },

        // (5) virtual Exchange::OCDM_RESULT StoreLicenseData(const uint8_t*, uint16_t, uint8_t*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::ISessionExt* implementation = reinterpret_cast<Exchange::ISessionExt*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint8_t* _licenseData{};
            uint16_t _licenseDataSize = reader.LockBuffer<uint16_t>(_licenseData);
            reader.UnlockBuffer(_licenseDataSize);

            uint8_t* _secureStopId{};

            _secureStopId = static_cast<uint8_t*>(ALLOCA(16 * sizeof(uint8_t)));
            ASSERT(_secureStopId != nullptr);

            Exchange::OCDM_RESULT result = implementation->StoreLicenseData(_licenseData, _licenseDataSize, _secureStopId);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Exchange::OCDM_RESULT>(result);
            writer.Buffer<uint8_t>(16, _secureStopId);
        },

        // (6) virtual Exchange::OCDM_RESULT SelectKeyId(const uint8_t, const uint8_t*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::ISessionExt* implementation = reinterpret_cast<Exchange::ISessionExt*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint8_t* _keyId{};
            const uint8_t _keyLength = reader.LockBuffer<uint8_t>(_keyId);
            reader.UnlockBuffer(_keyLength);

            Exchange::OCDM_RESULT result = implementation->SelectKeyId(_keyLength, _keyId);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Exchange::OCDM_RESULT>(result);
        },

        // (7) virtual Exchange::OCDM_RESULT CleanDecryptContext() = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::ISessionExt* implementation = reinterpret_cast<Exchange::ISessionExt*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::OCDM_RESULT result = implementation->CleanDecryptContext();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Exchange::OCDM_RESULT>(result);
        }
        , nullptr
    }; // ExchangeSessionExtStubMethods

    //
    // Exchange::IAccessorOCDM interface stub definitions
    //
    // Methods:
    //  (0) virtual bool IsTypeSupported(const string&, const string&) const = 0
    //  (1) virtual Exchange::OCDM_RESULT Metadata(const string&, string&) const = 0
    //  (2) virtual Exchange::OCDM_RESULT Metricdata(const string&, uint32_t&, uint8_t*) const = 0
    //  (3) virtual Exchange::OCDM_RESULT CreateSession(const string&, const int32_t, const string&, const uint8_t*, const uint16_t, const uint8_t*, const uint16_t, Exchange::ISession::ICallback*, string&, Exchange::ISession*&) = 0
    //  (4) virtual Exchange::OCDM_RESULT SetServerCertificate(const string&, const uint8_t*, const uint16_t) = 0
    //  (5) virtual uint64_t GetDrmSystemTime(const string&) const = 0
    //  (6) virtual string GetVersionExt(const string&) const = 0
    //  (7) virtual uint32_t GetLdlSessionLimit(const string&) const = 0
    //  (8) virtual bool IsSecureStopEnabled(const string&) = 0
    //  (9) virtual Exchange::OCDM_RESULT EnableSecureStop(const string&, bool) = 0
    //  (10) virtual uint32_t ResetSecureStops(const string&) = 0
    //  (11) virtual Exchange::OCDM_RESULT GetSecureStopIds(const string&, uint8_t*, uint16_t, uint32_t&) = 0
    //  (12) virtual Exchange::OCDM_RESULT GetSecureStop(const string&, const uint8_t*, uint16_t, uint8_t*, uint16_t&) = 0
    //  (13) virtual Exchange::OCDM_RESULT CommitSecureStop(const string&, const uint8_t*, uint16_t, const uint8_t*, uint16_t) = 0
    //  (14) virtual Exchange::OCDM_RESULT DeleteKeyStore(const string&) = 0
    //  (15) virtual Exchange::OCDM_RESULT DeleteSecureStore(const string&) = 0
    //  (16) virtual Exchange::OCDM_RESULT GetKeyStoreHash(const string&, uint8_t*, uint16_t) = 0
    //  (17) virtual Exchange::OCDM_RESULT GetSecureStoreHash(const string&, uint8_t*, uint16_t) = 0
    //

    static ProxyStub::MethodHandler ExchangeAccessorOCDMStubMethods[] = {
        // (0) virtual bool IsTypeSupported(const string&, const string&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IAccessorOCDM* implementation = reinterpret_cast<const Exchange::IAccessorOCDM*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _keySystem = reader.Text();
            const string _mimeType = reader.Text();

            bool result = implementation->IsTypeSupported(static_cast<const string&>(_keySystem), static_cast<const string&>(_mimeType));

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Boolean(result);
        },

        // (1) virtual Exchange::OCDM_RESULT Metadata(const string&, string&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IAccessorOCDM* implementation = reinterpret_cast<const Exchange::IAccessorOCDM*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _keySystem = reader.Text();

            string _metadata{};

            Exchange::OCDM_RESULT result = implementation->Metadata(static_cast<const string&>(_keySystem), _metadata);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Exchange::OCDM_RESULT>(result);
            writer.Text(_metadata);
        },

        // (2) virtual Exchange::OCDM_RESULT Metricdata(const string&, uint32_t&, uint8_t*) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IAccessorOCDM* implementation = reinterpret_cast<const Exchange::IAccessorOCDM*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _keySystem = reader.Text();
            uint32_t _bufferSize = reader.Number<uint32_t>();

            uint8_t* _buffer{};

            if (_bufferSize != 0) {
                ASSERT(_bufferSize <= 0x1000000);
                _buffer = static_cast<uint8_t*>(ALLOCA(_bufferSize * sizeof(uint8_t)));
                ASSERT(_buffer != nullptr);
            }

            Exchange::OCDM_RESULT result = implementation->Metricdata(static_cast<const string&>(_keySystem), _bufferSize, _buffer);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Exchange::OCDM_RESULT>(result);
            writer.Buffer<uint32_t>((_buffer == nullptr? 0 : _bufferSize), _buffer);
            writer.Number<uint32_t>(_bufferSize);
        },

        // (3) virtual Exchange::OCDM_RESULT CreateSession(const string&, const int32_t, const string&, const uint8_t*, const uint16_t, const uint8_t*, const uint16_t, Exchange::ISession::ICallback*, string&, Exchange::ISession*&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IAccessorOCDM* implementation = reinterpret_cast<Exchange::IAccessorOCDM*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _keySystem = reader.Text();
            const int32_t _licenseType = reader.Number<int32_t>();
            const string _initDataType = reader.Text();
            const uint8_t* _initData{};
            const uint16_t _initDataLength = reader.LockBuffer<uint16_t>(_initData);
            reader.UnlockBuffer(_initDataLength);
            const uint8_t* _CDMData{};
            const uint16_t _CDMDataLength = reader.LockBuffer<uint16_t>(_CDMData);
            reader.UnlockBuffer(_CDMDataLength);
            Core::instance_id _callbackInstanceId__ = reader.Number<Core::instance_id>();

            string _sessionId{};
            Exchange::ISession* _session{};

            Exchange::ISession::ICallback* _callback{};
            ProxyStub::UnknownProxy* _callbackProxy__ = nullptr;
            if (_callbackInstanceId__ != 0) {
                _callbackProxy__ = RPC::Administrator::Instance().ProxyInstance(channel, _callbackInstanceId__, false, _callback);
                ASSERT((_callback != nullptr) && (_callbackProxy__ != nullptr));
            }

            Exchange::OCDM_RESULT result = implementation->CreateSession(static_cast<const string&>(_keySystem), _licenseType, static_cast<const string&>(_initDataType), _initData, _initDataLength, _CDMData, _CDMDataLength, _callback, _sessionId, _session);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Exchange::OCDM_RESULT>(result);
            writer.Text(_sessionId);
            writer.Number<Core::instance_id>(RPC::instance_cast(_session));

            if (_callbackProxy__ != nullptr) {
                RPC::Administrator::Instance().Release(_callbackProxy__, message->Response());
            }

            RPC::Administrator::Instance().RegisterInterface(channel, _session);
        },

        // (4) virtual Exchange::OCDM_RESULT SetServerCertificate(const string&, const uint8_t*, const uint16_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IAccessorOCDM* implementation = reinterpret_cast<Exchange::IAccessorOCDM*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _keySystem = reader.Text();
            const uint8_t* _serverCertificate{};
            const uint16_t _serverCertificateLength = reader.LockBuffer<uint16_t>(_serverCertificate);
            reader.UnlockBuffer(_serverCertificateLength);

            Exchange::OCDM_RESULT result = implementation->SetServerCertificate(static_cast<const string&>(_keySystem), _serverCertificate, _serverCertificateLength);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Exchange::OCDM_RESULT>(result);
        },

        // (5) virtual uint64_t GetDrmSystemTime(const string&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IAccessorOCDM* implementation = reinterpret_cast<const Exchange::IAccessorOCDM*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _keySystem = reader.Text();

            uint64_t result = implementation->GetDrmSystemTime(static_cast<const string&>(_keySystem));

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint64_t>(result);
        },

        // (6) virtual string GetVersionExt(const string&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IAccessorOCDM* implementation = reinterpret_cast<const Exchange::IAccessorOCDM*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _keySystem = reader.Text();

            string result = implementation->GetVersionExt(static_cast<const string&>(_keySystem));

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Text(result);
        },

        // (7) virtual uint32_t GetLdlSessionLimit(const string&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IAccessorOCDM* implementation = reinterpret_cast<const Exchange::IAccessorOCDM*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _keySystem = reader.Text();

            uint32_t result = implementation->GetLdlSessionLimit(static_cast<const string&>(_keySystem));

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (8) virtual bool IsSecureStopEnabled(const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IAccessorOCDM* implementation = reinterpret_cast<Exchange::IAccessorOCDM*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _keySystem = reader.Text();

            bool result = implementation->IsSecureStopEnabled(static_cast<const string&>(_keySystem));

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Boolean(result);
        },

        // (9) virtual Exchange::OCDM_RESULT EnableSecureStop(const string&, bool) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IAccessorOCDM* implementation = reinterpret_cast<Exchange::IAccessorOCDM*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _keySystem = reader.Text();
            bool _enable = reader.Boolean();

            Exchange::OCDM_RESULT result = implementation->EnableSecureStop(static_cast<const string&>(_keySystem), _enable);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Exchange::OCDM_RESULT>(result);
        },

        // (10) virtual uint32_t ResetSecureStops(const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IAccessorOCDM* implementation = reinterpret_cast<Exchange::IAccessorOCDM*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _keySystem = reader.Text();

            uint32_t result = implementation->ResetSecureStops(static_cast<const string&>(_keySystem));

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (11) virtual Exchange::OCDM_RESULT GetSecureStopIds(const string&, uint8_t*, uint16_t, uint32_t&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IAccessorOCDM* implementation = reinterpret_cast<Exchange::IAccessorOCDM*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _keySystem = reader.Text();
            uint16_t _idsLength = reader.Number<uint16_t>();
            uint32_t _count = reader.Number<uint32_t>();

            uint8_t* _ids{};

            if (_idsLength != 0) {
                _ids = static_cast<uint8_t*>(ALLOCA(_idsLength * sizeof(uint8_t)));
                ASSERT(_ids != nullptr);
            }

            Exchange::OCDM_RESULT result = implementation->GetSecureStopIds(static_cast<const string&>(_keySystem), _ids, _idsLength, _count);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Exchange::OCDM_RESULT>(result);
            writer.Buffer<uint16_t>(_idsLength, _ids);
            writer.Number<uint32_t>(_count);
        },

        // (12) virtual Exchange::OCDM_RESULT GetSecureStop(const string&, const uint8_t*, uint16_t, uint8_t*, uint16_t&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IAccessorOCDM* implementation = reinterpret_cast<Exchange::IAccessorOCDM*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _keySystem = reader.Text();
            const uint8_t* _sessionID{};
            uint16_t _sessionIDLength = reader.LockBuffer<uint16_t>(_sessionID);
            reader.UnlockBuffer(_sessionIDLength);
            uint16_t _rawSize = reader.Number<uint16_t>();

            uint8_t* _rawData{};

            if (_rawSize != 0) {
                _rawData = static_cast<uint8_t*>(ALLOCA(_rawSize * sizeof(uint8_t)));
                ASSERT(_rawData != nullptr);
            }

            Exchange::OCDM_RESULT result = implementation->GetSecureStop(static_cast<const string&>(_keySystem), _sessionID, _sessionIDLength, _rawData, _rawSize);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Exchange::OCDM_RESULT>(result);
            writer.Buffer<uint16_t>((_rawData == nullptr? 0 : _rawSize), _rawData);
            writer.Number<uint16_t>(_rawSize);
        },

        // (13) virtual Exchange::OCDM_RESULT CommitSecureStop(const string&, const uint8_t*, uint16_t, const uint8_t*, uint16_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IAccessorOCDM* implementation = reinterpret_cast<Exchange::IAccessorOCDM*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _keySystem = reader.Text();
            const uint8_t* _sessionID{};
            uint16_t _sessionIDLength = reader.LockBuffer<uint16_t>(_sessionID);
            reader.UnlockBuffer(_sessionIDLength);
            const uint8_t* _serverResponse{};
            uint16_t _serverResponseLength = reader.LockBuffer<uint16_t>(_serverResponse);
            reader.UnlockBuffer(_serverResponseLength);

            Exchange::OCDM_RESULT result = implementation->CommitSecureStop(static_cast<const string&>(_keySystem), _sessionID, _sessionIDLength, _serverResponse, _serverResponseLength);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Exchange::OCDM_RESULT>(result);
        },

        // (14) virtual Exchange::OCDM_RESULT DeleteKeyStore(const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IAccessorOCDM* implementation = reinterpret_cast<Exchange::IAccessorOCDM*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _keySystem = reader.Text();

            Exchange::OCDM_RESULT result = implementation->DeleteKeyStore(static_cast<const string&>(_keySystem));

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Exchange::OCDM_RESULT>(result);
        },

        // (15) virtual Exchange::OCDM_RESULT DeleteSecureStore(const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IAccessorOCDM* implementation = reinterpret_cast<Exchange::IAccessorOCDM*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _keySystem = reader.Text();

            Exchange::OCDM_RESULT result = implementation->DeleteSecureStore(static_cast<const string&>(_keySystem));

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Exchange::OCDM_RESULT>(result);
        },

        // (16) virtual Exchange::OCDM_RESULT GetKeyStoreHash(const string&, uint8_t*, uint16_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IAccessorOCDM* implementation = reinterpret_cast<Exchange::IAccessorOCDM*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _keySystem = reader.Text();
            uint16_t _keyStoreHashLength = reader.Number<uint16_t>();

            uint8_t* _keyStoreHash{};

            if (_keyStoreHashLength != 0) {
                _keyStoreHash = static_cast<uint8_t*>(ALLOCA(_keyStoreHashLength * sizeof(uint8_t)));
                ASSERT(_keyStoreHash != nullptr);
            }

            Exchange::OCDM_RESULT result = implementation->GetKeyStoreHash(static_cast<const string&>(_keySystem), _keyStoreHash, _keyStoreHashLength);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Exchange::OCDM_RESULT>(result);
            writer.Buffer<uint16_t>(_keyStoreHashLength, _keyStoreHash);
        },

        // (17) virtual Exchange::OCDM_RESULT GetSecureStoreHash(const string&, uint8_t*, uint16_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IAccessorOCDM* implementation = reinterpret_cast<Exchange::IAccessorOCDM*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _keySystem = reader.Text();
            uint16_t _secureStoreHashLength = reader.Number<uint16_t>();

            uint8_t* _secureStoreHash{};

            if (_secureStoreHashLength != 0) {
                _secureStoreHash = static_cast<uint8_t*>(ALLOCA(_secureStoreHashLength * sizeof(uint8_t)));
                ASSERT(_secureStoreHash != nullptr);
            }

            Exchange::OCDM_RESULT result = implementation->GetSecureStoreHash(static_cast<const string&>(_keySystem), _secureStoreHash, _secureStoreHashLength);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Exchange::OCDM_RESULT>(result);
            writer.Buffer<uint16_t>(_secureStoreHashLength, _secureStoreHash);
        }
        , nullptr
    }; // ExchangeAccessorOCDMStubMethods

    // -----------------------------------------------------------------
    // PROXIES
    // -----------------------------------------------------------------

    //
    // RPC::IIteratorTypeInstance_b3acff3685df4032 interface proxy definitions
    //
    // Methods:
    //  (0) virtual bool Next(string&) = 0
    //  (1) virtual bool Previous(string&) = 0
    //  (2) virtual void Reset(const uint32_t) = 0
    //  (3) virtual bool IsValid() const = 0
    //  (4) virtual uint32_t Count() const = 0
    //  (5) virtual string Current() const = 0
    //

    class RPCIteratorTypeInstance_b3acff3685df4032Proxy final : public ProxyStub::UnknownProxyType<RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>> {
    public:
        RPCIteratorTypeInstance_b3acff3685df4032Proxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        bool Next(string& _info) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            bool result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Boolean();
                _info = reader.Text();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        bool Previous(string& _info) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            bool result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Boolean();
                _info = reader.Text();
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

        string Current() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(5));

            string result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Text();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

    }; // class RPCIteratorTypeInstance_b3acff3685df4032Proxy

    //
    // Exchange::IOpenCDM interface proxy definitions
    //
    // Methods:
    //  (0) virtual Core::hresult Systems(Exchange::IOpenCDM::IStringIterator*&) const = 0
    //  (1) virtual Core::hresult Designators(const string&, Exchange::IOpenCDM::IStringIterator*&) const = 0
    //

    class ExchangeOpenCDMProxy final : public ProxyStub::UnknownProxyType<Exchange::IOpenCDM> {
    public:
        ExchangeOpenCDMProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        Core::hresult Systems(Exchange::IOpenCDM::IStringIterator*& _keySystems) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
                _keySystems = reinterpret_cast<Exchange::IOpenCDM::IStringIterator*>(static_cast<const ProxyStub::UnknownProxy&>(*this).Interface(reader.Number<Core::instance_id>(), Exchange::IOpenCDM::IStringIterator::ID));
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        Core::hresult Designators(const string& _keySystem, Exchange::IOpenCDM::IStringIterator*& _designators) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_keySystem);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
                _designators = reinterpret_cast<Exchange::IOpenCDM::IStringIterator*>(static_cast<const ProxyStub::UnknownProxy&>(*this).Interface(reader.Number<Core::instance_id>(), Exchange::IOpenCDM::IStringIterator::ID));
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

    }; // class ExchangeOpenCDMProxy

    //
    // Exchange::ISession interface proxy definitions
    //
    // Methods:
    //  (0) virtual Exchange::OCDM_RESULT Load() = 0
    //  (1) virtual void Update(const uint8_t*, const uint16_t) = 0
    //  (2) virtual Exchange::OCDM_RESULT Remove() = 0
    //  (3) virtual string Metadata() const = 0
    //  (4) virtual Exchange::OCDM_RESULT Metricdata(uint32_t&, uint8_t*) const = 0
    //  (5) virtual Exchange::ISession::KeyStatus Status() const = 0
    //  (6) virtual Exchange::ISession::KeyStatus Status(const uint8_t*, const uint8_t) const = 0
    //  (7) virtual Exchange::OCDM_RESULT CreateSessionBuffer(string&) = 0
    //  (8) virtual string BufferId() const = 0
    //  (9) virtual string SessionId() const = 0
    //  (10) virtual void Close() = 0
    //  (11) virtual void ResetOutputProtection() = 0
    //  (12) virtual void Revoke(Exchange::ISession::ICallback*) = 0
    //  (13) virtual Exchange::OCDM_RESULT SetParameter(const string&, const string&)
    //

    class ExchangeSessionProxy final : public ProxyStub::UnknownProxyType<Exchange::ISession> {
    public:
        ExchangeSessionProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        Exchange::OCDM_RESULT Load() override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            Exchange::OCDM_RESULT result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Number<Exchange::OCDM_RESULT>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        void Update(const uint8_t* _keyMessage, const uint16_t _keyLength) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Buffer<uint16_t>(_keyLength, _keyMessage);

            static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
        }

        Exchange::OCDM_RESULT Remove() override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(2));

            Exchange::OCDM_RESULT result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Number<Exchange::OCDM_RESULT>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        string Metadata() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(3));

            string result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Text();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        Exchange::OCDM_RESULT Metricdata(uint32_t& _bufferSize, uint8_t* _buffer) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(4));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_bufferSize);

            Exchange::OCDM_RESULT result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Number<Exchange::OCDM_RESULT>();
                reader.Buffer<uint32_t>(_bufferSize, _buffer);
                _bufferSize = reader.Number<uint32_t>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        Exchange::ISession::KeyStatus Status() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(5));

            Exchange::ISession::KeyStatus result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Number<Exchange::ISession::KeyStatus>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        Exchange::ISession::KeyStatus Status(const uint8_t* _keyID, const uint8_t _keyIDLength) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(6));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Buffer<uint8_t>(_keyIDLength, _keyID);

            Exchange::ISession::KeyStatus result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Number<Exchange::ISession::KeyStatus>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        Exchange::OCDM_RESULT CreateSessionBuffer(string& _bufferID) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(7));

            Exchange::OCDM_RESULT result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Number<Exchange::OCDM_RESULT>();
                _bufferID = reader.Text();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        string BufferId() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(8));

            string result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Text();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        string SessionId() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(9));

            string result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Text();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        void Close() override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(10));

            static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
        }

        void ResetOutputProtection() override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(11));

            static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
        }

        void Revoke(Exchange::ISession::ICallback* _callback) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(12));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_callback));

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());

                _Complete(reader);
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }
        }

        Exchange::OCDM_RESULT SetParameter(const string& _parameter_1, const string& _parameter_2) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(13));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_parameter_1);
            writer.Text(_parameter_2);

            Exchange::OCDM_RESULT result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Number<Exchange::OCDM_RESULT>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
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

    }; // class ExchangeSessionProxy

    //
    // Exchange::ISession::ICallback interface proxy definitions
    //
    // Methods:
    //  (0) virtual void OnKeyMessage(const uint8_t*, const uint16_t, const string&) = 0
    //  (1) virtual void OnError(const int16_t, const Exchange::OCDM_RESULT, const string&) = 0
    //  (2) virtual void OnKeyStatusUpdate(const uint8_t*, const uint8_t, const Exchange::ISession::KeyStatus) = 0
    //  (3) virtual void OnKeyStatusesUpdated() const = 0
    //

    class ExchangeSessionCallbackProxy final : public ProxyStub::UnknownProxyType<Exchange::ISession::ICallback> {
    public:
        ExchangeSessionCallbackProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        void OnKeyMessage(const uint8_t* _keyMessage, const uint16_t _keyLength, const string& _URL) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Buffer<uint16_t>(_keyLength, _keyMessage);
            writer.Text(_URL);

            static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
        }

        void OnError(const int16_t _error, const Exchange::OCDM_RESULT _sysError, const string& _errorMessage) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<int16_t>(_error);
            writer.Number<Exchange::OCDM_RESULT>(_sysError);
            writer.Text(_errorMessage);

            static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
        }

        void OnKeyStatusUpdate(const uint8_t* _keyID, const uint8_t _keyIDLength, const Exchange::ISession::KeyStatus _status) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(2));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Buffer<uint8_t>(_keyIDLength, _keyID);
            writer.Number<Exchange::ISession::KeyStatus>(_status);

            static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
        }

        void OnKeyStatusesUpdated() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(3));

            static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
        }

    }; // class ExchangeSessionCallbackProxy

    //
    // Exchange::ISessionExt interface proxy definitions
    //
    // Methods:
    //  (0) virtual uint32_t SessionIdExt() const = 0
    //  (1) virtual string BufferIdExt() const = 0
    //  (2) virtual Exchange::OCDM_RESULT SetDrmHeader(const uint8_t*, uint16_t) = 0
    //  (3) virtual Exchange::OCDM_RESULT GetChallengeDataExt(uint8_t*, uint16_t&, uint32_t) = 0
    //  (4) virtual Exchange::OCDM_RESULT CancelChallengeDataExt() = 0
    //  (5) virtual Exchange::OCDM_RESULT StoreLicenseData(const uint8_t*, uint16_t, uint8_t*) = 0
    //  (6) virtual Exchange::OCDM_RESULT SelectKeyId(const uint8_t, const uint8_t*) = 0
    //  (7) virtual Exchange::OCDM_RESULT CleanDecryptContext() = 0
    //

    class ExchangeSessionExtProxy final : public ProxyStub::UnknownProxyType<Exchange::ISessionExt> {
    public:
        ExchangeSessionExtProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        uint32_t SessionIdExt() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

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

        string BufferIdExt() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            string result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Text();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        Exchange::OCDM_RESULT SetDrmHeader(const uint8_t* _drmHeader, uint16_t _drmHeaderLength) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(2));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Buffer<uint16_t>(_drmHeaderLength, _drmHeader);

            Exchange::OCDM_RESULT result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Number<Exchange::OCDM_RESULT>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        Exchange::OCDM_RESULT GetChallengeDataExt(uint8_t* _challenge, uint16_t& _challengeSize, uint32_t _isLDL) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(3));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint16_t>(_challengeSize);
            writer.Number<uint32_t>(_isLDL);

            Exchange::OCDM_RESULT result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Number<Exchange::OCDM_RESULT>();
                reader.Buffer<uint16_t>(_challengeSize, _challenge);
                _challengeSize = reader.Number<uint16_t>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        Exchange::OCDM_RESULT CancelChallengeDataExt() override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(4));

            Exchange::OCDM_RESULT result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Number<Exchange::OCDM_RESULT>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        Exchange::OCDM_RESULT StoreLicenseData(const uint8_t* _licenseData, uint16_t _licenseDataSize, uint8_t* _secureStopId) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(5));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Buffer<uint16_t>(_licenseDataSize, _licenseData);

            Exchange::OCDM_RESULT result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Number<Exchange::OCDM_RESULT>();
                reader.Buffer<uint8_t>(16, _secureStopId);
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        Exchange::OCDM_RESULT SelectKeyId(const uint8_t _keyLength, const uint8_t* _keyId) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(6));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Buffer<uint8_t>(_keyLength, _keyId);

            Exchange::OCDM_RESULT result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Number<Exchange::OCDM_RESULT>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        Exchange::OCDM_RESULT CleanDecryptContext() override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(7));

            Exchange::OCDM_RESULT result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Number<Exchange::OCDM_RESULT>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

    }; // class ExchangeSessionExtProxy

    //
    // Exchange::IAccessorOCDM interface proxy definitions
    //
    // Methods:
    //  (0) virtual bool IsTypeSupported(const string&, const string&) const = 0
    //  (1) virtual Exchange::OCDM_RESULT Metadata(const string&, string&) const = 0
    //  (2) virtual Exchange::OCDM_RESULT Metricdata(const string&, uint32_t&, uint8_t*) const = 0
    //  (3) virtual Exchange::OCDM_RESULT CreateSession(const string&, const int32_t, const string&, const uint8_t*, const uint16_t, const uint8_t*, const uint16_t, Exchange::ISession::ICallback*, string&, Exchange::ISession*&) = 0
    //  (4) virtual Exchange::OCDM_RESULT SetServerCertificate(const string&, const uint8_t*, const uint16_t) = 0
    //  (5) virtual uint64_t GetDrmSystemTime(const string&) const = 0
    //  (6) virtual string GetVersionExt(const string&) const = 0
    //  (7) virtual uint32_t GetLdlSessionLimit(const string&) const = 0
    //  (8) virtual bool IsSecureStopEnabled(const string&) = 0
    //  (9) virtual Exchange::OCDM_RESULT EnableSecureStop(const string&, bool) = 0
    //  (10) virtual uint32_t ResetSecureStops(const string&) = 0
    //  (11) virtual Exchange::OCDM_RESULT GetSecureStopIds(const string&, uint8_t*, uint16_t, uint32_t&) = 0
    //  (12) virtual Exchange::OCDM_RESULT GetSecureStop(const string&, const uint8_t*, uint16_t, uint8_t*, uint16_t&) = 0
    //  (13) virtual Exchange::OCDM_RESULT CommitSecureStop(const string&, const uint8_t*, uint16_t, const uint8_t*, uint16_t) = 0
    //  (14) virtual Exchange::OCDM_RESULT DeleteKeyStore(const string&) = 0
    //  (15) virtual Exchange::OCDM_RESULT DeleteSecureStore(const string&) = 0
    //  (16) virtual Exchange::OCDM_RESULT GetKeyStoreHash(const string&, uint8_t*, uint16_t) = 0
    //  (17) virtual Exchange::OCDM_RESULT GetSecureStoreHash(const string&, uint8_t*, uint16_t) = 0
    //

    class ExchangeAccessorOCDMProxy final : public ProxyStub::UnknownProxyType<Exchange::IAccessorOCDM> {
    public:
        ExchangeAccessorOCDMProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        bool IsTypeSupported(const string& _keySystem, const string& _mimeType) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_keySystem);
            writer.Text(_mimeType);

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

        Exchange::OCDM_RESULT Metadata(const string& _keySystem, string& _metadata) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_keySystem);

            Exchange::OCDM_RESULT result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Number<Exchange::OCDM_RESULT>();
                _metadata = reader.Text();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        Exchange::OCDM_RESULT Metricdata(const string& _keySystem, uint32_t& _bufferSize, uint8_t* _buffer) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(2));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_keySystem);
            writer.Number<uint32_t>(_bufferSize);

            Exchange::OCDM_RESULT result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Number<Exchange::OCDM_RESULT>();
                reader.Buffer<uint32_t>(_bufferSize, _buffer);
                _bufferSize = reader.Number<uint32_t>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        Exchange::OCDM_RESULT CreateSession(const string& _keySystem, const int32_t _licenseType, const string& _initDataType, const uint8_t* _initData, const uint16_t _initDataLength, const uint8_t* _CDMData, const uint16_t _CDMDataLength, Exchange::ISession::ICallback* _callback, string& _sessionId, Exchange::ISession*& _session) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(3));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_keySystem);
            writer.Number<int32_t>(_licenseType);
            writer.Text(_initDataType);
            writer.Buffer<uint16_t>(_initDataLength, _initData);
            writer.Buffer<uint16_t>(_CDMDataLength, _CDMData);
            writer.Number<Core::instance_id>(RPC::instance_cast(_callback));

            Exchange::OCDM_RESULT result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Number<Exchange::OCDM_RESULT>();
                _sessionId = reader.Text();
                _session = reinterpret_cast<Exchange::ISession*>(static_cast<const ProxyStub::UnknownProxy&>(*this).Interface(reader.Number<Core::instance_id>(), Exchange::ISession::ID));

                _Complete(reader);
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        Exchange::OCDM_RESULT SetServerCertificate(const string& _keySystem, const uint8_t* _serverCertificate, const uint16_t _serverCertificateLength) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(4));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_keySystem);
            writer.Buffer<uint16_t>(_serverCertificateLength, _serverCertificate);

            Exchange::OCDM_RESULT result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Number<Exchange::OCDM_RESULT>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        uint64_t GetDrmSystemTime(const string& _keySystem) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(5));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_keySystem);

            uint64_t result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Number<uint64_t>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        string GetVersionExt(const string& _keySystem) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(6));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_keySystem);

            string result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Text();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        uint32_t GetLdlSessionLimit(const string& _keySystem) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(7));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_keySystem);

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

        bool IsSecureStopEnabled(const string& _keySystem) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(8));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_keySystem);

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

        Exchange::OCDM_RESULT EnableSecureStop(const string& _keySystem, bool _enable) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(9));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_keySystem);
            writer.Boolean(_enable);

            Exchange::OCDM_RESULT result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Number<Exchange::OCDM_RESULT>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        uint32_t ResetSecureStops(const string& _keySystem) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(10));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_keySystem);

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

        Exchange::OCDM_RESULT GetSecureStopIds(const string& _keySystem, uint8_t* _ids, uint16_t _idsLength, uint32_t& _count) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(11));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_keySystem);
            writer.Number<uint16_t>(_idsLength);
            writer.Number<uint32_t>(_count);

            Exchange::OCDM_RESULT result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Number<Exchange::OCDM_RESULT>();
                reader.Buffer<uint16_t>(_idsLength, _ids);
                _count = reader.Number<uint32_t>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        Exchange::OCDM_RESULT GetSecureStop(const string& _keySystem, const uint8_t* _sessionID, uint16_t _sessionIDLength, uint8_t* _rawData, uint16_t& _rawSize) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(12));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_keySystem);
            writer.Buffer<uint16_t>(_sessionIDLength, _sessionID);
            writer.Number<uint16_t>(_rawSize);

            Exchange::OCDM_RESULT result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Number<Exchange::OCDM_RESULT>();
                reader.Buffer<uint16_t>(_rawSize, _rawData);
                _rawSize = reader.Number<uint16_t>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        Exchange::OCDM_RESULT CommitSecureStop(const string& _keySystem, const uint8_t* _sessionID, uint16_t _sessionIDLength, const uint8_t* _serverResponse, uint16_t _serverResponseLength) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(13));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_keySystem);
            writer.Buffer<uint16_t>(_sessionIDLength, _sessionID);
            writer.Buffer<uint16_t>(_serverResponseLength, _serverResponse);

            Exchange::OCDM_RESULT result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Number<Exchange::OCDM_RESULT>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        Exchange::OCDM_RESULT DeleteKeyStore(const string& _keySystem) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(14));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_keySystem);

            Exchange::OCDM_RESULT result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Number<Exchange::OCDM_RESULT>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        Exchange::OCDM_RESULT DeleteSecureStore(const string& _keySystem) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(15));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_keySystem);

            Exchange::OCDM_RESULT result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Number<Exchange::OCDM_RESULT>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        Exchange::OCDM_RESULT GetKeyStoreHash(const string& _keySystem, uint8_t* _keyStoreHash, uint16_t _keyStoreHashLength) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(16));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_keySystem);
            writer.Number<uint16_t>(_keyStoreHashLength);

            Exchange::OCDM_RESULT result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Number<Exchange::OCDM_RESULT>();
                reader.Buffer<uint16_t>(_keyStoreHashLength, _keyStoreHash);
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        Exchange::OCDM_RESULT GetSecureStoreHash(const string& _keySystem, uint8_t* _secureStoreHash, uint16_t _secureStoreHashLength) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(17));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_keySystem);
            writer.Number<uint16_t>(_secureStoreHashLength);

            Exchange::OCDM_RESULT result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Number<Exchange::OCDM_RESULT>();
                reader.Buffer<uint16_t>(_secureStoreHashLength, _secureStoreHash);
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
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

    }; // class ExchangeAccessorOCDMProxy

    POP_WARNING()
    POP_WARNING()

    // -----------------------------------------------------------------
    // REGISTRATION
    // -----------------------------------------------------------------
    namespace {

        typedef ProxyStub::UnknownStubType<RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>, RPCIteratorTypeInstance_b3acff3685df4032StubMethods> RPCIteratorTypeInstance_b3acff3685df4032Stub;
        typedef ProxyStub::UnknownStubType<Exchange::IOpenCDM, ExchangeOpenCDMStubMethods> ExchangeOpenCDMStub;
        typedef ProxyStub::UnknownStubType<Exchange::ISession, ExchangeSessionStubMethods> ExchangeSessionStub;
        typedef ProxyStub::UnknownStubType<Exchange::ISession::ICallback, ExchangeSessionCallbackStubMethods> ExchangeSessionCallbackStub;
        typedef ProxyStub::UnknownStubType<Exchange::ISessionExt, ExchangeSessionExtStubMethods> ExchangeSessionExtStub;
        typedef ProxyStub::UnknownStubType<Exchange::IAccessorOCDM, ExchangeAccessorOCDMStubMethods> ExchangeAccessorOCDMStub;

        static class Instantiation {
        public:
            Instantiation()
            {
                RPC::Administrator::Instance().Announce<RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>, RPCIteratorTypeInstance_b3acff3685df4032Proxy, RPCIteratorTypeInstance_b3acff3685df4032Stub>();
                RPC::Administrator::Instance().Announce<Exchange::IOpenCDM, ExchangeOpenCDMProxy, ExchangeOpenCDMStub>();
                RPC::Administrator::Instance().Announce<Exchange::ISession, ExchangeSessionProxy, ExchangeSessionStub>();
                RPC::Administrator::Instance().Announce<Exchange::ISession::ICallback, ExchangeSessionCallbackProxy, ExchangeSessionCallbackStub>();
                RPC::Administrator::Instance().Announce<Exchange::ISessionExt, ExchangeSessionExtProxy, ExchangeSessionExtStub>();
                RPC::Administrator::Instance().Announce<Exchange::IAccessorOCDM, ExchangeAccessorOCDMProxy, ExchangeAccessorOCDMStub>();
            }
            ~Instantiation()
            {
                RPC::Administrator::Instance().Recall<RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>>();
                RPC::Administrator::Instance().Recall<Exchange::IOpenCDM>();
                RPC::Administrator::Instance().Recall<Exchange::ISession>();
                RPC::Administrator::Instance().Recall<Exchange::ISession::ICallback>();
                RPC::Administrator::Instance().Recall<Exchange::ISessionExt>();
                RPC::Administrator::Instance().Recall<Exchange::IAccessorOCDM>();
            }
        } ProxyStubRegistration;

    } // namespace

} // namespace ProxyStubs

}
