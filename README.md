
# 0x16. C - Simple Shell

Simple Shell is a Unix shell program written in C by Stephen Brennan. It is a minimalistic implementation of a Unix shell that provides basic functionality.

The shell is a computer program that provides a command-line interface for users to interact with the operating system. It allows users to execute commands, manage files, and automate tasks.

## Usage/Examples

```c
#include "main.h"

int main(int argc, char *argv[])
{

}
```


## Implemented Commands


- Built-in Command Check : ```The shell directly executes the code then returns to the command prompt.```
- Executable File Search : ```It searches for the executable file for the command in the directories listed in the PATH environment variable and when file is found, the shell executes the command in a child process, replace the child process's memory image with the executable file, child process executes the external command then exits. The shell waits for the child process to exit then returns to the command prompt.```

## Authors

- [@Shenouda Mikhael](https://github.com/shenoudaMikhael)
- [@Salsabil Ahamed](https://github.com/salsapil)
