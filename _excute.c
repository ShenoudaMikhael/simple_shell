#include "main.h"

int _excute(char **command, char *argv, int *status)
{
    pid_t pid;

    pid = fork();
    if (pid == 0) /* if child process, execute */
    {

        if (execve(command[0], command, environ) == -1)
        {

            perror(argv);
        }
    }
    else /* if parent, wait for child then free all */
    {
        waitpid(pid, status, 0);
    }
    return (*status);
}