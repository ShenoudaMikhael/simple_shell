#include "main.h"
/**
 * my_strtok - function
 * @str: string
 * @delim: delimiter
 * Return: token
*/
char *_strtok(char *str, const char *delim)
{
	static char *lastToken;
	char *token;
	const char *d;

	if (str != NULL)
	{
		lastToken = str;
	}
	if (lastToken == NULL)
	{
		return (NULL);
	}
	token = lastToken;
	while (*token != '\0' && strchr(delim, *token) != NULL)
	{
		token++;
	}
	if (*token == '\0')
	{
		lastToken = NULL;
		return (NULL);
	}
	d = delim;
	while (*lastToken != '\0' && strchr(d, *lastToken) == NULL)
	{
		lastToken++;
	}
	if (*lastToken != '\0')
	{
		*lastToken = '\0';
		lastToken++;
	}
	else
	{
		lastToken = NULL;
	}
	return (token);
}
