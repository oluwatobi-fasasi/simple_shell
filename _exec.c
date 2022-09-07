#include "main.h"

/**
 * _exec - calls fork and execve
 * @argv: argument vector
 * @str: place holder for argument 1
 * Return: 0 or 1
 */
int _exec(char **argv, char *str)
{
	pid_t child_pid = fork();
	int status;

	if (child_pid == -1)
	{
		perror(str);
		return (1);
	}
	if (child_pid == 0)
	{
		if (execve(argv[0], argv, environ) == -1)
			perror(str);
		sleep(3);
	}
	else
	{
		wait(&status);
	}
	return (0);
}
