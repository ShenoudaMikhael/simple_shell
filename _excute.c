#include "main.h"
/**
 * _excute - excute command on child and wait for process
 * @command: ptr command
 * @argv: shell name
 * @status: int to set status code
 * Return: int status
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
		if (WEXITSTATUS(*status) != 0)
			*status = WEXITSTATUS(*status);
	}
	return (*status);
}
