#include "stdafx.h"

extern "C" {
#include "../BitManipulation/serialization.h"
}

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace BitmanipulationTests
{
	TEST_CLASS(SerializationTests)
	{
	public:

		TEST_METHOD(serializationAndDeserializationShouldReturnOriginalValue)
		{
			Status state = Finish, stateTwo;
			Numbers no = Fifteen, noTwo;

			short buf;
			serialize(state, no, &buf);
			deserialize(buf, &stateTwo, &noTwo);

			Assert::IsTrue(state == stateTwo);
			Assert::IsTrue(no == noTwo);
		}
	};
}