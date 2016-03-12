#include "stdafx.h"
#include "longestSuffix.h"

static char* extract(char* input, char* pattern)
{
	if (input == nullptr)
		return "";
	if (pattern == nullptr)
		return input;

	size_t inputLen = strlen(input);
	size_t patternLen = strlen(pattern);
	if (inputLen < patternLen)
		return input;

	for (int i = (int)inputLen - (int)patternLen; i >= 0; i--)
	{
		bool complete = true;
		for (unsigned int j = 0; j < patternLen; j++)
		{
			if (input[i + j] != pattern[j])
			{
				complete = false;
				break;
			}
		}

		if (complete)
			return &input[i + patternLen];
	}

	return input;
}

RECOGNIZEPATTERN_API char * extract(char * input)
{
	return extract(input, "::");
}

RECOGNIZEPATTERN_API void extract2(char* input, char ** output)
{
	if (output == nullptr)
		return;

	*output = extract(input);
}
