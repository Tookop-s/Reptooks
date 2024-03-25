import os

def compare_outputs():
    # Run the shell commands directly
    os.system('< pipex_testeur/infiles/basic.txt grep -A5 is | cat -e > Tools_pipex/noexist; echo $? > result1.txt')
    os.system('./pipex "pipex_testeur/infiles/basic.txt" "grep -A5 is" "cat -e" "Tools_pipex/notexist"; echo $? > result2.txt')

    # Read the return codes from files
    with open('result1.txt', 'r') as file:
        returncode1 = int(file.read().strip())

    with open('result2.txt', 'r') as file:
        returncode2 = int(file.read().strip())

    # Compare return codes
    if returncode1 != returncode2:
        print("Return codes do not match!")
        print("Command 1 return code:", returncode1)
        print("Command 2 return code:", returncode2)
    else:
        print("Test passed!")

# Compare the outputs
compare_outputs()