#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

char *_nltrim(char *input, size_t size)
{
	int q = 0;

	char *no_new_line = malloc(size);

	while (input[q] != '\n')
	{
		no_new_line[q] = input[q];
		q++;
	}
	no_new_line[q] = '\0';
	return (no_new_line);
}
