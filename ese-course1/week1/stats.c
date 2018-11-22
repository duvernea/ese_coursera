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
 * @file <Add File Name> 
 * @brief <Add Brief Description Here >
 *
 * <Add Extended Description Here>
 *
 * @author <Add FirsName LastName>
 * @date <Add date >
 *
 */


#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)


void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  /* Other Variable Declarations Go Here */
  /* Statistics and Printing Functions Go Here */
    unsigned char mean = find_mean(test);
    printf("mean: %u\n", mean);

    unsigned char min = find_minimum(test);
    printf("min: %u\n", min);

    unsigned char max = find_maximum(test);
    printf("max: %u\n", max);

    // print_array(test);

    // sort_array(test);

    // print_array(test);

    unsigned char median = find_median(test);
    printf("median: %u\n", median);

}

/* Add other Implementation File Code Here */

unsigned char find_mean(unsigned char numbers[]) {

  unsigned int sum = 0;
	
  for (int i=0; i<SIZE; i++) {
    sum += (unsigned int) numbers[i];
    //printf("%u\n", (unsigned int) numbers[i]);
  }
  unsigned char mean = sum / SIZE;
  // printf ("sum: %u\n\n", sum);
  // printf ("mean: %u\n\n", mean);

  // unsigned char mean = (unsigned char) sum / SIZE;

	return mean;
}

unsigned char find_minimum(unsigned char numbers[]) {

  unsigned int min = numbers[0];
  
  for (int i=1; i<SIZE; i++) {
    if (numbers[i] < min) {
      min = numbers[i];
    }
  }
  return min;
}
unsigned char find_maximum(unsigned char numbers[]) {

  unsigned int max = numbers[0];
  
  for (int i=1; i<SIZE; i++) {
    if (numbers[i] > max) {
      max = numbers[i];
    }
  }
  return max;
}
void sort_array(unsigned char numbers[]) {
  // array is sorted in place. no need for return
  // bubblesort
  int swap;
  for (int i=0; i<SIZE-1; i++) {
    for (int j=0; j<SIZE-i-1; j++) {
      if (numbers[j] < numbers[j+1]) {
        unsigned char temp = numbers[j];
        numbers[j] = numbers[j+1];
        numbers[j+1] = temp;

      }

    }
  } 
}

void print_array(unsigned char numbers[]) {
  for (int i=0; i< SIZE; i++) {
    printf("%u, ", numbers[i]);
  }
  printf("\n");
}
unsigned char find_median(unsigned char numbers[]) {
  unsigned char temp[SIZE];
  for (int i=0; i<SIZE; i++) {
    temp[i] = numbers[i];
  }
  sort_array(temp);
  unsigned char median;
  if (SIZE % 2 == 0) {
    median = (temp[SIZE/2] + temp[SIZE/2-1]) / 2;
  } else {
    median = temp[SIZE/2];
  }

  return median;
}