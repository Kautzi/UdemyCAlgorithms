#include "bubble_sort.h"
#include <stdlib.h>
#include <stdio.h>


/*Implement the bubble sort function for an 1D array*/

//### Function Declaration ###

void printArray(int* array, size_t size_of_array)
{

    for(size_t i = 0; i < size_of_array; i++)
    {
        if(i == size_of_array-1)
        {
            printf("%d ",array[i]);
        }
        else
        {
        printf("%d, ",array[i]);
        }

    }
    printf("\n");
}

int * bubbleSort(int* array, size_t size_of_array)
{

    for(size_t i = 0 ; i < size_of_array; i++)
    {

        for(size_t j = 0; j < size_of_array-1 - i; j++)
        {
            if(array[j] < array[j+1])
            {
                swap(array, j,j+1);
            }

        }
    }

    return array;

}

void swap(int* array, size_t idx1,size_t idx2 ) // Tested => PASS
{

    int temp = array[idx1];

    array[idx1] = array[idx2];

    array[idx2] = temp;



return;

}
