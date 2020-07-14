// MODULE:		dynarr1.cpp	
// PROGRAMMER:	Gary J. Blair
// LANGUAGE:	C++
// DATE:		96/04/11
//
// PURPOSE:
//		Emplementation for class DynamicIntArray.
//		Illustrate dynamic integer arrays with subscript checking.
//		Illustrate new, copy constructor, overloading [].  

#include        <iostream.h>
#include        <stdlib.h>
#include		<string.h>
#include		"dynarr1.h"

		// Constructor.
	
DynamicIntArray::DynamicIntArray( size_t size, const char * const name )
{
	size_t	i;	// Loop variable.
	
	cout	<< "constructor called for " << name << endl;
	data = new int[size];
	if (! data)
	{
		cerr	<< "*** Memory allocation failed.\n"; 
		exit(1);
	}
	array_size = size;
	for (i=0; i<array_size; ++i)
		data[i] = 0;
	strcpy(array_name,name);
}

	 
		// Copy Constructor.
	
DynamicIntArray::DynamicIntArray( const DynamicIntArray& rhs )
{ 
	size_t	i;	// Loop variable.
	
	cout	<< "Copy constructor called to copy " << rhs.array_name << endl;
	
	data = new int[rhs.array_size];
	if (! data)
	{
		cerr	<< "*** Memory allocation failed.\n"; 
		exit(1);
	}
	array_size = rhs.array_size;
	for (i=0; i<array_size; ++i)
		data[i] = rhs.data[i];
	strcpy(array_name,"copy of ");
	strcat(array_name,rhs.array_name);
}
	
		// Destructor.
		
DynamicIntArray::~DynamicIntArray(void)
{
	delete	data;
	array_size = 0;
	cout	<< "Destructor called for " << array_name << endl;
}
	
		// Assignment operator=.
		
DynamicIntArray&	DynamicIntArray::operator=(DynamicIntArray& rhs)
{
	size_t	i;	// Loop variable.
	
	cout	<< "operator= called to copy " << rhs.array_name << " to " 
			<< array_name << endl;
	
	if (this == &rhs)
		return	*this;
	if (array_size != rhs.array_size)
	{
		delete	data;		// Deallocate current space.
		data = new int[rhs.array_size];
		if (! data)
		{
			cerr	<< "*** Memory allocation failed.\n"; 
			exit(1);
		}
		array_size = rhs.array_size;
	}
	for (i=0; i<array_size; ++i)
		data[i] = rhs.data[i];
	return	*this;
}
	
		// Accessor function which returns a reference to an element of
		// the dynamically allocated memory.
		
int&	DynamicIntArray::operator[]( long subscript )
{
	if (subscript < 0 || subscript > (array_size - 1))
	{
		cerr	<<	"*** Out of range subscript = " << subscript << endl;
		exit(1);
	}
	return	data[subscript];
}
		
const int&	DynamicIntArray::operator[]( long subscript ) const
{
	cout << "Invoked const operator[]\n";
	if (subscript < 0 || subscript > (array_size - 1))
	{
		cerr	<<	"*** Out of range subscript = " << subscript << endl;
		exit(1);
	}
	return	data[subscript];
}
	
		// Inquire the size of the array.
		
size_t	DynamicIntArray::size(void)
{    
	return	array_size;
}           
