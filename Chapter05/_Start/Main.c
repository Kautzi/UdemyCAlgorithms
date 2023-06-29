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

    uint32_t idx = 2;

    printf("Value at idx %u = %f\n",idx,*(search_idx(list,idx)->value));

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


    node_t * g= createNode(44.0f);

    pushNode(list,g,2);

    printList(list);

    popNode(list,2);

    printList(list);

    node_t * h= createNode(45.0f);

    pushNode(list,h,3);

    printList(list);

    popNode(list,3);

    printList(list);

    node_t * i= createNode(46.0f);

    pushNode(list,i,0);

    printList(list);

    popNode(list,0);

    printList(list);

    list = freeList(list);
    assert(NULL == list);


return 0;
}
