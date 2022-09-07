#include "main.h"

/**
 * _exec - calls fork and execve
 * @argv: argument vector
 * Return: 0 or 1
 */
int _exec(char **argv)
{
	pid_t child_pid = fork();
	int status;

	if (child_pid == -1)
	{
		perror("./hsh");
		return (1);
	}
	if (child_pid == 0)
	{
		if (execve(argv[0], argv, NULL) == -1)
			perror("./hsh");
		sleep(3);
	}
	else
	{
		wait(&status);
	}
	return (0);
}
