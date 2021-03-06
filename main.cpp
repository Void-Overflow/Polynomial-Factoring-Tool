#include <iostream>

#include "identify.h"

#include "GCF.h"
#include "Grouping.h"
#include "FactoringTrinomials.h"
#include "DifferenceOfTwoSquares.h"
#include "Solving.h"

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
			action = true;
		else
			action = false;

		identify get_type;
		get_type.input = usr_input;
		get_type.set_type();
		get_type.set_method();

		Solving getRoots;

		std::cout << "Output after identifying:" << get_type.output << '\n';
		std::cout << get_type.polynomial_type << " that must be factored by the method of " << get_type.factoring_method_extent << "\n\n";
		
		GCF gcf(get_type.output, get_type.factoring_method_extent);
		if (get_type.factoring_method_extent != 1 && get_type.factoring_method_extent != 2) {
			gcf.getGCF();
			gcf.getOutput();

			get_type.input = gcf.plainOutput;

			std::cout << "GCF : " << gcf.gcd <<" - Output : " << gcf.output << '\n' << std::endl;
		}


		if (get_type.factoring_method_extent == 1) {
			Grouping group(get_type.output);
			group.seperateInput();
			group.getCommonFactors();

			std::cout << "Grouping Output : " << group.output[0] + group.output[1] << std::endl;

			if (action == true) {
				getRoots.input[0] = group.output[0];
				getRoots.input[1] = group.output[1];

				getRoots.getTerms();
				getRoots.getOutput();

				std::cout << "Solving : X = " + getRoots.output[0] + " ; X = " + getRoots.output[1] << std::endl;
			}
		}

		else if (get_type.factoring_method_extent == 4 || get_type.factoring_method_extent == 3) {
			get_type.get_vars();
			get_type.get_vertex();
			
			std::cout << "Y-intercept : " << get_type.y_intercept << '\n';
			std::cout << "Vertex : (" << get_type.vertex[0] << "," << get_type.vertex[1]  << ")\n\n";

			Factoring_Trinomials trinomials(gcf.plainOutput, get_type.factoring_method_extent);
			trinomials.getFactorsOfC();
			trinomials.getOutput();

			if(gcf.gcd != 1 && trinomials.output[0] != "PRIME")
				std::cout << "Trinomial Factoring Output : " << gcf.gcd << trinomials.output[0] + trinomials.output[1] << std::endl;
			else
				std::cout << "Trinomial Factoring Output : " << trinomials.output[0] + trinomials.output[1] << '\n' << std::endl;

			if (action == true) {
				getRoots.input[0] = trinomials.output[0];
				getRoots.input[1] = trinomials.output[1];

				getRoots.getTerms();
				getRoots.getOutput();

				std::cout << "Solving : X = " + getRoots.output[0] + " ; X = " + getRoots.output[1] << std::endl;
			}
		}

		else if (get_type.factoring_method_extent == 2) {
			DifferenceOfTwoSquares DOTS(get_type.output);
			DOTS.getSquares();
			DOTS.getOutput();

			std::cout << "Difference of Two Squares Factoring Output : " << DOTS.output[0] << DOTS.output[1] << std::endl;

			if (action == true) {
				getRoots.input[0] = DOTS.output[0];
				getRoots.input[1] = DOTS.output[1];

				getRoots.getTerms();
				getRoots.getOutput();

				std::cout << "Solving : X = " + getRoots.output[0] + " ; X = " + getRoots.output[1] << std::endl;
			}
		}

		std::cout << "\n\nWould you like to do another one? y/n:";
		std::cin >> exitstr;
		if (exitstr != "y")
			if(exitstr != "Y")
				return 0;
	}
}