#include <assert.h>
#include "Queue.h"
#include <stdio.h>



int main(void)
{
    const uint32_t capacity = 4U;
    queue_t *FIFO = createQueue(capacity);



    freeQueue(FIFO);
    return 0;
}
