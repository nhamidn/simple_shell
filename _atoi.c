#include "main.h"

/**
 * _atoi - convert a string to an integer
 * @s: the string to convert
 * Return: Integer.
 */
int _atoi(char *s)
{
	int i;
	int result;
	int neg;
	int count;

	i = 0;
	neg = 1;
	result = 0;
	while ((s[i] < 48 || 57 < s[i]) && s[i])
		i++;
	if (s[i] == '\0')
		return (0);
	if (i > 0)
	{
		count = 0;
		while (count < i)
		{
			if (s[count] == '-')
				neg *= -1;
			count++;
		}
	}
	while (s[i])
	{
		if (s[i] < 48 || 57 < s[i])
			return (result);
		result = (result * 10) + ((s[i] - '0') * neg);
		/**
		 * if ((result * 10) == 2147483640 && neg == -1)
		 *	result = ((result * 10) * neg)
		 *		- (s[i] - '0')
		 * else
		 *	result = (result * 10) + (s[i] - '0');
		 */
		i++;
	}
	return (result);
}
