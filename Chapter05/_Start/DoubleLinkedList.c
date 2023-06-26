#include <stdio.h>
#include "DoubleLinkedList.h"

/*
typedef struct node
{
    struct node *next;  //elements of next => next->value , next->next, next->prev => or NULL if back element see struct list
    struct node *prev;  //elements of prev => prev->value , prev->next, prev->prev => or NULL if front element see struct list
    value_type_t *value;
}node_t;

typedef struct list
{
    node_t * front;
    node_t * back;
    uint32_t size;

}list_t;
*/

node_t *createNode(const value_type_t value)
{

    node_t * node = (node_t*)malloc(sizeof(node_t));
    if(node == NULL)
    {
        return NULL;
    }


    value_type_t * node_value = (value_type_t*)malloc(sizeof(value_type_t));
    if(node_value == NULL)
    {
        free(node);
        return NULL;
    }

    *node_value= value;

    //After allocation memory of all members of the nede struct asign them to their adresses to the node structs

    node->next = NULL;

    node->prev = NULL;

    node->value = node_value;

    return node;



}

node_t *freeNode(node_t *node)
{
    if(node == NULL)
    {
        return NULL;
    }

    free(node->value);
    node->value=NULL;

    free(node);
    node=NULL;

    return NULL;
}

list_t *createList(void)
{

    list_t * list = (list_t*)malloc(sizeof(list_t));
    if(list == NULL)
    {
        return NULL;
    }

    list->front= NULL;
    list->back= NULL;

    list->size=0u;

return list;

}

list_t *freeList(list_t *list)
{

    if(list == NULL)
    {
        return NULL;
    }

    free(list);
    list = NULL;

    return NULL;


}

void printList(const list_t * const list)
{

    if(list == NULL)
    {
        return;
    }

    printf("List contains %u elements.\n",list->size);


}
