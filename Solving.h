#ifndef SOLVING_H
#define SOLVING_H

#include <string>

class Solving
{
private:
	std::string _terms[2][2];
public:
	std::string input[2];
	std::string output[2];

	void getTerms();
	void getOutput(); //Also combine like terms
};

#endif