#ifndef IDENTIFY_INPUT_H
#define IDENTIFY_INPUT_H

#include <string>

class identify
{
protected:
	std::string _input;
	bool _action;
public:
	int polynomial_type; // 0, 1, 2, 3 : Monomial, Binomial, Trinomial, Polynomial
	int factoring_method_extent; // 0, 1, 2, 3, 4, 5 : GCF, Grouping , Difference of Two Squares, Trinomial-ax^2+bx+c, Trinomial-x+bx+c, Solving

	std::string output;

	identify(std::string in, bool action);

	void set_type();
	void set_method(); 
};

#endif
