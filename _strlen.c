
/**
 * _strlen - get sreing length
 * @s: the string
 * Return: int
 */
int _strlen(char *s)
{
	int len = 0;

	while (s[len] != '\0')
	{
		len++;
	}

	return (len);
}
