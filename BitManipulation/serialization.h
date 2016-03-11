#pragma once

// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the BITMANIPULATION_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// BITMANIPULATION_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef BITMANIPULATION_EXPORTS
#define BITMANIPULATION_API __declspec(dllexport)
#else
#define BITMANIPULATION_API __declspec(dllimport)
#endif

typedef enum {
	Stop = 0,
	Start = 1,
	Finish = 5,
	Fail = 255
} Status;


typedef enum {
	One = 1,
	Fifteen = 15,
	Last = 255
} Numbers;

BITMANIPULATION_API void serialize(Status s, Numbers n, short int * data);

BITMANIPULATION_API void deserialize(short int data, Status * s, Numbers * n);
