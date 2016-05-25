#include "stdafx.h"
#include "../RegualExpressions/Alternative.h"
#include "../RegualExpressions/Character.h"
#include "../RegualExpressions/Concatenation.h"
#include "../RegualExpressions/Phi.h"
#include "../RegualExpressions/Star.h"

using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace RegularExpressionsTests
{		
	TEST_CLASS(simplifyRegexTests)
	{
	public:
		
		TEST_METHOD(simplifyAlternativeBug1)
		{
			// a + (a+b)
			RE* re = new Alt(
				new Ch('a'),
				new Alt(new Ch('a'), new Ch('b')));
			RE* simp = re->simp();
			Assert::IsTrue(simp->equals(new Alt(new Ch('a'), new Ch('b'))));
			Assert::AreEqual(simp->pretty(), string("(a+b)"));

		}

		TEST_METHOD(simplifyAlternativeBug2)
		{
			// (a+b) + a
			RE* re = new Alt(
				new Alt(new Ch('a'), new Ch('b')),
				new Ch('a'));
			RE* simp = re->simp();
			Assert::IsTrue(simp->equals(new Alt(new Ch('a'), new Ch('b'))));
			Assert::AreEqual(simp->pretty(), string("(a+b)"));
		}

		TEST_METHOD(simplifySixthRegexRule)
		{
			RE* re = new Alt(new Phi(), new Ch('c'));
			Assert::AreEqual(re->pretty(), string("(phi+c)"));

			RE* simp = re->simp();
			Assert::IsTrue(simp->equals(new Ch('c')));
			Assert::AreEqual(simp->pretty(), string("c"));
		}

		TEST_METHOD(simplifySeventhRegexRule)
		{
			RE* re = new Alt(new Ch('c'), new Phi());
			Assert::AreEqual(re->pretty(), string("(c+phi)"));

			RE* simp = re->simp();
			Assert::IsTrue(simp->equals(new Ch('c')));
			Assert::AreEqual(simp->pretty(), string("c"));
		}

		TEST_METHOD(simplifyFourthRegexRule)
		{
			RE* re = new Star(new Star(new Ch('c')));
			Assert::AreEqual(re->pretty(), string("c**"));

			RE* simp = re->simp();
			Assert::IsTrue(simp->equals(new Star(new Ch('c'))));
			Assert::AreEqual(simp->pretty(), string("c*"));
		}

		TEST_METHOD(simplifyPhiStarToEpsilon)
		{
			RE* re = new Star(new Phi());
			Assert::AreEqual(re->pretty(), string("phi*"));

			RE* simp = re->simp();
			Assert::IsTrue(simp->equals(new Epsilon()));
			Assert::AreEqual(simp->pretty(), string("eps"));
		}

		TEST_METHOD(simplifyFirstRegexRule)
		{
			RE* re = new Concatenation(new Epsilon(), new Ch('c'));
			Assert::AreEqual(re->pretty(), string("(epsc)"));

			RE* simp = re->simp();
			Assert::IsTrue(simp->equals(new Ch('c')));
			Assert::AreEqual(simp->pretty(), string("c"));
		}

		TEST_METHOD(simplifySecondRegexRule)
		{
			RE* re = new Concatenation(new Phi(), new Ch('c'));
			Assert::AreEqual(re->pretty(), string("(phic)"));

			RE* simp = re->simp();
			Assert::IsTrue(simp->equals(new Phi()));
			Assert::AreEqual(simp->pretty(), string("phi"));
		}

		TEST_METHOD(simplifyThirdRegexRule)
		{
			RE* re = new Star(new Phi());
			Assert::AreEqual(re->pretty(), string("phi*"));

			RE* simp = re->simp();
			Assert::IsTrue(simp->equals(new Eps()));
			Assert::AreEqual(simp->pretty(), string("eps"));
		}

		TEST_METHOD(simplifyFifthRegexRule)
		{
			RE* re = new Alt(new Character('c'), new Character('c'));
			Assert::AreEqual(re->pretty(), string("(c+c)"));

			RE* simp = re->simp();
			Assert::IsTrue(simp->equals(new Character('c')));
			Assert::AreEqual(simp->pretty(), string("c"));
		}

		TEST_METHOD(simplifySulzmanBugInAlternative)
		{
			// c+c* -> c*
			// 
			RE* re = new Alt(new Star(new Ch('c')), new Ch('c'));
			Assert::AreEqual(re->pretty(), string("(c*+c)"));

			RE* simp = re->simp();
			Assert::IsTrue(simp->equals(new Star(new Ch('c'))));
			Assert::AreEqual(simp->pretty(), string("c*"));
		}
	};
}