#include <stdio.h>
#include <stdlib.h>//malloc,calloc,realloc

#include "Stack.h"

stack_t *createStack(const uint32_t capacity)
{
    stack_t *array = (stack_t*) malloc(sizeof(stack_t));

    if(array == NULL)
    {
        return NULL;
    }

    value_type_t *data = (value_type_t*)malloc(sizeof(value_type_t)*capacity);

    if(data == NULL)
    {
        free(array);
        return NULL;
    }

    array->data=data;

    array->size=0U;
    array->capacity=capacity;

    return array;

}

stack_t *freeStack(stack_t *stack)
{
    if(stack == NULL)
    {
        return NULL;
    }

    if(stack->data != NULL)
    {
    free(stack->data);
    stack->data=NULL;
    }

    free(stack);
    stack=NULL;

    return NULL;
}

void printStack(const stack_t *const stack)
{
    if(stack == NULL )
    {
        return;
    }

    printf("Stack has size of %u and a capacity of %u\n",stack->size,stack->capacity);

    for(uint32_t i = stack->size    ; i > 0; i --)
    {
        printf("Index: %d, Value: %f\n", i-1, stack->data[i-1]);
    }

    return;


}

bool isFull(const stack_t *const stack)
{
    if(stack == NULL)
    {
        return false;
    }

    if(stack->size >= stack->capacity)
    {
        return true;
    }
    else
    {
        return false;
    }

}

bool isEmpty(const stack_t *const stack)
{
    if(stack == NULL)
    {
        return false;
    }

    if(stack->size == 0)
    {
        return true;
    }
    else
    {
        return false;
    }

}

value_type_t top(const stack_t *const stack)
{
    if(stack == NULL || isEmpty(stack))
    {
        return NO_VALUE;
    }

    return stack->data[stack->size - 1u];

}

void push(stack_t *const stack, const value_type_t value)
{

    if(stack == NULL || isFull(stack))
    {
        return;
    }

    stack->data[stack->size]= value;
    stack->size++;
    return;

}

value_type_t pop(stack_t *const stack)
{
    if(stack == NULL || isEmpty(stack))
    {
        return NO_VALUE;
    }
    value_type_t return_val = top(stack);
    stack->data[stack->size - 1]=NO_VALUE;
    stack->size--;

    return return_val;
}
