// hw2.cpp : Defines the entry point for the console application.
//

#include <string>
#include <fstream>
#include "ArgumentManager.h"
#include "OrderedLinkedList.h"
#include "Exception.h"
#include "CreditCheck.h"
#include "IDCheck.h"
#include "FirstNameCheck.h"
#include "LastNameCheck.h"
#include "MajorCheck.h"
#include "GPACheck.h"

using namespace std;

bool isNumber(string str);
bool checkID(string idNum);
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
		//if line is print_roster, read the following cariables and call respecting method
		else if (line == "PRINT_ROSTER")
		{
			readVariables(infile, idNum, firstName, lastName, major, gpa, credits, 0, 0, 0, 0, 0, 0);
			olList.PRINT_ROSTER(outfile);
			outfile << endl;
		}

		//if line is print_by_major, read the following cariables and call respecting method
		else if (line == "PRINT_BY_MAJOR")
		{
			readVariables(infile, idNum, firstName, lastName, major, gpa, credits, 0, 0, 0, 4, 0, 0);
			olList.PRINT_BY_MAJOR(major, outfile);
			outfile << endl;
		}

		//if line is print_by_gpa, read the following cariables and call respecting method
		else if (line == "PRINT_BY_GPA") {
			//call read variables
			readVariables(infile, idNum, firstName, lastName, major, gpa, credits, 0, 0, 0, 0, 5, 0);
			olList.PRINT_BY_GPA(gpa, outfile);
			outfile << endl;
		}

		//if line is print_student, read the following cariables and call respecting method

		else if (line == "PRINT_STUDENT") {
			//call readVariables
			readVariables(infile, idNum, firstName, lastName, major, gpa, credits, 0, 2, 3, 0, 0, 0);
			olList.PRINT_STUDENT(firstName, lastName, outfile);
			outfile << endl;
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
	IDCheck idc{};
	MajorCheck majc{};
	FirstNameCheck fnc{};
	LastNameCheck lnc{};
	GPACheck gpac{};
	CreditCheck cc{};


	//while there are lines to be read
	while (infile.good())
	{

		string line2;
		getline(infile, line2);
		//store variables locally
		if (b1 == 1)
		{
			try {
				//if the line is blank there is an argument missing
				if (line2 == "")
					throw Exception(line2);
				//check if input is valid
				else if (!idc.checkID(line2))
					throw(idc);
				idNum = line2;
			}
			
			catch (IDCheck& e)
			{
				//set number to default value
				idNum = "0";
				//if the parameter fits the description for the first name, that means the ID is missing and we can store the line in firstname
				if (fnc.checkFN(line2)) {
					firstName = line2;
					b2 -= 2;
					cout << e.idFormat() << endl;
				}
			}
			catch (Exception e)
			{
				//set number to default value
				idNum = "0";
				cout << e.argMissing() << endl;
			}
			b1 -= 1;
		}
		else if (b2 == 2)
		{
			try
			{
				//validate first name
				if (!fnc.checkFN(line2))
					throw(fnc);
				firstName = line2;
				b2 -= 2;

			}
			catch (FirstNameCheck& e)
			{
				cout << e.fnFormat() << endl;
			}
		}
		else if (b3 == 3)
		{
			try
			{
				//check input validity
				if (!lnc.checkLN(line2))
					throw(lnc);
				lastName = line2;
				b3 -= 3;
			}
			catch (LastNameCheck & e)
			{
				cout << e.lnFormat() << endl;
			}
		}
		else if (b4 == 4)
		{
			try {
				//validate input
				if (!MajorCheck::isLetter(line2))
					throw majc;
				if (line2 == "")
					throw Exception(line2);
				major = line2;
			}
			catch (Exception e) {
				major = "Unknown";
				cout << e.argMissing() << endl;
			}
			catch (MajorCheck e)
			{
				cout << majc.majFormat(line2) << endl;
				major = "Unknown";
				//if the argument fits the description for gpa, store it in gpa
				if(gpac.checkGPA(line2))
				{
					gpa = line2;
					b5 -= 5;
				}
				//if the argument fits the description for credits, store it in credits
				if(cc.checkCredits(line2))
				{
					credits = line2;
					b6 -= 6;
				}
			}
			b4 -= 4;
		}
		else if (b5 == 5)
		{

			try
			{
				if (line2 == "")
					throw Exception(line2);
				//validate input
				if (!gpac.checkGPA(line2))
					throw gpac;
				gpa = line2;

			}
			catch (GPACheck& e)
			{
				gpa = "0.00";
				cout << e.gpaFormat(line2) << endl;
				//if the argument fits the description for credits
				if(cc.checkCredits(line2))
				{
					credits = line2;
					b6 -= 6; 
				}
			}
			catch (Exception e)
			{
				gpa = "0.00";
				cout << e.argMissing() << endl;
			}
			b5 -= 5;
		}
		else if (b6 == 6)
		{
			try {
				//check for missing arguments
				if (line2 == "")
					throw Exception(line2);
				//validate input
				if (!cc.checkCredits(line2))
					throw cc;

				credits = line2;
			}
			catch (CreditCheck& e)
			{
				credits = "0";
				cout << e.creditFormat(line2) << endl;
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
