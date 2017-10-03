// hw2.cpp : Defines the entry point for the console application.
//

#include <string>
#include <fstream>
#include "ArgumentManager.h"
#include "OrderedLinkedList.h"
#include "Exception.h"

using namespace std;

void readFile(ifstream & infilename, ofstream& outfilename, OrderedLinkedList<nodeType<string>>& olList);
void readVariables(ifstream & infilename, string& idNum, string& firstName, string& lastName, string& major, string& gpa, string& credits, int b1, int b2, int b3, int b4, int b5, int b6);
bool checkGPA(string GPA2);
bool checkCredits(string credits);
bool checkMajor(string major);

int main(int argc, char* argv[])
{
	ArgumentManager am(argc, argv);
	const string infilename = am.get("A");
	const string outfilename = am.get("C");

	ifstream infile{ infilename };
	OrderedLinkedList<nodeType<string>> olList{};
	ofstream outfile(outfilename);

	//Inside readFile is where we call the functions and get their arguments as we are reading the file
	readFile(infile, outfile, olList);
	infile.close();
	outfile.close();
}



void readFile(ifstream & infile, ofstream & outfile, OrderedLinkedList<nodeType<string>>& olList)
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
			readVariables(infile, idNum, firstName, lastName, major, gpa, credits, 1, 2, 3, 4, 5, 6);
			olList.INSERT(nullptr, nullptr, idNum, firstName, lastName, major, gpa, credits);
		}
		else if (line == "PRINT_ROSTER")
		{
			readVariables(infile, idNum, firstName, lastName, major, gpa, credits, 0, 0, 0, 0, 0, 0);
			olList.PRINT_ROSTER(outfile, infile);
		}

		else if (line == "PRINT_BY_MAJOR")
		{
			readVariables(infile, idNum, firstName, lastName, major, gpa, credits, 0, 0, 0, 4, 0, 0);
			olList.PRINT_BY_MAJOR(major, outfile, infile);
		}


		else if (line == "PRINT_BY_GPA") {
			//call read variables
			readVariables(infile, idNum, firstName, lastName, major, gpa, credits, 0, 0, 0, 0, 5, 0);
			olList.PRINT_BY_GPA(gpa, outfile, infile);
		}


		else if (line == "PRINT_STUDENT") {
			//call readVariables
			readVariables(infile, idNum, firstName, lastName, major, gpa, credits, 0, 2, 3, 0, 0, 0);
			olList.PRINT_STUDENT(firstName, lastName, outfile, infile);
		}
		else if (line == "DELETE_STUDENT") {
			//call readVariables
			readVariables(infile, idNum, firstName, lastName, major, gpa, credits, 0, 2, 3, 0, 0, 0);
			olList.DELETE_STUDENT(firstName, lastName);
		}
		else if (line == "DELETE_ID") {
			//call readVariables
			readVariables(infile, idNum, firstName, lastName, major, gpa, credits, 1, 0, 0, 0, 0, 0);
			olList.DELETE_ID(idNum);
		}

		else if (line == "UPDATE_GPA") {
			//call readVariables
			readVariables(infile, idNum, firstName, lastName, major, gpa, credits, 0, 2, 3, 0, 5, 0);
			olList.UPDATE_GPA(firstName, lastName, gpa);
		}
		else if (line == "UPDATE_MAJOR") {
			//call readVariables
			readVariables(infile, idNum, firstName, lastName, major, gpa, credits, 0, 2, 3, 4, 0, 0);
			olList.UPDATE_MAJOR(firstName, lastName, major);
		}
		else if (line == "ADD_CLASS") {
			//call readVariables
			readVariables(infile, idNum, firstName, lastName, major, gpa, credits, 0, 2, 3, 0, 0, 6);
			olList.ADD_CLASS(firstName, lastName, credits);
		}
		else if (line == "REMOVE_CLASS")
		{
			//call readVariables
			readVariables(infile, idNum, firstName, lastName, major, gpa, credits, 0, 2, 3, 0, 0, 6);
			olList.REMOVE_CLASS(firstName, lastName, credits);
		}
		else if (line == "GPA") {
			olList.GPA(outfile);
		}
	}

}

void readVariables(ifstream & infile, string& idNum, string& firstName, string& lastName, string& major, string& gpa, string& credits, int b1, int b2, int b3, int b4, int b5, int b6)
{
	//while there are lines to be read
	while (infile.good())
	{
		string line2;
		getline(infile, line2);
		//store variables locally
		if (b1 == 1)
		{

			try {
				if (line2 == "")
					throw Exception(line2);
				if (line2.size() != 5)
					throw(idNum);
				idNum = line2;
			}
			catch (const string e)
			{
				idNum = "0";
				cout << "Your ID: " << e << " is the incorrect number of digits. It must be 5 digits long" << endl;
			}
			catch (Exception e)
			{
				idNum = "0";
				cout << e.argMissing() << endl;
			}
			b1 -= 1;
		}
		if (b2 == 2)
		{
			firstName = line2;
			b2 -= 2;
		}
		if (b3 == 3)
		{
			lastName = line2;
			b3 -= 3;
		}
		if (b4 == 4)
		{
			try {
				if (!checkMajor(line2))
					throw line2;
				if (line2 == "")
					throw Exception(line2);
				major = line2;
			}
			catch (Exception e) {
				major = "";
				cout << e.argMissing() << endl;
			}
			catch (string e)
			{
				cout << "Major is either in incorrect format or not listed" << endl;
				major = "";
				b5 = 5;
			}
			b4 -= 4;
		}
		if (b5 == 5)
		{
			try
			{
				if (line2 == "")
					throw Exception(line2);
				if (!checkGPA(line2))
					throw line2;
				gpa = line2;

			}
			catch (string e)
			{
				gpa = "0.00";
				cout << "Your GPA: " << e << " is in the incorrect GPA format. Example: 3.58 or 0.00. It must be a number in between 0.00 and 4.00" << endl;
			}
			catch (Exception e)
			{
				gpa = "0";
				cout << e.argMissing() << endl;
			}
			b5 -= 5;
		}
		if (b6 == 6)
		{
			try {
				if (line2 == "")
					throw Exception(line2);
				if (!checkCredits(line2))
					throw line2;

				credits = line2;
			}
			catch (string e)
			{
				credits = "0";
				cout << "Your credits: " << e << " is in the wrong format. It must be a whole number between 0 and 15." << endl;
			}
			catch (Exception e)
			{
				credits = "0";
				cout << e.argMissing() << endl;
				break;
			}

			b6 -= 6;
		}

		//if line is blank - BREAK
		if (line2 == "")
		{
			break;
		}
	}
}

bool checkGPA(string GPA2)
{
	double gpaNum = stod(GPA2);

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

bool checkCredits(string credits)
{
	bool flag{ true };
	int cr = stoi(credits);

	if (cr < 0 || cr > 15)
	{
		flag = false;
	}
	return flag;
}

bool checkMajor(string major)
{
	bool flag = true;
	for (char i : major)
	{
		if (i <65 || i > 90 && i < 97 || i > 122)
		{
			flag = false;
		}
		else
			flag = true;
	}
	return flag;
}

