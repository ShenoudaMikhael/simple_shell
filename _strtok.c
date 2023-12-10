#include "main.h"

char **_strtok(char *input, char del)
{
	int i = 0, argc = 0, temp_i = 0;

	char **tokens = malloc(sizeof(char *) * 1024);


	while (input[i] != '\0')
	{

		if (input[i] == del)
		{

			tokens[argc] = malloc(sizeof(char) * ((i - temp_i) + 1));
			_strncpy(tokens[argc], input + temp_i, i - temp_i);
			tokens[argc][i - temp_i] = '\0';
			while (input[i] == del)
			{
				i++;
			}

			temp_i = i;
			argc++;
		}

		i++;
	}

	if (i != temp_i)
	{
		tokens[argc] = malloc(sizeof(char) * (i - temp_i + 1));
		if (tokens[argc] == NULL)
		{
			_free_memory(tokens);
			return NULL;
		}

		_strncpy(tokens[argc], input + temp_i, i - temp_i);
		tokens[argc][i - temp_i] = '\0';
		argc++;
	}

	tokens[argc] = NULL;
	return (tokens);
}
