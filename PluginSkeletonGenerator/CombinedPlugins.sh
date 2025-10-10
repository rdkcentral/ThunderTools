#!/usr/bin/env bash
set -Eeuo pipefail

if [ $# -lt 3 ]; then
  echo "Usage: $0 COUNT /path/to/ThunderInterfaces/interfaces/IMath.h /path/where/to/create/CombinedPlugins"
  exit 1
fi

COUNT="$1"
IFACE="$2"
TARGET_ROOT="$3"

# Capture the launch directory
START_DIR="$(pwd)"

# Validate COUNT is a positive integer
if ! [[ "$COUNT" =~ ^[1-9][0-9]*$ ]]; then
  echo "COUNT must be a positive integer"
  exit 1
fi

if ! command -v python3 >/dev/null 2>&1; then
  echo "python3 not found in PATH"
  exit 1
fi

# Ensure the generator exists in the launch directory
if [ ! -f "$START_DIR/PluginSkeletonGenerator.py" ]; then
  echo "PluginSkeletonGenerator.py not found in launch directory: $START_DIR"
  exit 1
fi

# Resolve absolute paths so they work after cd
if command -v realpath >/dev/null 2>&1; then
  IFACE_ABS="$(realpath "$IFACE")"
  TARGET_ROOT_ABS="$(realpath "$TARGET_ROOT")"
else
  IFACE_ABS="$IFACE"
  TARGET_ROOT_ABS="$TARGET_ROOT"
fi

if [ ! -e "$IFACE_ABS" ]; then
  echo "Interface path not found: $IFACE_ABS"
  exit 1
fi

# Create CombinedPlugins under the specified base path
TARGET_DIR="$TARGET_ROOT_ABS/CombinedPlugins"
mkdir -p "$TARGET_DIR"

# Work inside CombinedPlugins in a subshell so the parent shell CWD is unchanged
(
  cd "$TARGET_DIR"

  # Loop Plugin1..PluginN and run the generator with the new answers
  for i in $(seq 1 "$COUNT"); do
    plugin="Plugin$i"

    # New answers per run:
    # 1) $plugin
    # 2) N
    # 3) N
    # 4) $IFACE_ABS
    # 5) <Enter>
    # 6) N
    # 7) <Enter>
    printf '%s\nN\nN\n%s\n\nN\n\n' "$plugin" "$IFACE_ABS" | python3 "$START_DIR/PluginSkeletonGenerator.py"
  done

  # Create CMakeList.txt with one add_subdirectory line per plugin
  {
    for i in $(seq 1 "$COUNT"); do
      printf 'add_subdirectory(%s)\n' "Plugin$i"
    done
  } > CMakeList.txt
)

