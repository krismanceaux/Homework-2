// hw2.cpp : Defines the entry point for the console application.
//

#include <string>
#include <sstream>
#include <fstream>
#include "ArgumentManager.h"
#include "OrderedLinkedList.h"

using namespace std;

void readMajor(ifstream& infile, string& major);
void readCredits(ifstream& infile, string& credits);
void readID(ifstream& infile, string& id);
void readNames(ifstream& infile, string& firstName, string& lastName);
void readGPA(ifstream& infile, string& gpa);
void readMajorVariables(string& major, ifstream& infile);
void readFile(ifstream & infilename, ofstream& outfilename, OrderedLinkedList<nodeType<string>>& olList);
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
	ofstream outfile(outfilename);
	readFile(infile, outfile, olList);
	infile.close();

	//olList.PRINT_ROSTER(outfile);


	

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
			readVariables(infile, idNum, firstName, lastName, major, gpa, credits);
			
			olList.INSERT(nullptr, nullptr, idNum, firstName, lastName, major, gpa, credits);
		}
		else if (line == "PRINT_ROSTER")
		{
			readVariables(infile, idNum, firstName, lastName, major, gpa, credits);
			olList.PRINT_ROSTER(outfile);
		}

		else if (line == "PRINT_BY_MAJOR")
		{
			readVariables(infile, idNum, firstName, lastName, major, gpa, credits);
			olList.PRINT_BY_MAJOR(major, outfile);
		}
			

		else if (line == "PRINT_BY_GPA") {
			//call read variables
			readGPA(infile, gpa);
			olList.PRINT_BY_GPA(gpa, outfile);
		}


		else if (line == "PRINT_STUDENT") {
			//call readVariables
			readNames(infile, firstName, lastName);
			olList.PRINT_STUDENT(firstName, lastName, outfile);
		}
		else if (line == "DELETE_STUDENT") {
			//call readVariables
			readNames(infile, firstName, lastName);
			olList.DELETE_STUDENT(firstName, lastName);
		}
		else if (line == "DELETE_ID") {
			//call readVariables
			readID(infile, idNum);
			olList.DELETE_ID(idNum);
		}

		else if (line == "UPDATE_GPA") {
			//call readVariables
			readNames(infile, firstName, lastName);
			readGPA(infile, gpa);
			olList.UPDATE_GPA(firstName, lastName, gpa);
		}
		else if (line == "UPDATE_MAJOR") {
			//call readVariables
			readNames(infile, firstName, lastName);
			readMajor(infile, major);
			olList.UPDATE_MAJOR(firstName, lastName, major);
		}
		else if (line == "ADD_CLASS") {
			//call readVariables
			readNames(infile, firstName, lastName);
			readCredits(infile, credits);
			olList.ADD_CLASS(firstName, lastName, credits);
		}
		else if (line == "REMOVE_CLASS")
		{
			//call readVariables
			readNames(infile, firstName, lastName);
			readCredits(infile, credits);
			olList.REMOVE_CLASS(firstName, lastName, credits);
		}
		else if (line == "GPA") {
			olList.GPA(outfile);
		}
	}

}

void readVariables(ifstream & infile, string& idNum, string& firstName, string& lastName, string& major, string& gpa, string& credits)
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

void readMajorVariables(string& major, ifstream& infile)
{
	int count{ 0 };
	//while there are lines to be read
	while (infile.good())
	{

		string line2;
		getline(infile, line2);
		stringstream ss(line2);
		//store variables locally
		if (count == 0) {
			ss >> major;
		}
		count++;

		//if line is blank - BREAK
		if (line2 == "")
		{
			break;
		}

		ss.str("");
		ss.clear();
	}
}

void readNames(ifstream& infile, string& firstName, string& lastName)
{
	int count{ 0 };
	//while there are lines to be read
	while (infile.good())
	{
		string line2;
		getline(infile, line2);
		stringstream ss(line2);
		//store variables locally
		if (count == 0) {
			ss >> firstName;
		}
		else if(count == 1)
		{
			ss >> lastName;
		}
		count++;

		//if line is blank - BREAK
		if (line2 == "")
		{
			break;
		}

		ss.str("");
		ss.clear();
	}

}

void readGPA(ifstream& infile, string& gpa)
{
	int count{ 0 };
	//while there are lines to be read
	while (infile.good())
	{
		string line2;
		getline(infile, line2);
		stringstream ss(line2);
		//store variables locally
		if (count == 0) {
			ss >> gpa;
		}
		count++;

		//if line is blank - BREAK
		if (line2 == "")
		{
			break;
		}

		ss.str("");
		ss.clear();
	}
}
void readID(ifstream& infile, string& id)
{
	int count{ 0 };
	//while there are lines to be read
	while (infile.good())
	{
		string line2;
		getline(infile, line2);
		stringstream ss(line2);
		//store variables locally
		if (count == 0) {
			ss >> id;
		}
		count++;

		//if line is blank - BREAK
		if (line2 == "")
		{
			break;
		}

		ss.str("");
		ss.clear();
	}
}
void readCredits(ifstream& infile, string& credits)
{
	int count{ 0 };
	//while there are lines to be read
	while (infile.good())
	{
		string line2;
		getline(infile, line2);
		stringstream ss(line2);
		//store variables locally
		if (count == 0) {
			ss >> credits;
		}
		count++;

		//if line is blank - BREAK
		if (line2 == "")
		{
			break;
		}

		ss.str("");
		ss.clear();
	}
}
void readMajor(ifstream& infile, string& major)
{
	int count{ 0 };
	//while there are lines to be read
	while (infile.good())
	{
		string line2;
		getline(infile, line2);
		stringstream ss(line2);
		//store variables locally
		if (count == 0) {
			ss >> major;
		}
		count++;

		//if line is blank - BREAK
		if (line2 == "")
		{
			break;
		}

		ss.str("");
		ss.clear();
	}
}
