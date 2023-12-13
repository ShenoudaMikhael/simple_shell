/**
 * _strncmp - function
 * @s1: input
 * @s2: input
 * @n: input
 * Return: always 0
*/
int _strncmp(const char *s1, const char *s2, int n)
{


	while (n > 0 && (*s1 != '\0' || *s2 != '\0'))
	{
		if (*s1 != *s2)
		{
			return (*s1 - *s2);
		}
		s1++;
		s2++;
		n--;
	}
	return (0);
}
