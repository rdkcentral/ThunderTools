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

#include <ImplementationFactory.h>
#include <ITestRichError.h>

namespace Thunder {
namespace TestImplementation {

    class TestRichErrorImpl : public FunctionalTest::ITestRichError {
    private:
        using ErrorAlias = FunctionalTest::ITestRichError::ErrorAlias;
        using Details = Core::OptionalType<Core::ErrorDetails<FunctionalTest::ITestRichError::ErrorContext>>;
        using VoidDetails = Core::OptionalType<Core::ErrorDetails<void>>;
        using AliasDetails = Core::OptionalType<ErrorAlias>;
        using OptionalAliasDetails = FunctionalTest::ITestRichError::OptErrorAlias;
        using StringDetails = Core::OptionalType<Core::ErrorDetails<string>>;

        static Core::ErrorDetails<FunctionalTest::ITestRichError::ErrorContext>& SetDetails(Details& details)
        {
            details = Core::ErrorDetails<FunctionalTest::ITestRichError::ErrorContext>();
            return (details.Value());
        }

        static void SetData(Details& details, const uint16_t subcode, const string& reason)
        {
            FunctionalTest::ITestRichError::ErrorContext context;
            context.subcode = subcode;
            context.reason = reason;
            SetDetails(details).data = context;
        }

        static Core::ErrorDetails<void>& SetDetails(VoidDetails& details)
        {
            details = Core::ErrorDetails<void>();
            return (details.Value());
        }

        static Core::ErrorDetails<string>& SetDetails(StringDetails& details)
        {
            details = Core::ErrorDetails<string>();
            return (details.Value());
        }

    public:
        TestRichErrorImpl() = default;

        ~TestRichErrorImpl() override = default;

        TestRichErrorImpl(const TestRichErrorImpl&) = delete;
        TestRichErrorImpl& operator=(const TestRichErrorImpl&) = delete;

        Core::hresult Plain(Details& errorDetails) override
        {
            SetData(errorDetails, 21, _T("plain data"));
            return (Core::ERROR_UNAVAILABLE);
        }

        Core::hresult Inbound(const string& input, Details& errorDetails) override
        {
            Core::hresult result = Core::ERROR_NONE;

            if (input == _T("data-only")) {
                SetData(errorDetails, 42, _T("inbound data"));
                result = Core::ERROR_BAD_REQUEST;
            }
            else if (input == _T("message-only")) {
                SetDetails(errorDetails).message = _T("inbound message");
                result = Core::ERROR_UNAVAILABLE;
            }
            else if (input == _T("no-details")) {
                result = Core::ERROR_GENERAL;
            }

            return (result);
        }

        Core::hresult Outbound(string& output, Details& errorDetails) override
        {
            output = _T("must not be returned");
            SetDetails(errorDetails).code = -32042;
            return (Core::ERROR_GENERAL);
        }

        Core::hresult Transform(const string& input, string& output, Details& errorDetails) override
        {
            Core::hresult result = Core::ERROR_NONE;

            if (input == _T("message-only")) {
                SetDetails(errorDetails).message = _T("transform message");
                result = Core::ERROR_UNAVAILABLE;
            }
            else if (input == _T("full-error")) {
                Core::ErrorDetails<FunctionalTest::ITestRichError::ErrorContext>& details(SetDetails(errorDetails));
                FunctionalTest::ITestRichError::ErrorContext context;
                context.subcode = 84;
                context.reason = _T("transform data");
                details.code = -32084;
                details.message = _T("transform full error");
                details.data = context;
                result = Core::ERROR_BAD_REQUEST;
            }
            else {
                output = input + _T(" transformed");
            }

            return (result);
        }

        Core::hresult InboundVoid(const string& input, VoidDetails& errorDetails) override
        {
            Core::hresult result = Core::ERROR_NONE;

            if (input == _T("code-only")) {
                SetDetails(errorDetails).code = -32110;
                result = Core::ERROR_BAD_REQUEST;
            }

            return (result);
        }

        Core::hresult InboundVoidNoArg(const string& input, VoidDetails& errorDetails) override
        {
            Core::hresult result = Core::ERROR_NONE;

            if (input == _T("message-only")) {
                SetDetails(errorDetails).message = _T("void default message");
                result = Core::ERROR_UNAVAILABLE;
            }

            return (result);
        }

        Core::hresult InboundAlias(const string& input, AliasDetails& errorDetails) override
        {
            Core::hresult result = Core::ERROR_NONE;

            if (input == _T("data-only")) {
                SetData(errorDetails, 63, _T("alias data"));
                result = Core::ERROR_BAD_REQUEST;
            }

            return (result);
        }

        Core::hresult InboundAliasOpt(const string& input, OptionalAliasDetails& errorDetails) override
        {
            Core::hresult result = Core::ERROR_NONE;

            if (input == _T("full-error")) {
                Core::ErrorDetails<FunctionalTest::ITestRichError::ErrorContext>& details(SetDetails(errorDetails));
                FunctionalTest::ITestRichError::ErrorContext context;
                context.subcode = 64;
                context.reason = _T("optional alias data");
                details.code = -32164;
                details.message = _T("optional alias message");
                details.data = context;
                result = Core::ERROR_GENERAL;
            }

            return (result);
        }

        Core::hresult InboundString(const string& input, StringDetails& errorDetails) override
        {
            Core::hresult result = Core::ERROR_NONE;

            if (input == _T("data-only")) {
                SetDetails(errorDetails).data = _T("string error data");
                result = Core::ERROR_BAD_REQUEST;
            }

            return (result);
        }

        BEGIN_INTERFACE_MAP(TestRichErrorImpl)
        INTERFACE_ENTRY(FunctionalTest::ITestRichError)
        END_INTERFACE_MAP
    };

    static Factory::Registrar<FunctionalTest::ITestRichError, TestRichErrorImpl> g_richErrorRegistrar;

} // namespace TestImplementation
} // namespace Thunder
