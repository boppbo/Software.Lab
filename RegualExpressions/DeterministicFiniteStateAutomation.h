#pragma once

#include "stdafx.h"
#include "NonDeterministicFIniteStateAutomation.h"

/// <summary>	The finite state automation </summary>
class REGUALEXPRESSIONS_API FSA : public NFA {
private:
	std::vector<int> *current;
	void closure();
public:

	/// <summary>	Constructor. </summary>
	///
	/// <param name="fsa">	The fsa. </param>
	explicit FSA(NFA fsa) : NFA(fsa) {
		this->current = new std::vector<int>();
		this->reset();
	}
	/// <summary>	Destructor. </summary>
	~FSA()
	{
		delete this->current;
	}

	/// <summary>	Resets this object. </summary>
	void reset();

	/// <summary>	Steps the given c. </summary>
	///
	/// <param name="c">	The character. </param>
	void step(char c);

	/// <summary>	Query if this object is final. </summary>
	///
	/// <returns>	true if final, false if not. </returns>
	bool isFinal();

	/// <summary>	Runs the given s. </summary>
	///
	/// <param name="s">	The std::string to process. </param>
	///
	/// <returns>	true if it succeeds, false if it fails. </returns>
	bool run(std::string s);
};