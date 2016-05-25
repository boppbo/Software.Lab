
// Ein moeglicher Rahmen fuer Aufgabe 4, zweite Teilaufgabe,
// uebersetze regulaeren Ausdruck in einen NFA.
// Der Einfachheit in ein .h File gepackt.

#include "stdafx.h"
#include "../RegualExpressions/Alternative.h"
#include "../RegualExpressions/Character.h"
#include "../RegualExpressions/Concatenation.h"
#include "../RegualExpressions/Phi.h"
#include "../RegualExpressions/Star.h"
#include "../RegualExpressions/NonDeterministicFiniteStateAutomation.h"

/// <summary>	An identifier provider. </summary>
class IdProvider
{
private:
	int _id = 0;
public:

	/// <summary>	Peek current. </summary>
	///
	/// <returns>	An int. </returns>
	int peekCurrent() const { return this->_id; }

	/// <summary>	Gets the current. </summary>
	///
	/// <returns>	The current. </returns>
	int getCurrent() { return this->_id++; }
};

/// <summary>	The regualexpressions api. </summary>
class REGUALEXPRESSIONS_API FiniteStateAutomationFactory {
protected:

	/// <summary>	Gets a nfa. </summary>
	///
	/// <param name="regularExpression">	[in,out] The regular expression. </param>
	/// <param name="idProvider">			[in,out] The identifier provider. </param>
	///
	/// <returns>	The nfa. </returns>
	NFA getNFA(RE &regularExpression, IdProvider &idProvider);
public:

	/// <summary>	Gets a nfa. </summary>
	///
	/// <param name="regularExpression">	[in,out] The regular expression. </param>
	///
	/// <returns>	The nfa. </returns>
	NFA getNFA(RE &regularExpression);
};