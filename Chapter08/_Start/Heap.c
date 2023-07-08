#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Heap.h"

heap_t *createHeap(const uint32_t capacity)
{
    heap_t *heap = (heap_t *)malloc(sizeof(heap_t));

    if (NULL == heap)
    {
        return NULL;
    }

    const size_t data_size = capacity * sizeof(value_type_t);
    value_type_t *data = (value_type_t *)malloc(data_size);

    if (NULL == data)
    {
        free(heap);

        return NULL;
    }

    heap->capacity = capacity;
    heap->size = 0u;
    heap->data = data;

    return heap;
}

heap_t *freeHeap(heap_t *heap)
{
    if (NULL != heap->data)
    {
        free(heap->data);
    }

    if (NULL != heap)
    {
        free(heap);
    }

    return NULL;
}


uint32_t parentNode(uint32_t idx)
{

    return (idx - 1u )/ 2u;

}

uint32_t leftChildNode(uint32_t idx)
{

    return (2u * idx) + 1u;

}

uint32_t rightChildNode(uint32_t idx)
{

     return (2u * idx) + 2u;

}

void swap(value_type_t* a,value_type_t* b)
{
    value_type_t temp = *a;

    *a=*b;
    *b=temp;
    return;


}

void insertValue(heap_t* heap, value_type_t value)
{

    if(heap == NULL || heap->size == heap->capacity)
    {
        return;
    }

    heap->size++;
    uint32_t idx = heap->size-1u;
    heap->data[idx]=value;

    while(      (idx != 0 )     &&      (heap->data[parentNode(idx)] > heap->data[idx])      )
    {
        swap(&heap->data[idx],&heap->data[parantNode(idx)]);
        idx = parentNode(idx);

    }

}

void printHeap(const heap_t *const heap)
{
    if (NULL == heap)
    {
        return;
    }
}
