#include "main.h"
/**
 * strncpy2 - function
 * @dest: input
 * @src: input
 * @start: input
 * @n: input
 * Return: dest
*/
char *_strncpy2(char *dest, char *src, int start, int n)
{
	int i;
	i = start;

	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	printf("%s\n", dest);
	return (dest);
}
