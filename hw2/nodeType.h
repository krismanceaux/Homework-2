
#pragma once

template <class Type1, class Type2, class Type3>
struct nodeType
{
	nodeType<Type1, Type2, Type3> *next;
	nodeType<Type1, Type2, Type3> *previous;
	Type1 idNum = 0;
	Type2 firstName = "";
	Type2 lastName = "";
	Type2 major= "";
	Type3 gpa = 0;
	Type1 credits = 0;

	nodeType<Type1, Type2, Type3>() : idNum(0), firstName(""), lastName(""), major(""), gpa(0.0), credits(0){}

	nodeType<Type1, Type2, Type3>(nodeType<Type1, Type2, Type3>* next, 
		nodeType<Type1, Type2, Type3>* previous, Type1 idNum, Type2 firstName, 
		Type2 lastName, Type2 major, Type3 gpa, Type1 credits)
		: next(nullptr), previous(nullptr), idNum(idNum), firstName(firstName), 
	lastName(lastName), major(major), gpa(gpa), credits(credits){}
};