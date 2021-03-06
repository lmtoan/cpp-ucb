// MODULE:		distance.cpp	
// PROGRAMMER:	Gary J. Blair
// LANGUAGE:	C++
// DATE:		96/04/11
//
// PURPOSE:
//		Implement the Distance class.

#include		<iostream.h>  
#include		<stdlib.h>
#include        "distance.h"

  		// The no argument constructor initializes a Distance to 0'0".
  		
Distance::Distance()
{
  feet = 0;
  inches = 0.0;
}

    	// Initialize a Distance to the specified value.
    	
Distance::Distance( int ft, double in )
{
  feet = ft;
  inches = in;
}

    	// Define + that operates on Distance + Distance.
    	
Distance	Distance::operator + ( Distance &rhs )
{
  int    sum_feet;
  double sum_inches;

  sum_feet = feet + rhs.feet;
  sum_inches = inches + rhs.inches;
  if (sum_inches >= 12.0)
  {
    sum_inches -= 12.0;
    ++sum_feet;
  }
  return Distance(sum_feet,sum_inches);
}
    
    	// Define + that operates on Distance + int which means add feet.   
    	
Distance	Distance::operator + ( int rhs )
{      
	return	*this + Distance(rhs,0.0);
}
    
    	// Define + that operates on Distance + double which means add inches.   
    	
Distance	Distance::operator + ( double rhs )
{      
	return	*this + Distance(0,rhs);
}        
    
    	// Define + that operates on int + Distance which means add feet.      
    
Distance	operator + ( int lhs, Distance &rhs )
{ 
  int    sum_feet;
  double sum_inches;

  sum_feet = lhs + rhs.feet;
  sum_inches = rhs.inches;
  return Distance(sum_feet,sum_inches);
}
    
    	// Define + that operates on double + Distance which means add inches.      
    
Distance	operator + ( double lhs, Distance &rhs )
{      
	return	rhs + lhs;
} 
    
    	// Define stream insertion operator for Distances.

ostream& operator << ( ostream& str, Distance& d )
{
  str << d.feet << "'" << d.inches << "\"";
  return str;
}

    	// Define stream extraction operator for Distances.
    	
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
