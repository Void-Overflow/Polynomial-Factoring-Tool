#include "Solving.h"

std::string removeCharacters(std::string S, char c)
{
	S.erase(remove(
		S.begin(), S.end(), c),
		S.end());

	return S;
}

void Solving::getTerms()
{
	input[0] = removeCharacters(input[0], '(');
	input[0] = removeCharacters(input[0], ')');

	input[1] = removeCharacters(input[1], '(');
	input[1] = removeCharacters(input[1], ')');

	for (int i = 1; i < input[0].length(); i++) {
		if (input[0].at(i) == '+' || input[0].at(i) == '-') {
			_terms[0][0].assign(input[0], 0, i);

			for (int x = i + 1; x < input[0].length(); x++)
				_terms[0][1] += input[0][x];

			break;
		}
	}
	for (int i = 1; i < input[1].length(); i++) {
		if (input[1].at(i) == '+' || input[1].at(i) == '-' ) {
			_terms[1][0].assign(input[1], 0, i);

			if (input[1].at(i) == '-')
				_terms[1][1] = '-';

			for (int x = i + 1; x < input[1].length(); x++)
				_terms[1][1] += input[1][x];

			break;
		}
	}	
}

void Solving::getOutput()
{
	std::string coefficients[2];

	for (int i = 0; i < _terms[0][0].length(); i++) {
		if (_terms[0][0].at(i) == 'x') {
			coefficients[0].assign(_terms[0][0], 0, i);
			break;
		}
	}
	for (int i = 0; i < _terms[1][0].length(); i++) {
		if (_terms[1][0].at(i) == 'x') {
			coefficients[1].assign(_terms[1][0], 0, i);
			break;
		}
	}
	
	output[0] = _terms[0][1] + "/" + coefficients[0];
	output[1] = _terms[1][1] + "/" + coefficients[1];
}
