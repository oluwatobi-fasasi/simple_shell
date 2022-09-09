#include "main.h"

/**
 * main - a simple shell
 * @argc: argument count
 * @agv: argument vector
 *
 * Return: 0 on success
 */
int main(int argc, char *agv[])
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
			_puts("($) ");
		nread = getline(&buff, &len, stream);
		if (nread == -1)
		{
			if (isatty(STDIN_FILENO))
				_puts("\n");
			break;
		}
		buff[_strlen(buff) - 1] = '\0';
		wc = wordcount(buff);
		if (argc == 1 && wc > 0)
		{
			argv = splitstr(buff, " \n\t", wc);
			argv[0] = findpath(argv[0]);
			if (argv[0] && access(argv[0], X_OK) == 0)
				_exec(argv, agv[0]);
			else
				perror(agv[0]);

		}
	}
	free(buff);
	return (0);
}
