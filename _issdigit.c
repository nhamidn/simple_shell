#include "main.h"

/**
 * _issdigit - check string if is only digits
 * @s: element to test.
 * Return: 1 if s contains only digits, otherwise 0.
 */
int _issdigit(char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}
