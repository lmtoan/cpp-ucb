// MODULE:		dynarr4d.cpp	
// PROGRAMMER:	Gary J. Blair
// LANGUAGE:	C++
// DATE:		96/04/11
//
// PURPOSE:
// 		Driver for dynarr4 exercise.
//		Illustrate templates.  


#include        <iostream.h>
#include        <stdlib.h>  
#include		"dynarr4.h"


void	main(void)
{ 
	DynamicArray<int>		x(16);
	DynamicArray<double> 	*q;
	long					i;
	
	for (i=0; i<x.size(); ++i)
		x[i] = i * i; 
	
		
	q = new DynamicArray<double>(16);
	for (i=0; i<q->size(); ++i)
		(*q)[i] = i*i + 0.1;

	for (i=0; i<16; ++i)
			cout  <<  x[i]  << "   "  <<  (*q)[i] << endl;
	
}
