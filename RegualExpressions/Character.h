#pragma once

#include "RegularExpression.h"

class Ch : public RE {
private:
	char c;
protected:
	~Ch() { }
public:
	Ch(char _c) { c = _c; }
	char getChar() { return c; }
	REType ofType() { return ChType; }
	std::string pretty() { return std::string(1, c); }
	bool containsEps() { return false; }
	bool isPhi() { return false; }
	bool equals(RE* other)
	{
		if (other == nullptr)
			return false;

		if (this->ofType() != other->ofType())
			return false;

		Ch* typedOther = static_cast<Ch*>(other);

		return this->getChar() == typedOther->getChar();
	}
};

typedef Ch Character;