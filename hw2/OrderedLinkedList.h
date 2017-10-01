#pragma once

#include <string>
#include "nodeType.h"
#include "linkedListType.h"
#include <iostream>
using namespace std;

template<class Type>
class OrderedLinkedList : public linkedListType<Type>
{
private:
	int count;
public:
	OrderedLinkedList<Type>();

	void INSERT(nodeType<string>* next,
		nodeType<string>* previous, string idNum, string firstName,
		string lastName, string major, string gpa, string credits);
	void insertFirst(const Type& newItem);
	void insertLast(const Type& newItem);
	bool search(const Type& searchItem) const;
	void deleteNode(const Type& deleteItem);
	void PRINT_ROSTER(ofstream& outfile) const;
	void PRINT_BY_MAJOR(string& major, ofstream& outfile);
	void PRINT_BY_GPA(string& gpa, ofstream& outfile);
	void PRINT_STUDENT(string& firstName, string& lastName, ofstream& outfile);
	void DELETE_STUDENT(string& firstName, string& lastName);
	void DELETE_ID(string& id);
	void UPDATE_GPA(string& firstName, string& lastName, string& gpa);
	void UPDATE_MAJOR(string& firstName, string& lastName, string& major);
	void ADD_CLASS(string& firstName, string& lastName, string& credits);
	void REMOVE_CLASS(string& firstName, string& lastName, string& credits);
	void GPA(ofstream& outfile);
};

template <class Type>
OrderedLinkedList<Type>::OrderedLinkedList() : linkedListType()
{
	this->count = 0;
}




template<class Type>
void OrderedLinkedList<Type>::INSERT(nodeType<string>* next,
	nodeType<string>* previous, string idNum, string firstName,
	string lastName, string major, string gpa, string credits)
{


	nodeType<string> * node = new nodeType<string>
		(nullptr, nullptr, idNum, firstName, lastName, major, gpa, credits);
	count++;
	//if the file is empty just insert the node
	if (this->isEmptyList()) {
		node->next = this->last;
		node->previous = this->first;
		this->first = node;
		this->last = node;
	}
	//if the file is not empty, walk through the list to find the alphabetical position to insert the node.
	else if (!this->isEmptyList()){
		nodeType<string>* reader = this->first;
		//while reader is not null and (the passed in last name is greater than reader or (the last names are equal and the passed in first name is greater than reader))
		while (reader && (lastName > reader->lastName || (lastName == reader->lastName && firstName > reader->firstName)))
		{
			reader = reader->next;
		}

		//If the names are equal, compare ID numbers and reject duplicates
		if(reader && reader->lastName == lastName)
		{
			if(reader->firstName == firstName || reader->idNum == idNum)
			{
				cout << "Duplicate entry. Input rejected." << endl;
				delete node;
				count--;
			}
			//if not, order by first name
			else
			{
				//insert in front of reader
				if(reader->firstName > firstName)
				{
					node->next = reader;
					node->previous = reader->previous;
					//If the if the node that reader landed on is not the first node
					if (reader->previous != nullptr) {
						reader->previous->next = node;
					}
					reader->previous = node;

					//If the node we are inserting in front of is the first item in the list, point first to the new node to 
					//avoid losing the new nodes
					if (this->first == reader)
					{
						this->first = node;
					}
				}
				else
				{
					node->previous = reader;
					node->next = reader->next;
					//If the if the node that reader landed on is the last node
					if (reader->next != nullptr) {
						reader->next->previous = node;
					}
					reader->next = node;
					if(this->last == reader)
					{
						this->last = node;
					}
				}
			}
		}

		//If we've made it to the very end of the list
		else if(reader == nullptr)
		{
			node->next = nullptr;
			node->previous = this->last;
			this->last->next = node;
			this->last = node;
		}
		//Insert in front of the node that reader stopped on
		else
		{
			
			node->next = reader;
			node->previous = reader->previous;
			//If the if the node that reader landed on 
			if (reader->previous != nullptr){
				reader->previous->next = node;
			}
			reader->previous = node;
			
			//If the node we are inserting in front of is the first item in the list, point first to the new node to 
			//avoid losing the new nodes
			if(this->first == reader)
			{
				this->first = node;
			}
		}
		
	}
}

template<class Type>
void OrderedLinkedList<Type>::insertFirst(const Type& newItem)
{
	
}

template<class Type>
void OrderedLinkedList<Type>::insertLast(const Type& newItem)
{
	
}

template <class Type>
bool OrderedLinkedList<Type>::search(const Type& searchItem) const
{
	return true;
}

template <class Type>
void OrderedLinkedList<Type>::deleteNode(const Type& deleteItem)
{
	
}



template<class Type>
void OrderedLinkedList<Type>::PRINT_ROSTER(ofstream& outfile) const
{

	nodeType<string>* reader = this->first;
	while(reader)
	{
		outfile << reader->firstName << " " << reader->lastName << ", " << reader->idNum << endl;
		reader = reader->next;
	}
	outfile << endl;
}

template<class Type>
void OrderedLinkedList<Type>::PRINT_BY_MAJOR(string& major, ofstream& outfile)
{
	nodeType<string>* reader = this->first;
	while(reader)
	{
		if(reader->major == major)
		{
			outfile << reader->firstName << " " << reader->lastName << ", " << reader->idNum << endl << endl;
		}
		reader = reader->next;
	}
}

template<class Type>
void OrderedLinkedList<Type>::PRINT_BY_GPA(string& gpa, ofstream& outfile)
{
	nodeType<string>* reader = this->first;
	while (reader)
	{
		double GPA1 = stod(gpa);
		double GPA2 = stod(reader->gpa);
		if(GPA2 >= GPA1)
		{
			outfile << reader->firstName << " " << reader->lastName << ", " << reader->idNum << endl << endl;
		}
		reader = reader->next;
	}
}

template <class Type>
void OrderedLinkedList<Type>::PRINT_STUDENT(string& firstName, string& lastName, ofstream& outfile)
{
	nodeType<string>* reader = this->first;
	while(reader->lastName != lastName && reader->firstName != firstName)
	{
		reader = reader->next;
	}

	outfile << reader->firstName << " " << reader->lastName << ", " << reader->idNum << endl
		<< "Major: " << reader->major << endl << "GPA: " << reader->gpa << endl << "Credits Enrolled: " << reader->credits << endl << endl;
}

template<class Type>
void OrderedLinkedList<Type>::DELETE_STUDENT(string & firstName, string & lastName)
{
	nodeType<string>* reader = this->first;
	while(reader->lastName != lastName && reader->firstName != firstName)
	{
		reader = reader->next; 
	}
	if (reader->previous != nullptr) {
		reader->previous->next = reader->next;
	}
	else
	{
		this->first = reader->next;
	}
	if (reader->next != nullptr) {
		reader->next->previous = reader->previous;
	}
	else
	{
		this->last = reader->previous;
	}
	delete reader;
}

template<class Type>
void OrderedLinkedList<Type>::DELETE_ID(string & id)
{
	nodeType<string>* reader = this->first;
	while (reader->idNum != id)
	{
		reader = reader->next;
	}
	if (reader->previous != nullptr) {
		reader->previous->next = reader->next;
	}
	else
	{
		this->first = reader->next;
	}
	if (reader->next != nullptr) {
		reader->next->previous = reader->previous;
	}
	else
	{
		this->last = reader->previous;
	}
	delete reader;
}

template<class Type>
void OrderedLinkedList<Type>::UPDATE_GPA(string & firstName, string & lastName, string& gpa)
{
	nodeType<string>* reader = this->first;
	while (reader->lastName != lastName && reader->firstName != firstName)
	{
		reader = reader->next;
	}
	reader->gpa = gpa;
}

template<class Type>
void OrderedLinkedList<Type>::UPDATE_MAJOR(string & firstName, string & lastName, string & major)
{
	nodeType<string>* reader = this->first;
	while (reader->lastName != lastName && reader->firstName != firstName)
	{
		reader = reader->next;
	}
	reader->major = major;
}

template<class Type>
void OrderedLinkedList<Type>::ADD_CLASS(string & firstName, string & lastName, string& credits)
{
	nodeType<string>* reader = this->first;
	while (reader->lastName != lastName && reader->firstName != firstName)
	{
		reader = reader->next;
	}
	const int cr1 = stoi(reader->credits);
	const int cr2 = stoi(credits);
	reader->credits = to_string(cr1 + cr2);

}

template<class Type>
void OrderedLinkedList<Type>::REMOVE_CLASS(string & firstName, string & lastName, string& credits)
{
	nodeType<string>* reader = this->first;
	while (reader->lastName != lastName && reader->firstName != firstName)
	{
		reader = reader->next;
	}
	const int cr1 = stoi(reader->credits);
	const int cr2 = stoi(credits);
	reader->credits = to_string(cr1 - cr2);
}

template<class Type>
void OrderedLinkedList<Type>::GPA(ofstream& outfile)
{
	double total{ 0 };
	nodeType<string>* reader = this->first;
	while (reader)
	{
		total += stod(reader->gpa);
		reader = reader->next;
	}
	const double mean = total / count;

	outfile << "GPA mean: " << mean << endl;
}
