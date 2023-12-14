#include "main.h"

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
	char *cm = _strdup(tokens[0]);

	

	if (access(cm, F_OK & R_OK) == 0)
	{
		free(full_cmd);
		tokens[0] = _strdup(cm);
		free(cm);
		cm = NULL;
		return (0);
	}
	else
	{
		command_length = _strlen(tokens[0]);
		for (i = 0; paths[i] != NULL; i++)
		{
			directory_length = _strlen(paths[i]);
			full_cmd = malloc(sizeof(char) * (command_length + directory_length + 2));
			if (full_cmd == NULL)
				return (1);
			_strcpy(full_cmd, paths[i]);
			_strcat(full_cmd, "/");
			_strcat(full_cmd, cm);
			_strcat(full_cmd, "\0");
			if (access(full_cmd, F_OK & R_OK) == 0)
			{
				tokens[0] = malloc(strlen(full_cmd) + 1 * sizeof(char));
				_strcpy(tokens[0], full_cmd);
				free(full_cmd);
				full_cmd = NULL;
				free(cm);
				cm = NULL;
				return (0);
			}
			else
			{
			}
			free(full_cmd);

			full_cmd = NULL;
		}
	}
	free(cm);
	cm = NULL;
	return (127);
}
