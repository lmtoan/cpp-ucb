// MODULE:		distance.h	
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
    
    	// Define + that operates on Distance + Distance.
    	
    Distance operator + ( Distance &rhs );   
    
    	// Define + that operates on Distance + int which means add feet.   
    	
    Distance operator + ( int rhs );
    
    	// Define + that operates on Distance + double which means add inches.   
    	
    Distance operator + ( double rhs );        
    
    	// Define + that operates on int + Distance which means add feet.      
    
    friend Distance operator + ( int lhs, Distance &rhs );
    
    	// Define + that operates on double + Distance which means add inches.      
    
    friend Distance operator + ( double lhs, Distance &rhs ); 
    
    	// Define stream insertion operator for Distances.
    	
    friend ostream& operator << ( ostream& str, Distance& d );   
    
    	// Define stream extraction operator for Distances.
    	
    friend istream& operator >> ( istream& str, Distance& d );

  private:
    int    feet;
    double inches;

};
