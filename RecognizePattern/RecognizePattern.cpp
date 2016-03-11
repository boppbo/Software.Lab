// RecognizePattern.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "RecognizePattern.h"


// This is an example of an exported variable
RECOGNIZEPATTERN_API int nRecognizePattern=0;

// This is an example of an exported function.
RECOGNIZEPATTERN_API int fnRecognizePattern(void)
{
    return 42;
}

// This is the constructor of a class that has been exported.
// see RecognizePattern.h for the class definition
CRecognizePattern::CRecognizePattern()
{
    return;
}
