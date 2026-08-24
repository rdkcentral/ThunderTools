//
// generated automatically from "ITestOptionals.h"
//
// implements COM-RPC proxy stubs for:
//   - class FunctionalTest::ITestOptionals
//

#include "ITestOptionals.h"

#include <com/com.h>

namespace Thunder {

namespace ProxyStubs {

    PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    // -----------------------------------------------------------------
    // STUBS
    // -----------------------------------------------------------------

    //
    // FunctionalTest::ITestOptionals interface stub definitions
    //
    // Methods:
    //  (0) virtual Core::hresult Add(const uint32_t, const Core::OptionalType<uint32_t>&, uint32_t&) = 0
    //  (1) virtual Core::hresult Multiply(const int32_t, const Core::OptionalType<int32_t>&, int32_t&) = 0
    //  (2) virtual Core::hresult Concatenate(const string&, const Core::OptionalType<string>&, string&) = 0
    //  (3) virtual Core::hresult Divide(const uint32_t, const uint32_t, uint32_t&, Core::OptionalType<uint32_t>&) = 0
    //  (4) virtual Core::hresult ParseInt(const string&, int32_t&, Core::OptionalType<bool>&) = 0
    //  (5) virtual Core::hresult Format(const string&, const Core::OptionalType<string>&, const Core::OptionalType<string>&, string&) = 0
    //  (6) virtual Core::hresult Calculate(const int32_t, const Core::OptionalType<int32_t>&, const Core::OptionalType<int32_t>&, int32_t&) = 0
    //  (7) virtual Core::hresult ProcessOptionalBuffer(const uint8_t*, const uint16_t, uint8_t*, const uint16_t, uint16_t&) = 0
    //  (8) virtual Core::hresult ProcessOptionalVector(const Core::OptionalType<std::vector<uint8_t>>&, Core::OptionalType<std::vector<uint8_t>>&) = 0
    //  (9) virtual Core::hresult ProcessOptionalInlineVector(Core::OptionalType<std::vector<uint8_t>>&, const bool) = 0
    //  (10) virtual Core::hresult ProcessOptionalVectorInOptionalStruct(const Core::OptionalType<FunctionalTest::ITestOptionals::Compound>&, Core::OptionalType<FunctionalTest::ITestOptionals::Compound>&) = 0
    //  (11) virtual Core::hresult ProcessOptionalVectorInOptionalInlineStruct(Core::OptionalType<FunctionalTest::ITestOptionals::Compound>&, const bool) = 0
    //  (12) virtual Core::hresult AllOptional(const Core::OptionalType<uint32_t>&, const Core::OptionalType<uint32_t>&, const Core::OptionalType<uint32_t>&, uint32_t&) = 0
    //  (13) virtual Core::hresult WithDefault(const string&, const Core::OptionalType<bool>&, string&) = 0
    //

    static ProxyStub::MethodHandler FunctionalTestTestOptionalsStubMethods[] = {
        // (0) virtual Core::hresult Add(const uint32_t, const Core::OptionalType<uint32_t>&, uint32_t&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            FunctionalTest::ITestOptionals* implementation = reinterpret_cast<FunctionalTest::ITestOptionals*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint32_t _a = reader.Number<uint32_t>();
            Core::OptionalType<uint32_t> _b{};
            if (reader.Boolean() == true) {
                _b = reader.Number<uint32_t>();
            }

            uint32_t _result{};

            Core::hresult result = implementation->Add(_a, static_cast<const Core::OptionalType<uint32_t>&>(_b), _result);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
            writer.Number<uint32_t>(_result);
        },

        // (1) virtual Core::hresult Multiply(const int32_t, const Core::OptionalType<int32_t>&, int32_t&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            FunctionalTest::ITestOptionals* implementation = reinterpret_cast<FunctionalTest::ITestOptionals*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const int32_t _value = reader.Number<int32_t>();
            Core::OptionalType<int32_t> _multiplier{};
            if (reader.Boolean() == true) {
                _multiplier = reader.Number<int32_t>();
            }

            int32_t _result{};

            Core::hresult result = implementation->Multiply(_value, static_cast<const Core::OptionalType<int32_t>&>(_multiplier), _result);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
            writer.Number<int32_t>(_result);
        },

        // (2) virtual Core::hresult Concatenate(const string&, const Core::OptionalType<string>&, string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            FunctionalTest::ITestOptionals* implementation = reinterpret_cast<FunctionalTest::ITestOptionals*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _first = reader.Text();
            Core::OptionalType<string> _second{};
            if (reader.Boolean() == true) {
                _second = reader.Text();
            }

            string _result{};

            Core::hresult result = implementation->Concatenate(static_cast<const string&>(_first), static_cast<const Core::OptionalType<string>&>(_second), _result);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
            writer.Text(_result);
        },

        // (3) virtual Core::hresult Divide(const uint32_t, const uint32_t, uint32_t&, Core::OptionalType<uint32_t>&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            FunctionalTest::ITestOptionals* implementation = reinterpret_cast<FunctionalTest::ITestOptionals*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint32_t _dividend = reader.Number<uint32_t>();
            const uint32_t _divisor = reader.Number<uint32_t>();
            Core::OptionalType<uint32_t> _remainder{};
            if (reader.Boolean() == true) {
                _remainder = reader.Number<uint32_t>();
            }

            uint32_t _quotient{};

            Core::hresult result = implementation->Divide(_dividend, _divisor, _quotient, _remainder);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
            writer.Number<uint32_t>(_quotient);
            writer.Boolean(_remainder.IsSet());
            if (_remainder.IsSet() == true) {
                writer.Number<uint32_t>(_remainder.Value());
            }
        },

        // (4) virtual Core::hresult ParseInt(const string&, int32_t&, Core::OptionalType<bool>&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            FunctionalTest::ITestOptionals* implementation = reinterpret_cast<FunctionalTest::ITestOptionals*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _text = reader.Text();
            Core::OptionalType<bool> _success{};
            if (reader.Boolean() == true) {
                _success = reader.Boolean();
            }

            int32_t _value{};

            Core::hresult result = implementation->ParseInt(static_cast<const string&>(_text), _value, _success);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
            writer.Number<int32_t>(_value);
            writer.Boolean(_success.IsSet());
            if (_success.IsSet() == true) {
                writer.Boolean(_success.Value());
            }
        },

        // (5) virtual Core::hresult Format(const string&, const Core::OptionalType<string>&, const Core::OptionalType<string>&, string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            FunctionalTest::ITestOptionals* implementation = reinterpret_cast<FunctionalTest::ITestOptionals*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _text = reader.Text();
            Core::OptionalType<string> _prefix{};
            if (reader.Boolean() == true) {
                _prefix = reader.Text();
            }
            Core::OptionalType<string> _suffix{};
            if (reader.Boolean() == true) {
                _suffix = reader.Text();
            }

            string _result{};

            Core::hresult result = implementation->Format(static_cast<const string&>(_text), static_cast<const Core::OptionalType<string>&>(_prefix), static_cast<const Core::OptionalType<string>&>(_suffix), _result);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
            writer.Text(_result);
        },

        // (6) virtual Core::hresult Calculate(const int32_t, const Core::OptionalType<int32_t>&, const Core::OptionalType<int32_t>&, int32_t&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            FunctionalTest::ITestOptionals* implementation = reinterpret_cast<FunctionalTest::ITestOptionals*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const int32_t _value = reader.Number<int32_t>();
            Core::OptionalType<int32_t> _min{};
            if (reader.Boolean() == true) {
                _min = reader.Number<int32_t>();
            }
            Core::OptionalType<int32_t> _max{};
            if (reader.Boolean() == true) {
                _max = reader.Number<int32_t>();
            }

            int32_t _result{};

            Core::hresult result = implementation->Calculate(_value, static_cast<const Core::OptionalType<int32_t>&>(_min), static_cast<const Core::OptionalType<int32_t>&>(_max), _result);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
            writer.Number<int32_t>(_result);
        },

        // (7) virtual Core::hresult ProcessOptionalBuffer(const uint8_t*, const uint16_t, uint8_t*, const uint16_t, uint16_t&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            FunctionalTest::ITestOptionals* implementation = reinterpret_cast<FunctionalTest::ITestOptionals*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint8_t* _input{};
            const uint16_t _inputSize = reader.LockBuffer<uint16_t>(_input);
            reader.UnlockBuffer(_inputSize);
            const uint16_t _maxOutputSize = reader.Number<uint16_t>();

            uint16_t _written{};
            uint8_t* _output{};

            if (_maxOutputSize != 0) {
                _output = static_cast<uint8_t*>(ALLOCA(_maxOutputSize * sizeof(uint8_t)));
                ASSERT(_output != nullptr);
            }

            Core::hresult result = implementation->ProcessOptionalBuffer(_input, _inputSize, _output, _maxOutputSize, _written);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
            writer.Buffer<uint16_t>(_written, _output);
        },

        // (8) virtual Core::hresult ProcessOptionalVector(const Core::OptionalType<std::vector<uint8_t>>&, Core::OptionalType<std::vector<uint8_t>>&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            FunctionalTest::ITestOptionals* implementation = reinterpret_cast<FunctionalTest::ITestOptionals*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            Core::OptionalType<std::vector<uint8_t>> _input{};
            if (reader.Boolean() == true) {
                std::vector<uint8_t> _inputObject__{};
                uint8_t _inputObject__Size = reader.Number<uint8_t>();
                ASSERT((_inputObject__Size >= 0) && (_inputObject__Size <= 8));
                _inputObject__.reserve(_inputObject__Size);
                for (uint8_t i = 0; i < _inputObject__Size; i++) {
                    uint8_t _inputObject__Item = reader.Number<uint8_t>();
                    _inputObject__.push_back(std::move(_inputObject__Item));
                }
                _input = std::move(_inputObject__);
            }

            Core::OptionalType<std::vector<uint8_t>> _output{};

            Core::hresult result = implementation->ProcessOptionalVector(static_cast<const Core::OptionalType<std::vector<uint8_t>>&>(_input), _output);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
            writer.Boolean(_output.IsSet());
            if (_output.IsSet() == true) {
                writer.Number<uint8_t>(_output.Value().size());
                for (uint8_t i = 0; i < _output.Value().size(); i++) {
                    writer.Number<uint8_t>(_output.Value()[i]);
                }
            }
        },

        // (9) virtual Core::hresult ProcessOptionalInlineVector(Core::OptionalType<std::vector<uint8_t>>&, const bool) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            FunctionalTest::ITestOptionals* implementation = reinterpret_cast<FunctionalTest::ITestOptionals*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            Core::OptionalType<std::vector<uint8_t>> _data{};
            if (reader.Boolean() == true) {
                std::vector<uint8_t> _dataObject__{};
                uint8_t _dataObject__Size = reader.Number<uint8_t>();
                ASSERT((_dataObject__Size >= 0) && (_dataObject__Size <= 8));
                _dataObject__.reserve(_dataObject__Size);
                for (uint8_t i = 0; i < _dataObject__Size; i++) {
                    uint8_t _dataObject__Item = reader.Number<uint8_t>();
                    _dataObject__.push_back(std::move(_dataObject__Item));
                }
                _data = std::move(_dataObject__);
            }
            const bool _unset = reader.Boolean();

            Core::hresult result = implementation->ProcessOptionalInlineVector(_data, _unset);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
            writer.Boolean(_data.IsSet());
            if (_data.IsSet() == true) {
                writer.Number<uint8_t>(_data.Value().size());
                for (uint8_t i = 0; i < _data.Value().size(); i++) {
                    writer.Number<uint8_t>(_data.Value()[i]);
                }
            }
        },

        // (10) virtual Core::hresult ProcessOptionalVectorInOptionalStruct(const Core::OptionalType<FunctionalTest::ITestOptionals::Compound>&, Core::OptionalType<FunctionalTest::ITestOptionals::Compound>&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            FunctionalTest::ITestOptionals* implementation = reinterpret_cast<FunctionalTest::ITestOptionals*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            Core::OptionalType<FunctionalTest::ITestOptionals::Compound> _input{};
            if (reader.Boolean() == true) {
                FunctionalTest::ITestOptionals::Compound _inputObject__{};
                _inputObject__.magic = reader.Text();
                if (reader.Boolean() == true) {
                    _inputObject__.optionalMagic = reader.Text();
                }
                uint8_t _inputObject___dataSize = reader.Number<uint8_t>();
                ASSERT((_inputObject___dataSize >= 0) && (_inputObject___dataSize <= 8));
                _inputObject__.data.reserve(_inputObject___dataSize);
                for (uint8_t i = 0; i < _inputObject___dataSize; i++) {
                    uint8_t _inputObject___dataItem = reader.Number<uint8_t>();
                    _inputObject__.data.push_back(std::move(_inputObject___dataItem));
                }
                if (reader.Boolean() == true) {
                    std::vector<uint8_t> _inputObject___optionalDataObject__{};
                    uint8_t _inputObject___optionalDataObject__Size = reader.Number<uint8_t>();
                    ASSERT((_inputObject___optionalDataObject__Size >= 0) && (_inputObject___optionalDataObject__Size <= 8));
                    _inputObject___optionalDataObject__.reserve(_inputObject___optionalDataObject__Size);
                    for (uint8_t i = 0; i < _inputObject___optionalDataObject__Size; i++) {
                        uint8_t _inputObject___optionalDataObject__Item = reader.Number<uint8_t>();
                        _inputObject___optionalDataObject__.push_back(std::move(_inputObject___optionalDataObject__Item));
                    }
                    _inputObject__.optionalData = std::move(_inputObject___optionalDataObject__);
                }
                _input = std::move(_inputObject__);
            }

            Core::OptionalType<FunctionalTest::ITestOptionals::Compound> _output{};

            Core::hresult result = implementation->ProcessOptionalVectorInOptionalStruct(static_cast<const Core::OptionalType<FunctionalTest::ITestOptionals::Compound>&>(_input), _output);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
            writer.Boolean(_output.IsSet());
            if (_output.IsSet() == true) {
                writer.Text(_output.Value().magic);
                writer.Boolean(_output.Value().optionalMagic.IsSet());
                if (_output.Value().optionalMagic.IsSet() == true) {
                    writer.Text(_output.Value().optionalMagic.Value());
                }
                writer.Number<uint8_t>(_output.Value().data.size());
                for (uint8_t i = 0; i < _output.Value().data.size(); i++) {
                    writer.Number<uint8_t>(_output.Value().data[i]);
                }
                writer.Boolean(_output.Value().optionalData.IsSet());
                if (_output.Value().optionalData.IsSet() == true) {
                    writer.Number<uint8_t>(_output.Value().optionalData.Value().size());
                    for (uint8_t i = 0; i < _output.Value().optionalData.Value().size(); i++) {
                        writer.Number<uint8_t>(_output.Value().optionalData.Value()[i]);
                    }
                }
            }
        },

        // (11) virtual Core::hresult ProcessOptionalVectorInOptionalInlineStruct(Core::OptionalType<FunctionalTest::ITestOptionals::Compound>&, const bool) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            FunctionalTest::ITestOptionals* implementation = reinterpret_cast<FunctionalTest::ITestOptionals*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            Core::OptionalType<FunctionalTest::ITestOptionals::Compound> _data{};
            if (reader.Boolean() == true) {
                FunctionalTest::ITestOptionals::Compound _dataObject__{};
                _dataObject__.magic = reader.Text();
                if (reader.Boolean() == true) {
                    _dataObject__.optionalMagic = reader.Text();
                }
                uint8_t _dataObject___dataSize = reader.Number<uint8_t>();
                ASSERT((_dataObject___dataSize >= 0) && (_dataObject___dataSize <= 8));
                _dataObject__.data.reserve(_dataObject___dataSize);
                for (uint8_t i = 0; i < _dataObject___dataSize; i++) {
                    uint8_t _dataObject___dataItem = reader.Number<uint8_t>();
                    _dataObject__.data.push_back(std::move(_dataObject___dataItem));
                }
                if (reader.Boolean() == true) {
                    std::vector<uint8_t> _dataObject___optionalDataObject__{};
                    uint8_t _dataObject___optionalDataObject__Size = reader.Number<uint8_t>();
                    ASSERT((_dataObject___optionalDataObject__Size >= 0) && (_dataObject___optionalDataObject__Size <= 8));
                    _dataObject___optionalDataObject__.reserve(_dataObject___optionalDataObject__Size);
                    for (uint8_t i = 0; i < _dataObject___optionalDataObject__Size; i++) {
                        uint8_t _dataObject___optionalDataObject__Item = reader.Number<uint8_t>();
                        _dataObject___optionalDataObject__.push_back(std::move(_dataObject___optionalDataObject__Item));
                    }
                    _dataObject__.optionalData = std::move(_dataObject___optionalDataObject__);
                }
                _data = std::move(_dataObject__);
            }
            const bool _unset = reader.Boolean();

            Core::hresult result = implementation->ProcessOptionalVectorInOptionalInlineStruct(_data, _unset);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
            writer.Boolean(_data.IsSet());
            if (_data.IsSet() == true) {
                writer.Text(_data.Value().magic);
                writer.Boolean(_data.Value().optionalMagic.IsSet());
                if (_data.Value().optionalMagic.IsSet() == true) {
                    writer.Text(_data.Value().optionalMagic.Value());
                }
                writer.Number<uint8_t>(_data.Value().data.size());
                for (uint8_t i = 0; i < _data.Value().data.size(); i++) {
                    writer.Number<uint8_t>(_data.Value().data[i]);
                }
                writer.Boolean(_data.Value().optionalData.IsSet());
                if (_data.Value().optionalData.IsSet() == true) {
                    writer.Number<uint8_t>(_data.Value().optionalData.Value().size());
                    for (uint8_t i = 0; i < _data.Value().optionalData.Value().size(); i++) {
                        writer.Number<uint8_t>(_data.Value().optionalData.Value()[i]);
                    }
                }
            }
        },

        // (12) virtual Core::hresult AllOptional(const Core::OptionalType<uint32_t>&, const Core::OptionalType<uint32_t>&, const Core::OptionalType<uint32_t>&, uint32_t&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            FunctionalTest::ITestOptionals* implementation = reinterpret_cast<FunctionalTest::ITestOptionals*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            Core::OptionalType<uint32_t> _a{};
            if (reader.Boolean() == true) {
                _a = reader.Number<uint32_t>();
            }
            Core::OptionalType<uint32_t> _b{};
            if (reader.Boolean() == true) {
                _b = reader.Number<uint32_t>();
            }
            Core::OptionalType<uint32_t> _c{};
            if (reader.Boolean() == true) {
                _c = reader.Number<uint32_t>();
            }

            uint32_t _result{};

            Core::hresult result = implementation->AllOptional(static_cast<const Core::OptionalType<uint32_t>&>(_a), static_cast<const Core::OptionalType<uint32_t>&>(_b), static_cast<const Core::OptionalType<uint32_t>&>(_c), _result);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
            writer.Number<uint32_t>(_result);
        },

        // (13) virtual Core::hresult WithDefault(const string&, const Core::OptionalType<bool>&, string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            FunctionalTest::ITestOptionals* implementation = reinterpret_cast<FunctionalTest::ITestOptionals*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _value = reader.Text();
            Core::OptionalType<bool> _uppercase{};
            if (reader.Boolean() == true) {
                _uppercase = reader.Boolean();
            }

            string _result{};

            Core::hresult result = implementation->WithDefault(static_cast<const string&>(_value), static_cast<const Core::OptionalType<bool>&>(_uppercase), _result);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
            writer.Text(_result);
        }
        , nullptr
    }; // FunctionalTestTestOptionalsStubMethods

    // -----------------------------------------------------------------
    // PROXIES
    // -----------------------------------------------------------------

    //
    // FunctionalTest::ITestOptionals interface proxy definitions
    //
    // Methods:
    //  (0) virtual Core::hresult Add(const uint32_t, const Core::OptionalType<uint32_t>&, uint32_t&) = 0
    //  (1) virtual Core::hresult Multiply(const int32_t, const Core::OptionalType<int32_t>&, int32_t&) = 0
    //  (2) virtual Core::hresult Concatenate(const string&, const Core::OptionalType<string>&, string&) = 0
    //  (3) virtual Core::hresult Divide(const uint32_t, const uint32_t, uint32_t&, Core::OptionalType<uint32_t>&) = 0
    //  (4) virtual Core::hresult ParseInt(const string&, int32_t&, Core::OptionalType<bool>&) = 0
    //  (5) virtual Core::hresult Format(const string&, const Core::OptionalType<string>&, const Core::OptionalType<string>&, string&) = 0
    //  (6) virtual Core::hresult Calculate(const int32_t, const Core::OptionalType<int32_t>&, const Core::OptionalType<int32_t>&, int32_t&) = 0
    //  (7) virtual Core::hresult ProcessOptionalBuffer(const uint8_t*, const uint16_t, uint8_t*, const uint16_t, uint16_t&) = 0
    //  (8) virtual Core::hresult ProcessOptionalVector(const Core::OptionalType<std::vector<uint8_t>>&, Core::OptionalType<std::vector<uint8_t>>&) = 0
    //  (9) virtual Core::hresult ProcessOptionalInlineVector(Core::OptionalType<std::vector<uint8_t>>&, const bool) = 0
    //  (10) virtual Core::hresult ProcessOptionalVectorInOptionalStruct(const Core::OptionalType<FunctionalTest::ITestOptionals::Compound>&, Core::OptionalType<FunctionalTest::ITestOptionals::Compound>&) = 0
    //  (11) virtual Core::hresult ProcessOptionalVectorInOptionalInlineStruct(Core::OptionalType<FunctionalTest::ITestOptionals::Compound>&, const bool) = 0
    //  (12) virtual Core::hresult AllOptional(const Core::OptionalType<uint32_t>&, const Core::OptionalType<uint32_t>&, const Core::OptionalType<uint32_t>&, uint32_t&) = 0
    //  (13) virtual Core::hresult WithDefault(const string&, const Core::OptionalType<bool>&, string&) = 0
    //

    class FunctionalTestTestOptionalsProxy final : public ProxyStub::UnknownProxyType<FunctionalTest::ITestOptionals> {
    public:
        FunctionalTestTestOptionalsProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        Core::hresult Add(const uint32_t _a, const Core::OptionalType<uint32_t>& _b, uint32_t& _result) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_a);
            writer.Boolean(_b.IsSet());
            if (_b.IsSet() == true) {
                writer.Number<uint32_t>(_b.Value());
            }

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
                _result = reader.Number<uint32_t>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        Core::hresult Multiply(const int32_t _value, const Core::OptionalType<int32_t>& _multiplier, int32_t& _result) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<int32_t>(_value);
            writer.Boolean(_multiplier.IsSet());
            if (_multiplier.IsSet() == true) {
                writer.Number<int32_t>(_multiplier.Value());
            }

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
                _result = reader.Number<int32_t>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        Core::hresult Concatenate(const string& _first, const Core::OptionalType<string>& _second, string& _result) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(2));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_first);
            writer.Boolean(_second.IsSet());
            if (_second.IsSet() == true) {
                writer.Text(_second.Value());
            }

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
                _result = reader.Text();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        Core::hresult Divide(const uint32_t _dividend, const uint32_t _divisor, uint32_t& _quotient, Core::OptionalType<uint32_t>& _remainder) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(3));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_dividend);
            writer.Number<uint32_t>(_divisor);
            writer.Boolean(_remainder.IsSet());
            if (_remainder.IsSet() == true) {
                writer.Number<uint32_t>(_remainder.Value());
            }

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
                _quotient = reader.Number<uint32_t>();
                if (reader.Boolean() == true) {
                    _remainder = reader.Number<uint32_t>();
                }
                else {
                    _remainder = Core::OptionalType<uint32_t>();
                }
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        Core::hresult ParseInt(const string& _text, int32_t& _value, Core::OptionalType<bool>& _success) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(4));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_text);
            writer.Boolean(_success.IsSet());
            if (_success.IsSet() == true) {
                writer.Boolean(_success.Value());
            }

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
                _value = reader.Number<int32_t>();
                if (reader.Boolean() == true) {
                    _success = reader.Boolean();
                }
                else {
                    _success = Core::OptionalType<bool>();
                }
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        Core::hresult Format(const string& _text, const Core::OptionalType<string>& _prefix, const Core::OptionalType<string>& _suffix, string& _result) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(5));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_text);
            writer.Boolean(_prefix.IsSet());
            if (_prefix.IsSet() == true) {
                writer.Text(_prefix.Value());
            }
            writer.Boolean(_suffix.IsSet());
            if (_suffix.IsSet() == true) {
                writer.Text(_suffix.Value());
            }

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
                _result = reader.Text();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        Core::hresult Calculate(const int32_t _value, const Core::OptionalType<int32_t>& _min, const Core::OptionalType<int32_t>& _max, int32_t& _result) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(6));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<int32_t>(_value);
            writer.Boolean(_min.IsSet());
            if (_min.IsSet() == true) {
                writer.Number<int32_t>(_min.Value());
            }
            writer.Boolean(_max.IsSet());
            if (_max.IsSet() == true) {
                writer.Number<int32_t>(_max.Value());
            }

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
                _result = reader.Number<int32_t>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        Core::hresult ProcessOptionalBuffer(const uint8_t* _input, const uint16_t _inputSize, uint8_t* _output, const uint16_t _maxOutputSize, uint16_t& _written) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(7));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Buffer<uint16_t>(_inputSize, _input);
            writer.Number<uint16_t>(_maxOutputSize);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
                _written = reader.Buffer<uint16_t>(_maxOutputSize, _output);
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        Core::hresult ProcessOptionalVector(const Core::OptionalType<std::vector<uint8_t>>& _input, Core::OptionalType<std::vector<uint8_t>>& _output) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(8));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Boolean(_input.IsSet());
            if (_input.IsSet() == true) {
                writer.Number<uint8_t>(_input.Value().size());
                for (uint8_t i = 0; i < _input.Value().size(); i++) {
                    writer.Number<uint8_t>(_input.Value()[i]);
                }
            }

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
                if (reader.Boolean() == true) {
                    std::vector<uint8_t> _outputObject__{};
                    uint8_t _outputSize{};
                    _outputSize = reader.Number<uint8_t>();
                    _outputObject__.reserve(_outputSize);
                    for (uint8_t i = 0; i < _outputSize; i++) {
                        uint8_t _outputItem{};
                        _outputItem = reader.Number<uint8_t>();
                        _outputObject__.push_back(std::move(_outputItem));
                    }
                    _output = std::move(_outputObject__);
                }
                else {
                    _output = Core::OptionalType<std::vector<uint8_t>>();
                }
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        Core::hresult ProcessOptionalInlineVector(Core::OptionalType<std::vector<uint8_t>>& _data, const bool _unset) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(9));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Boolean(_data.IsSet());
            if (_data.IsSet() == true) {
                writer.Number<uint8_t>(_data.Value().size());
                for (uint8_t i = 0; i < _data.Value().size(); i++) {
                    writer.Number<uint8_t>(_data.Value()[i]);
                }
            }
            writer.Boolean(_unset);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
                if (reader.Boolean() == true) {
                    std::vector<uint8_t> _dataObject__{};
                    uint8_t _dataSize{};
                    _dataSize = reader.Number<uint8_t>();
                    _dataObject__.reserve(_dataSize);
                    for (uint8_t i = 0; i < _dataSize; i++) {
                        uint8_t _dataItem{};
                        _dataItem = reader.Number<uint8_t>();
                        _dataObject__.push_back(std::move(_dataItem));
                    }
                    _data = std::move(_dataObject__);
                }
                else {
                    _data = Core::OptionalType<std::vector<uint8_t>>();
                }
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        Core::hresult ProcessOptionalVectorInOptionalStruct(const Core::OptionalType<FunctionalTest::ITestOptionals::Compound>& _input, Core::OptionalType<FunctionalTest::ITestOptionals::Compound>& _output) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(10));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Boolean(_input.IsSet());
            if (_input.IsSet() == true) {
                writer.Text(_input.Value().magic);
                writer.Boolean(_input.Value().optionalMagic.IsSet());
                if (_input.Value().optionalMagic.IsSet() == true) {
                    writer.Text(_input.Value().optionalMagic.Value());
                }
                writer.Number<uint8_t>(_input.Value().data.size());
                for (uint8_t i = 0; i < _input.Value().data.size(); i++) {
                    writer.Number<uint8_t>(_input.Value().data[i]);
                }
                writer.Boolean(_input.Value().optionalData.IsSet());
                if (_input.Value().optionalData.IsSet() == true) {
                    writer.Number<uint8_t>(_input.Value().optionalData.Value().size());
                    for (uint8_t i = 0; i < _input.Value().optionalData.Value().size(); i++) {
                        writer.Number<uint8_t>(_input.Value().optionalData.Value()[i]);
                    }
                }
            }

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
                if (reader.Boolean() == true) {
                    FunctionalTest::ITestOptionals::Compound _outputObject__{};
                    _outputObject__.magic = reader.Text();
                    if (reader.Boolean() == true) {
                        _outputObject__.optionalMagic = reader.Text();
                    }
                    else {
                        _outputObject__.optionalMagic = Core::OptionalType<string>();
                    }
                    uint8_t _outputObject___dataSize{};
                    _outputObject___dataSize = reader.Number<uint8_t>();
                    _outputObject__.data.clear();
                    _outputObject__.data.reserve(_outputObject___dataSize);
                    for (uint8_t i = 0; i < _outputObject___dataSize; i++) {
                        uint8_t _outputObject___dataItem{};
                        _outputObject___dataItem = reader.Number<uint8_t>();
                        _outputObject__.data.push_back(std::move(_outputObject___dataItem));
                    }
                    if (reader.Boolean() == true) {
                        std::vector<uint8_t> _outputObject___optionalDataObject__{};
                        uint8_t _outputObject___optionalDataSize{};
                        _outputObject___optionalDataSize = reader.Number<uint8_t>();
                        _outputObject___optionalDataObject__.reserve(_outputObject___optionalDataSize);
                        for (uint8_t i = 0; i < _outputObject___optionalDataSize; i++) {
                            uint8_t _outputObject___optionalDataItem{};
                            _outputObject___optionalDataItem = reader.Number<uint8_t>();
                            _outputObject___optionalDataObject__.push_back(std::move(_outputObject___optionalDataItem));
                        }
                        _outputObject__.optionalData = std::move(_outputObject___optionalDataObject__);
                    }
                    else {
                        _outputObject__.optionalData = Core::OptionalType<std::vector<uint8_t>>();
                    }
                    _output = std::move(_outputObject__);
                }
                else {
                    _output = Core::OptionalType<FunctionalTest::ITestOptionals::Compound>();
                }
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        Core::hresult ProcessOptionalVectorInOptionalInlineStruct(Core::OptionalType<FunctionalTest::ITestOptionals::Compound>& _data, const bool _unset) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(11));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Boolean(_data.IsSet());
            if (_data.IsSet() == true) {
                writer.Text(_data.Value().magic);
                writer.Boolean(_data.Value().optionalMagic.IsSet());
                if (_data.Value().optionalMagic.IsSet() == true) {
                    writer.Text(_data.Value().optionalMagic.Value());
                }
                writer.Number<uint8_t>(_data.Value().data.size());
                for (uint8_t i = 0; i < _data.Value().data.size(); i++) {
                    writer.Number<uint8_t>(_data.Value().data[i]);
                }
                writer.Boolean(_data.Value().optionalData.IsSet());
                if (_data.Value().optionalData.IsSet() == true) {
                    writer.Number<uint8_t>(_data.Value().optionalData.Value().size());
                    for (uint8_t i = 0; i < _data.Value().optionalData.Value().size(); i++) {
                        writer.Number<uint8_t>(_data.Value().optionalData.Value()[i]);
                    }
                }
            }
            writer.Boolean(_unset);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
                if (reader.Boolean() == true) {
                    FunctionalTest::ITestOptionals::Compound _dataObject__{};
                    _dataObject__.magic = reader.Text();
                    if (reader.Boolean() == true) {
                        _dataObject__.optionalMagic = reader.Text();
                    }
                    else {
                        _dataObject__.optionalMagic = Core::OptionalType<string>();
                    }
                    uint8_t _dataObject___dataSize{};
                    _dataObject___dataSize = reader.Number<uint8_t>();
                    _dataObject__.data.clear();
                    _dataObject__.data.reserve(_dataObject___dataSize);
                    for (uint8_t i = 0; i < _dataObject___dataSize; i++) {
                        uint8_t _dataObject___dataItem{};
                        _dataObject___dataItem = reader.Number<uint8_t>();
                        _dataObject__.data.push_back(std::move(_dataObject___dataItem));
                    }
                    if (reader.Boolean() == true) {
                        std::vector<uint8_t> _dataObject___optionalDataObject__{};
                        uint8_t _dataObject___optionalDataSize{};
                        _dataObject___optionalDataSize = reader.Number<uint8_t>();
                        _dataObject___optionalDataObject__.reserve(_dataObject___optionalDataSize);
                        for (uint8_t i = 0; i < _dataObject___optionalDataSize; i++) {
                            uint8_t _dataObject___optionalDataItem{};
                            _dataObject___optionalDataItem = reader.Number<uint8_t>();
                            _dataObject___optionalDataObject__.push_back(std::move(_dataObject___optionalDataItem));
                        }
                        _dataObject__.optionalData = std::move(_dataObject___optionalDataObject__);
                    }
                    else {
                        _dataObject__.optionalData = Core::OptionalType<std::vector<uint8_t>>();
                    }
                    _data = std::move(_dataObject__);
                }
                else {
                    _data = Core::OptionalType<FunctionalTest::ITestOptionals::Compound>();
                }
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        Core::hresult AllOptional(const Core::OptionalType<uint32_t>& _a, const Core::OptionalType<uint32_t>& _b, const Core::OptionalType<uint32_t>& _c, uint32_t& _result) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(12));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Boolean(_a.IsSet());
            if (_a.IsSet() == true) {
                writer.Number<uint32_t>(_a.Value());
            }
            writer.Boolean(_b.IsSet());
            if (_b.IsSet() == true) {
                writer.Number<uint32_t>(_b.Value());
            }
            writer.Boolean(_c.IsSet());
            if (_c.IsSet() == true) {
                writer.Number<uint32_t>(_c.Value());
            }

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
                _result = reader.Number<uint32_t>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        Core::hresult WithDefault(const string& _value, const Core::OptionalType<bool>& _uppercase, string& _result) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(13));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_value);
            writer.Boolean(_uppercase.IsSet());
            if (_uppercase.IsSet() == true) {
                writer.Boolean(_uppercase.Value());
            }

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
                _result = reader.Text();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

    }; // class FunctionalTestTestOptionalsProxy

    POP_WARNING()
    POP_WARNING()

    // -----------------------------------------------------------------
    // REGISTRATION
    // -----------------------------------------------------------------
    namespace {

        typedef ProxyStub::UnknownStubType<FunctionalTest::ITestOptionals, FunctionalTestTestOptionalsStubMethods> FunctionalTestTestOptionalsStub;

        static class Instantiation {
        public:
            Instantiation()
            {
                RPC::Administrator::Instance().Announce<FunctionalTest::ITestOptionals, FunctionalTestTestOptionalsProxy, FunctionalTestTestOptionalsStub>();
            }
            ~Instantiation()
            {
                RPC::Administrator::Instance().Recall<FunctionalTest::ITestOptionals>();
            }
        } ProxyStubRegistration;

    } // namespace

} // namespace ProxyStubs

}
