#include "stdafx.h"
 
extern "C" {
#include "../BitManipulation/switchLowHighByte.h"
}

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace BitmanipulationTests
{
	TEST_CLASS(SwitchLowHighByteTests)
	{
	public:

		TEST_METHOD(switchLowHighByteShouldReturnPositiveValue)
		{
			Assert::IsTrue(0x3412 == switchLowHighByte(0x1234));
		}

		TEST_METHOD(switchLowHighByteShouldReturnInputForSecondCall)
		{
			Assert::IsTrue(0x1234 == switchLowHighByte(switchLowHighByte(0x1234)));
		}

	};
}