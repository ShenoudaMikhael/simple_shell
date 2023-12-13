#include "main.h"
/**
 * _free_memory - function
 * @ptr: input
 * Return: void
 */
void _free_memory(char **ptr)
{

	int i;


	if (ptr != NULL)
	{

		for (i = 0; ptr[i] != NULL; i++)

			free(ptr[i]);

		free(ptr);
	}
	ptr = NULL;
}
