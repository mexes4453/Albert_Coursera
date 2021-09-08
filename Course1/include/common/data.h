/**
 * @file data.h
 * @brief Abtraction of number conversion from integer to ascii and vice-versa
 *
 * This header file provides an abstraction of convert numbers to ascii given a base of interest
 * and vice-versa using the functions declared herein. 
 *
 * @author Udoh Chiemezie Albert
 * @date September 3 2021
 *
 */

#ifndef __DATA_H__
#define __DATA_H__

#include <stdio.h>
#include <stdint.h>
#include "memory.h"


/*---------------------------------  my_itoa  -----------------------------------------------*
 * Integer-to-ASCII needs to convert data from a standard integer type into an ASCII string.
 * The number you wish to convert is passed in as a signed 32-bit integer.
 * You should be able to support bases 2 to 16 by specifying the integer value of
 * the base you wish to convert to (base).
 *
 * Copy the converted character string to the uint8_t* pointer passed in as a parameter (ptr)
 * The signed 32-bit number will have a maximum string size (Hint: Think base 2).
 * You must place a null terminator at the end of the converted c-string
 * Function should return the length of the converted data (including a negative sign). 
 * Example my_itoa(ptr, 1234, 10) should return an ASCII string length of 5 (including the null  
 * terminator).
 *
 * This function needs to handle signed data.
 *
 * @param data    : int32_t integer to be converted to ascii
 * @param ptr     : uint8_t * - Pointer to buffer which stores the ascii char
 * @param base    : uint32_t base - target base
 *
 * @return        : unsigned 8byte integer which stores length of char in buffer
 *--------------------------------------------------------------------------------------------*/

uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base);






/*---------------------------------  my_atoi  -----------------------------------------------*
 *
 * ASCII-to-Integer needs to convert data back from an ASCII represented string into an 
 * integer type.
 * All operations need to be performed using pointer arithmetic, not array indexing
 * The character string to convert is passed in as a uint8_t * pointer (ptr).
 * The number of digits in your character set is passed in as a uint8_t integer (digits).
 * You should be able to support bases 2 to 16.
 * The converted 32-bit signed integer should be returned.
 *
 * This function needs to handle signed data.
 *
 * @param ptr     : uint8_t * - Pointer to buffer which stores the ascii char
 * @param digits  : uint8_t   - integer value of no of ascii digits in buffer
 * @param base    : uint32_t  - target base
 *
 * @return        : int32_t   - base10 integer
 *--------------------------------------------------------------------------------------------*/

int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base);



#endif //__DATA_H__
