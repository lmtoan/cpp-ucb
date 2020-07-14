// MODULE:		llmain.cpp			
// PROGRAMMER:	Gary J. Blair
// LANGUAGE:	C++
// DATE:		97/08/04
//
// PURPOSE:                       
//      Demonstrate Lists.

#include	<iostream.h>  
#include	<string.h>
#include	"linklist.h"
#include	"person.h"
                       
void	main(void)
{
	Person			*p, *p1,*p2,*p3,*p4,*p5,*p6,*p7;
	List			l;                   
	ListIterator	*iter; 
	unsigned long	ssn;
	List			*cloned_list;
	
	p1 = new Person("Kmetz, Rhonda",889922336);		l.Insert(p1);
	p2 = new Person("Jones, Tom", 122334455);		l.Insert(p2); 
	p3 = new Person("Phillips, Bob",545667887);		l.Insert(p3); 
	p4 = new Person("Adams, Don", 999997777);		l.Insert(p4);
	p5 = new Person("Zwakenberg, Rich", 888777666);	l.Insert(p5);
	p6 = new Person("Blair, Gary", 777666321);		l.Insert(p6);
	p7 = new Person("Johnson, Bill", 221835412);	l.Insert(p7);
	
	iter = new ListIterator(l);
	while (p=(Person *)(iter->NextItemInList()))
		p->print();
	delete iter;

	cloned_list = l.Clone();
	cout	<< "The cloned list:\n";
	iter = new ListIterator(*cloned_list);
	while (p=(Person *)(iter->NextItemInList()))
		p->print();
	delete iter;
	
	l.Delete(p2);
	p4->Delete();
	ssn = 888777666;
	l.Delete(&ssn,CompareSSN);
	
	cout << "\nAfter deleting Jones, Adams, and Zwakenberg the list is\n\n";
	
	iter = new ListIterator(l);
	while (p=(Person *)(iter->NextItemInList()))
		p->print();
	delete iter; 
	
	ssn = 889922336;
	p = (Person *)(l.Find(&ssn,CompareSSN));
	cout << "\nResult of searching for SSN 889922336 is" << endl;
	p->print();
}                                                







