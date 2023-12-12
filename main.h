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

extern char **environ;

void _free_memory(char **paths);

int _strlen(char *s);
int _strcmp(char *env, char *s);
int _search_path(char **paths, char **tokens);
char **_get_paths(char **environ, int pathCount);

int _atoi(char *s);

void _nltrim(char *input);
char *_strcat(char *dest, char *src);
int _strncmp(const char *s1, const char *s2, int n);

char *_strncpy(char *dest, char *src, int n);
char *_strcpy(char *dest, char *src);
char *_strncpy2(char *dest, char *src, int start, int n);

char *my_strtok(char *str, const char *delim);
char **tokenize(char *str, const char *delim, int *tokenCount);

char **_getpath(char **environ);

void freeTokens(char **tokens, int tokenCount);

int _eof(int getline_result, char *string,
		 char **paths);

int child(char **tokens);
char *_handle_environ();

void _noninteractive(char *argv);
void _handle_exit(char **tokens, int status, int tokenCount, char *string);
void _handleCtrlC(int signum);
void _interactive(char *argv);

#endif
