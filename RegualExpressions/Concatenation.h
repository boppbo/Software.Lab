#pragma once

#include "RegularExpression.h"

/// <summary>	A concatenation. </summary>
class Conc : public RE {
protected:
	/// <summary>	Destructor. </summary>
	~Conc()
	{
	}

private:
	RE* r1;
	RE* r2;
public:

	/// <summary>	Constructor. </summary>
	///
	/// <param name="_r1">	[in,out] If non-null, the first r. </param>
	/// <param name="_r2">	[in,out] If non-null, the second r. </param>
	Conc(RE* _r1, RE* _r2) { r1 = _r1; r2 = _r2; }

	/// <summary>	Gets the left. </summary>
	///
	/// <returns>	null if it fails, else the left. </returns>
	RE* getLeft() { return r1; }

	/// <summary>	Gets the right. </summary>
	///
	/// <returns>	null if it fails, else the right. </returns>
	RE* getRight() { return r2; }

	/// <summary>	Of type. </summary>
	///
	/// <returns>	A REType. </returns>
	REType ofType() { return ConcType; }

	/// <summary>	Gets the string representation of this instance. </summary>
	///
	/// <returns>	A std::string. </returns>
	std::string pretty()
	{
		return std::string("(") + r1->pretty() + r2->pretty() + ")";
	}

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

		Conc* typedOther = static_cast<Conc*>(other);

		return this->getLeft()->equals(typedOther->getLeft())
			&& this->getRight()->equals(typedOther->getRight());
	}

	/// <summary>	Query if this object contains EPS. </summary>
	///
	/// <returns>	true if it succeeds, false if it fails. </returns>
	bool containsEps() {
		return (r1->containsEps() && r2->containsEps());
	}

	/// <summary>	Query if this object is phi. </summary>
	///
	/// <returns>	true if phi, false if not. </returns>
	bool isPhi() {
		return (r1->isPhi() || r2->isPhi());
	}

	/// <summary>	Gets the simplified regex. </summary>
	///
	/// <returns>	null if it fails, else a pointer to a RE. </returns>
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