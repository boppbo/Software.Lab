#pragma once

#include "RegularExpression.h"

/// <summary>	A character. </summary>
class Ch : public RE {
private:
	char c;
protected:
	/// <summary>	Destructor. </summary>
	~Ch() { }
public:

	/// <summary>	Constructor. </summary>
	///
	/// <param name="_c">	The c. </param>
	Ch(char _c) { c = _c; }

	/// <summary>	Gets the character. </summary>
	///
	/// <returns>	The character. </returns>
	char getChar() { return c; }

	/// <summary>	Gets the type </summary>
	///
	/// <returns>	A REType. </returns>
	REType ofType() { return ChType; }

	/// <summary>	Gets the pretty. </summary>
	///
	/// <returns>	A std::string. </returns>
	std::string pretty() { return std::string(1, c); }

	/// <summary>	Query if this object contains EPS. </summary>
	///
	/// <returns>	true if it succeeds, false if it fails. </returns>
	bool containsEps() { return false; }

	/// <summary>	Query if this object is phi. </summary>
	///
	/// <returns>	true if phi, false if not. </returns>
	bool isPhi() { return false; }

	/// <summary>	Tests if this RE* is considered equal to another. </summary>
	///
	/// <param name="other">	[in,out] If non-null, the re* to compare to this object. </param>
	///
	/// <returns>	true if the objects are considered equal, false if they are not. </returns>
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