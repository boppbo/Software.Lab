#include "stdafx.h"
#include "breakIntoWords.h"

static void saveWord(char* line, int* currWord, int maxWords, int currWordStart, int currWordEnd, char* words[])
{
	if (*currWord >= maxWords || currWordStart >= currWordEnd)
		return;

	words[*currWord] = &line[currWordStart];
	line[currWordEnd] = '\0';
	(*currWord)++;
}

RECOGNIZEPATTERN_API int breakIntoWords(char *line, int maxwords, char *words[])
{
	int result = 0;

	if (line != nullptr)
	{
		int lastWordStart = 0;
		unsigned int lineLen = strlen(line);
		for (unsigned int i = 0; i <= lineLen; i++)
		{
			char currentChar = line[i];

			if (currentChar == ' ' || i == lineLen)
			{
				saveWord(line, &result, maxwords, lastWordStart, i, words);
				lastWordStart = i + 1;
			}
		}
	}

	return result;
}

