#include "shell.h"
/**
 * get_path - function to get full path and search for command on the directories in this path
 * @cmd: command 
 * Return: always 0
*/
extern char **environ;

char *get_path(char *cmd)
{
    char **env = environ;
    char *path, *path_cpy, *path_tk, *file_path;
    int cmd_len, dir_len;

    while (*env) {
        if (strncmp(*env, "PATH", 4) == 0) {
            path = *env + 5;
            break;
        }
        env++;
    }

    if (path){
        path_cpy = strdup(path);
        path_tk = strtok(path_cpy, ":");

        while(path_tk != NULL)
        {
            dir_len = strlen(path_tk);
            cmd_len = strlen(cmd);
            file_path = malloc(cmd_len + dir_len + 2);
            strcpy(file_path, path_tk);
            strcat(file_path, "/");
            strcat(file_path, cmd);
            strcat(file_path, "\0");

            if (access(file_path, F_OK) == 0)
            {
                free(path_cpy);
                return (file_path);
            }
            else
            {
                free(file_path);
                path_tk = strtok(NULL, ":");
            }
        }
        free(path_cpy);

        if (access(cmd, F_OK) == 0)
        {
            return (cmd);
        }
    }
    return (0);
}