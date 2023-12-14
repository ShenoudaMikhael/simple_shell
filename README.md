
# 0x16. C - Simple Shell

Simple Shell is a Unix shell program written in C by Stephen Brennan. It is a minimalistic implementation of a Unix shell that provides basic functionality.

The shell is a computer program that provides a command-line interface for users to interact with the operating system. It allows users to execute commands, manage files, and automate tasks.

Simple shells are often used by developers and system administrators for scripting tasks. They can also be used by users who want a more powerful and flexible way to interact with their operating system.

## ./hsh

```c
#include "main.h"

int main(int argc, char *argv[])
{
(void)argc;
}
```

## Used Functions
- isatty: tests whether fd is an open file descriptor referring to a terminal.
- getline: read a line of text from a file, but when stdin is specified, standard input is read.
- write: write nbyte bytes from the buffer pointed to by buf to the file associated with the open file         descriptor, fildes.
- strtok: breaks string str into a series of tokens using the delimiter delim.
- execve: replaces the current process image with a new process image specified by path.
- exit: the function that forcefully terminates the current program and transfers the control to the operating system to exit the program.
- access: the function that forcefully terminates the current program and transfers the control to the operating system to exit the program.
- free: the function that forcefully terminates the current program and transfers the control to the operating system to exit the program.
- malloc: allocates memory and leaves the memory uninitialized.


## Implemented Commands


- Built-in Command Check : ```The shell directly executes the code then returns to the command prompt.```
- Executable File Search : ```It searches for the executable file for the command in the directories listed in the PATH environment variable and when file is found, the shell executes the command in a child process, replace the child process's memory image with the executable file, child process executes the external command then exits. The shell waits for the child process to exit then returns to the command prompt.```

## Authors

- [@Shenouda Mikhael](https://github.com/shenoudaMikhael)
- [@Salsabil Ahamed](https://github.com/salsapil)
