// MODULE:		distanc1.cpp	
// PROGRAMMER:	Gary J. Blair
// LANGUAGE:	C++
// DATE:		96/04/11
//
// PURPOSE:
//		Provide a type for English distances.  
//		Illustrate operator overloading.

#include        <iostream.h>
#include        <stdlib.h>

typedef		struct	{
						int		feet;
						double	inches;
					}	Distance;

Distance	operator + ( Distance &lhs, Distance &rhs );
                                                 

void	main(void)
{                                                     
	Distance	a = {16,5.0};
	Distance	b = {17,9.0};
	Distance	total;
	
	total = a + b;
	cout	<< "The total distance is " 
			<< total.feet << "'"
			<< total.inches << "\"\n";
}
 

Distance operator + ( Distance &lhs, Distance &rhs )
{
  Distance	sum;

  sum.feet = lhs.feet + rhs.feet;
  sum.inches = lhs.inches + rhs.inches;
  if (sum.inches >= 12.0)
  {
    sum.inches -= 12.0;
    ++sum.feet;
  }
  return sum;
}
