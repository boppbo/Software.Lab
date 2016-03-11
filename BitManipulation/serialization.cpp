#include "stdafx.h"
#include "serialization.h"

BITMANIPULATION_API void serialize(Status s, Numbers n, short int * data)
{
	*data = s | n << 8;
}

BITMANIPULATION_API void deserialize(short int data, Status * s, Numbers * n)
{
	*s = static_cast<Status>(data & 0x00FF);
	*n = static_cast<Numbers>(data >> 8);
}