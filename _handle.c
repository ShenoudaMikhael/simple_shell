#include "main.h"
#include <signal.h>

void _handleCtrlC(int signum)
{
	if (signum == 2)
		exit(EXIT_SUCCESS);
}

void _handle_exit(char **tokens, int status, int tokenCount, char *string)
{
	if (tokens != NULL && _strcmp(tokens[0], "exit") == 0)
	{
		if (tokens[1] != NULL)
			status = _atoi(tokens[1]);
		free(string);
		freeTokens(tokens, tokenCount);

		exit(status);
	}
}

char *_handle_environ()
{
	char **env;

	for (env = environ; *env != NULL; env++)
	{

		if (_strncmp(*env, "PATH=", 5) == 0)
		{
			return (*env + 5);
		}
	}
	return (NULL);
}
