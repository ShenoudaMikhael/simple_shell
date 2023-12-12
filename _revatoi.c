#include "main.h"
#include <stdarg.h>
/**
 * _sprintf - convert to char
 * @buffer: bufer to convert
 * @format: buffer format
 * Return: int
 */
int _sprintf(char *buffer, const char *format, ...)
{
	va_list args;
	int count;

	va_start(args, format);
	count = vsprintf(buffer, format, args);
	va_end(args);

	return (count);
}
/**
 * _rev_atoi - convert int to char
 * @num: number to convert
 * Return: char *
 */
char *_rev_atoi(int num)
{
	char *result = (char *)malloc(12 * sizeof(char));

	if (result == NULL)
	{
		return (NULL);
	}

	_sprintf(result, "%d", num);

	return (result);
}
