#include "shell.h"
void execmd(char **argv)
{
    char *cmd = NULL, *cmd_line = NULL;

    if (argv)
    {
        cmd = argv[0];
        cmd_line = get_path(cmd);

        if (execve(cmd_line, argv, NULL) == -1)
        {
            printf("./shell: No such file or directory\n");
        }
    }
}
