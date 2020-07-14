// MODULE:		inherit1.cpp	
// PROGRAMMER:	Gary J. Blair
// LANGUAGE:	C++
// DATE:		96/04/11
//
// PURPOSE:
// 		Illustrate inheritance. 
//

#include        <iostream.h>
#include        <stdlib.h>
#include		<string.h>

class	Thing	// Thing is the base of all our objects.
{
	public: 
	Thing() { strcpy(name,""); };
	Thing( char * thing_name ) { strcpy(name,thing_name); };
    virtual void print();
    virtual void print( int n );
    
	protected:
    char name[80];
};

void	Thing::print()
{
  cout << "name:" << name;
}

void	Thing::print( int n )
{
	cout	<< "Invoking one argument print.\n";
	print();
	for (int i=1; i<=n; ++i )
		cout	<< "\n";
}


class	Person : public Thing
{
	public:
    Person();
    Person( char *person_name, int person_age );
    void print(); 
    void print( int n );
    
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

void	Person::print()
{
	Thing::print();
	cout	<< " age: " << age;
}

void	Person::print( int n )
{
	cout	<< "Invoking one argument print.\n";
	print();
	for (int i=1; i<=n; ++i )
		cout	<< "\n";
}

class	Politician : public Person
{
	public:
    Politician( char *person_name, int person_age, char *pol_party );
    void	print();
    void 	print( int n );

	protected:
    char	party[40];
};

Politician::Politician( char *person_name, int person_age, char *pol_party )
	  : Person(person_name,person_age)
{
  strcpy(party,pol_party);
}

void	Politician::print()
{
  Person::print();
  cout	<< " party:" << party;
}

void	Politician::print( int n )
{  
	cout	<< "Invoking one argument print.\n";
	print();
	for (int i=1; i<=n; ++i )
		cout	<< "\n";
}


void	main(void)
{
  Thing			t("Cessna 182");
  Person		me("Gary J. Blair",37);
  Politician	president("Bill Clinton",46,"Democrat"); 
  Thing			*p;

  t.print();			cout << "\n";
  me.print();			cout << "\n";
  president.print();	cout << "\n";
  
  p = &t;
  p->print();
  cout	<< endl;
  p->print(1);
  
  p = &me;
  p->print();
  cout	<< endl;
  p->print(2);
  
  p = &president;
  p->print();
  cout	<< endl;
  p->print(3);
}