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

---

## Annotation Coverage Matrix

| Annotation | Interface(s) |
|---|---|
| `@in` / `@out` / `@inout` | All |
| `@length:param` | ITestBuffers, ITestOptionals, ITestPrimitives |
| `@maxlength:param` | ITestBuffers, ITestOptionals |
| `@encode:base64` | ITestBuffers |
| `@encode:hex` | ITestBuffers |
| `@encode:text` | ITestEnums |
| `@encode:bitmask` | ITestEnums |
| `@encode:mac` | ITestAsync (via ICallback::Complete) |
| `@opaque` | ITestStructs |
| `@restrict` (integer range) | ITestRestrictions, ITestBuffers, ITestAsync |
| `@restrict` (float range) | ITestRestrictions |
| `@restrict` (string length) | ITestRestrictions |
| `@restrict:nonempty` | ITestRestrictions |
| `@restrict:K` suffix | ITestRestrictions |
| `@restrict` on `std::vector` | ITestStructs, ITestEvents |
| `@default` | ITestAsync, ITestOptionals |
| `@optional` / `Core::OptionalType<T>` | ITestAsync, ITestOptionals, ITestEnums, ITestEvents, ITestRestrictions |
| `@property` (read-write) | ITestEnums, ITestStructs, ITestAsync |
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
| `@json 1.0.0` | ITestPrimitives, ITestEnums, ITestOptionals, ITestRestrictions, ITestStructs, ITestEvents, ITestAsync |
| `std::vector<Primitive>` | ITestStructs |
| `std::vector<Struct>` | ITestStructs, ITestEvents |
| `RPC::IStringIterator` | ITestIterators |
| `RPC::IValueIterator` | ITestIterators |

