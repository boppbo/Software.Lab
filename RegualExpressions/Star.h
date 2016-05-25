#pragma once

#include "Epsilon.h"

/// <summary>	A star. </summary>
class Star : public RE {
protected:
	/// <summary>	Destructor. </summary>
	~Star()
	{
	}

private:
	RE* r;
public:

	/// <summary>	Constructor. </summary>
	///
	/// <param name="_r">	[in,out] If non-null, the r. </param>
	Star(RE* _r) { r = _r; }

	/// <summary>	Gets the re. </summary>
	///
	/// <returns>	null if it fails, else the re. </returns>
	RE* getRE() { return r; }

	/// <summary>	Gets the type. </summary>
	///
	/// <returns>	A REType. </returns>
	REType ofType() { return StarType; }

	/// <summary>	Gets the string representation of this instance </summary>
	///
	/// <returns>	A std::string. </returns>
	std::string pretty() {
		return r->pretty() + "*";
	}

	/// <summary>	Query if this object contains EPS. </summary>
	///
	/// <returns>	true if it succeeds, false if it fails. </returns>
	bool containsEps() {
		return true;
	}

	/// <summary>	Query if this object is phi. </summary>
	///
	/// <returns>	true if phi, false if not. </returns>
	bool isPhi() {
		return false;
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

		Star* typedOther = static_cast<Star*>(other);

		return this->getRE()->equals(typedOther->getRE());
	}

	/// <summary>	Gets the simplified regex. </summary>
	///
	/// <returns>	null if it fails, else a pointer to a RE. </returns>
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