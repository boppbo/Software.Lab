#include "stdafx.h"
#include "switchLowHighByte.h"

BITMANIPULATION_API short int switchLowHighByte(short int i)
{
	short int low = i & 0x00FF;
	short int high = i & 0xFF00;

	return (low << 8) | (high >> 8);
}