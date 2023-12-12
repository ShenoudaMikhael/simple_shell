#include "shell.h"
extern char **environ;
int main(int argc, char **argv)
{
    char *string = NULL, *string_cpy = NULL;
    size_t size = 0;
    ssize_t read;
    const char *delim = " \n";
    int num_tk = 0;
    char *token;
    int i;
    
}