#include "main.h"
#include <signal.h>

void _interactive(char *argv)
{
	int search_result = -1, tokenCount = 0;
	int pathCount = 0, status = 0, getline_result = 0;
	char *string = NULL, *env = NULL;
	size_t size = 0;
	char **tokens = NULL, **paths = NULL;
	char ***holder = malloc(sizeof(char) * 1024);
	int holderCount = 0;

	signal(SIGINT, _handleCtrlC);
	while (1)
	{
		write(1, "($) ", 4);
		getline_result = getline(&string, &size, stdin);
		if (_strlen(string) == 1)
		{
			if (string != NULL)
				free(string), string = NULL;
			continue;
		}
		if (getline_result == -1)
		{
			for (search_result = 0; search_result < holderCount + 1; search_result++)
				_free_memory(holder[search_result]);
			free(holder), free(string), exit(EXIT_FAILURE);
		}
		if (string[_strlen(string) - 1] == '\n')
			string[_strlen(string) - 1] = '\0';
		tokens = tokenize(string, " ", &tokenCount);
		_handle_exit(tokens, status, tokenCount, string);
		env = _handle_environ();
		paths = tokenize(env, ":", &pathCount);
		search_result = _search_path(paths, tokens);
		if (search_result == 0)
			child(tokens);
		else
			perror(strcat(argv, "1"));
		holder[holderCount] = paths, holderCount++;
		holder[holderCount] = tokens, holderCount++;
	}
}
