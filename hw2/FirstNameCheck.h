#pragma once

#include <string>
using namespace std;

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

	string fnFormat()
	{
		return this->fnCheck;
	}

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