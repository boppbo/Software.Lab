#include "stdafx.h"
#include "breakIntoWords.h"

/// <summary>	Saves a word into the array. </summary>
///
/// <remarks>	Boris, 23.03.2016. </remarks>
///
/// <param name="line">				The line. </param>
/// <param name="currWord">			The curr word. </param>
/// <param name="maxWords">			The maximum words. </param>
/// <param name="currWordStart">	The curr word start. </param>
/// <param name="currWordEnd">  	The curr word end. </param>
/// <param name="words">			The words. </param>
static void saveWord(char* line, int* currWord, int maxWords, int currWordStart, int currWordEnd, char* words[])
{
	if (*currWord >= maxWords || currWordStart >= currWordEnd)
		return;

	words[*currWord] = &line[currWordStart];
	line[currWordEnd] = '\0';
	(*currWord)++;
}

/// <summary>	Break string into words. </summary>
///
/// <remarks>	Boris, 23.03.2016. </remarks>
///
/// <param name="line">	   	The line. </param>
/// <param name="maxwords">	The maxwords. </param>
/// <param name="words">   	The words. </param>
///
/// <returns>	An int. </returns>
RECOGNIZEPATTERN_API int breakIntoWords(char *line, int maxwords, char *words[])
{
	int result = 0;

	if (line != NULL)
	{
		int lastWordStart = 0;
		unsigned int lineLen = strlen(line);

		// go through the line
		for (unsigned int i = 0; i <= lineLen; i++)
		{
			char currentChar = line[i];

			// a space divides words,
			// furthermore we might have a word at the end of the string
			if (currentChar == ' ' || i == lineLen)
			{
				// will throw away whitespace as the lastwordstart will then be
				// bigger or equal than current word start 
				saveWord(line, &result, maxwords, lastWordStart, i, words);
				lastWordStart = i + 1;
			}
		}
	}

	return result;
}

