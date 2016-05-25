#pragma once

#include "stdafx.h"
#include "Transition.h"

/// <summary>	The nonfinite state automation. </summary>
class REGUALEXPRESSIONS_API NFA {
private:
	std::vector<int> *final;
	std::vector<Transition> *ts;
	int init;
	NFA(std::vector<Transition> _ts, int _init)
	{
		this->ts = new std::vector<Transition>(_ts);
		this->init = _init;
	}
public:

	/// <summary>	Constructor. </summary>
	///
	/// <param name="_ts">   	The ts. </param>
	/// <param name="_init"> 	The init. </param>
	/// <param name="_final">	The final. </param>
	NFA(std::vector<Transition> _ts, int _init, std::vector<int> _final) : NFA( _ts, _init ) {
		this->final = new std::vector<int>(_final);
	}

	/// <summary>	Constructor. </summary>
	///
	/// <param name="_ts">   	The ts. </param>
	/// <param name="_init"> 	The init. </param>
	/// <param name="_final">	The final. </param>
	NFA(std::vector<Transition> _ts, int _init, int _final) : NFA(_ts, _init) {
		this->final = new std::vector<int>();
		this->final->push_back(_final);
	}

	/// <summary>	Copy constructor. </summary>
	///
	/// <param name="obj">	The object. </param>
	NFA(const NFA& obj) : NFA(obj.getTransitions(), obj.getInitial(), obj.getFinals()) { }
	/// <summary>	Destructor. </summary>
	~NFA()
	{
		delete this->final;
		delete this->ts;
	}

	/// <summary>	Gets the finals. </summary>
	///
	/// <returns>	The finals. </returns>
	std::vector<int> getFinals() const
	{
		return *final;
	}

	/// <summary>	Gets the initial. </summary>
	///
	/// <returns>	The initial. </returns>
	int getInitial() const
	{
		return init;
	}

	/// <summary>	Gets the transitions. </summary>
	///
	/// <returns>	The transitions. </returns>
	std::vector<Transition> getTransitions() const
	{
		return *ts;
	}
};