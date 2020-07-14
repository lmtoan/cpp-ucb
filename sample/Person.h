// MODULE:		person.h			
// PROGRAMMER:	Gary J. Blair
// LANGUAGE:	C++
// DATE:		97/08/04
//
// PURPOSE:                       
//		Store information about a person.                       
//      Derive a concrete type from the ADT ListItem.

#ifndef		person_h
#define		person_h

#include	<iostream.h>  
#include	<string.h>
#include	"linklist.h"
                       

class Person : public ListItem
{      
	public:    
	Person( char *s, unsigned long id ) {strcpy(name,s); ssn=id;};
	virtual	int		CompareByInsertKey( ListItem* item_in_list );
	virtual void	print();	
	virtual	ListItem*	Clone();

	
	char			name[50];	// Person's name.
	
	private: 
	unsigned long	ssn;		// Social security number.  
	
	friend	int CompareSSN( ListItem*  item_in_list, void*	 search_key ); 
}; 

#endif






