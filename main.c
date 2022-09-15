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
	cmd_f cmd[] = {
		{"exit", exitfunc},
		{"env", _printenv}
	};

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
		if (argc > 0 && wc > 0)
		{
			n = check_cmd(argv[0]);
			if (n >= 0)
				cmd[n].f(buff, argv);
			else
				_exec(argv, agv[0]);
		}
	}
	if (wc > 0)
	{
		free(buff);
		freevect(argv);
	}
	return (0);
}
