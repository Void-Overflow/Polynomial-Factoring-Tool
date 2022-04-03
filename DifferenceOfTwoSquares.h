#ifndef DIFFERENCEOFTWOSQUARES_H
#define DIFFERENCEOFTWOSQUARES_H

#include <string>

class DifferenceOfTwoSquares
{
private:
	std::string _input;

	int _nums[2];
	float _squares[2];
public:
	std::string output[2];
	DifferenceOfTwoSquares(std::string in);

	void getSquares();
	void getOutput();
};

#endif
