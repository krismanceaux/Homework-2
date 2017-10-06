#pragma once
#include <string>
#include "GPACheck.h"
using namespace std;

class IDCheck
{
private: 
	string idMessage = "The ID is either missing or in the wrong format";


public:

	IDCheck() {};
	IDCheck(string idMessage)
	{
		idFormat();
	}

	string idFormat()
	{
		return this->idMessage;
	}

	bool checkID(string idNum)
	{
		bool flag{ true };
		if(idNum.length() != 5)
		{
			flag = false;
		}
		
		if(!GPACheck::isNumber(idNum))
		{
			flag = false;
		}

		return flag;
	}
};