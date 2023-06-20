#include <stdio.h>
#include <assert.h>

#include "Stack.h"

int main(void)
{

    const uint32_t capacity = 4U;
    stack_t *stack = createStack(capacity);

    printStack(stack);



return 0;
}
