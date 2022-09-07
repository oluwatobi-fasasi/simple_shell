#include "main.h"

/**
 * main - a simple shell
 *
 * Return: 0 on success
 */
int main(void)
{
	char *buff = NULL;
	size_t len = 0;
	FILE *stream = stdin;
	int wc;
	char **argv;
	ssize_t nread = 0;

	while (nread >= 0)
	{
		if (isatty(STDIN_FILENO))
			_puts("#cisfun$ ");
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
		if (argv[0] != NULL)
			_exec(argv);
	}
	free(buff);
	exit(0);
}
