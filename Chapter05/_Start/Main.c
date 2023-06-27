#include <stdio.h>
#include <assert.h>

#include "DoubleLinkedList.h"


int main(void)
{

    list_t * list = createList();

    node_t * a= createNode(1.0f);
    node_t * b= createNode(2.0f);
    node_t * c= createNode(3.0f);

    pushBack(list,a);
    pushBack(list,b);
    pushBack(list,c);

    printList(list);

    popBack(list);
    popBack(list);
    popBack(list);

    printList(list);

    node_t * d= createNode(1.0f);
    node_t * e= createNode(2.0f);
    node_t * f= createNode(3.0f);

    pushFront(list,d);
    pushFront(list,e);
    pushFront(list,f);

    printList(list);

    popFront(list);
    //popFront(list);
    //popFront(list);

    printList(list);

    list = freeList(list);
    assert(NULL == list);


return 0;
}
