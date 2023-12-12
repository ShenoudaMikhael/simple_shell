#include "main.h"
void freeTokens(char **tokens, int tokenCount)
{
	int i;

	for (i = 0; i < tokenCount; i++)
	{
		free(tokens[i]);
	}
	free(tokens);
}
