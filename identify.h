#ifndef IDENTIFY_INPUT_H
#define IDENTIFY_INPUT_H

#include <string>

class identify
{
protected:
	float _varLocations[3][3]; //A, B, C : start, end, value
public:
	int polynomial_type; // 0, 1, 2, 3 : Monomial, Binomial, Trinomial, Polynomial
	int factoring_method_extent; // 0, 1, 2, 3, 4 : GCF, Grouping , Difference of Two Squares, Trinomial-ax^2+bx+c, Trinomial-x+bx+c

	std::string input;
	std::string output;

	identify();

	void set_type();
	void set_method(); 

	float vertex[2]; //x, y
	int y_intercept;

	void get_vars();
	void get_vertex(); //-b/2a for x-cordinate
};

#endif
