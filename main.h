#ifndef _HEADER_
#define _HEADER_
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/wait.h>
#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include <signal.h>
#include <sys/stat.h>
#include <errno.h>

extern char **environ;
int _strlen(const char *str);
int _puts(const char *str);
char **splitstr(char *str, char *delim, int wc);
char *_strdup(const char *str);
void catch_sig(int sign_id);
int wordcount(char *str);
char *pathcat(char *dest, char *src, int len);
char *findpath(char *cmd);
char *_getenv(const char *name);
int _strncmp(const char *str1, const char *str2, int len);
int delim_nter(char *str, char *delim);
int _exec(char **argv, char *str);
void freevect(char **argv);
void freepath(char *str);
int _perror(const char *str);

#endif
