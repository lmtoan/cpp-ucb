// MODULE:		linklist.cpp			
// PROGRAMMER:	Gary J. Blair
// LANGUAGE:	C++
// DATE:		97/08/04
//
// PURPOSE:                       
//      Provide a linked list capability.
//		Illustrate iterators.
//		Illustrate friend classes.       
//		Illustrate ADTs.

#include	<iostream.h>  
#include	<string.h> 
#include	"linklist.h"
                       
void	ListItem::Delete()
{
	plist->Delete(this);
}

void		List::Insert( ListItem *new_item )
{
	ListItem	*search;	// Ptr to search items in list.
							// Want to find first item in list
							// with a key >= new_item's key. 
		
	if (! head)	// List is currently empty.
	{
		head = tail = new_item;
		new_item->next = new_item->prev = NULL;
	}
	else	// Find first item larger than inserted item.
	{
		for (search=head; search; search=search->next)
			if (new_item->CompareByInsertKey(search) < 0)
				break;
				
		if (search==head)	// Inserting new first item.
		{
			head = new_item;
			new_item->next = search;
			search->prev = head;
			new_item->prev = NULL;
		}
		else if (! search)	// Means insert as new last item.
		{	
			tail->next = new_item;
			new_item->prev = tail;
			new_item->next = NULL;
			tail = new_item;
		}
		else
		{
			new_item->prev = search->prev;
			search->prev->next = new_item;
			new_item->next = search;
			search->prev = new_item;
		}
	}
	new_item->inserted = 1;
	new_item->plist = this;	
        NextGeneration();
}
  
ListItem*	List::Find( void *search_item_key, COMPARATOR c)
{
	ListItem	*search;	// Ptr to traverse each item in list.
	
	for (search=head; search; search=search->next)
		if (! c(search,search_item_key))
			return	search;
	return	NULL;
}

void		List::Delete( ListItem *deleted_item )
{
	if (head == deleted_item)
		head = deleted_item->next; 
	else
		deleted_item->prev->next = deleted_item->next;
		
	if (tail == deleted_item)
		tail = deleted_item->prev;
	else
     	deleted_item->next->prev = deleted_item->prev;

	deleted_item->next = NULL;
	deleted_item->prev = NULL;
	deleted_item->inserted = 0;
	deleted_item->plist = NULL;
	NextGeneration();
}

int			List::Delete( void *deleted_item_key, COMPARATOR c )
{
	ListItem	*search;	// Ptr to traverse each item in list.
	
	if (search=Find(deleted_item_key,c))
	{
			Delete(search);
			return	1;
	}
	else
		return	0;
}

List*	List::Clone()
{
	List			*newList;	// Ptr to duplicate list.
	ListItem		*p;			// Ptr to traverse original list.
	ListItem		*pdup;		// Ptr to duplicate of p.
	ListIterator	*iter;		// Iterator over original list.
	
	newList = new List;
	if (! newList)
		return	NULL;

	iter = new ListIterator(*this);
	while (p=(iter->NextItemInList()))
	{
		pdup = p->Clone();
		if (! pdup)
			return	newList;
		newList->Insert(pdup);
	}
	delete	iter;
	return	newList;
}
 
 
ListIterator::ListIterator( List& list_to_iterate )
{
	l = &list_to_iterate;
	next_item = l->head;
	generation = l->GetGeneration();
}

ListItem*		ListIterator::NextItemInList()
{  
	ListItem	*rv;	// Return value - ptr to next item.
	
	//if (generation != l->GetGeneration())	// The list changed!
	//	throw IteratorException(*l);
		
	rv = next_item;
	if (next_item)
		next_item = next_item->next;
	return  rv;
}








