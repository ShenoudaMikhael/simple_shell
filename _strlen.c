#include <stdlib.h>
/**
 * _strlen - get sreing length
 * @s: the string
 * Return: int
 */
int _strlen(char *s)
{
	int count = 0;

	if (s == NULL)
	{
		return (0);
	}
	while (*s++)
	{
		count++;
	}
	return (count);
}
