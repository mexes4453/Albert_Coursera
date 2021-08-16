/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file <stats.h> 
 * @brief <Statistics function declaration>
 *
 * <This file contains all function declaration for data statistical analysis>
 *
 *
 * @author <Chiemezie Albert Udoh>
 * @date   <15.08.2021>
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/* Add Your Declarations and Function Comments here */

 
void print_statistics(unsigned char *dataSet, unsigned long data_length); 
/**
 * @brief <A function that prints the statistics of an array including minimum, maximum, mean, and  median.>
 *
 * <This function executes the following functions to obtain statistics data
 *       find_minimum(dataSet, data_length)
 *       find_maximum(dataSet, data_length)
 *       find_mean(dataSet, data_length)
 *       find_median(dataSet, data_length)
 * 
 *  The statistics data obtained are printed to screen.>
 *
 *
 * @param <dataSet>       <pointer (memory address) to data set>
 * @param <data_length>   <no of item in data set (array)
 *
 * @return <void : prints to screen >
 */


void print_array(unsigned char *dataSet, unsigned long data_length);
/**
 * @brief <Given an array of data and a length, prints the array to the screen>
 *
 * <This function prints the a given data set to screen >
 *
 * @param <dataSet>       <pointer (memory address) to data set>
 * @param <data_length>   <no of item in data set (array)
 *
 * @return <void : prints to screen >
 */



unsigned char find_median(unsigned char *dataSet, unsigned long data_length); 
/**
 * @brief <Given an array of data and a length, returns the median value>
 *
 * <This function sorts the dataset from largest to smallest using the sort_array function.
 *  and then returns the data value in the middle position of the data set depending on
 *  the number of data items (even or odd) in the data array>
 *
 * @param <dataSet>       <pointer (memory address) to data set>
 * @param <data_length>   <no of item in data set (array)
 *
 * @return <median of data array of type (unsigned char) >
 */



unsigned long find_mean(unsigned char *dataSet, unsigned long data_length);
/**
 * @brief <Given an array of data and a length, returns the mean>
 *
 * <This function finds the average of the given data set>
 *
 * @param <dataSet>       <pointer (memory address) to data set>
 * @param <data_length>   <no of item in data set (array)
 *
 * @return <average of data set array of type (unsigned char) >
 */




unsigned char find_maximum(unsigned char *dataSet, unsigned long data_length);
/**
 * @brief <Given an array of data and a length, returns the maximum>
 *
 * <This function sorts the dataset from largest to smallest using the sort_array function
 *  and then returns the largest data item as minimum>
 *
 * @param <dataSet>       <pointer (memory address) to data set>
 * @param <data_length>   <no of item in data set (array)
 *
 * @return <largest data array item of type (unsigned char) >
 */




unsigned char find_minimum(unsigned char *, unsigned long data_length);  
/**
 * @brief <Given an array of data and a length, returns the minimum>
 *
 * <This function sorts the dataset from largest to smallest using the sort_array function
 *  and then returns the smallest data item as minimum>
 *
 * @param <dataSet>       <pointer (memory address) to data set>
 * @param <data_length>   <no of item in data set (array)
 *
 * @return <smallest data array item of type (unsigned char)>
 */





void sort_array(unsigned char *, unsigned long data_length);
/**
 * @brief <A function that sorts data array from largest to smallest >
 *
 * < Given an array of data and a length, sorts the array from largest to smallest. 
 *   (The zeroth Element should be the largest value, and the last element (n-1) should 
 *   be the smallest value
 * >
 *
 * @param <dataSet>     <pointer (memory address) to data set>
 * @param <data_length> <no of item in data set (array)>
 *
 * @return <no return>
 */
#endif /* __STATS_H__ */

