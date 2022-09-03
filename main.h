#ifndef _HEADER_
#define _HEADER_
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/wait.h>
#define _GNU_SOURCE
#include <stdio.h>

extern char **environ;
int _strlen(char *str);
int _puts(const char *str);

#endif
