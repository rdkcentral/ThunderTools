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
#include "ComRpcServer.h"


#ifdef INCLUDE_JSON_RPC_INTERFACES
// Include generated headers for JSON-RPC interfaces
#include <JsonRpcInterfaces.h>
#endif

using namespace Thunder;

class TestEnvironment : public ::testing::Environment {
public:
    void SetUp() override {
        // Start the RPC server
        // Implementation factories are already registered via static initialization
        ComRpcServer::Start();
        
        // Give the server a moment to fully initialize
        SleepMs(100);
    }

    void TearDown() override {
        // Stop the RPC server
        ComRpcServer::Stop();
    }
};

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    ::testing::AddGlobalTestEnvironment(new TestEnvironment());
    return RUN_ALL_TESTS();
}
