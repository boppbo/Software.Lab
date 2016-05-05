#pragma once

#include "Epsilon.h"

class Star : public RE {
private:
	RE* r;
public:
	Star(RE* _r) { r = _r; }
	RE* getRE() { return r; }
	REType ofType() { return StarType; }
	std::string pretty() {
		return r->pretty() + "*";
	}
	bool containsEps() {
		return true;
	}
	bool isPhi() {
		return false;
	}
	bool equals(RE* other)
	{
		if (other == nullptr)
			return false;

		if (this->ofType() != other->ofType())
			return false;

		Star* typedOther = static_cast<Star*>(other);

		return this->getRE()->equals(typedOther->getRE());
	}
	RE* simp() {

		// Simplify subparts
		r = r->simp();

		// Then, check if any of the simplification rules are applicable

		// 3. `r* ==> eps` falls `L(r)={}`
		if (r->isPhi()) {
			return new Eps();
		}
		// 4. `(r*)* ==> r*`
		if (r->ofType() == StarType) {
			return this->r;
		}

		return this;
	}
};