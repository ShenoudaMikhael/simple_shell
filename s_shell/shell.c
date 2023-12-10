#include "shell.h"

int main(int argc, char **argv)
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
    (void)argc;

    while (1) 
    {
        printf("%s", prompt);
        read = getline(&string, &size, stdin);
        if (read == -1){
            printf("\n");
            return (-1);
        }
        string_cpy = malloc(sizeof(char) * read);
        if (string_cpy == NULL){
            perror("memory allocation error");
            return (-1);
        }
        strcpy(string_cpy, string);

        token = strtok(string, delim);
        while (token != NULL){
            num_tk++;
            token = strtok(NULL, delim);
        }
        num_tk++;

        argv = malloc(sizeof(char *) * num_tk);
        token = strtok(string_cpy, delim);
        for (i = 0; token != NULL; i++){
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