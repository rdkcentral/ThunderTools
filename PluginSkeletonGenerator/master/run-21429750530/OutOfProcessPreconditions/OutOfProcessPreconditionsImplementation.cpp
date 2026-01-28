/*
* If not stated otherwise in this file or this component's LICENSE file the
* following copyright and licenses apply:
*
* Copyright 2026 [PLEASE ADD COPYRIGHT NAME!]
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

#include "Module.h"
#include <interfaces/IMessageControl.h>

namespace Thunder {
namespace Plugin {

    class OutOfProcessPreconditionsImplementation : public Exchange::IMessageControl {
    public:
        OutOfProcessPreconditionsImplementation(const OutOfProcessPreconditionsImplementation&) = delete;
        OutOfProcessPreconditionsImplementation& operator=(const OutOfProcessPreconditionsImplementation&) = delete;
        OutOfProcessPreconditionsImplementation(OutOfProcessPreconditionsImplementation&&) = delete;
        OutOfProcessPreconditionsImplementation& operator=(OutOfProcessPreconditionsImplementation&&) = delete;

        OutOfProcessPreconditionsImplementation()
            : Exchange::IMessageControl()
        {
        }
        ~OutOfProcessPreconditionsImplementation() override = default;

    public:

        BEGIN_INTERFACE_MAP(OutOfProcessPreconditionsImplementation)
            INTERFACE_ENTRY(Exchange::IMessageControl)
        END_INTERFACE_MAP

        // IMessageControl methods

        Core::hresult Enable(const messagetype /* type */, const string& /* category */, const string& /* module */, const bool /* enabled */) override {
            return Core::ERROR_NONE;
        }

        Core::hresult Modules(IStringIterator*& /* modules */ /* @out */) const override {
            return Core::ERROR_NONE;
        }

        Core::hresult Controls(const string& /* module */ /* @index */, IControlIterator*& /* control */ /* @out */) const override {
            return Core::ERROR_NONE;
        }
    private:

    };

    SERVICE_REGISTRATION(OutOfProcessPreconditionsImplementation, 1, 0)
} // Plugin
} // Thunder