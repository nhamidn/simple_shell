#include "main.h"

/**
 * read_commands - Read commands line by line fromt he stdin
 *
 * Return: string containing the first line.
 */
char *read_commands()
{
	char *line = NULL;
	size_t bufsize = 0;

	if (getline(&line, &bufsize, stdin) == -1)
		return (NULL);
	return (line);
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
	int status;

	if (args[0] == NULL)
		return (1);
	pid = fork();
	if (pid == 0)
	{
		if (execve(args[0], args, NULL) == -1)
			perror(prog_name);
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		perror("fork error");
	}
	else
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}

	return (1);
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
	char *line;
	char **args;

	while (1)
	{
		_sputs("#cisfun$ ");
		line = read_commands();
		if (!line)
		{
			_putchar('\n');
			break;
		}
		args = _strsplit(line);
		if (argc > 0)
			execute_command(args, argv[0]);
		free2darr(args);
		free(args);
	}
	return (0);
}
