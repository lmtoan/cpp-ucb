// INHERIT3.CPP  92/08/30
//
// Purpose:
//   Illustrate inheritance.


#include <iostream.h>
#include <string.h>

class thing
{

		// Thing is the base of all our objects.

public:
    virtual void print();
};


void thing::print()
{
  cout << "Invoked << with a thing.\n";
}

class person : public thing {
protected:
    char name[20];
    int  age;

public:
    person();
    person( char init_name[], int age );
    void print();
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
  cout << name << " " << age << "\n";
}

class politician : public person{
protected:
    char party[20];

public:
    politician( char init_name[], int init_age, char init_party[] );
    void print();
};

politician::politician( char init_name[], int init_age, char init_party[] )
          : person(init_name,init_age)
{
  strcpy(party,init_party);
}

void politician::print()
{

  person::print();
  cout << party << "\n";
}


class list : public thing {
protected:
  int    size;
  thing* items[50];

public:
  list() {size = 0;};
  void insert( thing& new_item );
  void print();
};

void list::insert( thing& new_item )
{
  items[size++] = &new_item;
}

void list::print()
{
  int i;

  for (i=0; i<size; ++i)
    (*items[i]).print();
}

void main()
{
  thing      t,x;
  person     me("Gary J. Blair",34);
  person     wife("Tammy Blair",36);
  politician pres("George Bush",68,"Republican");
  politician vp("Dan Quayle", 48, "Republican");
  int        i;
  list       main_list, sub_list;

  main_list.insert(t);
  main_list.insert(me);
  main_list.insert(pres);
  cout << "Printing main list.\n";
  main_list.print();
  cout << "\n";

  sub_list.insert(x);
  sub_list.insert(wife);
  sub_list.insert(vp);
  cout << "Print sub-list.\n";
  sub_list.print();
  cout << "\n";

  main_list.insert(sub_list);
  cout << "Printing main list containing sub-list.\n";
  main_list.print();
  cout << "\n";
}