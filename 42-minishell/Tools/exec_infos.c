/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_infos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchamore <gchamore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 12:10:11 by anferre           #+#    #+#             */
/*   Updated: 2024/05/29 15:54:19 by gchamore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// redirections : 

// -if << the word that follows is subject to quote removal
// -if others need to expand $var, remove quotes

// -expand * only if it result in a single word

// -failure to open or create a file should cause the redirection to fail

// input : 
// -If the file does not exist, the command will fail with an error.
// -If the file exists but is not readable (due to file permissions), the command will fail with an error.
// -If the file is a directory, the command will fail with an error.

// output :
// -If the file does not exist, it is created.
// -If the file exists, > will overwrite it and >> will append to it.
// -If the file exists but is not writable (due to file permissions), the command will fail with an error.
// -If the file is a directory, the command will fail with an error.


// command execution :

// -If no command name results, variable assignments shall affect the current execution environment.
// var="Hello, World!"
// echo $var

// -If there is no command name, any redirections shall be performed in a subshell environment.
// > newfile.txt

// -If any of the redirections performed in the current shell execution environment fail, the command shall immediately fail with an exit status greater than zero
// > /root/forbidden.txt

// -If there is a command name, execution shall continue as described in Command Search and Execution.
// echo "Hello, World!"

// command search and execution :

// -If the command name does not contain any slashes, the first successful step in the following sequence shall occur:
// *check for built-in commands
// *search in the path
// 	if built-in command is found, execution in the same process 
// 		echo "Hello, World!"
// 	if not, fork and execute the command in the child process
// 		/bin/ls
// 	if not found exit status 127 and error message 
// ?need to handle If the file is not in an executable format, execve() fails with an ENOEXEC error.
// it tries to execute the file as a shell script, meaning reading from the file and trying to execute each line 


// - if you provide a path (either absolute or relative, If the command name contains at least one slash) to the command, the shell will try to execute the file at that path. The shell does this by creating a new process and using the execve() function to replace the new process with the command.

// pipelines :

// If this is not the first command, redirect its standard input to read from the read end of the previous pipe.
// If this is not the last command, redirect its standard output to write to the write end of the current pipe.
// If there's an input redirection (<), open the specified file and redirect standard input to read from this file.
// If there's an output redirection (>), open the specified file and redirect standard output to write to this file.
// Execute the command.

// return the exit status of the last command in the pipeline

// shel execution environment :

// open files -> 0 1 2 and other openned files

// working directory -> current working directory

// shell parameters ->  variables in the environment

