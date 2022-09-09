#include "main.h"

/**
 * _puts - writes a string to standard output
 * @str: a string as argument
 * Return: 0 on success
 */
int _puts(const char *str)
{
	int i = 0;

	while (str[i])
	{
		write(STDOUT_FILENO, &str[i], 1);
		i++;
	}
	return (0);
}
