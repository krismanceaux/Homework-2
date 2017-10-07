#pragma once
#include <string>
using namespace std;

/* This is an exception class for validating the gpa
*/

class GPACheck
{
private:
	string gpaCheck = "GPA is in incorrect format";


public:
	GPACheck() {};
	GPACheck(string gpaCheck)
	{
		gpaFormat(gpaCheck);
	}

	string gpaFormat(string gpaCheck)
	{
		return this->gpaCheck;
	}

	// static function to check if a certain string represents a number. may be used across other classes
	static bool isNumber(string str)
	{
		for (char i : str)
		{
			if (i < 48 && i != 46 || i > 57)
			{
				return false;
			}
		}
		return true;
	}

	//check if the arg fits the description for gpa
	bool checkGPA(string GPA2)
	{
		double gpaNum;
		if (isNumber(GPA2)) {
			gpaNum = stod(GPA2);
		}
		else
		{
			return false;
		}
		bool flag{ true };
		int count{ 0 };
		for (char i : GPA2)
		{
			if (i < 48 && i != 46 || i > 57)
			{
				flag = false;
			}
			count++;
		}
		if (GPA2[1] != '.')
		{
			flag = false;
		}
		if (gpaNum < 0.0 || gpaNum > 4.0)
		{
			flag = false;
		}
		return flag;
	}
};