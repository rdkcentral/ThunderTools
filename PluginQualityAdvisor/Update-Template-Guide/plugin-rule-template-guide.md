# Plugin Rule Manager — Rule Template Guide

Use this guide to fill in a rule template and pass it to `/thunder-plugin-rule-manager`.
A filled template lets you skip the interactive questionnaire entirely — the manager parses your document,
validates it, and updates all four files in one shot:

- `ThunderTools/PluginQualityAdvisor/rules/thunder-plugin-rules.yaml`
- `ThunderTools/PluginQualityAdvisor/Prompts/thunder-plugin-review.prompt.md`
- `ThunderTools/PluginQualityAdvisor/README.md`
- `ThunderTools/.github/openspec/changes/thunder-plugin-qa/specs/plugin/spec.md`

---

## Which template should I use?

Use this table to pick the right template. Both follow the same semantic-review methodology.

| Question | Template A | Template B |
|---|---|---|
| Does the rule focus on a specific function or declaration? | Yes | No |
| Does the rule check behavior across multiple parts of the plugin? | No | Yes |
| Does it involve thread safety, resource cleanup flow, or security? | No | Yes |

**Mostly Template A answers -> use Template A (Phase Checkpoint).**
**Any Template B answer -> use Template B (Holistic Rule).**

If your rule could go either way, the manager will offer you both options and ask you to confirm.

---

## How to use this template

1. Copy the appropriate blank template below into a new `.md` file
2. Set `Action` to `Add`, `Update`, or `Remove`
3. Fill in the fields that apply to your action (see field reference below)
4. Attach the file — or paste its contents — when you open `/thunder-plugin-rule-manager`
5. The manager confirms what it parsed before making any changes

---

## Template A — Phase Checkpoint Rule

Phase checkpoint rules are organized under phase sections (rule_01 to rule_38).

### Blank template

```markdown
## Plugin Rule — Phase Checkpoint

Action: Add

Rule_ID:
Phase: Phase 4 — Lifecycle
Name:
Severity: violation

### What This Rule Checks
<!-- Why does this rule exist? What bug or problem does it prevent? -->

### Extraction Target
<!-- Which specific code block to read? e.g. "Initialize() method body" -->

### Yes/No Question
<!-- Single yes/no question. Expected answer is always Yes. -->

### Verification Steps
1.
2.
3.

### Violation Pattern
<!-- One-line summary under 10 words -->

### Fix
// WRONG:

// CORRECT:

### Conditional
No
Skip when:
```

---

## Template B — Holistic Rule

Holistic rules check broader plugin behavior such as thread safety, resource handling, and cleanup flow by looking at related code together. They are organized under 8 sub-phases (rule_39 to rule_84).

### Blank template

```markdown
## Plugin Rule — Holistic

Action: Add

Rule_ID:
Category: concurrency
Name:
Severity: violation

### What This Rule Checks
<!-- Why does this rule exist? What architectural problem does it prevent? -->

### Review Question
<!-- Semantic question about what to verify across the plugin -->

### Review Method
<!-- How to evaluate. Must describe reading full code context, not pattern matching -->

### Evidence Requirement
<!-- What the validator must provide on failure. Must include [File:line] citation -->
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

Sequential identifier in the format `rule_XX` (e.g. `rule_17`, `rule_41`).

- **Add** — leave blank to auto-assign the next available number, or specify your own
- **Update/Remove** — mandatory; this is how the manager finds the rule

Current rule ranges:
- rule_01 to rule_38: Phase checkpoints
- rule_39 to rule_84: Holistic rules

---

### `Phase` *(required for Add phase checkpoint; not used for holistic rules)*

Pick exactly one:

```
Phase 1 — Module Structure       (currently: rule_01 to rule_03)
Phase 2 — Code Style             (currently: rule_04 to rule_13)
Phase 3 — Class Registration     (currently: rule_14 to rule_16)
Phase 4 — Lifecycle              (currently: rule_17 to rule_28)
Phase 5 — Implementation         (currently: rule_29 to rule_31)
Phase 5C — Out-of-Process        (currently: rule_32 to rule_33)
Phase 6 — Configuration          (currently: rule_34 to rule_36)
Phase 7 — CMake                  (currently: rule_37)
Phase 8 — COM Interface Rules    (currently: rule_38)
```

---

### `Category` *(required for Add holistic rule; not used for phase checkpoints)*

| Category | What it covers |
|---|---|
| `conventions` | Code style, naming, headers, pragmas |
| `lifecycle_integrity` | State management, cleanup, Deinitialize correctness |
| `concurrency` | Thread safety, locking, re-entrancy |
| `com_safety` | COM reference counting, AddRef/Release balance |
| `resource_management` | RAII, memory, file descriptors, bounded containers |
| `jsonrpc_compliance` | JSON-RPC handler correctness, input validation |
| `inter_plugin_design` | Plugin dependencies, registration order |
| `code_quality_security` | Security, ASSERT usage, error propagation |

---

### `Name` *(required for Add; optional for Update)*

Short descriptive title in Title Case. 2-5 words.

**Good:** `Observer Cleanup In Deinitialize`, `Handlers Must Not Block`
**Avoid:** `Check Initialize`, `COM Rule`

---

### `Severity` *(required for Add; optional for Update)*

| Value | Meaning | Report symbol |
|---|---|---|
| `violation` | Must fix — causes bugs, crashes, or codegen failures | VIOLATION |
| `warning` | Should fix — best practice with real risk | WARNING |
| `suggestion` | Optional — style or consistency improvement | SUGGESTION |

---

### Phase Checkpoint-specific fields

- **Extraction Target** — exact function/section/lines to read (e.g. "Initialize() method body")
- **Yes/No Question** — single binary question; Yes = PASS, No = VIOLATION
- **Verification Steps** — 3-8 numbered steps using semantic reasoning (never regex)
- **Violation Pattern** — one-line citation summary, under 10 words
- **Fix** — `// WRONG:` and `// CORRECT:` code snippets
- **Conditional** — `Yes` or `No`; if Yes, include `Skip when:` condition

### Holistic Rule-specific fields

- **Review Question** — semantic question spanning multiple code paths
- **Review Method** — must describe reading full code context, not pattern matching
- **Evidence Requirement** — must require exact `[File:line]` citation

---

## What to fill per action

| Field | Add (Phase) | Add (Holistic) | Update | Remove |
|---|---|---|---|---|
| `Action` | Required | Required | Required | Required |
| `Rule_ID` | Optional | Optional | Required | Required |
| `Phase` | Required | — | Only if changing | — |
| `Category` | — | Required | Only if changing | — |
| `Name` | Required | Required | Only if changing | — |
| `Severity` | Required | Required | Only if changing | — |
| Content sections | All | All | Only changed ones | — |

**Update rule:** fill only the fields you want to change — leave everything else blank.

---

## Examples

### Add — Phase Checkpoint rule

```markdown
## Plugin Rule — Phase Checkpoint

Action: Add

Rule_ID:
Phase: Phase 4 — Lifecycle
Name: Observer Cleanup In Deinitialize
Severity: violation

### What This Rule Checks
When a plugin calls Register() in Initialize() to attach an observer, it must call
Unregister() with the same observer in Deinitialize(). Failing to do so leaves a
dangling observer pointer causing a crash on the next event dispatch.

### Extraction Target
Deinitialize() method body and Initialize() method body

### Yes/No Question
Is Unregister() called in Deinitialize() for every observer registered in Initialize()?

### Verification Steps
1. Read Initialize() and collect all Register() call arguments
2. If no Register() calls are found -> SKIP
3. Read Deinitialize() and collect all Unregister() call arguments
4. For each observer registered in step 1, check if a matching Unregister() exists
5. If any observer is missing its Unregister() -> VIOLATION
6. Otherwise -> PASS

### Violation Pattern
Observer registered but not unregistered in Deinitialize()

### Fix
// WRONG:
void MyPlugin::Deinitialize(PluginHost::IShell* service)
{
    _service->Release();
    _service = nullptr;
}

// CORRECT:
void MyPlugin::Deinitialize(PluginHost::IShell* service)
{
    service->Unregister(&_notification);
    _service->Release();
    _service = nullptr;
}

### Conditional
Yes
Skip when: no Register() calls exist in Initialize()
```

---

### Add — Holistic Rule

```markdown
## Plugin Rule — Holistic

Action: Add

Rule_ID:
Category: concurrency
Name: Shared State Protected by CriticalSection
Severity: violation

### What This Rule Checks
Any member variable accessed from multiple threads (JSON-RPC handlers,
notification callbacks, WorkerPool jobs) must be protected by Core::CriticalSection.
Unprotected concurrent access causes data races and undefined behaviour.

### Review Question
Is every shared member variable protected by Core::CriticalSection on all access paths?

### Review Method
Read the full plugin class declaration to identify member variables. For each variable,
trace all access points across Initialize, Deinitialize, JSON-RPC handlers, notification
callbacks, and WorkerPool jobs. Verify each access path acquires _adminLock or equivalent.
Do not use pattern-only checks — reason about actual control flow and thread boundaries.

### Evidence Requirement
Provide exact [File:line] citation for each unprotected shared member access,
including which threads can reach that code path concurrently.
```

---

### Update — partial (change severity and question only)

```markdown
## Plugin Rule — Phase Checkpoint

Action: Update

Rule_ID: rule_06

Severity: violation

### Yes/No Question
Is nullptr used in place of NULL everywhere in the plugin source files?
```

---

### Remove

```markdown
## Plugin Rule — Phase Checkpoint

Action: Remove

Rule_ID: rule_06
```

The manager confirms the rule name and phase before deleting.

---

## Common mistakes

| Mistake | Problem | Fix |
|---|---|---|
| Yes/No Question is open-ended | Cannot produce binary PASS/FAIL | Rewrite as: "Is X present immediately after Y?" |
| Verification Steps describe text search | Steps must reason semantically | Write "read and determine" not "search for" |
| Violation Pattern left empty | Citation has no summary | Always fill — under 10 words |
| `Conditional: Yes` without `Skip when:` | No condition to evaluate | Always complete `Skip when:` |
| Wrong `Rule_ID` on Update/Remove | Manager reports "not found" | Verify ID in YAML before submitting |
| All fields filled on Update | Unintended overwrites | Fill only changed fields |
| Phase rule requires cross-file reasoning | Should be Holistic | Use Template B |
| Holistic rule reducible to one yes/no | Should be Phase Checkpoint | Use Template A |

---

## Quick reference

```
PHASE CHECKPOINT (Template A)         HOLISTIC RULE (Template B)

Action:    Add | Update | Remove      Action:    Add | Update | Remove
Rule_ID:   e.g. rule_17              Rule_ID:   e.g. rule_48
Phase:     Phase 4 — Lifecycle        Category:  concurrency
Name:      Title Case, 2-5 words      Name:      Title Case, 2-5 words
Severity:  violation|warning|suggestion   Severity:  violation|warning|suggestion

### What This Rule Checks             ### What This Rule Checks
### Extraction Target                  ### Review Question
### Yes/No Question                    ### Review Method
### Verification Steps                 ### Evidence Requirement
### Violation Pattern
### Fix
### Conditional
```