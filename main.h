#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "sys/types.h"
#include <sys/stat.h>
#include <sys/wait.h>

extern char **environ;
char *_strdup(const char *str);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
char *_strtok(char *str, const char *delim);

char **_tokenizer(char *line, char *delim);
char **_tokenize(char *str, const char *delim, int *tokenCount);
char **_get_paths(char **environ);
void _freeTokens(char **tokens, int tokenCount);

int _atoi(char *s);
int _strcmp(char *env, char *s);
int _strlen(char *s);
int _strncmp(const char *s1, const char *s2, int n);

int _excute(char **command, char *argv, int *status);
int _search_path(char **paths, char **tokens);

void _free_memory(char **ptr);

#endif
