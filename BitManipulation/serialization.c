#include "stdafx.h"
#include "serialization.h"

/// <summary>	serialize this object to the given integer. </summary>
///
/// <remarks>	Boris, 22.03.2016. </remarks>
///
/// <param name="s">   	The Status to process. </param>
/// <param name="n">   	The Numbers to process. </param>
/// <param name="data">	The data. </param>
BITMANIPULATION_API void serialize(Status s, Numbers n, short int * data)
{
	*data = s | n << 8;
}

/// <summary>	deserialize this object to the given integer. </summary>
///
/// <remarks>	Boris, 22.03.2016. </remarks>
///
/// <param name="data">	The data. </param>
/// <param name="s">   	The Status to process. </param>
/// <param name="n">   	The Numbers to process. </param>
BITMANIPULATION_API void deserialize(short int data, Status * s, Numbers * n)
{
	*s = (Status)(data & 0x00FF);
	*n = (Numbers)(data >> 8);
}