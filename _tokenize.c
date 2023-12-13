#include "main.h"
/**
 * tokenize - function
 * @str: input
 * @delim: input
 * @tokenCount: input
 * Return: value
 */
char **_tokenize(char *str, const char *delim, int *tokenCount)
{

	const char *d = delim;
	char *token;
	int count = 0;
	char *strCopy = _strdup(str);
	char **tokens = malloc(1024 * sizeof(char *));

	if (tokens == NULL)
	{
		free(str);
		perror("Error allocating memory");
		exit(EXIT_FAILURE);
	}
	if (strCopy == NULL)
	{
		free(str);

		perror("Error duplicating string");
		exit(EXIT_FAILURE);
	}
	token = strtok(strCopy, d);
	while (token != NULL)
	{
		if (count >= 1024)
		{
			free(str);
			free(strCopy);
			exit(EXIT_FAILURE);
		}
		tokens[count] = _strdup(token);
		if (tokens[count] == NULL)
		{
			free(str);
			free(strCopy);
			perror("Error duplicating token");
			exit(EXIT_FAILURE);
		}
		count++;
		token = strtok(NULL, d);
	}

	free(strCopy);
	strCopy = NULL;
	*tokenCount = count;

	return (tokens);
}
