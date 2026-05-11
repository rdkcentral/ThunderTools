## 1. Repository and Project Scaffold

- [ ] 1.1 Create `ThunderTools/PluginQA/` directory with `README.md`, `requirements.txt` (`PyYAML` + `openai` SDK), and `__init__.py`
- [ ] 1.2 Create `ThunderTools/PluginQA/tests/` directory with `__init__.py` and `corpus/` subdirectory
- [ ] 1.3 Create `ThunderTools/PluginQA/rules/` directory tree: `rules/mem/`, `rules/iface/`, `rules/plugin/`, `rules/imap/`, `rules/config/`, `rules/oop/`
- [ ] 1.4 Create `ThunderTools/PluginQA/rule_engine/` package with `__init__.py` and `finding.py` (`Finding` dataclass, `Severity` enum, JSON serialisation)
- [ ] 1.5 Add `ThunderTools/PluginQA/` entry to `ThunderDevTools.py` script menu as option 2 (alongside PSG option 1)

## 2. Rule Engine — Core Infrastructure

- [ ] 2.1 Implement `rule_engine/loader.py`: scans `rules/` directory tree, loads and validates all YAML rule files at startup, raises actionable errors for missing required fields; returns a list of rule dicts filtered by `scope` for a given file type
- [ ] 2.2 Implement `rule_engine/prompt_builder.py`: accepts file content (string) + list of rule dicts; assembles the structured rule checklist prompt; calls GitHub Models API (`openai/gpt-4.1`, authenticated via `GH_TOKEN`); parses the JSON array response; returns a list of `Finding` instances
- [ ] 2.3 Implement `rule_engine/engine.py`: `RuleEngine` class that loads rules via `loader.py`, reads file content, handles token-limit guard (split by scope if needed), calls `prompt_builder.py`, and returns a list of `Finding` instances
- [ ] 2.4 Implement `review_plugin.py` as standalone CLI entry point: accepts file paths as CLI args; fails fast with actionable message if `GH_TOKEN` not set; runs `RuleEngine` per file; prints findings as line-delimited JSON to stdout; exits `1` on any `error` finding, `0` otherwise

## 3. Rule Definitions — YAML Checklist Files (17 rules)

Each file has fields: `id`, `severity`, `source`, `description`, `scope`. No `type`, `pattern`, `extract`, or `query` fields.

- [ ] 3.1 Write `rules/mem/ishell-no-addref.yaml`
- [ ] 3.2 Write `rules/mem/ishell-no-release.yaml`
- [ ] 3.3 Write `rules/mem/qi-no-release.yaml`
- [ ] 3.4 Write `rules/mem/direct-delete-com.yaml`
- [ ] 3.5 Write `rules/iface/missing-external.yaml`
- [ ] 3.6 Write `rules/iface/non-hresult-method.yaml`
- [ ] 3.7 Write `rules/iface/non-virtual-iunknown.yaml`
- [ ] 3.8 Write `rules/iface/stl-across-boundary.yaml`
- [ ] 3.9 Write `rules/plugin/throw-present.yaml`
- [ ] 3.10 Write `rules/plugin/register-leak.yaml`
- [ ] 3.11 Write `rules/plugin/missing-unavailable.yaml`
- [ ] 3.12 Write `rules/plugin/hardcoded-path.yaml`
- [ ] 3.13 Write `rules/plugin/module-h-not-first.yaml`
- [ ] 3.14 Write `rules/plugin/init-logic-in-ctor.yaml`
- [ ] 3.15 Write `rules/imap/incomplete.yaml`
- [ ] 3.16 Write `rules/config/raw-json-parse.yaml`
- [ ] 3.17 Write `rules/oop/missing-terminate.yaml`

## 4. Rule Engine — Test Corpus

- [ ] 5.1 Create `tests/corpus/<ruleId>-bad.cpp` and `tests/corpus/<ruleId>-good.cpp` snippet files for all 17 rules (tasks 3.1–3.9 and 4.1–4.7)
- [ ] 5.2 Write `tests/test_corpus.py`: pytest parametrised test that runs each bad snippet through the engine and asserts the expected `ruleId` appears, and each good snippet produces no finding for that rule
- [ ] 5.3 Add `tests/test_yaml_schema.py`: pytest test that loads every YAML file in `rules/` and validates required fields are present
- [ ] 5.4 Verify `pytest ThunderTools/PluginQA/tests/` passes locally and in CI

## 5. Single-Call API Mechanism

- [ ] 5.1 Implement prompt assembly in `rule_engine/prompt_builder.py`: loads rules filtered by scope, formats them as a numbered checklist (id, severity, description), instructs model to return a JSON array with fields `ruleId`, `severity`, `line`, `message`; empty array if clean
- [ ] 5.2 Implement token-limit guard in `prompt_builder.py`: estimate token count of file + prompt; if over limit, split into two calls (one per scope: `cpp` rules + `h` rules); merge results
- [ ] 5.3 Implement retry with exponential back-off (max 3 attempts) in `prompt_builder.py`; on final failure raise with enough context for a `system/ai-unavailable` meta-finding
- [ ] 5.4 Write `tests/test_prompt_builder.py`: unit tests using mocked API — assert correct prompt structure, correct JSON parsing, token-split behaviour, retry behaviour, `GH_TOKEN` absent fast-fail

## 6. VS Code Prompt Files

- [ ] 6.1 Write `ThunderTools/PluginQA/prompts/thunder-review.prompt.md`: instructs agent to invoke `review_plugin.py` via its terminal tool on the open plugin file (or explicit paths), then present findings grouped by severity and rule ID
- [ ] 6.2 Write `ThunderTools/PluginQA/prompts/thunder-generate.prompt.md`: Q&A flow → YAML construction → instructs agent to run PSG via terminal → then invoke `review_plugin.py` on the generated output and present findings
- [ ] 6.3 Write `ThunderTools/PluginQA/prompts/thunder-pattern.prompt.md`: description → agent reasons using Thunder instruction files → returns canonical pattern + code block
- [ ] 6.4 Write `ThunderTools/PluginQA/prompts/thunder-interface.prompt.md`: open-header or explicit path → instructs agent to invoke `review_plugin.py` with `--scope h` flag → interface compliance summary
- [ ] 6.5 Manually verify each prompt file appears as a slash command in VS Code Copilot Chat Agent mode and that the agent correctly invokes `review_plugin.py` and presents its output

## 7. GitHub Actions CI Workflow

- [ ] 7.1 Write `.github/workflows/PluginQA.yml`: trigger on `pull_request` for `**/*.h`, `**/*.cpp`, `**/CMakeLists.txt`; detect changed plugin directories by checking for `Module.h`
- [ ] 7.2 Add job: install Python deps (`PyYAML`, `openai`), run `review_plugin.py` on each changed plugin file (one API call per file), serialize findings to JSON artefact
- [ ] 7.3 Add job step: render PR comment with severity-grouped findings using `peter-evans/create-or-update-comment@v5` (matching PSG workflow pattern)
- [ ] 7.4 Exit workflow with non-zero status if any `error`-severity findings present; exit 0 for warnings-only
- [ ] 7.5 Add CI matrix: `ubuntu-latest` and `macos-latest` runners; verify findings are identical across platforms
- [ ] 7.6 Run the workflow against `rdkservices/DeviceInfo` and `rdkservices/UserSettings` as integration smoke test; document known findings in `ThunderTools/PluginQA/README.md`

## 8. Documentation and Packaging

- [ ] 8.1 Write `ThunderTools/PluginQA/README.md`: terminal usage (`python review_plugin.py <file>`), VS Code prompt file installation, CI integration, `GH_TOKEN` requirement, how to add/modify YAML rules
- [ ] 8.2 Add `ThunderTools/PluginQA/` to the `ThunderTools` top-level `README.md` under Developer Tools
- [ ] 8.3 Update `ThunderTools/ThunderDevTools/ThunderDevTools.py` to include `thunder-plugin-qa` as a runnable tool option

## 9. MCP Server (Optional Enhancement — implement after sections 1–8 are complete)

- [ ] 9.1 Create `requirements-mcp.txt` (`mcp` SDK only); keep core `requirements.txt` unchanged
- [ ] 9.2 Implement `mcp_server.py`: initialise `mcp` SDK server with `name="thunder-plugin-qa"`, register tools: `review_plugin`, `generate_skeleton`, `validate_interface`, `suggest_pattern`, `explain_rule`
- [ ] 9.3 Implement `review_plugin` tool handler: delegate to `RuleEngine`; return serialised `Finding` list
- [ ] 9.4 Implement `generate_skeleton` tool handler: validate YAML config against PSG schema, invoke `PluginSkeletonGenerator.py` subprocess, return file tree or structured error
- [ ] 9.5 Implement `validate_interface` tool handler: run `RuleEngine` with `iface/*` rules only
- [ ] 9.6 Implement `suggest_pattern` and `explain_rule` tool handlers: look up patterns and rule descriptions from the rules registry and instruction files
- [ ] 9.7 Write `ThunderTools/PluginQA/mcp.json` sample VS Code MCP config with `THUNDER_TOOLS_PATH` env var
- [ ] 9.8 Write `tests/test_server.py`: integration tests for all MCP tools using the `mcp` SDK test client
- [ ] 9.9 Update prompt files (6.1–6.4) to optionally call MCP tools directly instead of invoking scripts via the agent terminal tool
