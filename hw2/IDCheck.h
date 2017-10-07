/* This is an exception class for validating the ID
 */

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
	//return error message
	string idFormat()
	{
		return this->idMessage;
	}
	//validate ID length and check if it is a number
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