#pragma once

#include "RegularExpression.h"

class Phi : public RE {
public:
	REType ofType() { return PhiType; }
	std::string pretty() { return "phi"; }
	bool containsEps() { return false; }
	bool isPhi() { return true; }
	bool equals(RE* other)
	{
		if (other == nullptr)
			return false;

		return this->ofType() == other->ofType();
	}
};