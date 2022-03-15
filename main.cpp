#include <iostream>

#include "identify.h"

#include "GCF.h"

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
		std::cin >> action_in; std::cout << '\n';

		if (action_in == 's')
			action = 1;
		else
			action = 0;

		identify get_type(usr_input, action);
		get_type.set_type();
		get_type.set_method();

		std::cout << "Output after identifying:" << get_type.output << '\n';
		std::cout << get_type.polynomial_type << " that must be factored by the method of " << get_type.factoring_method_extent << "\n\n";
		
		GCF gcf(get_type.output, get_type.factoring_method_extent);
		gcf.getGCF();
		gcf.getOutput();

		std::cout << "GCF Output : " << gcf.output << std::endl;

		std::cout << "\n\nWould you like to do another one? y/n:";
		std::cin >> exitstr;
		if (exitstr != "y")
			if(exitstr != "Y")
				return 0;
	}
}