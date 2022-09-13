#include "main.h"

/**
 * exec_bultin - executes the builtin
 * @str: a string argument
 * Return: void
 */
void exec_builtin(char *str)
{

	if (strncmp(str, "exit", 4) == 0)
		exit(0);
}
