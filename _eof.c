#include "main.h"
int _eof(int getline_result, char *string,
		  char **paths)

{
	if (getline_result == -1)
	{

		free(string);
		paths = NULL;
		(void)paths;

		write(1, "exit shell\n", 5);
		exit(EXIT_FAILURE);
	}
	return (0);
}
