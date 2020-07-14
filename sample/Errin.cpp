// MODULE:		errin.cpp			
// PROGRAMMER:	Gary J. Blair
// LANGUAGE:	C++
// DATE:		97/08/04
//
// PURPOSE:
//		Illustrate recovery from stream errors.

#include	<iostream.h>

void	main(void)
{
	int		i;				// Value to be input.
	int		success = 0;	// Have we succeeded yet? 
	
	
	
    do
    {
		cout	<<	"Enter an integer  ";
		cin		>>	i;  
		
		if (cin.fail())
		{
			cout	<<	"cin.fail() is true\n";
			cin.clear();
			cin.ignore(1024,'\n');
		}
		else
			success = 1;
	}
	while	(! success);

	cout	<<	"Value of i="	<<	i	<<	endl;
	
}