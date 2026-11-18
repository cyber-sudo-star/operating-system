#!/bin/bash
# Experiment 7: String Operations in Shell Script
# - Calculates length of string
# - Extracts substring using shell expansion

echo "Enter a String:"
read str

echo "Length of String: ${#str}"

echo "Enter String Position:"
read start

echo "Enter Number of characters:"
read length

echo -n "Substring: "
echo "${str:$start:$length}"
