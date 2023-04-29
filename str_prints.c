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
	_sputs(prog_name);
	_sputs(": 1: ");
	_sputs(cmd);
	_puts(": not found");
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

