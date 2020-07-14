// MODULE:		distanc4.cpp	
// PROGRAMMER:	Gary J. Blair
// LANGUAGE:	C++
// DATE:		96/04/11
//
// PURPOSE:
//		Provide a class for English distances.  
//		Illustrate overloading of ++ operator.

#include        <iostream.h>
#include        <stdlib.h>   
#include		"dist4.h"

void	main(void)
{                                                     
	Distance	a(3,6.0);
	Distance	b;

	b = a;
	
	cout	<< "Initially a=" << a << " and b=" << b << endl;
	++a;
	b++;
	cout	<< "After preincrementing,  a=" << a << endl;
	cout	<< "After postincrementing, b=" << b << endl;	
	
	if (a == b)
		cout	<< a << " is equal to " << b << endl;
	else
		cout	<< a << " is not equal to " << b << endl;
		
	cout	<< a << " + " << b << " = ";
	a += b;
	cout	<< a << endl;
	
	Distance	x(4,5.0);
	
	cout	<< x << endl;
	x.operator++();
	cout	<< x << endl;
	x.operator++(3);
	cout	<< x << endl;	
}
 
