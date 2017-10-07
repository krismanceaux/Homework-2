#pragma once
#include <string>
#include "GPACheck.h"
using namespace std;

/* This is an exception class for validating the credits
*/

class CreditCheck
{
private:
	string creditCheck = "Credit is in incorrect format";


public:
	CreditCheck() {};
	CreditCheck(string creditCheck)
	{
		creditFormat(creditCheck);
	}

	//return the error message
	string creditFormat(string creditCheck)
	{
		return this->creditCheck;
	}

	//check if the argument fits the description for credits
	bool checkCredits(string credits)
	{
		bool flag{ true };
		for (char i : credits)
		{
			if (i == '.')
			{
				flag = false;
			}
			if(!GPACheck::isNumber(credits))
			{
				flag = false;
			}
		
		}

		if (GPACheck::isNumber(credits)) {
			
			try
			{
				int cr = stoi(credits);
				if (cr < 0 || cr > 15)
				{
					flag = false;
				}

			}
			catch (...)
			{
				cout << "Incorrect number format" << endl;
				flag = false;
			}
			
		}
		return flag;
	}
};