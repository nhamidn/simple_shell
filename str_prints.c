#include "main.h"

/**
 * _print_not_found - print not found message if
 * command is not found
 * @prog_name: name of program
 * @cmd: command
 * Return: Nothing (void function)
 */
void _print_not_found(char *prog_name, char *cmd)
{
	char *err_msg = NULL;
	int err_len = _strlen(prog_name) + _strlen(cmd) + 17;

	err_msg = malloc(sizeof(char) * (err_len + 1));
	if (err_msg == NULL)
		exit(EXIT_FAILURE);
	_strcpy(err_msg, prog_name);
	_strcat(err_msg, ": 1: ");
	_strcat(err_msg, cmd);
	_strcat(err_msg, ": not found\n");
	write(STDERR_FILENO, err_msg, err_len);
	free(err_msg);
}

/**
 * _puts - Prints a string followed by newline
 * @s: string to print
 * Return: Nothing (void function).
 */
void _puts(char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		_putchar(s[i]);
		i++;
	}
	_putchar('\n');
}

/**
 * _sputs - Prints a string
 * @s: string to print
 * Return: Nothing (void function).
 */
void _sputs(char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		_putchar(s[i]);
		i++;
	}
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

