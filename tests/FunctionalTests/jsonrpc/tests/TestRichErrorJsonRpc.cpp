/*
 * If not stated otherwise in this file or this component's LICENSE file the
 * following copyright and licenses apply:
 *
 * Copyright 2026 Metrological
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <gtest/gtest.h>
#include "JsonRpcTestHarness.h"
#include <ITestRichError.h>

using namespace Thunder;

namespace {

    class ErrorContextJson : public Core::JSON::Container {
    public:
        ErrorContextJson()
            : Core::JSON::Container()
            , Subcode(0)
            , Reason()
        {
            Add(_T("subcode"), &Subcode);
            Add(_T("reason"), &Reason);
        }

        ErrorContextJson(const ErrorContextJson& copy)
            : Core::JSON::Container()
            , Subcode(copy.Subcode)
            , Reason(copy.Reason)
        {
            Add(_T("subcode"), &Subcode);
            Add(_T("reason"), &Reason);
        }

        ~ErrorContextJson() override = default;

        Core::JSON::DecUInt16 Subcode;
        Core::JSON::String Reason;
    };

    Core::JSONRPC::Message::Info ParseError(const string& response)
    {
        Core::JSONRPC::Message::Info error;
        Core::OptionalType<Core::JSON::Error> report;
        error.FromString(response, report);
        EXPECT_FALSE(report.IsSet()) << "Response: " << response;
        return (error);
    }

    Core::JSONRPC::Message::Info ExpectedError(const uint32_t result)
    {
        Core::JSONRPC::Message::Info error;
        error.SetError(result);
        return (error);
    }

    ErrorContextJson ParseData(const Core::JSONRPC::Message::Info& error)
    {
        ErrorContextJson data;
        Core::OptionalType<Core::JSON::Error> report;
        data.FromString(error.Data.Value(), report);
        EXPECT_FALSE(report.IsSet()) << "Data: " << error.Data.Value();
        return (data);
    }

    string ParseStringData(const Core::JSONRPC::Message::Info& error)
    {
        Core::JSON::String data;
        Core::OptionalType<Core::JSON::Error> report;
        data.FromString(error.Data.Value(), report);
        EXPECT_FALSE(report.IsSet()) << "Data: " << error.Data.Value();
        return (data.Value());
    }

} // namespace

class TestRichErrorJsonRpc : public JsonRpcTesting::JsonRpcTestHarness {
};

TEST_F(TestRichErrorJsonRpc, Plain_DataOnlyPreservesThunderCodeAndMessage)
{
    string response;
    const uint32_t result = CallMethod("plain", string(), response);
    const Core::JSONRPC::Message::Info error(ParseError(response));
    const Core::JSONRPC::Message::Info expected(ExpectedError(result));
    const ErrorContextJson data(ParseData(error));

    EXPECT_EQ(result, Core::ERROR_UNAVAILABLE);
    EXPECT_EQ(error.Code.Value(), expected.Code.Value());
    EXPECT_EQ(error.Text.Value(), expected.Text.Value());
    EXPECT_EQ(data.Subcode.Value(), 21);
    EXPECT_EQ(data.Reason.Value(), string("plain data"));
}

TEST_F(TestRichErrorJsonRpc, Inbound_DataOnlyPreservesThunderCodeAndMessage)
{
    string response;
    const uint32_t result = CallMethod("inbound", R"({"input":"data-only"})", response);
    const Core::JSONRPC::Message::Info error(ParseError(response));
    const Core::JSONRPC::Message::Info expected(ExpectedError(result));
    const ErrorContextJson data(ParseData(error));

    EXPECT_EQ(result, Core::ERROR_BAD_REQUEST);
    EXPECT_EQ(error.Code.Value(), expected.Code.Value());
    EXPECT_EQ(error.Text.Value(), expected.Text.Value());
    EXPECT_EQ(data.Subcode.Value(), 42);
    EXPECT_EQ(data.Reason.Value(), string("inbound data"));
}

TEST_F(TestRichErrorJsonRpc, Inbound_NoDetailsLeavesResponseEmpty)
{
    string response;
    const uint32_t result = CallMethod("inbound", R"({"input":"no-details"})", response);

    EXPECT_EQ(result, Core::ERROR_GENERAL);
    EXPECT_TRUE(response.empty());
}

TEST_F(TestRichErrorJsonRpc, Outbound_CodeOnlyPreservesThunderMessageAndSuppressesOutput)
{
    string response;
    const uint32_t result = CallMethod("outbound", string(), response);
    const Core::JSONRPC::Message::Info error(ParseError(response));
    const Core::JSONRPC::Message::Info expected(ExpectedError(result));

    EXPECT_EQ(result, Core::ERROR_GENERAL);
    EXPECT_EQ(error.Code.Value(), -32042);
    EXPECT_EQ(error.Text.Value(), expected.Text.Value());
    EXPECT_EQ(response.find("must not be returned"), string::npos);
}

TEST_F(TestRichErrorJsonRpc, Transform_SuccessReturnsOutput)
{
    string response;
    const uint32_t result = CallMethod("transform", R"({"input":"request"})", response);

    EXPECT_EQ(result, Core::ERROR_NONE);
    EXPECT_EQ(response, R"("request transformed")");
}

TEST_F(TestRichErrorJsonRpc, Transform_MessageOnlyPreservesThunderCode)
{
    string response;
    const uint32_t result = CallMethod("transform", R"({"input":"message-only"})", response);
    const Core::JSONRPC::Message::Info error(ParseError(response));
    const Core::JSONRPC::Message::Info expected(ExpectedError(result));

    EXPECT_EQ(result, Core::ERROR_UNAVAILABLE);
    EXPECT_EQ(error.Code.Value(), expected.Code.Value());
    EXPECT_EQ(error.Text.Value(), string("transform message"));
}

TEST_F(TestRichErrorJsonRpc, Transform_FullErrorSerializesAllFields)
{
    string response;
    const uint32_t result = CallMethod("transform", R"({"input":"full-error"})", response);
    const Core::JSONRPC::Message::Info error(ParseError(response));
    const ErrorContextJson data(ParseData(error));

    EXPECT_EQ(result, Core::ERROR_BAD_REQUEST);
    EXPECT_EQ(error.Code.Value(), -32084);
    EXPECT_EQ(error.Text.Value(), string("transform full error"));
    EXPECT_EQ(data.Subcode.Value(), 84);
    EXPECT_EQ(data.Reason.Value(), string("transform data"));
}

TEST_F(TestRichErrorJsonRpc, InboundVoid_CodeOnlyOmitsDataAndPreservesThunderMessage)
{
    string response;
    const uint32_t result = CallMethod("inboundVoid", R"({"input":"code-only"})", response);
    const Core::JSONRPC::Message::Info error(ParseError(response));
    const Core::JSONRPC::Message::Info expected(ExpectedError(result));

    EXPECT_EQ(result, Core::ERROR_BAD_REQUEST);
    EXPECT_EQ(error.Code.Value(), -32110);
    EXPECT_EQ(error.Text.Value(), expected.Text.Value());
    EXPECT_FALSE(error.Data.IsSet());
}

TEST_F(TestRichErrorJsonRpc, InboundVoidNoArg_MessageOnlyOmitsDataAndPreservesThunderCode)
{
    string response;
    const uint32_t result = CallMethod("inboundVoidNoArg", R"({"input":"message-only"})", response);
    const Core::JSONRPC::Message::Info error(ParseError(response));
    const Core::JSONRPC::Message::Info expected(ExpectedError(result));

    EXPECT_EQ(result, Core::ERROR_UNAVAILABLE);
    EXPECT_EQ(error.Code.Value(), expected.Code.Value());
    EXPECT_EQ(error.Text.Value(), string("void default message"));
    EXPECT_FALSE(error.Data.IsSet());
}

TEST_F(TestRichErrorJsonRpc, InboundAlias_DataOnlyResolvesAliasAndPreservesDefaults)
{
    string response;
    const uint32_t result = CallMethod("inboundAlias", R"({"input":"data-only"})", response);
    const Core::JSONRPC::Message::Info error(ParseError(response));
    const Core::JSONRPC::Message::Info expected(ExpectedError(result));
    const ErrorContextJson data(ParseData(error));

    EXPECT_EQ(result, Core::ERROR_BAD_REQUEST);
    EXPECT_EQ(error.Code.Value(), expected.Code.Value());
    EXPECT_EQ(error.Text.Value(), expected.Text.Value());
    EXPECT_EQ(data.Subcode.Value(), 63);
    EXPECT_EQ(data.Reason.Value(), string("alias data"));
}

TEST_F(TestRichErrorJsonRpc, InboundAliasOpt_FullErrorResolvesOptionalAlias)
{
    string response;
    const uint32_t result = CallMethod("inboundAliasOpt", R"({"input":"full-error"})", response);
    const Core::JSONRPC::Message::Info error(ParseError(response));
    const ErrorContextJson data(ParseData(error));

    EXPECT_EQ(result, Core::ERROR_GENERAL);
    EXPECT_EQ(error.Code.Value(), -32164);
    EXPECT_EQ(error.Text.Value(), string("optional alias message"));
    EXPECT_EQ(data.Subcode.Value(), 64);
    EXPECT_EQ(data.Reason.Value(), string("optional alias data"));
}

TEST_F(TestRichErrorJsonRpc, InboundString_DataOnlySerializesStringAndPreservesDefaults)
{
    string response;
    const uint32_t result = CallMethod("inboundString", R"({"input":"data-only"})", response);
    const Core::JSONRPC::Message::Info error(ParseError(response));
    const Core::JSONRPC::Message::Info expected(ExpectedError(result));

    EXPECT_EQ(result, Core::ERROR_BAD_REQUEST);
    EXPECT_EQ(error.Code.Value(), expected.Code.Value());
    EXPECT_EQ(error.Text.Value(), expected.Text.Value());
    EXPECT_EQ(ParseStringData(error), string("string error data"));
}

TEST_F(TestRichErrorJsonRpc, InboundString_SuccessLeavesResponseEmpty)
{
    string response;
    const uint32_t result = CallMethod("inboundString", R"({"input":"success"})", response);

    EXPECT_EQ(result, Core::ERROR_NONE);
    EXPECT_TRUE(response.empty());
}
