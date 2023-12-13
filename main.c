#include "main.h"
#include <signal.h>

/**
 * _get_line
 */
char *_read_line()
{

	char *string = NULL;
	size_t len;
	ssize_t n;

	if (isatty(STDIN_FILENO))
		write(1, "($) ", 4);
	n = getline(&string, &len, stdin);
	if (n == -1)
	{
		if (string != NULL)
			free(string);
		return (NULL);
	}
	return (string);
}

/**
 * main - simple shell main entry
 * @argc: num of args
 * @argv: args
 * Return: int
 */
int main(int argc, char *argv[])
{
	int status = 0, tokenCount = 0, i = 0;
	char *string = NULL, **command;
	(void)argc;
	(void)argv;
	while (1)
	{
		string = _read_line();
		if (string == NULL)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			return (status);
		}
		command = _tokenize(string, " \t\n", &tokenCount);
		if (!tokenCount)
			continue;
		printf("start path search %i  %i\n", tokenCount, i);

		printf("End Path search\n");
		status = _excute(command,argv[0]);
		_freeTokens(command, tokenCount);
		free(string);
	}
	return (status);
}
