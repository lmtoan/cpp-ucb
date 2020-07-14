// INHERIT.CPP  91/11/15
//
// Purpose:
//   Illustrate inheritance.


#include <iostream.h>

class thing
{

		// Thing is the base of all our objects.

public:
    virtual void print();
};


void thing::print()
{
  cout << "Invoked << with a thing.\n";
};


class person : public thing {
protected:
    char name[20];

public:
    person() {name[0] = '\0';};
    person( char n[] );
    void print();
};

person::person( char n[] )
{
  int i;

  for (i=0; (i < 20) && (name[i] = n[i]); ++i);
};

void person::print()
{
  cout << name << "\n";
}

class employee : public person{
protected:
    char ssn[12];
    int  salary;

public:
    employee( char n[], char id[], int monthly_pay );
    void print();
};

employee::employee( char n[], char id[], int monthly_pay )
{
  int i;

  for (i=0; (i < 20) && (name[i] = n[i]); ++i);
  for (i=0; (i < 12) && (ssn[i] = id[i]); ++i);
  salary = monthly_pay;
};

void employee::print()
{
  //str << name;
  person::print();
  cout << ssn << "\n"
       << salary << "\n";
}


void main()
{
  thing    t;
  person   me("Gary J. Blair");
  employee pres("George Bush","123-45-6789",16667);
  thing*   things[3];
  int      i;

  cout << "Printing individual things.\n";
  t.print();
  me.print();
  pres.print();
  cout << "Print things from the array.\n";
  things[0] = &t;
  things[1] = &me;
  things[2] = &pres;
  for (i=0; i<3; i++)
    (*things[i]).print();
}