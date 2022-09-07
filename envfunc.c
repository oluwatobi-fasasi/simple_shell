#include "main.h"

/**
 * _getenv -  gets an environment variable value.
 * @name: variable to search for
 * Return: a pointer to a string value of env
 */
char *_getenv(const char *name)
{
        int i = 0;
        int len = _strlen(name);
        char *val;
        int k = 0;
        int len_env;

        while (environ[i])
        {
                if (_strncmp(environ[i], name, len) == 0)
                {
                        len_env = _strlen(environ[i]);
                        val = malloc((len_env - len) + 1);
                        if (val == NULL)
                                return (NULL);
                        if (environ[i][len] == '=')
                        {
                                len++;
                                while (environ[i][len])
                                {
                                        val[k] = environ[i][len];
                                        k++;
                                        len++;
                                }
                                val[k] = '\0';
                        }
                        return (val);
                }
                i++;
        }
        return (NULL);
}

/**
 * findpath - find the absolute path
 * @cmd: command
 * Return: the absolute path
 */
char *findpath(char *cmd)
{
        struct stat st;
        char *getpath;
        char **ptokens;
        int deli_num;
        int i = 0;

        if (cmd)
        {
                if ((stat(cmd, &st) != 0) && cmd[0] != '\\')
                {
                        getpath = _getenv("PATH");
                        deli_num = delim_nter(getpath, ":") + 1;
                        ptokens = splitstr(getpath, ":", deli_num);

                        while (ptokens[i])
                        {
                                ptokens[i] = pathcat(ptokens[i], cmd, _strlen(cmd));
                                if ((stat(ptokens[i], &st) == 0))
                                {
                                        free(cmd);
                                        cmd = ptokens[i];
                                        return (cmd);
                                }
                                i++;
                        }
                        free(getpath);
                        free(ptokens);
                }
                if (stat(cmd, &st) == 0)
                        return (cmd);
        }
        free(cmd);
        return (NULL);
}
