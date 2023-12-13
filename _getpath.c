#include "main.h"
/**
 * _getpath - function
 * @environ: input
 * Return: value
*/
char **_getpath()
{
	char **paths = NULL;
	char *path = NULL;
	int env;

	env = 0;

	while (environ[env] != NULL)
	{
		if (_strcmp(environ[env], "PATH=") == 0)
		{
			path = malloc(sizeof(char) * (_strlen(environ[env] + 5) + 1));
			_strcpy(path, environ[env] + 5);

			paths = _tokenizer(path, ":");

			free(path);

			break;
		}
		env++;
	}
	return (paths);
}
