// MODULE:		dist5.cpp	
// PROGRAMMER:	Gary J. Blair
// LANGUAGE:	C++
// DATE:		96/04/11
//
// PURPOSE:
//		Implement the Distance class.

#include		<iostream.h>  
#include		<stdlib.h>
#include		<math.h>
#include        "dist5.h"   

#define			FEET_PER_METER	3.280833	/* # of feet/meter */

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

    	// Initialize a Distance to the specified value,
    	// which is in meters.
    	// This can also be used as a conversion operator.
    	
Distance::Distance( float	n_meters )
{ 
  double	total_feet;
  
  total_feet = n_meters * FEET_PER_METER;
  feet = (int)(floor(total_feet));
  inches = (total_feet - feet) * 12;
}

		// Convert English Distance to meters.
		
Distance::operator float()
{
	return	(float)((feet + inches/12) / FEET_PER_METER);
}

    	// Define + that operates on Distance + Distance.
    	
Distance	Distance::operator + ( Distance &rhs ) const
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
