#include "main.h"
/**
 * _freeTokens - free 2d array memory
 * @tokens: input
 * @tokenCount: input
 * Return: input
*/
void _freeTokens(char **tokens, int tokenCount)
{
	int i;

	for (i = 0; i < tokenCount; i++)
	{
		free(tokens[i]);
	}
	free(tokens);
}
