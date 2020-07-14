// MODULE:		adder.cpp			
// PROGRAMMER:	Gary J. Blair
// LANGUAGE:	C++
// DATE:		97/08/04
//
// PURPOSE:
//		Add 2 numbers together.
//		Illustrate use of files with streams.

#include	<iostream.h>
#include	<fstream.h>

void	main(void)
{
	char		input_filename[1024];	// Name of input file.
	char		output_filename[1024];	// Name of output file.
	int			a,b;					// 2 ints from input file.
	int			sum;					// Sum of a and b.

	cout	<< "Enter the input file name    ";
	cin		>> input_filename;
	cout	<< "Enter the output filename    ";
	cin		>> output_filename;

	ifstream	data_in(input_filename);	// Stream for input.
	ofstream	data_out(output_filename);	// Stream for output.
	data_in	>> a;
	data_in	>> b;
	sum = a + b;
	data_out	<<	"The sum of " << a << " and " << b
				<<  " is "  << sum  << endl;
	data_out.close();
}
