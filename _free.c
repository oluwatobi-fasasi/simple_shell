#include "main.h"

/**
 * freevect - free the malloc allocated to vectors
 * @argv: vector
 * Return: void
 */
void freevect(char **argv)
{
	int i = 0;
	char **tmp = argv;

	if (argv)
	{
		while (argv[i])
		{
			free(argv[i]);
			i++;
		}
		free(tmp);
	}
}
