#include "main.h"
#include <signal.h>
/**
 * main - simple shell main entry
 * @argc: num of args
 * @argv: args
 * Return: int
 */
int main(int argc, char *argv[])
{

	(void)argc;

	if (isatty(STDIN_FILENO))
	{
		_interactive(argv);

		/* END OF INTERACTIVE*/
	}
	else
		_noninteractive(argv);

	return (0);
}
