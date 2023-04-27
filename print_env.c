#include "main.h"

/**
 * print_env - Prints the current environment
 * Return: Nothing (Void function)
 */
void print_env(void)
{
	int i = 0;

	while (environ[i] != NULL)
	{
		_puts(environ[i]);
		i++;
	}
}

