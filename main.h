#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "sys/types.h"
#include <sys/stat.h>
#include <sys/wait.h>

typedef struct bins
{
    char *cmd;
    int (*fun)(char *);
} built_ins;

void _free_memory(char **paths);

int _strlen(char *s);
int _strcmp(char *env, char *s);
int _search_path(char **paths, char **tokens);
int _atoi(char *s);

char *_nltrim(char *input, size_t size);
char *_strcat(char *dest, char *src);
char *_strncpy(char *dest, char *src, int n);
char *_strcpy(char *dest, char *src);
char *_strncpy2(char *dest, char *src, int start, int n);
char **_strtok(char *input, char del);
char **_getpath(char **environ);

#endif
