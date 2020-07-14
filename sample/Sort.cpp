// MODULE:		sort.cpp	
// PROGRAMMER:	Gary J. Blair
// LANGUAGE:	C++
// DATE:		96/04/11
//
// PURPOSE:
//     	Sort arrays of integers and floats.
//		Illustrate name overloading.

#include        <iostream.h>
#include        <stdlib.h>
                             
void	sort( int x[], int n );
void	sort( float x[], int n );
                            

void	main(void)
{
	int		i;		/* Loop variable. */ 
	int		int_data[] = {16,2,31,47,9,21,83,50,77,25,11,14,41}; 
	int		n_int_data = 13;         
	float	float_data[] = {16.6,2.2,31.1,47.7,9.9,21.1,83.3,50.0,
							77.7,25.5,11.1,14.4,41.1};    
	int		n_float_data = 13;
	
	sort(int_data,n_int_data);			// Invoke sort of int array.
	cout << "int_data sorted:\n";
	for (i=0; i<n_int_data; ++i)
		cout << int_data[i] << endl;
	
	sort(float_data,n_float_data);		// Invoke sort of float array.
	cout << "float_data sorted:\n";
	for (i=0; i<n_float_data; ++i)
		cout << float_data[i] << endl;
	
}


void	sort( int x[], int n )
{
  int	 temp;  		/* Temporary for swapping. */
  int    last;          /* Index of last item to be examined. */
  int    i;             /* Loop over items to be compared. */
  int    sorted;        /* Are things sorted yet? */

  last = n - 1;  /* Because arrays are 0-based. */
  do
  {
    sorted = 1;
    for (i=0; i<last; ++i)
      if (x[i] > x[i+1])
      {
        temp = x[i];
        x[i] = x[i+1];
        x[i+1] = temp;
        sorted = 0;
      }  
    last--;
  }
  while (!sorted);
}


void	sort( float x[], int n )
{
  float	 temp;  		/* Temporary for swapping. */
  int    last;          /* Index of last item to be examined. */
  int    i;             /* Loop over items to be compared. */
  int    sorted;        /* Are things sorted yet? */

  last = n - 1;  /* Because arrays are 0-based. */
  do
  {
    sorted = 1;
    for (i=0; i<last; ++i)
      if (x[i] > x[i+1])
      {
        temp = x[i];
        x[i] = x[i+1];
        x[i+1] = temp;
        sorted = 0;
      }  
    last--;
  }
  while (!sorted);
}

