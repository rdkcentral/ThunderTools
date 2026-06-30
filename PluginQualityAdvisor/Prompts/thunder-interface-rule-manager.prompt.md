---
title: "Thunder Interface Rule Manager"
description: "Add, update, or remove COM interface validation rules via guided questionnaire — keeps YAML, prompt, and spec in sync"
---

## Purpose

This prompt manages rules in `ThunderTools/PluginQA/rules/thunder-interface-rules.yaml` and keeps all related files in sync atomically:

1. `ThunderTools/PluginQA/rules/thunder-interface-rules.yaml` — rule data
2. `ThunderTools/PluginQA/Prompts/thunder-interface-review.prompt.md` — Quick Reference table + rule detail blocks
3. `ThunderTools/openspec/changes/thunder-plugin-qa/specs/interface/spec.md` — spec requirements

---

## Step 0 — Document Template Fast Path

If the user pastes a filled template with the following sections, skip the questionnaire and proceed directly to Step 3/4:

```
## Description
<what the rule checks and why>

## How to Find It (Extraction Logic)
1. <step 1>
2. <step 2>

## How to Verify It
1. <verification step 1>
2. <verification step 2>

## Violation Pattern
<single-line description of wrong pattern>

## Fix
// WRONG:
<wrong code>

// Correct:
<correct code>

## Example
<reference to a real Thunder interface file>
```

After receiving a template, also run **Core vs Advisory Classification** to verify the rule list placement is correct.

---

## Step 1 — Collect Action

Ask the user the following questions using `vscode_askQuestions`:

**Question 1** (header: `action`):
What do you want to do?
- Add a new rule
- Update an existing rule
- Remove a rule

**Question 2** (header: `rule_list`):
Is this a core rule or an advisory rule?

Options:
- Core rule (codegen failure, ABI breakage, or crash risk)
- Advisory rule (best practice or style)

Message: |
  **Core rules** are violations that cause codegen failures, ABI breakage, runtime crashes,
  or incorrect RPC behaviour. All 15 current core rules are severity: violation.
  Examples: missing @json tag, wrong return type, missing @restrict on std::vector.

  **Advisory rules** are best-practice or style guidance that improves interface quality
  but does not cause immediate failures.
  Examples: single responsibility, explicit enum types.

---

## Step 2 — Branch by Action

### Branch: REMOVE

Ask for the rule ID only (e.g. `core_1_1` or `advisory_m2_1`) then go to **Step 4**.

### Branch: UPDATE

**(2a)** Ask for the rule ID.

**(2b)** Read the current rule from `thunder-interface-rules.yaml` and display it annotated with numbered field labels:

```
[1] id: <value>
[2] name: <value>
[3] severity: <value>
[4] description: <value>
[5] extraction_logic: <value>
[6] verification_logic: <value>
[7] violation_pattern: <value>
[8] fix_template: <value>
[9] citation: <value>
```

Note: There is **no `category` field**.

**(2c)** Ask the user (via `vscode_askQuestions`, multi-select): Which fields do you want to change? (select from [1]–[9])

**(2d)** For each selected field number, ask only the new value.

Then go to **Step 3**.

### Branch: ADD

Ask all fields via `vscode_askQuestions`:

- **id**: What is the rule ID? (e.g. `core_18_1` or `advisory_m6_1`)
  Message: Core rules use `core_N_1` numbering. Advisory rules use `advisory_mN_1`.

- **name**: What is the rule name? (Title Case, e.g. "No Inline Default Values")

- **severity**: What is the severity?
  Options: violation | warning | suggestion

- **description**: Describe what the rule checks and why it matters. (multiline)

- **extraction_logic**: How should the validator find the relevant code? (numbered steps)
  Message: Describe reading and understanding the code — not searching for patterns.
           Example: "1. Read the full interface declaration\n2. Identify all method parameter types"

- **verification_logic**: What are the verification steps? (numbered steps)
  Message: Each step must describe semantic reasoning — "Reason about X", never "search for Y".

- **violation_pattern**: Single-line description of the wrong pattern.

- **fix_template**: Show WRONG pattern and Correct pattern.

- **citation**: A reference to a real Thunder interface file that illustrates the rule.

---

## Step 3 — Apply Changes (ADD / UPDATE)

### Update `thunder-interface-rules.yaml`:

1. Add/update the rule in the `core_rules` or `advisory_rules` list as appropriate
2. **Do NOT add a `category` field**
5. Update rule count comments if present

### Update `thunder-interface-review.prompt.md`:

1. Add/update the row in the **Quick Reference table** with: `| id | Name | Key Point |`
2. The Quick Reference table row is the only required prompt edit for most rule changes

### Update `specs/interface/spec.md`:

1. Add/update the corresponding requirement line for the new/changed rule

---

## Step 4 — Remove Rule

### From `thunder-interface-rules.yaml`:
- Remove the entire rule block from the `core_rules` or `advisory_rules` list


### From `thunder-interface-review.prompt.md`:
- Remove the row from the Quick Reference table for the removed rule

### From `specs/interface/spec.md`:
- Remove the corresponding requirement line

---

## Step 5 — Confirmation Report

After completing all changes, display:

```
## Interface Rule Manager — Changes Applied

**Action:** [Add/Update/Remove]
**Rule:** [id] — [name]
**List:** [Core/Advisory]

### Files Updated
| File | Change |
|------|--------|
| thunder-interface-rules.yaml | [Added/Updated/Removed] rule |
| thunder-interface-review.prompt.md | Quick Reference table [updated/row added/row removed] |
| specs/interface/spec.md | Requirement [added/updated/removed] |
```

---

## Core vs Advisory Classification

| Criterion | Core ✅ | Advisory ✅ |
|-----------|---------|------------|
| Causes codegen failure (missing @json, wrong return type) | ✅ | ❌ |
| Causes ABI breakage (vtable incompatibility, type size change) | ✅ | ❌ |
| Causes runtime crash or RPC protocol error | ✅ | ❌ |
| Prevents cross-process serialisation | ✅ | ❌ |
| Best practice / style improvement | ❌ | ✅ |
| Improves maintainability or SRP | ❌ | ✅ |

**Wrong-list correction:** If a submitted rule clearly belongs in the other list (e.g. a crash-causing rule submitted as advisory), move it to the correct list and explain the reclassification to the user before applying changes.


