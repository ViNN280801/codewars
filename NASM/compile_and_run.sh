#!/usr/bin/env bash
# Usage: ./compile_and_run.sh <file.asm> <tests.cpp>

set -e

ASM_FILE="$1"
CPP_FILE="$2"

if [[ -z "$ASM_FILE" || -z "$CPP_FILE" ]]; then
    echo "Usage: $0 <file.asm> <tests.cpp>"
    exit 1
fi

if [[ ! -f "$ASM_FILE" ]]; then
    echo "Error: ASM file '$ASM_FILE' not found"
    exit 1
fi

if [[ ! -f "$CPP_FILE" ]]; then
    echo "Error: CPP file '$CPP_FILE' not found"
    exit 1
fi

OBJ_ASM="${ASM_FILE%.asm}.o"
OBJ_OUT="./test_runner"

echo "==> Assembling $ASM_FILE..."
nasm -f elf64 "$ASM_FILE" -o "$OBJ_ASM"

echo "==> Compiling and linking $CPP_FILE..."
clang++ -std=c++20 -O0 -g -fPIE -Wall -Wpedantic -Wextra -Wshadow -Wnarrowing -fsanitize=address,undefined,leak \
        "$CPP_FILE" "$OBJ_ASM" \
         -lgtest -lgtest_main -lpthread \
         -o "$OBJ_OUT"

echo "==> Running tests..."
"$OBJ_OUT"

trap 'echo "==> Cleaning up..."; rm -f "$OBJ_ASM" "$OBJ_OUT"' EXIT
