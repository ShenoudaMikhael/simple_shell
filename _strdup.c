#include "main.h"
/**
 * _strdup - duplicate string
 * @str: text to dublicate
 * Return: char *
 */
char *_strdup(const char *str)
{

	char *ptr;

	int i, len = 0;

	if (str == NULL)

		return (NULL);

	while (*str != '\0')
	{
		len++;

		str++;
	}

	str = str - len;

	ptr = malloc(sizeof(char) * (len + 1));

	if (ptr == NULL)

		return (NULL);

	for (i = 0; i <= len; i++)

		ptr[i] = str[i];

	return (ptr);
}
/**
 * _strdup2 - duplicate string
 * @str: text to dublicate
 * Return: char *
 */
char *_strdup2(const char *str)
{
	char *ptr = NULL;
	int i = 0;
	int len = 0;
	const char *temp = str;

	while (*temp != '\0')
	{
		len++;
		temp++;
	}

	temp = str;

	ptr = malloc(sizeof(char) * (len + 1));

	if (ptr == NULL)
		return NULL;

	for (i = 0; i < len; i++)
		ptr[i] = temp[i];

	ptr[len] = '\0';

	return (ptr);
}
