#include "stdafx.h"
#include "Transform.h"
#include "Character.h"

using namespace std;

NFA FiniteStateAutomationFactory::getNFA(RE& regularExpression, IdProvider &idProvider)
{
	vector<Transition> ts;
	int start = idProvider.getCurrent()
	  , stop = idProvider.getCurrent();

	switch (regularExpression.ofType())
	{
		case EpsType:
			ts.push_back(Transition(start, stop));
			return NFA(ts, start, stop);
		case ChType:
			ts.push_back(Transition(start, dynamic_cast<Ch&>(regularExpression).getChar(), stop));
			return NFA(ts, start, stop);
		case StarType:
		{
			//Thompson style get NFA for re and use it's transitions
			NFA internalNFA = getNFA(*dynamic_cast<Star&>(regularExpression).getRE(), idProvider);
			ts = internalNFA.getTransitions();

			// Add transitions from our start/stop to instant stop(epsilon) and to the internal nfa
			ts.push_back(Transition(start, stop));
			ts.push_back(Transition(start, internalNFA.getInitial()));
			for (int final : internalNFA.getFinals()) ts.push_back(Transition(final, start));

			return NFA(ts, start, stop);
		}
		case ConcType:
		{
			// 1. Baue NFAs des linken und rechten Teilworts
			NFA left = getNFA(*dynamic_cast<Conc&>(regularExpression).getLeft(), idProvider);
			NFA right = getNFA(*dynamic_cast<Conc&>(regularExpression).getRight(), idProvider);

			// 2. Sammle Transitionen auf von n1 und n2.
			vector<Transition> leftT = left.getTransitions();
			vector<Transition> rightT = right.getTransitions();
			ts.insert(ts.end(), leftT.begin(), leftT.end());
			ts.insert(ts.end(), rightT.begin(), rightT.end());
			//    Verbinde neuen Start-/Endzustand mit alten Start-/Endzustaenden.
			for (int leftFinal : left.getFinals()) ts.push_back(Transition(leftFinal, right.getInitial()));

			return NFA(ts, left.getInitial(), right.getFinals());
		}
		case PhiType:
			// Phi: Akzeptiert kein Wort
			// NFA besteht aus einem Start und Stopzustand und *keiner* Transition
			return NFA(ts, start, stop);
		case AltType:
		{	// 1. Baue NFAs der linken und rechten Alternative
			NFA n1 = getNFA(*dynamic_cast<Alt&>(regularExpression).getLeft(), idProvider);
			NFA n2 = getNFA(*dynamic_cast<Alt&>(regularExpression).getRight(), idProvider);

			// 2. Sammle Transitionen auf von n1 und n2.
			//    Verbinde neuen Start-/Endzustand mit alten Start-/Endzustaenden.
			vector<Transition> t1 = n1.getTransitions();
			vector<Transition> t2 = n2.getTransitions();

			ts.insert(ts.end(), t1.begin(), t1.end());
			ts.insert(ts.end(), t2.begin(), t2.end());

			ts.push_back(Transition(start, n1.getInitial()));
			ts.push_back(Transition(start, n2.getInitial()));
			for (int leftFinal : n1.getFinals()) ts.push_back(Transition(leftFinal, stop));
			for (int rightFinal : n2.getFinals()) ts.push_back(Transition(rightFinal, stop));

			return NFA(ts, start, stop);
		}
		default:
			throw std::logic_error("Not Implemented");
	}

}

NFA FiniteStateAutomationFactory::getNFA(RE& regularExpression)
{
	IdProvider foo;
	return this->getNFA(regularExpression, foo);
}
