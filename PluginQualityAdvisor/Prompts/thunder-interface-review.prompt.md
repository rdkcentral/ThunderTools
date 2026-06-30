## Context

Thunder uses COM-style interfaces defined in `ThunderInterfaces/interfaces/`. These interfaces are binary contracts used across process boundaries. All validation uses semantic reasoning — the validator reads the interface header in full as a human reviewer would, never using regex or text search as the primary detection method.

Rules are loaded at runtime from: `ThunderTools/PluginQA/rules/thunder-interface-rules.yaml`

---

## Quick Reference — All 19 Rules

| ID | Rule | Key Point |
|----|------|-----------|
| core_1_1 | File and Namespace Structure | Must be in WPEFramework::Exchange namespace; file name matches interface name |
| core_2_1 | Interface Declaration Shape | struct EXTERNAL, virtual Core::IUnknown, ID enum, all pure virtual |
| core_3_1 | Interface ID Registration | ID must be RPC::ID_* constant registered in ids.h |
| core_4_1 | Pure Virtual Methods Only | All methods = 0, no inline code, no static methods |
| core_5_1 | Return Type Conventions | Core::hresult mandatory for @json interfaces in Thunder 5.0+ |
| core_6_1 | Const Correctness | @out parameters must be non-const references |
| core_9_1 | Thunder Type Conventions | string not std::string; explicit integer widths |
| core_10_1 | Register/Unregister Patterns | INotification: Register+Unregister; ICallback: Callback(nullptr clears) |
| core_11_1 | Nested Event Interfaces | @event tag required; EXTERNAL; own ID; inherits Core::IUnknown |
| core_12_1 | @json Tag (CRITICAL) | Without @json, ZERO RPC code generated |
| core_13_1 | Binary Compatibility | No method removal, reordering, or signature changes in released interfaces |
| core_14_1 | No AddRef/Release Redeclaration | Inherited from Core::IUnknown — never redeclare |
| core_15_1 | No std::map in Interfaces | Not serialisable across process boundaries |
| core_16_1 | Explicit Integer Widths | uint32_t not int; no platform-dependent types |
| core_17_1 | @restrict Mandatory with std::vector | Every std::vector parameter must have @restrict:N |
| advisory_m1_1 | Single Responsibility Principle | One coherent purpose per interface |
| advisory_m2_1 | Enum Underlying Types | Named enums used as params need explicit type; anonymous ID enum excluded |
| advisory_m3_1 | No Exceptions | No throw; use Core::hresult for errors |
| advisory_m5_1 | @restrict for Non-vector Params | Advisory for non-vector params with natural bounds (not std::vector — covered by core_17_1) |

---

> **CRITICAL:** Load `ThunderTools/PluginQA/rules/thunder-interface-rules.yaml` before validating. The YAML contains the full rule definitions, extraction logic, verification logic, and fix templates. This quick reference is a navigation aid only.

---

## Your Task

1. **Identify** the interface file to validate (from user's command or ask if not provided)
2. **Load** `ThunderTools/PluginQA/rules/thunder-interface-rules.yaml` for full rule definitions
3. **Validate** the interface against all 19 rules in order (core_1_1 → core_17_1, then advisory_m1_1 → advisory_m5_1)
4. **Report** with grouped sections using the output format below
5. **Provide** specific fix examples using the `fix_template` from the YAML

For each rule, apply contextual judgment (JUDGE step): if the developer's approach technically violates a rule but is valid and reasonable in their specific context, downgrade the severity and populate the `Reasoning` field.

---

## Step 6 — Generate CSV Report

After reporting results in chat, generate a CSV file:

**File path:** `ThunderTools/PluginQA/Reports/interface/{InterfaceName}_{YYYY-MM-DD}.csv`

- Create `ThunderTools/PluginQA/Reports/interface/` if it does not exist
- Never overwrite an existing file — append `_2`, `_3` etc. if needed

**CSV columns (exact order):**

| Column | Description | Example |
|--------|-------------|---------|
| No | Row number starting at 1 | `1` |
| Interface | Interface filename without extension | `IHdmiCecSink` |
| Date | ISO date of review | `2026-06-05` |
| Rule_ID | YAML rule id | `core_12_1` |
| Rule_Name | Rule name | `@json Tag (CRITICAL)` |
| Status | Effective status after JUDGE step | `VIOLATION` |
| Severity | YAML severity | `violation` |
| File | Interface file | `IHdmiCecSink.h` |
| Line | Exact line number | `45` |
| Citation | Short citation string | `[IHdmiCecSink.h:45]` |
| Issue_Description | What was found | `@json tag missing above struct declaration` |
| Fix_Summary | One-line fix | `Add // @json 1.0.0 above struct EXTERNAL` |
| Reasoning | Populated only on severity downgrade; empty otherwise | `` |

**Formatting rules:**
- UTF-8, no BOM, CRLF line endings
- Fields containing commas must be wrapped in double quotes
- Embedded double quotes escaped as `""`
- Empty fields: leave blank (two consecutive commas)
- One row per violated rule only — PASS rows excluded

**If no issues found:** Generate header row + comment row:

```csv
No,Interface,Date,Rule_ID,Rule_Name,Status,Severity,File,Line,Citation,Issue_Description,Fix_Summary,Reasoning
,,,,,,,,,,All rules passed — no issues found,,
```

**Post-generation message:**
```
📊 Report saved:
   ThunderTools/PluginQA/Reports/interface/{InterfaceName}_{YYYY-MM-DD}.csv
   {N} issue(s) logged — {violations} violations, {warnings} warnings, {suggestions} suggestions

To open in Excel (Windows):
   Start-Process "ThunderTools\PluginQA\Reports\interface\{InterfaceName}_{YYYY-MM-DD}.csv"
```

---

## Example Output Structure

```
## Thunder Interface Validation — IHdmiCecSink

### 🔴 Violations (Must Fix)

**core_12_1 — @json Tag (CRITICAL)**
Status: VIOLATION
Citation: [IHdmiCecSink.h:45] @json tag missing above struct declaration
Issue: Without @json 1.0.0, ZERO JSON-RPC code will be generated for this interface.
Fix:
  // @json 1.0.0       ← ADD THIS LINE
  struct EXTERNAL IHdmiCecSink : virtual public Core::IUnknown {

---

### 🟡 Warnings (Should Fix)

**core_16_1 — Explicit Integer Widths**
Status: WARNING
Citation: [IHdmiCecSink.h:72] int parameter — use uint32_t
Issue: int type is platform-dependent and may differ in size across architectures.
Fix: Replace `const int volume` with `const uint32_t volume`

---

### 🟢 Suggestions (Optional)

(none)

---

### ✅ Validated (N rules passed)

core_1_1, core_2_1, core_3_1, core_4_1, core_5_1, core_6_1, core_9_1,
core_10_1, core_11_1, core_13_1, core_14_1, core_15_1, core_17_1,
advisory_m1_1, advisory_m2_1, advisory_m3_1, advisory_m5_1

---

### Compatibility Notes

(Binary compatibility assessment — note if interface appears to be newly created vs released)
```

---

## Contextual Judgment (JUDGE step)

| Scenario | Status field | Reasoning field |
|----------|-------------|-----------------|
| Rule satisfied | `PASS` — include in ✅ section | Omit |
| Rule violated, no mitigation | `VIOLATION` / `WARNING` / `SUGGESTION` | Omit |
| Rule technically violated but developer's approach is valid | Downgrade one level + `Status` field shows downgraded level | **Required** |

The `Status` field reflects the **effective** severity after JUDGE:
- `violation` → `VIOLATION` (🔴), downgrade to `WARNING` (🟡) or `SUGGESTION` (🟢)
- `warning` → `WARNING` (🟡), downgrade to `SUGGESTION` (🟢)
- `suggestion` → `SUGGESTION` (🟢)

Severity is **never escalated** above the YAML-defined level.

---

## Common Critical Issues

- **Missing @json tag** — the #1 cause of "why is there no JSON-RPC for my interface?" — results in zero generated code
- **std::vector without @restrict** — required; missing @restrict produces unsafe unbounded deserialization
- **std::map in interface** — not serialisable across process boundaries; use iterators instead
- **Missing nested IDs** — INotification/ICallback without their own RPC::ID_* values
- **Ambiguous integer types** — `int` and `long` change size on different platforms; always use uint32_t etc.

---

## Important Notes

- Thunder documentation: https://rdkcentral.github.io/Thunder/
- Validation priorities: @json tag first → Core::hresult returns → @restrict on vectors → type conventions → binary compatibility → advisory rules
- Load the YAML before every validation run — rules may have been updated since this prompt was created
- Interface headers are in `ThunderInterfaces/interfaces/` — search there first