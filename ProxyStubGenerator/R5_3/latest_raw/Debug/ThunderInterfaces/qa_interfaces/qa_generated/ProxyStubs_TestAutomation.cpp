//
// generated automatically from "ITestAutomation.h"
//
// implements COM-RPC proxy stubs for:
//   - class IMemory
//   - class IComRpc
//   - class IComRpc::IComRpcInternal
//   - class ITestTextOptions
//   - class ITestTextOptions::INotification
//   - class ITestTextOptions::ITestLegacy
//   - class ITestTextOptions::ITestLegacy::INotification
//   - class ITestTextOptions::ITestKeep
//   - class ITestTextOptions::ITestKeep::INotification
//   - class ITestTextOptions::ITestCustom
//   - class ITestTextOptions::ITestCustom::INotification
//   - class ITestUtils
//

#include "Module.h"
#include "ITestAutomation.h"

#include <com/com.h>

namespace Thunder {

namespace ProxyStubs {

    using namespace QualityAssurance;

    PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    // -----------------------------------------------------------------
    // STUBS
    // -----------------------------------------------------------------

    //
    // IMemory interface stub definitions
    //
    // Methods:
    //  (0) virtual Core::hresult AllocateMemory(const uint32_t) = 0
    //  (1) virtual Core::hresult FreeAllocatedMemory() = 0
    //

    static ProxyStub::MethodHandler MemoryStubMethods[] = {
        // (0) virtual Core::hresult AllocateMemory(const uint32_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            IMemory* implementation = reinterpret_cast<IMemory*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint32_t _size = reader.Number<uint32_t>();

            Core::hresult result = implementation->AllocateMemory(_size);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
        },

        // (1) virtual Core::hresult FreeAllocatedMemory() = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            IMemory* implementation = reinterpret_cast<IMemory*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Core::hresult result = implementation->FreeAllocatedMemory();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
        }
        , nullptr
    }; // MemoryStubMethods

    //
    // IComRpc interface stub definitions
    //
    // Methods:
    //  (0) virtual Core::hresult TestBigString(const uint32_t) = 0
    //

    static ProxyStub::MethodHandler ComRpcStubMethods[] = {
        // (0) virtual Core::hresult TestBigString(const uint32_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            IComRpc* implementation = reinterpret_cast<IComRpc*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint32_t _length = reader.Number<uint32_t>();

            Core::hresult result = implementation->TestBigString(_length);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
        }
        , nullptr
    }; // ComRpcStubMethods

    //
    // IComRpc::IComRpcInternal interface stub definitions
    //
    // Methods:
    //  (0) virtual Core::hresult BigStringTest(const string&) = 0
    //

    static ProxyStub::MethodHandler ComRpcComRpcInternalStubMethods[] = {
        // (0) virtual Core::hresult BigStringTest(const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            IComRpc::IComRpcInternal* implementation = reinterpret_cast<IComRpc::IComRpcInternal*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            ASSERT((reader.PeekNumber<Core::UInt24>() >= 0) && (reader.PeekNumber<Core::UInt24>() <= 4194303));
            const string _testString = reader.Text<Core::UInt24>();

            Core::hresult result = implementation->BigStringTest(static_cast<const string&>(_testString));

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
        }
        , nullptr
    }; // ComRpcComRpcInternalStubMethods

    //
    // ITestTextOptions interface stub definitions
    //
    // Methods:
    //  (0) virtual Core::hresult TestStandard(const uint32_t, const uint32_t, const ITestTextOptions::TestDetails&, const ITestTextOptions::EnumTextOptions) = 0
    //

    static ProxyStub::MethodHandler TestTextOptionsStubMethods[] = {
        // (0) virtual Core::hresult TestStandard(const uint32_t, const uint32_t, const ITestTextOptions::TestDetails&, const ITestTextOptions::EnumTextOptions) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            ITestTextOptions* implementation = reinterpret_cast<ITestTextOptions*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint32_t _firstTestParam = reader.Number<uint32_t>();
            const uint32_t _secondTestParam = reader.Number<uint32_t>();
            ITestTextOptions::TestDetails _thirdTestParam{};
            _thirdTestParam.testDetailsFirst = reader.Text();
            _thirdTestParam.testDetailsSecond = reader.Text();
            const ITestTextOptions::EnumTextOptions _fourthTestParam = reader.Number<ITestTextOptions::EnumTextOptions>();

            Core::hresult result = implementation->TestStandard(_firstTestParam, _secondTestParam, static_cast<const ITestTextOptions::TestDetails&>(_thirdTestParam), _fourthTestParam);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
        }
        , nullptr
    }; // TestTextOptionsStubMethods

    //
    // ITestTextOptions::INotification interface stub definitions
    //
    // Methods:
    //  (0) virtual void TestEvent(const uint32_t, const uint32_t, const ITestTextOptions::TestDetails&, const ITestTextOptions::EnumTextOptions) = 0
    //

    static ProxyStub::MethodHandler TestTextOptionsNotificationStubMethods[] = {
        // (0) virtual void TestEvent(const uint32_t, const uint32_t, const ITestTextOptions::TestDetails&, const ITestTextOptions::EnumTextOptions) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            ITestTextOptions::INotification* implementation = reinterpret_cast<ITestTextOptions::INotification*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint32_t _firstTestParam = reader.Number<uint32_t>();
            const uint32_t _secondTestParam = reader.Number<uint32_t>();
            ITestTextOptions::TestDetails _thirdTestParam{};
            _thirdTestParam.testDetailsFirst = reader.Text();
            _thirdTestParam.testDetailsSecond = reader.Text();
            const ITestTextOptions::EnumTextOptions _fourthTestParam = reader.Number<ITestTextOptions::EnumTextOptions>();

            implementation->TestEvent(_firstTestParam, _secondTestParam, static_cast<const ITestTextOptions::TestDetails&>(_thirdTestParam), _fourthTestParam);
        }
        , nullptr
    }; // TestTextOptionsNotificationStubMethods

    //
    // ITestTextOptions::ITestLegacy interface stub definitions
    //
    // Methods:
    //  (0) virtual Core::hresult TestLegacy(const uint32_t, const uint32_t, const ITestTextOptions::ITestLegacy::TestDetails&, const ITestTextOptions::ITestLegacy::EnumTextOptions) = 0
    //

    static ProxyStub::MethodHandler TestTextOptionsTestLegacyStubMethods[] = {
        // (0) virtual Core::hresult TestLegacy(const uint32_t, const uint32_t, const ITestTextOptions::ITestLegacy::TestDetails&, const ITestTextOptions::ITestLegacy::EnumTextOptions) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            ITestTextOptions::ITestLegacy* implementation = reinterpret_cast<ITestTextOptions::ITestLegacy*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint32_t _firstTestParam = reader.Number<uint32_t>();
            const uint32_t _secondTestParam = reader.Number<uint32_t>();
            ITestTextOptions::ITestLegacy::TestDetails _thirdTestParam{};
            _thirdTestParam.testDetailsFirst = reader.Text();
            _thirdTestParam.testDetailsSecond = reader.Text();
            const ITestTextOptions::ITestLegacy::EnumTextOptions _fourthTestParam = reader.Number<ITestTextOptions::ITestLegacy::EnumTextOptions>();

            Core::hresult result = implementation->TestLegacy(_firstTestParam, _secondTestParam, static_cast<const ITestTextOptions::ITestLegacy::TestDetails&>(_thirdTestParam), _fourthTestParam);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
        }
        , nullptr
    }; // TestTextOptionsTestLegacyStubMethods

    //
    // ITestTextOptions::ITestLegacy::INotification interface stub definitions
    //
    // Methods:
    //  (0) virtual void TestEvent(const uint32_t, const uint32_t, const ITestTextOptions::ITestLegacy::TestDetails&, const ITestTextOptions::ITestLegacy::EnumTextOptions) = 0
    //

    static ProxyStub::MethodHandler TestTextOptionsTestLegacyNotificationStubMethods[] = {
        // (0) virtual void TestEvent(const uint32_t, const uint32_t, const ITestTextOptions::ITestLegacy::TestDetails&, const ITestTextOptions::ITestLegacy::EnumTextOptions) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            ITestTextOptions::ITestLegacy::INotification* implementation = reinterpret_cast<ITestTextOptions::ITestLegacy::INotification*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint32_t _firstTestParam = reader.Number<uint32_t>();
            const uint32_t _secondTestParam = reader.Number<uint32_t>();
            ITestTextOptions::ITestLegacy::TestDetails _thirdTestParam{};
            _thirdTestParam.testDetailsFirst = reader.Text();
            _thirdTestParam.testDetailsSecond = reader.Text();
            const ITestTextOptions::ITestLegacy::EnumTextOptions _fourthTestParam = reader.Number<ITestTextOptions::ITestLegacy::EnumTextOptions>();

            implementation->TestEvent(_firstTestParam, _secondTestParam, static_cast<const ITestTextOptions::ITestLegacy::TestDetails&>(_thirdTestParam), _fourthTestParam);
        }
        , nullptr
    }; // TestTextOptionsTestLegacyNotificationStubMethods

    //
    // ITestTextOptions::ITestKeep interface stub definitions
    //
    // Methods:
    //  (0) virtual Core::hresult TestKeeP(const uint32_t, const uint32_t, const ITestTextOptions::ITestKeep::TestDetails&, const ITestTextOptions::ITestKeep::EnumTextOptions) = 0
    //

    static ProxyStub::MethodHandler TestTextOptionsTestKeepStubMethods[] = {
        // (0) virtual Core::hresult TestKeeP(const uint32_t, const uint32_t, const ITestTextOptions::ITestKeep::TestDetails&, const ITestTextOptions::ITestKeep::EnumTextOptions) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            ITestTextOptions::ITestKeep* implementation = reinterpret_cast<ITestTextOptions::ITestKeep*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint32_t _firstTestParaM = reader.Number<uint32_t>();
            const uint32_t _secondTestParaM = reader.Number<uint32_t>();
            ITestTextOptions::ITestKeep::TestDetails _thirdTestParaM{};
            _thirdTestParaM.testDetailsFirst = reader.Text();
            _thirdTestParaM.testDetailsSecond = reader.Text();
            const ITestTextOptions::ITestKeep::EnumTextOptions _fourthTestParaM = reader.Number<ITestTextOptions::ITestKeep::EnumTextOptions>();

            Core::hresult result = implementation->TestKeeP(_firstTestParaM, _secondTestParaM, static_cast<const ITestTextOptions::ITestKeep::TestDetails&>(_thirdTestParaM), _fourthTestParaM);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
        }
        , nullptr
    }; // TestTextOptionsTestKeepStubMethods

    //
    // ITestTextOptions::ITestKeep::INotification interface stub definitions
    //
    // Methods:
    //  (0) virtual void TestEvent(const uint32_t, const uint32_t, const ITestTextOptions::ITestKeep::TestDetails&, const ITestTextOptions::ITestKeep::EnumTextOptions) = 0
    //

    static ProxyStub::MethodHandler TestTextOptionsTestKeepNotificationStubMethods[] = {
        // (0) virtual void TestEvent(const uint32_t, const uint32_t, const ITestTextOptions::ITestKeep::TestDetails&, const ITestTextOptions::ITestKeep::EnumTextOptions) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            ITestTextOptions::ITestKeep::INotification* implementation = reinterpret_cast<ITestTextOptions::ITestKeep::INotification*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint32_t _firstTestParam = reader.Number<uint32_t>();
            const uint32_t _secondTestParam = reader.Number<uint32_t>();
            ITestTextOptions::ITestKeep::TestDetails _thirdTestParam{};
            _thirdTestParam.testDetailsFirst = reader.Text();
            _thirdTestParam.testDetailsSecond = reader.Text();
            const ITestTextOptions::ITestKeep::EnumTextOptions _fourthTestParam = reader.Number<ITestTextOptions::ITestKeep::EnumTextOptions>();

            implementation->TestEvent(_firstTestParam, _secondTestParam, static_cast<const ITestTextOptions::ITestKeep::TestDetails&>(_thirdTestParam), _fourthTestParam);
        }
        , nullptr
    }; // TestTextOptionsTestKeepNotificationStubMethods

    //
    // ITestTextOptions::ITestCustom interface stub definitions
    //
    // Methods:
    //  (0) virtual Core::hresult TestCustom(const uint32_t, const uint32_t, const ITestTextOptions::ITestCustom::TestDetails&, const ITestTextOptions::ITestCustom::EnumTextOptions) = 0
    //

    static ProxyStub::MethodHandler TestTextOptionsTestCustomStubMethods[] = {
        // (0) virtual Core::hresult TestCustom(const uint32_t, const uint32_t, const ITestTextOptions::ITestCustom::TestDetails&, const ITestTextOptions::ITestCustom::EnumTextOptions) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            ITestTextOptions::ITestCustom* implementation = reinterpret_cast<ITestTextOptions::ITestCustom*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint32_t _firstTestParam = reader.Number<uint32_t>();
            const uint32_t _secondTestParam = reader.Number<uint32_t>();
            ITestTextOptions::ITestCustom::TestDetails _thirdTestParam{};
            _thirdTestParam.testDetailsFirst = reader.Text();
            _thirdTestParam.testDetailsSecond = reader.Text();
            const ITestTextOptions::ITestCustom::EnumTextOptions _fourthTestParam = reader.Number<ITestTextOptions::ITestCustom::EnumTextOptions>();

            Core::hresult result = implementation->TestCustom(_firstTestParam, _secondTestParam, static_cast<const ITestTextOptions::ITestCustom::TestDetails&>(_thirdTestParam), _fourthTestParam);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
        }
        , nullptr
    }; // TestTextOptionsTestCustomStubMethods

    //
    // ITestTextOptions::ITestCustom::INotification interface stub definitions
    //
    // Methods:
    //  (0) virtual void TestEvent(const uint32_t, const uint32_t, const ITestTextOptions::ITestCustom::TestDetails&, const ITestTextOptions::ITestCustom::EnumTextOptions) = 0
    //

    static ProxyStub::MethodHandler TestTextOptionsTestCustomNotificationStubMethods[] = {
        // (0) virtual void TestEvent(const uint32_t, const uint32_t, const ITestTextOptions::ITestCustom::TestDetails&, const ITestTextOptions::ITestCustom::EnumTextOptions) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            ITestTextOptions::ITestCustom::INotification* implementation = reinterpret_cast<ITestTextOptions::ITestCustom::INotification*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint32_t _firstTestParam = reader.Number<uint32_t>();
            const uint32_t _secondTestParam = reader.Number<uint32_t>();
            ITestTextOptions::ITestCustom::TestDetails _thirdTestParam{};
            _thirdTestParam.testDetailsFirst = reader.Text();
            _thirdTestParam.testDetailsSecond = reader.Text();
            const ITestTextOptions::ITestCustom::EnumTextOptions _fourthTestParam = reader.Number<ITestTextOptions::ITestCustom::EnumTextOptions>();

            implementation->TestEvent(_firstTestParam, _secondTestParam, static_cast<const ITestTextOptions::ITestCustom::TestDetails&>(_thirdTestParam), _fourthTestParam);
        }
        , nullptr
    }; // TestTextOptionsTestCustomNotificationStubMethods

    //
    // ITestUtils interface stub definitions
    //
    // Methods:
    //  (0) virtual Core::hresult Crash() const = 0
    //

    static ProxyStub::MethodHandler TestUtilsStubMethods[] = {
        // (0) virtual Core::hresult Crash() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const ITestUtils* implementation = reinterpret_cast<const ITestUtils*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Core::hresult result = implementation->Crash();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
        }
        , nullptr
    }; // TestUtilsStubMethods

    // -----------------------------------------------------------------
    // PROXIES
    // -----------------------------------------------------------------

    //
    // IMemory interface proxy definitions
    //
    // Methods:
    //  (0) virtual Core::hresult AllocateMemory(const uint32_t) = 0
    //  (1) virtual Core::hresult FreeAllocatedMemory() = 0
    //

    class MemoryProxy final : public ProxyStub::UnknownProxyType<IMemory> {
    public:
        MemoryProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        Core::hresult AllocateMemory(const uint32_t _size) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_size);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        Core::hresult FreeAllocatedMemory() override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

    }; // class MemoryProxy

    //
    // IComRpc interface proxy definitions
    //
    // Methods:
    //  (0) virtual Core::hresult TestBigString(const uint32_t) = 0
    //

    class ComRpcProxy final : public ProxyStub::UnknownProxyType<IComRpc> {
    public:
        ComRpcProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        Core::hresult TestBigString(const uint32_t _length) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_length);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

    }; // class ComRpcProxy

    //
    // IComRpc::IComRpcInternal interface proxy definitions
    //
    // Methods:
    //  (0) virtual Core::hresult BigStringTest(const string&) = 0
    //

    class ComRpcComRpcInternalProxy final : public ProxyStub::UnknownProxyType<IComRpc::IComRpcInternal> {
    public:
        ComRpcComRpcInternalProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        Core::hresult BigStringTest(const string& _testString) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text<Core::UInt24>(_testString);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

    }; // class ComRpcComRpcInternalProxy

    //
    // ITestTextOptions interface proxy definitions
    //
    // Methods:
    //  (0) virtual Core::hresult TestStandard(const uint32_t, const uint32_t, const ITestTextOptions::TestDetails&, const ITestTextOptions::EnumTextOptions) = 0
    //

    class TestTextOptionsProxy final : public ProxyStub::UnknownProxyType<ITestTextOptions> {
    public:
        TestTextOptionsProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        Core::hresult TestStandard(const uint32_t _firstTestParam, const uint32_t _secondTestParam, const ITestTextOptions::TestDetails& _thirdTestParam, const ITestTextOptions::EnumTextOptions _fourthTestParam) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_firstTestParam);
            writer.Number<uint32_t>(_secondTestParam);
            writer.Text(_thirdTestParam.testDetailsFirst);
            writer.Text(_thirdTestParam.testDetailsSecond);
            writer.Number<ITestTextOptions::EnumTextOptions>(_fourthTestParam);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

    }; // class TestTextOptionsProxy

    //
    // ITestTextOptions::INotification interface proxy definitions
    //
    // Methods:
    //  (0) virtual void TestEvent(const uint32_t, const uint32_t, const ITestTextOptions::TestDetails&, const ITestTextOptions::EnumTextOptions) = 0
    //

    class TestTextOptionsNotificationProxy final : public ProxyStub::UnknownProxyType<ITestTextOptions::INotification> {
    public:
        TestTextOptionsNotificationProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        void TestEvent(const uint32_t _firstTestParam, const uint32_t _secondTestParam, const ITestTextOptions::TestDetails& _thirdTestParam, const ITestTextOptions::EnumTextOptions _fourthTestParam) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_firstTestParam);
            writer.Number<uint32_t>(_secondTestParam);
            writer.Text(_thirdTestParam.testDetailsFirst);
            writer.Text(_thirdTestParam.testDetailsSecond);
            writer.Number<ITestTextOptions::EnumTextOptions>(_fourthTestParam);

            static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
        }

    }; // class TestTextOptionsNotificationProxy

    //
    // ITestTextOptions::ITestLegacy interface proxy definitions
    //
    // Methods:
    //  (0) virtual Core::hresult TestLegacy(const uint32_t, const uint32_t, const ITestTextOptions::ITestLegacy::TestDetails&, const ITestTextOptions::ITestLegacy::EnumTextOptions) = 0
    //

    class TestTextOptionsTestLegacyProxy final : public ProxyStub::UnknownProxyType<ITestTextOptions::ITestLegacy> {
    public:
        TestTextOptionsTestLegacyProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        Core::hresult TestLegacy(const uint32_t _firstTestParam, const uint32_t _secondTestParam, const ITestTextOptions::ITestLegacy::TestDetails& _thirdTestParam, const ITestTextOptions::ITestLegacy::EnumTextOptions _fourthTestParam) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_firstTestParam);
            writer.Number<uint32_t>(_secondTestParam);
            writer.Text(_thirdTestParam.testDetailsFirst);
            writer.Text(_thirdTestParam.testDetailsSecond);
            writer.Number<ITestTextOptions::ITestLegacy::EnumTextOptions>(_fourthTestParam);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

    }; // class TestTextOptionsTestLegacyProxy

    //
    // ITestTextOptions::ITestLegacy::INotification interface proxy definitions
    //
    // Methods:
    //  (0) virtual void TestEvent(const uint32_t, const uint32_t, const ITestTextOptions::ITestLegacy::TestDetails&, const ITestTextOptions::ITestLegacy::EnumTextOptions) = 0
    //

    class TestTextOptionsTestLegacyNotificationProxy final : public ProxyStub::UnknownProxyType<ITestTextOptions::ITestLegacy::INotification> {
    public:
        TestTextOptionsTestLegacyNotificationProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        void TestEvent(const uint32_t _firstTestParam, const uint32_t _secondTestParam, const ITestTextOptions::ITestLegacy::TestDetails& _thirdTestParam, const ITestTextOptions::ITestLegacy::EnumTextOptions _fourthTestParam) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_firstTestParam);
            writer.Number<uint32_t>(_secondTestParam);
            writer.Text(_thirdTestParam.testDetailsFirst);
            writer.Text(_thirdTestParam.testDetailsSecond);
            writer.Number<ITestTextOptions::ITestLegacy::EnumTextOptions>(_fourthTestParam);

            static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
        }

    }; // class TestTextOptionsTestLegacyNotificationProxy

    //
    // ITestTextOptions::ITestKeep interface proxy definitions
    //
    // Methods:
    //  (0) virtual Core::hresult TestKeeP(const uint32_t, const uint32_t, const ITestTextOptions::ITestKeep::TestDetails&, const ITestTextOptions::ITestKeep::EnumTextOptions) = 0
    //

    class TestTextOptionsTestKeepProxy final : public ProxyStub::UnknownProxyType<ITestTextOptions::ITestKeep> {
    public:
        TestTextOptionsTestKeepProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        Core::hresult TestKeeP(const uint32_t _firstTestParaM, const uint32_t _secondTestParaM, const ITestTextOptions::ITestKeep::TestDetails& _thirdTestParaM, const ITestTextOptions::ITestKeep::EnumTextOptions _fourthTestParaM) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_firstTestParaM);
            writer.Number<uint32_t>(_secondTestParaM);
            writer.Text(_thirdTestParaM.testDetailsFirst);
            writer.Text(_thirdTestParaM.testDetailsSecond);
            writer.Number<ITestTextOptions::ITestKeep::EnumTextOptions>(_fourthTestParaM);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

    }; // class TestTextOptionsTestKeepProxy

    //
    // ITestTextOptions::ITestKeep::INotification interface proxy definitions
    //
    // Methods:
    //  (0) virtual void TestEvent(const uint32_t, const uint32_t, const ITestTextOptions::ITestKeep::TestDetails&, const ITestTextOptions::ITestKeep::EnumTextOptions) = 0
    //

    class TestTextOptionsTestKeepNotificationProxy final : public ProxyStub::UnknownProxyType<ITestTextOptions::ITestKeep::INotification> {
    public:
        TestTextOptionsTestKeepNotificationProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        void TestEvent(const uint32_t _firstTestParam, const uint32_t _secondTestParam, const ITestTextOptions::ITestKeep::TestDetails& _thirdTestParam, const ITestTextOptions::ITestKeep::EnumTextOptions _fourthTestParam) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_firstTestParam);
            writer.Number<uint32_t>(_secondTestParam);
            writer.Text(_thirdTestParam.testDetailsFirst);
            writer.Text(_thirdTestParam.testDetailsSecond);
            writer.Number<ITestTextOptions::ITestKeep::EnumTextOptions>(_fourthTestParam);

            static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
        }

    }; // class TestTextOptionsTestKeepNotificationProxy

    //
    // ITestTextOptions::ITestCustom interface proxy definitions
    //
    // Methods:
    //  (0) virtual Core::hresult TestCustom(const uint32_t, const uint32_t, const ITestTextOptions::ITestCustom::TestDetails&, const ITestTextOptions::ITestCustom::EnumTextOptions) = 0
    //

    class TestTextOptionsTestCustomProxy final : public ProxyStub::UnknownProxyType<ITestTextOptions::ITestCustom> {
    public:
        TestTextOptionsTestCustomProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        Core::hresult TestCustom(const uint32_t _firstTestParam, const uint32_t _secondTestParam, const ITestTextOptions::ITestCustom::TestDetails& _thirdTestParam, const ITestTextOptions::ITestCustom::EnumTextOptions _fourthTestParam) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_firstTestParam);
            writer.Number<uint32_t>(_secondTestParam);
            writer.Text(_thirdTestParam.testDetailsFirst);
            writer.Text(_thirdTestParam.testDetailsSecond);
            writer.Number<ITestTextOptions::ITestCustom::EnumTextOptions>(_fourthTestParam);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

    }; // class TestTextOptionsTestCustomProxy

    //
    // ITestTextOptions::ITestCustom::INotification interface proxy definitions
    //
    // Methods:
    //  (0) virtual void TestEvent(const uint32_t, const uint32_t, const ITestTextOptions::ITestCustom::TestDetails&, const ITestTextOptions::ITestCustom::EnumTextOptions) = 0
    //

    class TestTextOptionsTestCustomNotificationProxy final : public ProxyStub::UnknownProxyType<ITestTextOptions::ITestCustom::INotification> {
    public:
        TestTextOptionsTestCustomNotificationProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        void TestEvent(const uint32_t _firstTestParam, const uint32_t _secondTestParam, const ITestTextOptions::ITestCustom::TestDetails& _thirdTestParam, const ITestTextOptions::ITestCustom::EnumTextOptions _fourthTestParam) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_firstTestParam);
            writer.Number<uint32_t>(_secondTestParam);
            writer.Text(_thirdTestParam.testDetailsFirst);
            writer.Text(_thirdTestParam.testDetailsSecond);
            writer.Number<ITestTextOptions::ITestCustom::EnumTextOptions>(_fourthTestParam);

            static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
        }

    }; // class TestTextOptionsTestCustomNotificationProxy

    //
    // ITestUtils interface proxy definitions
    //
    // Methods:
    //  (0) virtual Core::hresult Crash() const = 0
    //

    class TestUtilsProxy final : public ProxyStub::UnknownProxyType<ITestUtils> {
    public:
        TestUtilsProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        Core::hresult Crash() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

    }; // class TestUtilsProxy

    POP_WARNING()
    POP_WARNING()

    // -----------------------------------------------------------------
    // REGISTRATION
    // -----------------------------------------------------------------
    namespace {

        typedef ProxyStub::UnknownStubType<IMemory, MemoryStubMethods> MemoryStub;
        typedef ProxyStub::UnknownStubType<IComRpc, ComRpcStubMethods> ComRpcStub;
        typedef ProxyStub::UnknownStubType<IComRpc::IComRpcInternal, ComRpcComRpcInternalStubMethods> ComRpcComRpcInternalStub;
        typedef ProxyStub::UnknownStubType<ITestTextOptions, TestTextOptionsStubMethods> TestTextOptionsStub;
        typedef ProxyStub::UnknownStubType<ITestTextOptions::INotification, TestTextOptionsNotificationStubMethods> TestTextOptionsNotificationStub;
        typedef ProxyStub::UnknownStubType<ITestTextOptions::ITestLegacy, TestTextOptionsTestLegacyStubMethods> TestTextOptionsTestLegacyStub;
        typedef ProxyStub::UnknownStubType<ITestTextOptions::ITestLegacy::INotification, TestTextOptionsTestLegacyNotificationStubMethods> TestTextOptionsTestLegacyNotificationStub;
        typedef ProxyStub::UnknownStubType<ITestTextOptions::ITestKeep, TestTextOptionsTestKeepStubMethods> TestTextOptionsTestKeepStub;
        typedef ProxyStub::UnknownStubType<ITestTextOptions::ITestKeep::INotification, TestTextOptionsTestKeepNotificationStubMethods> TestTextOptionsTestKeepNotificationStub;
        typedef ProxyStub::UnknownStubType<ITestTextOptions::ITestCustom, TestTextOptionsTestCustomStubMethods> TestTextOptionsTestCustomStub;
        typedef ProxyStub::UnknownStubType<ITestTextOptions::ITestCustom::INotification, TestTextOptionsTestCustomNotificationStubMethods> TestTextOptionsTestCustomNotificationStub;
        typedef ProxyStub::UnknownStubType<ITestUtils, TestUtilsStubMethods> TestUtilsStub;

        static class Instantiation {
        public:
            Instantiation()
            {
                RPC::Administrator::Instance().Announce<IMemory, MemoryProxy, MemoryStub>();
                RPC::Administrator::Instance().Announce<IComRpc, ComRpcProxy, ComRpcStub>();
                RPC::Administrator::Instance().Announce<IComRpc::IComRpcInternal, ComRpcComRpcInternalProxy, ComRpcComRpcInternalStub>();
                RPC::Administrator::Instance().Announce<ITestTextOptions, TestTextOptionsProxy, TestTextOptionsStub>();
                RPC::Administrator::Instance().Announce<ITestTextOptions::INotification, TestTextOptionsNotificationProxy, TestTextOptionsNotificationStub>();
                RPC::Administrator::Instance().Announce<ITestTextOptions::ITestLegacy, TestTextOptionsTestLegacyProxy, TestTextOptionsTestLegacyStub>();
                RPC::Administrator::Instance().Announce<ITestTextOptions::ITestLegacy::INotification, TestTextOptionsTestLegacyNotificationProxy, TestTextOptionsTestLegacyNotificationStub>();
                RPC::Administrator::Instance().Announce<ITestTextOptions::ITestKeep, TestTextOptionsTestKeepProxy, TestTextOptionsTestKeepStub>();
                RPC::Administrator::Instance().Announce<ITestTextOptions::ITestKeep::INotification, TestTextOptionsTestKeepNotificationProxy, TestTextOptionsTestKeepNotificationStub>();
                RPC::Administrator::Instance().Announce<ITestTextOptions::ITestCustom, TestTextOptionsTestCustomProxy, TestTextOptionsTestCustomStub>();
                RPC::Administrator::Instance().Announce<ITestTextOptions::ITestCustom::INotification, TestTextOptionsTestCustomNotificationProxy, TestTextOptionsTestCustomNotificationStub>();
                RPC::Administrator::Instance().Announce<ITestUtils, TestUtilsProxy, TestUtilsStub>();
            }
            ~Instantiation()
            {
                RPC::Administrator::Instance().Recall<IMemory>();
                RPC::Administrator::Instance().Recall<IComRpc>();
                RPC::Administrator::Instance().Recall<IComRpc::IComRpcInternal>();
                RPC::Administrator::Instance().Recall<ITestTextOptions>();
                RPC::Administrator::Instance().Recall<ITestTextOptions::INotification>();
                RPC::Administrator::Instance().Recall<ITestTextOptions::ITestLegacy>();
                RPC::Administrator::Instance().Recall<ITestTextOptions::ITestLegacy::INotification>();
                RPC::Administrator::Instance().Recall<ITestTextOptions::ITestKeep>();
                RPC::Administrator::Instance().Recall<ITestTextOptions::ITestKeep::INotification>();
                RPC::Administrator::Instance().Recall<ITestTextOptions::ITestCustom>();
                RPC::Administrator::Instance().Recall<ITestTextOptions::ITestCustom::INotification>();
                RPC::Administrator::Instance().Recall<ITestUtils>();
            }
        } ProxyStubRegistration;

    } // namespace

} // namespace ProxyStubs

}
