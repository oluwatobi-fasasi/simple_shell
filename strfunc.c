#include "main.h"

/**
 * _strlen - returns the length of a string
 * @str: the address to string argument
 * Return: length of the string
 */
int _strlen(const char *str)
{
	int i = 0;

	while (str[i])
		i++;
	return (i);
}

/**
 * splitstr - return a pointer to an array
 * @str: string argument to split
 * @wc: integer argument for word count
 * @delim: what char to split at
 * Return: a pointer to an array of delimit string
 */
char **splitstr(char *str, char *delim, int wc)
{
	char *token = NULL;
	char *tmp = NULL;
	char **ptoken;
	int i = 0;

	ptoken = malloc(sizeof(char *) * (wc + 1));
	if (ptoken == NULL)
		return (NULL);
	if (str[_strlen(str) - 1] == '\n')
		str[_strlen(str) - 1] = '\0';
	tmp = _strdup(str);
	token = strtok(tmp, delim);
	while (token)
	{
		ptoken[i] = _strdup(token);
		token = strtok(NULL, delim);
		i++;
	}
	ptoken[i] = NULL;
	free(tmp);
	return (ptoken);
}

/**
 * _strdup - duplicate string
 * @str: pointer to the string
 * Return: pointer to copy
 */
char *_strdup(const char *str)
{
	int i = 0;
	char *copy;

	copy = malloc(_strlen(str) + 1);
	while (str[i])
	{
		copy[i] = str[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

/**
 * pathcat - concatenate strings
 * @src: string to concate
 * @dest: address to concate to
 * @len: length of src
 * Return: a pointer to the new string
 */
char *pathcat(char *dest, char *src, int len)
{
	int i = 0;
	char *newstr;
	int m;
	int k = 0;

	m = _strlen(dest);
	newstr = malloc(len + m + 2);
	if (newstr == NULL)
		return (NULL);
	while (dest[i])
	{
		newstr[i] = dest[i];
		i++;
	}
	newstr[i] = '/';
	i++;
	while (src[k])
	{
		newstr[i] = src[k];
		i++;
		k++;
	}
	newstr[i] = '\0';
	return (newstr);
}
/**
 * _strncmp - compares two string unto spelt length
 * @len: an integer
 * @str1: string argument 1
 * @str2: string argument 2
 * Return: 0 if true, or the difference
 */
int _strncmp(const char *str1, const char *str2, int len)
{
	int i;

	for (i = 0; str1[i] == str2[i]; i++)
	{
		if (str2[i + 1] == '\0' && str2[len] == '\0')
			return (0);
	}
	return (str1[i] - str2[i]);
}
