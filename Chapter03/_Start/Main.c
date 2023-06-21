#include <stdio.h>
#include <assert.h>

#include "Stack.h"

int main(void)
{

    const uint32_t capacity = 4U;
    stack_t *stack = createStack(capacity);

    push(stack,0.0F);
    assert(0.0F == stack->data[0]);
    push(stack,1.0F);
    push(stack,2.0F);
    push(stack,3.0F);
    assert(pop(stack)== 3.0F);

    printStack(stack);



return 0;
}
