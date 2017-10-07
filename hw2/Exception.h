#pragma once
/* This is an exception class for checking if a method call has no arguments
*/

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