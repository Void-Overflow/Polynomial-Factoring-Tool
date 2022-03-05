#include <iostream>

#include "identify.h"

int main() {
	std::string exitstr;
	while (true) {
		std::string usr_input;

		char action_in;
		bool action;

		std::cout << "\nEnter Equation to Solve/Factor: ";
		if (exitstr == "y" || exitstr == "Y")
			std::cin.ignore();
		std::getline(std::cin, usr_input);

		std::cout << "\n\nWould you like to solve the equation or just factor? (enter input as f or s): ";
		std::cin >> action_in;

		if (action_in == 's')
			action = 1;
		else
			action = 0;

		identify check_type(usr_input, action);
		check_type.set_type();
		check_type.set_method();

		std::cout << "Output after :" << check_type.output << '\n';
		std::cout << check_type.polynomial_type << " that must be factored by the method of " << check_type.factoring_method_extent;

		std::cout << "\n\nWould you like to do another one? y/n:";
		std::cin >> exitstr;
		if (exitstr != "y")
			if(exitstr != "Y")
				return 0;
	}
}