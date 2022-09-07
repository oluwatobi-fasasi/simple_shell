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
	/*int wc;*/
	char *argv[2];
	ssize_t nread = 0;
	struct stat st;

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
		buff[_strlen(buff) - 1] = '\0';
		argv[0] = buff;
		argv[1] = NULL;
		/*wc = wordcount(buff);*/
		/*argv = splitstr(buff, " \n\t", wc);*/
		/*argv[0] = findpath(argv[0]);*/
		if (argv[0] != NULL && argc == 1 && stat(argv[0], &st) == 0)
			_exec(argv, agv[0]);
		else
			perror(agv[0]);
	}
	free(buff);
	exit(0);
}
