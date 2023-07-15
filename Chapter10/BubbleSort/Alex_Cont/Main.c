#include <stdio.h>
#include <stdlib.h>


#include "bubble_sort.h"



int main(void){

    int array[10]={2,-3,50,6,-1,43,90,11,-100,1};

    printArray(array,10);
    bubbleSort(array,10);
    printArray(array,10);
    /*
    printArray(array,10);

    bubbleSort(array,10);

    printArray(array,10);
*/

    return 0;
}
