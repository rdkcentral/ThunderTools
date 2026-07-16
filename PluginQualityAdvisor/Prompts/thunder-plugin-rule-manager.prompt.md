---
title: "Thunder Plugin Rule Manager"
description: "Add, update, or remove Thunder plugin validation rules and keep related files in sync."
---

## Purpose

This prompt manages rules in `PluginQualityAdvisor/rules/thunder-plugin-rules.yaml` and keeps all related files in sync atomically:

1. `PluginQualityAdvisor/rules/thunder-plugin-rules.yaml` - rule data
2. `PluginQualityAdvisor/Prompts/thunder-plugin-review.prompt.md` - checkpoint descriptions
3. `PluginQualityAdvisor/README.md` - documentation
4. `.github/openspec/changes/thunder-plugin-qa/specs/plugin/spec.md` - spec requirements

---

## Step 0 - Document Template Fast Path

If the user pastes a filled template with the following sections, skip the questionnaire and go directly to Step 3/4:

```
## What This Rule Checks
<description of what the rule validates>

## Extraction Target
<which code block to read>

## Yes/No Question
<the bounded yes/no question>

## Verification Steps
1. <first step>
2. <second step>

## Violation Pattern
<single-line description of what's wrong>

## Fix
<WRONG pattern and Correct pattern>

## Conditional
Yes/No - and if Yes, what is the skip condition?
```

After receiving a template, also run **Phase Checkpoint vs Holistic Classification** to verify the template classification is correct before proceeding.

---

## Step 1 - Collect Action

Ask the user the following questions using `vscode_askQuestions`:

**Question 1** (header: `action`):
What do you want to do?
- Add a new rule
- Update an existing rule
- Remove a rule

**Question 2** (header: `rule_kind`):
Is this a phase checkpoint rule or a holistic rule?

Options:
- Phase checkpoint rule (bounded yes/no query, one code block)
- Holistic rule (semantic review, requires full-plugin reasoning)

Message: |
  **Phase checkpoint rule:** Can be reduced to ONE yes/no question on ONE specific code block.
  Example: "Is AddRef() called immediately after assigning the IShell* pointer?"

  **Holistic rule:** Requires architectural judgment, threading analysis, security reasoning,
  or reading multiple code paths that cannot be bounded to a single yes/no question.
  Example: "Are all notification callbacks safe from deadlock across the full plugin lifecycle?"

**Question 3** (header: `phase`) - ask only if rule_kind = Phase checkpoint:
Which phase does this rule belong to?

Options:
- Phase 1 - Module Structure (currently: rule_01 to rule_03)
- Phase 2 - Code Style (currently: rule_04 to rule_13)
- Phase 3 - Class Registration (currently: rule_14 to rule_16)
- Phase 4 - Lifecycle (currently: rule_17 to rule_28)
- Phase 5 - Implementation (currently: rule_29 to rule_31)
- Phase 5C - Out-of-Process (currently: rule_32 to rule_33)
- Phase 6 - Configuration (currently: rule_34 to rule_36)
- Phase 7 - CMake (currently: rule_37)
- Phase 8 - COM Interface Rules (currently: rule_38)

---

## Step 2 - Branch by Action

### Branch: REMOVE

Ask for the rule ID (rule_XX) then go to **Step 4**.

### Branch: UPDATE

**(2a)** Ask for the rule ID.

**(2b)** Read the current rule from `thunder-plugin-rules.yaml` and display it annotated with numbered field labels:

```
[1] rule_id: <value>
[2] name: <value>
[3] severity: <value>
[4] phase: <value>
[5] extraction.target: <value>             (phase checkpoint only)
[6] extraction.method: <value>             (phase checkpoint only)
[7] bounded_query.question: <value>        (phase checkpoint only)
[8] verification_logic: <list>             (phase checkpoint only)
[9] violation_pattern: <value>
[10] fix_template: <value>
[11] conditional: <value>                  (phase checkpoint only)
[12] skip_condition: <value>               (phase checkpoint only)
[13] citation.line_format: <value>         (phase checkpoint only)
[14] review_question: <value>              (holistic only)
[15] review_method: <value>                (holistic only)
[16] evidence_requirement: <value>         (holistic only)
```

**(2c)** Ask the user (via `vscode_askQuestions`, multi-select): Which fields do you want to change? (list field numbers)

**(2d)** For each selected field, ask for the new value only.

Then go to **Step 3**.

### Branch: ADD (phase checkpoint)

Ask the following via `vscode_askQuestions`:

- **rule_id**: What is the checkpoint ID? (e.g. `rule_17`)
  Message: Use sequential `rule_XX` numbering matching the existing phase ranges.

- **name**: What is the rule name? (Title Case, e.g. "No Raw Pointers After Move")

- **severity**: What is the severity?
  Options: violation | warning | suggestion

- **extraction_target**: What specific code block should be extracted?
  Message: Describe the EXACT code location (e.g. "All ->Release() calls on member variables in Deinitialize()")

- **extraction_method**: How should the code be read?
  Message: ✅ "Read the full function body as a human developer..."
           ❌ "Search for the pattern X..." (do not use search/regex language)

- **bounded_question**: What is the yes/no question?
  Message: ✅ "Is nullptr assigned immediately after every ->Release() call on a member?"
           ❌ "Does the code have nullptr after Release?" (too vague)

- **verification_steps**: What are the verification steps? (numbered list)
  Message: Each step must describe semantic reasoning - "Read X and reason about Y". Never "search for" or "match pattern".

- **violation_pattern**: Single-line description of what's wrong.

- **fix_template**: Show WRONG pattern and Correct pattern.

- **conditional**: Is this rule conditional (SKIP if prerequisite not found)? Yes/No
  If Yes: What is the skip condition?

### Branch: ADD (holistic)

Ask only:

- **rule_id**: What is the rule ID? (e.g. `rule_80`)
- **name**: What is the rule name? (Title Case)
- **severity**: Options: violation | warning | suggestion
- **review_question**: What semantic question describes what to verify?
  Message: Frame as a full-context semantic question, e.g. "Using semantic reasoning over the full lifecycle, is every..."
- **review_method**: (pre-filled) "Read the full relevant code context (control flow, ownership, lifecycle, and threading where applicable) before deciding PASS/FAIL/SUGGEST. Do not use pattern-only checks."
- **evidence_requirement**: (pre-filled) "Provide exact [File:line] citation for any failure."

---

## Step 3 - Apply Changes (ADD / UPDATE)

### Update `thunder-plugin-rules.yaml`:

**For phase checkpoint rules:**
- Add/update the rule in the correct `phase_N_checkpoints` section
- Rule must use object form for `bounded_query`: `{ question: "...", expected_answer: "Yes" }`
- `verification_logic` must be a YAML list of numbered step strings (`- "1. ..."`)
- Increment `total_rules` in the `metadata` block

**For general rules:**
- Add/update the rule in the `general_rules` section
- Include: rule_id, name, severity, `category: "<sub-phase>" (conventions|lifecycle_integrity|concurrency|com_safety|resource_management|jsonrpc_compliance|inter_plugin_design|code_quality_security)`, review_question, review_method, evidence_requirement
- **Do NOT add** extraction, bounded_query, or verification_logic fields to general rules
- Increment `total_general_rules` in the `metadata` block

### Update `thunder-plugin-review.prompt.md`:

- Add/update the checkpoint description in the appropriate Phase section
- Include: rule_id, severity indicator, name, SKIP condition (if conditional), query text, citation format
- Update the phase count total if a new rule was added

### Update `README.md`:

- Add/update the rule entry under the appropriate phase in the Plugin Validation section
- Update checkpoint counts in the Validation Phases table

### Update `specs/plugin/spec.md`:

- Add/update the corresponding scenario in the spec under the relevant phase

---

## Step 4 - Remove Rule

### From `thunder-plugin-rules.yaml`:
- Remove the entire rule block from the appropriate section
- Decrement `total_rules` or `total_general_rules` in metadata

### From `thunder-plugin-review.prompt.md`:
- Remove the checkpoint description from the appropriate Phase section
- Update the phase count total

### From `README.md`:
- Remove the rule entry from the Plugin Validation section
- Update checkpoint counts

### From `specs/plugin/spec.md`:
- Remove the corresponding scenario

---

## Step 5 - Confirmation Report

After completing all changes, display:

```
## Rule Manager - Changes Applied

**Action:** [Add/Update/Remove]
**Rule:** [rule_id] - [name]
**Type:** [Phase checkpoint/Holistic]

### Files Updated
| File | Change |
|------|--------|
| thunder-plugin-rules.yaml | [Added/Updated/Removed] rule; total phase checkpoints: N, holistic: N |
| thunder-plugin-review.prompt.md | [Added/Updated/Removed] Phase N checkpoint description |
| README.md | [Added/Updated/Removed] rule entry; Phase N total: N checkpoints |
| specs/plugin/spec.md | [Added/Updated/Removed] scenario |
```

---

## Phase Checkpoint vs Holistic Classification

| Criterion | Phase checkpoint ✅ | Holistic ✅ |
|-----------|-------------|----------|
| Can reduce to ONE yes/no question | ✅ | ❌ |
| Targets ONE specific code block | ✅ | ❌ |
| Result is verifiable/reproducible across runs | ✅ | Requires judgment |
| Requires understanding multiple code paths | ❌ | ✅ |
| Requires architectural/threading/security reasoning | ❌ | ✅ |
| Would need a bounded query covering entire codebase | ❌ | ✅ |

**Phase checkpoint criteria (all 5 must be YES):**
1. Can express as a single yes/no bounded query?
2. Targets a single specific code block?
3. Verification logic is a numbered list of semantic reasoning steps?
4. Does NOT require broad architectural concern analysis?
5. Does NOT require multi-path reasoning?

**Holistic criteria (any of these → holistic):**
1. Requires holistic code understanding beyond one function?
2. Involves threading, concurrency, or re-entrancy analysis?
3. Involves security reasoning or OWASP-type checks?
4. Requires understanding of architectural patterns (observer, lifecycle symmetry)?
5. Requires reading multiple code paths to decide?
6. Cannot be reduced to a single bounded yes/no query?

**Ambiguous cases:** If the classification is not clear, ask the user before proceeding. Display the classification criteria above and explain which criteria pull each way.