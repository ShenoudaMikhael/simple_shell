#include "main.h"
/**
 * _nltrim -function
 * @input: input
 * Return: void
 */
void _nltrim(char *input)
{
	int len = _strlen(input);

	input[len - 1] = '\0';
}
