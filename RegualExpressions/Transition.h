#pragma once

#include "stdafx.h"

class REGUALEXPRESSIONS_API Transition {
private:
	char c;
	bool epsilon;
	int from;
	int to;
public:
	Transition(int _from, int _to) : c(0), epsilon(true), from(_from), to(_to) { }
	Transition(int _from, char _c, int _to) : c(_c), epsilon(false), from(_from), to(_to) { }
	bool isEpsilonTransition() { return epsilon; }
	int toState() { return to; }
	bool trigger(int from)
	{
		return (epsilon && from == this->from);
	}
	bool trigger(int from, char c)
	{
		return (!epsilon && from == this->from && c == this->c);
	}
};
