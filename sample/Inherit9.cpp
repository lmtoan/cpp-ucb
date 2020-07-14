// MODULE:		inherit9.cpp	
// PROGRAMMER:	Gary J. Blair
// LANGUAGE:	C++
// DATE:		96/04/11
//
// PURPOSE:
// 		Illustrate virtual functions.
//		Illustrate stream inserting of a pointer. 
//

#include        <iostream.h>
#include        <stdlib.h>
#include		<string.h>

class	Thing	// Thing is the base of all our objects.
{
	public: 
	Thing() { strcpy(name,""); };
	Thing( char * thing_name ) { strcpy(name,thing_name); };
    virtual void print() { print(cout); };
    virtual void print(ostream& str);
    friend	ostream& operator << ( ostream& str, Thing *t );

	protected:
    char name[80];
};

void	Thing::print(ostream& str)
{
  str << "name:" << name;
}

ostream& operator << ( ostream& str, Thing *t )
{
	t->print(str);
	return	str;
}


class	Person : public Thing
{
	public:
    Person();
    Person( char *person_name, int person_age );
    virtual void print() { print(cout); };
    virtual void print(ostream& str);
    
	protected:
    int  age;
};

Person::Person() : Thing()
{
  age = -1;
}

Person::Person( char *person_name, int person_age ) : Thing(person_name)
{
  age = person_age;
}

void	Person::print(ostream& str)
{
	Thing::print(str);
	str	<< " age: " << age;
}

class	Politician : public Person
{
	public:
    Politician( char *person_name, int person_age, char *pol_party );
    virtual void print() { print(cout); };
    virtual void print(ostream& str);

	protected:
    char	party[40];
};

Politician::Politician( char *person_name, int person_age, char *pol_party )
	  : Person(person_name,person_age)
{
  strcpy(party,pol_party);
}

void	Politician::print(ostream& str)
{

  Person::print(str);
  str	<< " party:" << party;
}

class	SimpleList	:	public	Thing
{
  public:
  SimpleList() { size = 0;};
  void insert( Thing& new_item ) {items[size++] = &new_item;};
  void print() { print(cout); };
  void print( ostream& str );

  protected:
  int    size;
  Thing* items[50];
};

void SimpleList::print( ostream& str )
{
  for (int i=0; i<size; ++i)
    str << items[i] << endl;
}

void main()
{
  Thing      	t("something"),x("another");
  Person     	me("Gary J. Blair",32);
  Person    	wife("Tammy Blair",34);
  Politician 	pres("George Bush",68,"Republican");
  Politician 	vp("Dan Quayle", 48, "Republican");
  SimpleList	main_list, sub_list;
 
  main_list.insert(t);
  main_list.insert(me);
  main_list.insert(pres);
  cout << "Printing main list.\n"
       << (Thing *)  &main_list
       << "\n";

  sub_list.insert(x);
  sub_list.insert(wife);
  sub_list.insert(vp);
  cout << "Print sub-list.\n"
       << (Thing *)  &sub_list
       << "\n";

  main_list.insert(sub_list);
  cout << "Printing main list containing sub-list.\n"
       << (Thing *)  &main_list
       << "\n";
}
