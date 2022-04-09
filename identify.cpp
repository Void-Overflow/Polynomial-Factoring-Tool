#include "identify.h"

identify::identify()
{
	y_intercept = 0;
	for (int i = 0; i < 3; i++) {
		if (i <= 2)
			vertex[i] = 0;
		for (int x = 0; x < 3; x++)
			_varLocations[i][x] = 0;
	}
}

void identify::set_type()
{
	input.erase(remove(input.begin(), input.end(), ' '), input.end());
	output = input;

	size_t amtOfSigns = std::count(input.begin(), input.end(), '-') + std::count(input.begin(), input.end(), '+');
	
	if (input.at(0) == '-' || input.at(0) == '+')
		amtOfSigns--;

	if (amtOfSigns == 0) 
		identify::polynomial_type = 0;
	else if (amtOfSigns == 1) 
		identify::polynomial_type = 1;
	else if (amtOfSigns == 2) 
		identify::polynomial_type = 2;
	else if (amtOfSigns == 3) 
		identify::polynomial_type = 3;
	else 
		identify::polynomial_type = 3;
	
}

void identify::set_method()
{
	if (identify::polynomial_type == 0)
		identify::factoring_method_extent = 0;
	else if (identify::polynomial_type == 1) {
		if (std::count(identify::output.begin(), identify::output.end(), '-') > 0)
			identify::factoring_method_extent = 2;
		else
			identify::factoring_method_extent = 1;
	}
	else if (identify::polynomial_type == 2) {
		if (identify::output.at(0) == '-') {
			identify::output.erase(0, 1);
			for (int i = 0; i < identify::output.length(); i++) {
				if (identify::output.at(i) == '-')
					identify::output.at(i) = '+';
				else if (identify::output.at(i) == '+')
					identify::output.at(i) = '-';
			}
		}

		if ((int)identify::output.at(0) - 48 < 10)
			identify::factoring_method_extent = 3;
		else
			identify::factoring_method_extent = 4;
	}
	else if (identify::polynomial_type == 3)
		identify::factoring_method_extent = 1;
}

void identify::get_vars()
{
	int counter = 0;

	std::string Vals;
	_varLocations[2][1] = (float)input.length();

	int a = 0;
	int c = 0;
	int b = 0;

	bool NegativeFlag = false;
	for (int i = 0; i < input.length(); i++) {
		if (input.at(i) == '+' || input.at(i) == '-') {
			counter++;
			if (counter == 2) {
				_varLocations[2][0] = (float)i;
				if (input.at(i) == '-')
					NegativeFlag = true;
				for (int x = 0; x < input.length() - (i + 1); x++)
					Vals += input.at(i + (x + 1));
			}
		}
	}

	if (NegativeFlag == true)
		c = -std::stoi(Vals);
	else
		c = std::stoi(Vals);

	y_intercept = c;
	_varLocations[2][2] = (float)c;

	counter = 0;
	Vals = "";
	NegativeFlag = false;

	for (int i = 0; i < _varLocations[2][0]; i++) {
		if (input.at(i) == '+' || input.at(i) == '-') {
			counter++;
			_varLocations[1][0] = (float)i + 1.0f;
			_varLocations[1][1] = _varLocations[2][0] - 1.0f;
			if (counter == 1) {
				if (input.at(i) == '-')
					NegativeFlag = true;
				for (int x = 0; x < input.length() - (i + 1); x++)
					Vals += input.at(i + (x + 1));
			}
		}
	}

	if (NegativeFlag == true)
		b = -stoi(Vals);
	else
		b = stoi(Vals);

	_varLocations[1][2] = (float)b;

	if (identify::factoring_method_extent == 3) {
		Vals = "";
		for (int i = 0; i < input.length(); i++) {
			if (input.at(i) == '^') {
				_varLocations[0][0] = (float)i + 1.0f;
				_varLocations[0][1] = _varLocations[1][0] - 1.0f;
				if (input.at(0) == '-') {
					Vals.assign(input, 1, i - 1);
					a = -std::stoi(Vals);
				}
				else if (input.at(0) == '+') {
					Vals.assign(input, 1, i - 1);
					a = std::stoi(Vals);
				}
				else {
					Vals.assign(input, 0, i - 1);
					a = std::stoi(Vals);
				}
				break;
			}
		}

		_varLocations[0][2] = (float)a;
	}
	else {
		_varLocations[0][0] = 0.0f;
		_varLocations[0][1] = 1.0f;
		_varLocations[0][2] = 1.0f;
	}
}

void identify::get_vertex()
{
	float x = 0.0f, y = 0.0f;

	x = -_varLocations[1][2] / (2 * _varLocations[0][2]); //-b/2a
	y = _varLocations[0][2] * (pow(x, 2)) + (_varLocations[1][2] * (double)x) + _varLocations[2][2]; //ax^2 + bx + c

	vertex[0] = x;
	vertex[1] = y;
}
