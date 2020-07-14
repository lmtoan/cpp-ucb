// MODULE:		dynarr1.h	
// PROGRAMMER:	Gary J. Blair
// LANGUAGE:	C++
// DATE:		96/04/11
//
// PURPOSE:
//		Declarations for class DynamicIntArray.
//		Illustrate dynamic integer arrays with subscript checking.
//		Illustrate new, copy constructor, overloading [], destructors.

#include        <iostream.h>
#include        <stdlib.h> 

class	DynamicIntArray
{ 
	public:
	 
		// Constructor.
	
	DynamicIntArray( size_t	size, const char * const name );
	 
		// Copy Constructor.
	
	DynamicIntArray( const DynamicIntArray& rhs );
	
		// Destructor.
		
	~DynamicIntArray(void);
	
		// Assignment operator=.
		
	DynamicIntArray&	operator=(DynamicIntArray& rhs);
	
		// Accessor function which returns a reference to an element of
		// the dynamically allocated memory.
		
	int&			operator[]( long subscript );
		
	const int&		operator[]( long subscript ) const;
	
		// Inquire the size of the array.
		
	size_t	size(void);
	
	
	private:
	size_t		array_size;		// Size of the dynamic array.
	char		array_name[80];	// For educational purposes only.
	int			*data;			// Pointer to dynamic memory for the array.
	
};
