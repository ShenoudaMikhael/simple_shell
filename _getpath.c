#include <stddef.h>
#include "main.h"
char **_getpath(char **environ)
{

	char **paths = NULL;
	int env, q;

	env = 0;

	while (environ[env])
	{
		if (_strcmp(environ[env], "PATH=") == 0)
		{
			paths = _strtok(environ[env] + 5, ':');
			q = 0;
			while (paths[q])
			{
				q++;
			}

			break;
		}
		env++;
	}
	return (paths);
}
