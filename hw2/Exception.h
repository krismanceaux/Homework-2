#pragma once

using namespace std;
class Exception
{
private: 
	string argMessage{ "There are missing arguments." };
public: 
	Exception(string argMessage)
	{
		argMissing();
	}

	string argMissing()
	{
		return this->argMessage;
	}
};