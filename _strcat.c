#include <stdio.h>
/**
 * _strcat - concat two strings
 * @dest: destination
 * @src: Source
 * Return: full text
 */
char *_strcat(char *dest, char *src)
{
	int i, i2;

	i = 0;
	i2 = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	while (src[i2] != '\0')
	{
		dest[i] = src[i2];
		i2++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
