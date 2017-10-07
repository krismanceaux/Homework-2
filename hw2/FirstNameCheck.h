#pragma once

#include <string>
using namespace std;

/* This is an exception class for validating the First Name
*/

class FirstNameCheck
{
private:
	string fnCheck = "First name is either missing or in the incorrect format";


public:
	FirstNameCheck() {};

	FirstNameCheck(string fnCheck)
	{
		fnFormat();
	}
	
	//return error message
	string fnFormat()
	{
		return this->fnCheck;
	}

	//check if fn is not a number
	bool checkFN(string fn)
	{
		bool flag{ true };
		if(GPACheck::isNumber(fn))
		{
			flag = false;
		}
		return flag;
	}
};