#include "DifferenceOfTwoSquares.h"

DifferenceOfTwoSquares::DifferenceOfTwoSquares(std::string in)
{
	_input = in;
	output[1] = "";
}

void DifferenceOfTwoSquares::getSquares()
{
	std::string vals[2];
	for (int i = 0; i < _input.length(); i++) {
		if (_input.at(i) == 'x') {
			if (_input.at(i + 3) == '+') {
				output[0] = "PRIME";
				return;
			}
			
			if (_input.at(0) != 'x')
				vals[0].assign(_input, 0, i);
			else
				vals[0] = "0";
			vals[1].assign(_input, i + 4, _input.length());
			break;
		}
	}
	_nums[0] = stoi(vals[0]);
	_nums[1] = stoi(vals[1]);

	_squares[0] = sqrt(_nums[0]);
	_squares[1] = sqrt(_nums[1]);

	if (ceil(_squares[0]) != floor(_squares[0]) || ceil(_squares[1]) != floor(_squares[1])) {
		output[0] = "PRIME";
		return;
	}
}

void DifferenceOfTwoSquares::getOutput()
{
	if (output[0] == "PRIME")
		return;
	else {
		if (_squares[0] != 0) {
			output[0] = "(" + std::to_string((int)_squares[0]) + "x+" + std::to_string((int)_squares[1]) + ")";
			output[1] = "(" + std::to_string((int)_squares[0]) + "x-" + std::to_string((int)_squares[1]) + ")";
		}
		else {
			output[0] = "(x+" + std::to_string((int)_squares[1]) + ")";
			output[1] = "(x-" + std::to_string((int)_squares[1]) + ")";
		}
	}
}
