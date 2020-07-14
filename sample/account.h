// MODULE:		account.h
// PROGRAMMER:	Gary J. Blair
// LANGUAGE:	C++
// DATE:		96/04/11
//
// PURPOSE:
//   Declaration of account objects.
//   Demonstrate fundamental concepts about classes.

class	Account
{
        public:	// The following members may be accessed anywhere.

		// Define some representational types.

        typedef		unsigned long	AccountNumber;
        typedef		double			Money;

		// The 0-argument constructor.

        Account(void);

		// A 2-argument constructor.

        Account( AccountNumber acct_num, Money acct_bal );

		// A member function to deposit money in an account.

        void     deposit( Money amount );
 		// A member function to withdraw money from an account.

        void     withdraw( Money amount );

		// A member function to inquire the current balance.

        Money    balance(void);

		// A member function to read account information in the
		// form acct-num:acct-bal from cin.

        void     read(void);

		// A member function to write account information in the
		// form acct-num:acct-bal to cout.

        void     write(void);

        private:	// The following members may only be accessed
					// by member functions.

        AccountNumber	account_number;	// The account number.
        Money		account_balance;	// Account balance.
        int		initialized;			// Has account been init'ed?

		// A member function to ensure that an account has been initialized
		// prior to actual use.

        void     verify_initialization(void);
};
