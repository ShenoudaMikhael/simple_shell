#include "main.h"
/**
 * child - function
 * @tokens: input
 * Return: always 0
 */
int child(char **tokens, char **environ)
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
