// hw2.cpp : Defines the entry point for the console application.
//

#include <string>
#include <sstream>
#include <fstream>
#include "ArgumentManager.h"
#include "OrderedLinkedList.h"

using namespace std;

void readFile(ifstream & infilename, OrderedLinkedList<nodeType<int, string, double>>& olList);
void readVariables(ifstream & infilename, int& idNum, string& firstName, string& lastName, string& major, double& gpa, int& credits);


int main(int argc, char* argv[])
{




	ArgumentManager am(argc, argv);
	const string infilename = am.get("A");
	const string outfilename = am.get("C");
	
	ifstream infile{ infilename };
	OrderedLinkedList<nodeType<int, string, double>> olList{};

	readFile(infile, olList);
	olList.PRINT_ROSTER();


	infile.close();

}



void readFile(ifstream & infile, OrderedLinkedList<nodeType<int, string, double>>& olList)
{
	string line{ "" };
	int idNum{ 0 };
	string firstName{ "" };
	string lastName{ "" };
	string major{ "" };
	double gpa{ 0 };
	int credits{ 0 };

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

void readVariables(ifstream & infile, int& idNum, string& firstName, string& lastName, string& major, double& gpa, int& credits)
{
	
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
			ss >> idNum;
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
			ss >> gpa;
		}
		else if (count == 5)
		{
			ss >> credits;
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