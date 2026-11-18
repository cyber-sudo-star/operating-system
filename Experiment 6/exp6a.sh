#!/bin/bash
# Experiment 6(a): Determine login / working duration of a specified user

read -p "Enter username: " user
login_time=$(who | awk -v u="$user" '$1 == u {print $3, $4; exit}')

if [ -z "$login_time" ]; then
    echo "user is not currently logged in."
else
    echo "Login time: $login_time"
fi
