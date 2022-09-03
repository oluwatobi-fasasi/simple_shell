#include "main.h"

/**
 * main - a simple shell
 *
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	pid_t child_pid;
	ssize_t nread;
	char *buff = NULL;
	size_t len = 0;
	FILE *stream = stdin;
	int status;

	_puts("($)");
	while ((nread = getline(&buff, &len, stream)) != -1 && argc == 1)
	{
		buff[_strlen(buff) - 1] = '\0';
		child_pid = fork();
		if (child_pid == -1)
		{
			perror(argv[0]);
			return (1);
		}
		if (child_pid == 0)
		{
			if (execve(buff, argv, environ) == -1)
				perror(argv[0]);
			sleep(3);
		}
		else
		{
			wait(&status);
		}
		_puts("($)");
	}
	free(buff);
	exit(0);
}
