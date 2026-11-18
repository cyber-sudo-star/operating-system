#!/bin/bash
# Experiment 6(c): Delete all lines containing a specified word in one or more files

if [ $# -lt 1 ]; then
    echo "Usage: $0 <file1> [file2 ...]"
    exit 1
fi

read -p "Enter word to delete: " word

for file in "$@"; do
    if [ -f "$file" ]; then
        sed -i "/$word/d" "$file"
        echo "Processed '$file': lines containing '$word' deleted."
    else
        echo "Warning: File '$file' does not exist."
    fi
done

echo "Operation completed."
