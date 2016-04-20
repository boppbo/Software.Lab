#include "stdafx.h"
#include "stdbool.h"
#include "longestSuffix.h"

/// <summary>	Query if this object contains pattern. </summary>
///
/// <remarks>	Boris, 4/20/2016. </remarks>
///
/// <param name="input">			[in,out] If non-null, the input. </param>
/// <param name="inputLen">			Length of the input. </param>
/// <param name="pattern">			[in,out] If non-null, specifies the pattern. </param>
/// <param name="patternLen">   	Length of the pattern. </param>
/// <param name="patternStarts">	The pattern starts. </param>
///
/// <returns>	true if it succeeds, false if it fails. </returns>
static bool containsPattern(char* input, size_t inputLen, char* pattern, size_t patternLen, int patternStarts)
{
	//iterate trough the pattern 
	for (unsigned int i = 0; i < patternLen; i++)
	{
		// search for the pattern at the specified position (early exit)
		if (input[patternStarts + i] != pattern[i])
		{
			// pattern incomplete
			return false;
		}
	}

	// the pattern was complete
	return true;
}

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

	// search from the end of the string for the pattern
	// We can start searching subtracting the patten length
	for (int i = (int)inputLen - (int)patternLen; i >= 0; i--)
	{
		//if the pattern is complete return the position
		if (containsPattern(input, inputLen, pattern, patternLen, i))
			return &input[i + patternLen];

		// otherwise continue looking at the previous (string-wise) position.
	}

	// input doesn't contain pattern -> return whole input
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
