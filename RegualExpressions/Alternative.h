#pragma once

#include "RegularExpression.h"
#include "Star.h"

class Alt : public RE {
private:
	RE* r1;
	RE* r2;
public:
	Alt(RE* _r1, RE* _r2) { r1 = _r1; r2 = _r2; }
	RE* getLeft() { return r1; }
	RE* getRight() { return r2; }
	REType ofType() { return AltType; }
	std::string pretty() {
		std::string s("(");
		s.append(r1->pretty());
		s.append("+");
		s.append(r2->pretty());
		s.append(")");
		return s;
	}
	bool containsEps() {
		return (r1->containsEps() || r2->containsEps());
	}
	bool isPhi() {
		return (r1->isPhi() && r2->isPhi());
	}
	bool equals(RE* other)
	{
		if (other == nullptr)
			return false;

		if (this->ofType() != other->ofType())
			return false;

		Alt* typedOther = static_cast<Alt*>(other);

		// TODO: should be equal for swapped left right
		return this->getLeft()->equals(typedOther->getLeft())
			&& this->getRight()->equals(typedOther->getRight());
	}

	RE* simp()
	{
		// First, simplify subparts
		r1 = r1->simp();
		r2 = r2->simp();

		// Then, check if any of the simplification rules are applicable

		// 6. `r1 + r2 ==> r2` falls `L(r1)={}`
		if (r1->isPhi()) return r2;
		// 7. `r1 + r2 ==> r1` falls `L(r2)={}`
		if (r2->isPhi()) return r1;
		// 5. `r1 + r1 == r1`
		if (r1->equals(r2))
			return r1;

		// r1* + r1 ==> r1*
		if (r1->ofType() == StarType)
		{
			Star* star = static_cast<Star*>(r1);
			if (star->getRE()->equals(r2))
				return star;
		}
		// r1 + r1* ==> r1*
		if (r2->ofType() == StarType)
		{
			Star* star = static_cast<Star*>(r2);
			if (star->getRE()->equals(r1))
				return star;
		}

		// r1+r2 + r1 ==> r1+r2
		if (r1->ofType() == AltType)
		{
			Alt* alt = static_cast<Alt*>(r1);
			if (alt->getLeft()->equals(r2) || alt->getRight()-equals(r2))
				return alt;
		}
		// r1 + r1+r2 ==> r1+r2
		if (r2->ofType() == AltType)
		{
			Alt* alt = static_cast<Alt*>(r2);
			if (alt->getLeft()->equals(r1) || alt->getRight() - equals(r1))
				return alt;
		}

		return this;

		// N.B. We're a bit relaxed when it comes to garbage collection.
		// For example, in case of rule (6) we should clean up the
		// memory space occupied by r1 which we ignore here.
	}
};

typedef Alt Alternative;