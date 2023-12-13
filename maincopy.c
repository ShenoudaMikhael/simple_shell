#include "main.h"
#include <signal.h>
/**
 * main - simple shell main entry
 * @argc: num of args
 * @argv: args
 * Return: int
 */
int main(int argc, char *argv[], char *environ[])
{

	(void)argc;

	if (isatty(STDIN_FILENO))
	{
		_interactive(argv[0], environ);

		/* END OF INTERACTIVE*/
	}
	else
		_noninteractive(argv[0], environ);

	return (0);
}
