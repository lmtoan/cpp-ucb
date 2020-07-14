// MODULE:		demoacct.cpp
// PROGRAMMER:	Gary J. Blair
// LANGUAGE:	C++
// DATE:		96/04/11
//
// PURPOSE:
//   Test account objects.
//   Demonstrate fundamental concepts about classes.

#include        <iostream.h>
#include        <stdlib.h>
#include        "account.h"

void    main(void)
{
        Account	gary(3819,1000.00);	// 2-arg constructor invoked.
        Account	dummy;				// Default constructor invoked.
        Account	no_name; 			// Default constructor invoked.

        gary.withdraw(100.00);
        cout	<< "After withdrawing $100.00 Gary has $"
		<< gary.balance() << endl;

        gary.deposit(200.00);
        cout	<< "After depositing  $200.00 Gary has $"
		<< gary.balance() << endl;

        cout << "Enter information for a new account ";
        no_name.read();
        cout << "The information entered is ";
        no_name.write();
        cout << endl;

        no_name.deposit(12);
        cout	<< "After depositing $12.00 that account has $"
		<< no_name.balance() << endl;

        dummy.deposit(50.00);	// Causes error due to uninitialized account.

}
