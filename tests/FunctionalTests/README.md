# ThunderTools ProxyStub Functional Test Suite

Functional tests for the Thunder `ProxyStubGenerator` tool.
Each test interface exercises a specific IDL annotation or marshalling pattern.
The build is fully self-contained: Thunder and GoogleTest are fetched automatically via CMake `FetchContent`.

## Test interfaces

| CMake option | Interface | What it tests |
|---|---|---|
| `TEST_PRIMITIVES` | `ITestPrimitives` | Round-trip marshalling of every scalar type: `int8/16/24/32/64`, `uint8/16/24/32/64`, `float`, `double`, `bool`, `instance_id`, `Core::Time`, `Core::MACAddress`, `string` |
| `TEST_BUFFERS` | `ITestBuffers` | `@length` / `@maxlength` annotations on `uint8_t[]` parameters: input, output, in/out, and multi-buffer patterns |
| `TEST_OPTIONALS` | `ITestOptionals` | `Core::OptionalType<T>` on input and output parameters, `@default` values, and the optional-buffer convention |
| `TEST_RESTRICTIONS` | `ITestRestrictions` | `@restrict` range validation on integers (signed/unsigned), floats, strings (length), the `nonempty` shorthand, the `K`-suffix, and `OptionalType` combined with a range |
| `TEST_ENUMS` | `ITestEnums` | Enum serialisation: `@encode:text`, `@encode:bitmask`, `@property`, in/out/inout parameters, optional enums |
| `TEST_STRUCTS` | `ITestStructs` | POD struct marshalling: in/out/inout parameters, nested structs, `std::vector<struct>`, `@opaque`, `@index` (property slot), `@restrict` on vectors |
| `TEST_EVENTS` | `ITestEvents` | Event callback pattern (`@event`, `INotification`): scalar payloads, struct payloads, `std::vector` payloads, `OptionalType` payloads, `@statuslistener` |
| `TEST_ASYNC` | `ITestAsync` | `@async` pattern: concurrent slots, `ICallback` interface, `@property` with `@index`, `OptionalType` in a callback |
| `TEST_INTERFACES`  | `ITestInterfacePointers` | Generator control annotations: `@interface` (void\* + ID dynamic typing), `@stub` (server-side only), `@omit` (excluded from both proxy and stub) |
| `TEST_ITERATORS`  | `ITestIterators` | `RPC::IStringIterator` / `IValueIterator` passing and the store-and-query pattern that avoids COM-RPC channel deadlock |

`TEST_INTERFACES` and `TEST_ITERATORS` are off by default pending a thorough review of the generated code.

> **`@restrict` validation note**: the generator emits `ASSERT()` calls in the generated stub for out-of-range values — not graceful error returns. Passing a value outside a `@restrict` range will abort the process rather than returning `ERROR_INVALID_INPUT`. Tests that verify rejection of invalid values are therefore exercising the generator's validation path, not the implementation.

> **Iterator drain timing**: `RegisterStringIterator` / `RegisterValueIterator` drain the incoming iterator on a detached background thread to avoid a COM-RPC channel deadlock (calling `Next()` from within the stub handler would block the channel). Tests insert a fixed 150 ms sleep before querying results. This is a known fragility.

## Build

```bash
cmake -S . -B build
cmake --build build -j$(nproc)
```

Both Thunder (`master`) and GoogleTest (`v1.17.x`) are fetched at configure time. To pin a specific revision:

```bash
cmake -S . -B build \
  -DTHUNDER_VERSION=<tag-or-sha> \
  -DGOOGLE_TEST_VERSION=<tag-or-sha>
```

### Enabling / disabling test groups

Any `TEST_*` option can be toggled at configure time:

```bash
cmake -S . -B build -DTEST_ITERATORS=ON -DTEST_BUFFERS=OFF
```

### JSON-RPC coverage

Interfaces annotated with `@json 1.0.0` can also have JSON-RPC glue generated. This is off by default:

```bash
cmake -S . -B build -DINCLUDE_JSON_RPC_INTERFACES=ON
```

This generates JSON-RPC dispatch code but integration with the main test executable is a work in progress.

### JSON-RPC functional tests

A separate test executable validates JsonGenerator output using a simplified header-only architecture:

```bash
cmake -S . -B build -DBUILD_JSON_RPC_TESTS=ON
cmake --build build --target JsonRpcFunctionalTests
./build/tests/JsonRpcFunctionalTests
```

This creates `JsonRpcFunctionalTests` executable that:
- Reuses the same interface definitions and implementation classes as COM-RPC tests
- Tests **full round-trip JSON marshalling/unmarshalling** using Thunder's `PluginHost::JSONRPC::Invoke()` directly
- Uses **header-only infrastructure** (`JsonRpcServer.h` contains both registration system and dispatcher)
- **One-line registration** per interface using lambda-based static registrars (no template specialization boilerplate)
- Uses `JsonRpcTestHarness<IF>` fixtures instead of `TestHarness<IF>`
- Validates that generated `J<Interface>::Register()` dispatch code compiles and works correctly
- Verifies **parameter deserialization** (JSON request → C++ types → implementation)
- Verifies **return value serialization** (implementation → C++ types → JSON response)
- Tests enum conversion (all enums serialize as UPPERCASE strings: `"RED"`, `"RUNNING"`, `"HIGH"`)
- Tests bitmask enums as arrays of strings: `["CAP_AUDIO", "CAP_VIDEO"]`
- Validates struct marshalling (nested structs, vectors, etc.)
- Checks parameter validation (`@restrict` ranges, required fields)

**Current status**: 48 tests passing across Primitives, Enums, Structs, and Restrictions interfaces:
- **TestPrimitives**: 16 tests (all echo* methods for scalars, strings, special types - excludes Int24/UInt24 due to JsonGenerator bugs)
- **TestEnums**: 9 tests (setters/getters, properties, toggles, comparisons, validation)
- **TestStructs**: 12 tests (point/rectangle operations, calculations, validation, geometry)
- **TestRestrictions**: 11 tests (range validation, clamping, fixed values, boundary checks)

**Known limitations**:
- Int24/UInt24 excluded (JsonGenerator generates non-existent `Core::Int24` type instead of `int24_t`)
- Events, Async, and Interfaces tests not implemented (require IHandler callback infrastructure and async patterns)
- Buffers and Optionals excluded (known JsonGenerator bugs with `@length`/`@maxlength` on buffers)
- Iterators excluded (no JSON-RPC mapping for RPC::IStringIterator)
- Raw pointer patterns (char*) excluded (`@json:omit` - no clean JSON mapping)

## Run

```bash
./build/ProxyStubFunctionalTests
```

Or via CTest:

```bash
ctest --test-dir build --output-on-failure
```

## Architecture

The test binary runs a COM-RPC server and client in the same process, communicating over a Unix domain socket. Each interface has a concrete implementation registered on the server side; the test exercises the full marshalling stack — proxy serialisation, IPC transport, stub deserialisation, implementation, and the return path — without any out-of-process plumbing.

```
┌────────────────────────────────────────────────────┐
│               ProxyStubFunctionalTests             │
│                                                    │
│  Server side                  Test side            │
│  ┌─────────────────────┐      ┌─────────────────┐  │
│  │ ComRpcServer        │      │ TestHarness<IF> │  │
│  │ (RPC::Communicator) │◄────►│                 │  │
│  │                     │ UDS  │ CommunicatorCli │  │
│  │  Acquire() →        │      │ + InvokeServer  │  │
│  │  ImplementationPro- │      │                 │  │
│  │  vider (factory map)│      │  _proxy (IF*)   │  │
│  │                     │      │                 │  │
│  │  Stub (generated)   │      │  Proxy (genera- │  │
│  │  Impl               │      │   ted)          │  │
│  └─────────────────────┘      └─────────────────┘  │
│                                                    │
│              /tmp/comrpc_test.socket               │
└────────────────────────────────────────────────────┘
```

**Server side** — `ComRpcServer` extends `RPC::Communicator` and overrides `Acquire()`. When the client opens an interface, `Acquire()` looks up a factory in `ImplementationProvider` and returns a new implementation instance. Implementations register themselves at static-initialisation time via `ImplementationRegistrar<INTERFACE, IMPL>`, so there is no explicit wiring in `main`.

**Client side** — each `TestHarness<IF>` fixture creates an `RPC::CommunicatorClient` backed by an `RPC::InvokeServerType` engine and calls `Open<IF>()` to obtain a proxy. Tests call methods on `_proxy` exactly as they would on a local object.

ProxyStubs are generated by `ProxyStubGenerator` at build time into `build/comrpc/` and compiled directly into the binary. No shared-library loading or plugin registration is involved.

## JSON-RPC test architecture

The JSON-RPC test binary uses Thunder's `PluginHost::JSONRPC` for direct method dispatch without network transport. The infrastructure is **header-only** - all registration and dispatch logic lives in `JsonRpcServer.h`:

```
┌────────────────────────────────────────────────────┐
│            JsonRpcFunctionalTests                  │
│                                                    │
│  Server side                  Test side            │
│  ┌─────────────────────┐      ┌─────────────────┐  │
│  │ JsonRpcServer       │      │ JsonRpcTest-    │  │
│  │ (PluginHost::       │      │ Harness<IF>     │  │
│  │  JSONRPC)           │      │                 │  │
│  │                     │      │ CallMethod()    │  │
│  │ ┌─────────────────┐ │      │   ↓             │  │
│  │ │Registration     │ │      │ JSONRPC::       │  │
│  │ │Provider (lambda-│ │◄─────┤ Invoke()        │  │
│  │ │based registry)  │ │      │   ↓             │  │
│  │ └─────────────────┘ │      │ JSON-RPC 2.0    │  │
│  │                     │      │ params/response │  │
│  │  MockShell          │      │                 │  │
│  │  (IShell stub)      │      │                 │  │
│  │                     │      │                 │  │
│  │  Impl (reused)      │      │                 │  │
│  └─────────────────────┘      └─────────────────┘  │
│                                                    │
│         Direct function call (no socket)           │
└────────────────────────────────────────────────────┘
```

**Server side** — `JsonRpcServer` inherits from `PluginHost::JSONRPC` and `PluginHost::IPlugin`. A `MockShell` provides the minimal `IShell` interface needed for initialization. Implementation classes are the same protocol-agnostic implementations used for COM-RPC tests.

**Registration system** (header-only in `JsonRpcServer.h`):
- `JsonRpcRegistrationProvider`: Singleton collecting registration lambdas
- `JsonRpcRegistrar<INTERFACE, IMPL>`: Template class capturing register function in lambda
- Static initialization: Each implementation file has one-line registrar:
  ```cpp
  static JsonRpcServer::JsonRpcRegistrar<ITestPrimitives, TestPrimitivesImpl>
      g_jsonrpc_registrar(JTestPrimitives::Register<JsonRpcServer>);
  ```
- Lambda-based pattern: Register function is passed to constructor, captured in lambda, executed on `Start()`
- Deferred execution: `Core::Service<IMPL>::Create<>()` happens inside lambda where class definition exists

**Client side** — `JsonRpcTestHarness<IF>` fixtures call `CallMethod(name, params, response)` which directly invokes `_server->Invoke()` with JSON-RPC 2.0 formatted parameters. No network transport is used - tests invoke the dispatcher directly as function calls. This exercises the **complete marshalling path**:
1. Test creates JSON request string (e.g., `{"color":"RED"}`)
2. Generated `J<Interface>` code **deserializes** JSON → validates → converts to C++ types
3. Implementation method executes with C++ parameters
4. Generated code **serializes** C++ return values → JSON response string
5. Test validates JSON response content

**Enum encoding** — The generated `JsonEnum_TestEnums.cpp` conversion tables map all enums to UPPERCASE strings in JSON, regardless of `@encode:text` annotation. Examples:
- Color enum: `"RED"`, `"GREEN"`, `"BLUE"`, `"YELLOW"` (not numeric 0,1,2,3)
- State enum: `"IDLE"`, `"RUNNING"`, `"PAUSED"`, `"STOPPED"`, `"ERROR"`
- Priority enum: `"LOW"`, `"NORMAL"`, `"HIGH"`, `"CRITICAL"`
- Capabilities bitmask: `["CAP_AUDIO", "CAP_VIDEO"]` (array of strings)

JSON-RPC dispatch headers are generated by `JsonGenerator` at build time into `build/tests/jsonrpc/`.

**Registration pattern advantages**:
- Matches COM-RPC simplicity: one static registrar per interface
- No template specialization boilerplate (just function pointer passing)
- Clean separation: no JSON-RPC code in implementation files except `#ifdef` guarded registrar
- Automatic: adding new interface requires only one line in .cpp file

## Known limitations

Several IDL patterns are commented out in the interface headers with `FIXME` markers where the generator produces invalid or non-compiling output. These are tracked as open issues against `ProxyStubGenerator` / `JsonGenerator` and represent the primary motivation for this test suite.