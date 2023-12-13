#include "main.h"
/**
 * _get_paths - function
 * @environ: environment
 * Return: value
 */
char **_get_paths(char **environ)
{
	int i = 0;
	char *path = NULL;
	char **paths = NULL;

	for (; environ[i] != NULL; i++)
	{

		if (_strncmp(environ[i], "PATH=", 5) == 0)
		{
			path = _strdup(environ[i] + 5);
			paths = _tokenizer(path, ":");
			free(path);
			break;
		}
	}

	return (paths);
}