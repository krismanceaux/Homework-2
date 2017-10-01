// hw2.cpp : Defines the entry point for the console application.
//

#include <string>
#include <sstream>
#include <fstream>
#include "ArgumentManager.h"
#include "OrderedLinkedList.h"

using namespace std;

void readFile(ifstream & infilename, OrderedLinkedList<nodeType<string>>& olList);
void readVariables(ifstream & infilename, string& idNum, string& firstName, string& lastName, string& major, string& gpa, string& credits);
int charCount(string& str);
bool checkGPA(string& GPA2);
bool checkCredits(string& credits);

int main(int argc, char* argv[])
{
	ArgumentManager am(argc, argv);
	const string infilename = am.get("A");
	const string outfilename = am.get("C");
	
	ifstream infile{ infilename };
	OrderedLinkedList<nodeType<string>> olList{};

	readFile(infile, olList);
	infile.close();

	olList.PRINT_ROSTER();


	

}



void readFile(ifstream & infile, OrderedLinkedList<nodeType<string>>& olList)
{
	string line{ "" };
	string idNum{ "0" };
	string firstName{ "" };
	string lastName{ "" };
	string major{ "" };
	string gpa{ "0.0" };
	string credits{ "0" };

	//while there are lines to be read
	while (infile.good())
	{
		//get the current line
		getline(infile, line);

		//if line is INSERT
		if (line == "INSERT") {
			//call readVariables
			readVariables(infile, idNum, firstName, lastName, major, gpa, credits);
			
			olList.INSERT(nullptr, nullptr, idNum, firstName, lastName, major, gpa, credits);
		}
		//else if line is PRINT_ROSTER
			//call the PRINT_ROSTER function						TODO: IMPLEMENT FUNCTION

		//else if line is PRINT_BY_MAJOR
			//call readVariables
			//readVariables(infile, idNum, firstName, lastName, major, gpa, credits);

			//call the PRINT_BY_MAJOR function						TODO: IMPLEMENT FUNCTION 

		//else if line is PRINT_BY_GPA
			//call read variables
			//readVariables(infile, idNum, firstName, lastName, major, gpa, credits);

			//call PRINT_BY_GPA

		//else if line is PRINT_STUDENT
			//call readVariables
			//readVariables(infile, idNum, firstName, lastName, major, gpa, credits);
			//call PRINT_STUDENT									TODO: IMPLEMENT FUNCTION

		//else if line is DELETE_STUDENT
			//call readVariables
			//readVariables(infile, idNum, firstName, lastName, major, gpa, credits);
			// call DELETE_STUDENT									TODO: IMPLEMENT FUNCTION

		//else if DELETE_ID
			//call readVariables
			//readVariables(infile, idNum, firstName, lastName, major, gpa, credits);
			// call DELETE_ID										TODO: IMPLEMENT FUNCTION

		//else if UPDATE_GPA
			//call readVariables
			//readVariables(infile, idNum, firstName, lastName, major, gpa, credits);
			// call UPDATE_GPA										TODO: IMPLEMENT FUNCTION

		//else if UPDATE_MAJOR
			//call readVariables
			//readVariables(infile, idNum, firstName, lastName, major, gpa, credits);
			//call UPDATE_MAJOR										TODO: IMPLEMENT FUNCTION

		//else if ADD_CLASS
			//call readVariables
			//readVariables(infile, idNum, firstName, lastName, major, gpa, credits);
			//call ADD_CLASS

		//else if REMOVE_CLASS
			//call readVariables
			//readVariables(infile, idNum, firstName, lastName, major, gpa, credits);
			//call REMOVE_CLASS										TODO: IMPLEMENT FUNCTION

		//else if GPA
			//call GPA												TODO: IMPLEMENT FUNCTION

	}

}

void readVariables(ifstream & infile, string& idNum, string& firstName, string& lastName, string& major, string& gpa, string& credits)
{
	double gpa3;
	int count{ 0 };
	//while there are lines to be read
	while (infile.good())
	{
	
		string line2;
		getline(infile, line2);
		stringstream ss(line2);
		//store variables locally
		if(count == 0)
		{
			
			try {
				ss >> idNum;
				if (charCount(line2) != 5)
					throw(idNum);
				
			}catch(const string e)
			{
				idNum = "0";
				cout << "Your ID: " << e << " is the incorrect number of digits. It must be 5 digits long" << endl;
			}
		}
		else if (count == 1)
		{
			ss >> firstName;;
		}
		else if (count == 2)
		{
			ss >> lastName;
		}
		else if (count == 3)
		{
			ss >> major;
		}
		else if (count == 4)
		{
			try
			{
				if (!checkGPA(line2))
					throw line2;
				ss >> gpa;
				
			}
			catch (string e)
			{
				gpa = "0.00";
				cout << "Your GPA: " << e << " is in the incorrect GPA format. Example: 3.58 or 0.00. It must be a number in between 0.00 and 4.00" << endl;
			}
		}
		else if (count == 5)
		{
			try {
				if (!checkCredits(line2))
					throw line2;
				ss >> credits;
			}catch(string e)
			{
				credits = "0";
				cout << "Your credits: " << e << " is in the wrong format. It must be a whole number between 0 and 15." << endl;
			}
		}
		count++;
		
		//if line is blank - BREAK
		if(line2 == "")
		{
			break;
		}

		ss.str("");
		ss.clear(); 
	}
}

int charCount(string& str)
{
	int count{ 0 };
	for(char i : str)
	{
		count++;
	}
	return count;
}

bool checkGPA(string& GPA2)
{
	double gpaNum = stod(GPA2);

	bool flag{ true };
	int count{ 0 };
	for(char i : GPA2)
	{
		if(i < 48 && i != 46 || i > 57)
		{
			flag = false;
		}
		count++;
	}
	if(GPA2[1] != '.')
	{
		flag = false;
	}
	if(gpaNum < 0.0 || gpaNum > 4.0)
	{
		flag = false;
	}
	return flag;
}

bool checkCredits(string& credits)
{
	bool flag{ true };
	int cr = stoi(credits);
	
	if(cr < 0 || cr > 15)
	{
		flag = false;
	}
	return flag;
}