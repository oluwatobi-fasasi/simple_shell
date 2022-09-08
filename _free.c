#include "main.h"

/**
 * freevect - free the malloc allocated to vectors
 * @argv: vector
 * Return: void
 */
void freevect(char **argv)
{
	char **tmp = argv;

	if (argv)
	{
		while (*argv)
			free(*argv++);
		free(tmp);
	}
}
