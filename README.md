0x16.C - Simple Shell
Description - This team project is part of the curriculum of ALX.

What you should learn from this project:
1. How to start coding your own shell
2. How to manipulate the environment of the current process
3. How to execute another program with the execve system call
4. How to suspend the execution of a process until one of its children terminates
5. How to create processes

Usage
All your files will be compiled on Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic -std=gnu89.
Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
All your header files should be include guarded

Tasks to be completed on this project
0 - Write a beautiful code that passes the Betty checks
1 - Write a UNIX command line interpreter.
2 - Simple shell 0.1 + and Handle command lines with arguments
3 - Simple shell 0.2 + and Handle the PATH and fork must not be called if the command doesn’t exist
4 - Simple shell 0.3 + and Implement the exit built-in, that exits the shell and You don’t have to handle any argument to the built-in exit
5 - Simple shell 0.4 + and Implement the env built-in, that prints the current environment
6 - Simple shell 0.1 + and Write your own getline function and use a buffer to read many chars at once and call the least possible the read system call
7 - Simple shell 0.2 + and You are not allowed to use strtok
8 - Simple shell 0.4 + and handle arguments for the built-in exit
9 - Simple shell 1.0 + and implement the setenv and unsetenv builtin commands
10 - Implement the builtin command cd: Changes the current directory of the process, f no argument is given to cd the command must be interpreted like cd $HOME, You have to update the environment variable PWD when you change directory, You have to handle the command cd -
11 - Handle the commands separator ;
12 - Handle the && and || shell logical operators
13 - implement the alias builtin command
14 - Handle variables replacement, Handle the $? variable, Handle the $$ variable
15 - Handle comments (#)
16 - Your shell can take a file as a command line argument, The file contains all the commands that your shell should run before exiting, n this mode, the shell should not print a prompt and should not read from stdin

