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
		write(1, &str[i], 1);
		i++;
	}
	return (0);
}

/**
 * _strlen - returns the length of a string
 * @str: the address to string argument
 * Return: length of the string
 */
int _strlen(char *str)
{
	int i = 0;

	while (str[i])
		i++;
	return (i);
}
