#include "stdafx.h"
#include "stdbool.h"
#include "longestSuffix.h"

/// <summary>	Extracts the longest suffix for the given pattern. </summary>
///
/// <remarks>	Boris, 23.03.2016. </remarks>
///
/// <param name="input">  	The input. </param>
/// <param name="pattern">	Specifies the pattern. </param>
///
/// <returns>	null if it fails, else a pointer to a char. </returns>
static char* extractInternal(char* input, char* pattern)
{
	if (input == NULL)
		return "";
	if (pattern == NULL)
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

/// <summary>	Extracts the longest suffix </summary>
///
/// <remarks>	Boris, 22.03.2016. </remarks>
///
/// <param name="input">	The input. </param>
///
/// <returns>	null if it fails, else a pointer to a char. </returns>
RECOGNIZEPATTERN_API char* extract(char * input)
{
	return extractInternal(input, "::");
}

/// <summary>	Extracts the longest suffix. </summary>
///
/// <remarks>	Boris, 22.03.2016. </remarks>
///
/// <param name="input"> 	The input. </param>
/// <param name="output">	The output. </param>
RECOGNIZEPATTERN_API void extract2(char* input, char ** output)
{
	if (output == NULL)
		return;

	*output = extract(input);
}
