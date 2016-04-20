#include "stdafx.h"

extern "C" {
#include "../RecognizePattern/longestSuffix.h"
}

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace RecognizePatternTests
{
	TEST_CLASS(LongestSuffixTests)
	{
	public:

		TEST_METHOD(extractSuffixNoPattern)
		{
			Assert::AreEqual("Hallo", extract("Hallo"));
		}

		TEST_METHOD(extractSuffixOnlyPattern)
		{
			Assert::AreEqual("", extract("::"));
		}

		TEST_METHOD(extractSuffixNoSuffix)
		{
			Assert::AreEqual("", extract("Ha::llo::"));
		}

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

		TEST_METHOD(extract2SuffixShouldNotThrowOnInputNullPointer)
		{
			char* result;
			extract2(nullptr, &result);
			Assert::AreEqual("", result);
		}

		TEST_METHOD(extract2SuffixShouldNotThrowOnOutputNullPointer)
		{
			extract2("47::11", nullptr);
		}
	};
}