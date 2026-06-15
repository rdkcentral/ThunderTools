# Thunder Plugin Rules — v3.3.0

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

> **YAML source:** `ThunderTools/PluginQA/rules/thunder-plugin-rules.yaml` → `general_rules` section

---

### rule_40

**#pragma once** | `suggestion` | Category: Conventions

**What to check:** Every header file (`.h`) in the plugin uses `#pragma once` as its include guard — not legacy `#ifndef`/`#define`/`#endif`.

**Where to look:** All `.h` files in the plugin folder.

**Violation pattern:** A header file uses legacy `#ifndef` include guard instead of `#pragma once`.

```cpp
// WRONG:
#ifndef DICTIONARY_H
#define DICTIONARY_H
// ...
#endif

// Correct:
#pragma once
// ...
```

**Citation format:** `[FileName.h:1] Missing #pragma once — uses legacy include guard`

---

### rule_41

**Apache 2.0 Copyright Header** | `suggestion` | Category: Conventions

**What to check:** Every source file (`.cpp`, `.h`) starts with the standard Apache 2.0 copyright header block.

**Where to look:** First 20 lines of every source file.

**Violation pattern:** Source file is missing the Apache 2.0 copyright header.

```cpp
// Correct — top of every file:
/*
 * If not stated otherwise in this file or this component's LICENSE file the
 * following copyright and licenses apply:
 *
 * Copyright 2024 Metrological
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * ...
 */
```

**Citation format:** `[FileName.cpp:1] Missing Apache 2.0 copyright header`

---

### rule_42

**STL Types** | `warning` | Category: Code Quality

**What to check:** Thunder type aliases (`string`, `vector`) are used instead of their `std::` equivalents (`std::string`, `std::vector`) wherever Thunder aliases are available.

**Where to look:** Function signatures, class member declarations, return types, and local variables.

**Violation pattern:** `std::string`, `std::vector`, or other STL types used where Thunder aliases exist.

```cpp
// WRONG:
std::string GetName() const;
std::vector<std::string> _items;

// Correct:
string GetName() const;
std::vector<string> _items;  // Thunder aliases 'string' but not all containers
```

**Citation format:** `[PluginName.h:LINE] std::string used — use Thunder alias 'string'`

---

### rule_43

**ASSERT vs Error Handling** | `warning` | Category: Code Quality

**What to check:** `ASSERT` is used only for programmer invariants (conditions that must always be true in correct code). It must never be used for runtime error handling — things that can legitimately fail (user input, network, configuration).

**Where to look:** All `ASSERT(...)` calls in the plugin.

**Violation pattern:** `ASSERT` used on a condition that can fail at runtime.

```cpp
// WRONG:
string Initialize(PluginHost::IShell* service) {
    _impl = service->Root<IPlugin>();
    ASSERT(_impl != nullptr);  // Root<T>() CAN return nullptr at runtime
    _impl->DoWork();
}

// Correct:
string Initialize(PluginHost::IShell* service) {
    _impl = service->Root<IPlugin>();
    if (_impl == nullptr) {
        return "Failed to acquire implementation";
    }
    ASSERT(_service != nullptr);  // OK — _service was set above and must be valid here
    _impl->DoWork();
}
```

**Citation format:** `[PluginName.cpp:LINE] ASSERT used on runtime condition — use proper error handling`

---

### rule_44

**OOP Registration Order** | `violation` | Category: Lifecycle Integrity

**What to check:** In out-of-process plugins, `service->Register()` must be called **after** the remote implementation is acquired, and `service->Unregister()` must be called **before** the remote implementation is released.

**Where to look:** `Initialize()` and `Deinitialize()` in OOP plugins.

**Violation pattern:** `service->Register()` called before `Root<T>()`, or `service->Unregister()` called after implementation release.

```cpp
// WRONG:
string Initialize(PluginHost::IShell* service) {
    service->Register(_notification);        // too early
    _impl = service->Root<IImplementation>();
}

// Correct:
string Initialize(PluginHost::IShell* service) {
    _impl = service->Root<IImplementation>();
    if (_impl != nullptr) {
        service->Register(_notification);    // after acquisition
    }
}
void Deinitialize(PluginHost::IShell* service) {
    service->Unregister(_notification);      // before release
    _impl->Release();
    _impl = nullptr;
}
```

**Citation format:** `[PluginName.cpp:LINE] Registration order incorrect relative to implementation acquisition`

---

### rule_45

**Complete State Reset in Deinitialize** | `violation` | Category: Lifecycle Integrity

**What to check:** Every member variable set during `Initialize()` or during operation must be reset to its default/null state in `Deinitialize()`. A subsequent `Initialize()` call must start from a completely clean state.

**Where to look:** Compare class member declarations with `Deinitialize()` body — every non-trivial member must be reset.

**Violation pattern:** Member variable set during plugin operation but not reset in `Deinitialize()`.

```cpp
// WRONG:
void Deinitialize(PluginHost::IShell* service) {
    _service->Release();
    _service = nullptr;
    // _connectionId not reset, _isActive not reset
}

// Correct:
void Deinitialize(PluginHost::IShell* service) {
    _service->Release();
    _service = nullptr;
    _connectionId = 0;
    _isActive = false;
}
```

**Citation format:** `[PluginName.cpp:LINE] Member '_connectionId' not reset in Deinitialize()`

---

### rule_46

**Reverse-Order Cleanup** | `suggestion` | Category: Lifecycle Integrity

**What to check:** `Deinitialize()` should release resources in the reverse order of how they were acquired in `Initialize()`. This prevents use-after-free when later resources depend on earlier ones.

**Where to look:** Compare acquisition order in `Initialize()` with release order in `Deinitialize()`.

**Violation pattern:** Resources released in the same order as acquired (not reversed).

```cpp
// Initialize acquires: _service → _impl → _notification
// Deinitialize should release: _notification → _impl → _service

// WRONG:
void Deinitialize(PluginHost::IShell* service) {
    _service->Release(); _service = nullptr;      // first acquired, first released
    _impl->Release(); _impl = nullptr;
}

// Correct:
void Deinitialize(PluginHost::IShell* service) {
    service->Unregister(_notification);           // last acquired, first released
    _impl->Release(); _impl = nullptr;
    _service->Release(); _service = nullptr;      // first acquired, last released
}
```

**Citation format:** `[PluginName.cpp:LINE] Cleanup order does not reverse acquisition order`

---

### rule_47

**Observer Locking** | `violation` | Category: Concurrency

**What to check:** Observer/notification lists must be protected by a lock (`Core::CriticalSection`) when iterated and when observers are added or removed — to prevent data races from concurrent callback dispatch vs. registration changes.

**Where to look:** Observer container access (iteration in notification dispatch, `push_back`/`erase` in Register/Unregister).

**Violation pattern:** Observer list accessed without lock held.

```cpp
// WRONG:
void NotifyObservers() {
    for (auto& obs : _observers) {  // no lock — race with Register/Unregister
        obs->StateChanged();
    }
}

// Correct:
void NotifyObservers() {
    _adminLock.Lock();
    auto copy = _observers;  // copy under lock
    _adminLock.Unlock();
    for (auto& obs : copy) {
        obs->StateChanged();
    }
}
```

**Citation format:** `[PluginName.cpp:LINE] Observer list iterated without lock`

---

### rule_48

**AddRef/Release Balance** | `violation` | Category: COM Safety

**What to check:** Every `AddRef()` call on a COM interface is balanced by exactly one `Release()` call across all code paths — including error/early-return paths. No leaks, no double-releases.

**Where to look:** All COM interface pointer acquisitions and their corresponding release paths.

**Violation pattern:** `AddRef()` without matching `Release()` on an error path, or `Release()` called twice.

```cpp
// WRONG — leak on error path:
_impl = service->Root<IPlugin>();
if (_impl != nullptr) {
    if (!Setup()) {
        return "Setup failed";  // _impl leaked — never released
    }
}

// Correct:
_impl = service->Root<IPlugin>();
if (_impl != nullptr) {
    if (!Setup()) {
        _impl->Release();
        _impl = nullptr;
        return "Setup failed";
    }
}
```

**Citation format:** `[PluginName.cpp:LINE] COM interface leaked on error path — missing Release()`

---

### rule_49

**CMake NAMESPACE Variable** | `suggestion` | Category: Conventions

**What to check:** `CMakeLists.txt` uses `${NAMESPACE}` for target naming and installation paths as per Thunder build conventions.

**Where to look:** `CMakeLists.txt` — target names, install paths, and project declarations.

**Violation pattern:** Hardcoded namespace string used instead of `${NAMESPACE}`.

```cmake
# WRONG:
install(TARGETS ${MODULE_NAME} DESTINATION lib/wpeframework/plugins)

# Correct:
install(TARGETS ${MODULE_NAME} DESTINATION ${CMAKE_INSTALL_PREFIX}/lib/${NAMESPACE}/plugins)
```

**Citation format:** `[CMakeLists.txt:LINE] Hardcoded namespace — use ${NAMESPACE}`

---

### rule_50

**Handlers Must Not Block** | `violation` | Category: Concurrency

**What to check:** No notification handler (`IPlugin::INotification`, `IRemoteConnection::INotification` callbacks) performs blocking operations — no network calls, file I/O, sleep, or synchronous waiting on the framework's callback thread.

**Where to look:** All `Activated()`, `Deactivated()`, `Unavailable()`, and `Terminated()` callback bodies.

**Violation pattern:** Blocking call inside a notification handler.

```cpp
// WRONG:
void Activated(const string& callsign, PluginHost::IShell* shell) override {
    std::this_thread::sleep_for(std::chrono::seconds(5));  // blocks framework thread
    auto data = HttpGet("http://...");                      // blocks on network
}

// Correct:
void Activated(const string& callsign, PluginHost::IShell* shell) override {
    _parent.ScheduleWork(callsign);  // dispatch to WorkerPool
}
```

**Citation format:** `[PluginName.cpp:LINE] Blocking operation in notification callback`

---

### rule_51

**No Activate/Deactivate from Handlers** | `violation` | Category: Concurrency

**What to check:** No notification callback directly calls `service->Activate()` or `service->Deactivate()` — this causes deadlock because those methods acquire the same framework lock that dispatches callbacks.

**Where to look:** All notification callback bodies.

**Violation pattern:** `Activate()` or `Deactivate()` called from inside a notification handler.

```cpp
// WRONG:
void Deactivated(const string& callsign, PluginHost::IShell* shell) override {
    _service->Activate(PluginHost::IShell::REQUESTED);  // DEADLOCK
}

// Correct:
void Deactivated(const string& callsign, PluginHost::IShell* shell) override {
    // Schedule activation on WorkerPool instead
    Core::IWorkerPool::Instance().Submit(Core::ProxyType<ActivateJob>(*this));
}
```

**Citation format:** `[PluginName.cpp:LINE] Activate/Deactivate called from notification handler — causes deadlock`

---

### rule_52

**Shared State Protected by CriticalSection** | `violation` | Category: Concurrency

**What to check:** Every member variable accessed from both the main thread (Initialize/Deinitialize, JSON-RPC handlers) and notification callbacks must be protected by a `Core::CriticalSection` lock.

**Where to look:** Member variables modified in handlers AND accessed in other methods without locking.

**Violation pattern:** Shared member accessed from multiple threads without lock.

```cpp
// WRONG:
void Activated(...) override { _isReady = true; }    // callback thread
uint32_t GetStatus(...) { return _isReady ? 1 : 0; } // JSON-RPC thread — no lock

// Correct:
void Activated(...) override {
    _adminLock.Lock();
    _isReady = true;
    _adminLock.Unlock();
}
uint32_t GetStatus(...) {
    _adminLock.Lock();
    bool ready = _isReady;
    _adminLock.Unlock();
    return ready ? 1 : 0;
}
```

**Citation format:** `[PluginName.cpp:LINE] Shared member '_isReady' accessed without lock`

---

### rule_53

**No Lock Held During Framework Callbacks** | `violation` | Category: Concurrency

**What to check:** All locks (`_adminLock`) must be released before calling back into the Thunder framework — before `service->Submit()`, `Notify()`, `Activate()`, or dispatching notifications. Holding a lock while calling framework APIs causes deadlock.

**Where to look:** Code paths that hold `_adminLock` and then call framework methods.

**Violation pattern:** Lock held during a framework callback invocation.

```cpp
// WRONG:
_adminLock.Lock();
_state = newState;
_service->Submit(PluginHost::IShell::ACTIVATED, this);  // framework call while locked
_adminLock.Unlock();

// Correct:
_adminLock.Lock();
_state = newState;
_adminLock.Unlock();
_service->Submit(PluginHost::IShell::ACTIVATED, this);  // lock released first
```

**Citation format:** `[PluginName.cpp:LINE] Framework callback called while holding _adminLock`

---

### rule_54

**Worker Jobs Check Deinitialize Guard** | `violation` | Category: Concurrency

**What to check:** All worker job `Dispatch()` methods must check a deinitialization guard flag (e.g. `_deinitialized`) at the start to avoid using stale/null framework pointers after `Deinitialize()` has run.

**Where to look:** All `IJob::Dispatch()` or WorkerPool job implementations.

**Violation pattern:** Job dispatches without checking whether plugin has been deinitialized.

```cpp
// WRONG:
void Dispatch() override {
    _parent._service->DoSomething();  // _service may be nullptr after Deinitialize
}

// Correct:
void Dispatch() override {
    _parent._adminLock.Lock();
    if (_parent._service == nullptr) {
        _parent._adminLock.Unlock();
        return;  // plugin already deinitialized
    }
    auto* svc = _parent._service;
    _parent._adminLock.Unlock();
    svc->DoSomething();
}
```

**Citation format:** `[PluginName.cpp:LINE] Worker job does not check deinitialize guard before using framework pointers`

---

### rule_55

**File Descriptors / Sockets Wrapped in RAII** | `violation` | Category: Resource Management

**What to check:** All file descriptors, sockets, and OS handles are wrapped in RAII types or explicitly closed in `Deinitialize()`. They must never be leaked on any code path.

**Where to look:** All `open()`, `socket()`, `fopen()` calls and their corresponding close paths.

**Violation pattern:** File descriptor or socket opened but not closed on all paths (including error paths).

```cpp
// WRONG:
int fd = open("/dev/input0", O_RDONLY);
if (error) return "Failed";  // fd leaked

// Correct:
Core::DataElementFile _file;  // RAII — auto-closes on destruction
// Or explicit:
void Deinitialize(...) {
    if (_fd >= 0) { close(_fd); _fd = -1; }
}
```

**Citation format:** `[PluginName.cpp:LINE] File descriptor not closed on error path`

---

### rule_56

**No Unbounded Memory Growth** | `violation` | Category: Resource Management

**What to check:** All data structures (`map`, `vector`, `list`, `queue`) populated at runtime have a bounded size or eviction policy. Without bounds, long-running plugins exhaust memory.

**Where to look:** All `push_back`, `insert`, `emplace` calls on member containers — check for corresponding eviction, size cap, or periodic cleanup.

**Violation pattern:** Runtime-populated container with no size limit or eviction.

```cpp
// WRONG:
void OnEvent(const Event& e) {
    _eventLog.push_back(e);  // grows forever
}

// Correct:
void OnEvent(const Event& e) {
    if (_eventLog.size() >= MAX_EVENTS) {
        _eventLog.erase(_eventLog.begin());
    }
    _eventLog.push_back(e);
}
```

**Citation format:** `[PluginName.cpp:LINE] Container '_eventLog' grows unbounded — add size limit`

---

### rule_57

**Config Errors Return Non-Empty from Initialize** | `violation` | Category: Lifecycle Integrity

**What to check:** All configuration errors (missing required fields, invalid values, out-of-range values) must cause `Initialize()` to return a non-empty error string. Silently accepting bad config leads to undefined runtime behavior.

**Where to look:** Configuration parsing in `Initialize()` — all branches after `FromString()` or `Config` field access.

**Violation pattern:** Configuration error detected but `Initialize()` still returns empty string (success).

```cpp
// WRONG:
_config.FromString(service->ConfigLine());
if (_config.Port.Value() == 0) {
    SYSLOG(Logging::Error, "Invalid port");
    // falls through to return string() — Thunder thinks init succeeded
}
return string();

// Correct:
_config.FromString(service->ConfigLine());
if (_config.Port.Value() == 0) {
    return "Configuration error: port must be non-zero";
}
return string();
```

**Citation format:** `[PluginName.cpp:LINE] Config error not reported — Initialize() returns empty string`

---

### rule_58

**interface->Register/Unregister Pairing** | `violation` | Category: JSON-RPC Compliance

**What to check:** Every `interface->Register()` call (registering a notification/callback on a non-service COM interface) must be matched by `interface->Unregister()` in `Deinitialize()`.

**Where to look:** `Initialize()` for `_impl->Register(...)` calls; `Deinitialize()` for matching `_impl->Unregister(...)`.

**Violation pattern:** Interface notification registered but not unregistered in `Deinitialize()`.

```cpp
// WRONG:
string Initialize(...) {
    _impl->Register(_sink);
}
void Deinitialize(...) {
    _impl->Release(); _impl = nullptr;
    // _impl->Unregister(_sink) missing — dangling callback
}

// Correct:
void Deinitialize(...) {
    _impl->Unregister(_sink);   // unregister BEFORE release
    _impl->Release(); _impl = nullptr;
}
```

**Citation format:** `[PluginName.cpp:LINE] interface->Register() without matching Unregister() in Deinitialize()`

---

### rule_59

**Handler Registration Order** | `violation` | Category: JSON-RPC Compliance

**What to check:** Notification handlers must be registered **after** the interfaces they observe are fully acquired, and unregistered **before** those interfaces are released. Registering before acquisition or unregistering after release causes callbacks on partially-initialized state.

**Where to look:** Ordering of `Register()`/`Unregister()` calls relative to interface acquisition/release in `Initialize()`/`Deinitialize()`.

**Violation pattern:** Handler registered before interface is ready, or unregistered after interface is released.

```cpp
// WRONG:
void Deinitialize(...) {
    _impl->Release(); _impl = nullptr;  // release first
    service->Unregister(_notification); // unregister after — callback may fire on null _impl
}

// Correct:
void Deinitialize(...) {
    service->Unregister(_notification); // unregister first
    _impl->Release(); _impl = nullptr;  // then release
}
```

**Citation format:** `[PluginName.cpp:LINE] Handler unregistered after interface release — wrong order`

---

### rule_60

**Use Core::ERROR_\* for Handler Failure Codes** | `violation` | Category: JSON-RPC Compliance

**What to check:** All failure returns in JSON-RPC handlers and COM interface method implementations must use `Core::ERROR_*` named constants — not raw numeric literals.

**Where to look:** Return statements in handler methods.

**Violation pattern:** Raw integer returned instead of `Core::ERROR_*` constant.

```cpp
// WRONG:
uint32_t SetValue(...) {
    if (!valid) return 1;      // raw integer
    if (!found) return 0x80004005;  // Windows HRESULT
}

// Correct:
uint32_t SetValue(...) {
    if (!valid) return Core::ERROR_GENERAL;
    if (!found) return Core::ERROR_UNKNOWN_KEY;
}
```

**Citation format:** `[PluginName.cpp:LINE] Raw integer error code — use Core::ERROR_* constant`

---

### rule_61

**Input Validation in JSON-RPC Handlers** | `violation` | Category: JSON-RPC Compliance

**What to check:** Every JSON-RPC handler validates its input parameters (null checks, string length limits, enum range checks) before using them. Unvalidated external input leads to crashes or undefined behavior.

**Where to look:** All JSON-RPC handler method bodies — the first thing after parameter extraction.

**Violation pattern:** Input parameter used without validation.

```cpp
// WRONG:
uint32_t SetName(const string& name) {
    _name = name;  // no length check — could be 10MB string
    return Core::ERROR_NONE;
}

// Correct:
uint32_t SetName(const string& name) {
    if (name.empty() || name.length() > 256) {
        return Core::ERROR_BAD_REQUEST;
    }
    _name = name;
    return Core::ERROR_NONE;
}
```

**Citation format:** `[PluginName.cpp:LINE] JSON-RPC input not validated before use`

---

### rule_62

**Event Constants and Typed JSON Payloads** | `warning` | Category: JSON-RPC Compliance

**What to check:** Event names are defined as named constants (not inline string literals). Event payloads use typed `JsonData::*` classes, not untyped free-form strings.

**Where to look:** All `Notify()` or event dispatch calls.

**Violation pattern:** Inline string literal for event name, or untyped payload.

```cpp
// WRONG:
Notify("stateChanged", "{\"state\":\"active\"}");  // inline string, untyped

// Correct:
static constexpr auto EVT_STATE_CHANGED = _T("stateChanged");
JsonData::StateInfo info;
info.State = "active";
Notify(EVT_STATE_CHANGED, info);
```

**Citation format:** `[PluginName.cpp:LINE] Event name is inline string — define as named constant`

---

### rule_63

**COM Reference Counting Correctness** | `violation` | Category: COM Safety

**What to check:** COM reference counting is correctly maintained across all code paths — `AddRef` when storing a new copy, `Release` when done, no double-release or leak on any path including error paths.

**Where to look:** All COM interface pointer assignments, returns, and storage patterns.

**Violation pattern:** Interface pointer stored without `AddRef`, or released twice, or not released on error path.

```cpp
// WRONG — double release:
_impl->Release();
// ... later in same function ...
_impl->Release();  // double release — undefined behavior

// WRONG — missing AddRef when copying:
IPlugin* copy = _impl;  // no AddRef — two owners, one ref count

// Correct:
IPlugin* copy = _impl;
copy->AddRef();  // now balanced
// ... use copy ...
copy->Release();
```

**Citation format:** `[PluginName.cpp:LINE] COM reference counting incorrect — double release / missing AddRef`

---

### rule_64

**No Hard Inter-Plugin Dependencies** | `warning` | Category: Inter-Plugin Design

**What to check:** The plugin uses the observer pattern and dynamic interface acquisition (`QueryInterfaceByCallsign`, `IPlugin::INotification`) for inter-plugin communication — no hard compile-time or startup-time dependencies.

**Where to look:** `#include` directives, `Initialize()` for hardcoded callsign requirements.

**Violation pattern:** Plugin fails to start if another specific plugin is not present.

```cpp
// WRONG:
#include "../OtherPlugin/OtherPlugin.h"  // compile-time dependency
auto* other = static_cast<OtherPlugin*>(GetPlugin("OtherPlugin"));

// Correct:
auto* other = _service->QueryInterfaceByCallsign<IOtherInterface>("OtherPlugin");
if (other != nullptr) {
    other->DoWork();
    other->Release();
}
```

**Citation format:** `[PluginName.cpp:LINE] Hard dependency on another plugin — use dynamic acquisition`

---

### rule_65

**JSON-RPC Handlers Are Re-entrant Safe** | `violation` | Category: Concurrency

**What to check:** All JSON-RPC handlers are safe for concurrent invocation — they either access only local state or properly lock shared state before access.

**Where to look:** All JSON-RPC handler bodies that access class member variables.

**Violation pattern:** Handler reads/writes shared state without lock.

```cpp
// WRONG:
uint32_t GetCount(...) {
    return _count;  // no lock — may race with notification thread modifying _count
}

// Correct:
uint32_t GetCount(...) {
    _adminLock.Lock();
    uint32_t count = _count;
    _adminLock.Unlock();
    return count;
}
```

**Citation format:** `[PluginName.cpp:LINE] JSON-RPC handler accesses shared state without lock`

---

### rule_66

**IPlugin::INotification Callbacks Must Not Block** | `violation` | Category: Concurrency

**What to check:** No `IPlugin::INotification` callback (`Activated`, `Deactivated`, `Unavailable`) blocks the calling thread — no synchronous waits, no contended mutex acquisitions, no I/O operations.

**Where to look:** All `IPlugin::INotification` callback implementations.

**Violation pattern:** Blocking operation inside a plugin notification callback.

```cpp
// WRONG:
void Deactivated(const string& callsign, PluginHost::IShell*) override {
    _adminLock.Lock();  // may block if held by long operation
    WriteLogToFile(callsign);  // I/O blocks
    _adminLock.Unlock();
}

// Correct:
void Deactivated(const string& callsign, PluginHost::IShell*) override {
    // schedule work, don't block
    _parent.ScheduleCleanup(callsign);
}
```

**Citation format:** `[PluginName.cpp:LINE] INotification callback performs blocking operation`

---

### rule_67

**Lock Scope Minimized** | `violation` | Category: Concurrency

**What to check:** Critical sections are held for the minimum time necessary — only the actual shared state access. No I/O, no blocking operations, no framework callbacks while holding a lock.

**Where to look:** All `_adminLock.Lock()` ... `_adminLock.Unlock()` spans.

**Violation pattern:** Lock held during I/O, sleep, or framework call.

```cpp
// WRONG:
_adminLock.Lock();
_data = FetchFromNetwork();    // blocks while locked
ProcessData(_data);
_adminLock.Unlock();

// Correct:
auto data = FetchFromNetwork();  // do I/O outside lock
_adminLock.Lock();
_data = data;                    // only protect the assignment
_adminLock.Unlock();
```

**Citation format:** `[PluginName.cpp:LINE] Lock held during blocking operation — minimize lock scope`

---

### rule_68

**Plugin Threads Joined in Deinitialize** | `violation` | Category: Concurrency

**What to check:** All threads started by the plugin are explicitly stopped and joined in `Deinitialize()` before it returns. Threads left running after `Deinitialize()` access null pointers.

**Where to look:** Thread creation (in `Initialize()` or during operation) and `Deinitialize()` for join/stop.

**Violation pattern:** Thread started but not joined/stopped in `Deinitialize()`.

```cpp
// WRONG:
void Deinitialize(...) {
    _service->Release(); _service = nullptr;
    // _workerThread still running — will access _service
}

// Correct:
void Deinitialize(...) {
    _workerThread.Stop();   // signal stop
    _workerThread.Wait();   // join — wait for exit
    _service->Release(); _service = nullptr;
}
```

**Citation format:** `[PluginName.cpp:LINE] Thread not joined in Deinitialize() — may access stale pointers`

---

### rule_69

**Memory and Allocation Safety** | `warning` | Category: Resource Management

**What to check:** No memory leaks (every `new` has a corresponding `delete` on all paths), no use-after-free, no buffer overflows, no large stack allocations or VLAs.

**Where to look:** All `new`/`delete` pairs, raw buffer operations, and stack-allocated arrays.

**Violation pattern:** `new` without matching `delete` on error path, or access to freed memory.

```cpp
// WRONG:
char* buffer = new char[size];
if (error) return Core::ERROR_GENERAL;  // buffer leaked
delete[] buffer;

// Correct:
std::unique_ptr<char[]> buffer(new char[size]);
if (error) return Core::ERROR_GENERAL;  // auto-freed
// Or use stack for small, known-size buffers
```

**Citation format:** `[PluginName.cpp:LINE] Memory leak on error path — 'buffer' not freed`

---

### rule_70

**Framework Pointers Not Accessed After Deinitialize** | `violation` | Category: Lifecycle Integrity

**What to check:** No worker thread, background job, or async callback can access framework pointers (`IShell*`, service pointers, notification interfaces) after `Deinitialize()` has completed and nulled them.

**Where to look:** Worker jobs, timers, and async callbacks that use `_service` or other framework pointers.

**Violation pattern:** Background task accesses `_service` without checking if it's been nulled.

```cpp
// WRONG:
void TimerExpired() {
    _service->Submit(...);  // _service may be nullptr after Deinitialize
}

// Correct:
void TimerExpired() {
    _adminLock.Lock();
    if (_service == nullptr) { _adminLock.Unlock(); return; }
    PluginHost::IShell* svc = _service;
    svc->AddRef();
    _adminLock.Unlock();
    svc->Submit(...);
    svc->Release();
}
```

**Citation format:** `[PluginName.cpp:LINE] Framework pointer accessed without null check after potential Deinitialize()`

---

### rule_71

**hresult Return Values Checked** | `violation` | Category: COM Safety

**What to check:** The return value of every `Core::hresult`-returning COM interface method call is checked and errors handled — never silently discarded.

**Where to look:** All calls to COM interface methods that return `Core::hresult`.

**Violation pattern:** `hresult` return value ignored.

```cpp
// WRONG:
_impl->SetConfiguration(config);  // return value ignored

// Correct:
Core::hresult result = _impl->SetConfiguration(config);
if (result != Core::ERROR_NONE) {
    SYSLOG(Logging::Error, "SetConfiguration failed: %d", result);
    return result;
}
```

**Citation format:** `[PluginName.cpp:LINE] hresult return value from COM call ignored`

---

### rule_72

**ASSERT Only for Programmer Invariants** | `warning` | Category: Code Quality

**What to check:** `ASSERT` is used only for conditions that represent programmer errors (invariants that should never be false in correct code). Never for runtime conditions that can legitimately fail.

**Where to look:** All `ASSERT(...)` calls — evaluate whether the condition can ever be false at runtime.

**Violation pattern:** `ASSERT` on a condition that can fail at runtime (network result, user input, config value).

*(Same principle as rule_43 — this rule targets holistic patterns across the full plugin.)*

**Citation format:** `[PluginName.cpp:LINE] ASSERT on runtime condition`

---

### rule_73

**Security: Logging, Shell, Path, and Error Exposure** | `violation` | Category: Code Quality

**What to check:** The plugin avoids: (1) logging sensitive data (passwords, tokens, PII), (2) executing shell commands with unsanitized external input, (3) exposing internal error details through JSON-RPC responses, (4) path traversal via external inputs.

**Where to look:** All `SYSLOG`/`TRACE` calls, any `system()`/`popen()` calls, JSON-RPC error responses, and path construction from external input.

**Violation pattern:** Sensitive data logged, or shell command built from unvalidated input.

```cpp
// WRONG:
SYSLOG(Logging::Info, "Auth token: %s", token.c_str());  // leaks secret
system(("rm " + userInput).c_str());                      // command injection

// Correct:
SYSLOG(Logging::Info, "Auth token received (length=%d)", token.length());
// Never use system() with external input
```

**Citation format:** `[PluginName.cpp:LINE] Sensitive data logged / unsanitized shell command`

---

### rule_74

**JSON-RPC Input Validation for Bounds and Types** | `violation` | Category: JSON-RPC Compliance

**What to check:** Every JSON-RPC handler validates numeric inputs for range bounds and type correctness before use in operations that could overflow, underflow, or cause undefined behavior.

**Where to look:** All JSON-RPC handlers that accept numeric parameters.

**Violation pattern:** Numeric input used in arithmetic or array indexing without bounds check.

```cpp
// WRONG:
uint32_t SetVolume(const uint8_t volume) {
    _device->SetVol(volume);  // no check — what if volume > 100?
}

// Correct:
uint32_t SetVolume(const uint8_t volume) {
    if (volume > 100) return Core::ERROR_BAD_REQUEST;
    _device->SetVol(volume);
    return Core::ERROR_NONE;
}
```

**Citation format:** `[PluginName.cpp:LINE] Numeric input not bounds-checked before use`

---

### rule_75

**Config Completeness and Resource Cleanup** | `warning` | Category: Code Quality

**What to check:** All configuration fields are registered with `Add()` in the `Config` constructor. All resources acquired based on configuration values are properly released in `Deinitialize()`.

**Where to look:** `Config` class constructor (for `Add()` completeness) and `Deinitialize()` (for config-based resource cleanup).

**Violation pattern:** Config field used but not registered with `Add()`, or config-acquired resource not released.

```cpp
// WRONG:
class Config : public Core::JSON::Container {
    Config() : Core::JSON::Container() {
        Add(_T("port"), &Port);
        // Timeout field used in code but not Add()'d — won't parse
    }
    Core::JSON::DecUInt16 Port;
    Core::JSON::DecUInt32 Timeout;  // missing Add()
};

// Correct:
Config() : Core::JSON::Container() {
    Add(_T("port"), &Port);
    Add(_T("timeout"), &Timeout);
}
```

**Citation format:** `[PluginName.h:LINE] Config field 'Timeout' not registered with Add()`

---

### rule_76

**OOP Error Propagation and Method Naming** | `warning` | Category: Inter-Plugin Design

**What to check:** Out-of-process method implementations properly propagate errors from the remote process back to the plugin host. Method names follow Thunder conventions — no abbreviations, clear verb+noun form.

**Where to look:** OOP implementation wrapper methods and their return value handling.

**Violation pattern:** Remote error swallowed (returns `ERROR_NONE` even when remote call failed), or method named with abbreviations.

```cpp
// WRONG:
Core::hresult GetVol(uint8_t& vol) {  // abbreviated name
    _impl->GetVolume(vol);              // ignores return value
    return Core::ERROR_NONE;
}

// Correct:
Core::hresult GetVolume(uint8_t& volume) {
    return _impl->GetVolume(volume);    // propagates error
}
```

**Citation format:** `[PluginName.cpp:LINE] OOP error not propagated / method name uses abbreviation`

---

### rule_77

**Observer Classes Private and Nested** | `suggestion` | Category: Conventions

**What to check:** Observer/notification inner classes are declared as `private` nested classes within the plugin class — not exposed as separate public classes in the header.

**Where to look:** Plugin header file — notification class declarations.

**Violation pattern:** Notification class declared outside the plugin class or as public.

```cpp
// WRONG:
class DictionaryNotification : public PluginHost::IPlugin::INotification { ... };
class Dictionary : public PluginHost::IPlugin { ... };

// Correct:
class Dictionary : public PluginHost::IPlugin {
private:
    class Notification : public PluginHost::IPlugin::INotification { ... };
};
```

**Citation format:** `[PluginName.h:LINE] Observer class not nested as private inside plugin class`

---

### rule_78

**No Deprecated JSON-RPC APIs** | `violation` | Category: JSON-RPC Compliance

**What to check:** No deprecated JSON-RPC APIs are used — no legacy `Register` overloads replaced by typed versions, no `IDispatcher`, no `Announce`-style event patterns.

**Where to look:** All JSON-RPC registration and event dispatch code.

**Violation pattern:** Use of deprecated API (e.g. untyped `Register`, legacy event dispatch).

```cpp
// WRONG:
Register("method", [this](const string& params) -> string { ... });  // legacy untyped

// Correct:
Register<JsonData::SetParams, JsonData::SetResult>(_T("method"), &Plugin::Method, this);
```

**Citation format:** `[PluginName.cpp:LINE] Deprecated JSON-RPC API used`

---

### rule_79

**All Acquired Pointers Cleared After Deinitialize** | `violation` | Category: Lifecycle Integrity

**What to check:** Every pointer member set to a non-null value during the plugin's lifetime is explicitly set to `nullptr` in `Deinitialize()` (in addition to being released). This ensures a double-`Deinitialize()` call cannot cause a double-release.

**Where to look:** All pointer members vs. `Deinitialize()` body.

**Violation pattern:** Pointer member released but not nulled, or not touched at all in `Deinitialize()`.

```cpp
// WRONG:
void Deinitialize(...) {
    _impl->Release();     // released but not nulled
    _service->Release();
    _service = nullptr;
    // _connection not touched at all
}

// Correct:
void Deinitialize(...) {
    _impl->Release(); _impl = nullptr;
    _service->Release(); _service = nullptr;
    _connection = nullptr;
}
```

**Citation format:** `[PluginName.cpp:LINE] Pointer member not set to nullptr after Release()`

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