#pragma once

#include <string>
#include "GPACheck.h"
using namespace std;

/* This is an exception class for validating the Last Name
*/

class LastNameCheck
{
private:
	string lnCheck = "Last name is either missing or in the incorrect format";


public:
	LastNameCheck() {};
	LastNameCheck(string lnCheck)
	{
		lnFormat();
	}

	//return error message
	string lnFormat()
	{
		return this->lnCheck;
	}

	//check if the last name contains numbers
	bool checkLN(string ln)
	{
		bool flag{ true };
		if (GPACheck::isNumber(ln))
		{
			flag = false;
		}
		return flag;
	}

};