#pragma once
#include <string>
using namespace std;

/* This is an exception class for validating the major
*/

class MajorCheck
{
private:
	string majCheck = "Major is in incorrect format";


public:
	MajorCheck() {};
	string majFormat(string majCheck)
	{
		return this->majCheck;
	}

	//check if the arg fits the description for major
	static bool isLetter(string major)
	{
		bool flag = true;
		for (char i : major)
		{
			if (i <65 || i > 90 && i < 97 || i > 122)
			{
				flag = false;
			}
		}
		return flag;
	}
};