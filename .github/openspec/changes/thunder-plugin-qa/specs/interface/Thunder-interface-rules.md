# Thunder Interface Validation Rules

**Status:** For Review

## Description

Rules for validating Thunder COM interface headers in `ThunderInterfaces/interfaces/`.

Every rule uses semantic reasoning - read the interface header in full and reason about the code as a human reviewer. Never use regex or text search as the primary detection method.

---

## Summary (19 rules: 16 core + 3 advisory)

| ID | Name | Severity |
|----|------|----------|
| core_1_1 | File Structure | suggestion |
| core_2_1 | Interface Declaration Shape | warning |
| core_3_1 | Interface ID Registration | violation |
| core_4_1 | Pure Virtual Methods Only | warning |
| core_5_1 | Return Type Conventions | violation |
| core_6_1 | Const Correctness | violation |
| core_7_1 | Thunder Type Conventions | violation |
| core_8_1 | Register/Unregister Patterns | violation |
| core_9_1 | Event Interfaces | violation |
| core_10_1 | @json Tag (CRITICAL) | warning |
| core_11_1 | No IUnknown/IReferenceCounted Methods in Interfaces | violation |
| core_12_1 | No std::map in Interfaces | violation |
| core_13_1 | Explicit Integer Widths | violation |
| core_14_1 | @restrict Mandatory with std::vector | violation |
| core_15_1 | No Method Overloads in @json Interfaces | violation |
| core_16_1 | No Reserved JSON-RPC Method Names | violation |
| advisory_m1_1 | Single Responsibility Principle | warning |
| advisory_m2_1 | Enum Underlying Types | warning |
| advisory_m3_1 | No Exceptions | violation |

---

## Core Rules (16)

### core_1_1 - File Structure

**Severity:** suggestion

**Description:**

Thunder interface headers must follow a standard structure:
- File name should match the interface name (IFoo.h for struct EXTERNAL IFoo),
  though exceptions may exist
- No implementation code in interface headers - pure declarations only

**Extraction Logic:**

1. Read the full interface header file
2. Note the file name and the primary interface struct name
3. Check for any non-declaration code (function implementations, static variables, etc.)

**Verification Logic:**

1. Verify the primary interface struct name matches the file name (e.g. IDictionary in IDictionary.h)
   - Exception: multi-interface files or platform-specific groupings may have different naming
2. Verify there is no implementation code - only forward declarations, typedefs, struct/enum declarations
3. If issues are found → SUGGESTION

**Violation Pattern:** File name does not match interface name, or implementation code present in interface header

**Fix Example:**

```cpp
// WRONG: Implementation code in interface header
struct EXTERNAL IDictionary : virtual public Core::IUnknown {
    virtual Core::hresult Get(const string& key, string& value) {
        return Core::ERROR_NONE; // ← implementation code not allowed
    }
};

// Correct: pure declarations only
struct EXTERNAL IDictionary : virtual public Core::IUnknown {
    virtual Core::hresult Get(const string& key, string& value /* @out */) = 0;
};
```

**Citation:** ThunderInterfaces/interfaces/IDictionary.h — Exchange namespace and file naming

---

### core_2_1 — Interface Declaration Shape

**Severity:** warning

**Description:**

Thunder COM interfaces must follow the correct declaration shape:
- Must be a struct (not class) with the EXTERNAL macro
- Must inherit virtually from Core::IUnknown
- Must declare a nested enum with the ID value (RPC::ID_*)
- All methods must be pure virtual

**Extraction Logic:**

1. Read the interface struct declaration
2. Examine the struct keyword, EXTERNAL macro, and inheritance list
3. Check for the nested enum { ID = RPC::ID_* }
4. Examine all method declarations for pure virtual (= 0)

**Verification Logic:**

1. Verify the declaration uses 'struct EXTERNAL IName'
2. Verify inheritance is 'virtual public Core::IUnknown'
3. Verify a nested enum contains ID = RPC::ID_*
4. Verify all methods are pure virtual (= 0)
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

**Citation:** ThunderInterfaces/interfaces/IDictionary.h:LINE — struct EXTERNAL shape

---

### core_3_1 — Interface ID Registration

**Severity:** violation

**Description:**

Every Thunder COM interface must have a unique numeric ID registered in
RPC::IDs (in ThunderInterfaces/interfaces/ids.h or equivalent).
The ID enum value in the struct must reference the registered RPC::ID_* constant.
Sub-interfaces (INotification, ICallback nested in a parent) must also have their
own unique IDs.

ID ranges (defined in Thunder/Source/com/Ids.h):
- Thunder core interfaces: ID_OFFSET_INTERNAL + 0x0001 .. 0x007F
- Extension interfaces: ID_EXTENSIONS_INTERFACE_OFFSET (ID_OFFSET_INTERNAL + 0x0080)
- External (ThunderInterfaces) interfaces: ID_EXTERNAL_INTERFACE_OFFSET (ID_OFFSET_INTERNAL + 0x1000)
- QA interfaces: ID_EXTERNAL_QA_INTERFACE_OFFSET (0xA000)
- Example interfaces: ID_EXTERNAL_EXAMPLE_INTERFACE_OFFSET (0xB000)
- CC interfaces (entservices-apis): ID_EXTERNAL_CC_INTERFACE_OFFSET (0xCC00 .. 0xDFFF)

Interfaces in entservices-apis MUST use IDs within the CC range
(RPC::IDS::ID_EXTERNAL_CC_INTERFACE_OFFSET + offset, range 0xCC00–0xDFFF).

**Extraction Logic:**

1. Read the interface struct declaration and note its ID value
2. Check whether the ID value uses an RPC::ID_* constant
3. Check ids.h (or the ID registration file) for the corresponding entry
4. Determine whether the interface belongs to entservices-apis (CC range) or ThunderInterfaces (external range)

**Verification Logic:**

1. Verify the struct enum { ID = RPC::ID_* } uses a named constant, not a raw number
2. Verify the ID is registered in ThunderInterfaces ids.h (or equivalent)
3. Verify the ID is unique — no other interface uses the same value
4. Nested INotification and ICallback interfaces must also have their own IDs
5. For entservices-apis interfaces: verify the ID falls within the CC range (0xCC00–0xDFFF)
6. If any condition fails → VIOLATION

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

**Citation:** ThunderInterfaces/interfaces/ids.h — ID_DICTIONARY registration

---

### core_4_1 — Pure Virtual Methods Only

**Severity:** warning

**Description:**

Thunder COM interface methods must be pure virtual (= 0). No default
implementations, no inline code, no static methods, no non-virtual methods.
The interface is a pure abstract contract — all implementation is in the
implementing class, not in the interface.

**Extraction Logic:**

1. Read all method declarations in the interface struct
2. Check each method for the = 0 specifier
3. Look for any inline code, default implementations, or static methods

**Verification Logic:**

1. Every method in the interface must end with = 0
2. No method may have a body (even {})
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

**Citation:** ThunderInterfaces/interfaces/IDictionary.h — pure virtual methods

---

### core_5_1 — Return Type Conventions

**Severity:** violation

**Description:**

In Thunder 5.0+, all COM interface methods annotated with @json (i.e. methods
that generate JSON-RPC code) MUST return Core::hresult. Void return types and
other return types are not allowed for JSON-RPC-generating methods.
Methods in pure COM interfaces (no @json) should also use Core::hresult for
error reporting where applicable.

Exceptions:
- Notification/event methods (methods in interfaces tagged with @event, such as
  INotification or ICallback) MUST return void, not Core::hresult.
- Legacy/old interfaces (pre-Thunder 5.0) may not adhere to this rule.

**Extraction Logic:**

1. Read all interface method declarations
2. Note which methods are under a @json-tagged interface or have @json annotations
3. Identify notification/event interfaces (tagged with @event)
4. Check the return type of each method

**Verification Logic:**

1. For interfaces tagged with @json (or in Thunder 5.0+ contexts), all methods must return Core::hresult
2. Exception: methods in @event-tagged notification interfaces MUST return void
3. Void return types are not allowed for non-notification JSON-RPC methods
4. Custom return types (not Core::hresult) for non-status purposes are not allowed — use @out parameters instead
5. Legacy interfaces (pre-Thunder 5.0) may not comply — flag as warning, not violation
6. If any non-notification JSON-RPC method lacks Core::hresult return type → VIOLATION

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

**Citation:** ThunderInterfaces/interfaces/IAudioOutput.h — Core::hresult return types

---

### core_6_1 — Const Correctness

**Severity:** violation

**Description:**

Interface methods must use const correctly:
- Input-only parameters should be const (const string& key)
- Output parameters should be non-const references (string& value)
- Methods that do not modify the object should be const (though pure virtual const is rare)
- @out parameters must be non-const references to allow the implementation to write
- Notification methods (methods in INotification/ICallback interfaces) should NEVER be const —
  the implementation needs to modify state when handling notifications

**Extraction Logic:**

1. Read all method parameter declarations
2. Examine const qualifiers on each parameter
3. Identify parameters marked @out and verify they are non-const references
4. Identify input parameters and verify they are const where appropriate

**Verification Logic:**

1. @out parameters must be non-const references (string& value, not const string& value)
2. Input parameters that are passed by value or const ref are correct
3. Non-const reference parameters without @out indicate potential API design issues
4. If @out parameters are const (preventing write) → VIOLATION

**Violation Pattern:** @out parameter declared const preventing the implementation from writing the output value

**Fix Example:**

```cpp
// WRONG:
virtual Core::hresult Get(const string& key, const string& value /* @out */) = 0;
//                                              ^^^^^  ← const prevents writing

// Correct:
virtual Core::hresult Get(const string& key, string& value /* @out */) = 0;
```

**Citation:** ThunderInterfaces/interfaces/IDictionary.h — const correctness on @out params

---

### core_7_1 — Thunder Type Conventions

**Severity:** violation

**Description:**

Thunder interfaces must use Thunder type aliases, not std:: types directly:
- string (not std::string) for text
- Core::hresult (not HRESULT or int) for error returns
- uint8_t, uint16_t, uint32_t, uint64_t (not int, long, short)
- bool (acceptable) but not BOOL
Using std::string in interfaces breaks cross-ABI compatibility.

**Extraction Logic:**

1. Read all method parameter types and return types in the interface
2. Identify any std:: type usage (std::string, std::vector without @restrict review)
3. Check for non-Thunder integer types (int, long, short, BOOL, HRESULT)

**Verification Logic:**

1. std::string in interface parameters → VIOLATION (use string)
2. HRESULT or raw int for error codes → VIOLATION (use Core::hresult)
3. Non-width-specific integer types (int, long) for interface params → check core_13_1
4. BOOL → VIOLATION (use bool)
5. If std::string found → VIOLATION

**Violation Pattern:** std::string used in interface — must use Thunder string type alias

**Fix Example:**

```cpp
// WRONG:
virtual Core::hresult Get(const std::string& key, std::string& value) = 0;

// Correct:
virtual Core::hresult Get(const string& key, string& value /* @out */) = 0;
```

**Citation:** ThunderInterfaces/interfaces/IDictionary.h — Thunder string type alias

---

### core_8_1 — Register/Unregister Patterns

**Severity:** violation

**Description:**

Notification interfaces follow two patterns:
- INotification (1:many observer): Register(INotification*) and Unregister(INotification*)
  for multiple simultaneous subscribers
- ICallback (1:1 callback): Callback(ICallback*) sets a single callback (nullptr to clear)
Register/Unregister must take a pointer to the notification interface.
ICallback::Callback() replaces the previous callback, so no Unregister needed.

**Extraction Logic:**

1. Read the interface for Register/Unregister/Callback method declarations
2. Identify whether it follows the INotification (1:many) or ICallback (1:1) pattern
3. Check the method signatures

**Verification Logic:**

1. INotification pattern: must have both Register(INotification*) and Unregister(INotification*)
2. ICallback pattern: must have Callback(ICallback*) accepting nullptr to clear
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
virtual Core::hresult Unregister(INotification* notification) = 0;

// Correct — ICallback (1:1, nullptr clears):
virtual Core::hresult Callback(ICallback* callback) = 0;
```

**Citation:** ThunderInterfaces/interfaces/IDictionary.h — Register/Unregister pattern

---

### core_9_1 — Event Interfaces

**Severity:** violation

**Description:**

Event/notification interfaces must:
- Have the @event tag (// @event) above the struct declaration
- Use EXTERNAL in the struct declaration
- Have their own unique ID in the RPC ID list
- Inherit from Core::IUnknown (not from the parent interface)
Missing @event prevents the code generator from emitting event dispatch code.

**Extraction Logic:**

1. Read the interface for any struct declarations that represent a notification/event (INotification, ICallback, etc.)
2. Check for the @event comment tag above the declaration
3. Check for EXTERNAL in the declaration
4. Check for an enum { ID = RPC::ID_* }

**Verification Logic:**

1. Every event/notification interface must have // @event immediately above the struct
2. Must use EXTERNAL in the declaration
3. Must have its own ID in the RPC ID list
4. Must inherit from Core::IUnknown
5. If any condition fails → VIOLATION

**Violation Pattern:** @event tag missing on notification interface, or missing EXTERNAL/ID

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

**Citation:** ThunderInterfaces/interfaces/IDictionary.h — @event tag on INotification

---

### core_10_1 — @json Tag (CRITICAL)

**Severity:** warning

**Description:**

Without the @json tag, ZERO JSON-RPC code is generated for the interface.
This is the most common critical omission. The tag must appear immediately
above the struct declaration as: // @json 1.0.0
No blank lines are allowed between the @json tag and the struct declaration.
If an interface intentionally does not need JSON-RPC (pure COM only), the
absence of @json is acceptable — but this must be an intentional design choice.

Hints that an interface was meant to be a JSON-RPC interface:
- Presence of tags like @alias, @text, @opaque, @bitmask, @index in comments
- Methods using @in/@out parameter annotations
- Interface resembles a service API (properties, events, methods)
If such hints are present but @json is missing, flag as warning and ask
whether the interface was intended to generate JSON-RPC code.

**Extraction Logic:**

1. Read the lines immediately above the 'struct EXTERNAL I...' declaration
2. Look for a // @json comment with a version number
3. Check there are no blank lines between the tag and the struct declaration

**Verification Logic:**

1. If the interface is intended to generate JSON-RPC code: verify // @json N.N.N appears immediately above the struct declaration
2. No blank lines between the @json tag and the struct line
3. If the interface is intentionally JSON-RPC-free (pure COM) → acceptable, note as design choice
4. If @json is missing from an interface that should have it → VIOLATION

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

**Citation:** ThunderInterfaces/interfaces/IDictionary.h:LINE — @json 1.0.0 above struct

---

### core_11_1 — No IUnknown/IReferenceCounted Methods in Interfaces

**Severity:** violation

**Description:**

Methods inherited from Core::IUnknown or Core::IReferenceCounted (AddRef, Release,
QueryInterface) must NOT be redeclared in interface structs. These are provided by
the base class and redeclaring them creates separate vtable entries, breaking COM
reference counting and causing crashes.

**Extraction Logic:**

1. Read all method declarations in the interface struct (including nested structs)
2. Look for any AddRef(), Release(), or QueryInterface() declarations

**Verification Logic:**

1. The interface must not declare AddRef(), Release(), or QueryInterface()
2. These methods are inherited from Core::IUnknown via the virtual inheritance chain
3. If any IUnknown/IReferenceCounted method appears as an interface method → VIOLATION

**Violation Pattern:** IUnknown/IReferenceCounted method (AddRef, Release, QueryInterface) declared in interface — must be inherited only

**Fix Example:**

```cpp
// WRONG:
struct EXTERNAL IDictionary : virtual public Core::IUnknown {
    virtual uint32_t AddRef() const = 0;        // ← DO NOT REDECLARE
    virtual uint32_t Release() const = 0;       // ← DO NOT REDECLARE
    virtual void* QueryInterface(uint32_t) = 0; // ← DO NOT REDECLARE
    virtual Core::hresult Get(const string& key, string& value) = 0;
};

// Correct:
struct EXTERNAL IDictionary : virtual public Core::IUnknown {
    enum { ID = RPC::ID_DICTIONARY };
    virtual Core::hresult Get(const string& key, string& value /* @out */) = 0;
};
```

**Citation:** ThunderInterfaces/interfaces/IDictionary.h — IUnknown methods inherited only
ThunderInterfaces/interfaces/IDictionary.h — AddRef/Release inherited from Core::IUnknown

---

### core_12_1 — No std::map in Interfaces

**Severity:** violation

**Description:**

std::map (and other std:: associative containers) must not appear as interface
method parameters or return types. std::map is not serialisable across process
boundaries via Thunder's RPC mechanism and causes code generation failures.
Use structured types, repeated calls, or JSON containers instead.

**Extraction Logic:**

1. Read all method parameter types in the interface
2. Look for std::map, std::unordered_map, std::multimap, or similar associative containers

**Verification Logic:**

1. Any std::map or similar associative container in method parameters → VIOLATION
2. Consider whether a Core::JSON::Container or repeated method calls can replace it
3. If std::map found in interface → VIOLATION

**Violation Pattern:** std::map used in interface parameter — not serialisable across process boundaries

**Fix Example:**

```cpp
// WRONG:
virtual Core::hresult GetAll(std::map<string, string>& values /* @out */) = 0;

// Correct: use repeated queries or a structured type
virtual Core::hresult GetKeys(RPC::IStringIterator*& keys /* @out */) = 0;
virtual Core::hresult Get(const string& key, string& value /* @out */) = 0;
```

**Citation:** ThunderInterfaces/interfaces/IDictionary.h — no std::map in interfaces

---

### core_13_1 — Explicit Integer Widths

**Severity:** violation

**Description:**

Interface method parameters and return values must use explicit-width integer
types (uint8_t, uint16_t, uint32_t, uint64_t, int32_t, etc.) rather than
platform-dependent types (int, long, short, size_t, unsigned int).
Implicit-width types change size between platforms and break binary compatibility.

**Extraction Logic:**

1. Read all method parameter types and return types
2. Identify any integer parameters using platform-dependent types

**Verification Logic:**

1. int, long, short, unsigned int, unsigned long, size_t in interface parameters → VIOLATION
2. char is acceptable for character data; bool is acceptable
3. uint8_t, uint16_t, uint32_t, uint64_t, int32_t etc. are correct
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

**Citation:** ThunderInterfaces/interfaces/IVolume.h — explicit integer widths

---

### core_14_1 — @restrict Mandatory with std::vector

**Severity:** violation

**Description:**

Every interface method parameter of type std::vector (or Core::JSON::ArrayType equivalent)
MUST be annotated with /* @restrict:N */ where N is the maximum allowed element count.
Without @restrict, the code generator cannot produce safe bounds-checking code and may
generate unbounded deserialization that is exploitable.
Note: This rule specifically applies to std::vector.

**Extraction Logic:**

1. Read all method parameter declarations
2. Identify any parameters of type std::vector<T>
3. Check for the @restrict comment annotation on each vector parameter

**Verification Logic:**

1. Every std::vector parameter must have /* @restrict:N */ annotation
2. N must be a positive integer representing the maximum element count
3. Missing @restrict on std::vector → VIOLATION
4. @restrict on non-vector types is not enforced by this rule

**Violation Pattern:** std::vector parameter missing @restrict annotation — required for safe bounds checking

**Fix Example:**

```cpp
// WRONG:
virtual Core::hresult GetItems(std::vector<string>& items /* @out */) = 0;

// Correct:
virtual Core::hresult GetItems(std::vector<string>& items /* @out @restrict:256 */) = 0;
```

**Citation:** ThunderInterfaces/interfaces/IPackager.h — @restrict on std::vector

---

### core_15_1 — No Method Overloads in @json Interfaces

**Severity:** violation

**Description:**

In interfaces tagged with @json, method names must be unique — no C++ overloads
are allowed because JSON-RPC dispatches by method name string only (no signature
overload resolution). Methods that would be overloads in C++ will produce duplicate
JSON-RPC method names, causing code generation failures or undefined dispatch behavior.
Note: @text tags can change the JSON-RPC method name. When checking for duplicates,
use the effective JSON-RPC name (i.e. the @text value if present, otherwise the C++ name).
Two methods with different C++ names but the same @text value also collide.

**Extraction Logic:**

1. Read all method declarations in @json-tagged interfaces
2. For each method, determine the effective JSON-RPC name:
   - If @text annotation is present, use that as the name
   - Otherwise use the C++ method name
3. Collect all effective names into a list

**Verification Logic:**

1. Check for any duplicate effective JSON-RPC method names
2. Two methods with the same C++ name (overloads) → VIOLATION
3. Two methods with different C++ names but the same @text value → VIOLATION
4. If any duplicates are found → VIOLATION

**Violation Pattern:** Duplicate JSON-RPC method name in @json interface — overloads not allowed

**Fix Example:**

```cpp
// WRONG — overloaded methods produce duplicate JSON-RPC names:
// @json 1.0.0
struct EXTERNAL IDictionary : virtual public Core::IUnknown {
    virtual Core::hresult Get(const string& key, string& value /* @out */) = 0;
    virtual Core::hresult Get(const uint32_t index, string& value /* @out */) = 0; // ← overload!
};

// Correct — use distinct names:
// @json 1.0.0
struct EXTERNAL IDictionary : virtual public Core::IUnknown {
    virtual Core::hresult Get(const string& key, string& value /* @out */) = 0;
    virtual Core::hresult GetByIndex(const uint32_t index, string& value /* @out */) = 0;
};

// Also WRONG — @text collision:
virtual Core::hresult GetValue(const string& key, string& value /* @out */) = 0;      // @text get
virtual Core::hresult GetStatus(string& status /* @out */) = 0;                        // @text get  ← collision!
```

**Citation:** ThunderInterfaces/interfaces/ — no overloads in @json interfaces

---

### core_16_1 — No Reserved JSON-RPC Method Names

**Severity:** violation

**Description:**

Interfaces tagged with @json must not declare methods with names that collide
with built-in JSON-RPC framework methods. The following names are reserved by
the Thunder JSON-RPC infrastructure and will conflict:
- Version / Versions (built-in version query)
- exists (built-in method existence check)
These names will cause conflicts with the framework's built-in handlers,
leading to undefined dispatch behavior or shadowing.
Check both the C++ method name and any @text annotation for collisions.

**Extraction Logic:**

1. Read all method declarations in @json-tagged interfaces
2. For each method, determine the effective JSON-RPC name (@text or C++ name)
3. Compare against the reserved name list: version, versions, exists (case-insensitive)

**Verification Logic:**

1. If any method's effective JSON-RPC name matches a reserved name (case-insensitive) → VIOLATION
2. Reserved names: "version", "versions", "exists"
3. Check both the bare method name and any @text annotation
4. If collision found → VIOLATION

**Violation Pattern:** Interface method uses a reserved JSON-RPC name (version/versions/exists) — conflicts with built-in framework handlers

**Fix Example:**

```cpp
// WRONG — collides with built-in JSON-RPC 'exists' method:
virtual Core::hresult Exists(const string& key, bool& result /* @out */) = 0;

// Correct — use a non-reserved name:
virtual Core::hresult Contains(const string& key, bool& result /* @out */) = 0;

// WRONG — collides with built-in 'version':
virtual Core::hresult Version(string& version /* @out */) = 0;

// Correct:
virtual Core::hresult GetVersion(string& version /* @out */) = 0;
```

**Citation:** Thunder JSON-RPC framework — reserved method names

---

## Advisory Rules (3)

### advisory_m1_1 — Single Responsibility Principle

**Severity:** warning

**Description:**

Each COM interface should have a single, clearly defined responsibility.
An interface that mixes unrelated concerns (e.g. audio control + network management)
is harder to implement, test, and maintain. If an interface is doing too many
unrelated things, it should be split into multiple focused interfaces.

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

**Citation:** ThunderInterfaces/interfaces/IHdmiCecSink.h — single responsibility

---

### advisory_m2_1 — Enum Underlying Types

**Severity:** warning

**Description:**

Enums used in interface parameters or return types should use explicit underlying
types (: uint8_t, : uint32_t) for ABI stability.
Exception: the anonymous ID enum inside the interface struct (enum { ID = RPC::ID_* })
must NOT have an explicit underlying type — this is by Thunder convention.
Only named enums that are used as parameter types need explicit underlying types.

**Extraction Logic:**

1. Read all enum declarations in the interface header
2. Identify named enums used as method parameter types
3. Identify the anonymous ID enum { ID = RPC::ID_* }
4. Check for explicit underlying types on named enums

**Verification Logic:**

1. Anonymous ID enum (enum { ID = RPC::ID_* }) must NOT have explicit type — skip it
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

**Citation:** ThunderInterfaces/interfaces/IAVInput.h — explicit enum underlying type

---

### advisory_m3_1 — No Exceptions

**Severity:** violation

**Description:**

Thunder COM interfaces and their implementations must not use C++ exceptions.
Exceptions cannot cross COM/RPC process boundaries safely.
All error conditions must be reported via Core::hresult return values.
Exception specifications (throw(...), noexcept) are irrelevant — the real
issue is that throw statements must not appear in COM implementation code.

**Extraction Logic:**

1. Read all interface method signatures and any associated implementation hints
2. Check for exception specifications or throw annotations
3. If implementation files are accessible, check for throw statements

**Verification Logic:**

1. No exception specifications that imply throws (throw(...)) on interface methods
2. noexcept specifications are acceptable (they prevent exceptions from propagating)
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

**Citation:** ThunderInterfaces/interfaces/IDictionary.h — no exceptions in COM interfaces

---