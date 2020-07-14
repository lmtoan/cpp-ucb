// MODULE:		distanc2.cpp	
// PROGRAMMER:	Gary J. Blair
// LANGUAGE:	C++
// DATE:		96/04/11
//
// PURPOSE:
//		Provide a type for English distances.  
//		Illustrate creation of new stream insertion
//		and stream extraction operators.

#include        <iostream.h>
#include        <stdlib.h>

typedef		struct	{
						int		feet;
						double	inches;
					}	Distance;

Distance	operator + ( Distance &lhs, Distance &rhs );
ostream&	operator << ( ostream& str, Distance& d );
istream&	operator >> ( istream& str, Distance& d );


void	main(void)
{                                                     
	Distance	a = {16,5.0};
	Distance	b = {17,9.0};
	Distance	total;
	
	total = a + b;
	cout	<< a << " + " << b << " = " << total << endl;
	
	cout << "Enter 2 distances ";
	cin >> a >> b;
	total = a + b;
	cout	<< a << " + " << b << " = " << total << endl;
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



ostream& operator << ( ostream& str, Distance& d )
{
  str << d.feet << "'" << d.inches << "\"";
  return str;
}

istream& operator >> ( istream& str, Distance& d )
{
  str >> d.feet;
  if (str.get() != '\'')
  {
  	cerr << "*** Error extracting Distance.\n";
  	exit(1);
  }
  str >> d.inches;
  if (str.get() != '"')
  {
  	cerr << "*** Error extracting Distance.\n";
  	exit(1);
  }
  return str;
}
