// MODULE:		convert2.cpp			
// PROGRAMMER:	Gary J. Blair
// LANGUAGE:	C++
// DATE:		96/04/11
//
// PURPOSE:
//		Represent planar coordintes in rectangular and
//		polar form.   
//      Illustrate interclass conversions in destination class.

#include        <iostream.h>
#include        <stdlib.h>
#include		<math.h>

class	Rectangular;
class	Polar;

class	Rectangular
{ 
	public:
	Rectangular(void) { x=0.0; y=0.0; };
	Rectangular( double x_coord, double y_coord );
	
		// Construct a Rectangular from a Polar.
		// Also serves as a convertor.
		
	Rectangular( Polar p );
	
	friend	ostream& operator<<( ostream& str, Rectangular& r );
	
	private:
	double		x;		// The x coordinate.
	double		y;		// The y coordinate.
};

class	Polar
{
	public:
	Polar(void) { radius=0.0; angle=0.0; };
	Polar( double r, double theta );
	
		// Inquiry functions required by
		// Rectangular::Rectangular( Polar& p);
		
	double	Angle(void)  { return angle; };
	double	Radius(void) { return radius; };
	
	friend	ostream& operator<<( ostream& str, Polar& p );
	
	private:
	double		radius;	// Radius from origin.
	double		angle;	// Angle with conventional x-axis.
};

void	main(void)
{ 
	const double	pi = acos(-1.0);	// Define pi.
	Polar			p1(10.0,pi/4);
	Polar			p2(20.0,pi/6);
	Rectangular		r1;
	
	r1 = p1;
	cout	<< p1 << " = " << r1 << endl;
	
	r1 = p2;
	cout	<< p2 << " = " << r1 << endl;	
}


Rectangular::Rectangular( double x_coord, double y_coord )
{
	x = x_coord;
	y = y_coord;
}
	
		// Construct a Rectangular from a Polar.
		// Also serves as a convertor.
		
Rectangular::Rectangular( Polar p )
{
	double	r = p.Radius();
	double	theta = p.Angle();
	                          
	x = r * cos(theta);
	y = r * sin(theta);
}
	
ostream& operator<<( ostream& str, Rectangular& r )
{
	str	<< "x:" << r.x << "  y:" << r.y;
	return	str;
}


Polar::Polar( double r, double theta )
{
	radius = r;
	angle  = theta;
}
	
ostream& operator<<( ostream& str, Polar& p )
{
	str	<< "radius:" << p.radius << "  angle:" << p.angle;
	return	str;
}
