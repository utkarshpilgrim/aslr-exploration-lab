#!/bin/bash

# Usage: ./diff-script.sh log1.log log2.log

LOG1=$1
LOG2=$2

if [ -z "$LOG1" ] || [ -z "$LOG2" ]; then
    echo "Usage: $0 log1.log log2.log"
    exit 1
fi

echo "Diffing key addresses (e.g., stack, heap, libc):"
diff <(grep -E 'stack|heap|libc' $LOG1) <(grep -E 'stack|heap|libc' $LOG2)