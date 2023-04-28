#include "main.h"

/**
 * read_commands - Read commands line by line fromt he stdin
 * @status: previous status code
 * Return: string containing the first line.
 */
char *read_commands(int status)
{
	char *line = NULL, ex[] = "exit";
	size_t bufsize = 0;
	int i = 0, j = 0, is_exit = -1;

	if (getline(&line, &bufsize, stdin) == -1)
	{
		free(line);
		return (NULL);
	}
	while (line[i] != '\0' && line[i] != 10)
	{
		if (line[i] == ex[0] && is_exit == -1)
		{
			is_exit = 1;
			j = 0;
			while (ex[j] != '\0')
			{
				if (ex[j] != line[i + j])
				{
					is_exit = 0;
					break;
				}
				j++;
			}
			i += j;
		}
		if (line[i] != ' ' && line[i] != '\t' &&
				line[i] != 10 && is_exit == 1 && line[i] != '\0')
		{
			is_exit = 0;
			break;
		}
		i++;
	}
	if (is_exit == 1)
	{
		free(line);
		exit(status);
	}
	return (line);
}

/**
 * get_command_path - get the path of a command
 * @command: the command name
 * Return: currently NULL (WIP).
 */
char *get_command_path(char *command)
{
	char *path_env = getenv("PATH");

	if (path_env == NULL || command == NULL)
	{
		return (NULL);
	}

	return (NULL);
}


/**
 * execute_command - responsible for executing a command
 * with the given arguments.
 * @args: array of strings representing the command and arguments.
 * @prog_name: the name of the program.
 * Return: 1 on success 0 when it fails.
 */
int execute_command(char **args, char *prog_name)
{
	pid_t pid;
	int status = 0;
	char *new_path = NULL;

	if (args[0] == NULL)
		return (1);
	new_path = get_new_path(args[0]);
	pid = fork();
	if (pid == 0)
	{
		if (new_path != NULL)
		{
			if (execve(new_path, args, environ) == -1)
				perror(prog_name);
		}
		else
		{
			if (execve(args[0], args, environ) == -1)
				perror(prog_name);
		}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
		perror("fork error");
	else
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	if (new_path != NULL)
		free(new_path);
	return (WEXITSTATUS(status));
}

/**
 * free2darr - free 2d array.
 * @arr: 2d array to free.
 * Return: Nothing (void function)
 */
void free2darr(char **arr)
{
	int i = 0;

	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
}
/**
 * main - Entry point.
 * @argc: number of command line arguments.
 * @argv: the command line arguments.
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
	char *line = NULL;
	char **args = NULL;
	int status = 0;
	int interactive = isatty(STDIN_FILENO);

	if (argc == 1)
	{
		while (1)
		{
			if (interactive)
				_sputs("#cisfun$ ");
			line = read_commands(status);
			if (!line)
			{
				if (interactive)
					_putchar('\n');
				break;
			}
			args = _strsplit(line);
			free(line);
			if (args[0] != NULL)
			{
				if (_strcmp(args[0], "env") == 0)
				{
					print_env();
					status = 0;
				}
				else
					status = execute_command(args, argv[0]);
			}
			free2darr(args);
			free(args);
		}
	}

	return (status);
}
