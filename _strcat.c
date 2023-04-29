#include "main.h"

/**
 * _strcat - concatenates two strings
 * @dest: destination string
 * @src: source string
 * Return: dest string.
 */
char *_strcat(char *dest, char *src)
{
	int i;
	int k;

	k = 0;
	i = 0;
	while (dest[i] != '\0')
		i++;
	while (src[k] != '\0')
	{
		dest[i] = src[k];
		i++;
		k++;
	}
	dest[i] = '\0';
	return (dest);
}
