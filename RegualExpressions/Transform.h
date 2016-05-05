
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

class IdProvider
{
private:
	int _id = 0;
public:
	int peekCurrent() const { return this->_id; }
	int getCurrent() { return this->_id++; }
};

class REGUALEXPRESSIONS_API FiniteStateAutomationFactory {
protected:
	NFA getNFA(RE &regularExpression, IdProvider &idProvider);
public:
	NFA getNFA(RE &regularExpression);
};