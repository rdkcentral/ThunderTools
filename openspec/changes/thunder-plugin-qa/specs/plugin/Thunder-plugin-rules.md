# Thunder Plugin Rules — v3.3.0

> **Purpose:** This document is the authoritative checklist for every Thunder plugin PR review.
> Every rule listed here must be verified before a PR is approved.
> Violations and warnings must be addressed; suggestions are encouraged but not blocking.

---

## How to Use This Document

1. **Read the full plugin first** — all source files, headers, CMakeLists, and config.
   Build a mental model of the plugin's architecture, lifecycle, threading model, and ownership before checking any individual rule.
2. **Check each rule** using the full context, not in isolation.
3. **Cite violations** with exact file and line number (e.g. `[Dictionary.cpp:108]`).
4. **Show the fix** — the corrected code block only, not the whole file.
5. **Never escalate severity** beyond what is defined per rule.

### Severity Levels

| Level | Meaning |
|---|---|
| `violation` | **Blocking.** PR cannot be merged until fixed. |
| `warning` | **Should fix.** Strong recommendation; reviewer discretion for blocking. |
| `suggestion` | **Nice to have.** Non-blocking improvement. |

---

## Rule Index

| # | Rule Name | Severity | Phase |
|---|---|---|---|
| [rule_01](#rule_01) | MODULE_NAME Plugin_ Prefix | suggestion | Module Structure |
| [rule_02](#rule_02) | MODULE_NAME_DECLARATION | violation | Module Structure |
| [rule_03](#rule_03) | Module.h Uses #pragma once | warning | Module Structure |
| [rule_04](#rule_04) | VARIABLE_IS_NOT_USED Accuracy | violation | Code Style |
| [rule_05](#rule_05) | Error Code Preservation | violation | Code Style |
| [rule_06](#rule_06) | NULL vs nullptr | warning | Code Style |
| [rule_07](#rule_07) | No delete on COM Interface Pointers | violation | Code Style |
| [rule_08](#rule_08) | nullptr After Release | violation | Code Style |
| [rule_09](#rule_09) | No QueryInterfaceByCallsign as Member | violation | Code Style |
| [rule_10](#rule_10) | No Smart Pointers on COM Objects | violation | Code Style |
| [rule_11](#rule_11) | No SmartLinkType for COMRPC Plugins | violation | Code Style |
| [rule_12](#rule_12) | No delete on Plugin Object | violation | Code Style |
| [rule_13](#rule_13) | No throw Keyword in Plugin Code | violation | Code Style |
| [rule_14](#rule_14) | Special Members Deleted (Main Class) | warning | Class Registration |
| [rule_15](#rule_15) | Plugin Metadata Registration | violation | Class Registration |
| [rule_16](#rule_16) | JSONRPC Inheritance When Used | violation | Class Registration |
| [rule_17](#rule_17) | IShell AddRef in Initialize | violation | Lifecycle |
| [rule_18](#rule_18) | IShell Release in Deinitialize | violation | Lifecycle |
| [rule_19](#rule_19) | Information() Method | violation | Lifecycle |
| [rule_20](#rule_20) | Root\<T\>() Null Check | violation | Lifecycle |
| [rule_21](#rule_21) | Root\<T\>() Release in Deinitialize | violation | Lifecycle |
| [rule_22](#rule_22) | Observer Cleanup in Deinitialize | violation | Lifecycle |
| [rule_23](#rule_23) | SubSystems() Release in Deinitialize | violation | Lifecycle |
| [rule_24](#rule_24) | Constructor Must Be Empty | violation | Lifecycle |
| [rule_25](#rule_25) | service->Register/Unregister Pairing | violation | Lifecycle |
| [rule_26](#rule_26) | Initialize Returns Error String on Failure | violation | Lifecycle |
| [rule_27](#rule_27) | No Manual Deinitialize() in Initialize | violation | Lifecycle |
| [rule_28](#rule_28) | Destructor Must Be Empty | violation | Lifecycle |
| [rule_29](#rule_29) | JSON-RPC Register/Unregister Pairing | violation | Implementation |
| [rule_30](#rule_30) | SinkType Pattern for Subscribers | violation | Implementation |
| [rule_31](#rule_31) | Unavailable() in SinkType Classes | violation | Implementation |
| [rule_32](#rule_32) | No Hardcoded Paths | violation | Implementation |
| [rule_33](#rule_33) | OOP Connection Termination in Deinitialize | violation | Out-of-Process |
| [rule_34](#rule_34) | connectionId Checked in IRemoteConnection Callbacks | violation | Out-of-Process |
| [rule_35](#rule_35) | Startmode Declaration | violation | Configuration |
| [rule_36](#rule_36) | Config Core::JSON::Container | violation | Configuration |
| [rule_37](#rule_37) | No Hardcoded Numeric Tuning Parameters | violation | Configuration |
| [rule_38](#rule_38) | CXX_STANDARD Uses Thunder Variable | violation | CMake |
| [rule_39](#rule_39) | COM Methods Return Core::hresult | violation | COM Interface |
| [rule_40](#rule_40) | #pragma once (all headers) | suggestion | Conventions |
| [rule_41](#rule_41) | Apache 2.0 Copyright Header | suggestion | Conventions |
| [rule_42](#rule_42) | STL Types | warning | Code Quality |
| [rule_43](#rule_43) | ASSERT vs Error Handling | warning | Code Quality |
| [rule_44](#rule_44) | OOP Registration Order | violation | Lifecycle Integrity |
| [rule_45](#rule_45) | Complete State Reset in Deinitialize | violation | Lifecycle Integrity |
| [rule_46](#rule_46) | Reverse-Order Cleanup | suggestion | Lifecycle Integrity |
| [rule_47](#rule_47) | Observer Locking | violation | Concurrency |
| [rule_48](#rule_48) | AddRef/Release Balance | violation | COM Safety |
| [rule_49](#rule_49) | CMake NAMESPACE Variable | suggestion | Conventions |
| [rule_50](#rule_50) | Handlers Must Not Block | violation | Concurrency |
| [rule_51](#rule_51) | No Activate/Deactivate from Handlers | violation | Concurrency |
| [rule_52](#rule_52) | Shared State Protected by CriticalSection | violation | Concurrency |
| [rule_53](#rule_53) | No Lock Held During Framework Callbacks | violation | Concurrency |
| [rule_54](#rule_54) | Worker Jobs Check Deinitialize Guard | violation | Concurrency |
| [rule_55](#rule_55) | File Descriptors / Sockets Wrapped in RAII | violation | Resource Management |
| [rule_56](#rule_56) | No Unbounded Memory Growth | violation | Resource Management |
| [rule_57](#rule_57) | Config Errors Return Non-Empty from Initialize | violation | Lifecycle Integrity |
| [rule_58](#rule_58) | interface->Register/Unregister Pairing | violation | JSON-RPC Compliance |
| [rule_59](#rule_59) | Handler Registration Order | violation | JSON-RPC Compliance |
| [rule_60](#rule_60) | Use Core::ERROR_* for Handler Failure Codes | violation | JSON-RPC Compliance |
| [rule_61](#rule_61) | Input Validation in JSON-RPC Handlers | violation | JSON-RPC Compliance |
| [rule_62](#rule_62) | Event Constants and Typed JSON Payloads | warning | JSON-RPC Compliance |
| [rule_63](#rule_63) | COM Reference Counting Correctness | violation | COM Safety |
| [rule_64](#rule_64) | No Hard Inter-Plugin Dependencies | warning | Inter-Plugin Design |
| [rule_65](#rule_65) | JSON-RPC Handlers Are Re-entrant Safe | violation | Concurrency |
| [rule_66](#rule_66) | IPlugin::INotification Callbacks Must Not Block | violation | Concurrency |
| [rule_67](#rule_67) | Lock Scope Minimized | violation | Concurrency |
| [rule_68](#rule_68) | Plugin Threads Joined in Deinitialize | violation | Concurrency |
| [rule_69](#rule_69) | Memory and Allocation Safety | warning | Resource Management |
| [rule_70](#rule_70) | Framework Pointers Not Accessed After Deinitialize | violation | Lifecycle Integrity |
| [rule_71](#rule_71) | hresult Return Values Checked | violation | COM Safety |
| [rule_72](#rule_72) | ASSERT Only for Programmer Invariants | warning | Code Quality |
| [rule_73](#rule_73) | Security: Logging, Shell, Path, and Error Exposure | violation | Code Quality |
| [rule_74](#rule_74) | JSON-RPC Input Validation for Bounds and Types | violation | JSON-RPC Compliance |
| [rule_75](#rule_75) | Config Completeness and Resource Cleanup | warning | Code Quality |
| [rule_76](#rule_76) | OOP Error Propagation and Method Naming | warning | Inter-Plugin Design |
| [rule_77](#rule_77) | Observer Classes Private and Nested | suggestion | Conventions |
| [rule_78](#rule_78) | No Deprecated JSON-RPC APIs | violation | JSON-RPC Compliance |
| [rule_79](#rule_79) | All Acquired Pointers Cleared After Deinitialize | violation | Lifecycle Integrity |

---

## Phase 1 — Module Structure

---

### rule_01

**MODULE_NAME Plugin_ Prefix** | `suggestion`

**What to check:** The `#define MODULE_NAME` value in `Module.h` must start with the `Plugin_` prefix.

**Where to look:** `Module.h` — the `#define MODULE_NAME ...` line.

**Violation pattern:** `MODULE_NAME` value does not start with `Plugin_`.

```cpp
// WRONG:
#define MODULE_NAME Dictionary

// Correct:
#define MODULE_NAME Plugin_Dictionary
```

**Citation format:** `[Module.h:LINE] MODULE_NAME value does not use Plugin_ prefix`

---

### rule_02

**MODULE_NAME_DECLARATION** | `violation`

**What to check:** `Module.cpp` must contain `MODULE_NAME_DECLARATION(BUILD_REFERENCE)`.

**Where to look:** `Module.cpp` — look for the macro invocation. Argument must be `BUILD_REFERENCE`, not empty or a hardcoded string.

**Violation pattern:** `MODULE_NAME_DECLARATION(BUILD_REFERENCE)` absent from `Module.cpp`.

```cpp
// WRONG: (macro missing)

// Correct:
MODULE_NAME_DECLARATION(BUILD_REFERENCE)
```

**Citation format:** `[Module.cpp:LINE] MODULE_NAME_DECLARATION(BUILD_REFERENCE) not found`

---

### rule_03

**Module.h Uses #pragma once** | `warning`

**What to check:** `Module.h` must use `#pragma once` — not a legacy `#ifndef`/`#define`/`#endif` guard.

**Where to look:** First 10 lines of `Module.h`.

**Violation pattern:** Legacy `#ifndef` guard used instead of `#pragma once`.

```cpp
// WRONG:
#ifndef __MODULE_H
#define __MODULE_H
// ...
#endif

// Correct:
#pragma once
// ...
```

**Citation format:** `[Module.h:LINE] Legacy #ifndef guard — use #pragma once`

---

## Phase 2 — Code Style

---

### rule_04

**VARIABLE_IS_NOT_USED Accuracy** | `violation`

**What to check:** Every parameter annotated with `VARIABLE_IS_NOT_USED` must genuinely be unused in the function body. Read the complete function body — not just the signature.

**Where to look:** All functions using `VARIABLE_IS_NOT_USED` in any form (inline annotation in signature or macro call in body).

**Violation pattern:** `VARIABLE_IS_NOT_USED` applied to a parameter that is actually referenced in the function body.

```cpp
// WRONG:
void Callback(VARIABLE_IS_NOT_USED const string& name, const uint32_t value) {
    ProcessValue(name, value);  // 'name' IS used
}

// Correct:
void Callback(const string& name, const uint32_t value) {
    ProcessValue(name, value);
}
```

**Citation format:** `[PluginName.cpp:LINE] VARIABLE_IS_NOT_USED on parameter that is actually used`

---

### rule_05

**Error Code Preservation** | `violation`

**What to check:** An error code variable that is conditionally set to a failure value must never be unconditionally overwritten with `ERROR_NONE` / `SUCCESS` afterward.

**Where to look:** All function bodies that contain error code variables (`result`, `errorCode`, `ret`, etc.).

**Violation pattern:** Conditional error assignment followed by an unconditional `ERROR_NONE` assignment.

```cpp
// WRONG:
uint32_t result = Core::ERROR_NONE;
if (condition) {
    result = Core::ERROR_GENERAL;
}
result = Core::ERROR_NONE;  // overwrites the conditional failure

// Correct:
uint32_t result = Core::ERROR_NONE;
if (condition) {
    result = Core::ERROR_GENERAL;
}
return result;
```

**Citation format:** `[PluginName.cpp:LINE] Error code unconditionally overwritten after conditional failure assignment`

---

### rule_06

**NULL vs nullptr** | `warning`

**What to check:** `nullptr` must be used exclusively as the null pointer literal. `NULL` must not appear as a pointer value in code (assignments, comparisons, function arguments). Exclude `NULL` inside string literals and comments.

**Where to look:** All function bodies and variable declarations.

**Violation pattern:** `NULL` used as a null pointer value in code.

```cpp
// WRONG:
IPlugin* plugin = NULL;
if (service == NULL) { ... }

// Correct:
IPlugin* plugin = nullptr;
if (service == nullptr) { ... }
```

**Citation format:** `[PluginName.cpp:LINE] NULL used as null pointer — use nullptr`

---

### rule_07

**No delete on COM Interface Pointers** | `violation`

**What to check:** `delete` or `delete[]` must never be used on a COM interface pointer (`I*` types). COM interfaces must use `Release()` for cleanup.

**Where to look:** All `delete` expressions in function bodies. Reason about the type of the deleted pointer from its declaration, name (`I` prefix convention), and usage context.

**Violation pattern:** `delete` used on a COM interface pointer.

```cpp
// WRONG:
delete _service;      // COM interfaces must NOT be deleted

// Correct:
_service->Release();
_service = nullptr;
```

**Citation format:** `[PluginName.cpp:LINE] delete used on COM interface pointer — use Release()`

---

### rule_08

**nullptr After Release** | `violation`

**What to check:** Every `->Release()` call on a member variable must be immediately followed by assigning `nullptr` to that member.

**Where to look:** All `->Release()` calls on member variables (prefixed with `_` or `this->` per Thunder convention).

**Violation pattern:** Member pointer not set to `nullptr` immediately after `->Release()`.

```cpp
// WRONG:
_service->Release();
// other code, no nullptr assignment

// Correct:
_service->Release();
_service = nullptr;
```

**Citation format:** `[PluginName.cpp:LINE] _service->Release() not followed by _service = nullptr`

---

### rule_09

**No QueryInterfaceByCallsign as Member** | `violation` | *Conditional: skip if no `QueryInterfaceByCallsign()` calls exist*

**What to check:** The result of `QueryInterfaceByCallsign()` must be used transiently — acquired, used, and released within the same scope. It must never be stored as a class member variable.

**Where to look:** All `QueryInterfaceByCallsign()` call sites and the storage of their return values.

**Violation pattern:** `QueryInterfaceByCallsign()` result stored as a member variable.

```cpp
// WRONG:
_remotePlugin = _service->QueryInterfaceByCallsign<IPlugin>("RemotePlugin");
// _remotePlugin stored as member, not released until Deinitialize

// Correct:
IPlugin* plugin = _service->QueryInterfaceByCallsign<IPlugin>("RemotePlugin");
if (plugin != nullptr) {
    plugin->SomeOperation();
    plugin->Release();
    plugin = nullptr;
}
```

**Citation format:** `[PluginName.cpp:LINE] QueryInterfaceByCallsign() result stored as member variable`

---

### rule_10

**No Smart Pointers on COM Objects** | `violation`

**What to check:** COM interface pointers (`I*` types) must never be wrapped in `shared_ptr` or `unique_ptr`. COM interfaces manage their own lifetime via `AddRef`/`Release` — smart pointers cause double-delete.

**Where to look:** All class member declarations and local variable declarations.

**Violation pattern:** COM interface pointer wrapped in a smart pointer.

```cpp
// WRONG:
std::shared_ptr<IPlugin> _plugin;
std::unique_ptr<IDictionary> _dict;

// Correct:
IPlugin* _plugin = nullptr;
IDictionary* _dict = nullptr;
// Release manually in Deinitialize()
```

**Citation format:** `[PluginName.h:LINE] COM interface wrapped in smart pointer`

---

### rule_11

**No SmartLinkType for COMRPC Plugins** | `violation`

**What to check:** `SmartLinkType` is deprecated. COMRPC plugins must use direct interface pointers, not `SmartLinkType`.

**Where to look:** All class declarations, member variable definitions, and `typedef`/`using` statements.

**Violation pattern:** `SmartLinkType` found anywhere in the plugin.

```cpp
// WRONG:
SmartLinkType<IPlugin, RPC::ID_PLUGIN, &RPC::metadata<IPlugin>> _link;

// Correct:
IPlugin* _plugin = nullptr;
// Acquire via QueryInterface, release in Deinitialize
```

**Citation format:** `[PluginName.h:LINE] SmartLinkType used — deprecated, use direct interface pointer`

---

### rule_12

**No delete on Plugin Object** | `violation`

**What to check:** `delete this` must never appear in plugin code. The Thunder framework owns the plugin object's lifetime.

**Where to look:** All function bodies in the plugin.

**Violation pattern:** `delete this` used in plugin code.

```cpp
// WRONG:
void SomeMethod() {
    if (done) {
        delete this;   // Thunder framework owns this object
    }
}

// Correct: signal to the framework instead
void SomeMethod() {
    if (done) {
        _service->Submit(PluginHost::IShell::DEACTIVATED, this);
    }
}
```

**Citation format:** `[PluginName.cpp:LINE] delete this used — plugin lifetime is framework-managed`

---

### rule_13

**No throw Keyword in Plugin Code** | `violation`

**What to check:** The `throw` keyword must not appear in any executable plugin code. Exceptions cannot cross COM boundaries. Exclude `throw` inside string literals and comments.

**Where to look:** All function bodies, read as a human reviewer.

**Violation pattern:** `throw` used in executable plugin code.

```cpp
// WRONG:
string Initialize(PluginHost::IShell* service) {
    if (!Init()) throw std::runtime_error("Init failed");
    return {};
}

// Correct:
string Initialize(PluginHost::IShell* service) {
    if (!Init()) return "Initialization failed";
    return {};
}
```

**Citation format:** `[PluginName.cpp:LINE] throw keyword used — use return error string instead`

---

## Phase 3 — Class Registration

---

### rule_14

**Special Members Deleted (Main Class)** | `warning`

**What to check:** The main plugin class (the one implementing `PluginHost::IPlugin`) must explicitly delete all 4 special members: copy constructor, copy assignment, move constructor, move assignment. Internal helper classes (`Notification`, `Sink`, `Config`, `JobWorker`, etc.) are explicitly excluded from this rule.

**Where to look:** The main plugin class declaration in the plugin header file.

**Violation pattern:** One or more of the 4 special members are not explicitly deleted.

```cpp
// WRONG: (one or more missing)
class Dictionary : public PluginHost::IPlugin {
public:
    Dictionary() = default;
    Dictionary(const Dictionary&) = delete;
    // Missing: move ctor, copy assign, move assign
};

// Correct:
class Dictionary : public PluginHost::IPlugin {
public:
    Dictionary() = default;
    Dictionary(const Dictionary&) = delete;
    Dictionary& operator=(const Dictionary&) = delete;
    Dictionary(Dictionary&&) = delete;
    Dictionary& operator=(Dictionary&&) = delete;
};
```

**Citation format:** `[PluginName.h:LINE] Not all 4 special members deleted in main plugin class`

---

### rule_15

**Plugin Metadata Registration** | `violation`

**What to check:** The plugin `.cpp` file must contain a `static Plugin::Metadata<PluginName>` registration. This registers the plugin with the Thunder framework.

**Where to look:** `PluginName.cpp`.

**Violation pattern:** `Plugin::Metadata<PluginName>` registration absent.

```cpp
// Correct — add to PluginName.cpp:
static Plugin::Metadata<Dictionary> metadata(
    Plugin::Information<Dictionary>::Versions,
    Plugin::Information<Dictionary>::Instances,
    Plugin::Information<Dictionary>::Prefix,
    Plugin::Information<Dictionary>::Interfaces,
    Plugin::Information<Dictionary>::Configuration,
    Plugin::Information<Dictionary>::Extends
);
```

**Citation format:** `[PluginName.cpp:LINE] Plugin::Metadata<PluginName> registration absent`

---

### rule_16

**JSONRPC Inheritance When Used** | `violation` | *Conditional: skip if plugin registers no JSON-RPC handlers*

**What to check:** If the plugin registers JSON-RPC handlers (`Register()` calls in `Initialize()`), the plugin class must inherit `PluginHost::JSONRPC`.

**Where to look:** `Initialize()` for `Register()` calls; the class declaration for JSONRPC inheritance.

**Violation pattern:** `Register()` calls present in `Initialize()` but class does not inherit `PluginHost::JSONRPC`.

```cpp
// WRONG:
class Dictionary : public PluginHost::IPlugin {
    // Missing PluginHost::JSONRPC inheritance
};

// Correct:
class Dictionary : public PluginHost::IPlugin,
                   public PluginHost::JSONRPC {
};
```

**Citation format:** `[PluginName.h:LINE] JSON-RPC used but JSONRPC inheritance missing`

---

## Phase 4 — Lifecycle

---

### rule_17

**IShell AddRef in Initialize** | `violation` | *Conditional: skip if class has no stored `IShell*` member*

**What to check:** If the plugin stores the `IShell*` pointer as a member, `AddRef()` must be called on it immediately after assignment in `Initialize()`.

**Where to look:** Assignment of the `IShell*` member in `Initialize()`.

**Violation pattern:** `IShell*` stored as member but `AddRef()` not called after assignment.

```cpp
// WRONG:
string Initialize(PluginHost::IShell* service) {
    _service = service;   // AddRef() missing
}

// Correct:
string Initialize(PluginHost::IShell* service) {
    ASSERT(service != nullptr);
    _service = service;
    _service->AddRef();
}
```

**Citation format:** `[PluginName.cpp:LINE] IShell* stored but AddRef() not called after assignment`

---

### rule_18

**IShell Release in Deinitialize** | `violation` | *Conditional: skip if class has no stored `IShell*` member*

**What to check:** `Deinitialize()` must call `Release()` on the stored `IShell*` and immediately set it to `nullptr`.

**Where to look:** `Deinitialize()` body.

**Violation pattern:** `IShell*` member not released or not nulled in `Deinitialize()`.

```cpp
// WRONG:
void Deinitialize(PluginHost::IShell* service) {
    // _service->Release() or _service = nullptr missing
}

// Correct:
void Deinitialize(PluginHost::IShell* service) {
    _service->Release();
    _service = nullptr;
}
```

**Citation format:** `[PluginName.cpp:LINE] IShell* not released or not nulled in Deinitialize()`

---

### rule_19

**Information() Method** | `violation`

**What to check:** The plugin must implement `string Information() const`. This method is part of `PluginHost::IPlugin` and is mandatory.

**Where to look:** Plugin `.cpp` and `.h` files.

**Violation pattern:** `string Information() const` not implemented.

```cpp
// Correct:
string PluginName::Information() const {
    return string();
}
```

**Citation format:** `[PluginName.cpp:LINE] Information() const method not implemented`

---

### rule_20

**Root\<T\>() Null Check** | `violation` | *Conditional: skip if `Initialize()` does not call `Root<T>()`*

**What to check:** The return value of `service->Root<T>()` must be checked for `nullptr` before use.

**Where to look:** `Root<T>()` call sites in `Initialize()`.

**Violation pattern:** `Root<T>()` return value used without `nullptr` check.

```cpp
// WRONG:
_implementation = service->Root<IPlugin>();
_implementation->DoSomething();  // may crash if Root returns nullptr

// Correct:
_implementation = service->Root<IPlugin>();
if (_implementation != nullptr) {
    _implementation->DoSomething();
} else {
    return "Failed to acquire implementation";
}
```

**Citation format:** `[PluginName.cpp:LINE] Root<T>() return value not checked for nullptr`

---

### rule_21

**Root\<T\>() Release in Deinitialize** | `violation` | *Conditional: skip if plugin does not call `Root<T>()`*

**What to check:** The pointer acquired via `Root<T>()` must be released and set to `nullptr` in `Deinitialize()`.

**Where to look:** `Deinitialize()` body — find the member that stores the `Root<T>()` result.

**Violation pattern:** `Root<T>()` pointer not released or not nulled in `Deinitialize()`.

```cpp
// WRONG:
void Deinitialize(PluginHost::IShell* service) {
    // _implementation->Release() missing
}

// Correct:
void Deinitialize(PluginHost::IShell* service) {
    if (_implementation != nullptr) {
        _implementation->Release();
        _implementation = nullptr;
    }
}
```

**Citation format:** `[PluginName.cpp:LINE] Root<T>() pointer not released in Deinitialize()`

---

### rule_22

**Observer Cleanup in Deinitialize** | `violation` | *Conditional: skip if plugin registers no observers*

**What to check:** Every observer or notification registered in `Initialize()` must be unregistered in `Deinitialize()`. Every `Register`/`Subscribe` call must have a matching `Unregister`/`Unsubscribe`.

**Where to look:** `Initialize()` for all `Register`/`Subscribe` calls; `Deinitialize()` for matching cleanup.

**Violation pattern:** Observer registered in `Initialize()` but not unregistered in `Deinitialize()`.

```cpp
// WRONG:
string Initialize(PluginHost::IShell* service) {
    service->Register(_notification);
}
void Deinitialize(PluginHost::IShell* service) {
    // service->Unregister(_notification) missing
}

// Correct:
void Deinitialize(PluginHost::IShell* service) {
    service->Unregister(_notification);
}
```

**Citation format:** `[PluginName.cpp:LINE] Observer registered in Initialize() but not cleaned up in Deinitialize()`

---

### rule_23

**SubSystems() Release in Deinitialize** | `violation` | *Conditional: skip if plugin does not use `SubSystems()`*

**What to check:** If `service->SubSystems()` is acquired in `Initialize()`, it must be released in `Deinitialize()`.

**Where to look:** `Initialize()` for `SubSystems()` acquisition; `Deinitialize()` for the matching `Release()`.

**Violation pattern:** `SubSystems()` acquired in `Initialize()` but not released in `Deinitialize()`.

```cpp
// WRONG:
string Initialize(PluginHost::IShell* service) {
    _subSystems = service->SubSystems();
}
void Deinitialize(PluginHost::IShell* service) {
    // _subSystems->Release() missing
}

// Correct:
void Deinitialize(PluginHost::IShell* service) {
    _subSystems->Release();
    _subSystems = nullptr;
}
```

**Citation format:** `[PluginName.cpp:LINE] SubSystems() not released in Deinitialize()`

---

### rule_24

**Constructor Must Be Empty** | `violation`

**What to check:** The plugin class constructor body must be empty — no initialization logic, no resource acquisition, no system calls. All initialization belongs in `Initialize()`. Member initializer lists with null/default values are acceptable.

**Where to look:** Plugin class constructor definition.

**Violation pattern:** Constructor body contains non-trivial initialization logic.

```cpp
// WRONG:
Dictionary::Dictionary() {
    _config.FromString("...");
    _service = GetService();
}

// Correct:
Dictionary::Dictionary()
    : _service(nullptr)
    , _config()
{
    // empty
}
```

**Citation format:** `[PluginName.cpp:LINE] Constructor contains initialization logic`

---

### rule_25

**service->Register/Unregister Pairing** | `violation` | *Conditional: skip if plugin does not call `service->Register()`*

**What to check:** Every `service->Register()` call in `Initialize()` must be matched by a `service->Unregister()` call in `Deinitialize()`.

**Where to look:** `Initialize()` for `service->Register()` calls; `Deinitialize()` for matching `service->Unregister()` calls.

**Violation pattern:** `service->Register()` in `Initialize()` not matched by `service->Unregister()` in `Deinitialize()`.

```cpp
// WRONG:
string Initialize(PluginHost::IShell* service) {
    service->Register(_notification);
}
void Deinitialize(PluginHost::IShell* service) {
    // service->Unregister(_notification) missing
}

// Correct:
void Deinitialize(PluginHost::IShell* service) {
    service->Unregister(_notification);
}
```

**Citation format:** `[PluginName.cpp:LINE] service->Register() without matching Unregister() in Deinitialize()`

---

### rule_26

**Initialize Returns Error String on Failure** | `violation`

**What to check:** `Initialize()` must return a non-empty error string on every failure path. Returning an empty string on failure prevents Thunder from knowing initialization failed.

**Where to look:** All return statements in `Initialize()`.

**Violation pattern:** `Initialize()` returns empty string on a failure condition.

```cpp
// WRONG:
string Initialize(PluginHost::IShell* service) {
    if (service == nullptr) {
        return string();  // empty string does not signal failure
    }
    return string();
}

// Correct:
string Initialize(PluginHost::IShell* service) {
    if (service == nullptr) {
        return "Service pointer is null";
    }
    return string();  // success
}
```

**Citation format:** `[PluginName.cpp:LINE] Initialize() returns empty string on failure condition`

---

### rule_27

**No Manual Deinitialize() in Initialize** | `violation`

**What to check:** `Initialize()` must never call `Deinitialize()` directly. Failure cleanup must be done explicitly with targeted resource release.

**Where to look:** The full `Initialize()` body.

**Violation pattern:** `Initialize()` calls `Deinitialize()` directly.

```cpp
// WRONG:
string Initialize(PluginHost::IShell* service) {
    _service = service;
    _service->AddRef();
    if (!Setup()) {
        Deinitialize(service);  // do not call Deinitialize from Initialize
        return "Setup failed";
    }
    return string();
}

// Correct:
string Initialize(PluginHost::IShell* service) {
    _service = service;
    _service->AddRef();
    if (!Setup()) {
        _service->Release();
        _service = nullptr;
        return "Setup failed";
    }
    return string();
}
```

**Citation format:** `[PluginName.cpp:LINE] Initialize() calls Deinitialize() — handle failures explicitly`

---

### rule_28

**Destructor Must Be Empty** | `violation`

**What to check:** The plugin destructor body must be completely empty. All resource cleanup belongs in `Deinitialize()`.

**Where to look:** Plugin class destructor definition.

**Violation pattern:** Destructor contains cleanup logic.

```cpp
// WRONG:
Dictionary::~Dictionary() {
    if (_service != nullptr) {
        _service->Release();
    }
}

// Correct:
Dictionary::~Dictionary() {
    // empty
}
```

**Citation format:** `[PluginName.cpp:LINE] Destructor contains cleanup logic — move to Deinitialize()`

---

## Phase 5 — Implementation

---

### rule_29

**JSON-RPC Register/Unregister Pairing** | `violation` | *Conditional: skip if plugin registers no JSON-RPC handlers*

**What to check:** Every JSON-RPC handler registered via `JSONRPC::Register()` in `Initialize()` must be unregistered via `JSONRPC::Unregister()` in `Deinitialize()`. Missing unregistration causes stale handler references after plugin deactivation.

**Where to look:** `Initialize()` for `Register()` calls; `Deinitialize()` for matching `Unregister()` calls.

**Violation pattern:** JSON-RPC handler registered but not unregistered.

```cpp
// WRONG:
string Initialize(PluginHost::IShell* service) {
    Register<Params, Result>(_T("method"), &PluginName::Method, this);
}
void Deinitialize(PluginHost::IShell* service) {
    // Unregister(_T("method")) missing
}

// Correct:
void Deinitialize(PluginHost::IShell* service) {
    Unregister(_T("method"));
}
```

**Citation format:** `[PluginName.cpp:LINE] JSON-RPC handler registered but not unregistered`

---

### rule_30

**SinkType Pattern for Subscribers** | `violation` | *Conditional: skip if plugin has no notification subscriptions*

**What to check:** Notification subscriber classes must follow the SinkType pattern — properly inheriting from the notification interface and implementing all required callbacks.

**Where to look:** All notification handler class declarations.

**Violation pattern:** Notification subscriber class does not properly implement the SinkType pattern.

```cpp
// WRONG:
class MyNotification {   // not inheriting IPlugin::INotification

// Correct:
class Notification : public PluginHost::IPlugin::INotification {
public:
    BEGIN_INTERFACE_MAP(Notification)
    INTERFACE_ENTRY(PluginHost::IPlugin::INotification)
    END_INTERFACE_MAP
    void Activated(const string& callsign, PluginHost::IShell* service) override;
    void Deactivated(const string& callsign, PluginHost::IShell* service) override;
    void Unavailable(const string& callsign, PluginHost::IShell* service) override;
};
```

**Citation format:** `[PluginName.h:LINE] Notification subscriber does not follow SinkType pattern`

---

### rule_31

**Unavailable() in SinkType Classes** | `violation` | *Conditional: skip if plugin has no SinkType classes*

**What to check:** Every class implementing `IPlugin::INotification` must also implement `Unavailable()`. `IPlugin::INotification` has 3 pure virtuals: `Activated`, `Deactivated`, and `Unavailable`.

**Where to look:** All classes inheriting `IPlugin::INotification`.

**Violation pattern:** SinkType class missing `Unavailable()` implementation.

```cpp
// WRONG:
class Notification : public PluginHost::IPlugin::INotification {
    void Activated(const string& callsign, PluginHost::IShell* service) override { ... }
    void Deactivated(const string& callsign, PluginHost::IShell* service) override { ... }
    // Unavailable() missing
};

// Correct:
class Notification : public PluginHost::IPlugin::INotification {
    void Activated(const string& callsign, PluginHost::IShell* service) override { ... }
    void Deactivated(const string& callsign, PluginHost::IShell* service) override { ... }
    void Unavailable(const string& callsign, PluginHost::IShell* service) override { ... }
};
```

**Citation format:** `[PluginName.h:LINE] SinkType class missing Unavailable() implementation`

---

### rule_32

**No Hardcoded Paths** | `violation`

**What to check:** No hardcoded filesystem paths in plugin code. Paths must come from configuration or be constructed from Thunder's data path API.

**Where to look:** All function bodies and member initializers — look for string literals that resemble filesystem paths (`/usr/`, `/etc/`, `/tmp/`, `C:\`, etc.).

**Violation pattern:** Hardcoded filesystem path found in plugin code.

```cpp
// WRONG:
string configFile = "/etc/myapp/config.json";
string dataDir = "/var/lib/thunder/data/";

// Correct:
string configFile = service->DataPath() + "config.json";
// Or: _config.DataPath.Value()
```

**Citation format:** `[PluginName.cpp:LINE] Hardcoded filesystem path`

---

## Phase 5C — Out-of-Process (OOP)

---

### rule_33

**OOP Connection Termination in Deinitialize** | `violation` | *Conditional: skip if plugin is not out-of-process*

**What to check:** `Deinitialize()` must properly terminate the OOP connection — release the remote implementation interface and terminate/release the connection channel.

**Where to look:** `Deinitialize()` body in OOP plugins using `IRemoteConnection`.

**Violation pattern:** OOP connection not properly terminated in `Deinitialize()`.

```cpp
// WRONG:
void Deinitialize(PluginHost::IShell* service) {
    // OOP connection not cleaned up
}

// Correct:
void Deinitialize(PluginHost::IShell* service) {
    if (_implementation != nullptr) {
        _implementation->Release();
        _implementation = nullptr;
    }
    if (_connection != nullptr) {
        _connection->Terminate();
        _connection->Release();
        _connection = nullptr;
    }
}
```

**Citation format:** `[PluginName.cpp:LINE] OOP connection not terminated in Deinitialize()`

---

### rule_34

**connectionId Checked in IRemoteConnection Callbacks** | `violation` | *Conditional: skip if plugin does not implement `IRemoteConnection::INotification`*

**What to check:** In every `IRemoteConnection` callback (`Activated`, `Deactivated`, `Terminated`), the `connectionId` parameter must be checked against the plugin's stored connection ID before taking any action.

**Where to look:** All `IRemoteConnection::INotification` callback implementations.

**Violation pattern:** `IRemoteConnection` callback does not check `connectionId` before acting.

```cpp
// WRONG:
void Terminated(const uint32_t id) override {
    // acts without checking if id matches
    _parent.ConnectionTerminated();
}

// Correct:
void Terminated(const uint32_t id) override {
    if (id == _parent._connectionId) {
        _parent.ConnectionTerminated();
    }
}
```

**Citation format:** `[PluginName.cpp:LINE] connectionId not checked in IRemoteConnection callback`

---

## Phase 6 — Configuration

---

### rule_35

**Startmode Declaration** | `violation` | *Conditional: skip if no `.conf.in` file exists*

**What to check:** The `.conf.in` file must declare an explicit `startmode`.

**Where to look:** `PluginName.conf.in`.

**Violation pattern:** `startmode` field absent from `.conf.in`.

```ini
# Correct — add to PluginName.conf.in:
startmode = Activated
```

**Citation format:** `[PluginName.conf.in:LINE] startmode field missing`

---

### rule_36

**Config Core::JSON::Container** | `violation` | *Conditional: skip if plugin has no configuration class*

**What to check:** The plugin configuration class must inherit `Core::JSON::Container`. Config classes that don't inherit `Core::JSON::Container` won't parse configuration correctly.

**Where to look:** The `Config` class declaration.

**Violation pattern:** `Config` class does not inherit `Core::JSON::Container`.

```cpp
// WRONG:
class Config {
public:
    string Root;
};

// Correct:
class Config : public Core::JSON::Container {
public:
    Config() : Core::JSON::Container() {
        Add(_T("root"), &Root);
    }
    Core::JSON::String Root;
};
```

**Citation format:** `[PluginName.h:LINE] Config class missing Core::JSON::Container inheritance`

---

### rule_37

**No Hardcoded Numeric Tuning Parameters** | `violation`

**What to check:** Numeric tuning parameters (timeouts, buffer sizes, retry counts, thresholds) must come from the `Config` class, not be hardcoded inline. Structural constants (`0`, `1`, `-1`, array indices) are acceptable inline.

**Where to look:** All function bodies and class member initializations.

**Violation pattern:** Hardcoded numeric tuning parameter.

```cpp
// WRONG:
Core::Thread::Run(5000);    // hardcoded 5-second timeout
if (retries > 3) { ... }    // hardcoded retry count

// Correct:
Core::Thread::Run(_config.Timeout.Value());
if (retries > _config.MaxRetries.Value()) { ... }
```

**Citation format:** `[PluginName.cpp:LINE] Hardcoded numeric tuning parameter — move to Config`

---

## Phase 7 — CMake

---

### rule_38

**CXX_STANDARD Uses Thunder Variable** | `violation` | *Conditional: skip if `CMakeLists.txt` does not set `CXX_STANDARD`*

**What to check:** If `CXX_STANDARD` is set in `CMakeLists.txt`, it must use `${CXX_STD}` (the Thunder build system variable) rather than a hardcoded value.

**Where to look:** `CMakeLists.txt`.

**Violation pattern:** `CXX_STANDARD` set to a hardcoded value.

```cmake
# WRONG:
set_target_properties(${MODULE_NAME} PROPERTIES CXX_STANDARD 14)

# Correct:
set_target_properties(${MODULE_NAME} PROPERTIES CXX_STANDARD ${CXX_STD})
```

**Citation format:** `[CMakeLists.txt:LINE] CXX_STANDARD hardcoded — use ${CXX_STD}`

---

## Phase 8 — COM Interface

---

### rule_39

**COM Methods Return Core::hresult** | `violation`

**What to check:** All COM interface methods declared in the plugin must return `Core::hresult`. Void return types and other return types are not allowed in COM interfaces (Thunder 5.0+).

**Where to look:** All interface method declarations in plugin header files — focus on pure virtual methods in COM interfaces.

**Violation pattern:** COM interface method does not return `Core::hresult`.

```cpp
// WRONG:
virtual void GetValue(const string& key, string& value) = 0;
virtual bool SetValue(const string& key, const string& value) = 0;

// Correct:
virtual Core::hresult GetValue(const string& key, string& value /* @out */) = 0;
virtual Core::hresult SetValue(const string& key, const string& value) = 0;
```

**Citation format:** `[PluginName.h:LINE] COM interface method does not return Core::hresult`

---

## Holistic Rules

The following rules require reading the full plugin context before evaluating. They span multiple files and patterns.

---

### rule_40

**#pragma once** | `suggestion` | Category: Conventions

Every header file in the plugin must use `#pragma once` as its include guard.

---

### rule_41

**Apache 2.0 Copyright Header** | `suggestion` | Category: Conventions

Every source file must contain a proper Apache 2.0 copyright header at the top.

---

### rule_42

**STL Types** | `warning` | Category: Code Quality

Thunder type aliases (`string`, `vector`) must be used instead of their `std::` equivalents (`std::string`, `std::vector`) wherever Thunder aliases are available. Check function signatures, class members, and return types.

---

### rule_43

**ASSERT vs Error Handling** | `warning` | Category: Code Quality

`ASSERT` must be used only for programmer invariants — conditions that must always be true in correct code. `ASSERT` must never be used for runtime error handling (user input errors, network failures, missing configuration).

---

### rule_44

**OOP Registration Order** | `violation` | Category: Lifecycle Integrity

In out-of-process plugins, `service->Register()` and `service->Unregister()` must be called in the correct order relative to acquiring and releasing the remote implementation.

---

### rule_45

**Complete State Reset in Deinitialize** | `violation` | Category: Lifecycle Integrity

Every member variable set during `Initialize()` or during operation must be reset to its default/null state in `Deinitialize()`. A subsequent `Initialize()` call must start from a completely clean state.

---

### rule_46

**Reverse-Order Cleanup** | `suggestion` | Category: Lifecycle Integrity

`Deinitialize()` should release resources in the reverse order of how they were acquired in `Initialize()`.

---

### rule_47

**Observer Locking** | `violation` | Category: Concurrency

Observer lists must be protected by appropriate locking when iterated and when observers are added or removed, to prevent data races.

---

### rule_48

**AddRef/Release Balance** | `violation` | Category: COM Safety

Every `AddRef()` call on a COM interface must be balanced by exactly one `Release()` call across all code paths, including error paths. No leaks, no double-releases.

---

### rule_49

**CMake NAMESPACE Variable** | `suggestion` | Category: Conventions

`CMakeLists.txt` must use the `${NAMESPACE}` variable for target naming and installation paths per Thunder conventions.

---

### rule_50

**Handlers Must Not Block** | `violation` | Category: Concurrency

No notification handler (`IPlugin::INotification` callbacks, `IRemoteConnection::INotification` callbacks) may perform blocking operations (network calls, file I/O, sleep, synchronous waiting) on the framework's callback thread.

---

### rule_51

**No Activate/Deactivate from Handlers** | `violation` | Category: Concurrency

No notification callback may call `service->Activate()` or `service->Deactivate()` directly — doing so causes deadlock on the framework thread.

---

### rule_52

**Shared State Protected by CriticalSection** | `violation` | Category: Concurrency

Every member variable accessed from both the main thread and notification callbacks must be protected by a `Core::CriticalSection` lock.

---

### rule_53

**No Lock Held During Framework Callbacks** | `violation` | Category: Concurrency

All locks must be released before calling back into the Thunder framework (e.g. before `service->Submit()`, `Activate()`, or notification dispatch) to prevent deadlock.

---

### rule_54

**Worker Jobs Check Deinitialize Guard** | `violation` | Category: Concurrency

All worker job (`IJob`, `WorkerPool`) `Dispatch()` methods must check a deinitialization guard flag at the start to avoid using stale pointers after `Deinitialize()` has run.

---

### rule_55

**File Descriptors / Sockets Wrapped in RAII** | `violation` | Category: Resource Management

All file descriptors, sockets, and OS handles must be wrapped in RAII types or explicitly closed in `Deinitialize()`. They must never be leaked.

---

### rule_56

**No Unbounded Memory Growth** | `violation` | Category: Resource Management

All data structures (`map`, `vector`, `list`, `queue`) populated at runtime must have a bounded size or eviction policy to prevent unbounded memory growth during sustained plugin operation.

---

### rule_57

**Config Errors Return Non-Empty from Initialize** | `violation` | Category: Lifecycle Integrity

All configuration errors (missing required fields, invalid values, out-of-range values) must cause `Initialize()` to return a non-empty error string.

---

### rule_58

**interface->Register/Unregister Pairing** | `violation` | Category: JSON-RPC Compliance

Every `interface->Register()` call (registering a notification/callback on a non-service interface) must be matched by a corresponding `interface->Unregister()` in `Deinitialize()`.

---

### rule_59

**Handler Registration Order in Initialize/Deinitialize** | `violation` | Category: JSON-RPC Compliance

Notification handlers must be registered **after** the interfaces they observe are fully acquired and set up, and unregistered **before** those interfaces are released — to avoid callbacks on partially-initialized state.

---

### rule_60

**Use Core::ERROR_\* for Handler Failure Codes** | `violation` | Category: JSON-RPC Compliance

All failures in JSON-RPC handlers and COM interface method implementations must be reported using `Core::ERROR_*` constants — never raw numeric literals or Windows error codes.

---

### rule_61

**Input Validation in JSON-RPC Handlers** | `violation` | Category: JSON-RPC Compliance

Every JSON-RPC handler must validate its input parameters (null pointer checks, string length limits, enum range checks) before using them.

---

### rule_62

**Event Constants and Typed JSON Payloads** | `warning` | Category: JSON-RPC Compliance

Event names must be defined as named constants rather than inline string literals. Event payloads must be typed JSON objects rather than untyped free-form strings.

---

### rule_63

**COM Reference Counting Correctness** | `violation` | Category: COM Safety

COM reference counting must be correctly maintained across all code paths where COM interfaces are passed, returned, or stored — `AddRef` when storing, `Release` when done, no double-release or leak on any path including error paths.

---

### rule_64

**No Hard Inter-Plugin Dependencies** | `warning` | Category: Inter-Plugin Design

The plugin must use the observer pattern and dynamic interface acquisition (`QueryInterfaceByCallsign`, `IPlugin::INotification`) for inter-plugin communication — no hard compile-time or startup-time dependencies on specific other plugins being present.

---

### rule_65

**JSON-RPC Handlers Are Re-entrant Safe** | `violation` | Category: Concurrency

All JSON-RPC handlers must be safe for concurrent invocation — either accessing only local state or properly locking shared state.

---

### rule_66

**IPlugin::INotification Callbacks Must Not Block** | `violation` | Category: Concurrency

No `IPlugin::INotification` callback (`Activated`, `Deactivated`, `Unavailable`) may block the calling thread — no synchronous waits, no contended mutex acquisitions, no I/O.

---

### rule_67

**Lock Scope Minimized** | `violation` | Category: Concurrency

All critical sections must be held for the minimum time necessary — covering only the actual shared state access. Blocking operations, callbacks, and I/O must never occur while holding a lock.

---

### rule_68

**Plugin Threads Joined in Deinitialize** | `violation` | Category: Concurrency

All threads started by the plugin must be explicitly stopped and joined (or detached with a lifetime guarantee) in `Deinitialize()` before the function returns.

---

### rule_69

**Memory and Allocation Safety** | `warning` | Category: Resource Management

There must be no memory leaks (every `new` must have a corresponding `delete` on all code paths), no use-after-free, and no buffer overflows.

---

### rule_70

**Framework Pointers Not Accessed After Deinitialize** | `violation` | Category: Lifecycle Integrity

No worker thread, background job, or async callback may access framework pointers (`IShell*`, service pointers, notification interfaces) after `Deinitialize()` has completed and nulled those pointers.

---

### rule_71

**hresult Return Values Checked** | `violation` | Category: COM Safety

The return value of every `Core::hresult`-returning COM interface method call must be checked and errors must be handled appropriately — never silently discarded.

---

### rule_72

**ASSERT Only for Programmer Invariants** | `warning` | Category: Code Quality

`ASSERT` must only be used for conditions that represent programmer errors — invariants that should never be false in correct code. It must never be used for conditions that can legitimately occur at runtime.

---

### rule_73

**Security: Logging, Shell, Path, and Error Exposure** | `violation` | Category: Code Quality

The plugin must avoid: logging sensitive data (passwords, tokens, PII); executing shell commands with unsanitized input; exposing internal error details through JSON-RPC responses; and path traversal via external inputs.

---

### rule_74

**JSON-RPC Input Validation for Bounds and Types** | `violation` | Category: JSON-RPC Compliance

Every JSON-RPC handler must validate numeric inputs for range bounds and type correctness before use in operations that could overflow, underflow, or cause undefined behavior.

---

### rule_75

**Config Completeness and Resource Cleanup** | `warning` | Category: Code Quality

All configuration fields must be registered with `Add()` in the `Config` constructor. All resources acquired based on configuration values must be properly released in `Deinitialize()`.

---

### rule_76

**OOP Error Propagation and Method Naming** | `warning` | Category: Inter-Plugin Design

Out-of-process method implementations must properly propagate errors from the remote process back to the plugin host. Method names must follow Thunder naming conventions — no abbreviations, clear verb+noun form.

---

### rule_77

**Observer Classes Private and Nested** | `suggestion` | Category: Conventions

Observer/notification classes should be declared as private nested classes within the plugin class — not as separate public classes in the header — to keep the plugin's internal observer implementation encapsulated.

---

### rule_78

**No Deprecated JSON-RPC APIs** | `violation` | Category: JSON-RPC Compliance

No deprecated JSON-RPC APIs must be used — no legacy `Register` overloads replaced by typed versions, no deprecated event dispatch patterns.

---

### rule_79

**All Acquired Pointers Cleared After Deinitialize** | `violation` | Category: Lifecycle Integrity

Every pointer member set to a non-null value during the plugin's lifetime must be explicitly set to `nullptr` in `Deinitialize()` (in addition to being released), such that a double-`Deinitialize()` would not cause a double-release.

---

## Summary by Phase

| Phase | Rules | Violations | Warnings | Suggestions |
|---|---|---|---|---|
| Module Structure | rule_01 – rule_03 | 1 | 1 | 1 |
| Code Style | rule_04 – rule_13 | 9 | 1 | 0 |
| Class Registration | rule_14 – rule_16 | 2 | 1 | 0 |
| Lifecycle | rule_17 – rule_28 | 12 | 0 | 0 |
| Implementation | rule_29 – rule_32 | 4 | 0 | 0 |
| Out-of-Process | rule_33 – rule_34 | 2 | 0 | 0 |
| Configuration | rule_35 – rule_37 | 3 | 0 | 0 |
| CMake | rule_38 | 1 | 0 | 0 |
| COM Interface | rule_39 | 1 | 0 | 0 |
| Holistic (rule_40 – rule_79) | 40 | 29 | 7 | 4 |
| **Total** | **79** | **64** | **10** | **5** |

---

*Document generated from `thunder-plugin-rules.yaml` v3.3.0. For questions or rule updates, raise a PR against the spec folder.*
