#include "main.h"

/**
 * exec_builtin - executes the builtin
 * @str: a string argument
 * @argv: argument vector:wq
 * Return: void
 */
void exec_builtin(char *str, char **argv)
{
	int i = 0;

	if (strncmp(str, "exit", 4) == 0)
	{
		freevect(argv);
		free(str);
		exit(0);
	}
	if (strncmp(str, "env", 3) == 0)
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
	char *built_cmd[3] = {"exit", "env", NULL};

	while (built_cmd[i])
	{
		if (strncmp(built_cmd[i], str, _strlen(built_cmd[i])) == 0)
			return (0);
		i++;
	}
	return (1);
}
