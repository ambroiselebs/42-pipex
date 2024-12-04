#!/bin/bash

# Vérifie que le nombre d'arguments est correct
if [ "$#" -ne 4 ]; then
    echo "Usage: $0 infile cmd1 cmd2 outfile"
    exit 1
fi

# Affectation des arguments
infile="$1"
cmd1="$2"
cmd2="$3"
outfile="$4"

# Exécute Valgrind avec les options appropriées
valgrind \
    --trace-children=yes \
    --track-fds=yes \
    --track-origins=yes \
    --keep-debuginfo=yes \
    --leak-check=full \
    --show-leak-kinds=all \
    ./pipex "$infile" "$cmd1" "$cmd2" "$outfile"
