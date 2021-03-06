#include "stdafx.h"
#include "DeterministicFiniteStateAutomation.h"

using namespace std;

/// <summary>	Resets this object. </summary>
void FSA::reset() {
	this->current->clear();
	this->current->push_back(this->getInitial());
	this->closure();
}

/// <summary>	Query if this object is final. </summary>
///
/// <returns>	true if final, false if not. </returns>
bool FSA::isFinal() {
	for (size_t i = 0; i < this->getFinals().size(); i++) {
		if (find(this->current->begin(), this->current->end(), this->getFinals()[i]) != this->current->end())
			return true;
	}
	return false;
}

/// <summary>	Closures this object. </summary>
void FSA::closure() {
	for (int i = 0; i < this->current->size(); i++)
	{
		for (Transition t : this->getTransitions())
			if (t.trigger((*this->current)[i]))
			{
				this->current->push_back(t.toState());
			}
	}
}

/// <summary>	Steps the given c. </summary>
///
/// <param name="c">	The character. </param>
void FSA::step(char c) {
	vector<int> *next = new vector<int>();
	for (size_t i = 0; i < this->getTransitions().size(); i++) {
		for (size_t j = 0; j < this->current->size(); j++) {
			if (this->getTransitions()[i].trigger((*this->current)[j], c))
				next->push_back(this->getTransitions()[i].toState());
		}
	}

	delete this->current;
	this->current = next;
	this->closure();
}

/// <summary>	Runs the string. </summary>
///
/// <param name="s">	The string. </param>
///
/// <returns>	true if it succeeds, false if it fails. </returns>
bool FSA::run(string s) {
	this->reset();
	for (size_t i = 0; i < s.length(); i++) {
		this->step(s[i]);
	}
	return this->isFinal();
}