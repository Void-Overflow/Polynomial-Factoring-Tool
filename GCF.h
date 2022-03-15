#ifndef GCF_H
#define GCF_H

#include <string>

class GCF 
{
private:
	std::string input;
	int extent;

	int nums[32];
public:
	std::string output;
	int gcd;

	GCF(std::string in, int extent);

	int getGCF();
	std::string getOutput();
};

#endif
