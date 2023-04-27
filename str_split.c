#include "main.h"

/**
 * words_count - count number o words in a string.
 * @str: string to count it words.
 * Return: number of words.
 */
int words_count(char *str)
{
	int i;
	int k;

	i = 0;
	k = 1;
	while (str[i] != '\0' && str[i] != 10)
	{
		if (str[i] == ' ' || str[i] == '\t')
		{
			k++;
			if (i > 0 && (str[i - 1] == ' ' || str[i - 1] == '\t'))
			{
				if (str[i + 1] == '\0' || str[i + 1] == '\n')
					k--;
				k--;
			}
		}
		i++;
	}
	if (str[0] == ' ' || str[0] == '\t')
		k--;
	return (k);
}

/**
 * charcount - count number of chars in a word.
 * @str: string to count it word chars.
 * @i: index of the words to count it chars.
 * Return: number of chars.
 */
int charcount(char *str, int i)
{
	int count;

	count = 0;
	while (str[i] != ' ' && str[i] != '\t' && str[i] != '\0' && str[i] != 10)
	{
		count++;
		i++;
	}
	return (count);
}

/**
 * _strsplit - split 1d string to 2d array..
 * @s: string to split.
 * Return: 2d char array.
 */
char **_strsplit(char *s)
{
	char **st;
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	if (s == NULL)
		return (NULL);
	st = malloc(sizeof(char *) * (words_count(s) + 1));
	if (st == NULL)
		return (NULL);
	while (s[i] != '\0' && s[i] != 10)
	{
		if (s[i] != ' ' && s[i] != '\t')
		{
			k = 0;
			st[j] = malloc(sizeof(char) * charcount(s, i));
			if (st[j] == NULL)
				return (NULL);
			while (s[i] != ' ' && s[i] != '\t' && s[i] != '\0' && s[i] != 10)
				st[j][k++] = s[i++];
			st[j++][k] = '\0';
		}
		else
			i++;
	}
	st[j] = NULL;
	return (st);
}
