// INHERIT5.CPP  92/09/10
//
// Purpose:
//   Illustrate destructors.


#include <iostream.h>
#include <string.h>
#include <stdlib.h>

class thing
{

		// Thing is the base of all our objects.

public:
    virtual void print();
    virtual void print( ostream& str );
    friend ostream& operator << ( ostream& str, thing *t );
};


void thing::print()
{
  print(cout);
}

void thing::print( ostream& str )
{
  str << "Invoked << with a thing.\n";
}

ostream& operator << ( ostream& str, thing *t )
{
  t->print(str);
  return str;
}

class person : public thing {
protected:
    char name[20];
    int  age;

public:
    person();
    person( char init_name[], int age );
    void print();
    void print( ostream& str );
};

person::person()
{
  name[0] = '\0';
  age     = -1;
}

person::person( char init_name[], int init_age )
{
  strcpy(name,init_name);
  age = init_age;
}

void person::print()
{
  print(cout);
}

void person::print( ostream& str )
{
  str << name << " " << age << "\n";
}

class politician : public person{
protected:
    char party[20];

public:
    politician( char init_name[], int init_age, char init_party[] );
    void print();
    void print( ostream& str );
};

politician::politician( char init_name[], int init_age, char init_party[] )
{
  strcpy(name,init_name);
  age = init_age;
  strcpy(party,init_party);
}

void politician::print()
{
  print(cout);
}

void politician::print( ostream& str )
{

  person::print(str);
  str << party << "\n";
}


class list : public thing {
protected:
  int    max_items;
  int    size;
  thing  **items;
  char   list_name[40];

public:
  list( int max_size, char l_name[] );
  ~list();
  void insert( thing& new_item );
  void print();
  void print( ostream& str );
};

list::list( int max_size, char l_name[] )
{
  max_items = max_size;
  size = 0;
  strcpy(list_name,l_name);
  if ((items = (thing**) malloc(max_items*sizeof(thing*))) == NULL)
  {
    cout << "Error allocating" << list_name << endl;
    exit(1);
  }
}

list::~list()
{
  cout << "Destructor called for " << list_name << endl;
  free(items);
}

void list::insert( thing& new_item )
{
  items[size++] = &new_item;
}

void list::print()
{
  print(cout);
}

void list::print( ostream& str )
{
  int i;

  for (i=0; i<size; ++i)
    str << items[i];
}

void main()
{
  thing      t,x;
  person     me("Gary J. Blair",34);
  person     wife("Tammy Blair",36);
  politician pres("George Bush",68,"Republican");
  politician vp("Dan Quayle", 48, "Republican");
  int        i;
  list       main_list(4,"main_list"), sub_list(3,"sub_list");

  main_list.insert(t);
  main_list.insert(me);
  main_list.insert(pres);

  sub_list.insert(x);
  sub_list.insert(wife);
  sub_list.insert(vp);

  main_list.insert(sub_list);
  cout << "Printing main list containing sub-list.\n"
       << &main_list
       << "\n";

}