#include "main.h"

int child(char **tokens)
{

	pid_t pid;
	int status, ex_result;

	pid = fork();
	if (pid == -1)
	{
		perror("AA");
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
	{

		ex_result = execve(tokens[0], tokens, environ);
		if (ex_result == -1)
		{
			perror("AA");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		waitpid(pid, &status, 0);
		printf("HERE");
		if (WIFEXITED(status))
		{
		}
		else if (WIFSIGNALED(status))
		{
		}
		else
		{
		}
	}

	return (0);
}
