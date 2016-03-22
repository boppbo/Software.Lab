#pragma once

// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the RECOGNIZEPATTERN_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// RECOGNIZEPATTERN_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef RECOGNIZEPATTERN_EXPORTS
#define RECOGNIZEPATTERN_API __declspec(dllexport)
#else
#define RECOGNIZEPATTERN_API __declspec(dllimport)
#endif

/// <summary>	Break string into words. </summary>
///
/// <remarks>	Boris, 22.03.2016. </remarks>
///
/// <param name="line">	   	The line. </param>
/// <param name="maxwords">	The maxwords. </param>
/// <param name="words">   	The words. </param>
///
/// <returns>	The result count. </returns>
RECOGNIZEPATTERN_API int breakIntoWords(char *line, int maxwords, char *words[]);