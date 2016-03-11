// BitManipulation.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "BitManipulation.h"


// This is an example of an exported variable
BITMANIPULATION_API int nBitManipulation=0;

// This is an example of an exported function.
BITMANIPULATION_API int fnBitManipulation(void)
{
    return 42;
}

// This is the constructor of a class that has been exported.
// see BitManipulation.h for the class definition
CBitManipulation::CBitManipulation()
{
    return;
}
