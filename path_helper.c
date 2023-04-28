#include "main.h"

/**
 * get_new_path - construct the path of the command.
 * @cmd: the command/
 * Return: pointer to new string.
 */
char *get_new_path(char *cmd)
{
	char *new_path = NULL, *paths, *path;

	if (access(cmd, X_OK) == -1)
	{
		paths = get_path_env();
		path = strtok(paths, ":");
		while (path != NULL)
		{
			new_path = append_to_path(path, cmd);
			if (access(new_path, X_OK) == -1)
				free(new_path);
			else
				break;
			path =  strtok(NULL, ":");
		}

	}
	return (new_path);
}

/**
 * append_to_path - append the command to a path.
 * @path: the path.
 * @cmd: the command/
 * Return: pointer to new string.
 */
char *append_to_path(char *path, char *cmd)
{
	int i = 0, j = 0;
	char *new_path = NULL;

	while (path[i] != '\0')
		i++;
	while (cmd[j] != '\0')
		j++;
	new_path = malloc(sizeof(char) * (i + j + 2));
	if (new_path == NULL)
		return (NULL);

	i = 0;
	while (path[i] != '\0')
	{
		new_path[i] = path[i];
		i++;
	}
	new_path[i] = '/';
	i++;
	j = 0;
	while (cmd[j] != '\0')
	{
		new_path[i + j] = cmd[j];
		j++;
	}
	new_path[i + j] = '\0';
	return (new_path);
}

/**
 * get_path_env - get the PATH env var.
 *
 * Return: string with the value of PATH.
 */
char *get_path_env()
{
	int i = 0, num_vars = 0;
	char *path = NULL, **env_copy = NULL;

	while (environ[num_vars] != NULL)
		num_vars++;
	env_copy = malloc((num_vars + 1) * sizeof(char *));
	if (env_copy == NULL)
		return (NULL);
	env_copy[num_vars] = NULL;
	while (environ[i] != NULL)
	{
		env_copy[i] = strdup(environ[i]);
		if (env_copy[i] == NULL)
			return (NULL);
		i++;
	}
	i = 0;
	while (env_copy[i] != NULL)
	{
		path = strtok(env_copy[i], "=");
		if (_strcmp(path, "PATH") == 0)
		{
			path = strtok(NULL, "=");
			return (path);
		}
		i++;
	}
	return (NULL);
}
