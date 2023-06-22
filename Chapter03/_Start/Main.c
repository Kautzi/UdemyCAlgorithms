#include <stdio.h>
#include <assert.h>

#include "Stack.h"
#define ASSERT_AREA
int main(void)
{

    const uint32_t capacity = 4U;
    stack_t *stack = createStack(capacity);

    push(stack,0.0F);
    push(stack,1.0F);
    push(stack,2.0F);
    push(stack,3.0F);

#if defined ASSERT_AREA

    assert(0.0F == stack->data[0]);
    assert(1.0F == stack->data[1]);
    assert(2.0F == stack->data[2]);
    assert(3.0F == stack->data[3]);

    assert(true == isFull(stack));
    assert(false == isEmpty(stack));

#endif

    const value_type_t top1 = top(stack);
#ifdef ASSERT_AREA
    assert(top1 == 3.0F);
#endif
    const value_type_t pop1= pop(stack);
#ifdef ASSERT_AREA
    assert(pop1 == 3.0F);
#endif

    printStack(stack);



return 0;
}
