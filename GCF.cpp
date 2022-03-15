#include "GCF.h"

#include <sstream>
#include <regex>

int toPos(int input) {
    if (input < 0)
        return input + (input * -2);
    else
        return input;
}

int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

int findGCD(int arr[], int n)
{
    int result = arr[0];
    for (int i = 1; i < n; i++)
    {
        result = gcd(arr[i], result);

        if (result == 1)
        {
            return 1;
        }
    }
    return result;
}

GCF::GCF(std::string in, int _extent)
{
	input = in;
	extent = _extent;
}

int counter = 0;

int GCF::getGCF()
{
    for (int i = 0; i < 32; i++)
        nums[i] = 0;

    bool negativeFlag = false;

    for (int i = 0; i < input.length(); i++) {
        int found;
        std::stringstream ss;
        std::string temp;
        ss << input[i];
        ss >> temp;

        if (input.at(i) == '^')
            i++;
        else {
            if (std::stringstream(temp) >> found) {
                if (negativeFlag == true) {
                    nums[counter] = found - (found * 2);
                    negativeFlag = false;
                }
                else
                    nums[counter] = found;
                counter++;

                std::stringstream s2;
                s2 << input[i + 1];
                temp = "";
                s2 >> temp;
                if (std::stringstream(temp) >> found) {
                    nums[counter - 1] = std::stoi(std::to_string(nums[counter - 1]) + std::to_string(found));
                    i++;
                }
            }
            if (temp == "-")
                negativeFlag = true;
        }
    }

    if (toPos(findGCD(nums, sizeof(nums) / sizeof(nums[0]))) != 1) 
        GCF::gcd = findGCD(nums, sizeof(nums) / sizeof(nums[0]));
    else
        GCF::gcd = 1;

	return 0;
}

std::string GCF::getOutput()
{
    output = input;
    if (gcd == 1) 
        return output;    
    else {
        char exp;
        for (int i = 0; i < output.length(); i++) {
            if (output.at(i) == '^') {
                i++;
                exp = output[i];
                output.at(i) = '|';
            }
        }

        for (int i = 0; i < counter; i++)
            output = std::regex_replace(output, std::regex(std::to_string(nums[i])), std::to_string(nums[i] / gcd));

        for (int i = 0; i < output.length(); i++) {
           if (output.at(i) == '|') {
                output.at(i) = exp;
           }
        }

        if (extent < 5)
            output = std::to_string(gcd) + "(" + output + ")";

        return output;
    }
}
