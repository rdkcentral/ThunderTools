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

#pragma once

#include "Ids.h"
#include "Module.h"

// @insert <core/Errors.h>

namespace Thunder {
namespace FunctionalTest {

    // @json 1.0.0
    struct EXTERNAL ITestRichError : virtual public Core::IUnknown {
        enum { ID = ID_TEST_RICH_ERROR };

        struct ErrorContext {
            uint16_t subcode;
            string reason;
        };

        using ErrorAlias = Core::ErrorDetails<ErrorContext>;
        using OptErrorAlias = Core::OptionalType<Core::ErrorDetails<ErrorContext>>;

        ~ITestRichError() override = default;

        // with struct data
        virtual Core::hresult Plain(Core::OptionalType<Core::ErrorDetails<ErrorContext>>& errorDetails /* @out */) = 0;
        virtual Core::hresult Inbound(const string& input, Core::OptionalType<Core::ErrorDetails<ErrorContext>>& errorDetails /* @out */) = 0;
        virtual Core::hresult Outbound(string& output /* @out */, Core::OptionalType<Core::ErrorDetails<ErrorContext>>& errorDetails /* @out */) = 0;
        virtual Core::hresult Transform(const string& input, string& output /* @out */, Core::OptionalType<Core::ErrorDetails<ErrorContext>>& errorDetails /* @out */) = 0;

        // with void data
        virtual Core::hresult InboundVoid(const string& input, Core::OptionalType<Core::ErrorDetails<void>>& errorDetails /* @out */) = 0;
        virtual Core::hresult InboundVoidNoArg(const string& input, Core::OptionalType<Core::ErrorDetails<>>& errorDetails /* @out */) = 0;

        // with alias for data 
        virtual Core::hresult InboundAlias(const string& input, Core::OptionalType<ErrorAlias>& errorDetails /* @out */) = 0;
        virtual Core::hresult InboundAliasOpt(const string& input, OptErrorAlias& errorDetails /* @out */) = 0;
        
        // with primitives
        virtual Core::hresult InboundString(const string& input, Core::OptionalType<Core::ErrorDetails<string>>& errorDetails /* @out */) = 0;
    };

} // namespace FunctionalTest
} // namespace Thunder
