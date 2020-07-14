// MODULE:		distanc5.cpp	
// PROGRAMMER:	Gary J. Blair
// LANGUAGE:	C++
// DATE:		96/04/11
//
// PURPOSE:
//		Provide a class for English distances.  
//		Illustrate overloading of ++ operator.

#include        <iostream.h>
#include        <stdlib.h>   
#include		"dist5.h"

void	main(void)
{                                                     
	Distance	a;
	Distance	b(5.2);		// Initialize b to 5.2 meters.
	Distance	c;
	float		x;

	a = 2.5;				// Constructor called for conversion.
	
	cout	<< "2.5m = " << a << endl;
	cout	<< "5.2m = " << b << endl;
	
	c = Distance(3.8) + b;	// Explicit use of conversion constructor.
	cout	<< "c = 3.8m + " << b << " = " << c << endl;
	
	x = c;
	cout	<< c << " = " << x << "m\n";
	c = x;
	cout	<< "After converting to metric then back to English c = "
			<< c << endl;	
}
 
