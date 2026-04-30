## 1. Repository and Project Scaffold

- [ ] 1.1 Create `ThunderTools/PluginQA/` directory with `README.md`, `requirements.txt` (`PyYAML` only — no `mcp` in core), and `__init__.py`
- [ ] 1.2 Create `ThunderTools/PluginQA/tests/` directory with `__init__.py` and empty `corpus/` subdirectory
- [ ] 1.3 Create `ThunderTools/PluginQA/rules/` directory tree: `rules/mem/`, `rules/iface/`, `rules/plugin/`, `rules/imap/`, `rules/config/`, `rules/oop/`
- [ ] 1.4 Create `ThunderTools/PluginQA/rule_engine/` package with `__init__.py`, `finding.py` (`Finding` dataclass, `Severity` enum, JSON serialisation), and `custom/` subdirectory
- [ ] 1.5 Add `ThunderTools/PluginQA/` entry to `ThunderDevTools.py` script menu as option 2 (alongside PSG option 1)

## 2. Rule Engine — Core Infrastructure

- [ ] 2.1 Implement `rule_engine/parser.py`: lightweight structural C++ parser using `re` — extracts class declarations, method signatures, `Initialize`/`Deinitialize` bodies, constructor/destructor bodies, `#include` order, interface maps, and `QueryInterface` call sites into a `ParsedFile` dataclass. No full AST required.
- [ ] 2.2 Implement `rule_engine/loader.py`: scans `rules/` directory tree, loads and validates all YAML rule files at startup, raises actionable errors for missing required fields; validates that `type: ai_query` rules have both `extract` and `query` fields
- [ ] 2.3 Implement `rule_engine/prompt_builder.py`: accepts a `ParsedFile`, a rule's `extract` list, and a `query` string; extracts the named structural regions from `ParsedFile`; calls GitHub Models API (`openai/gpt-4.1`) with the extracted context + query; parses yes/no/cannot-determine response; returns a `Finding` or `None`
- [ ] 2.4 Implement `rule_engine/interpreter.py`: executes `type: pattern` rules only (regex per line, scoped to `cpp`/`h`/`any`); no `type: custom` dispatch
- [ ] 2.5 Implement `rule_engine/engine.py`: `RuleEngine` class that loads rules via `loader.py`, parses files via `parser.py`, runs offline pass via `interpreter.py`, then runs AI query pass via `prompt_builder.py` (gated on `GH_TOKEN`), and returns a merged list of `Finding` instances
- [ ] 2.6 Implement `review_plugin.py` as standalone CLI entry point: accepts file paths as CLI args, runs `RuleEngine`, prints findings as line-delimited JSON to stdout, exits `1` on any `error` finding, `0` otherwise

## 3. Rule Definitions — Pattern and Context-Pair Rules (YAML)

- [ ] 3.1 Write `rules/plugin/throw-present.yaml` (`type: pattern`, regex `\b(throw|try|catch)\b`, scope `any`)
- [ ] 3.2 Write `rules/plugin/hardcoded-path.yaml` (`type: pattern`, detects string literals starting with `/` not preceded by `%`)
- [ ] 3.3 Write `rules/plugin/module-h-not-first.yaml` (`type: context_pair`, `Module.h` not the first `#include` in a `.cpp`)
- [ ] 3.4 Write `rules/iface/missing-external.yaml` (`type: pattern`, `struct`/`class` inheriting `IUnknown` without `EXTERNAL`)
- [ ] 3.5 Write `rules/iface/non-hresult-method.yaml` (`type: pattern`, virtual method return type not `Core::hresult`)
- [ ] 3.6 Write `rules/iface/non-virtual-iunknown.yaml` (`type: pattern`, interface without `virtual public Core::IUnknown`)
- [ ] 3.7 Write `rules/iface/stl-across-boundary.yaml` (`type: pattern`, STL container types in virtual method signatures)
- [ ] 3.8 Write `rules/mem/direct-delete-com.yaml` (`type: pattern`, `delete` applied to a COM interface pointer)
- [ ] 3.9 Write `rules/config/raw-json-parse.yaml` (`type: pattern`, `std::string::find`/`sscanf` used for JSON instead of `Core::JSON::Container`)

## 4. Rule Definitions — AI Query Rules (YAML with `type: ai_query`)

- [ ] 4.1 Write `rules/mem/ishell-no-addref.yaml` (`type: ai_query`, `extract: [initialize_body]`, query asks whether stored `IShell*` member has `AddRef()` called in `Initialize()`)
- [ ] 4.2 Write `rules/mem/ishell-no-release.yaml` (`type: ai_query`, `extract: [deinitialize_body]`, query asks whether stored `IShell*` member has `Release()` called in `Deinitialize()`)
- [ ] 4.3 Write `rules/mem/qi-no-release.yaml` (`type: ai_query`, `extract: [method_bodies]`, query asks whether any `QueryInterface`/`QueryInterfaceByCallsign` result is assigned without a subsequent `Release()`)
- [ ] 4.4 Write `rules/plugin/register-leak.yaml` (`type: ai_query`, `extract: [initialize_body, deinitialize_body]`, query asks whether every `Register()`/`Subscribe()` call in `Initialize()` has a matching `Unregister()`/`Unsubscribe()` in `Deinitialize()`)
- [ ] 4.5 Write `rules/plugin/missing-unavailable.yaml` (`type: ai_query`, `extract: [class_declarations]`, query asks whether any inner class inheriting `IPlugin::INotification` is missing an `Unavailable()` override)
- [ ] 4.6 Write `rules/plugin/init-logic-in-ctor.yaml` (`type: ai_query`, `extract: [ctor_body, dtor_body]`, query asks whether the constructor or destructor contains non-trivial logic beyond member initialisation)
- [ ] 4.7 Write `rules/imap/incomplete.yaml` (`type: ai_query`, `extract: [interface_map, class_declarations]`, query asks whether `BEGIN_INTERFACE_MAP` is missing any entry for an inherited interface)
- [ ] 4.8 Write `rules/oop/missing-terminate.yaml` (`type: ai_query`, `extract: [deinitialize_body]`, query asks whether `Deinitialize()` acquires a `RemoteConnection` without calling `Terminate()`)

## 5. Rule Engine — Test Corpus

- [ ] 5.1 Create `tests/corpus/<ruleId>-bad.cpp` and `tests/corpus/<ruleId>-good.cpp` snippet files for all 17 rules (tasks 3.1–3.9 and 4.1–4.7)
- [ ] 5.2 Write `tests/test_corpus.py`: pytest parametrised test that runs each bad snippet through the engine and asserts the expected `ruleId` appears, and each good snippet produces no finding for that rule
- [ ] 5.3 Add `tests/test_yaml_schema.py`: pytest test that loads every YAML file in `rules/` and validates required fields are present
- [ ] 5.4 Verify `pytest ThunderTools/PluginQA/tests/` passes locally and in CI

## 6. AI Query Mechanism

- [ ] 6.1 Implement GitHub Models API client inside `rule_engine/prompt_builder.py`: uses `openai/gpt-4.1` model (matching PSG workflow), authenticates via `GH_TOKEN`, sends extracted code block + bounded query, returns structured yes/no/cannot-determine result
- [ ] 6.2 Implement per-rule failure isolation in `prompt_builder.py`: if the API call for one rule fails (non-200, timeout), that rule produces a `system/ai-unavailable` meta-finding and the engine continues with remaining rules
- [ ] 6.3 Add retry with exponential back-off (max 3 attempts) per AI query call; gate entire AI query pass on `GH_TOKEN` presence; when absent, append single `system/ai-skipped` meta-finding instead of per-rule meta-findings
- [ ] 6.4 Write `tests/test_ai_queries.py`: tests using mocked GitHub Models API responses — assert yes response → finding produced, no response → no finding, cannot-determine → suggestion finding, API error → meta-finding produced + offline results intact

## 7. Phase 1 — Agent-Surfaced Results (VS Code Prompt Files)

- [ ] 7.1 Write `ThunderTools/PluginQA/prompts/thunder-review.prompt.md`: open-file or explicit-paths → instructs agent to run `review_plugin.py` via terminal tool → grouped severity output
- [ ] 7.2 Write `ThunderTools/PluginQA/prompts/thunder-generate.prompt.md`: Q&A flow → YAML construction → instructs agent to run PSG via terminal → then run `review_plugin.py` on generated output
- [ ] 7.3 Write `ThunderTools/PluginQA/prompts/thunder-pattern.prompt.md`: description → agent reasons using Thunder instruction files → returns canonical pattern + code block
- [ ] 7.4 Write `ThunderTools/PluginQA/prompts/thunder-interface.prompt.md`: open-header or explicit path → instructs agent to run `review_plugin.py` with `--iface-only` flag → compliance summary
- [ ] 7.5 Manually verify each prompt file appears as a slash command in VS Code Copilot Chat Agent mode and produces correct output

## 8. Phase 2 — GitHub Actions PR Integration

> Implement this section after Phase 1 (Section 7) prompt files are validated in the developer workflow.

- [ ] 8.1 Write `.github/workflows/PluginQA.yml`: trigger on `pull_request` for `**/*.h`, `**/*.cpp`, `**/CMakeLists.txt`; detect changed plugin directories by checking for `Module.h`
- [ ] 8.2 Add job: install Python deps, run rule engine offline pass on all changed plugin files, serialize findings to JSON artefact
- [ ] 8.3 Add job step: LLM pass using `GH_TOKEN`; append findings to JSON; handle rate-limit gracefully
- [ ] 8.4 Add job step: render PR comment with severity-grouped findings using `peter-evans/create-or-update-comment@v5` (matching PSG workflow pattern); collapsible AI section for LLM findings
- [ ] 8.5 Exit workflow with non-zero status if any `error`-severity findings present; exit 0 for warnings-only
- [ ] 8.6 Add CI matrix: `ubuntu-latest` and `macos-latest` runners; verify findings are identical across platforms
- [ ] 8.7 Run the workflow against `rdkservices/DeviceInfo` and `rdkservices/UserSettings` as integration smoke test; document known findings in `ThunderTools/PluginQA/README.md`

## 9. Documentation and Packaging

- [ ] 9.1 Write `ThunderTools/PluginQA/README.md`: terminal usage, prompt file installation, CI integration, environment variables (`THUNDER_REPO_PATH`), how to add/modify YAML rules
- [ ] 9.2 Add `ThunderTools/PluginQA/` to the `ThunderTools` top-level `README.md` under Developer Tools
- [ ] 9.3 Update `ThunderTools/ThunderDevTools/ThunderDevTools.py` to include `thunder-plugin-qa` as a runnable tool option

## 10. MCP Server (Optional Enhancement — implement after sections 1–9 are complete)

- [ ] 10.1 Create `requirements-mcp.txt` (`mcp` SDK only); keep core `requirements.txt` unchanged
- [ ] 10.2 Implement `mcp_server.py`: initialise `mcp` SDK server with `name="thunder-plugin-qa"`, register tools: `review_plugin`, `generate_skeleton`, `validate_interface`, `suggest_pattern`, `explain_rule`
- [ ] 10.3 Implement `review_plugin` tool handler: delegate to `RuleEngine` + optional LLM pass; return serialised `Finding` list
- [ ] 10.4 Implement `generate_skeleton` tool handler: validate YAML config against PSG schema, invoke `PluginSkeletonGenerator.py` subprocess, return file tree or structured error
- [ ] 10.5 Implement `validate_interface` tool handler: run `RuleEngine` with `iface/*` rules only
- [ ] 10.6 Implement `suggest_pattern` and `explain_rule` tool handlers: look up patterns and rule descriptions from the rules registry and instruction files
- [ ] 10.7 Write `ThunderTools/PluginQA/mcp.json` sample VS Code MCP config with `THUNDER_TOOLS_PATH` env var
- [ ] 10.8 Write `tests/test_server.py`: integration tests for all MCP tools using the `mcp` SDK test client
- [ ] 10.9 Update prompt files (7.1–7.4) to call MCP tools directly instead of invoking scripts via the agent terminal tool
