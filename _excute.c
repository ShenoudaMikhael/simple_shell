#include "main.h"
/**
 * 
*/
int _excute(char **command, char *argv, int *status)
{
	pid_t pid;

	pid = fork();
	if (pid == 0)
	{

		if (execve(command[0], command, environ) == -1)
		{

			perror(argv);
		}
	}
	else
	{
		waitpid(pid, status, 0);
	}
	return (*status);
}
