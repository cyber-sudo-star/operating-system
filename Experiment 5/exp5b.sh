#!/bin/bash
# Experiment 5(b): Convert file name to uppercase

if [ -f "$1" ]; then
    new_name=$(echo "$1" | tr '[:lower:]' '[:upper:]')
    mv "$1" "$new_name"
    echo "File Name changed to Upper Case: $new_name"
else
    echo "$1 does not exist"
fi
