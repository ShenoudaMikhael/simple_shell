#include "main.h"

char **_tokenizer(char *line, char *delim)
{
    char *token = NULL, *tmp = NULL;
    char **cmd = NULL;
    int cpt = 0, i = 0;

    if (!line)
        return (NULL);
    tmp = _strdup(line);

    token = strtok(tmp, delim);
    if (token == NULL)
    {

        free(line), line = NULL;
        free(tmp), tmp = NULL;
        return (NULL);
    }
    while (token)
    {
        cpt++;
        token = strtok(NULL, delim);
    }

    free(tmp), tmp = NULL;

    cmd = malloc(sizeof(char *) * (cpt + 5));
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
    cmd[i] = NULL;

    return (cmd);
}