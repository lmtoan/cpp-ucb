// MODULE:		dblstk1.h
// PROGRAMMER:	Gary J. Blair
// LANGUAGE:	C++
// DATE:		96/07/03	
//
// PURPOSE:
//		Declarations for class DoubleStack.

#include	<stdlib.h>

class	DoubleStack
{ 
	public:
	 
		// Constructor.
	
	DoubleStack( size_t	capacity  );
	 
		// Copy Constructor.
	
	DoubleStack( const DoubleStack& rhs );
	
		// Destructor.
		
	~DoubleStack(void);
	
		// Assignment operator=.
		
	DoubleStack&	operator=( DoubleStack& rhs);

		// Add item to stack, making it the topmost item.
		// Return value 1=success/0=failure.

	int	push( double&	item );

		// Remove top item from stack and return it in item.
		// Return value 1=success/0=failure.

	int	pop( double&	item );

		// Determine if the stack is empty.
		// Return value 1=empty/0=non-empty.

	int	empty(void);
	
		// Inquire the capacity of the stack.
		
	size_t	capacity(void);
	
		// Inquire the number of items on the stack.
		
	size_t	size(void);

		// Compare 2 stacks to see if the contain the same data.

	int	operator==( DoubleStack&	rhs );
	
	private:
	double	*data;		// Pointer to dynamic stack area.
	size_t	stack_size;	// Capacity of stack.
	size_t	tos;		// Top of stack. tos==0 ==> empty stack.
};

