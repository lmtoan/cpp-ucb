// MODULE:		dist5.h	
// PROGRAMMER:	Gary J. Blair
// LANGUAGE:	C++
// DATE:		96/04/11
//
// PURPOSE:
//		Header file for Distance class.

class Distance
{
  	public:          
  		
  		// The no argument constructor initializes a Distance to 0'0".
  		
    Distance();                   
    
    	// Initialize a Distance to the specified value.
    	
    Distance( int ft, double in );  

    	// Initialize a Distance to the specified value,
    	// which is in meters.
    	// This can also be used as a conversion operator.
    	
	Distance( float	n_meters );

		// Convert English Distance to meters.
		
	operator float();
    
    	// Define + that operates on Distance + Distance.
    	
    Distance operator + ( Distance &rhs ) const;   
    
    	// Define comparison operator.
    	
    int			operator==( Distance& rhs ) const;
    
    	// Define stream insertion operator for Distances.
    	
    friend ostream& operator << ( ostream& str, Distance& d );   
                                                             
    	// Define stream extraction operator for Distances.
    	
    friend istream& operator >> ( istream& str, Distance& d ); 
    
  	private:
    int    feet;
    double inches;


};
