#include "main.h"
/**
 * _free_memory - function
 * @ptr: input
 * Return: void
 */
void _free_memory(char **ptr)
{

	int i;

	if (!ptr)
		return;

	for (i = 0; ptr[i] != NULL; i++)
	{
		if (ptr[i])
			free(ptr[i]);
		ptr[i] = NULL;
	}
	free(ptr);

	ptr = NULL;
}
/**
 * _free_memory1 - function
 * @ptr: input
 * Return: void
 */
void _free_memory1(char **ptr)
{

	int i;

	if (!ptr)
		return;

	for (i = 1; ptr[i] != NULL; i++)
	{
		if (ptr[i])
			free(ptr[i]);
		ptr[i] = NULL;
	}
	free(ptr);

	ptr = NULL;
}
