#include "stdafx.h"
#include "wordCount.h"

RECOGNIZEPATTERN_API int count(char * input)
{
	int result = 0;

	if (input != nullptr)
	{
		bool currentlyInWord = false;
		for (unsigned int i = 0; i < strlen(input); i++)
		{
			char currentChar = input[i];

			if (currentChar != ' ' && !currentlyInWord)
				result++;

			currentlyInWord = (currentChar != ' ');
		}
	}

	return result;
}
