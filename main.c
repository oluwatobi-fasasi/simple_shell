#include "main.h"

/**
 * main - a simple shell
 *
 * Return: 0 on success
 */
int main()
{
	pid_t child_pid;
	char *buff = NULL;
	size_t len = 0;
	FILE *stream = stdin;
	int status;
	char **argv;
	ssize_t nread = 0;
	int wc;

	while (nread >= 0)
	{
		if (isatty(STDIN_FILENO))
			_puts("($) ");
		nread = getline(&buff, &len, stream);
		if (nread == -1)
		{
			if (isatty(STDIN_FILENO))
				_puts("\n");
			break;
		}
		wc = wordcount(buff);
		argv = splitstr(buff, " \n\t", wc);
		argv[0] = findpath(argv[0]);
		_puts(argv[0]);
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("/.hsh");
			return (1);
		}
		if (child_pid == 0)
		{
			if (execve(argv[0], argv, environ) == -1)
				perror("./hsh");
			sleep(3);
		}
		else
		{
			wait(&status);
		}
	}
	free(buff);
	exit(0);
}
