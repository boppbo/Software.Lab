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

/// <summary>	Extracts the given input. </summary>
///
/// <remarks>	Boris, 23.03.2016. </remarks>
///
/// <param name="input">	The input. </param>
///
/// <returns>	null if it fails, else a pointer to a char. </returns>
RECOGNIZEPATTERN_API char* extract(char* input);

/// <summary>	Extracts the 2. </summary>
///
/// <remarks>	Boris, 23.03.2016. </remarks>
///
/// <param name="input"> 	The input. </param>
/// <param name="output">	The output. </param>
RECOGNIZEPATTERN_API void extract2(char* input, char** output);