#include "main.h"

/**
 * get_path_env - get the PATH env var.
 *
 * Return: string with the value of PATH.
 */
char *get_path_env()
{
	int i = 0;
	char *path;

	while (environ[i] != NULL)
	{
		path = strtok(environ[i], "=");
		if (_strcmp(path, "PATH") == 0)
		{
			path = strtok(NULL, "=");
			return (path);
		}
		i++;
	}
	return (NULL);
}
