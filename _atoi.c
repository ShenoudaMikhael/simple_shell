#include "main.h"
/**
 * _atoi - extract numbers from string
 * @s: string to examine
 * Return: int
 */
int _atoi(char *s)
{
	int i, neg;
	signed int num;

	i = 0;
	num = 0;
	neg = 1;
	while (s[i] != '\0')
	{
		if (s[i - 1] == 45)
		{

			neg *= -1;
		}
		if (s[i] >= 48 && s[i] <= 57)
		{

			num *= 10;
			num = num + ((s[i] - 48) * neg);
		}
		else if (num != 0)
		{

			return (-1);
		}

		i++;
	}

	return (num);
}
