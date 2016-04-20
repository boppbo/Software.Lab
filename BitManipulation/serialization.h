#pragma once

// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the BITMANIPULATION_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// BITMANIPULATION_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef _WIN32
#ifdef BITMANIPULATION_EXPORTS
#define BITMANIPULATION_API __declspec(dllexport)
#else
#define BITMANIPULATION_API __declspec(dllimport)
#endif
#else
#define BITMANIPULATION_API
#endif

/// <summary>	Defines an enum representing the Status. </summary>
///
/// <remarks>	Boris, 22.03.2016. </remarks>
typedef enum {
	Stop = 0,
	Start = 1,
	Finish = 5,
	Fail = 255
} Status;

/// <summary>	Defines an enum representing the Numbers. </summary>
///
/// <remarks>	Boris, 23.03.2016. </remarks>
typedef enum {
	One = 1,
	Fifteen = 15,
	Last = 255
} Numbers;

/// <summary>	serialize this object to the given integer. </summary>
///
/// <remarks>	Boris, 22.03.2016. </remarks>
///
/// <param name="s">   	The Status to process. </param>
/// <param name="n">   	The Numbers to process. </param>
/// <param name="data">	The data. </param>
BITMANIPULATION_API void serialize(Status s, Numbers n, short int * data);

/// <summary>	deserialize this object to the given integer. </summary>
///
/// <remarks>	Boris, 22.03.2016. </remarks>
///
/// <param name="data">	The data. </param>
/// <param name="s">   	The Status to process. </param>
/// <param name="n">   	The Numbers to process. </param>
BITMANIPULATION_API void deserialize(short int data, Status * s, Numbers * n);
