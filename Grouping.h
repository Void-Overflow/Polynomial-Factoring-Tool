#ifndef GROUPING_H
#define GROUPING_H

#include <string>

class Grouping {
protected:
	std::string _input;
	std::string _seperatedInput[2];

	int _comm[2];
public:
	std::string output[2];
	Grouping(std::string in);

	void seperateInput();
	void getCommonFactors();
};

#endif
