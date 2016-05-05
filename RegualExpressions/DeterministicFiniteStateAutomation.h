#pragma once

#include "stdafx.h"
#include "NonDeterministicFIniteStateAutomation.h"

class REGUALEXPRESSIONS_API FSA : public NFA {
private:
	std::vector<int> *current;
	void closure();
public:
	explicit FSA(NFA fsa) : NFA(fsa) {
		this->current = new std::vector<int>();
		this->reset();
	}
	~FSA()
	{
		delete this->current;
	}

	void reset();
	void step(char c);
	bool isFinal();
	bool run(std::string s);
};