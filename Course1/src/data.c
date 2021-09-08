/*
 * @file data.c
 * @brief Abtraction of number conversion from integer to ascii and vice-versa
 *
 * This source file implements the declared functions required to convert numbers 
 * to ascii given a base of interest and vice-versa
 *
 * @author Udoh Chiemezie Albert
 * @date September 3 2021
 *
 */


#if defined (TEST_DATA)
    #include "../include/common/data.h"
#else
    #include "data.h"

#endif


/*------------------- bin_1s_comp ------------------------------------------------*
 *
 * This function is private - not visible to public - not declared in header file
 * This function inverts ascii data stored in a buffer from '0'
 * to '1' and vice versa. Hence called the 1's compliment
 *
 * @param buff_start_addr    : Pointer to buffer start address
 * @param bit_size           : buffer size - no of bits in data (0b11001 - 5bits)
 *
 * @return                   : void
 *
 *-------------------------------------------------------------------------------*/
void bin_1s_comp(uint8_t * buff_start_addr, uint8_t bit_size){
    // invert all to bits - 1st complement

    for (int i=0; i<bit_size; i++){                            // loop through all bits
        
        if ((*(buff_start_addr+i)) == '1'){                    // check if bit value is 1
            *(buff_start_addr+i) = '0';                        // change bit value to 0 if 1    
        }else{                                                 // if bit value is 0 change to 1
            *(buff_start_addr+i) = '1';
        }
    }
}



/*------------------- bin_add_one ------------------------------------------------*
 *
 * This function is private - not visible to public - not declared in header file
 *
 * This function performes binary addition of 1 to a binary data stored as ascii 
 * in buffer. 
 * Starting from the least bit, '1's are changed to '0' until it reaches a bit
 * which is '0'. This bit is then changed to '1' and the loop stops.
 *
 * @param buff_start_addr    : Pointer to buffer start address
 * @param bit_size           : buffer size - no of bits in data (0b11001 - 5bits)
 *
 * @return                   : void
 *
 *-------------------------------------------------------------------------------*/
void bin_add_one(uint8_t * buff_start_addr, uint8_t bit_size){
    // add 1  to binary data
    
    for (int i=0; i<bit_size; i++){
    
        if ((*(buff_start_addr+i)) == '0'){       // check if bit contains '0' else continue loop
            *(buff_start_addr+i) = '1';           // change bit value from 0 to 1
            break;                                // stop loop if bit original was 0
        }else{                                    // continue loop if bit is not '0'
            *(buff_start_addr+i) = '0';           // change bit value from '1' to '0'

        }
    }
}



/*------------------- bin_2s_comp ------------------------------------------------*
 *
 * This function is private - not visible to public - not declared in header file
 *
 * This function performes 2's compliment - (negative integer in binary form)
 *
 * it is done using two steps
 * 	1st complement - invert all to bits   - use function: bin_1s_comp 
 * 	2nd complement - add 1 to binary data - use function: bin_add_one
 *
 * @param buff_start_addr    : Pointer to buffer start address
 * @param bit_size           : buffer size - no of bits in data (0b11001 - 5bits)
 *
 * @return                   : void
 *
 *-------------------------------------------------------------------------------*/
void bin_2s_comp(uint8_t * buff_start_addr, uint8_t bit_size){
    // Performs the binary 2's complement operation
     
    bin_1s_comp(buff_start_addr, bit_size); // 1st complement - invert all to bits
    bin_add_one(buff_start_addr, bit_size); // add 1 to binary data - 2nd complement

}



/*------------------- int_2_ascii ------------------------------------------------*
 *
 * This function is private - not visible to public - not declared in header file
 *
 * This function converts integer to ascii. Integers 0 - 9 are converted by adding
 * 0x30 to get the corresponding ascii byte
 *
 * Integers 10 -15 are converted directly by coding
 *
 *
 * @param integer : unsigned 8byte integer
 *
 * @return        : unsigned 8byte integer type which stores char
 *
 *-------------------------------------------------------------------------------*/
uint8_t int_2_ascii(uint8_t integer){

    switch(integer){
        case 10: return 'A';
        case 11: return 'B';
        case 12: return 'C';
        case 13: return 'D';
        case 14: return 'E';
        case 15: return 'F';
        default:                          // for all remainder below 10 (0-9)
            return (integer + 0x30);      // convert remainder to ascii from integer
    }

}




/*------------------- ascii_2_int ------------------------------------------------*
 *
 * This function is private - not visible to public - not declared in header file
 *
 * This function converts ascii to integer. Integers 0 - 9 are converted by subtracting
 * 0x30 to get the corresponding integer
 *
 * Integers 10 -15 are converted directly by coding
 *
 *
 * @param integer : unsigned 8byte integer which stores char
 *
 * @return        : unsigned 8byte integer 
 *
 *-------------------------------------------------------------------------------*/

uint8_t ascii_2_int(uint8_t ascii){

    switch(ascii){
        case 'A': return 10;
        case 'B': return 11;
        case 'C': return 12;
        case 'D': return 13;
        case 'E': return 14;
        case 'F': return 15;
        default:                      // for all remainder below 10 (0-9)
            return (ascii - 0x30);    // convert remainder to ascii from integer
    }

}




/*------------------- my_pow ------------------------------------------------*
 *
 * This function is private - not visible to public - not declared in header file
 *
 * This function performs the power multiplication of a given base (2^^3) = 8
 *
 *
 * @param base  : int32_t (2)
 * @param power : int32_t (3)
 *
 * @return      : int32_t (8)
 *
 *-------------------------------------------------------------------------------*/
int32_t my_pow(int32_t base, uint32_t power){
    int32_t res=0;               // store the result of multiplication
    
    if (power==0){               // example: 2^^0 = 1
        res = 1;                 
    }else if (power==1){         // example: 2^^1 = 2
        res = base;
    }else{
        res = 1;                 // set result to 1 for multiplication
        while(power != 0){       // example: 2^^2 = 4
            res *= base;	 // add multiplication result until power value is 0
            power--;             // update power value after multiplication
        }
    }
    return res;

}




/*------------------- int_2_base_digits ------------------------------------------------*
 *
 * This function is private - not visible to public - not declared in header file
 *
 * This function performes convertion from integer to base digits.
 * 5 (base10) = 0101 (base2)
 * 5 (base10) = 0x05 (base16)
 *
 * This execution is performed using a buffer as output are stored in ascii char
 * @param buff_addr    : Pointer to buffer start address of type uint8_t
 * @param int_data     : int32_t integer (base10)
 * @param base         : uint32_t base - target base
 *
 * @return             : unsigned 8byte integer which stores length of char in buffer
 *
 *--------------------------------------------------------------------------------------*/
uint8_t int_2_base_digits(uint8_t * buff_addr, int32_t int_data, uint32_t base){

    uint8_t rem;			   // stores remainder
    uint8_t data_str_len = 0;              // length of char store in buffer

    while(int_data != 0){
        ++buff_addr;                       // Update buffer pointer to next byte address
        rem  = int_data % base;
        *buff_addr = int_2_ascii(rem);     // convert to ASCII (+ 0x30) and store in buffer
        int_data = int_data/base;          // Update data
        data_str_len++;                    // Updata string size
    }

    return data_str_len;
}



uint8_t binAscii_2_baseAscii(uint8_t * buff_addr, uint8_t bit_size, uint8_t base_size){

    uint8_t base_pow_idx = 0;
    uint8_t base_res = 0;
    uint8_t data_str_len = 0;

    for(int i=1; i<= bit_size; i++){
        //printf("\n% d: %c", i, (*(buff_start_addr + i)));
        base_res += ascii_2_int(*(buff_addr + i)) * my_pow(2,base_pow_idx);
        *(buff_addr + i) = 0;                 // replace data with 0 after process
        base_pow_idx++;
                  
        if ((base_pow_idx == base_size) || (i==bit_size)){
            base_pow_idx = 0;                       // reset base power to 0; base16 - (0, 1, 2, 3)
            data_str_len++;                         // update string count
            base_res = int_2_ascii(base_res);       // convert int to ascii
            *(buff_addr + data_str_len) = base_res;
            base_res = 0;                           // reset base_res for next quad

        }
    }
    return data_str_len;
}



uint8_t bit_fill_up(uint8_t * buff_addr, uint8_t bit_count, uint8_t bit_size){
    uint8_t data_str_len=0;
    
    while((bit_count+1) <= bit_size){      // next bit count = bit_count + 1
        *(++buff_addr) = '0';
        bit_count++;
        data_str_len++;
    }
return data_str_len;
}


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



uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base){
// convert from integer to ascii string
 
    uint8_t * buff;
    uint8_t buffer_len = 35;
    buff = (uint8_t *)malloc(sizeof(uint8_t)*buffer_len);  // reserve data structure on the heap
    uint8_t * buff_start_addr = buff;                      // store buffer start address
    int8_t FLAG_SIGN = 0;                                  // 1:-VE ; 0:+VE
    int8_t data_str_len=0;                                 // data string size
    uint8_t bit_count =0;
    uint8_t bit_size =32;

    // update the null pointer
    *(buff) = '\0';                                        // null to end the buffer
    data_str_len++;		                           // Update string size (Null)
    //printf("\nPointer start: %p", buff);
    //printf("\nBase: %d", base);

    // check if data is positive or negative and update sign flag if negative
    if ((data != 0) && (data < 1)){
        FLAG_SIGN=1;                                       // data is negative
        data *= -1;                                        // convert -ve to +ve   
    }

    if (data == 0){
        *(++buff) = 0x30;
        data_str_len++;
         
    }else{
        data_str_len += int_2_base_digits(buff, data, base);
        buff = (uint8_t *)(buff_start_addr + (data_str_len-1)); // update the buff to end addr
        //printf("\n%d", data_str_len);

    }

    // check sign flag
    switch (base){
        
        case 2:
            if (FLAG_SIGN){                             // initiate 2's complement execution
                
                // fill  up the bits
                bit_count = buff - buff_start_addr;     // get no of bits after int2base conversion
                data_str_len += bit_fill_up(buff, bit_count, bit_size); // fill up bit 32;
                buff = (uint8_t *)(buff_start_addr + (data_str_len-1)); // update buff to end addr

                // Performs the binary 2's complement operation 
                bin_2s_comp(buff_start_addr+1, bit_size);               // index 0 contain Null \0
            }
            *(++buff) = 'b'; data_str_len++;                            // adding base symbol
            *(++buff) = '0'; data_str_len++;		                // adding base symbol
            break;



        case 8:

            if (FLAG_SIGN){ // operation to be executed in binary and converted back to base
                
                data_str_len = 1;                               // reset string count to contain \0
                buff = (uint8_t *)(buff_start_addr);            // reset buffer to point to null \0

                data_str_len += int_2_base_digits(buff, data, 2);// convert to base digit in binary
                buff = (uint8_t *)(buff_start_addr + (data_str_len-1)); // update buff to end addr

                // fill up the bits (remaining bits are fill up to 32 bits)
                bit_count = buff - buff_start_addr;
                //printf("\n%d", bit_count);
                data_str_len += bit_fill_up(buff, bit_count, bit_size); // fill up bit 32;

                // Performs the binary 2's complement operation 
                bin_2s_comp(buff_start_addr+1, bit_size);  // index 0 contain Null \0

                // convert back to base 8
                data_str_len = 1;                               // reset string count to contain \0
                data_str_len += binAscii_2_baseAscii(buff_start_addr, bit_size, 3);
                buff = (uint8_t *)(buff_start_addr + (data_str_len-1)); // update buff to end addr

            }
            *(++buff) = 'c'; data_str_len++;                              // adding base symbol
            *(++buff) = '0'; data_str_len++;		                  // adding base symbol
            break;


        case 16:

            if (FLAG_SIGN){
                // 2's complement execution
                data_str_len = 1;                               // reset string count to contain \0
                buff = (uint8_t *)(buff_start_addr);            // reset buffer to point to null \0
                data_str_len += int_2_base_digits(buff, data, 2);// convert to base digit in binary
                buff = (uint8_t *)(buff_start_addr + (data_str_len-1)); // update buff to end addr

                // fill  up the bits
                bit_count = buff - buff_start_addr;
                data_str_len += bit_fill_up(buff, bit_count, bit_size); // fill up bit 32;

               // Performs the binary 2's complement operation 
               bin_2s_comp(buff_start_addr+1, bit_size);      // index 0 contain Null \0

               // convert back to base 16
               data_str_len = 1;                               // reset string count to contain \0
               buff = (uint8_t *)(buff_start_addr);            // reset buffer to point to null \0
               data_str_len += binAscii_2_baseAscii(buff, bit_size, 4);
               buff = (uint8_t *)(buff_start_addr + (data_str_len-1)); // update the buff
            }
            *(++buff) = 'x'; data_str_len++;                              // adding base symbol
            *(++buff) = '0'; data_str_len++;		                  // adding base symbol
            break;


        case 10:
            if (FLAG_SIGN){
                *(++buff) = '-';             // add minus sign to string
                data_str_len++;              // Updata string size
            }
            break;
        default:
            NULL;
    }
    

/*  This section copies the ascii char from buff to ptr in reverse other
 *  but this operation has been replaced with following functions
 *  my_reverse & my_memcopy

    // ** code starts here **
    printf("\nPointer before: %p, %c", (buff), *(buff));
    printf("\nFUNC ASCII: ");
    while((*(buff)) != '\0'){
        printf("%c", *(buff));      // copy to ascii char to ptr addr
        *ptr = *(buff);
        //printf("\nPointer return: %p", (buff));
        ptr++; buff--;    
    }
    *ptr = *(buff);                //  copy NULL char to ptr

*/
    //printf("\n\nPointer exit: %p", buff);

/*
    for(int i=0; i<= 35; i++){
        printf("\n%d: %c", i, (*(buff_start_addr + i)));
    }
*/
    my_reverse(buff_start_addr, data_str_len);     // reverse the other of data in buff
                                                   // ['\0', '1', '1', '4'] ->  '4','1','1','\0'
    my_memcopy(buff_start_addr, ptr, data_str_len);// copy ascii chars from buff to ptr addr
    free((void *)buff_start_addr);                 // make buffer available again for use

    return data_str_len;

}



#if defined (TEST_DATA)
void test_itoa( int32_t data, uint8_t * ptr, uint32_t base){

    uint8_t str_len = my_itoa(data, ptr, base);
    printf("\nMAIN ASCII 1: ");

    for(int i=0; i<str_len; i++){
        printf ("%c", *(ptr+i));

    }
    
    printf("\nMAIN ASCII 2: ");
    for(int i=0; i<35; i++){
        if ((*(ptr+i)) != '\0'){
            printf ("%c", *(ptr+i));
        }else{
            break;
        }

    }
    printf ("\nstring length: %d\n", str_len);


}
#endif





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

int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base){
    //uint8_t * buff_start_addr = ptr;               // store buffer start address
    int8_t FLAG_SIGN = 0;                          // 1:-VE ; 0:+VE
    int32_t res_int = 0;

    // check sign data for base 10;
    if (*(ptr) == '-') FLAG_SIGN = 1;


    // update to the last pointer address containing integer ascii data
    ptr = ptr + (digits-2); 
    switch (base){

        case 2:
            //ptr = ptr + (digits-2); 		  // skip '0' and 'b'
            digits -= 3;                          // exclude '\0', 'b' and  '0'
            break;

        case 8:
            //ptr = ptr + (digits-2); 		  // skip '0' and 'c'
            digits -= 3;                          // exclude '\0', 'c' and  '0'
            break;

        case 10:
            if (FLAG_SIGN) {
                digits -= 2;             	 // update address ascii integer & '-' in buffer;
            }else{
                digits -= 1;                     // update address only ascii integer in buffer   
            }
            break;

        case 16:
            //ptr = ptr + (digits-2); 		  // skip '0' and 'x'
            digits -= 3;                          // exclude '\0', 'x' and  '0'
            break;

        default:
            NULL;


    }
    // fetch ascii digit, convert to int, convert to base
    for (int i=0; i<digits; i++){
        res_int += (int32_t)ascii_2_int(*(ptr)) * my_pow(base, i);
        ptr--;                                           // decrease pointer addr
    }
    if ((FLAG_SIGN==1) && (base==10)) res_int *= -1;     // update result if signed

    return res_int;

}


#if defined (TEST_DATA)
void test_atoi(uint8_t * ptr, uint8_t digits, uint32_t base){

    int32_t integer = my_atoi(ptr, digits, base);
    printf ("\nascii to int: %i\n", integer);


}
#endif

#if defined (TEST_DATA)

int main(){
    int32_t data = 123456;
    char ptr[35];
    uint8_t str_len;



    // test the itoa function
    printf ("\n*** Base 2");
    test_itoa(data, ptr, 2);     // base 2
    test_atoi(ptr,35, 2);        // base 2 +ve(digits:5); -ve(digits:32)

    printf ("\n*** Base 8");
    test_itoa(data, ptr, 8);     // base 8  
    test_atoi(ptr, 14, 8);       // base 8 +ve(digits:5); -ve(digits:11)

    printf ("\n*** Base 10");
    test_itoa(data, ptr, 10);    // base 10
    test_atoi(ptr, 7, 10);      // base 10 +ve(digits:2); -ve(digits:2)

    printf ("\n*** Base 16");
    test_itoa(data, ptr, 16);    // base 16
    test_atoi(ptr, 11, 16);       // base 16 +ve(digits:2); -ve(digits:8)
    
    // test the power function
    printf ("\npower of 3^3: %d\n", my_pow(3, 3));


    // test ascii to int
    printf ("\nchar E: %d\n", ascii_2_int('E'));
    printf ("\nchar 1: %d\n", ascii_2_int('1'));

}

#endif
