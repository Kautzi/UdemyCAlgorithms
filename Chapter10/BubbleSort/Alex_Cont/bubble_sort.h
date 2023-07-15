#ifndef BUBBLE_SORT_H
#define BUBBLE_SORT_H


#include <stdlib.h>
#include <stdint.h>
/*Implement the bubble sort function for an 1D array*/

//### Function Declaration ###

void printArray(int* array, size_t size_of_array); //prints the array

int * bubbleSort(int* array, size_t size_of_array); //sorts the array and returns its adress

void swap(int* array, size_t idx1,size_t idx2 ); // helper function to swap two elemnts of the array

#endif /* BUBBLE_SORT_H */
