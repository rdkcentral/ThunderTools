# Thunder Interface Validation Rules

**Version:** 3.2.2  
**Status:** For Review  

## Description

Rules for validating Thunder COM interface headers in `ThunderInterfaces/interfaces/`.  
Every rule uses semantic reasoning — read the interface header in full and reason about the code as a human reviewer. Never use regex or text search as the primary detection method.

---

## Core Rules (17) — Severity: Violation

### core_1_1 — File and Namespace Structure

**Severity:** violation

**Description:**  
Thunder interface headers must follow the standard file and namespace structure:
- File must be in `ThunderInterfaces/interfaces/` (or `qa_interfaces/` for QA)
- Interface must be declared inside the `WPEFramework::Exchange` namespace
- File name must match the interface name: `IFoo.h` for `struct EXTERNAL IFoo`
- No implementation code in interface headers — pure declarations only

**Extraction Logic:**
1. Read the full interface header file
2. Identify the namespace block(s) and their names
3. Note the file name and the primary interface struct name
4. Check for any non-declaration code (function implementations, static variables, etc.)

**Verification Logic:**
1. Verify the file is inside the `WPEFramework::Exchange` namespace
2. Verify the primary interface struct name matches the file name (e.g. `IDictionary` in `IDictionary.h`)
3. Verify there is no implementation code — only forward declarations, typedefs, struct/enum declarations
4. If any of these conditions fail → VIOLATION

**Violation Pattern:** Interface not in WPEFramework::Exchange namespace, file name mismatch, or implementation code present

**Fix Example:**

```cpp
// WRONG:
namespace WPEFramework {
    // Missing Exchange namespace
    struct EXTERNAL IDictionary : virtual public Core::IUnknown { ... };
}

// Correct:
namespace WPEFramework {
    namespace Exchange {
        struct EXTERNAL IDictionary : virtual public Core::IUnknown { ... };
    }
}
```

**Citation:** `ThunderInterfaces/interfaces/IDictionary.h` — Exchange namespace and file naming

---

### core_2_1 — Interface Declaration Shape

**Severity:** violation

**Description:**  
Thunder COM interfaces must follow the correct declaration shape:
- Must be a struct (not class) with the `EXTERNAL` macro
- Must inherit virtually from `Core::IUnknown` (or from another Thunder interface)
- Must declare a nested enum with the ID value (`RPC::ID_*`)
- All methods must be pure virtual

**Extraction Logic:**
1. Read the interface struct declaration
2. Examine the struct keyword, EXTERNAL macro, and inheritance list
3. Check for the nested `enum { ID = RPC::ID_* }`
4. Examine all method declarations for pure virtual (`= 0`)

**Verification Logic:**
1. Verify the declaration uses `struct EXTERNAL IName`
2. Verify inheritance is `virtual public Core::IUnknown` or a Thunder interface
3. Verify a nested enum contains `ID = RPC::ID_*`
4. Verify all methods are pure virtual (`= 0`)
5. If any fails → VIOLATION

**Violation Pattern:** Interface missing EXTERNAL macro, wrong inheritance, missing ID enum, or non-pure-virtual methods

**Fix Example:**

```cpp
// WRONG:
class IDictionary : public Core::IUnknown {
    enum { ID = 0x100 };  // ← raw value, not RPC::ID_*
    virtual void Get(const string& key) { }  // ← not pure virtual

// Correct:
struct EXTERNAL IDictionary : virtual public Core::IUnknown {
    enum { ID = RPC::ID_DICTIONARY };
    virtual Core::hresult Get(const string& key, string& value /* @out */) = 0;
};
```

**Citation:** `ThunderInterfaces/interfaces/IDictionary.h` — struct EXTERNAL shape

---

### core_3_1 — Interface ID Registration

**Severity:** violation

**Description:**  
Every Thunder COM interface must have a unique numeric ID registered in `RPC::IDs` (in `ThunderInterfaces/interfaces/ids.h` or equivalent). The ID enum value in the struct must reference the registered `RPC::ID_*` constant. Sub-interfaces (`INotification`, `ICallback` nested in a parent) must also have their own unique IDs.

**Extraction Logic:**
1. Read the interface struct declaration and note its ID value
2. Check whether the ID value uses an `RPC::ID_*` constant
3. Check `ids.h` (or the ID registration file) for the corresponding entry

**Verification Logic:**
1. Verify the struct `enum { ID = RPC::ID_* }` uses a named constant, not a raw number
2. Verify the ID is registered in ThunderInterfaces `ids.h` (or equivalent)
3. Verify the ID is unique — no other interface uses the same value
4. Nested `INotification` and `ICallback` interfaces must also have their own IDs
5. If any condition fails → VIOLATION

**Violation Pattern:** Interface ID missing from IDs registration, uses raw number, or is not unique

**Fix Example:**

```cpp
// WRONG:
enum { ID = 0x100 };   // ← raw number, not registered

// Correct:
enum { ID = RPC::ID_DICTIONARY };
// AND in ids.h:
// ID_DICTIONARY = RPC_ID_OFFSET + N,
```

**Citation:** `ThunderInterfaces/interfaces/ids.h` — ID_DICTIONARY registration

---

### core_4_1 — Pure Virtual Methods Only

**Severity:** violation

**Description:**  
Thunder COM interface methods must be pure virtual (`= 0`). No default implementations, no inline code, no static methods, no non-virtual methods. The interface is a pure abstract contract — all implementation is in the implementing class, not in the interface.

**Extraction Logic:**
1. Read all method declarations in the interface struct
2. Check each method for the `= 0` specifier
3. Look for any inline code, default implementations, or static methods

**Verification Logic:**
1. Every method in the interface must end with `= 0`
2. No method may have a body (even `{}`)
3. No static methods allowed in interfaces
4. No non-virtual methods (constructors, operators excepted)
5. If any violation → VIOLATION

**Violation Pattern:** Non-pure-virtual method, inline implementation, or static method in COM interface

**Fix Example:**

```cpp
// WRONG:
virtual Core::hresult Get(const string& key, string& value) {
    value = "default";   // ← inline implementation
    return Core::ERROR_NONE;
}

// Correct:
virtual Core::hresult Get(const string& key, string& value /* @out */) = 0;
```

**Citation:** `ThunderInterfaces/interfaces/IDictionary.h` — pure virtual methods

---

### core_5_1 — Return Type Conventions

**Severity:** violation

**Description:**  
In Thunder 5.0+, all COM interface methods annotated with `@json` (i.e. methods that generate JSON-RPC code) MUST return `Core::hresult`. Void return types and other return types are not allowed for JSON-RPC-generating methods. Methods in pure COM interfaces (no `@json`) should also use `Core::hresult` for error reporting where applicable.

**Extraction Logic:**
1. Read all interface method declarations
2. Note which methods are under a `@json`-tagged interface or have `@json` annotations
3. Check the return type of each method

**Verification Logic:**
1. For interfaces tagged with `@json` (or in Thunder 5.0+ contexts), all methods must return `Core::hresult`
2. Void return types are not allowed for JSON-RPC methods
3. Custom return types (not `Core::hresult`) for non-status purposes are not allowed — use `@out` parameters instead
4. If any JSON-RPC method lacks `Core::hresult` return type → VIOLATION

**Violation Pattern:** Interface method does not return Core::hresult — required for @json interfaces in Thunder 5.0+

**Fix Example:**

```cpp
// WRONG:
virtual void SetVolume(const uint8_t volume) = 0;
virtual string GetStatus() = 0;

// Correct:
virtual Core::hresult SetVolume(const uint8_t volume) = 0;
virtual Core::hresult GetStatus(string& status /* @out */) = 0;
```

**Citation:** `ThunderInterfaces/interfaces/IAudioOutput.h` — Core::hresult return types

---

### core_6_1 — Const Correctness

**Severity:** violation

**Description:**  
Interface methods must use const correctly:
- Input-only parameters should be const (`const string& key`)
- Output parameters should be non-const references (`string& value`)
- Methods that do not modify the object should be const (though pure virtual const is rare)
- `@out` parameters must be non-const references to allow the implementation to write

**Extraction Logic:**
1. Read all method parameter declarations
2. Examine const qualifiers on each parameter
3. Identify parameters marked `@out` and verify they are non-const references
4. Identify input parameters and verify they are const where appropriate

**Verification Logic:**
1. `@out` parameters must be non-const references (`string& value`, not `const string& value`)
2. Input parameters that are passed by value or const ref are correct
3. Non-const reference parameters without `@out` indicate potential API design issues
4. If `@out` parameters are const (preventing write) → VIOLATION

**Violation Pattern:** @out parameter declared const preventing the implementation from writing the output value

**Fix Example:**

```cpp
// WRONG:
virtual Core::hresult Get(const string& key, const string& value /* @out */) = 0;
//                                              ^^^^^  ← const prevents writing

// Correct:
virtual Core::hresult Get(const string& key, string& value /* @out */) = 0;
```

**Citation:** `ThunderInterfaces/interfaces/IDictionary.h` — const correctness on @out params

---

### core_9_1 — Thunder Type Conventions

**Severity:** violation

**Description:**  
Thunder interfaces must use Thunder type aliases, not `std::` types directly:
- `string` (not `std::string`) for text
- `Core::hresult` (not `HRESULT` or `int`) for error returns
- `uint8_t`, `uint16_t`, `uint32_t`, `uint64_t` (not `int`, `long`, `short`)
- `bool` (acceptable) but not `BOOL`

Using `std::string` in interfaces breaks cross-ABI compatibility.

**Extraction Logic:**
1. Read all method parameter types and return types in the interface
2. Identify any `std::` type usage (`std::string`, `std::vector` without @restrict review)
3. Check for non-Thunder integer types (`int`, `long`, `short`, `BOOL`, `HRESULT`)

**Verification Logic:**
1. `std::string` in interface parameters → VIOLATION (use `string`)
2. `HRESULT` or raw `int` for error codes → VIOLATION (use `Core::hresult`)
3. Non-width-specific integer types (`int`, `long`) for interface params → check core_16_1
4. `BOOL` → VIOLATION (use `bool`)
5. If `std::string` found → VIOLATION

**Violation Pattern:** std::string used in interface — must use Thunder string type alias

**Fix Example:**

```cpp
// WRONG:
virtual Core::hresult Get(const std::string& key, std::string& value) = 0;

// Correct:
virtual Core::hresult Get(const string& key, string& value /* @out */) = 0;
```

**Citation:** `ThunderInterfaces/interfaces/IDictionary.h` — Thunder string type alias

---

### core_10_1 — Register/Unregister Patterns

**Severity:** violation

**Description:**  
Notification interfaces follow two patterns:
- **INotification (1:many observer):** `Register(INotification*)` and `Unregister(INotification*)` for multiple simultaneous subscribers
- **ICallback (1:1 callback):** `Callback(ICallback*)` sets a single callback (`nullptr` to clear)

Register/Unregister must take a pointer to the notification interface. ICallback::Callback() replaces the previous callback, so no Unregister needed.

**Extraction Logic:**
1. Read the interface for Register/Unregister/Callback method declarations
2. Identify whether it follows the INotification (1:many) or ICallback (1:1) pattern
3. Check the method signatures

**Verification Logic:**
1. INotification pattern: must have both `Register(INotification*)` and `Unregister(INotification*)`
2. ICallback pattern: must have `Callback(ICallback*)` accepting nullptr to clear
3. Register without matching Unregister → VIOLATION
4. If notification registration pattern is non-standard → VIOLATION

**Violation Pattern:** Register(INotification*) present but Unregister(INotification*) missing, or non-standard notification pattern

**Fix Example:**

```cpp
// WRONG: (Unregister missing)
virtual Core::hresult Register(INotification* notification) = 0;
// Missing: Unregister

// Correct — INotification (1:many):
virtual Core::hresult Register(INotification* notification) = 0;
virtual Core::hresult Unregister(const INotification* notification) = 0;

// Correct — ICallback (1:1, nullptr clears):
virtual Core::hresult Callback(ICallback* callback) = 0;
```

**Citation:** `ThunderInterfaces/interfaces/IDictionary.h` — Register/Unregister pattern

---

### core_11_1 — Nested Event Interfaces

**Severity:** violation

**Description:**  
Event/notification interfaces nested inside a parent COM interface must:
- Have the `@event` tag (`// @event`) above the struct declaration
- Use `EXTERNAL` in the struct declaration
- Have their own unique ID in the RPC ID list
- Inherit from `Core::IUnknown` (not from the parent interface)

Missing `@event` prevents the code generator from emitting event dispatch code.

**Extraction Logic:**
1. Read the interface for any nested struct declarations
2. For each nested struct that represents a notification/event (INotification, ICallback, etc.)
3. Check for the `@event` comment tag above the declaration
4. Check for `EXTERNAL` in the declaration
5. Check for a nested `enum { ID = RPC::ID_* }`

**Verification Logic:**
1. Every nested event/notification interface must have `// @event` immediately above the struct
2. Must use `EXTERNAL` in the declaration
3. Must have its own ID in the RPC ID list
4. Must inherit from `Core::IUnknown`
5. If any condition fails → VIOLATION

**Violation Pattern:** @event tag missing on nested notification interface, or missing EXTERNAL/ID

**Fix Example:**

```cpp
// WRONG:
struct INotification : virtual public Core::IUnknown {
    enum { ID = RPC::ID_DICTIONARY_NOTIFICATION };  // ← @event tag missing

// Correct:
// @event
struct EXTERNAL INotification : virtual public Core::IUnknown {
    enum { ID = RPC::ID_DICTIONARY_NOTIFICATION };
    virtual void ValueChanged(const string& key, const string& value) = 0;
};
```

**Citation:** `ThunderInterfaces/interfaces/IDictionary.h` — @event tag on INotification

---

### core_12_1 — @json Tag (CRITICAL)

**Severity:** violation

**Description:**  
Without the `@json` tag, ZERO JSON-RPC code is generated for the interface. This is the most common critical omission. The tag must appear immediately above the struct declaration as: `// @json 1.0.0`. No blank lines are allowed between the `@json` tag and the struct declaration.

If an interface intentionally does not need JSON-RPC (pure COM only), the absence of `@json` is acceptable — but this must be an intentional design choice.

**Extraction Logic:**
1. Read the lines immediately above the `struct EXTERNAL I...` declaration
2. Look for a `// @json` comment with a version number
3. Check there are no blank lines between the tag and the struct declaration

**Verification Logic:**
1. If the interface is intended to generate JSON-RPC code: verify `// @json N.N.N` appears immediately above the struct declaration
2. No blank lines between the `@json` tag and the struct line
3. If the interface is intentionally JSON-RPC-free (pure COM) → acceptable, note as design choice
4. If `@json` is missing from an interface that should have it → VIOLATION

**Violation Pattern:** @json tag missing above interface struct declaration — no JSON-RPC code will be generated

**Fix Example:**

```cpp
// WRONG:
struct EXTERNAL IDictionary : virtual public Core::IUnknown {
    // ← @json tag missing — no RPC code will be generated

// Correct:
// @json 1.0.0
struct EXTERNAL IDictionary : virtual public Core::IUnknown {
```

**Citation:** `ThunderInterfaces/interfaces/IDictionary.h:LINE` — @json 1.0.0 above struct

---

### core_13_1 — Binary Compatibility

**Severity:** violation

**Description:**  
Thunder COM interfaces are binary interfaces — once released, they cannot be changed in backward-incompatible ways without breaking all compiled clients:
- Methods must not be reordered (vtable order is fixed)
- Methods must not be removed (creates vtable holes)
- Method signatures must not change (parameter types/count/order)
- New methods must be added at the END of the interface

Binary-incompatible changes require creating a new interface version (`IFoo2`).

**Extraction Logic:**
1. Read the interface method declarations in order
2. If comparing against a previous version: note any additions, removals, or reorderings
3. For new interfaces: verify method ordering follows a logical grouping with extensibility in mind

**Verification Logic:**
1. When reviewing against a baseline: check for removed methods, reordered methods, or changed signatures
2. New methods in a released interface must be at the end
3. If a released interface has been structurally modified → VIOLATION
4. For new (unreleased) interfaces: recommend logical method ordering for future extensibility

**Violation Pattern:** Released interface has methods removed, reordered, or signatures changed — breaks binary compatibility

**Fix Example:**

```cpp
// WRONG: (removed a method or changed signature in a released interface)
// v1: virtual Core::hresult Get(const string& key, string& value) = 0;
// v2: virtual Core::hresult Get(const string& key, string& value, bool caseSensitive) = 0;
//                                                                  ^^^^^^^^^^^^^^^^^ ← changed signature

// Correct: create a new interface version
struct EXTERNAL IDictionary2 : virtual public IDictionary {
    enum { ID = RPC::ID_DICTIONARY2 };
    virtual Core::hresult GetCaseSensitive(const string& key, const bool caseSensitive, string& value /* @out */) = 0;
};
```

**Citation:** `ThunderInterfaces/interfaces/IDictionary.h` — binary compatibility

---

### core_14_1 — No AddRef/Release Redeclaration

**Severity:** violation

**Description:**  
`AddRef()` and `Release()` are inherited from `Core::IUnknown` and must NOT be redeclared in interface structs. Redeclaring them creates a separate vtable entry, breaking COM reference counting and causing crashes.

**Extraction Logic:**
1. Read all method declarations in the interface struct (including nested structs)
2. Look for any `AddRef()` or `Release()` declarations

**Verification Logic:**
1. The interface must not declare `AddRef()` or `Release()`
2. These methods are inherited from `Core::IUnknown` via the virtual inheritance chain
3. If `AddRef()` or `Release()` appears as an interface method → VIOLATION

**Violation Pattern:** AddRef() or Release() redeclared in interface — must be inherited from Core::IUnknown only

**Fix Example:**

```cpp
// WRONG:
struct EXTERNAL IDictionary : virtual public Core::IUnknown {
    virtual uint32_t AddRef() const = 0;    // ← DO NOT REDECLARE
    virtual uint32_t Release() const = 0;   // ← DO NOT REDECLARE
    virtual Core::hresult Get(const string& key, string& value) = 0;
};

// Correct:
struct EXTERNAL IDictionary : virtual public Core::IUnknown {
    enum { ID = RPC::ID_DICTIONARY };
    virtual Core::hresult Get(const string& key, string& value /* @out */) = 0;
};
```

**Citation:** `ThunderInterfaces/interfaces/IDictionary.h` — AddRef/Release inherited from Core::IUnknown

---

### core_15_1 — No std::map in Interfaces

**Severity:** violation

**Description:**  
`std::map` (and other `std::` associative containers) must not appear as interface method parameters or return types. `std::map` is not serialisable across process boundaries via Thunder's RPC mechanism and causes code generation failures. Use structured types, repeated calls, or JSON containers instead.

**Extraction Logic:**
1. Read all method parameter types in the interface
2. Look for `std::map`, `std::unordered_map`, `std::multimap`, or similar associative containers

**Verification Logic:**
1. Any `std::map` or similar associative container in method parameters → VIOLATION
2. Consider whether a `Core::JSON::Container` or repeated method calls can replace it
3. If `std::map` found in interface → VIOLATION

**Violation Pattern:** std::map used in interface parameter — not serialisable across process boundaries

**Fix Example:**

```cpp
// WRONG:
virtual Core::hresult GetAll(std::map<string, string>& values /* @out */) = 0;

// Correct: use repeated queries or a structured type
virtual Core::hresult GetKeys(RPC::IStringIterator*& keys /* @out */) = 0;
virtual Core::hresult Get(const string& key, string& value /* @out */) = 0;
```

**Citation:** `ThunderInterfaces/interfaces/IDictionary.h` — no std::map in interfaces

---

### core_16_1 — Explicit Integer Widths

**Severity:** violation

**Description:**  
Interface method parameters and return values must use explicit-width integer types (`uint8_t`, `uint16_t`, `uint32_t`, `uint64_t`, `int32_t`, etc.) rather than platform-dependent types (`int`, `long`, `short`, `size_t`, `unsigned int`). Implicit-width types change size between platforms and break binary compatibility.

**Extraction Logic:**
1. Read all method parameter types and return types
2. Identify any integer parameters using platform-dependent types

**Verification Logic:**
1. `int`, `long`, `short`, `unsigned int`, `unsigned long`, `size_t` in interface parameters → VIOLATION
2. `char` is acceptable for character data; `bool` is acceptable
3. `uint8_t`, `uint16_t`, `uint32_t`, `uint64_t`, `int32_t` etc. are correct
4. If platform-dependent integer type found → VIOLATION

**Violation Pattern:** Platform-dependent integer type (int, long, short) used in interface — must use explicit-width types (uint32_t, etc.)

**Fix Example:**

```cpp
// WRONG:
virtual Core::hresult SetTimeout(const int timeout) = 0;
virtual Core::hresult GetSize(unsigned int& size /* @out */) = 0;

// Correct:
virtual Core::hresult SetTimeout(const uint32_t timeout) = 0;
virtual Core::hresult GetSize(uint32_t& size /* @out */) = 0;
```

**Citation:** `ThunderInterfaces/interfaces/IVolume.h` — explicit integer widths

---

### core_17_1 — @restrict Mandatory with std::vector

**Severity:** violation

**Description:**  
Every interface method parameter of type `std::vector` (or `Core::JSON::ArrayType` equivalent) MUST be annotated with `/* @restrict:N */` where N is the maximum allowed element count. Without `@restrict`, the code generator cannot produce safe bounds-checking code and may generate unbounded deserialization that is exploitable.

> **Note:** This rule specifically applies to `std::vector`. Non-vector parameters with optional constraints are covered by advisory_m5_1.

**Extraction Logic:**
1. Read all method parameter declarations
2. Identify any parameters of type `std::vector<T>`
3. Check for the `@restrict` comment annotation on each vector parameter

**Verification Logic:**
1. Every `std::vector` parameter must have `/* @restrict:N */` annotation
2. N must be a positive integer representing the maximum element count
3. Missing `@restrict` on `std::vector` → VIOLATION
4. `@restrict` on non-vector types is advisory (see advisory_m5_1)

**Violation Pattern:** std::vector parameter missing @restrict annotation — required for safe bounds checking

**Fix Example:**

```cpp
// WRONG:
virtual Core::hresult GetItems(std::vector<string>& items /* @out */) = 0;

// Correct:
virtual Core::hresult GetItems(std::vector<string>& items /* @out @restrict:256 */) = 0;
```

**Citation:** `ThunderInterfaces/interfaces/IPackager.h` — @restrict on std::vector

---

## Advisory Rules (4)

### advisory_m1_1 — Single Responsibility Principle

**Severity:** violation

**Description:**  
Each COM interface should have a single, clearly defined responsibility. An interface that mixes unrelated concerns (e.g. audio control + network management) is harder to implement, test, and maintain. If an interface is doing too many unrelated things, it should be split into multiple focused interfaces.

**Extraction Logic:**
1. Read the full interface and identify all the method groups
2. Reason about whether all methods serve a single coherent purpose
3. Look for method groups that could logically belong to separate interfaces

**Verification Logic:**
1. Reason about the interface's overall purpose from its name and method set
2. If methods clearly belong to two or more distinct responsibilities → VIOLATION
3. Minor convenience methods on an otherwise focused interface are acceptable
4. Apply judgment: is the mixing of concerns gratuitous or is there a clear design reason?

**Violation Pattern:** Interface mixes multiple unrelated responsibilities — consider splitting into focused interfaces

**Fix Example:**

```cpp
// WRONG: IDictionaryAndNetwork mixes dictionary and network concerns
struct EXTERNAL IDictionaryAndNetwork : virtual public Core::IUnknown {
    virtual Core::hresult Get(const string& key, string& value) = 0;
    virtual Core::hresult GetNetworkStatus(string& status) = 0;  // ← unrelated
};

// Correct: split into IDictionary and INetwork
```

**Citation:** `ThunderInterfaces/interfaces/IHdmiCecSink.h` — single responsibility

---

### advisory_m2_1 — Enum Underlying Types

**Severity:** warning

**Description:**  
Enums used in interface parameters or return types should use explicit underlying types (`: uint8_t`, `: uint32_t`) for ABI stability.

**Exception:** the anonymous ID enum inside the interface struct (`enum { ID = RPC::ID_* }`) must NOT have an explicit underlying type — this is by Thunder convention. Only named enums that are used as parameter types need explicit underlying types.

**Extraction Logic:**
1. Read all enum declarations in the interface header
2. Identify named enums used as method parameter types
3. Identify the anonymous ID enum `{ ID = RPC::ID_* }`
4. Check for explicit underlying types on named enums

**Verification Logic:**
1. Anonymous ID enum (`enum { ID = RPC::ID_* }`) must NOT have explicit type — skip it
2. Named enums used as parameter types should have explicit underlying types
3. If a named enum used as a parameter lacks an explicit underlying type → WARNING
4. Apply judgment: if the enum range clearly fits a known type, it is advisable

**Violation Pattern:** Named enum used in interface parameter lacks explicit underlying type — consider adding : uint8_t or : uint32_t

**Fix Example:**

```cpp
// WRONG: (named enum without explicit type)
enum State { IDLE, ACTIVE, ERROR };
virtual Core::hresult SetState(const State state) = 0;

// Correct:
enum State : uint8_t { IDLE = 0, ACTIVE = 1, ERROR = 2 };
virtual Core::hresult SetState(const State state) = 0;

// The ID enum stays anonymous (by convention):
enum { ID = RPC::ID_MY_INTERFACE };
```

**Citation:** `ThunderInterfaces/interfaces/IAVInput.h` — explicit enum underlying type

---

### advisory_m3_1 — No Exceptions

**Severity:** violation

**Description:**  
Thunder COM interfaces and their implementations must not use C++ exceptions. Exceptions cannot cross COM/RPC process boundaries safely. All error conditions must be reported via `Core::hresult` return values. Exception specifications (`throw(...)`, `noexcept`) are irrelevant — the real issue is that `throw` statements must not appear in COM implementation code.

**Extraction Logic:**
1. Read all interface method signatures and any associated implementation hints
2. Check for exception specifications or throw annotations
3. If implementation files are accessible, check for throw statements

**Verification Logic:**
1. No exception specifications that imply throws (`throw(...)`) on interface methods
2. `noexcept` specifications are acceptable (they prevent exceptions from propagating)
3. In implementation code: no throw statements in COM method implementations
4. If throw appears in COM code → VIOLATION

**Violation Pattern:** Exception specification or throw statement in COM interface or implementation — use Core::hresult for error reporting

**Fix Example:**

```cpp
// WRONG:
virtual Core::hresult Get(const string& key, string& value) throw(std::exception) = 0;

// Correct:
virtual Core::hresult Get(const string& key, string& value /* @out */) = 0;
// Implementation: return Core::ERROR_NOT_FOUND; instead of throwing
```

**Citation:** `ThunderInterfaces/interfaces/IDictionary.h` — no exceptions in COM interfaces

---

### advisory_m5_1 — @restrict for Non-vector Params

**Severity:** warning

**Description:**  
Parameters with natural upper bounds (strings with max length, integers with max value, buffers with max size) may benefit from `@restrict` annotations to communicate constraints to callers and enable bounds checking in generated code.

> **NOTE:** This rule applies to non-`std::vector` parameters only. `std::vector` parameters are covered by core_17_1 where `@restrict` is MANDATORY. This rule is advisory for non-vector types where bounds are meaningful.

**Extraction Logic:**
1. Read all method parameter declarations
2. Skip `std::vector` parameters (those are covered by core_17_1)
3. For remaining parameters, reason about whether they have natural upper bounds
4. Check for `@restrict` annotations on constrained parameters

**Verification Logic:**
1. Do NOT apply this rule to `std::vector` parameters — core_17_1 covers those
2. For string parameters used as identifiers, keys, or names: consider whether a max length makes sense
3. For integer count/size parameters: consider whether a max value is meaningful
4. If a non-vector parameter clearly has a natural bound but lacks `@restrict` → WARNING (advisory)
5. Apply judgment: not every parameter needs `@restrict` — only those with meaningful constraints

**Violation Pattern:** Non-vector parameter with natural upper bound lacks @restrict annotation (advisory)

**Fix Example:**

```cpp
// Without restriction (acceptable for many cases):
virtual Core::hresult SetName(const string& name) = 0;

// With @restrict for bounded parameters:
virtual Core::hresult SetName(const string& name /* @restrict:64 */) = 0;

// Note: for std::vector, @restrict is MANDATORY (see core_17_1):
virtual Core::hresult GetItems(std::vector<string>& items /* @out @restrict:256 */) = 0;
```

**Citation:** `ThunderInterfaces/interfaces/IVolumeControl.h` — @restrict on bounded params