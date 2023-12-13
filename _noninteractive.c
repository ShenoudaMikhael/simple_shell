#include "main.h"
/**
 * _noninteractive - function
 * @argv: input
 * Return: void
 */
void _noninteractive(char **argv)
{
	int search_result = -1, tokenCount = 0;
	int pathCount = 0, status = 0, getline_result = 0;
	char *string = NULL;
	char *env = NULL;
	size_t size = 0;
	char **tokens = NULL, **paths = NULL;
	char ***holder = malloc(sizeof(char) * 1024);
	int holderCount = 0;

	getline_result = getline(&string, &size, stdin);

	if (_strlen(string) == 1)
		exit(0);
	if (getline_result == -1)
	{

		for (search_result = 0; search_result < holderCount + 1; search_result++)
			_free_memory(holder[search_result]);
		free(holder);
		free(string);

		exit(EXIT_FAILURE);
	}
	if (string[_strlen(string) - 1] == '\n')
		string[_strlen(string) - 1] = '\0';

	tokens = tokenize(string, " ", &tokenCount);
	_handle_exit(tokens, status, tokenCount, string);
	env = _handle_environ();
	paths = tokenize(env, ":", &pathCount);
	search_result = _search_path(paths, tokens);
	if (search_result == 0)
		child(tokens, argv);
	else
		perror(strcat(argv[0], "1"));
	holder[holderCount] = paths;
	holderCount++;
	holder[holderCount] = tokens;
	holderCount++;
}
