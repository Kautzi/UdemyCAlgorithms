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

    printf("Has capacity => %u\n",stack->capacity);

    return;


}
