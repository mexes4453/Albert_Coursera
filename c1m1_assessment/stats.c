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
 * @file   <stats.c> 
 * @brief  <Statistics functions definition>
 *
 * <This file contains all function definition for data statistical analysis>
 *
 *
 * @author <Chiemezie Albert Udoh>
 * @date   <15.08.2021>
 *
 */



#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114,  88,  45,  76, 123,  87,  25,  23,
                              200, 122, 150,  90,  92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  /* Other Variable Declarations Go Here */
  /* Statistics and Printing Functions Go Here */
  //sort_array(test, SIZE);
  print_statistics(test, SIZE);
}

/* Add other Implementation File Code Here */
void print_statistics(unsigned char *dataSet, unsigned long data_length){
    printf("\n*** DATA ARRAY STATISTICAL ANALYSIS ***\n\n");
    printf("\nData array of size %u\n", (unsigned int)data_length);
    print_array(dataSet, data_length);
    printf("\nMedian = %u\n", (unsigned int)find_median(dataSet, data_length));
    printf("\nMean   = %u\n", (unsigned int)find_mean(dataSet, data_length));
    printf("\nMax    = %u\n", (unsigned int)find_maximum(dataSet, data_length));
    printf("\nMin    = %u\n", (unsigned int)find_minimum(dataSet, data_length));
}




void print_array(unsigned char *dataSet, unsigned long data_length){
    unsigned long i = 0;                                // data array indexer
    sort_array(dataSet, data_length);                   // sort the data array         
    printf("\n\nData array: ");                         // start printing on new line

    while(i < data_length){
        if ((i%10) == 0) printf("\n\t");                // only print 10 numbers in a row - newline
        printf("%-3u ", (unsigned int)(*(dataSet++)));  // print data array item
        i++;                                            // increase array index
    }
    printf("\n");
}



unsigned char find_median(unsigned char *dataSet, unsigned long data_length){
    unsigned long dataSum = 0;

    if (data_length ==  0) return 0;                              // check that data length is not zero
    sort_array(dataSet, data_length);                             // Sort the dataset from largest to smallest
    
    if (data_length%2 == 1){                                      // Data length is odd
        return dataSet[(data_length/2)+1];                        // return data item in middle position

    }else{                                                        // Data length is even
        /* return mean of 2 data items in middle position*/
        dataSum = (unsigned long)(dataSet[(data_length/2)]) +     
                  (unsigned long)(dataSet[(data_length/2)+1]);
        
        return (unsigned char) dataSum/2;                         // return mean of data 2 items in mid position
        
    }

}





unsigned long find_mean(unsigned char *dataSet, unsigned long data_length){
    unsigned long dataSum =0;

    if (data_length ==  0) return 0;              // check that data length is not zero

    for (int i=0;i<data_length;i++){              // add all data values in array
        dataSum += (unsigned long)(*(dataSet++));
    }

    return dataSum/data_length;                   // return average (mean)
    
}



unsigned char find_maximum(unsigned char *dataSet, unsigned long data_length){
    sort_array(dataSet, data_length);    // Sort the dataset from largest to smallest
    
    return dataSet[0];                   // return the largest data value - first item in array 


}



unsigned char find_minimum(unsigned char *dataSet, unsigned long data_length){
    sort_array(dataSet, data_length);    // Sort the dataset from largest to smallest
    
    return dataSet[data_length-1];       // return the smallest data value - last item in array 

}



void sort_array(unsigned char *dataSet, unsigned long data_length){
    int x, y;
    unsigned char temp;
    
    // Bubble sorting - largest to smallest
    for (x=0;x<data_length;x++){

        for (y=0;y<(data_length-1);y++){
            
            if (dataSet[y] < dataSet[y+1]){ // compare values and swap if need be
                temp = dataSet[y];          // assign smaller value to temp variable
                dataSet[y] = dataSet[y+1];  // perform swap - move larger value to the left
                dataSet[y+1] = temp;        // perform swap - move smaller value to the right
            }
        }
    }
    
    // print data set to screen
    // print_array(dataSet, data_length);

}





