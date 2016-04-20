#include "stdafx.h"
#include "stdbool.h"
#include "wordCount.h"

/// <summary>	Counts the words in the given input. </summary>
///
/// <remarks>	Boris, 23.03.2016. </remarks>
///
/// <param name="input">	The input. </param>
///
/// <returns>	The count. </returns>
RECOGNIZEPATTERN_API int count(char * input)
{
	int result = 0;

	if (input != NULL)
	{
		bool currentlyInWord = false;
		// go trough the string
		for (unsigned int i = 0; i < strlen(input); i++)
		{
			char currentChar = input[i];

			// increases the count when there aren't multiple spaces in series
			if (currentChar != ' ' && !currentlyInWord)
				result++;
			currentlyInWord = (currentChar != ' ');
		}
	}

	return result;
}
