#include "main.h"
/**
 * _get_paths - function
 * @environ: environment
 * @path_count: count of path
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
/**
 * _search_path - function
 * @paths: input
 * @tokens: input
 * Return: always 1
 */
int _search_path(char **paths, char **tokens)
{
	int i = 0, command_length = 0, directory_length = 0;
	char *full_cmd = NULL;

	if (access(tokens[0], F_OK & R_OK) == 0)
	{
		return (0);
	}
	else
	{

		command_length = _strlen(tokens[0]);

		for (i = 0; paths[i] != NULL; i++)
		{

			directory_length = _strlen(paths[i]);

			full_cmd = malloc(command_length + directory_length + 2);

			if (full_cmd == NULL)
				return (1);
			_strcpy(full_cmd, paths[i]);
			_strcat(full_cmd, "/");
			_strcat(full_cmd, tokens[0]);
			_strcat(full_cmd, "\0");

			if (access(full_cmd, F_OK & R_OK) == 0)
			{
				free(tokens[0]);
				tokens[0] = full_cmd;
				return (0);
			}
			else
			{
			}
			free(full_cmd);
			full_cmd = NULL;
		}
	}
	return (127);
}
