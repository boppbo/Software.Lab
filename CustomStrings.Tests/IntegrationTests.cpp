#include "stdafx.h"
#include "../CustomStrings/CustomStrings.h"

using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CustomStringsTests
{
	TEST_CLASS(IntegrationTests)
	{
	public:

		TEST_METHOD(stringShouldPassGivenTestFrame)
		{
			String s1;
			String s2("Hello");
			String s3(s2);
			s1 += s2; s2 = s3;
			
			stringstream foo;
			foo << s2 << endl;
			foo << s2[2] << endl;
			
			Assert::AreEqual(foo.str(), string("Hello\nl\n"));
		}

		TEST_METHOD(stringShouldSupportArrayIndexOperator)
		{
			String s("Hello");
			s[1] = 'a';

			Assert::AreEqual(s[0], 'H');
			Assert::AreEqual(s[1], 'a');
			Assert::AreEqual(s[2], 'l');
			Assert::AreEqual(s[3], 'l');
			Assert::AreEqual(s[4], 'o');
			Assert::AreEqual(s[5], '\0');
		}
	};
}