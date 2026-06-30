# Interface Rule Manager — Rule Template Guide

Use this guide to fill in a rule template and pass it to `/thunder-interface-rule-manager`.
A filled template lets you skip the interactive questionnaire entirely — the manager parses your document,
validates it, and updates all three files in one shot:

- `ThunderTools/PluginQA/rules/thunder-interface-rules.yaml`
- `ThunderTools/PluginQA/Prompts/thunder-interface-review.prompt.md`
- `ThunderTools/openspec/changes/thunder-plugin-qa/specs/interface/spec.md`

---

## Is my rule Core or Advisory?

| Question | Core Rule | Advisory Rule |
|---|---|---|
| Does the violation break code generation (e.g. no JSON-RPC output)? | Yes | No |
| Does it cause ABI/binary compatibility issues? | Yes | No |
| Does it cause crashes or undefined behaviour at runtime? | Yes | No |
| Is it a structural requirement for Thunder COM interfaces? | Yes | No |
| Is it a design best practice that improves quality but does not break anything? | No | Yes |
| Is it a style/convention preference? | No | Yes |

**Core rules** enforce strict COM interface correctness — structural requirements that MUST be satisfied for the interface to function correctly with Thunder's code generators and runtime.

**Advisory rules** are design-quality checks that address broader best practices (single responsibility, no exceptions, enum types, @restrict usage) — violations here indicate design concerns rather than broken code generation.

If the manager determines your rule is in the wrong list, it will auto-correct with an explanation.

---

## How to use this template

1. Copy the blank template below into a new `.md` file
2. Set `Action` to `Add`, `Update`, or `Remove`
3. Fill in the fields that apply to your action (see field reference below)
4. Attach the file — or paste its contents — when you open `/thunder-interface-rule-manager`
5. The manager confirms what it parsed before making any changes

---

## Blank template

```markdown
## Interface Rule

Action: Add

Rule_ID:
Rule_List: core
Name:
Severity: violation

### Description
<!-- What the rule checks and why. 2-5 sentences explaining the impact of violations -->

### How to Find It (Extraction Logic)
<!-- Numbered steps describing how to locate the relevant code in the interface header -->
1.
2.

### How to Verify It (Verification Logic)
<!-- Numbered steps describing what constitutes a pass vs fail -->
1.
2.
3.

### Violation Pattern
<!-- Single-line description of the wrong pattern -->

### Fix
// WRONG:

// Correct:

### Example Citation
<!-- Reference to a real Thunder interface file -->
ThunderInterfaces/interfaces/IExample.h — description
```

---

## Field Reference

### `Action` *(required — must be the first field)*

| Value | When to use |
|---|---|
| `Add` | Creating a new rule that does not yet exist |
| `Update` | Changing one or more fields on an existing rule |
| `Remove` | Deleting a rule entirely |

---

### `Rule_ID` *(required for Update/Remove; optional for Add)*

Format: `core_X_1` for core rules or `advisory_mX_1` for advisory rules.

Current core rules: `core_1_1` through `core_17_1` (15 rules)
Current advisory rules: `advisory_m1_1`, `advisory_m2_1`, `advisory_m3_1`, `advisory_m5_1` (4 rules)

- **Add** — leave blank to auto-assign the next available ID, or specify your own
- **Update/Remove** — mandatory; this is how the manager finds the rule

---

### `Rule_List` *(required for Add)*

| Value | When to use |
|---|---|
| `core` | Rule enforces codegen/ABI/crash-level correctness |
| `advisory` | Rule enforces design best practices |

---

### `Name` *(required for Add; optional for Update)*

Short descriptive title in Title Case. 2-5 words.

**Good:** `@json Tag (CRITICAL)`, `Binary Compatibility`, `No std::map in Interfaces`
**Avoid:** `Check Interface`, `Tag Rule`

---

### `Severity` *(required for Add; optional for Update)*

| Value | Meaning |
|---|---|
| `violation` | Must fix — breaks code generation, ABI, or causes crashes |
| `warning` | Should fix — best practice with real risk |
| `suggestion` | Optional — style or convention preference |

Note: All 15 core rules currently use `violation`. Advisory rules use mixed severities.

---

### `### Description` *(required for Add; optional for Update)*

Explain what the rule checks and why. Include the impact of violations.
Write 2-5 sentences as if explaining to a developer unfamiliar with Thunder interfaces.

---

### `### How to Find It (Extraction Logic)` *(required for Add; optional for Update)*

Numbered steps describing how to locate the relevant code in the interface header.
Must describe reading and understanding the code, NOT searching for text patterns.

**Good:**
```
1. Read the comment lines immediately above the interface struct declaration
2. Verify the @json tag is directly adjacent to the struct declaration (no blank lines between)
```

**Avoid:**
```
1. Search for "// @json" in the file
```

---

### `### How to Verify It (Verification Logic)` *(required for Add; optional for Update)*

Numbered steps describing what constitutes a pass vs fail.
Must use semantic reasoning — understand the code, don't pattern match.

---

### `### Violation Pattern` *(required for Add; optional for Update)*

Single-line string describing the wrong pattern. Shown in the violation output.

**Good:** `No @json comment found above interface struct — no RPC code will be generated`
**Avoid:** Multi-line descriptions or bullet lists

---

### `### Fix` *(required for Add; optional for Update)*

Show corrected code using `// WRONG:` and `// Correct:` markers.

---

### `### Example Citation` *(required for Add; optional for Update)*

Reference to a real Thunder interface file showing where this rule applies.
Format: `ThunderInterfaces/interfaces/IFileName.h — description`

---

## What to fill per action

| Field | Add | Update | Remove |
|---|---|---|---|
| `Action` | Required | Required | Required |
| `Rule_ID` | Optional | Required | Required |
| `Rule_List` | Required | Only if moving | — |
| `Name` | Required | Only if changing | — |
| `Severity` | Required | Only if changing | — |
| Content sections | All | Only changed ones | — |

**Update rule:** fill only the fields you want to change — leave everything else blank.

---

## Examples

### Add — Core rule

```markdown
## Interface Rule

Action: Add

Rule_ID:
Rule_List: core
Name: No Raw Pointer Returns
Severity: violation

### Description
Interface methods must not return raw pointers. Raw pointer returns create ownership
ambiguity — callers don't know whether to call Release() on the result. All pointer
returns must use the COM pattern: pass an output pointer parameter and return Core::hresult.

### How to Find It (Extraction Logic)
1. Read all virtual method declarations in the interface struct
2. For each method, examine the return type

### How to Verify It (Verification Logic)
1. For each virtual method, check if the return type is a raw pointer (T*)
2. Exclude Core::hresult and void returns — those are correct
3. Exclude string_view and similar value types — those are not ownership transfers
4. If any method returns a raw pointer type -> VIOLATION
5. Otherwise -> PASS

### Violation Pattern
Interface method returns raw pointer — ownership ambiguity

### Fix
// WRONG:
virtual IConnection* GetConnection(const uint32_t id) = 0;

// Correct:
virtual Core::hresult GetConnection(const uint32_t id, IConnection*& connection /* @out */) = 0;

### Example Citation
ThunderInterfaces/interfaces/INetworkControl.h — method return types
```

---

### Add — Advisory rule

```markdown
## Interface Rule

Action: Add

Rule_ID:
Rule_List: advisory
Name: Method Count Limit
Severity: warning

### Description
Interfaces with more than 12 methods may violate the single responsibility principle.
Consider splitting into focused sub-interfaces. Large interfaces are harder to implement,
test, and version safely.

### How to Find It (Extraction Logic)
1. Read the interface struct declaration
2. Count all pure virtual method declarations

### How to Verify It (Verification Logic)
1. Count the number of pure virtual methods in the interface
2. If count exceeds 12 -> WARNING (suggest splitting)
3. If count is 12 or fewer -> PASS

### Violation Pattern
Interface has more than 12 methods — consider splitting

### Fix
// WRONG:
struct EXTERNAL IMediaPlayer : virtual public Core::IUnknown {
    // 15+ methods in one interface
};

// Correct:
struct EXTERNAL IMediaPlayer : virtual public Core::IUnknown {
    // Core playback methods only (8 methods)
};
struct EXTERNAL IMediaPlayerMetadata : virtual public Core::IUnknown {
    // Metadata methods split out (7 methods)
};

### Example Citation
ThunderInterfaces/interfaces/IMediaPlayer.h — interface method count
```

---

### Update — change severity and verification logic

```markdown
## Interface Rule

Action: Update

Rule_ID: core_5_1

Severity: violation

### How to Verify It (Verification Logic)
1. For @json-tagged interfaces in Thunder 5.0+, ALL action methods must return Core::hresult
2. Getter methods (property getters) may return the value type directly
3. If any action method returns void or another type -> VIOLATION
```

---

### Remove

```markdown
## Interface Rule

Action: Remove

Rule_ID: advisory_m2_1
```

The manager confirms the rule name before deleting.

---

## Common mistakes

| Mistake | Problem | Fix |
|---|---|---|
| Extraction logic uses "search for" language | Must reason semantically | Write "read and examine" not "search for" |
| Violation pattern is multi-line | Must be single-line string | Condense to one sentence |
| Missing Example Citation | Manager cannot validate against real code | Always reference a real Thunder interface file |
| Core rule that is actually best-practice | Manager will flag misclassification | Let manager auto-correct to advisory |
| Advisory rule that breaks codegen | Manager will flag misclassification | Let manager auto-correct to core |
| `Rule_ID` format wrong | Must be `core_X_1` or `advisory_mX_1` | Check existing IDs in YAML |

---

## Quick reference

```
## Interface Rule

Action:      Add | Update | Remove
Rule_ID:     e.g. core_18_1 or advisory_m6_1
Rule_List:   core | advisory
Name:        Title Case, 2-5 words
Severity:    violation | warning | suggestion

### Description              — the WHY (required for Add)
### How to Find It           — extraction steps (required for Add)
### How to Verify It         — verification steps (required for Add)
### Violation Pattern        — single-line summary (required for Add)
### Fix                      — WRONG / Correct code (required for Add)
### Example Citation         — real Thunder interface reference (required for Add)
```
