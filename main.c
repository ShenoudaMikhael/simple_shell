#include "main.h"
#include <signal.h>
/**
 * _error_message - the errror message on wrong exit
 * @string: intial message
 * @argv: shell name;
 * @command: commaend name
 * Return: void
 */
void _error_message(char *string, char *argv, char *command)
{
	string = _strdup(argv), _strcat(string, " Illegal number:");
	_strcat(string, command), string[_strlen(string)] = '\n';
	write(STDERR_FILENO, string, _strlen(string));
}

/**
 * _read_line - get line from stdin
 * Return: char *
 */
char *_read_line()
{

	char *string = NULL;
	size_t len;
	ssize_t n;

	if (isatty(STDIN_FILENO))
		write(1, "($) ", 4);
	n = getline(&string, &len, stdin);
	if (n == -1)
	{
		free(string);
		return (NULL);
	}
	if (n > 0 && string[n - 1] == '\n')
	{
		string[n - 1] = '\0';
	}
	return (string);
}

/**
 * main - simple shell main entry
 * @argc: num of args
 * @argv: args
 * Return: int
 */
int main(int argc, char *argv[])
{
	int status = 0;
	char *string = NULL, **command = NULL, **paths = NULL;
	(void)argc;

start:
	string = _read_line();
	if (string == NULL)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "\n", 1);
		free(string);
		return (status);
	}
	command = _tokenizer(string, " \t");
	if (!command)
		goto start;
	if (_strcmp(command[0], "exit") == 0)
	{
		if (command[1])
		{
			if (_atoi(command[1]) > 0)
				status = _atoi(command[1]);
			else
			{
				_error_message(string, argv[0], command[1]);
				goto start;
			}
		}
		free(paths), paths = NULL, free(command), free(string), exit(status);
	}
	paths = _get_paths(environ), status = _search_path(paths, command);
	if (status == 0)
		status = _excute(command, argv[0], &status);
	else
		perror(argv[0]);
	free(string), free(paths), paths = NULL;
	(command[0]) ? free(command[0]) : (void)0;
	free(command);
	goto start;
	return (0);
}
