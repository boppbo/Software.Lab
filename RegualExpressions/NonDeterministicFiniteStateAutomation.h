#pragma once

#include "stdafx.h"
#include "Transition.h"

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
	NFA(std::vector<Transition> _ts, int _init, std::vector<int> _final) : NFA( _ts, _init ) {
		this->final = new std::vector<int>(_final);
	}
	NFA(std::vector<Transition> _ts, int _init, int _final) : NFA(_ts, _init) {
		this->final = new std::vector<int>();
		this->final->push_back(_final);
	}
	NFA(const NFA& obj) : NFA(obj.getTransitions(), obj.getInitial(), obj.getFinals()) { }
	~NFA()
	{
		delete this->final;
		delete this->ts;
	}
	std::vector<int> getFinals() const
	{
		return *final;
	}
	int getInitial() const
	{
		return init;
	}
	std::vector<Transition> getTransitions() const
	{
		return *ts;
	}
};