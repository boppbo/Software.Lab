#include "stdafx.h"
#include "switchLowHighByte.h"

/// <summary>	Switch low high byte. </summary>
///
/// <remarks>	Boris, 23.03.2016. </remarks>
///
/// <param name="i">	The integer. </param>
///
/// <returns>	The new integer. </returns>
BITMANIPULATION_API short int switchLowHighByte(short int i)
{
	auto low = (unsigned short int) i & 0x00FF;
	auto high = (unsigned short int) i & 0xFF00;

	return (low << 8) | (high >> 8);
}
