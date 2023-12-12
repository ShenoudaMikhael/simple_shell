#include "main.h"
/**
 * freeTokens - function
 * @tokens: input
 * @tokenCount: input
 * Return: input
*/
void freeTokens(char **tokens, int tokenCount)
{
	int i;

	for (i = 0; i < tokenCount; i++)
	{
		free(tokens[i]);
	}
	free(tokens);
}
