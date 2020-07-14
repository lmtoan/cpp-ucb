// MODULE:		dynarr4d.cpp	
// PROGRAMMER:	Gary J. Blair
// LANGUAGE:	C++
// DATE:		96/04/11
//
// PURPOSE:
// 		Template for dynamic arrays.
//		Illustrate templates.  
//		Note that this header file contains the bodies of the member functions.
//		This is because the compiler is actually generating code for us.


#include        <iostream.h>
#include        <stdlib.h>  

template <class T>
class	DynamicArray
{ 
	public:
	DynamicArray( size_t	size );
	~DynamicArray(void);
	T&	operator[]( long subscript );
	size_t	size(void);  
	
	private:
	size_t		array_size;		// Size of the dynamic array.
	T			*data;			// Pointer to dynamic memory for the array.
	
};

		// Constructor.
	
template<class T> DynamicArray<T>::DynamicArray( size_t size )
{
	long 	i;	// Loop variable.
	
	data = new T[size];
	if (! data)
	{
		cerr	<< "*** Memory allocation failed.\n"; 
		exit(1);
	}
	array_size = size;

	// We have to eliminate the initialization to zero, because for 
	// non-numeric arrays,we don't know what the 'zero' value is!

}
	
		// Destructor.
		
template<class T> DynamicArray<T>::~DynamicArray(void)
{
	delete[]	data;
	array_size = 0;
}
	
		// Accessor function which returns a reference to an element of
		// the dynamically allocated memory.
		
template<class T> T&	DynamicArray<T>::operator[]( long  subscript )
{
	if (subscript < 0 || subscript > (array_size - 1))
		exit(1);
	return	data[subscript];
}
	
		// Inquire the size of the array.
		
template<class T> size_t	DynamicArray<T>::size(void)
{    
	return	array_size;
}           

