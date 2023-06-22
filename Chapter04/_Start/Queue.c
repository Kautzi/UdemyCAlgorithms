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




}

value_type_t pop(queue_t *const queue)
{




}

value_type_t front(queue_t *const queue)
{




}

value_type_t back(queue_t *const queue)
{




}
