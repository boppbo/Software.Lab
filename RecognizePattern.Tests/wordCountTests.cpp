#include "stdafx.h"
#include "../RecognizePattern/wordCount.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace RecognizePatternTests
{
	TEST_CLASS(WordCountTest)
	{
	public:

		TEST_METHOD(wordCountForEmptyString)
		{
			Assert::AreEqual(0, count(""));
		}

		TEST_METHOD(wordCountForSingleWord)
		{
			Assert::AreEqual(1, count("Hallo"));
		}

		TEST_METHOD(wordCountForWhitespaceAndSingleWord)
		{
			Assert::AreEqual(1, count("  Hallo"));
		}

		TEST_METHOD(wordCountForSingleWordAndWhitespace)
		{
			Assert::AreEqual(1, count("Hallo  "));
		}

		TEST_METHOD(wordCountForSingleWordAndMixedWhitespace)
		{
			Assert::AreEqual(1, count("  Hallo  "));
		}

		TEST_METHOD(wordCountForTwoWords)
		{
			Assert::AreEqual(2, count("Hal lo"));
		}

		TEST_METHOD(wordCountForWhitespaceAndTwoWords)
		{
			Assert::AreEqual(2, count(" Hal lo"));
		}

		TEST_METHOD(wordCountForTwoWordsAndWhitespace)
		{
			Assert::AreEqual(2, count("Hal lo "));
		}

		TEST_METHOD(wordCountForTwoWordsAndMixedWhitespace)
		{
			Assert::AreEqual(2, count(" Hal lo  "));
		}
	};
}