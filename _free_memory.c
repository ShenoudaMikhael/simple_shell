#include <stdlib.h>

void _free_memory(char **ptr)
{

	int i;

	if (ptr != NULL)
	{

		for (i = 0; ptr[i] != NULL; i++)
		{

			free(ptr[i]);
		}

	}
}
