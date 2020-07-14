// MODULE:		mammal1.cpp	
// PROGRAMMER:	Gary J. Blair
// LANGUAGE:	C++
// DATE:		96/04/11
//
// PURPOSE:
// 		Illustrate name hiding. 
//

#include        <iostream.h>
#include        <stdlib.h>

class	Mammal
{ 
	public:
	void	Move() const { cout << "Mammal moves 1 step.\n"; };
	void	Move( int distance ) const
			{ cout << "Mammal moves " << distance << " steps.\n"; };
	
	protected:
	int		age;
	int		weight;
};                 

class	Dog : public Mammal
{ 
	public:
	void	Move() const { cout << "Dog moves 2 steps.\n"; };
	
		// You may receive a compiler warning at this point indicating
		// that a function is being hidden. Specifically, the function
		// void	Mammal::Move( int distance )
		// cannot be applied to a Dog object.
		// When you override a function name, you must override all
		// versions of the function, else the ones not specifically
		// overriden will be hidden in the derived class.
};

void	main(void)
{
	Mammal		big_animal;
	Dog			spot;
	
	big_animal.Move();
	big_animal.Move(7);
	spot.Move();
	// spot.Move(12);	// This would cause a compilation error if not
						// commented out.
}
