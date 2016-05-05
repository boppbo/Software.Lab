#include "stdafx.h"
#include "TestOrakel.h"
#include "../RegualExpressions/Alternative.h"
#include "../RegualExpressions/Character.h"
#include "../RegualExpressions/Concatenation.h"
#include "../RegualExpressions/Epsilon.h"
#include "../RegualExpressions/Phi.h"
#include "../RegualExpressions/Star.h"
#include "../RegualExpressions/DeterministicFiniteStateAutomation.h"
#include "../RegualExpressions/Transform.h"

using namespace std;

RE* deriv(RE* r, char l) 
{

	switch (r->ofType()) {
	case PhiType:
		return r;
	case EpsType:
		return new Phi();
	case ChType:
		if (static_cast<Ch*>(r)->getChar() == l) {
			return new Eps();
		}
		else {
			return new Phi();
		}
	case StarType: {
		RE* r1 = static_cast<Star*>(r)->getRE();
		return new Conc(deriv(r1, l), r);
	}
	case AltType: {
		RE* r1 = static_cast<Alt*>(r)->getLeft();
		RE* r2 = static_cast<Alt*>(r)->getRight();
		return new Alt(deriv(r1, l), deriv(r2, l));
	}
	case ConcType: {
		RE* r1 = static_cast<Conc*>(r)->getLeft();
		RE* r2 = static_cast<Conc*>(r)->getRight();
		if (r1->containsEps()) {
			return new Alt(new Conc(deriv(r1, l), r2), deriv(r2, l));
		}
		else {
			return new Conc(deriv(r1, l), r2);
		}
	}
	default: throw exception();
	}

}

bool match(RE* r, string s) {
	for (unsigned int i = 0; i < s.length(); i++) {
		r = deriv(r, s[i]);
	}
	return r->containsEps();
}

/// <summary>	Simp fix. </summary>
///
/// <param name="r1">	[in,out] If non-null, the first RE. </param>
///
/// <returns>	null if it fails, else a pointer to a RE. </returns>
RE* simpFix(RE* r1) {
	RE* r2 = r1->simp();

	if (r1->equals(r2))
		return r1;

	return simpFix(r2);
}

/// <summary>	Tests closure transform. </summary>
///
/// <param name="r">	[in,out] If non-null, the RE to process. </param>
/// <param name="s">	The string. </param>
///
/// <returns>	true if the test passes, false if the test fails. </returns>
bool testClosureTransform(RE* r, string s) {
	NFA nfa = FiniteStateAutomationFactory().getNFA(*r);
	FSA fsa(nfa);
	bool b1 = fsa.run(s);
	bool b2 = match(r, s);
	bool b = b1 == b2;

	cout << "Test case: " << r->pretty() << "   " << s << "\n";
	cout << "Test result: " << b << endl;

	return b;
}

/// <summary>
/// Ein Testfall besteht aus einem regulaeren Ausdruck (RE)
/// und einem Eingabestring.
/// 
/// Testorakel match ueberprueft ob string s enthalten in regex r.
/// 
/// Simplifizierer korrekt fuer Testfall, falls Testorakel gleiches Ergebnis liefert fuer
/// Original regex r und simplifizierten regex r->simp()
/// </summary>
///
/// <remarks>	Boris, 4/6/2016. </remarks>
///
/// <param name="r">	[in,out] If non-null, the RE to process. </param>
/// <param name="s">	The std::string to process. </param>
///
/// <returns>	true if the test passes, false if the test fails. </returns>
bool testSimp(RE* r, string s) {
	bool b = (match(r, s) == match(r->simp(), s));

	cout << "Test case: " << r->pretty() << "   " << s << "\n";
	cout << "Test result: " << b << endl;

	return b;
}