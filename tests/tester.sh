#!/bin/bash

OUTWIDTH=24
COMPILER=./bin/dcc

valid="./tests/valid/*.c"
invalid="./tests/invalid/*.c"

passed=0
total=0

# Passes if exit code of compilation is zero
for file in $valid; do
    printf "Testing %-*s" "$OUTWIDTH" "$(basename $file)"
    $COMPILER $file -o /dev/null 2>/dev/null
    if [[ $? ]]; then echo -e "\x1b[32mPASSED\x1b[0m"; passed=$(( $passed + 1 ))
    else              echo -e "\x1b[31mFAILED\x1b[0m"
    fi
    total=$(( $total + 1 ))
done

# Same as valid, except it passes when exit code is NOT zero
for file in $invalid; do
    printf "Testing %-*s" "$OUTWIDTH" "$(basename $file)"
    $COMPILER $file -o /dev/null 2>/dev/null
    if [[ $? ]]; then echo -e "\x1b[31mFAILED\x1b[0m"
    else              echo -e "\x1b[32mPASSED\x1b[0m"; passed=$(( $passed + 1 ))
    fi
    total=$(( $total + 1 ))
done

echo -e "\x1b[36mTests passed: $passed/$total.\x1b[0m"

