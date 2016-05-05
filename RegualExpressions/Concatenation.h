#pragma once

#include "RegularExpression.h"

class Conc : public RE {
private:
	RE* r1;
	RE* r2;
public:
	Conc(RE* _r1, RE* _r2) { r1 = _r1; r2 = _r2; }
	RE* getLeft() { return r1; }
	RE* getRight() { return r2; }
	REType ofType() { return ConcType; }
	std::string pretty()
	{
		return std::string("(") + r1->pretty() + r2->pretty() + ")";
	}
	bool equals(RE* other)
	{
		if (other == nullptr)
			return false;

		if (this->ofType() != other->ofType())
			return false;

		Conc* typedOther = static_cast<Conc*>(other);

		return this->getLeft()->equals(typedOther->getLeft())
			&& this->getRight()->equals(typedOther->getRight());
	}
	bool containsEps() {
		return (r1->containsEps() && r2->containsEps());
	}
	bool isPhi() {
		return (r1->isPhi() || r2->isPhi());
	}
	
	RE* simp()
	{
		// First, simplify subparts
		r1 = r1->simp();
		r2 = r2->simp();

		// Then, check if any of the simplification rules are applicable

		// 2. r1 r2 ==> phi falls L(r1)={}
		if (r1->isPhi()) return r1;
		// 2. r1 r2 ==> phi falls L(r2)={}
		if (r2->isPhi()) return r2;

		// 1. eps r ==> r
		if (r1->ofType() == EpsType) return r2;
		// 1. r eps ==> r
		if (r2->ofType() == EpsType) return r1;

		return this;

		// N.B. We're a bit relaxed when it comes to garbage collection.
		// For example, in case of rule (6) we should clean up the
		// memory space occupied by r1 which we ignore here.
	}
};

typedef Conc Concatenation;