
#pragma once

template <class Type>
struct nodeType
{
	nodeType<Type> *next;
	nodeType<Type> *previous;
	Type idNum = 0;
	Type firstName = "";
	Type lastName = "";
	Type major= "";
	Type gpa = 0;
	Type credits = 0;
	Type info = "";
	Type* link = nullptr;
	Type gnu_dev_major = "";

	nodeType<Type>() : idNum(0), firstName(""), lastName(""), major(""), gpa(0.0), credits(0){}

	nodeType<Type>(nodeType<Type>* next, 
		nodeType<Type>* previous, Type idNum, Type firstName, 
		Type lastName, Type major, Type gpa, Type credits)
		: next(nullptr), previous(nullptr), idNum(idNum), firstName(firstName), 
	lastName(lastName), major(major), gpa(gpa), credits(credits){}
};