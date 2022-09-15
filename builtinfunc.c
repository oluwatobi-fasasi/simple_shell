#include "main.h"

/**
 * exitfunc - executes the builtin
 * @str: a string argument
 * @argv: argument vector
 * Return: void
 */
void exitfunc(char *str, char **argv)
{
	if (strncmp(str, "exit", 4) == 0)
	{
		free(str);
		freevect(argv);
		exit(0);
	}
}

/**
 * _printenv - print environment variables
 * @str: string command
 * @argv: argument vector
 * Return: void
 */
void _printenv(char *str, char **argv)
{
	int i = 0;

	if (str != NULL && argv != NULL)
	{
		while (environ[i])
			i++;
		i--;
		while (environ[i])
		{
			_puts(environ[i]);
			_puts("\n");
			i--;
		}
	}
}
/**
 * check_cmd - check to see is input is a built in
 * @str: a string argument
 * Return: 0 on success or 1 on failure
 */
int check_cmd(char *str)
{
	int i = 0;
	char *built_cmd[] = {"exit", "env", NULL};

	while (built_cmd[i])
	{
		if (strncmp(built_cmd[i], str, _strlen(built_cmd[i])) == 0)
		{
			return (i);
		}
		i++;
	}
	return (-1);
}
