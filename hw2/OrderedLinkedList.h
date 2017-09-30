#pragma once

#include <string>
#include "nodeType.h"
#include "linkedListType.h"
#include <iostream>
using namespace std;

template<class Type>
class OrderedLinkedList : public linkedListType<Type>
{

public:
	OrderedLinkedList<Type>();

	void INSERT(nodeType<int, string, double>* next,
		nodeType<int, string, double>* previous, int idNum, string firstName,
		string lastName, string major, double gpa, int credits);
	void insertFirst(const Type& newItem);
	void insertLast(const Type& newItem);
	bool search(const Type& searchItem) const;
	void deleteNode(const Type& deleteItem);
	void PRINT_ROSTER() const;
	void PRINT_BY_MAJOR(string major);
	void PRINT_BY_GPA(string gpa);
	void PRINT_STUDENT(string firstName, string lastName);
	void DELETE_STUDENT(string firstName, string lastName);
	void DELETE_ID(string id);
	void UPDATE_GPA(string firstName, string lastName);
	void UPDATE_MAJOR(string firstName, string lastName, string major);
	void ADD_CLASS(string firstName, string lastName, int credits);
	void REMOVE_CLASS(string firstName, string lastName, int credits);
	double GPA();
};

template <class Type>
OrderedLinkedList<Type>::OrderedLinkedList() : linkedListType()
{}




template<class Type>
void OrderedLinkedList<Type>::INSERT(nodeType<int, string, double>* next,
	nodeType<int, string, double>* previous, int idNum, string firstName,
	string lastName, string major, double gpa, int credits)
{
	nodeType<int, string, double> * node = new nodeType<int, string, double>
		(nullptr, nullptr, idNum, firstName, lastName, major, gpa, credits);
	if (this->isEmptyList()) {
		node->next = this->last;
		node->previous = this->first;
		this->first = node;
		this->last = node;
	}
	else if (!this->isEmptyList()){
		node->next = nullptr;
		node->previous = this->last;
		this->last->next = node;
		this->last = node;
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
void OrderedLinkedList<Type>::PRINT_ROSTER() const
{
	nodeType<int, string, double>* reader = first;
	while(reader)
	{
		cout << reader->idNum << endl << reader->firstName << endl 
		<< reader->lastName << endl << reader->major << endl << reader->gpa << 
			endl << reader->credits << endl << endl;
		reader = reader->next;
	}
}
