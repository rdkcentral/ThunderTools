# COM-RPC Functional Test Interfaces

Test interfaces for the Thunder/WPEFramework ProxyStubGenerator. Each interface targets a specific annotation category or feature area. Together they provide systematic coverage of the generator's marshalling code paths.

---

## Interfaces

### ITestPrimitives
Validates round-trip marshalling for every primitive type the generator supports: `int8/16/32/64`, `uint8/16/32/64`, `int24_t`/`Core::UInt24`, `float`, `double`, `bool`, `string`, `Core::instance_id`, `Core::Time`, `Core::MACAddress`, and raw `char*` buffers. The `char*` method carries `@json:omit` since raw C-string buffers have no clean JSON-RPC mapping.

### ITestBuffers
Covers all `@length` and `@maxlength` buffer passing patterns: fixed-size arrays (`uint8_t[4]`, `uint32_t[4]`, `uint8_t[8/16]`), variable-length input buffers with `@length:param`, output buffers with `@length:out @maxlength:capacity`, in/out buffers, and multi-buffer merge. Also exercises `@encode:base64` and `@encode:hex` on fixed arrays. Not tagged `@json 1.0.0` because the generator produces uncompilable JSON-RPC code for buffer methods.

### ITestEnums
Covers enum serialisation: plain integer enums, `@encode:text` (string names on JSON-RPC), and `@encode:bitmask` (flag arrays on JSON-RPC). Exercises enums as `@in`, `@out`, and `@inout` parameters, multi-enum calls, `@property` (read-write, read-only, write-only), and `Core::OptionalType<Enum>`.

### ITestOptionals
Validates `Core::OptionalType<T>` — the R4+ replacement for `@optional` — as input parameters with `@default` values, as output parameters the caller may ignore, and in combinations (multiple optionals, optional buffers, all-optional edge case). Types covered: `uint32_t`, `int32_t`, `string`, `bool`, and raw byte buffers.

### ITestRestrictions
Covers the `@restrict` annotation across all value kinds: exact-value restriction (`@restrict:42`), closed ranges on unsigned integers, signed integers, floats, and doubles, string length restrictions (`@restrict:1..64`, `@restrict:nonempty`), the K-suffix shorthand (`@restrict:4K`), multiple restricted parameters in one call, `@inout` restricted parameters, and `Core::OptionalType` combined with a restrict range.

### ITestStructs
Validates POD struct marshalling: nested structs (`Rectangle` contains `Point`), structs as `@in`/`@out`/`@inout` parameters, multi-struct calls, `std::vector<Struct>` with `@restrict`, `@property` with `@index` for per-slot addressing, and `@opaque` for raw JSON pass-through.

### ITestIterators
Validates `RPC::IStringIterator` and `RPC::IValueIterator` lifecycle: creation (normal, empty, large), and the store-and-query pattern that avoids COM-RPC channel deadlock. Clients hand an iterator to the server (which drains it synchronously), then query the cached results via a separate call — keeping the channel free for callbacks. Not tagged `@json 1.0.0` as iterators have no clean JSON mapping.

### ITestEvents
Validates the `@event` / `INotification` pattern with a full range of payload types: primitive scalars, structs, `std::vector<Struct>` with `@restrict`, `Core::OptionalType` payloads, and `@statuslistener`. Also exercises `@index` on `OnStateChanged` to route events to channel-specific subscribers.

### ITestAsync
Validates the `@async` pattern where a completion callback replaces the return path. Supports up to 7 concurrent operations via a slot pool (0..6). `Calculate` assigns and returns a slot; `SlotResult` is a `@property` with `@index` so each slot is independently addressable via the JSON-RPC property API. Results auto-clear on read.

### ITestInterfaces
Validates three stub-generator control annotations: `@interface:id` on `void*` return values and output parameters (dynamic interface pointer passing with generated QueryInterface/AddRef/Release), `@stub` (method present server-side only, no proxy emitted), and `@omit` (method excluded from both stub and proxy, vtable slot preserved).

### ITestEncodingMac
Validates `@encode:mac` on a `Core::MACAddress` parameter: the JSON-RPC layer encodes the six-byte address as a colon-separated hex string (e.g. `"AA:BB:CC:DD:EE:FF"`). Exercises both input (set) and output (get) directions.

### ITestLengthModes
Covers the two buffer-length variants not in `ITestBuffers`: `@length:void` (no length parameter; caller provides null-terminated or fixed-size data) and `@length:return` (the method return value carries the buffer length rather than a separate parameter). COM-RPC only — `@length:return` is incompatible with `uint32_t` return types used for JSON-RPC error codes.

### ITestJsonShape
Exercises JSON payload shaping annotations: `@wrapped` (a single scalar output is enclosed in a named object rather than returned bare) and `@extract` (a single-element list may be flattened to a scalar in the JSON response).

### ITestJsonTextKeep
Validates `@text:keep` at interface level: every method name, parameter name, and POD member name in the generated JSON-RPC interface matches the C++ identifier exactly, with no case transformation applied.

### ITestJsonTextCase
Validates `@text:legacy` at interface level: all method names, parameter names, and POD member names are lowercased in the generated JSON-RPC interface, matching the pre-5.2 Thunder convention.

### ITestJsonCompliant
Baseline for the default `@compliant` JSON-RPC format. Single-parameter method inputs are enclosed in a named object (`{"payload":"abc"}`), and the response value is placed in the `"result"` field of the JSON-RPC envelope. Provides a comparison point for the two uncompliant modes below.

### ITestJsonUncompliantExtended ⚠️ deprecated
Pins the generator behaviour for `@uncompliant:extended` (deprecated — do not use in new interfaces; see Thunder `docs/plugin/interfaces/tags.md`). The essential property contract: the SET request sends the value as a **bare scalar** (e.g. `42`, not `{"value":42}`) while the GET response still uses the `"result"` field. Methods are **not** affected — they remain wrapped just like `@compliant`. Without a `@property`, the mode is indistinguishable from `@compliant` in tests.

### ITestJsonUncompliantCollapsed ⚠️ deprecated
Pins the generator behaviour for `@uncompliant:collapsed` (deprecated — do not use in new interfaces; see Thunder `docs/plugin/interfaces/tags.md`). Extends the bare-scalar contract to **all** single-parameter methods, properties, and notifications. Property SET sends a bare scalar, and the GET response is placed in the `"params"` field of the JSON-RPC envelope (not `"result"` as in compliant and extended modes). Sending a wrapped object to a collapsed method must be rejected.

---

## Annotation Coverage Matrix

| Annotation | Interface(s) |
|---|---|
| `@in` / `@out` / `@inout` | All |
| `@length:param` | ITestBuffers, ITestOptionals, ITestPrimitives |
| `@length:void` | ITestLengthModes |
| `@length:return` | ITestLengthModes |
| `@maxlength:param` | ITestBuffers, ITestOptionals |
| `@encode:base64` | ITestBuffers |
| `@encode:hex` | ITestBuffers |
| `@encode:text` | ITestEnums |
| `@encode:bitmask` | ITestEnums |
| `@encode:mac` | ITestEncodingMac |
| `@opaque` | ITestStructs |
| `@restrict` (integer range) | ITestRestrictions, ITestBuffers, ITestAsync |
| `@restrict` (float range) | ITestRestrictions |
| `@restrict` (string length) | ITestRestrictions |
| `@restrict:nonempty` | ITestRestrictions |
| `@restrict:K` suffix | ITestRestrictions |
| `@restrict` on `std::vector` | ITestStructs, ITestEvents |
| `@default` | ITestAsync, ITestOptionals |
| `@optional` / `Core::OptionalType<T>` | ITestAsync, ITestOptionals, ITestEnums, ITestEvents, ITestRestrictions |
| `@property` (read-write) | ITestEnums, ITestStructs, ITestAsync, ITestJsonUncompliantExtended, ITestJsonUncompliantCollapsed |
| `@property` (read-only) | ITestEnums, ITestAsync |
| `@property` (write-only) | ITestEnums |
| `@index` | ITestStructs, ITestEvents, ITestAsync |
| `@event` | ITestEvents |
| `@statuslistener` | ITestEvents |
| `@async` | ITestAsync |
| `@interface:id` (return value) | ITestInterfaces |
| `@interface:id` (output param) | ITestInterfaces |
| `@stub` | ITestInterfaces |
| `@omit` | ITestInterfaces |
| `@json:omit` | ITestPrimitives |
| `@wrapped` | ITestJsonShape |
| `@extract` | ITestJsonShape |
| `@text:keep` | ITestJsonTextKeep |
| `@text:legacy` | ITestJsonTextCase |
| `@compliant` | ITestJsonCompliant |
| `@uncompliant:extended` ⚠️ deprecated | ITestJsonUncompliantExtended |
| `@uncompliant:collapsed` ⚠️ deprecated | ITestJsonUncompliantCollapsed |
| `@json 1.0.0` | ITestPrimitives, ITestEnums, ITestOptionals, ITestRestrictions, ITestStructs, ITestEvents, ITestAsync, ITestEncodingMac, ITestJsonShape, ITestJsonTextKeep, ITestJsonTextCase, ITestJsonCompliant, ITestJsonUncompliantExtended, ITestJsonUncompliantCollapsed |
| `std::vector<Primitive>` | ITestStructs |
| `std::vector<Struct>` | ITestStructs, ITestEvents |
| `RPC::IStringIterator` | ITestIterators |
| `RPC::IValueIterator` | ITestIterators |

