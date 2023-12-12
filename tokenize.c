#include "main.h"
/**
 * tokenize - function
 * @str: input
 * @delim: input
 * @tokenCount: input
 * Return: value
*/
char **tokenize(char *str, const char *delim, int *tokenCount)
{

	const char *d = delim;
	char *token;
	int count = 0;
	char *strCopy = strdup(str);
	char **tokens = malloc(1024 * sizeof(char *));

	if (tokens == NULL)
	{
		perror("Error allocating memory");
		exit(EXIT_FAILURE);
	}
	if (strCopy == NULL)
	{
		perror("Error duplicating string");
		exit(EXIT_FAILURE);
	}
	token = my_strtok(strCopy, d);
	while (token != NULL)
	{
		if (count >= 1024)
		{
		
			exit(EXIT_FAILURE);
		}
		tokens[count] = strdup(token);
		if (tokens[count] == NULL)
		{
			perror("Error duplicating token");
			exit(EXIT_FAILURE);
		}
		count++;
		token = my_strtok(NULL, d);
	}

	free(strCopy);

	*tokenCount = count;

	return (tokens);
}
