#include "stdafx.h"
#include "../CustomStrings/CustomStrings.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CustomStringsTests
{
	TEST_CLASS(InitializationTests)
	{
	public:

		TEST_METHOD(TestDefaultConstructor)
		{
			String s;
		}

		TEST_METHOD(TestCharConstructor)
		{
			String s('a');
			Assert::AreEqual(s[0], 'a');
			Assert::AreEqual(s[1], '\0');
		}

		TEST_METHOD(TestCharPointerConstructor)
		{
			String s("Hello");
			Assert::AreEqual(s[0], 'H');
			Assert::AreEqual(s[1], 'e');
			Assert::AreEqual(s[2], 'l');
			Assert::AreEqual(s[3], 'l');
			Assert::AreEqual(s[4], 'o');
			Assert::AreEqual(s[5], '\0');
		}

		TEST_METHOD(TestCopyConstructor)
		{
			String s1("Hello");
			String s2(s1);

			Assert::AreEqual(s2[0], 'H');
			Assert::AreEqual(s2[1], 'e');
			Assert::AreEqual(s2[2], 'l');
			Assert::AreEqual(s2[3], 'l');
			Assert::AreEqual(s2[4], 'o');
			Assert::AreEqual(s2[5], '\0');
		}

	};
}