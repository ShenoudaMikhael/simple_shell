#include "main.h"
#include <signal.h>

void handleCtrlC(int signum)
{
	if (signum == 2)
		exit(EXIT_SUCCESS);
}
void handle_exit(char **tokens, int status, int tokenCount, char *string)
{
	if (tokens != NULL && _strcmp(tokens[0], "exit") == 0)
	{
		if (tokens[1] != NULL)
			status = _atoi(tokens[1]);
		free(string);
		freeTokens(tokens, tokenCount);

		exit(status);
	}
}
char *handle_environ()
{
	char **env;

	for (env = environ; *env != NULL; env++)
	{

		if (_strncmp(*env, "PATH=", 5) == 0)
		{
			return (*env + 5);
			break;
		}
	}
	return (NULL);
}
int main(int argc, char *argv[])
{

	int search_result = -1, tokenCount = 0, pathCount = 0, status = 0, getline_result = 0;
	char *string = NULL;
	char *env = NULL;
	size_t size = 0;
	char **tokens = NULL, **paths = NULL;
	char ***holder = malloc(sizeof(char) * 1024);
	int holderCount = 0;
	(void)argc;

	if (isatty(STDIN_FILENO))
	{
		signal(SIGINT, handleCtrlC);

		while (1)
		{

			write(1, "($) ", 4);

			getline_result = getline(&string, &size, stdin);

			if (_strlen(string) == 1)
			{
				if (string != NULL)
					free(string), string = NULL;
				continue;
			}
			if (getline_result == -1)
			{

				for (search_result = 0; search_result < holderCount + 1; search_result++)
					_free_memory(holder[search_result]);
				free(holder);
				free(string);

				exit(EXIT_FAILURE);
			}
			if (string[_strlen(string) - 1] == '\n')
			{
				string[_strlen(string) - 1] = '\0';
			}
			
			tokens = tokenize(string, " ", &tokenCount);
			handle_exit(tokens, status, tokenCount, string);
			env = handle_environ();

			paths = tokenize(env, ":", &pathCount);

			search_result = _search_path(paths, tokens);

				if (search_result == 0)
			{
				child(tokens);
			}
			else
			{
				perror(strcat(argv[0], "1"));
			}
			holder[holderCount] = paths;
			holderCount++;
			holder[holderCount] = tokens;
			holderCount++;
		}

		/* END OF INTERACTIVE*/
	}
	else
	{



		getline_result = getline(&string, &size, stdin);

		if (_strlen(string) == 1)
		{
			exit(0);
		}
		if (getline_result == -1)
		{

			for (search_result = 0; search_result < holderCount + 1; search_result++)
				_free_memory(holder[search_result]);
			free(holder);
			free(string);

			exit(EXIT_FAILURE);
		}
		if (string[_strlen(string) - 1] == '\n')
		{
			string[_strlen(string) - 1] = '\0';
		}
		
		tokens = tokenize(string, " ", &tokenCount);
		handle_exit(tokens, status, tokenCount, string);
		env = handle_environ();

		paths = tokenize(env, ":", &pathCount);

		search_result = _search_path(paths, tokens);

		if (search_result == 0)
		{
			child(tokens);
		}
		else
		{
			perror(strcat(argv[0], "1"));
		}
		holder[holderCount] = paths;
		holderCount++;
		holder[holderCount] = tokens;
		holderCount++;
	}
	return (0);
}
