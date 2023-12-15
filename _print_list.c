#include "main.h"
/**
 * _printList - print char **
 * @env: list
 * Return: void
 */
void _printList(char **env)
{

	int length = 0;
	int i = 0;

	if (env == NULL)
	{
		write(STDOUT_FILENO, "NULL\n", 5);
		return;
	}

	for (i = 0; env[i] != NULL; i++)
	{
		length = 0;
		while (env[i][length] != '\0')
		{
			length++;
		}

		write(STDOUT_FILENO, env[i], length);
		write(STDOUT_FILENO, "\n", 1);
	}
}
