// MODULE:		account.cpp
// PROGRAMMER:	Gary J. Blair
// LANGUAGE:	C++
// DATE:		96/04/11
//
// PURPOSE:
//   Implementation of account objects.
//   Demonstrate fundamental concepts about classes.

#include        <iostream.h>
#include        <stdlib.h>
#include        "account.h"

Account::Account(void)
{
        this->initialized = 0;
}

Account::Account( AccountNumber acct_num, Money acct_bal )
{
        this->initialized = 1;
        this->account_number = acct_num;
        this->account_balance = acct_bal;

}

void    Account::deposit( Money amount )
{
        this->verify_initialization();
        this->account_balance += amount;
}

void    Account::withdraw( Money amount )
{
        verify_initialization();
        account_balance -= amount;

}

Account::Money Account::balance(void)
{
        verify_initialization();
        return account_balance;
}

void     Account::write(void)
{
      verify_initialization();
      cout << account_number << ":" << account_balance;
}

void     Account::read(void)
{
        cin >> account_number;
        if (cin.get() != ':')
        {
                cerr << "*** Error reading account: no colon.\n";
                exit(1);
        }
        cin >> account_balance;
        initialized = 1;
}

void    Account::verify_initialization(void)
{
        if (initialized)
                return;
        else
        {
                cerr << "*** Attempt to use uninitialized account.\n";
                exit(1);
        }
}
