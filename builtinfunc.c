#include "main.h"

/**
 * exec_builtin - executes the builtin
 * @str: a string argument
 * @argv: argument vector:wq
 * Return: void
 */
void exec_builtin(char *str, char **argv)
{

	if (strncmp(str, "exit", 4) == 0)
	{
		freevect(argv);
		free(str);
		exit(0);
	}
}
