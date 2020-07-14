// MODULE:		dynarr1d.cpp	
// PROGRAMMER:	Gary J. Blair
// LANGUAGE:	C++
// DATE:		96/04/11
//
// PURPOSE:
// 		Driver for dynarr1 exercise.
//		Illustrate dynamic integer arrays with subscript checking.
//		Illustrate new, copy constructor, overloading [], destructors.  


#include        <iostream.h>
#include        <stdlib.h>
#include		"dynarr1.h"

void	create_array( size_t size );
void	print_array( DynamicIntArray a );
void	newfunc( const DynamicIntArray& a);

void	main(void)
{
	size_t	size;
	             
	cout	<< "Enter the array size ";
	cin		>> size;
	create_array(size);
	cout	<< "main terminating.\n";
}

void	create_array( size_t size )
{
	DynamicIntArray		x(size,"x");	// Dynamic array.
	long				i;				// Loop variable.
	DynamicIntArray		*p;				// Pointer to DynamicIntArray.
	
	cout	<< "The size of x is " << x.size() << endl;

	x[0] = 1;
	x[1] = 1;
	for (i=2; i<x.size(); ++i)
		x[i] = x[i-1] + x[i-2];
	print_array(x);
	
	cout << "Initializing y to x.\n";
	DynamicIntArray		y = x;			// Demonstrate copy constructor.
	
	p = new DynamicIntArray(3,"*p");
	cout	<< "The size of *p is " << p->size() << endl;
	(*p)[0] = 1996;
	(*p)[1] = 5;
	(*p)[2] = 30;
	print_array(*p);	
	*p = x;
	cout	<< "The size of *p is now " << p->size() << endl;
	print_array(*p);
	delete p;    
	newfunc(x);
	                                       
	cout	<< "create_array returning.\n";
}

void	print_array( DynamicIntArray a )
{
	size_t				i;			// Loop variable.

	for (i=0; i<a.size(); ++i)
		cout	<< "a[" << i << "] = " << a[i] << endl;
	cout	<< "print_array returning.\n";	
}

void newfunc( const DynamicIntArray& a )
{
	cout << "a[0]=" << a[0] << '\n';
}