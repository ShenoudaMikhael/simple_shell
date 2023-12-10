
/**
 * _strcmp - compare 2 strings
 * @env: the string 1
 * @s: the string 2
 * Return: int
 */
int _strcmp(char *env, char *s)
{
	int i, result = 0;

	for (i = 0; env[i] && s[i]; i++)
	{

		if (env[i] != s[i])
		{
			result = 1;
			break;
		}
	}

	return (result);
}
