//
// generated automatically from "ITestAutomation.h"
//
// implements COM-RPC proxy stubs for:
//   - class QualityAssurance::IMemory
//   - class QualityAssurance::IComRpc
//   - class QualityAssurance::IComRpc::IComRpcInternal
//   - class QualityAssurance::ITestTextOptions
//   - class QualityAssurance::ITestTextOptions::INotification
//   - class QualityAssurance::ITestTextOptions::ITestLegacy
//   - class QualityAssurance::ITestTextOptions::ITestLegacy::INotification
//   - class QualityAssurance::ITestTextOptions::ITestKeep
//   - class QualityAssurance::ITestTextOptions::ITestKeep::INotification
//   - class QualityAssurance::ITestTextOptions::ITestCustom
//   - class QualityAssurance::ITestTextOptions::ITestCustom::INotification
//   - class QualityAssurance::ITestUtils
//
// secure code enabled:
//   - instance verification enabled
//   - range verification enabled
//   - frame coherency verification enabled
//

#include "Module.h"
#include "ITestAutomation.h"

#include <com/com.h>

namespace Thunder {

namespace ProxyStubs {

    PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    // -----------------------------------------------------------------
    // STUBS
    // -----------------------------------------------------------------

    //
    // QualityAssurance::IMemory interface stub definitions
    //
    // Methods:
    //  (0) virtual Core::hresult AllocateMemory(const uint32_t) = 0
    //  (1) virtual Core::hresult FreeAllocatedMemory() = 0
    //

    static ProxyStub::MethodHandler QualityAssuranceMemoryStubMethods[] = {
        // (0) virtual Core::hresult AllocateMemory(const uint32_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                QualityAssurance::IMemory* implementation = reinterpret_cast<QualityAssurance::IMemory*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), QualityAssurance::IMemory::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint32_t _size = reader.Number<uint32_t>();

                Core::hresult result = implementation->AllocateMemory(_size);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<Core::hresult>(result);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(hresult);
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", QualityAssurance::IMemory::ID, 0, hresult);
            }
        },

        // (1) virtual Core::hresult FreeAllocatedMemory() = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                QualityAssurance::IMemory* implementation = reinterpret_cast<QualityAssurance::IMemory*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), QualityAssurance::IMemory::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                Core::hresult result = implementation->FreeAllocatedMemory();

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<Core::hresult>(result);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(hresult);
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", QualityAssurance::IMemory::ID, 1, hresult);
            }
        }
        , nullptr
    }; // QualityAssuranceMemoryStubMethods

    //
    // QualityAssurance::IComRpc interface stub definitions
    //
    // Methods:
    //  (0) virtual Core::hresult TestBigString(const uint32_t) = 0
    //

    static ProxyStub::MethodHandler QualityAssuranceComRpcStubMethods[] = {
        // (0) virtual Core::hresult TestBigString(const uint32_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                QualityAssurance::IComRpc* implementation = reinterpret_cast<QualityAssurance::IComRpc*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), QualityAssurance::IComRpc::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint32_t _length = reader.Number<uint32_t>();

                Core::hresult result = implementation->TestBigString(_length);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<Core::hresult>(result);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(hresult);
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", QualityAssurance::IComRpc::ID, 0, hresult);
            }
        }
        , nullptr
    }; // QualityAssuranceComRpcStubMethods

    //
    // QualityAssurance::IComRpc::IComRpcInternal interface stub definitions
    //
    // Methods:
    //  (0) virtual Core::hresult BigStringTest(const string&) = 0
    //

    static ProxyStub::MethodHandler QualityAssuranceComRpcComRpcInternalStubMethods[] = {
        // (0) virtual Core::hresult BigStringTest(const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                QualityAssurance::IComRpc::IComRpcInternal* implementation = reinterpret_cast<QualityAssurance::IComRpc::IComRpcInternal*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), QualityAssurance::IComRpc::IComRpcInternal::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (Core::RealSize<Core::UInt24>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const Core::UInt24 _testStringPeekedLen__ = reader.PeekNumber<Core::UInt24>();
                ASSERT((_testStringPeekedLen__ >= 0) && (_testStringPeekedLen__ <= 4194303));
                if (!((_testStringPeekedLen__ >= 0) && (_testStringPeekedLen__ <= 4194303))) { return (COM_ERROR | Core::ERROR_INVALID_RANGE); }
                if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<Core::UInt24>()) + _testStringPeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const string _testString = reader.Text<Core::UInt24>();

                Core::hresult result = implementation->BigStringTest(static_cast<const string&>(_testString));

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<Core::hresult>(result);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(hresult);
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", QualityAssurance::IComRpc::IComRpcInternal::ID, 0, hresult);
            }
        }
        , nullptr
    }; // QualityAssuranceComRpcComRpcInternalStubMethods

    //
    // QualityAssurance::ITestTextOptions interface stub definitions
    //
    // Methods:
    //  (0) virtual Core::hresult TestStandard(const uint32_t, const uint32_t, const QualityAssurance::ITestTextOptions::TestDetails&, const QualityAssurance::ITestTextOptions::EnumTextOptions) = 0
    //

    static ProxyStub::MethodHandler QualityAssuranceTestTextOptionsStubMethods[] = {
        // (0) virtual Core::hresult TestStandard(const uint32_t, const uint32_t, const QualityAssurance::ITestTextOptions::TestDetails&, const QualityAssurance::ITestTextOptions::EnumTextOptions) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                QualityAssurance::ITestTextOptions* implementation = reinterpret_cast<QualityAssurance::ITestTextOptions*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), QualityAssurance::ITestTextOptions::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint32_t _firstTestParam = reader.Number<uint32_t>();
                if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint32_t _secondTestParam = reader.Number<uint32_t>();
                QualityAssurance::ITestTextOptions::TestDetails _thirdTestParam{};
                if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint16_t _thirdTestParam_testDetailsFirstPeekedLen__ = reader.PeekNumber<uint16_t>();
                if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint16_t>()) + _thirdTestParam_testDetailsFirstPeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                _thirdTestParam.testDetailsFirst = reader.Text();
                if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint16_t _thirdTestParam_testDetailsSecondPeekedLen__ = reader.PeekNumber<uint16_t>();
                if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint16_t>()) + _thirdTestParam_testDetailsSecondPeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                _thirdTestParam.testDetailsSecond = reader.Text();
                if (reader.Length() < (Core::RealSize<QualityAssurance::ITestTextOptions::EnumTextOptions>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const QualityAssurance::ITestTextOptions::EnumTextOptions _fourthTestParam = reader.Number<QualityAssurance::ITestTextOptions::EnumTextOptions>();

                Core::hresult result = implementation->TestStandard(_firstTestParam, _secondTestParam, static_cast<const QualityAssurance::ITestTextOptions::TestDetails&>(_thirdTestParam), _fourthTestParam);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<Core::hresult>(result);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(hresult);
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", QualityAssurance::ITestTextOptions::ID, 0, hresult);
            }
        }
        , nullptr
    }; // QualityAssuranceTestTextOptionsStubMethods

    //
    // QualityAssurance::ITestTextOptions::INotification interface stub definitions
    //
    // Methods:
    //  (0) virtual void TestEvent(const uint32_t, const uint32_t, const QualityAssurance::ITestTextOptions::TestDetails&, const QualityAssurance::ITestTextOptions::EnumTextOptions) = 0
    //

    static ProxyStub::MethodHandler QualityAssuranceTestTextOptionsNotificationStubMethods[] = {
        // (0) virtual void TestEvent(const uint32_t, const uint32_t, const QualityAssurance::ITestTextOptions::TestDetails&, const QualityAssurance::ITestTextOptions::EnumTextOptions) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                QualityAssurance::ITestTextOptions::INotification* implementation = reinterpret_cast<QualityAssurance::ITestTextOptions::INotification*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), QualityAssurance::ITestTextOptions::INotification::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint32_t _firstTestParam = reader.Number<uint32_t>();
                if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint32_t _secondTestParam = reader.Number<uint32_t>();
                QualityAssurance::ITestTextOptions::TestDetails _thirdTestParam{};
                if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint16_t _thirdTestParam_testDetailsFirstPeekedLen__ = reader.PeekNumber<uint16_t>();
                if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint16_t>()) + _thirdTestParam_testDetailsFirstPeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                _thirdTestParam.testDetailsFirst = reader.Text();
                if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint16_t _thirdTestParam_testDetailsSecondPeekedLen__ = reader.PeekNumber<uint16_t>();
                if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint16_t>()) + _thirdTestParam_testDetailsSecondPeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                _thirdTestParam.testDetailsSecond = reader.Text();
                if (reader.Length() < (Core::RealSize<QualityAssurance::ITestTextOptions::EnumTextOptions>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const QualityAssurance::ITestTextOptions::EnumTextOptions _fourthTestParam = reader.Number<QualityAssurance::ITestTextOptions::EnumTextOptions>();

                implementation->TestEvent(_firstTestParam, _secondTestParam, static_cast<const QualityAssurance::ITestTextOptions::TestDetails&>(_thirdTestParam), _fourthTestParam);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", QualityAssurance::ITestTextOptions::INotification::ID, 0, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        }
        , nullptr
    }; // QualityAssuranceTestTextOptionsNotificationStubMethods

    //
    // QualityAssurance::ITestTextOptions::ITestLegacy interface stub definitions
    //
    // Methods:
    //  (0) virtual Core::hresult TestLegacy(const uint32_t, const uint32_t, const QualityAssurance::ITestTextOptions::ITestLegacy::TestDetails&, const QualityAssurance::ITestTextOptions::ITestLegacy::EnumTextOptions) = 0
    //

    static ProxyStub::MethodHandler QualityAssuranceTestTextOptionsTestLegacyStubMethods[] = {
        // (0) virtual Core::hresult TestLegacy(const uint32_t, const uint32_t, const QualityAssurance::ITestTextOptions::ITestLegacy::TestDetails&, const QualityAssurance::ITestTextOptions::ITestLegacy::EnumTextOptions) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                QualityAssurance::ITestTextOptions::ITestLegacy* implementation = reinterpret_cast<QualityAssurance::ITestTextOptions::ITestLegacy*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), QualityAssurance::ITestTextOptions::ITestLegacy::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint32_t _firstTestParam = reader.Number<uint32_t>();
                if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint32_t _secondTestParam = reader.Number<uint32_t>();
                QualityAssurance::ITestTextOptions::ITestLegacy::TestDetails _thirdTestParam{};
                if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint16_t _thirdTestParam_testDetailsFirstPeekedLen__ = reader.PeekNumber<uint16_t>();
                if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint16_t>()) + _thirdTestParam_testDetailsFirstPeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                _thirdTestParam.testDetailsFirst = reader.Text();
                if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint16_t _thirdTestParam_testDetailsSecondPeekedLen__ = reader.PeekNumber<uint16_t>();
                if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint16_t>()) + _thirdTestParam_testDetailsSecondPeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                _thirdTestParam.testDetailsSecond = reader.Text();
                if (reader.Length() < (Core::RealSize<QualityAssurance::ITestTextOptions::ITestLegacy::EnumTextOptions>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const QualityAssurance::ITestTextOptions::ITestLegacy::EnumTextOptions _fourthTestParam = reader.Number<QualityAssurance::ITestTextOptions::ITestLegacy::EnumTextOptions>();

                Core::hresult result = implementation->TestLegacy(_firstTestParam, _secondTestParam, static_cast<const QualityAssurance::ITestTextOptions::ITestLegacy::TestDetails&>(_thirdTestParam), _fourthTestParam);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<Core::hresult>(result);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(hresult);
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", QualityAssurance::ITestTextOptions::ITestLegacy::ID, 0, hresult);
            }
        }
        , nullptr
    }; // QualityAssuranceTestTextOptionsTestLegacyStubMethods

    //
    // QualityAssurance::ITestTextOptions::ITestLegacy::INotification interface stub definitions
    //
    // Methods:
    //  (0) virtual void TestEvent(const uint32_t, const uint32_t, const QualityAssurance::ITestTextOptions::ITestLegacy::TestDetails&, const QualityAssurance::ITestTextOptions::ITestLegacy::EnumTextOptions) = 0
    //

    static ProxyStub::MethodHandler QualityAssuranceTestTextOptionsTestLegacyNotificationStubMethods[] = {
        // (0) virtual void TestEvent(const uint32_t, const uint32_t, const QualityAssurance::ITestTextOptions::ITestLegacy::TestDetails&, const QualityAssurance::ITestTextOptions::ITestLegacy::EnumTextOptions) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                QualityAssurance::ITestTextOptions::ITestLegacy::INotification* implementation = reinterpret_cast<QualityAssurance::ITestTextOptions::ITestLegacy::INotification*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), QualityAssurance::ITestTextOptions::ITestLegacy::INotification::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint32_t _firstTestParam = reader.Number<uint32_t>();
                if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint32_t _secondTestParam = reader.Number<uint32_t>();
                QualityAssurance::ITestTextOptions::ITestLegacy::TestDetails _thirdTestParam{};
                if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint16_t _thirdTestParam_testDetailsFirstPeekedLen__ = reader.PeekNumber<uint16_t>();
                if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint16_t>()) + _thirdTestParam_testDetailsFirstPeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                _thirdTestParam.testDetailsFirst = reader.Text();
                if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint16_t _thirdTestParam_testDetailsSecondPeekedLen__ = reader.PeekNumber<uint16_t>();
                if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint16_t>()) + _thirdTestParam_testDetailsSecondPeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                _thirdTestParam.testDetailsSecond = reader.Text();
                if (reader.Length() < (Core::RealSize<QualityAssurance::ITestTextOptions::ITestLegacy::EnumTextOptions>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const QualityAssurance::ITestTextOptions::ITestLegacy::EnumTextOptions _fourthTestParam = reader.Number<QualityAssurance::ITestTextOptions::ITestLegacy::EnumTextOptions>();

                implementation->TestEvent(_firstTestParam, _secondTestParam, static_cast<const QualityAssurance::ITestTextOptions::ITestLegacy::TestDetails&>(_thirdTestParam), _fourthTestParam);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", QualityAssurance::ITestTextOptions::ITestLegacy::INotification::ID, 0, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        }
        , nullptr
    }; // QualityAssuranceTestTextOptionsTestLegacyNotificationStubMethods

    //
    // QualityAssurance::ITestTextOptions::ITestKeep interface stub definitions
    //
    // Methods:
    //  (0) virtual Core::hresult TestKeeP(const uint32_t, const uint32_t, const QualityAssurance::ITestTextOptions::ITestKeep::TestDetails&, const QualityAssurance::ITestTextOptions::ITestKeep::EnumTextOptions) = 0
    //

    static ProxyStub::MethodHandler QualityAssuranceTestTextOptionsTestKeepStubMethods[] = {
        // (0) virtual Core::hresult TestKeeP(const uint32_t, const uint32_t, const QualityAssurance::ITestTextOptions::ITestKeep::TestDetails&, const QualityAssurance::ITestTextOptions::ITestKeep::EnumTextOptions) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                QualityAssurance::ITestTextOptions::ITestKeep* implementation = reinterpret_cast<QualityAssurance::ITestTextOptions::ITestKeep*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), QualityAssurance::ITestTextOptions::ITestKeep::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint32_t _firstTestParaM = reader.Number<uint32_t>();
                if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint32_t _secondTestParaM = reader.Number<uint32_t>();
                QualityAssurance::ITestTextOptions::ITestKeep::TestDetails _thirdTestParaM{};
                if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint16_t _thirdTestParaM_testDetailsFirstPeekedLen__ = reader.PeekNumber<uint16_t>();
                if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint16_t>()) + _thirdTestParaM_testDetailsFirstPeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                _thirdTestParaM.testDetailsFirst = reader.Text();
                if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint16_t _thirdTestParaM_testDetailsSecondPeekedLen__ = reader.PeekNumber<uint16_t>();
                if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint16_t>()) + _thirdTestParaM_testDetailsSecondPeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                _thirdTestParaM.testDetailsSecond = reader.Text();
                if (reader.Length() < (Core::RealSize<QualityAssurance::ITestTextOptions::ITestKeep::EnumTextOptions>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const QualityAssurance::ITestTextOptions::ITestKeep::EnumTextOptions _fourthTestParaM = reader.Number<QualityAssurance::ITestTextOptions::ITestKeep::EnumTextOptions>();

                Core::hresult result = implementation->TestKeeP(_firstTestParaM, _secondTestParaM, static_cast<const QualityAssurance::ITestTextOptions::ITestKeep::TestDetails&>(_thirdTestParaM), _fourthTestParaM);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<Core::hresult>(result);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(hresult);
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", QualityAssurance::ITestTextOptions::ITestKeep::ID, 0, hresult);
            }
        }
        , nullptr
    }; // QualityAssuranceTestTextOptionsTestKeepStubMethods

    //
    // QualityAssurance::ITestTextOptions::ITestKeep::INotification interface stub definitions
    //
    // Methods:
    //  (0) virtual void TestEvent(const uint32_t, const uint32_t, const QualityAssurance::ITestTextOptions::ITestKeep::TestDetails&, const QualityAssurance::ITestTextOptions::ITestKeep::EnumTextOptions) = 0
    //

    static ProxyStub::MethodHandler QualityAssuranceTestTextOptionsTestKeepNotificationStubMethods[] = {
        // (0) virtual void TestEvent(const uint32_t, const uint32_t, const QualityAssurance::ITestTextOptions::ITestKeep::TestDetails&, const QualityAssurance::ITestTextOptions::ITestKeep::EnumTextOptions) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                QualityAssurance::ITestTextOptions::ITestKeep::INotification* implementation = reinterpret_cast<QualityAssurance::ITestTextOptions::ITestKeep::INotification*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), QualityAssurance::ITestTextOptions::ITestKeep::INotification::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint32_t _firstTestParam = reader.Number<uint32_t>();
                if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint32_t _secondTestParam = reader.Number<uint32_t>();
                QualityAssurance::ITestTextOptions::ITestKeep::TestDetails _thirdTestParam{};
                if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint16_t _thirdTestParam_testDetailsFirstPeekedLen__ = reader.PeekNumber<uint16_t>();
                if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint16_t>()) + _thirdTestParam_testDetailsFirstPeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                _thirdTestParam.testDetailsFirst = reader.Text();
                if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint16_t _thirdTestParam_testDetailsSecondPeekedLen__ = reader.PeekNumber<uint16_t>();
                if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint16_t>()) + _thirdTestParam_testDetailsSecondPeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                _thirdTestParam.testDetailsSecond = reader.Text();
                if (reader.Length() < (Core::RealSize<QualityAssurance::ITestTextOptions::ITestKeep::EnumTextOptions>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const QualityAssurance::ITestTextOptions::ITestKeep::EnumTextOptions _fourthTestParam = reader.Number<QualityAssurance::ITestTextOptions::ITestKeep::EnumTextOptions>();

                implementation->TestEvent(_firstTestParam, _secondTestParam, static_cast<const QualityAssurance::ITestTextOptions::ITestKeep::TestDetails&>(_thirdTestParam), _fourthTestParam);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", QualityAssurance::ITestTextOptions::ITestKeep::INotification::ID, 0, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        }
        , nullptr
    }; // QualityAssuranceTestTextOptionsTestKeepNotificationStubMethods

    //
    // QualityAssurance::ITestTextOptions::ITestCustom interface stub definitions
    //
    // Methods:
    //  (0) virtual Core::hresult TestCustom(const uint32_t, const uint32_t, const QualityAssurance::ITestTextOptions::ITestCustom::TestDetails&, const QualityAssurance::ITestTextOptions::ITestCustom::EnumTextOptions) = 0
    //

    static ProxyStub::MethodHandler QualityAssuranceTestTextOptionsTestCustomStubMethods[] = {
        // (0) virtual Core::hresult TestCustom(const uint32_t, const uint32_t, const QualityAssurance::ITestTextOptions::ITestCustom::TestDetails&, const QualityAssurance::ITestTextOptions::ITestCustom::EnumTextOptions) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                QualityAssurance::ITestTextOptions::ITestCustom* implementation = reinterpret_cast<QualityAssurance::ITestTextOptions::ITestCustom*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), QualityAssurance::ITestTextOptions::ITestCustom::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint32_t _firstTestParam = reader.Number<uint32_t>();
                if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint32_t _secondTestParam = reader.Number<uint32_t>();
                QualityAssurance::ITestTextOptions::ITestCustom::TestDetails _thirdTestParam{};
                if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint16_t _thirdTestParam_testDetailsFirstPeekedLen__ = reader.PeekNumber<uint16_t>();
                if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint16_t>()) + _thirdTestParam_testDetailsFirstPeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                _thirdTestParam.testDetailsFirst = reader.Text();
                if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint16_t _thirdTestParam_testDetailsSecondPeekedLen__ = reader.PeekNumber<uint16_t>();
                if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint16_t>()) + _thirdTestParam_testDetailsSecondPeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                _thirdTestParam.testDetailsSecond = reader.Text();
                if (reader.Length() < (Core::RealSize<QualityAssurance::ITestTextOptions::ITestCustom::EnumTextOptions>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const QualityAssurance::ITestTextOptions::ITestCustom::EnumTextOptions _fourthTestParam = reader.Number<QualityAssurance::ITestTextOptions::ITestCustom::EnumTextOptions>();

                Core::hresult result = implementation->TestCustom(_firstTestParam, _secondTestParam, static_cast<const QualityAssurance::ITestTextOptions::ITestCustom::TestDetails&>(_thirdTestParam), _fourthTestParam);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<Core::hresult>(result);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(hresult);
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", QualityAssurance::ITestTextOptions::ITestCustom::ID, 0, hresult);
            }
        }
        , nullptr
    }; // QualityAssuranceTestTextOptionsTestCustomStubMethods

    //
    // QualityAssurance::ITestTextOptions::ITestCustom::INotification interface stub definitions
    //
    // Methods:
    //  (0) virtual void TestEvent(const uint32_t, const uint32_t, const QualityAssurance::ITestTextOptions::ITestCustom::TestDetails&, const QualityAssurance::ITestTextOptions::ITestCustom::EnumTextOptions) = 0
    //

    static ProxyStub::MethodHandler QualityAssuranceTestTextOptionsTestCustomNotificationStubMethods[] = {
        // (0) virtual void TestEvent(const uint32_t, const uint32_t, const QualityAssurance::ITestTextOptions::ITestCustom::TestDetails&, const QualityAssurance::ITestTextOptions::ITestCustom::EnumTextOptions) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                QualityAssurance::ITestTextOptions::ITestCustom::INotification* implementation = reinterpret_cast<QualityAssurance::ITestTextOptions::ITestCustom::INotification*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), QualityAssurance::ITestTextOptions::ITestCustom::INotification::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint32_t _firstTestParam = reader.Number<uint32_t>();
                if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint32_t _secondTestParam = reader.Number<uint32_t>();
                QualityAssurance::ITestTextOptions::ITestCustom::TestDetails _thirdTestParam{};
                if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint16_t _thirdTestParam_testDetailsFirstPeekedLen__ = reader.PeekNumber<uint16_t>();
                if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint16_t>()) + _thirdTestParam_testDetailsFirstPeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                _thirdTestParam.testDetailsFirst = reader.Text();
                if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint16_t _thirdTestParam_testDetailsSecondPeekedLen__ = reader.PeekNumber<uint16_t>();
                if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint16_t>()) + _thirdTestParam_testDetailsSecondPeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                _thirdTestParam.testDetailsSecond = reader.Text();
                if (reader.Length() < (Core::RealSize<QualityAssurance::ITestTextOptions::ITestCustom::EnumTextOptions>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const QualityAssurance::ITestTextOptions::ITestCustom::EnumTextOptions _fourthTestParam = reader.Number<QualityAssurance::ITestTextOptions::ITestCustom::EnumTextOptions>();

                implementation->TestEvent(_firstTestParam, _secondTestParam, static_cast<const QualityAssurance::ITestTextOptions::ITestCustom::TestDetails&>(_thirdTestParam), _fourthTestParam);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", QualityAssurance::ITestTextOptions::ITestCustom::INotification::ID, 0, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        }
        , nullptr
    }; // QualityAssuranceTestTextOptionsTestCustomNotificationStubMethods

    //
    // QualityAssurance::ITestUtils interface stub definitions
    //
    // Methods:
    //  (0) virtual Core::hresult Crash() const = 0
    //

    static ProxyStub::MethodHandler QualityAssuranceTestUtilsStubMethods[] = {
        // (0) virtual Core::hresult Crash() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const QualityAssurance::ITestUtils* implementation = reinterpret_cast<const QualityAssurance::ITestUtils*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), QualityAssurance::ITestUtils::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                Core::hresult result = implementation->Crash();

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<Core::hresult>(result);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(hresult);
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", QualityAssurance::ITestUtils::ID, 0, hresult);
            }
        }
        , nullptr
    }; // QualityAssuranceTestUtilsStubMethods

    // -----------------------------------------------------------------
    // PROXIES
    // -----------------------------------------------------------------

    //
    // QualityAssurance::IMemory interface proxy definitions
    //
    // Methods:
    //  (0) virtual Core::hresult AllocateMemory(const uint32_t) = 0
    //  (1) virtual Core::hresult FreeAllocatedMemory() = 0
    //

    class QualityAssuranceMemoryProxy final : public ProxyStub::UnknownProxyType<QualityAssurance::IMemory> {
    public:
        QualityAssuranceMemoryProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
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
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", QualityAssurance::IMemory::ID, 0, hresult);
            }

            return (hresult);
        }

        Core::hresult FreeAllocatedMemory() override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

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
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", QualityAssurance::IMemory::ID, 1, hresult);
            }

            return (hresult);
        }

    }; // class QualityAssuranceMemoryProxy

    //
    // QualityAssurance::IComRpc interface proxy definitions
    //
    // Methods:
    //  (0) virtual Core::hresult TestBigString(const uint32_t) = 0
    //

    class QualityAssuranceComRpcProxy final : public ProxyStub::UnknownProxyType<QualityAssurance::IComRpc> {
    public:
        QualityAssuranceComRpcProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
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
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", QualityAssurance::IComRpc::ID, 0, hresult);
            }

            return (hresult);
        }

    }; // class QualityAssuranceComRpcProxy

    //
    // QualityAssurance::IComRpc::IComRpcInternal interface proxy definitions
    //
    // Methods:
    //  (0) virtual Core::hresult BigStringTest(const string&) = 0
    //

    class QualityAssuranceComRpcComRpcInternalProxy final : public ProxyStub::UnknownProxyType<QualityAssurance::IComRpc::IComRpcInternal> {
    public:
        QualityAssuranceComRpcComRpcInternalProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
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
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", QualityAssurance::IComRpc::IComRpcInternal::ID, 0, hresult);
            }

            return (hresult);
        }

    }; // class QualityAssuranceComRpcComRpcInternalProxy

    //
    // QualityAssurance::ITestTextOptions interface proxy definitions
    //
    // Methods:
    //  (0) virtual Core::hresult TestStandard(const uint32_t, const uint32_t, const QualityAssurance::ITestTextOptions::TestDetails&, const QualityAssurance::ITestTextOptions::EnumTextOptions) = 0
    //

    class QualityAssuranceTestTextOptionsProxy final : public ProxyStub::UnknownProxyType<QualityAssurance::ITestTextOptions> {
    public:
        QualityAssuranceTestTextOptionsProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        Core::hresult TestStandard(const uint32_t _firstTestParam, const uint32_t _secondTestParam, const QualityAssurance::ITestTextOptions::TestDetails& _thirdTestParam, const QualityAssurance::ITestTextOptions::EnumTextOptions _fourthTestParam) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_firstTestParam);
            writer.Number<uint32_t>(_secondTestParam);
            writer.Text(_thirdTestParam.testDetailsFirst);
            writer.Text(_thirdTestParam.testDetailsSecond);
            writer.Number<QualityAssurance::ITestTextOptions::EnumTextOptions>(_fourthTestParam);

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
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", QualityAssurance::ITestTextOptions::ID, 0, hresult);
            }

            return (hresult);
        }

    }; // class QualityAssuranceTestTextOptionsProxy

    //
    // QualityAssurance::ITestTextOptions::INotification interface proxy definitions
    //
    // Methods:
    //  (0) virtual void TestEvent(const uint32_t, const uint32_t, const QualityAssurance::ITestTextOptions::TestDetails&, const QualityAssurance::ITestTextOptions::EnumTextOptions) = 0
    //

    class QualityAssuranceTestTextOptionsNotificationProxy final : public ProxyStub::UnknownProxyType<QualityAssurance::ITestTextOptions::INotification> {
    public:
        QualityAssuranceTestTextOptionsNotificationProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        void TestEvent(const uint32_t _firstTestParam, const uint32_t _secondTestParam, const QualityAssurance::ITestTextOptions::TestDetails& _thirdTestParam, const QualityAssurance::ITestTextOptions::EnumTextOptions _fourthTestParam) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_firstTestParam);
            writer.Number<uint32_t>(_secondTestParam);
            writer.Text(_thirdTestParam.testDetailsFirst);
            writer.Text(_thirdTestParam.testDetailsSecond);
            writer.Number<QualityAssurance::ITestTextOptions::EnumTextOptions>(_fourthTestParam);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", QualityAssurance::ITestTextOptions::INotification::ID, 0, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        }

    }; // class QualityAssuranceTestTextOptionsNotificationProxy

    //
    // QualityAssurance::ITestTextOptions::ITestLegacy interface proxy definitions
    //
    // Methods:
    //  (0) virtual Core::hresult TestLegacy(const uint32_t, const uint32_t, const QualityAssurance::ITestTextOptions::ITestLegacy::TestDetails&, const QualityAssurance::ITestTextOptions::ITestLegacy::EnumTextOptions) = 0
    //

    class QualityAssuranceTestTextOptionsTestLegacyProxy final : public ProxyStub::UnknownProxyType<QualityAssurance::ITestTextOptions::ITestLegacy> {
    public:
        QualityAssuranceTestTextOptionsTestLegacyProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        Core::hresult TestLegacy(const uint32_t _firstTestParam, const uint32_t _secondTestParam, const QualityAssurance::ITestTextOptions::ITestLegacy::TestDetails& _thirdTestParam, const QualityAssurance::ITestTextOptions::ITestLegacy::EnumTextOptions _fourthTestParam) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_firstTestParam);
            writer.Number<uint32_t>(_secondTestParam);
            writer.Text(_thirdTestParam.testDetailsFirst);
            writer.Text(_thirdTestParam.testDetailsSecond);
            writer.Number<QualityAssurance::ITestTextOptions::ITestLegacy::EnumTextOptions>(_fourthTestParam);

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
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", QualityAssurance::ITestTextOptions::ITestLegacy::ID, 0, hresult);
            }

            return (hresult);
        }

    }; // class QualityAssuranceTestTextOptionsTestLegacyProxy

    //
    // QualityAssurance::ITestTextOptions::ITestLegacy::INotification interface proxy definitions
    //
    // Methods:
    //  (0) virtual void TestEvent(const uint32_t, const uint32_t, const QualityAssurance::ITestTextOptions::ITestLegacy::TestDetails&, const QualityAssurance::ITestTextOptions::ITestLegacy::EnumTextOptions) = 0
    //

    class QualityAssuranceTestTextOptionsTestLegacyNotificationProxy final : public ProxyStub::UnknownProxyType<QualityAssurance::ITestTextOptions::ITestLegacy::INotification> {
    public:
        QualityAssuranceTestTextOptionsTestLegacyNotificationProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        void TestEvent(const uint32_t _firstTestParam, const uint32_t _secondTestParam, const QualityAssurance::ITestTextOptions::ITestLegacy::TestDetails& _thirdTestParam, const QualityAssurance::ITestTextOptions::ITestLegacy::EnumTextOptions _fourthTestParam) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_firstTestParam);
            writer.Number<uint32_t>(_secondTestParam);
            writer.Text(_thirdTestParam.testDetailsFirst);
            writer.Text(_thirdTestParam.testDetailsSecond);
            writer.Number<QualityAssurance::ITestTextOptions::ITestLegacy::EnumTextOptions>(_fourthTestParam);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", QualityAssurance::ITestTextOptions::ITestLegacy::INotification::ID, 0, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        }

    }; // class QualityAssuranceTestTextOptionsTestLegacyNotificationProxy

    //
    // QualityAssurance::ITestTextOptions::ITestKeep interface proxy definitions
    //
    // Methods:
    //  (0) virtual Core::hresult TestKeeP(const uint32_t, const uint32_t, const QualityAssurance::ITestTextOptions::ITestKeep::TestDetails&, const QualityAssurance::ITestTextOptions::ITestKeep::EnumTextOptions) = 0
    //

    class QualityAssuranceTestTextOptionsTestKeepProxy final : public ProxyStub::UnknownProxyType<QualityAssurance::ITestTextOptions::ITestKeep> {
    public:
        QualityAssuranceTestTextOptionsTestKeepProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        Core::hresult TestKeeP(const uint32_t _firstTestParaM, const uint32_t _secondTestParaM, const QualityAssurance::ITestTextOptions::ITestKeep::TestDetails& _thirdTestParaM, const QualityAssurance::ITestTextOptions::ITestKeep::EnumTextOptions _fourthTestParaM) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_firstTestParaM);
            writer.Number<uint32_t>(_secondTestParaM);
            writer.Text(_thirdTestParaM.testDetailsFirst);
            writer.Text(_thirdTestParaM.testDetailsSecond);
            writer.Number<QualityAssurance::ITestTextOptions::ITestKeep::EnumTextOptions>(_fourthTestParaM);

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
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", QualityAssurance::ITestTextOptions::ITestKeep::ID, 0, hresult);
            }

            return (hresult);
        }

    }; // class QualityAssuranceTestTextOptionsTestKeepProxy

    //
    // QualityAssurance::ITestTextOptions::ITestKeep::INotification interface proxy definitions
    //
    // Methods:
    //  (0) virtual void TestEvent(const uint32_t, const uint32_t, const QualityAssurance::ITestTextOptions::ITestKeep::TestDetails&, const QualityAssurance::ITestTextOptions::ITestKeep::EnumTextOptions) = 0
    //

    class QualityAssuranceTestTextOptionsTestKeepNotificationProxy final : public ProxyStub::UnknownProxyType<QualityAssurance::ITestTextOptions::ITestKeep::INotification> {
    public:
        QualityAssuranceTestTextOptionsTestKeepNotificationProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        void TestEvent(const uint32_t _firstTestParam, const uint32_t _secondTestParam, const QualityAssurance::ITestTextOptions::ITestKeep::TestDetails& _thirdTestParam, const QualityAssurance::ITestTextOptions::ITestKeep::EnumTextOptions _fourthTestParam) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_firstTestParam);
            writer.Number<uint32_t>(_secondTestParam);
            writer.Text(_thirdTestParam.testDetailsFirst);
            writer.Text(_thirdTestParam.testDetailsSecond);
            writer.Number<QualityAssurance::ITestTextOptions::ITestKeep::EnumTextOptions>(_fourthTestParam);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", QualityAssurance::ITestTextOptions::ITestKeep::INotification::ID, 0, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        }

    }; // class QualityAssuranceTestTextOptionsTestKeepNotificationProxy

    //
    // QualityAssurance::ITestTextOptions::ITestCustom interface proxy definitions
    //
    // Methods:
    //  (0) virtual Core::hresult TestCustom(const uint32_t, const uint32_t, const QualityAssurance::ITestTextOptions::ITestCustom::TestDetails&, const QualityAssurance::ITestTextOptions::ITestCustom::EnumTextOptions) = 0
    //

    class QualityAssuranceTestTextOptionsTestCustomProxy final : public ProxyStub::UnknownProxyType<QualityAssurance::ITestTextOptions::ITestCustom> {
    public:
        QualityAssuranceTestTextOptionsTestCustomProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        Core::hresult TestCustom(const uint32_t _firstTestParam, const uint32_t _secondTestParam, const QualityAssurance::ITestTextOptions::ITestCustom::TestDetails& _thirdTestParam, const QualityAssurance::ITestTextOptions::ITestCustom::EnumTextOptions _fourthTestParam) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_firstTestParam);
            writer.Number<uint32_t>(_secondTestParam);
            writer.Text(_thirdTestParam.testDetailsFirst);
            writer.Text(_thirdTestParam.testDetailsSecond);
            writer.Number<QualityAssurance::ITestTextOptions::ITestCustom::EnumTextOptions>(_fourthTestParam);

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
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", QualityAssurance::ITestTextOptions::ITestCustom::ID, 0, hresult);
            }

            return (hresult);
        }

    }; // class QualityAssuranceTestTextOptionsTestCustomProxy

    //
    // QualityAssurance::ITestTextOptions::ITestCustom::INotification interface proxy definitions
    //
    // Methods:
    //  (0) virtual void TestEvent(const uint32_t, const uint32_t, const QualityAssurance::ITestTextOptions::ITestCustom::TestDetails&, const QualityAssurance::ITestTextOptions::ITestCustom::EnumTextOptions) = 0
    //

    class QualityAssuranceTestTextOptionsTestCustomNotificationProxy final : public ProxyStub::UnknownProxyType<QualityAssurance::ITestTextOptions::ITestCustom::INotification> {
    public:
        QualityAssuranceTestTextOptionsTestCustomNotificationProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        void TestEvent(const uint32_t _firstTestParam, const uint32_t _secondTestParam, const QualityAssurance::ITestTextOptions::ITestCustom::TestDetails& _thirdTestParam, const QualityAssurance::ITestTextOptions::ITestCustom::EnumTextOptions _fourthTestParam) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_firstTestParam);
            writer.Number<uint32_t>(_secondTestParam);
            writer.Text(_thirdTestParam.testDetailsFirst);
            writer.Text(_thirdTestParam.testDetailsSecond);
            writer.Number<QualityAssurance::ITestTextOptions::ITestCustom::EnumTextOptions>(_fourthTestParam);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", QualityAssurance::ITestTextOptions::ITestCustom::INotification::ID, 0, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        }

    }; // class QualityAssuranceTestTextOptionsTestCustomNotificationProxy

    //
    // QualityAssurance::ITestUtils interface proxy definitions
    //
    // Methods:
    //  (0) virtual Core::hresult Crash() const = 0
    //

    class QualityAssuranceTestUtilsProxy final : public ProxyStub::UnknownProxyType<QualityAssurance::ITestUtils> {
    public:
        QualityAssuranceTestUtilsProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        Core::hresult Crash() const override
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
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", QualityAssurance::ITestUtils::ID, 0, hresult);
            }

            return (hresult);
        }

    }; // class QualityAssuranceTestUtilsProxy

    POP_WARNING()
    POP_WARNING()

    // -----------------------------------------------------------------
    // REGISTRATION
    // -----------------------------------------------------------------
    namespace {

        typedef ProxyStub::UnknownStubType<QualityAssurance::IMemory, QualityAssuranceMemoryStubMethods> QualityAssuranceMemoryStub;
        typedef ProxyStub::UnknownStubType<QualityAssurance::IComRpc, QualityAssuranceComRpcStubMethods> QualityAssuranceComRpcStub;
        typedef ProxyStub::UnknownStubType<QualityAssurance::IComRpc::IComRpcInternal, QualityAssuranceComRpcComRpcInternalStubMethods> QualityAssuranceComRpcComRpcInternalStub;
        typedef ProxyStub::UnknownStubType<QualityAssurance::ITestTextOptions, QualityAssuranceTestTextOptionsStubMethods> QualityAssuranceTestTextOptionsStub;
        typedef ProxyStub::UnknownStubType<QualityAssurance::ITestTextOptions::INotification, QualityAssuranceTestTextOptionsNotificationStubMethods> QualityAssuranceTestTextOptionsNotificationStub;
        typedef ProxyStub::UnknownStubType<QualityAssurance::ITestTextOptions::ITestLegacy, QualityAssuranceTestTextOptionsTestLegacyStubMethods> QualityAssuranceTestTextOptionsTestLegacyStub;
        typedef ProxyStub::UnknownStubType<QualityAssurance::ITestTextOptions::ITestLegacy::INotification, QualityAssuranceTestTextOptionsTestLegacyNotificationStubMethods> QualityAssuranceTestTextOptionsTestLegacyNotificationStub;
        typedef ProxyStub::UnknownStubType<QualityAssurance::ITestTextOptions::ITestKeep, QualityAssuranceTestTextOptionsTestKeepStubMethods> QualityAssuranceTestTextOptionsTestKeepStub;
        typedef ProxyStub::UnknownStubType<QualityAssurance::ITestTextOptions::ITestKeep::INotification, QualityAssuranceTestTextOptionsTestKeepNotificationStubMethods> QualityAssuranceTestTextOptionsTestKeepNotificationStub;
        typedef ProxyStub::UnknownStubType<QualityAssurance::ITestTextOptions::ITestCustom, QualityAssuranceTestTextOptionsTestCustomStubMethods> QualityAssuranceTestTextOptionsTestCustomStub;
        typedef ProxyStub::UnknownStubType<QualityAssurance::ITestTextOptions::ITestCustom::INotification, QualityAssuranceTestTextOptionsTestCustomNotificationStubMethods> QualityAssuranceTestTextOptionsTestCustomNotificationStub;
        typedef ProxyStub::UnknownStubType<QualityAssurance::ITestUtils, QualityAssuranceTestUtilsStubMethods> QualityAssuranceTestUtilsStub;

        static class Instantiation {
        public:
            Instantiation()
            {
                const RPC::SecureProxyStubType security = static_cast<RPC::SecureProxyStubType>(static_cast<std::underlying_type<RPC::SecureProxyStubType>::type>(RPC::SecureProxyStubType::PROXYSTUBS_SECURITY_SECURE) | static_cast<std::underlying_type<RPC::SecureProxyStubType>::type>(RPC::SecureProxyStubType::PROXYSTUBS_SECURITY_COHERENT));

                RPC::Administrator::Instance().Announce<QualityAssurance::IMemory, QualityAssuranceMemoryProxy, QualityAssuranceMemoryStub>(security);
                RPC::Administrator::Instance().Announce<QualityAssurance::IComRpc, QualityAssuranceComRpcProxy, QualityAssuranceComRpcStub>(security);
                RPC::Administrator::Instance().Announce<QualityAssurance::IComRpc::IComRpcInternal, QualityAssuranceComRpcComRpcInternalProxy, QualityAssuranceComRpcComRpcInternalStub>(security);
                RPC::Administrator::Instance().Announce<QualityAssurance::ITestTextOptions, QualityAssuranceTestTextOptionsProxy, QualityAssuranceTestTextOptionsStub>(security);
                RPC::Administrator::Instance().Announce<QualityAssurance::ITestTextOptions::INotification, QualityAssuranceTestTextOptionsNotificationProxy, QualityAssuranceTestTextOptionsNotificationStub>(security);
                RPC::Administrator::Instance().Announce<QualityAssurance::ITestTextOptions::ITestLegacy, QualityAssuranceTestTextOptionsTestLegacyProxy, QualityAssuranceTestTextOptionsTestLegacyStub>(security);
                RPC::Administrator::Instance().Announce<QualityAssurance::ITestTextOptions::ITestLegacy::INotification, QualityAssuranceTestTextOptionsTestLegacyNotificationProxy, QualityAssuranceTestTextOptionsTestLegacyNotificationStub>(security);
                RPC::Administrator::Instance().Announce<QualityAssurance::ITestTextOptions::ITestKeep, QualityAssuranceTestTextOptionsTestKeepProxy, QualityAssuranceTestTextOptionsTestKeepStub>(security);
                RPC::Administrator::Instance().Announce<QualityAssurance::ITestTextOptions::ITestKeep::INotification, QualityAssuranceTestTextOptionsTestKeepNotificationProxy, QualityAssuranceTestTextOptionsTestKeepNotificationStub>(security);
                RPC::Administrator::Instance().Announce<QualityAssurance::ITestTextOptions::ITestCustom, QualityAssuranceTestTextOptionsTestCustomProxy, QualityAssuranceTestTextOptionsTestCustomStub>(security);
                RPC::Administrator::Instance().Announce<QualityAssurance::ITestTextOptions::ITestCustom::INotification, QualityAssuranceTestTextOptionsTestCustomNotificationProxy, QualityAssuranceTestTextOptionsTestCustomNotificationStub>(security);
                RPC::Administrator::Instance().Announce<QualityAssurance::ITestUtils, QualityAssuranceTestUtilsProxy, QualityAssuranceTestUtilsStub>(security);
            }
            ~Instantiation()
            {
                RPC::Administrator::Instance().Recall<QualityAssurance::IMemory>();
                RPC::Administrator::Instance().Recall<QualityAssurance::IComRpc>();
                RPC::Administrator::Instance().Recall<QualityAssurance::IComRpc::IComRpcInternal>();
                RPC::Administrator::Instance().Recall<QualityAssurance::ITestTextOptions>();
                RPC::Administrator::Instance().Recall<QualityAssurance::ITestTextOptions::INotification>();
                RPC::Administrator::Instance().Recall<QualityAssurance::ITestTextOptions::ITestLegacy>();
                RPC::Administrator::Instance().Recall<QualityAssurance::ITestTextOptions::ITestLegacy::INotification>();
                RPC::Administrator::Instance().Recall<QualityAssurance::ITestTextOptions::ITestKeep>();
                RPC::Administrator::Instance().Recall<QualityAssurance::ITestTextOptions::ITestKeep::INotification>();
                RPC::Administrator::Instance().Recall<QualityAssurance::ITestTextOptions::ITestCustom>();
                RPC::Administrator::Instance().Recall<QualityAssurance::ITestTextOptions::ITestCustom::INotification>();
                RPC::Administrator::Instance().Recall<QualityAssurance::ITestUtils>();
            }
        } ProxyStubRegistration;

    } // namespace

} // namespace ProxyStubs

}
