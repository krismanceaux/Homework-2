#pragma once

#include <string>
using namespace std;

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

	string lnFormat()
	{
		return this->lnCheck;
	}
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