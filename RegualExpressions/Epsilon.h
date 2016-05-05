#pragma once

#include "RegularExpression.h"

class Eps : public RE {
public:
	REType ofType() { return EpsType; }
	std::string pretty() { return "eps"; }
	bool containsEps() { return true; }
	bool isPhi() { return false; }
	bool equals(RE* other)
	{
		if (other == nullptr)
			return false;

		return this->ofType() == other->ofType();
	}
};

typedef Eps Epsilon;