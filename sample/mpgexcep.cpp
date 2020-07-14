//	PROGRAM:	mpgexcep.cpp
//	PROGRAMMER:	Gary J. Blair
//	LANGUAGE:	ANSI C
//	DATE:		97/05/12
//
//	PURPOSE:  
//		Calculate gas mileage.
//		Illustrate use of exceptions for error handling.


#include	<iostream.h> 

class	InitOdomErr		{};
class	FinalOdomErr	{};
class	GasErr			{};

void	read_inputs( float& init_odom, float& final_odom, float& gas );
float	mileage( float init_odom, float final_odom, float gas );
void	print_result(float mpg);

void	main(void)
{
	int		success = 0;		/* Computation successful? */ 
	float	initial_odometer;	/* Initial odometer reading in miles. */
	float	final_odometer;		/* Final odometer reading in miles. */
	float	gas_used;			/* Gallons of gas used. */     
	float	mpg;				/* Miles per gallon. */
	
	while (! success)
	{
		try
		{
			read_inputs(initial_odometer,final_odometer,gas_used);	
			mpg = mileage(initial_odometer,final_odometer,gas_used);
			print_result(mpg); 
			success = 1;
		}
		catch (InitOdomErr)
		{
			cout << "*** Error in initial odometer reading.\n";
		}
		catch (FinalOdomErr)
		{
			cout << "*** Error in final odometer reading.\n";
		}
		catch (GasErr)
		{
			cout << "*** Error in amount of gas used.\n";
		}
	}
}

void	read_inputs( float& init_odom, float& final_odom, float& gas )
{
	cout << "Enter initial odometer reading ";
	cin  >> init_odom;
	cout << "Enter final odometer reading   ";
	cin  >> final_odom;
	cout << "Enter gallons of gas used      ";
	cin  >> gas;
}

float	mileage( float init_odom, float final_odom, float gas )
{ 
	if (init_odom < 0)
		throw	InitOdomErr();
	if (final_odom < init_odom)
		throw	FinalOdomErr();
	if (gas <= 0)
		throw	GasErr();
	return (final_odom - init_odom) / gas;
}

void	print_result(float mpg)
{ 
	cout << "Your gas mileage is " << mpg << endl;
}
