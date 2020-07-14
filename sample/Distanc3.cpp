// MODULE:		distanc3.cpp	
// PROGRAMMER:	Gary J. Blair
// LANGUAGE:	C++
// DATE:		96/04/11
//
// PURPOSE:
//		Provide a class for English distances.  
//		Illustrate operator overloading in classes.
//		Illustrate friend functions.

#include        <iostream.h>
#include        <stdlib.h>   
#include		"distance.h"

void	main(void)
{                                                     
	Distance	a;
	Distance	b(3,6.5);
	Distance	total;
	
	total = a + b;
	cout	<< a << " + " << b << " = " << total << endl;
	
	cout << "Enter 2 distances ";
	cin >> a >> b;
	total = a + b;
	cout	<< a << " + " << b << " = " << total << endl;
}
 
