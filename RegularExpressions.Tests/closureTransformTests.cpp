#include "stdafx.h"
#include "../RegualExpressions/Alternative.h"
#include "../RegualExpressions/Character.h"
#include "../RegualExpressions/Concatenation.h"
#include "../RegualExpressions/Phi.h"
#include "../RegualExpressions/Star.h"
#include "../RegualExpressions/NonDeterministicFIniteStateAutomation.h"
#include "../RegualExpressions/DeterministicFiniteStateAutomation.h"
#include "../RegualExpressions/Transform.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace RegularExpressionsTests
{
	TEST_CLASS(simplifyRegexTests)
	{
	private:
		FiniteStateAutomationFactory factory;

		/// <summary>
		/// Ein Testfall besteht aus einem regulaeren Ausdruck (RE)
		/// und einem Eingabestring.
		/// 
		/// Testorakel match ueberprueft ob string s enthalten in regex r.
		/// 
		/// closure und Tranformater RE -> NFA korrekt, falls Testorakel gleiches Ergebnis liefert wie
		/// Ausfuehrung des resultierenden NFA.
		/// </summary>
		///
		/// <param name="r">	[in,out] If non-null, the RE to process. </param>
		/// <param name="s">	The std::string to process. </param>
		bool containsWord(RE* regularExpression, std::string word) {
			NFA nfa = factory.getNFA(*regularExpression);
			FSA fsa(nfa);

			return fsa.run(word);
		}

	public:

		TEST_METHOD(fsaTestMethod1)
		{
			RE* r = new Alt(new Phi(), new Ch('c'));

			Assert::IsFalse(containsWord(r, ""));
			Assert::IsTrue(containsWord(r, "c"));
			Assert::IsFalse(containsWord(r, "ab"));
		}

		TEST_METHOD(fsaTestMethod2)
		{
			RE* r = new Star(new Ch('a'));

			Assert::IsTrue(containsWord(r, ""));
			Assert::IsTrue(containsWord(r, "a"));
			Assert::IsTrue(containsWord(r, "aaaaaaaaaaaaaaaa"));
			Assert::IsFalse(containsWord(r, "b"));

		}

		TEST_METHOD(fsaTestMethod3)
		{
			RE* r = new Star(new Conc(new Ch('a'), new Ch('b')));

			Assert::IsTrue(containsWord(r, ""));
			Assert::IsTrue(containsWord(r, "ab"));
			Assert::IsTrue(containsWord(r, "abab"));
			Assert::IsFalse(containsWord(r, "b"));

		}
	};
}