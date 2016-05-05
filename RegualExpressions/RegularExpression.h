#pragma once
#include "stdafx.h"
#include "RegularExpressionType.h"

class RE {
protected:
	~RE()
	{
	}
public:
	virtual REType ofType() = 0;
	virtual std::string pretty() = 0;
	virtual bool containsEps() = 0;
	virtual bool isPhi() = 0;
	virtual RE* simp() { return this; }

	/// <summary>	Repeated application of simp until we reach a fixpoint. </summary>
	///
	/// <remarks>	Boris, 4/6/2016. </remarks>
	///
	/// <returns>	a pointer to a RE. </returns>
	//RE* simpFix() {
	//	RE* simp = this->simp();
	//	return this->equals(simp) ? this : simp->simpFix();
	//}
	virtual bool equals(RE* other)
	{
		if (other == nullptr)
			return false;
		
		if (this->ofType() != other->ofType())
			return false;

		return this->pretty() == other->pretty();
	}
};

typedef RE RegularExpresion;