#include "shell.h"
/**
 * main - function
 * @argc: input
 * @argv: input
 * Return: always 0
*/
int main(int argc, char **argv)
{
    char *prompt = "~shell$ ";
    char *string = NULL, *string_cpy = NULL;
    size_t size = 0;
    ssize_t read;
    const char *delim = " \n";
    int num_tk = 0;
    char *token;
    int i;
    pid_t child_pid;
    char **env = environ;
    (void)argc;

    if (isatty(STDIN_FILENO))
    {
        printf("Program is running in interactive mode.\n");
        while (1)
        {
            printf("%s", prompt);
            read = getline(&string, &size, stdin);
            if (read == -1)
            {
                printf("\n");
                return (-1);
            }
            string_cpy = malloc(sizeof(char) * read);
            if (string_cpy == NULL)
            {
                perror("memory allocation error");
                return (-1);
            }
            strcpy(string_cpy, string);

            token = strtok(string, delim);
            while (token != NULL)
            {
                num_tk++;
                token = strtok(NULL, delim);
            }
            num_tk++;

            argv = malloc(sizeof(char *) * num_tk);
            token = strtok(string_cpy, delim);
            for (i = 0; token != NULL; i++)
            {
                argv[i] = malloc(sizeof(char) * strlen(token));
                strcpy(argv[i], token);
                child_pid = fork();
                if (child_pid == 0)
                {
                    if (strcmp(token, "env") == 0)
                    {
                        while (env)
                        {
                            printf("%s\n", *env);
                            env++;
                        }
                    }
                }
                else
                {
                    wait(NULL);
                }

                token = strtok(NULL, delim);
            }
            argv[i] = NULL;
            child_pid = fork();
            if (child_pid == 0)
            {
                execmd(argv);
                exit(0);
            }
            else
            {
                wait(NULL);
            }
        }
    }
    else
    {
        printf("Program is running in non-interactive mode.\n");
        read = getline(&string, &size, stdin);
        if (read == -1)
        {
            printf("\n");
            return (-1);
        }
        string_cpy = malloc(sizeof(char) * read);
        if (string_cpy == NULL)
        {
            perror("memory allocation error");
            return (-1);
        }
        strcpy(string_cpy, string);

        token = strtok(string, delim);
        while (token != NULL)
        {
            num_tk++;
            token = strtok(NULL, delim);
        }
        num_tk++;

        argv = malloc(sizeof(char *) * num_tk);
        token = strtok(string_cpy, delim);
        for (i = 0; token != NULL; i++)
        {
            argv[i] = malloc(sizeof(char) * strlen(token));
            strcpy(argv[i], token);
            token = strtok(NULL, delim);
        }
        argv[i] = NULL;
        child_pid = fork();
        if (child_pid == 0)
        {
            execmd(argv);
            exit(0);
        }
        else
        {
            wait(NULL);
        }
    }
    free(string_cpy);
    free(string);
    return (0);
}
