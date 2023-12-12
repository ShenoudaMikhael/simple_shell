#include "main.h"

/**
 * _strncpy - function to copy n of string bytes
 * @dest: destination ptr
 * @src: source ptr
 * @n: number of bytes to copy
 * Return: dest pointer
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i;

	i = 0;
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}

	while (i < n)
	{

		dest[i] = '\0';

		i++;
	}
	return (dest);
}
