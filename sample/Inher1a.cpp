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
    void print(); 
    friend ostream& operator<<(ostream& str, Thing& t );

	protected:
    char name[80];
};

void	Thing::print()
{
  cout << "name:" << name;
}

ostream& operator<<(ostream& str, Thing& t )
{
	str		<< "name:" << t.name;
	return	str;
}


class	Person : public Thing
{
	public:
    Person();
    Person( char *person_name, int person_age );
    void print(); 
    friend ostream& operator<<(ostream& str, Person& p );
    
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

ostream& operator<<(ostream& str, Person& p )
{
	str		<< "name:" << p.name;
	str		<< " age:" << p.age;
	return	str;
}

class	Politician : public Person
{
	public:
    Politician( char *person_name, int person_age, char *pol_party );
    void	print();
    friend ostream& operator<<(ostream& str, Politician& p );

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

ostream& operator<<(ostream& str, Politician& p )
{
	str		<< "name:" << p.name;
	str		<< " age:" << p.age;
	str		<< " party:" << p.party;
	return	str;
}


void	main(void)
{
  Thing       t("Cessna 182");
  Person      me("Gary J. Blair",37);
  Politician  president("Bill Clinton",46,"Democrat");

  t.print();			cout << "\n";
  me.print();			cout << "\n";
  president.print();	cout << "\n";
  
  cout	<< t << endl;
  cout	<< me << endl;
  cout	<< president << endl;
}