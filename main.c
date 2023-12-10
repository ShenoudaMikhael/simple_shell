#include "main.h"

int main(int argc, char *argv[])
{

	/*size_t chars_read;*/
	int getline_result = 0, strlen_result = 0;
	char *string = NULL;
	size_t size = 0;
	/*char *args[3];*/
	extern char **environ;
	/*new process */
	int status = 0;

	pid_t pid = 0;
	int ex_result = 0;
	/* string loop to remove new line */
	char *no_new_line = NULL;
	char **tokens = NULL;

	/* strtoken
	char *token = NULL;
	int t;
	*/
	char **paths = NULL;

	(void)argc;

	/* Test */

	if (isatty(STDIN_FILENO))
	{
	start:
		write(1, "($) ", 4);

		/* EOF */
		getline_result = getline(&string, &size, stdin);
		if (getline_result == -1)
		{
			free(string);
			_free_memory(paths);
			_free_memory(tokens);
			free(no_new_line);
			printf("exit shell\n");
			return (-1);
		}
		strlen_result = _strlen(string);

		if (strlen_result == 1)
		{
			goto start;
		}

		no_new_line = _nltrim(string, size);

		paths = _getpath(environ);

		tokens = _strtok(no_new_line, ' ');

		if (_search_path(paths, tokens) == 0)
		{
			pid = fork();
			if (pid == -1)
			{
				_free_memory(tokens);
				/* Error handling if fork fails */
				perror(strcat(argv[0], "1"));
				exit(EXIT_FAILURE);
			}
			if (pid == 0)
			{

				ex_result = execve(tokens[0], tokens, environ);
				if (ex_result == -1)
				{
					perror(argv[0]);

					exit(EXIT_FAILURE);
				}
			}
			else
			{
				/* This code is executed by the parent process */

				/* Wait for the child process to finish */
				waitpid(pid, &status, 0);

				if (WIFEXITED(status))
				{

					/*Child process exited normally*/
					/* printf("Child process completed with exit code: %d\n", WEXITSTATUS(status));*/
				}
				else if (WIFSIGNALED(status))
				{
					printf("Child process terminated by signal: %d\n", WTERMSIG(status));
				}
				else
				{
					/*Child process did not exit normally*/
					/*printf("Child process did not exit normally\n");*/
				}
			}
		}
		else
		{
			perror(strcat(argv[0], "1"));
		}

		goto start;
	}
	else
	{
		getline_result = getline(&string, &size, stdin);
		strlen_result = _strlen(string);

		if (strlen_result == 1)
		{
			return (0);
		}
		no_new_line = _nltrim(string, size);

		paths = _getpath(environ);

		tokens = _strtok(no_new_line, ' ');
		if (_search_path(paths, tokens) == 0)
		{
			pid = fork();
			if (pid == -1)
			{
				_free_memory(tokens);
				/* Error handling if fork fails */
				perror(strcat(argv[0], "1"));
				exit(EXIT_FAILURE);
			}
			if (pid == 0)
			{

				ex_result = execve(tokens[0], tokens, environ);
				if (ex_result == -1)
				{
					perror(argv[0]);

					exit(EXIT_FAILURE);
				}
			}
			else
			{
				/* This code is executed by the parent process */

				/* Wait for the child process to finish */
				waitpid(pid, &status, 0);

				if (WIFEXITED(status))
				{

					/*Child process exited normally*/
					/* printf("Child process completed with exit code: %d\n", WEXITSTATUS(status));*/
				}
				else if (WIFSIGNALED(status))
				{
					printf("Child process terminated by signal: %d\n", WTERMSIG(status));
				}
				else
				{
					/*Child process did not exit normally*/
					/*printf("Child process did not exit normally\n");*/
				}
			}
		}
		else
		{
			perror(strcat(argv[0], "1"));
		}
		/*getline(&string, &size, stdin);
		q = 0;
		no_new_line = malloc(size);
		while (string[q] != '\n')
		{
			no_new_line[q] = string[q];
			q++;
		}

		args[0] = no_new_line;
		args[1] = NULL;

		ex_result = execve(args[0], args, environ);
		if (ex_result == -1)
		{
			perror(argv[0]);

			exit(EXIT_FAILURE);
		}*/
	}

	return 0;
}
