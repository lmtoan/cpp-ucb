// MODULE:		testconv.cpp			
// PROGRAMMER:	Gary J. Blair
// LANGUAGE:	C++
// DATE:		96/04/11
//
// PURPOSE:
//		Test conversion approaches.
//			constructor in destination class.
//			conversion function in source class.
//			overloaded operator=.
//		in the following situations:
//			assign source class object to destination class object.
//			pass sco actual to dco formal
//			use in expression
// Notes:
//		Existence of both constructor and operator does not create
//		a problem unless you attempt to use one of them.
 
#include        <iostream.h>
#include        <stdlib.h>
#include		<math.h>

#define		USE_CONSTRUCTOR		1
#define		USE_OPERATOR		0
#define		USE_ASSIGNMENT		0

class	Rectangular;
class	Polar;

class	Rectangular
{ 
	public:
	Rectangular(void) { x=0.0; y=0.0; };
	Rectangular( double x_coord, double y_coord );
#if (USE_CONSTRUCTOR)
	Rectangular( Polar& p );
#endif
#if	(USE_ASSIGNMENT)
	Rectangular&	operator=( Polar& p );
#endif
	Rectangular operator+( Rectangular& rhs );
	
	friend	ostream& operator<<( ostream& str, Rectangular& r );
	
	private:
	double		x;		// The x coordinate.
	double		y;		// The y coordinate.
};

class	Polar
{
	public:
	Polar(void) { radius=0.0; angle=0.0; };
	Polar( double r, double theta ) { radius=r; angle=theta;};
	double  Angle(void)  { return angle; };
    double  Radius(void) { return radius; };
	
		// Conversion operator to Rectangular.
	
#if (USE_OPERATOR)
	operator Rectangular();
#endif
	
	friend	ostream& operator<<( ostream& str, Polar& p );
	
	private:
	double		radius;	// Radius from origin.
	double		angle;	// Angle with conventional x-axis.
};

void	testfunc( Rectangular r );

void	main(void)
{ 
	const double	pi = acos(-1.0);	// Define pi.
	Polar			p1(10.0,pi/4);
	Polar			p2(20.0,pi/6);
	Rectangular		r1, r2(3,4), r3;
	
	r1 = p1;
	cout	<< p1 << " = " << r1 << endl;
	
	r1 = p2;
	cout	<< p2 << " = " << r1 << endl;

	cout	<<  "invoking with testfunc with r1 = "
			<<	r1  << endl;

		// The following function is invoked correctly using
		// either constructor or operator.
		// The statement cannot be compiled if we use overloaded
		// assignment operator=.

	testfunc(p2);

	r3 = p2;

		// Following statement does not compile any of the 3 forms
		// of conversion.

//	r1 = r2 + p2;
//	cout	<<	r2  << " + "  << r3 << " = " << r1  << endl;
	

}


Rectangular::Rectangular( double x_coord, double y_coord )
{
	x = x_coord;
	y = y_coord;
}

	// Construct a Rectangular from a Polar.
	// Also serves as a convertor.

#if (USE_CONSTRUCTOR)
Rectangular::Rectangular( Polar& p )
{
	double  r = p.Radius();
	double  theta = p.Angle();
	x = r * cos(theta);
	y = r * sin(theta);
}
#endif

#if	(USE_ASSIGNMENT)
Rectangular&	Rectangular::operator=( Polar& p )
{
	double  r = p.Radius();
	double  theta = p.Angle();
	x = r * cos(theta);
	y = r * sin(theta);
	return	(*this);
}
#endif


Rectangular  Rectangular::operator+( Rectangular& rhs )
{
	double	xsum = x + rhs.x;
	double	ysum = y + rhs.y;
	return	Rectangular(xsum,ysum);
}
	
ostream& operator<<( ostream& str, Rectangular& r )
{
	str	<< "x:" << r.x << "  y:" << r.y;
	return	str;
}
	
		// Conversion operator to Rectangular.
	
#if (USE_OPERATOR)
Polar::operator Rectangular()
{
	double	local_x = radius * cos(angle);
	double	local_y = radius * sin(angle); 
	return	Rectangular(local_x,local_y);
}
#endif
	
ostream& operator<<( ostream& str, Polar& p )
{
	str	<< "radius:" << p.radius << "  angle:" << p.angle;
	return	str;
}

void	testfunc( Rectangular r )
{
	cout	<< "In testfunc, r is " << r << endl;
}


