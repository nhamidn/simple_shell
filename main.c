#include "main.h"

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

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	pid_t pid;

	while (1)
	{
		_puts("#cisfun$ ");
		break;
	}

	return (0);
}
