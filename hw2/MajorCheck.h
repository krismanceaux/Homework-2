#pragma once
#include <string>
using namespace std;

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