#include "main.h"

/**
 * wordcount - return the number of arguments
 * @str: string argument
 * Return: number of arguments
 */
int wordcount(char *str)
{
        int i = 0;
        int wc = 0;
        int button = 0;

        while (str[i])
        {
                if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
                {
                        button = 0;
                }
                else if (button == 0)
                {
                        button = 1;
                        wc++;
                }
                i++;
        }
        return (wc);
}

/**
 * delim_nter - return the number of the delimit
 * @str: string argument
 * Return: an integer
 */
int delim_nter(char *str, char *delim)
{
        int i = 0;
        int k =0;
        int num = 0;

        while (delim[i])
        {
                k = 0;
                if (str[k] == delim[i])
                {
                        num++;
                        k++;
                }
                i++;
        }
        return (num);
}
