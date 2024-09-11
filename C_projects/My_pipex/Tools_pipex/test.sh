#!/bin/bash

# Number of pipes you want to create
num_pipes=5000

# Initialize the command
cmds=()

# Loop to create the command with multiple instances of "cmd"
i=1
while [ $i -le $num_pipes ]; do
    cmds+=(" cat -e ")
    i=$((i+1))
done

# Run the pipex function with the generated command
./pipex "Tools_pipex/test1.txt" "${cmds[@]}" "Tools_pipex/test2.txt"
