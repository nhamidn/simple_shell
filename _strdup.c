#include "main.h"

/**
 * _strdup - save a copy of a string.
 * @s: string to copy.
 * Return: Pointer to new string.
 */
char *_strdup(char *s)
{
	int i;
	size_t l = 0;
	char *dest;

	l = _strlen(s);
	dest = (char *)malloc(sizeof(char) * (l + 1));
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
