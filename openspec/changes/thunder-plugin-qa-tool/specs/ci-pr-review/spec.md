## ADDED Requirements

### Requirement: PluginQA workflow triggers on plugin directory changes in PRs
The `PluginQA.yml` GitHub Actions workflow SHALL trigger on `pull_request` events when
files matching `**/*/CMakeLists.txt`, `**/*.h`, or `**/*.cpp` are changed within
directories that contain a Thunder plugin (detected by presence of `Module.h`).

#### Scenario: PR touching a plugin directory triggers the workflow
- **WHEN** a PR modifies `MyPlugin/MyPlugin.cpp`
- **WHEN** `MyPlugin/Module.h` exists in the repository
- **THEN** the `PluginQA` workflow runs for that PR

#### Scenario: PR touching only documentation does not trigger the workflow
- **WHEN** a PR modifies only `.md` files
- **THEN** the `PluginQA` workflow does not run

---

### Requirement: Workflow posts a structured review comment on the PR
The workflow SHALL post (or update) a single PR comment containing all findings from the
offline rule engine pass, grouped by plugin directory and severity. The comment SHALL
include a summary line (e.g. "3 errors, 2 warnings across 1 plugin").

#### Scenario: Review comment posted on first run
- **WHEN** the `PluginQA` workflow completes on a PR for the first time
- **THEN** a new comment is posted by the workflow bot with the structured findings

#### Scenario: Review comment updated on re-run
- **WHEN** the `PluginQA` workflow runs again on the same PR (e.g. after a push)
- **THEN** the existing `PluginQA` comment is updated (not duplicated)

#### Scenario: Zero-findings comment confirms clean review
- **WHEN** the workflow finds no errors or warnings
- **THEN** the PR comment states "No Thunder architecture violations found ✅"

---

### Requirement: Workflow uses LLM pass via GitHub Models API when available
After the offline pass, the workflow SHALL perform an LLM-backed review using the
`GH_TOKEN` secret (already available in GitHub Actions) via the GitHub Models API. LLM
findings SHALL be appended to the PR comment in a collapsible section.

#### Scenario: LLM findings appear in PR comment
- **WHEN** the GitHub Models API returns a valid response
- **THEN** the PR comment includes a collapsible section titled "AI-enhanced findings" with the LLM output

#### Scenario: LLM API unavailable does not fail the workflow
- **WHEN** the GitHub Models API is rate-limited or unavailable
- **THEN** the workflow completes successfully with only the offline findings in the PR comment
- **THEN** the workflow exits with status `success` (not `failure`)

---

### Requirement: Workflow does not fail the PR for warnings-only findings
The `PluginQA` workflow SHALL exit with a non-zero status code (failing the PR check)
only when there are one or more `error`-severity findings. Warning and suggestion findings
SHALL result in a `success` exit status.

#### Scenario: Error finding fails the PR check
- **WHEN** the rule engine finds at least one `error`-severity finding
- **THEN** the `PluginQA` workflow step exits with a non-zero status
- **THEN** the PR check appears as failed in the GitHub UI

#### Scenario: Warning-only findings pass the PR check
- **WHEN** the rule engine finds warnings but no errors
- **THEN** the `PluginQA` workflow exits with status 0
- **THEN** the PR check appears as passed in the GitHub UI

---

### Requirement: CI matrix covers both Ubuntu and macOS runners
The workflow SHALL run the rule engine on both `ubuntu-latest` and `macos-latest` runner
images to catch any platform-specific path or parsing differences.

#### Scenario: Both runners complete without errors
- **WHEN** the `PluginQA` workflow triggers on a PR
- **THEN** both the ubuntu-latest and macos-latest jobs complete
- **THEN** findings from both runners are identical (no platform-specific false positives)
