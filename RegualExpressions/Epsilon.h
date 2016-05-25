#pragma once

#include "RegularExpression.h"

/// <summary>	An epsilon. </summary>
class Eps : public RE {
protected:
	/// <summary>	Destructor. </summary>
	~Eps()
	{
	}

public:

	/// <summary>	Gets the type. </summary>
	///
	/// <returns>	A REType. </returns>
	REType ofType() { return EpsType; }

	/// <summary>	Gets the string representation of this instance. </summary>
	///
	/// <returns>	A std::string. </returns>
	std::string pretty() { return "eps"; }

	/// <summary>	Query if this object contains EPS. </summary>
	///
	/// <returns>	true if it succeeds, false if it fails. </returns>
	bool containsEps() { return true; }

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

		return this->ofType() == other->ofType();
	}
};

typedef Eps Epsilon;