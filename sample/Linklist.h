// MODULE:		linklist.h			
// PROGRAMMER:	Gary J. Blair
// LANGUAGE:	C++
// DATE:		97/08/04
//
// PURPOSE:                       
//      Provide a linked list capability.
//		Illustrate iterators.
//		Illustrate friend classes.       
//		Illustrate ADTs.

#ifndef	linklist_h
#define	linklist_h
                       
class	List;  				// Tracks the first and last items in a list.
class	ListItem;  			// Stores the actual items in the list.
class	ListIterator;		// Used to loop over all items in a list.
class	IteratorException;	// Thrown if iterator becomes out of date.

	// A COMPARATOR is a function that takes a pointer to an item in a
	// list, and a pointer to a key we are searching for. It extracts
	// the key of the item in the list and compares it against the 
	// search key, returning a value in the normal manner (e.g. strcmp).

typedef	int	(*COMPARATOR)( ListItem*  item_in_list, void*	 search_key ); 

	// ListItem is an ADT that provides the capability to insert and
	// remove items from a List. We use it by deriving a type from
	// ListItem and defining a CompareByInsertKey member function. 

class	ListItem	// ADT
{      
	friend class List;
	friend class ListIterator;
	
	public:    
	ListItem() {inserted=0; next=prev=NULL; plist=NULL;};
	
		// CompareByInsertKey is invoked upon something derived from
		// ListItem which we are inserting into a List. It takes as an 
		// argument another ListItem which is already in the list.
		// It compares the keys of these two ListItems, returning a
		// value in the usual manner for comparators (e.g. strcmp).
		                                        
	virtual	int	 	CompareByInsertKey( ListItem* item_in_list ) = 0;
	
		// Clone the item.

	virtual	ListItem*	Clone() = 0;
	
		// Provides each ListItem the ability to delete itself from
		// the list which contains it.
		
	void			Delete();
	
	private:
	ListItem*	next;		// Ptr to next item.
	ListItem*	prev;		// Ptr to previous item.
	int			inserted;	// Item has been inserted in a list. 
	List*		plist;		// Ptr to list containing this item.
}; 


	// List keeps track of the first and last items in a List.
	// It also keeps a generation count, which is incremented each
	// something is inserted or deleted. The purpose of this 
	// generation count is to enable iterators to detect when the
	// list has changed while being iterated.

class	List
{ 
	friend class ListIterator;
	friend class ListItem;
	
	public:
	List() {head=tail=NULL; generation=0;};
	    
	    // Insert new_item into the List.
		
	void			Insert( ListItem*  new_item );
	
		// Search the List for an item containing a key equal
		// to search_item_key, as determined by c.
	  
	ListItem*		Find( void *search_item_key, COMPARATOR c); 
	
		// Delete deleted_item from the list.
	
	void			Delete( ListItem*  deleted_item );
	
		// Delete the item containing a key equal
		// to deleted_item_key, as determined by c.
	  
	int				Delete( void*  deleted_item_key, COMPARATOR c );

			// Clone the list.

	virtual	List*	Clone();

	
	private:
	ListItem*		head;		// First item in last. 
	ListItem*		tail;		// Last item in last.
	unsigned long	generation;	// Generation number of the list.
								// Provides validity check for iterators.
								
	unsigned long	NextGeneration()	{return ++generation;};
	unsigned long	GetGeneration()		{return generation;};	
};

	// An iterator is an object that allows us to iterate over
	// a list by keeping track of the next item in the list to
	// process. We can have many iterators for the same list
	// active simultaneously. 

class ListIterator
{ 
	public:
	ListIterator( List& list_to_iterate );
	
		// Return a pointer to the next item in to be processed.
	
	ListItem*		NextItemInList();
	
	private:
	List*			l;			// List we are iterating over.
	ListItem*		next_item;	// Pointer to next item to be processed
	unsigned long	generation;	// Records l->generation at time when iterator
								// is created.
};  

	// This exception is thrown when we attempt to use an old
	// iterator. An iterator is old if the list it iterates has
	// been modified (an insert or delete has occurred) since
	// the iterator was created. This will be detected because
	// the iterator's generation, recorded when the iterator is
	// constructed, will not match the current generation of the
	// list.

class	IteratorException
{ 
	public:
	IteratorException( List& l ) { iterated_list = &l; };
	
	List*	iterated_list;		// List exception occurred on.
};

#endif

