#include "Grouping.h"
#include "GCF.h"

Grouping::Grouping(std::string in) {_input = in;}

void Grouping::seperateInput()
{
	int counter = 0;
	int cut_off_index = 0;

	for (int i = 1; i < _input.length(); i++) {
		if (_input.at(i) == '+' || _input.at(i) == '-') {
			if (counter == 0)
				counter++;
			else if (counter > 0) {
				cut_off_index = i;
				break;
			}
		}
	}
	
	_seperatedInput[0] = _input.substr(0, cut_off_index); 
	_seperatedInput[1] = _input.substr(cut_off_index, _input.length());
}

void Grouping::getCommonFactors()
{
	GCF gcf1(_seperatedInput[0], 1);
	gcf1.getGCF();
	gcf1.getOutput();
	GCF gcf2(_seperatedInput[1], 1);
	gcf2.getGCF();
	gcf2.getOutput();

	if(gcf2.gcd < 0)
		output[0] = "(" + std::to_string(gcf1.gcd) + "x" + std::to_string(gcf2.gcd) + ")";
	else
		output[0] = "(" + std::to_string(gcf1.gcd) + "x+" + std::to_string(gcf2.gcd) + ")";

	output[1] = "(" + gcf2.plainOutput + ")";
}

