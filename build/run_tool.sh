#!/bin/sh
set -e
SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd)"
cmake --build "$SCRIPT_DIR" --target TerminalTextRendering_Test
"$SCRIPT_DIR/TerminalTextRendering_Test" "$@"
