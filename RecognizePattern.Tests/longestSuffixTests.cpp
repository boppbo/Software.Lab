#include "stdafx.h"
#include "../RecognizePattern/longestSuffix.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace RecognizePatternTests
{
	TEST_CLASS(LongestSuffixTests)
	{
	public:

		TEST_METHOD(extractSuffixFirstTest)
		{
			Assert::AreEqual("o", extract("Ha::ll::o"));
		}

		TEST_METHOD(extractSuffixSecondTest)
		{
			Assert::AreEqual("11", extract("47::11"));
		}

		TEST_METHOD(extract2SuffixFirstTest)
		{
			char* result;
			extract2("Ha::ll::o", &result);
			Assert::AreEqual("o", result);
		}

		TEST_METHOD(extract2SuffixSecondTest)
		{
			char* result;
			extract2("47::11", &result);
			Assert::AreEqual("11", result);
		}
	};
}