/**
* @file task1.h
* @brief The header file project 
*/

#ifndef TASK1_H_
#define TASK1_H_

/**
* @brief	This function searches the log2 of the number
* @param	[in]	x Long integer number, x >= 0	
* @return	int
*/
unsigned short Log2 ( unsigned long x );

/**
* @brief	This function checks the number of appliances to the set {0,1,2,4,8,...}
* @param	[in]	x Long integer number, x >= 0
* @post		return value is 1 if the number belongs to the set, 0 - if not
* @return	int
*/
unsigned short DegreeOfNumber ( unsigned long x );

/**
* @brief	This function creates a block of bits equal to 1 in the number
* @param	[in]	p Bit number from which the unit starts, 0 <= p <= 31
* @param	[in]	n The number of bits equal to 1, 1 <= n <= 32-p
* @remark	bits out of the block is 0
* @return	undigned long
*/
unsigned long BitBlock ( unsigned short p, unsigned short n );

/**
* @brief	Function finds the absolute difference of two numbers
* @param	[in]	a The first number (minuend)
* @param	[in]	b The second number (subtrahend)
* @return	unsigned long
*/
unsigned long AbsSub ( long a, long b );

/**
* @brief	This function looks for a block of two bits equal to 1 in a binary code of number
* @param	[in]	x Long integer number, x >= 0
* @post		returns 1 if the block of two bits equal to 1 is not found, 0 - if not
* @return	int
*/
unsigned short TwoBits  (unsigned long x );

/**
* @brief	This function provides the correct input data by user
* @param	[in]	minValue Minimum value unput data by user
* @param	[in]	maxValue Maximum value unput data by user
* @return	unsigned short, unsigned long, long
*/
template< typename T > 
T ProtectionInput ( T minValue, T maxValue );  

#endif /* TASK1_H_ */