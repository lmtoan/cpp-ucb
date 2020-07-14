// MODULE:		dynarr2d.cpp	
// PROGRAMMER:	Gary J. Blair
// LANGUAGE:	C++
// DATE:		96/04/11
//
// PURPOSE:
// 		Driver for dynarr2 exercise.
//		Illustrate exceptions.  


#include        <iostream.h>
#include        <stdlib.h>  
#include		<string.h>

class	DynamicIntArray
{ 
	public:
	DynamicIntArray( size_t	size, const char * const name );
	~DynamicIntArray(void);
	int&	operator[]( long subscript );
	size_t	size(void);  
	
	class SubscriptError {}; // Exception class.
	
	private:
	size_t		array_size;		// Size of the dynamic array.
	char		array_name[80];	// For educational purposes only.
	int			*data;			// Pointer to dynamic memory for the array.
	
};

		// Constructor.
	
DynamicIntArray::DynamicIntArray( size_t size, const char * const name )
{
	long	i;	// Loop variable.
	
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
	
		// Destructor.
		
DynamicIntArray::~DynamicIntArray(void)
{
	delete	data;
	array_size = 0;
	cout	<< "Destructor called for " << array_name << endl;
}
	
		// Accessor function which returns a reference to an element of
		// the dynamically allocated memory.
		
int&	DynamicIntArray::operator[]( long subscript )
{
	if (subscript < 0 || subscript > (array_size - 1))
		throw SubscriptError();
	return	data[subscript];
}
	
		// Inquire the size of the array.
		
size_t	DynamicIntArray::size(void)
{    
	return	array_size;
}           


void	main(void)
{ 
	DynamicIntArray		x(23,"x");
	long				i;
	
	for (i=0; i<23; ++i)
		x[i] = i * i;
	
	try
	{	
		cout	<< "x[13]=" << x[13] << endl;
		cout	<< "x[27]=" << x[27] << endl;
	}
	catch (DynamicIntArray::SubscriptError)
	{
		cout	<< "*** Subscript error accessing array.\n";
	}
}
