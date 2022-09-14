#include "main.h"

/**
 * main - a simple shell
 * @argc: argument count
 * @agv: argument vector
 * Return: 0 on success
 */
int main(int argc, char *agv[])
{
	char *buff = NULL;
	size_t len = 0;
	FILE *stream = stdin;
	int wc, n;
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
		argv = splitstr(buff, " \n\t", wc);
		if (argc == 1 && wc > 0)
		{
			n = check_cmd(argv[0]);
			if ((n == 0) && (wc == 1))
				exec_builtin(argv[0], argv);
			if (n == 1)
				argv[0] = findpath(argv[0]);
			if (argv[0] && (access(argv[0], X_OK) == 0) && n == 1)
				_exec(argv, agv[0]);
			else if (n == 1)
				perror(agv[0]);
			free(buff);
			freevect(argv);
		}
		else if (wc > 0)
			perror(agv[0]);
	}
	return (0);
}
