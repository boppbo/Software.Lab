// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#define WIN32_LEAN_AND_MEAN

#include "targetver.h"

#include <algorithm>
#include <sstream>
#include <string>
#include <vector>
#include <windows.h>

// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the REGUALEXPRESSIONS_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// REGUALEXPRESSIONS_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef REGUALEXPRESSIONS_EXPORTS
#define REGUALEXPRESSIONS_API __declspec(dllexport)
#else
#define REGUALEXPRESSIONS_API __declspec(dllimport)
#endif
