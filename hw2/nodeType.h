#pragma once

template <class Type>
struct nodeType
{
	nodeType<Type> *next;
	nodeType<Type> *previous;
	Type idNum;
	Type firstName;
	Type lastName;
	Type tmajor;
	Type gpa;
	Type credits;
	
	//don't use
	Type info = "";
	Type* link = nullptr;
	//Type gnu_dev_major = "";

	nodeType<Type>(nodeType<Type>* next, 
		nodeType<Type>* previous, Type idNum, Type firstName, 
		Type lastName, Type tmajor, Type gpa, Type credits)
		: next(nullptr), previous(nullptr), idNum(idNum), firstName(firstName), 
	lastName(lastName), tmajor(tmajor), gpa(gpa), credits(credits){}

	nodeType<Type>() : idNum(0), firstName(""), lastName(""), tmajor(""), gpa(0.0), credits(0) {}

};