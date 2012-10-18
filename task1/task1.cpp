/**
* @file task1.cpp
* @brief Source file of project 
*/

#include "task1.h"
#include <iostream>

using namespace std;

// This function searches the log2 of the number
unsigned short Log2 ( unsigned long x )  
{
	short res = 0;	// counter shifts
	while (x > 1) 
	{
		x >>= 1;
		res++;	
	}
	return res;
}

// This function checks the number of appliances to the set {0,1,2,4,8,...}
unsigned short DegreeOfNumber ( unsigned long x )	
{
	return ( (x & (x-1UL) ) - 1UL ) >> 31 ;
}

// This function creates a block of bits equal to 1 in the number
unsigned long BitBlock ( unsigned short p, unsigned short n )
{
	unsigned long x = 0xFFFFFFFF;
	x <<= n;
	x = ~x;
	x <<= p;
	return x;
}

// Function finds the absolute difference of two numbers
unsigned long AbsSub ( long a, long b )
{
	long x = a - b;
	return ( (x >> 30) | 1L) * x;
}

// This function looks for a block of two bits equal to 1 in a binary code of number
unsigned short TwoBits ( unsigned long x )
{
	x &= x << 1;
	x |= x >> 1;
	x |= x >> 2;
	x |= x >> 4;
	x |= x >> 8;
	x |= x >> 16;
	return ~x & 1UL;
}

// This function provides the correct input data by user
template< typename T > 
T ProtectionInput ( T minValue, T maxValue )
{
	long long x;
	while (!scanf("%lld", &x) || (x < minValue || x > maxValue) )
	{
		fflush(stdin);
		printf("Error! Incorrectly input data!\n");
		printf("Please enter the number once again: ");
	}
	return (T)x;
}


void main ( void )
{
	const unsigned short BUFFER_LENGTH = 33;	//	Size of buffer
	char *buffer = new char[BUFFER_LENGTH];
	unsigned short i;
	unsigned long x;
	unsigned short startBit, lengthBlock;	//	number of start-bit, length of bit-block (for function BitBlock)
	long fNumber, sNumber;	//	first number and second number (for function AbsSub)

	while(true)
	{
		printf ("1 - Search log2 of the number (task 14);\n");
		printf ("2 - Checks the number of appliances to the set {0,1,2,4,8,...} (task 15);\n");
		printf ("3 - Creates a block of bits equal to 1 in the number (task 16);\n");
		printf ("4 - Finds the absolute difference of two numbers (task 17);\n");
		printf ("5 - Search a block of two bits equal to 1 in binary code of number (task 18);\n");
		printf ("0 - Exit;\n");
		printf ("Enter the number of action please: ");
		i = ProtectionInput<unsigned short>(0, 5);

		switch(i)
		{
			case 1:
				printf ("\nEnter the unsigned long number please: ");
				x = ProtectionInput<unsigned long>(0, ULONG_MAX);

				printf ("Input values:\n");
				printf ("\tdecimal: %d\n", x);
				itoa(x, buffer, 2);
				printf ("\tbinary:  %032s\n", buffer);
				
				x = Log2(x);
				break;
			
			case 2:
				printf ("\nEnter the unsigned long number please: ");
				x = ProtectionInput<unsigned long>(0, ULONG_MAX);

				printf ("Input values:\n");
				printf ("\tdecimal: %d\n", x);
				itoa (x, buffer, 2);
				printf ("\tbinary:  %032s\n", buffer);
				
				x = DegreeOfNumber(x);
				break;
			
			case 3:
				printf ("\nEnter the number of start bit (0 - 31):     ");
				startBit = ProtectionInput<unsigned short>(0, 31);
				i = 32 - startBit;
				printf ("Enter the length of the bit-block (1 - %d %s", i, "): ");
				lengthBlock = ProtectionInput<unsigned short>(0, i);

				printf ("Input values:\n");
				printf ("\tStart bit      : %d\n", startBit);
				printf ("\tLength of block: %d\n", lengthBlock);

				x = BitBlock (startBit, lengthBlock);
				break;
			
			case 4:
				printf ("\nEnter the first number  : ");
				fNumber = ProtectionInput<long>(LONG_MIN, LONG_MAX);
				printf ("Enter the second number : ");
				sNumber = ProtectionInput<long>(LONG_MIN, LONG_MAX);

				printf ("Input values:\n");
				printf ("\tFirst number decimal : %d\n", fNumber);
				itoa(fNumber, buffer, 2);
				printf ("\tFirst number binary  : %032s\n", buffer);
				printf ("\tSecond number decimal: %d\n", sNumber);
				itoa(sNumber, buffer, 2);
				printf ("\tSecond number binary : %032s\n", buffer);

				x = AbsSub (fNumber, sNumber);
				break;
			
			case 5:
				printf ("\nEnter the unsigned long number please: ");
				x = ProtectionInput<unsigned long>(0, ULONG_MAX);

				printf ("Input values:\n");
				printf ("\tdecimal: %d\n", x);
				itoa(x, buffer, 2);
				printf ("\tbinary:  %032s\n", buffer);

				x = TwoBits(x);
				break;

			default:
				delete[] buffer;
				return;
		}	// End of switch(i)

		printf ("Output values:\n");
		printf ("\tdecimal: %d\n", x);
		itoa(x, buffer, 2);
		printf ("\tbinary:  %032s\n", buffer);

		printf ("Press any key to continue...\n"); 
		_getwch();	// waiting of action
		system("cls");
	}	// End of while(1)
}	// End of main
