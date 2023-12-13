#include "main.h"

char **tokenizer(char *line, char *delim)
{
    char *token = NULL, *tmp = NULL;

    char **cmd = NULL;

    int cpt = 0, i = 0;


    if (!line)
        return (NULL);
    tmp = _strdup(line);
    token = strtok(tmp, delim);
    while (token)
    {
        cpt++;
        token = strtok(NULL, delim);
    }

    free(tmp), tmp = NULL;

    cmd = malloc(sizeof(char *) * (cpt + 1));
    if (!cmd)
    {
        free(line), line = NULL;
        return (NULL);
    }

    token = strtok(line, delim);
    while (token)
    {
        cmd[i] = token;
        token = strtok(NULL, delim);
        i++;
    }
    free(line);
    cmd[i] = NULL;
    return (cmd);
}