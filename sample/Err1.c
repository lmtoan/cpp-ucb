/*
	PROGRAM:	err1.c
	PROGRAMMER:	Gary J. Blair
	LANGUAGE:	ANSI C
	DATE:		96/07/05

	PURPOSE:
		Illustrate use of setjmp/longjmp for error handling.
		
	NOTES:
		setjmp/longjmp are not compatible with most C++ implementations.
*/

#include	<stdio.h> 
#include	<stdlib.h>
#include	<setjmp.h>

jmp_buf		main_prog_environment; /* Records info about runtime stack. */
                
void a(void);
void b(void);
void c(void);

void	main(void)
{
	int		setjmp_result;
	
	setjmp_result = setjmp(main_prog_environment);
	
	if (setjmp_result == 0)
	{  
		printf("Beginning main program.\n");         
		a();
		exit(0);
	}
	else	/* longjmp brings us here. */
	{                         
		printf("*** longjmp invoked with error value:%d.\n",setjmp_result);
		exit(1);
	}
}

void	a(void)
{
	b();
}

void	b(void)
{
	c();
}

void	c(void)
{       
	longjmp(main_prog_environment,73);
}
