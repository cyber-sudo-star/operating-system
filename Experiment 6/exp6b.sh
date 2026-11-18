#!/bin/bash
# Experiment 6(b): Display lines between start and end line numbers

read -p "Enter filename: " file
read -p "Enter starting line number: " start
read -p "Enter ending line: " end

if [ ! -f "$file" ]; then
    echo "Error: File '$file' not found."
    exit 1
fi

sed -n "${start},${end}p" "$file"
