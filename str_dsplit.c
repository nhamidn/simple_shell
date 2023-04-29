#include "main.h"

/**
 * _dsplit - split a string using a delemiter.
 * @str: string to split
 * @d: delemiter char
 * Return: pointer to new 2d array.
 */
char **_dsplit(char *str, char d)
{
	char **dest = NULL;
	int i, j, k, n, m, count = 0;

	for (i = 0; str[i]; i++)
	{
		if (str[i] == d)
			count++;
	}
	dest = (char **)malloc((count + 2) * sizeof(char *));
	if (dest == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i])
	{
		n = 0;
		while (str[i + n] && str[i + n] != d)
			n++;

		dest[j] = (char *)malloc(sizeof(char) * (n + 1));
		if (dest[j] == NULL)
		{
			for (k = 0; k < j; k++)
				free(dest[k]);
			free(dest);
			return (NULL);
		}

		for (m = 0; m < n; m++)
			dest[j][m] = str[i + m];
		dest[j][n] = '\0';
		j++;

		i += n;
		if (str[i])
			i++;
	}
	dest[j] = NULL;
	return (dest);
}
