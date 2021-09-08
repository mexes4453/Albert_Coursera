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
 * @file memory.c
 * @brief Abstraction of memory read and write operations
 *
 * This implementation file provides an abstraction of reading and
 * writing to memory via function calls. There is also a globally
 * allocated buffer array used for manipulation.
 *
 * @author Alex Fosdick
 * @date April 1 2017
 *
 */
//#include "memory.h"

#if defined (TEST_DATA)
   // #include <stdint.h>
   // #include <stdio.h>
   // #include <stdlib.h>
    #include "../include/common/memory.h"

#else 
    #include "memory.h"
#endif

/***********************************************************
 Function Definitions
***********************************************************/
void set_value(char * ptr, unsigned int index, char value){
  ptr[index] = value;
}

void clear_value(char * ptr, unsigned int index){
  set_value(ptr, index, 0);
}

char get_value(char * ptr, unsigned int index){
  return ptr[index];
}

void set_all(char * ptr, char value, unsigned int size){
  unsigned int i;
  for(i = 0; i < size; i++) {
    set_value(ptr, i, value);
  }
}

void clear_all(char * ptr, unsigned int size){
  set_all(ptr, 0, size);
}


/*----------------------------- my_memmove -----------------------------*
 *
 * This function takes two byte pointers (one source and one destination)
 * and a length of bytes to move from the source location to the 
 * destination.
 * it checks for overlap of source and destination by checking for 
 * contiguous available space to store data and avoid data corruption
 *----------------------------------------------------------------------*/
uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length){

    // store a copy of start and last byte address for both src and dst
    uint8_t * dst_start_ptr_addr = dst;                          // store dst start addr - copy
    uint8_t * dst_last_ptr_addr = (uint8_t *)(dst + (length-1)); // store dst last byte addr- copy

    uint8_t * src_start_ptr_addr = src;                          // store src byte addr- copy
    uint8_t * src_last_ptr_addr = (uint8_t *)(src + (length-1)); // store src last byte addr- copy
    
    // Check for overlap by comparing the address location of src and dst
    if (dst > src){ // move data from lower start (src) address  to higher start (dst) address
        
        // move data starting from last address upwards
        for (int i=0; i<length; i++){
            (*(dst_last_ptr_addr--)) = (*(src_last_ptr_addr));   // copy data
            (*(src_last_ptr_addr)) = 0;                          // replace with zero after move
            src_last_ptr_addr--;                                 // decrease adddress - next addr
        }
    
    }else if (dst < src){ // move data from higher start (src) to lower start (dst) address
    
        // move data starting from start address downwards    
        for (int i=0; i<length; i++){
            (*(dst_start_ptr_addr++)) = (*(src_start_ptr_addr)); // copy data
            (*(src_start_ptr_addr)) = 0;                         // replace with zero after move
            src_start_ptr_addr++;                                // increase address - next    
        }
    }
    return (dst);                                                // return destination start addr

}


/*----------------------------- my_memcopy -----------------------------*
 *
 * This function takes two byte pointers (one source and one destination)
 * and a length of bytes to copy from the source location to the 
 * destination.
 * 
 * it checks for overlap of source and destination by checking for 
 * contiguous available space to store data and avoid data corruption
 *----------------------------------------------------------------------*/
uint8_t * my_memcopy(uint8_t * src, uint8_t * dst, size_t length){

    // store a copy of start and last byte address for both src and dst
    uint8_t * dst_start_ptr_addr = dst;                          // store dst start addr - copy
    uint8_t * dst_last_ptr_addr = (uint8_t *)(dst + (length-1)); // store dst last byte addr- copy

    uint8_t * src_start_ptr_addr = src;                          // store src byte addr- copy
    uint8_t * src_last_ptr_addr = (uint8_t *)(src + (length-1)); // store src last byte addr- copy
    
    // Check for overlap by comparing the address location of src and dst
    if (dst > src){ // copy data from lower start (src) address  to higher start (dst) address

        // copy data starting from last address upwards
        for (int i=0; i<length; i++){
            (*(dst_last_ptr_addr--)) = (*(src_last_ptr_addr));   // copy data
            src_last_ptr_addr--;                                 // decrease adddress - next addr
        }
    
    }else if (dst < src){ // move data from higher start (src) to lower start (dst) address
    
        // copy data starting from start address downwards    
        for (int i=0; i<length; i++){
            (*(dst_start_ptr_addr++)) = (*(src_start_ptr_addr)); // copy data
            src_start_ptr_addr++;                                // increase address - next    
        }
    }
    return (dst);                                                // return destination start addr
}


/*------------------------ my_memset -----------------------------*
 * 
 * This function takes a pointer to a source memory location, a length 
 * in bytes and set all locations of that memory to a given value.

 *----------------------------------------------------------------*/
uint8_t * my_memset(uint8_t * src, size_t length, uint8_t value){

    uint8_t * start_ptr_addr = src;                              // store start byte addr of data
    for (int i=0; i<length; i++){
        *(start_ptr_addr++) =value;                              // store value in addr &
                                                                 // update pointer addr to next
    }
    return (src);                                                // return src start addr

}



/*------------------------ my_memzero -----------------------*
 *
 * This should take a pointer to a memory location, a length
 * in bytes and zero out all of the memory.
-------------------------------------------------------------*/
uint8_t * my_memzero(uint8_t * src, size_t length){
    
    uint8_t * start_ptr_addr = src;                             // store last byte addr of data

    for (int i=0; i<length; i++){
        *(start_ptr_addr++) =0;                                 // data at current src = 0 
    }
    return (src);                                               // return src start addr
}



/*------------------ my_reverse ------------------------------*
 *
 * This should take a pointer to a memory location 
 * and a length in bytes and reverse the order of
 * all  of the bytes.
 *
 * Data stored in pointers are swapped as the pointer
 * start addr increases and pointer last addr decreases
 * until last addr becomes greater than or equal to start addr
 * -> 0xF1 - 25 <------+  
 * -> 0xF2 - 40 <--+   |
 * -> 0xF3 - 32.   |   |
 * -> 0xF4 - 12 <--+   |
 * -> 0xF5 - 35 <------+
 *
 * -> 0xF1 - 35 <------+  
 * -> 0xF2 - 12 <--+   |
 * -> 0xF3 - 32.   |   |
 * -> 0xF4 - 40 <--+   |
 * -> 0xF5 - 25 <------+
 *------------------------------------------------------------*/
uint8_t * my_reverse(uint8_t * src, size_t length){

    uint8_t * start_ptr_addr = src;                           // store start addr temporarily
    uint8_t * last_ptr_addr = (uint8_t *)(src + (length-1));  // store last byte addr of data
    uint8_t tempByte;                                         // Variable to store data from ptr addr

    /* start reverse data by swapping */
    while (src <= last_ptr_addr){	      // As long as start addr is not equal to last addr
        tempByte = *(src);                // Store byte data temporarily 
        *(src) = *(last_ptr_addr);        // Place data from last addr to first (start) addr
        *(last_ptr_addr) = tempByte;      // Move data stored in temp var from start addr to last addr
        src++;                            // Update start addr -> address increases
        last_ptr_addr--;                  // Update last  addr -> address decreases

        
    }
    return start_ptr_addr;                // return src start addr
}



/*-------------- reserve_words --------------------*
 *
 * This should take number of words to allocate in 
 * dynamic memory by using the malloc function and
 * casting to ptr to the data type
 *-------------------------------------------------*/
int32_t * reserve_words(size_t length){

    int32_t * word_ptr = (int32_t *)malloc(length*sizeof(int32_t)); // reserve memory space on the heap

    return word_ptr;


}


/*----------- free_words -------------*
 *
 * This function Should free a dynamic
 * memory allocation by providing the 
 * pointer src to the function
 *------------------------------------*/
void free_words(uint32_t * src){

    free((void *)src);                 // make occupied memory on heap available for use
}







