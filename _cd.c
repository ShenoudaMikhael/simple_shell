#include "main.h"
/***/
extern char **environ;
int main(int argc, char *argv[])
{
    char *prompt = "~bella$ ";
    char *string = NULL, *string_cpy = NULL;
    size_t size = 0;
    ssize_t read;
    const char *delim = " \n";
    int num_tk = 0;
    char *token;
    int i;
    pid_t child_pid;
    char *home, *p_dir;
    char **env = environ;
    char *n_dir = argv[1];
    char cwd[1024];
    char *c_dir;
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
                    if (strcmp(token, "cd") == 0)
                    {
                        if (getcwd(cwd, sizeof(cwd)) != NULL)
                        {
                            c_dir = getcwd(cwd, sizeof(cwd));
                            while (*env)
                            {
                                if (strncmp(*env, "HOME", 4) == 0)
                                {
                                    home = *env + 5;
                                    break;
                                }
                                env++;
                            }
                            while (*env)
                            {
                                if (strncmp(*env, "OLDPWD", 6) == 0)
                                {
                                    p_dir = *env + 7;
                                    break;
                                }
                                env++;
                            }
                        }
                        else
                        {
                            perror("getcwd() error");
                        }
                    }
                }
                else
                {
                    wait(NULL);
                }
                token = strtok(NULL, delim);
                n_dir = token;
                if (n_dir == NULL)
                {
                    n_dir = home;
                    c_dir = n_dir;
                    chdir(c_dir);
                }
                else if (n_dir != NULL && (strcmp(n_dir, "-") != 0))
                {
                    strcat(c_dir, "/");
                    strcat(c_dir, n_dir);
                    strcat(c_dir, "\0");
                    chdir(c_dir);
                }
                else if (strcmp(n_dir, "-") == 0)
                {
                    n_dir = p_dir;
                    chdir(n_dir);
                }
            }
            argv[i] = NULL;
        }
    }
    return (0);
}