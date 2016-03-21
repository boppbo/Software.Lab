#include "stdafx.h"
#include "../RecognizePattern/breakIntoWords.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace RecognizePatternTests
{
	TEST_CLASS(BreakIntoWordsTest)
	{
	public:

		TEST_METHOD(breakIntoWordsForEmptyString)
		{
			char* words[1] = { nullptr };
			char str[] = "";

			Assert::AreEqual(0, breakIntoWords(str, 1, words));
			Assert::AreEqual(nullptr, words[0]);
		}

		TEST_METHOD(breakIntoWordsForSingleWord)
		{
			char* words[1];
			char str[] = "Hallo";

			Assert::AreEqual(1, breakIntoWords(str, 1, words));
			Assert::AreEqual("Hallo", words[0]);
		}

		TEST_METHOD(breakIntoWordsForWhitespaceAndSingleWord)
		{
			char* words[1];
			char str[] = "  Hallo";

			Assert::AreEqual(1, breakIntoWords(str, 1, words));
			Assert::AreEqual("Hallo", words[0]);
		}

		TEST_METHOD(breakIntoWordsForSingleWordAndWhitespace)
		{
			char* words[1];
			char str[] = "Hallo  ";

			Assert::AreEqual(1, breakIntoWords(str, 1, words));
			Assert::AreEqual("Hallo", words[0]);
		}

		TEST_METHOD(breakIntoWordsForSingleWordAndMixedWhitespace)
		{
			char* words[1];
			char str[] = "  Hallo  ";

			Assert::AreEqual(1, breakIntoWords(str, 1, words));
			Assert::AreEqual("Hallo", words[0]);
		}

		TEST_METHOD(breakIntoWordsForTwoWords)
		{
			char* words[2];
			char str[] = "Hal lo";

			Assert::AreEqual(2, breakIntoWords(str, 2, words));
			Assert::AreEqual("Hal", words[0]);
			Assert::AreEqual("lo", words[1]);
		}

		TEST_METHOD(breakIntoWordsForWhitespaceAndTwoWords)
		{
			char* words[2];
			char str[] = " Hal lo";

			Assert::AreEqual(2, breakIntoWords(str, 2, words));
			Assert::AreEqual("Hal", words[0]);
			Assert::AreEqual("lo", words[1]);
		}

		TEST_METHOD(breakIntoWordsForTwoWordsAndWhitespace)
		{
			char* words[2];
			char str[] = "Hal lo ";

			Assert::AreEqual(2, breakIntoWords(str, 2, words));
			Assert::AreEqual("Hal", words[0]);
			Assert::AreEqual("lo", words[1]);
		}

		TEST_METHOD(breakIntoWordsForTwoWordsAndMixedWhitespace)
		{
			char* words[2];
			char str[] = " Hal lo  ";

			Assert::AreEqual(2, breakIntoWords(str, 2, words));
			Assert::AreEqual("Hal", words[0]);
			Assert::AreEqual("lo", words[1]);
		}

		TEST_METHOD(breakIntoWordsForSmallArr)
		{
			char* words[] = {nullptr, nullptr, nullptr, nullptr};
			char str[] = " Hal  lo We lt ";

			Assert::AreEqual(2, breakIntoWords(str, 2, words));
			Assert::AreEqual("Hal", words[0]);
			Assert::AreEqual("lo", words[1]);
			Assert::AreEqual(nullptr, words[2]);
			Assert::AreEqual(nullptr, words[3]);
		}

	};
}