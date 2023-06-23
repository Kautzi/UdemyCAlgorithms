#include <stdio.h> //printf...
#include <stdlib.h>//malloc...
#include <assert.h>
#include "Queue.h"

#define ASSERT_AREA

queue_t *createQueue(const uint32_t capacity)
{

    queue_t *FIFO = (queue_t*)malloc(sizeof(queue_t));

    if(FIFO == NULL)
    {
        return NULL;
            #ifdef ASSERT_AREA
                assert(FIFO != NULL);
            #endif
    }

    value_type_t *data = (value_type_t*)malloc(sizeof(value_type_t)*capacity);
    if(data == NULL)
    {
        free(FIFO);
        return NULL;
            #ifdef ASSERT_AREA
                assert(data != NULL);
            #endif
    }

    FIFO->data=data;
    FIFO->size=0u;
    FIFO->capacity=capacity;
    FIFO->front_idx=0u;
    FIFO->back_idx=0u;

    return FIFO;

}

queue_t *freeQueue(queue_t *queue)
{

    if(queue == NULL)
    {
        return NULL;
    }

    free(queue->data);
    queue->data=NULL;
    free(queue);
    return NULL;



}

void printQueue(const queue_t *const queue)
{

    if(queue == NULL)
    {
        return;
    }

    printf("Queue has size of %u and capacity of %u\n",queue->size,queue->capacity);
    for(uint32_t i = 0; i < queue->size;i++)
    {

        uint32_t idx = (i + queue->front_idx) % queue->capacity;
    printf("Element %u at Index %u with Value %f\n",i,idx,queue->data[idx]);

    }

}

bool isFull(const queue_t *const queue)
{

    if(queue == NULL)
    {
        return false;
    }

    return queue->size >= queue->capacity;



}

bool isEmpty(const queue_t *const queue)
{

if(queue == NULL)
    {
        return false;
    }

    return queue->size == 0U;



}

void push(queue_t *const queue, const value_type_t value)
{
    if(isFull(queue))
    {
        return;
    }

    if(queue->size > 0)
    {
    queue->back_idx = (queue->back_idx +1U) % queue->capacity;
    }
    else
    {
        queue->back_idx = 0U;
        queue->front_idx = 0U;
    }

    queue->data[queue->back_idx]=value;
    queue->size++;




}

value_type_t pop(queue_t *const queue)
{

    if(isEmpty(queue))
    {
        return NO_VALUE;
    }

    uint32_t temp_idx = queue->front_idx;//for returning the actual front element

    if(queue->size > 1)
    {

    queue->front_idx = (queue->front_idx +1U) % queue->capacity;

    }
    else
    {
        queue->front_idx = 0U;
        queue->back_idx = 0U;
    }

    queue->size--;

    return queue->data[temp_idx];
}

value_type_t front(queue_t *const queue)
{

    if(isEmpty(queue))
    {
        return NO_VALUE;
    }

    return queue->data[queue->front_idx];

}

value_type_t back(queue_t *const queue)
{

    if(isEmpty(queue))
    {
        return NO_VALUE;
    }

    return queue->data[queue->back_idx];

}
