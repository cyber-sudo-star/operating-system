#!/bin/bash
# Experiment 5(a): Check if argument is a regular file or directory

if [ -f "$1" ]; then
    echo "$1 is a file"
elif [ -d "$1" ]; then
    echo "$1 is a directory"
else
    echo "$1 does not exist"
fi
