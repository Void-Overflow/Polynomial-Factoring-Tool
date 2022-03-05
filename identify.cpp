#include "identify.h"
identify::identify(std::string in, bool action)
{
	_action = action;
	_input = in;
	output = _input;

	std::remove_if(_input.begin(), _input.end(), isspace);
}

void identify::set_type()
{
	size_t amtOfSigns = std::count(_input.begin(), _input.end(), '-') + std::count(_input.begin(), _input.end(), '+');
	
	if (_input.at(0) == '-')
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
		identify::factoring_method_extent = 2;
	else if (identify::_action == true)
		identify::factoring_method_extent += 5;
}
