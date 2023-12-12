#include <stddef.h>
#include "main.h"
char **_getpath(char **environ)
{

	char **paths = NULL;
	char *path = NULL;
	int tokenCount;
	int env;

	env = 0;

	while (environ[env] != NULL)
	{
		if (_strcmp(environ[env], "PATH=") == 0)
		{
			path = malloc(sizeof(char) * (_strlen(environ[env] + 5) + 1));
			_strcpy(path, environ[env] + 5);

			paths = tokenize(path, ":", &tokenCount);

			free(path);

			break;
		}
		env++;
	}
	return (paths);
}
