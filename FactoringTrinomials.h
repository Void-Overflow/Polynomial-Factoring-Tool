#ifndef FACTORINGTRINOMIALS_H
#define FACTORINGTRINOMIALS_H

#include <string>

class Factoring_Trinomials
{
private: 
	int _cStartIndex;
	int _factorsOfC[2];

	std::string _input;
	bool _extent;
public:
	std::string output;
	Factoring_Trinomials(std::string input, int extent);

	void getFactorsOfC();
	void getOutput();
};

#endif
