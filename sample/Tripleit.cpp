// MODULE:         tripleit.cpp
// PROGRAMMER:     Gary J. Blair
// LANGUAGE:       C++
// DATE:           96/04/11
//
// PURPOSE:
//   Multiple numbers by 3.
//   Illustrate inline directive.

#include        <iostream.h>

inline void triple_it( int &x )
{
        x *= 3;
}


void    main(void)
{
        int y=17;

        cout << "Originally y=" << y << endl;
        triple_it(y);
        cout << "After tripling, y=" << y << endl;
}