#pragma once

#include "stdafx.h"

/// <summary>	The Transition. </summary>
class REGUALEXPRESSIONS_API Transition {
private:
	char c;
	bool epsilon;
	int from;
	int to;
public:

	/// <summary>	Constructor. </summary>
	///
	/// <param name="_from">	Source for the. </param>
	/// <param name="_to">  	to. </param>
	Transition(int _from, int _to) : c(0), epsilon(true), from(_from), to(_to) { }

	/// <summary>	Constructor. </summary>
	///
	/// <param name="_from">	Source for the. </param>
	/// <param name="_c">   	The c. </param>
	/// <param name="_to">  	to. </param>
	Transition(int _from, char _c, int _to) : c(_c), epsilon(false), from(_from), to(_to) { }

	/// <summary>	Query if this object is epsilon transition. </summary>
	///
	/// <returns>	true if epsilon transition, false if not. </returns>
	bool isEpsilonTransition() { return epsilon; }
	int toState() { return to; }

	/// <summary>	Triggers. </summary>
	///
	/// <param name="from">	Source for the. </param>
	///
	/// <returns>	true if it succeeds, false if it fails. </returns>
	bool trigger(int from)
	{
		return (epsilon && from == this->from);
	}

	/// <summary>	Triggers. </summary>
	///
	/// <param name="from">	Source for the. </param>
	/// <param name="c">   	The character. </param>
	///
	/// <returns>	true if it succeeds, false if it fails. </returns>
	bool trigger(int from, char c)
	{
		return (!epsilon && from == this->from && c == this->c);
	}
};
