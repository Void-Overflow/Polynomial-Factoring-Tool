#include "FactoringTrinomials.h"
#include "Grouping.h"

Factoring_Trinomials::Factoring_Trinomials(std::string input, int extent)
{
	_input = input;

	if (extent == 4)
		_extent = false;
	else
		_extent = true;

	_factorsOfC[0] = 0;
	_factorsOfC[1] = 0;
}

void Factoring_Trinomials::getFactorsOfC()
{
	int counter = 0;

	std::string Vals;
	_cStartIndex = 0;

	int c = 0;
	int b = 0;

	bool NegativeFlag = false;
	for (int i = 0; i < _input.length(); i++) {
		if (_input.at(i) == '+' || _input.at(i) == '-') {
			counter++;
			if (counter == 2) {
				_cStartIndex = i;
				if (_input.at(i) == '-')
					NegativeFlag = true;
				for (int x = 0; x < _input.length() - (i + 1); x++)
					Vals += _input.at(i + (x + 1));
			}
		}
	}

	if (NegativeFlag == true)
		c = -std::stoi(Vals);
	else
		c = std::stoi(Vals);

	if (_extent == true) { //When A isn't 1 -- extent is 3
		Vals = "";
		int a = 0;
		for (int i = 0; i < _input.length(); i++) {
			if (_input.at(i) == '^') {
				if (_input.at(0) == '-') {
					Vals.assign(_input, 1, i - 1);
					a = -std::stoi(Vals);
				}
				else if(_input.at(0) == '+'){
					Vals.assign(_input, 1, i - 1);
					a = std::stoi(Vals);
				}
				else {
					Vals.assign(_input, 0, i - 1);
					a = std::stoi(Vals);
				}
				break;
			}
		}
		c*=a;
	} 

	counter = 0;
	Vals = "";
	NegativeFlag = false;

	for (int i = 0; i < _cStartIndex; i++) {
		if (_input.at(i) == '+' || _input.at(i) == '-') {
			counter++;
			if (counter == 1) {
				if (_input.at(i) == '-')
					NegativeFlag = true;
				for (int x = 0; x < _input.length() - (i + 1); x++)
					Vals += _input.at(i + (x + 1));
			}
		}
	}

	if (NegativeFlag == true)
		b = -std::stoi(Vals);
	else
		b = std::stoi(Vals);

	for (int x = -std::abs(c); x <= std::abs(c); x++) {
		if (x == 0)
			x++;

		int y = c / x;
		
		if ((x + y) == b) {
			_factorsOfC[0] = x;
			_factorsOfC[1] = y;

			break;
		}
	} 
}

void Factoring_Trinomials::getOutput()
{
	std::string groupingInput = _input;
	std::string inputSubStrs[2];

	if (_factorsOfC[1] != 0 && _factorsOfC[0] != 0) {
		for (int i = 0; i < _input.length(); i++) {
			if (_input.at(i) == '+' || _input.at(i) == '-') {
				inputSubStrs[0].assign(_input, 0, i);
				inputSubStrs[1].assign(_input, _cStartIndex, _input.length());
				break;
			}
		}

		if (_factorsOfC[0] < 0)
			groupingInput = inputSubStrs[0] + std::to_string(_factorsOfC[0]) + "x";
		else
			groupingInput = inputSubStrs[0] + "+" + std::to_string(_factorsOfC[0]) + "x" + std::to_string(_factorsOfC[1]) + "x" + inputSubStrs[1];

		if (_factorsOfC[1] < 0)
			groupingInput += std::to_string(_factorsOfC[1]) + "x" + inputSubStrs[1];
		else
			groupingInput += "+" + std::to_string(_factorsOfC[1]) + "x" + inputSubStrs[1];

		Grouping group(groupingInput);
		group.seperateInput();
		group.getCommonFactors();

		output = group.output[0] + group.output[1];
	}
	else
		output = "PRIME";
}
