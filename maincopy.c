#include "main.h"
#include <signal.h>

int main(int argc, char *argv[])
{

	(void)argc;

	if (isatty(STDIN_FILENO))
	{
		_interactive(argv[0]);

		/* END OF INTERACTIVE*/
	}
	else
		_noninteractive(argv[0]);

	return (0);
}
