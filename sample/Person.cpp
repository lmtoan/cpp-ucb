// MODULE:		person.cpp			
// PROGRAMMER:	Gary J. Blair
// LANGUAGE:	C++
// DATE:		97/08/04
//
// PURPOSE:
//		Store information about a person.                       
//      Derive a concrete type from the ADT ListItem.

#include	"person.h"  


		// Clone the item.

ListItem*	Person::Clone()
{
	Person		*p;

	p = new Person(name,ssn);
	return	(ListItem *) p;
}

int		Person::CompareByInsertKey( ListItem* item_in_list )
{
	return	strcmp(this->name,((Person *)item_in_list)->name);
} 

void	Person::print()
{
	cout	<< name	<< ":" << ssn << endl;
}

int CompareSSN( ListItem*  item_in_list, void*	 search_key )
{
	unsigned long left  = ((Person *)item_in_list)->ssn;
	unsigned long right = *((unsigned long *) search_key);
	return	(left < right) ? -1 :
			(left > right) ?  1 :
			                  0 ;	
}

