#include "main.h"

/**
 * _strcmp - compare two strings.
 * @s1: pointer to first string.
 * @s2: pointer to second string.
 * Return: the difference between the two strings.
 */
int _strcmp(char *s1, char *s2)
{
	char *str1;
	char *str2;

	str1 = s1;
	str2 = s2;
	while (*str1 || *str2)
	{
		if (*str1 != *str2)
		{
			return (*str1 - *str2);
		}
		str1++;
		str2++;
	}
	return (0);
}
