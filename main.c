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
	char *argv[2] = {"./hsh", NULL};
	ssize_t nread = 0;

	while (nread >= 0)
	{
		if (isatty(STDIN_FILENO))
			_puts("#cisfun$ ");
		nread = getline(&buff, &len, stream);
		if (buff[_strlen(buff) - 1] == '\n')
			buff[_strlen(buff) - 1] = '\0';
		argv[0] = buff;
		if (nread == -1)
		{
			if (isatty(STDIN_FILENO))
				_puts("\n");
			break;
		}
		if (argv[0] != NULL)
		{
			_exec(argv);
		}
	}
	free(buff);
	exit(0);
}