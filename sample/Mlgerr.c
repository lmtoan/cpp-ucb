/*
	PROGRAM:	mlgerr.c
	PROGRAMMER:	Gary J. Blair
	LANGUAGE:	ANSI C
	DATE:		97/05/12

	PURPOSE:  
		Calculate gas mileage.
		Illustrate use of setjmp/longjmp for error handling.
		
	NOTES:
		setjmp/longjmp are not compatible with most C++ implementations.
*/

#include	<stdio.h> 
#include	<stdlib.h>
#include	<setjmp.h>

#define		INIT_ODOM_ERR	1
#define		FINAL_ODOM_ERR	2
#define		GAS_ERR			3

jmp_buf		main_loop; /* Records info about runtime stack. */ 

void	read_inputs( float *init_odom, float *final_odom, float *gas );
float	mileage( float init_odom, float final_odom, float gas );
void	print_result(float mpg);

void	main(void)
{
	int		setjmp_result;		/* Actual invocation of setjmp() or error return. */ 
	int		success = 0;		/* Computation successful? */ 
	float	initial_odometer;	/* Initial odometer reading in miles. */
	float	final_odometer;		/* Final odometer reading in miles. */
	float	gas_used;			/* Gallons of gas used. */     
	float	mpg;				/* Miles per gallon. */
	
	while (! success)
	{
		read_inputs(&initial_odometer,&final_odometer,&gas_used);	
		setjmp_result = setjmp(main_loop);
		if (setjmp_result == 0)
		{  
			mpg = mileage(initial_odometer,final_odometer,gas_used);
			print_result(mpg); 
			success = 1;
		}
		else if (setjmp_result == INIT_ODOM_ERR)
			printf("*** Error in initial odometer reading.\n");                        
		else if (setjmp_result == FINAL_ODOM_ERR)
			printf("*** Error in final odometer reading.\n");                        
		else if (setjmp_result == GAS_ERR)
			printf("*** Error in amount of gas used.\n");                        
	}
}

void	read_inputs( float  *init_odom, float *final_odom, float *gas )
{
	printf("Enter initial odometer reading ");
	scanf("%f",init_odom);
	printf("Enter final odometer reading   ");
	scanf("%f",final_odom);
	printf("Enter gallons of gas used      ");
	scanf("%f",gas);
}

float	mileage( float init_odom, float final_odom, float gas )
{ 
	if (init_odom < 0)
		longjmp(main_loop,INIT_ODOM_ERR);
	if (final_odom < init_odom)
		longjmp(main_loop,FINAL_ODOM_ERR);
	if (gas <= 0)
		longjmp(main_loop,GAS_ERR);
	return (final_odom - init_odom) / gas;
}

void	print_result(float mpg)
{ 
	printf("Your gas mileage is %.2f\n",mpg);
}
