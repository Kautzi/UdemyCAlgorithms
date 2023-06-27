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

void pushBack(list_t * list, node_t * node)
{
    if(list == NULL || node == NULL)
    {
        return;
    }

    //if list is empty initialise
    if(list->size == 0u)
    {
        node->next=NULL;
        node->prev=NULL;
        list->back = node;
        list->front = node;

    }

    node->next = NULL;
    list->back->next = node; //first give the actual back element with next == NULL the adress of node
    node->prev = list->back; // then give node the prev adress of the actual back element

    list->back = node;      // now set node as the last element

    list->size++;           // and increment the list size


return;
}

value_type_t popBack(list_t *list)
{
    if(list == NULL)
    {
        return NO_VALUE;
    }

    value_type_t value = *(list->back->value); // tempararily save the value of the
    //back element cause this element is deleted after the next code rows

    // temporarily safe the adress of the actual back element only for deletion

    node_t* temp_back = list->back;


    if(list->size > 1u)
    {
        list->back = list->back->prev; //tell the list that the previes value of the back element is now the back element
        list->back->next = NULL;    // and set the back element next adress to NULL

    }

    else
    {
        list->back = NULL;    // and set the back element next adress to NULL
        list->front = NULL;

    }
    // after doing the poping of the last element we have to
    //delete the previes last element because the memory is allocated yet
    list->size--;
    freeNode(temp_back);

    return value;
}

void pushFront(list_t * list, node_t *node)
{
    if(list == NULL || node == NULL)
    {
        return;
    }

    if(list->size > 0u)
    {
        list->front->prev = node;
        node->next = list->front;
        list->front = node;
        node->prev = NULL;
    }

    else
    {
        list->back = node;    // and set the back element next adress to NULL
        list->front = node;
        node->next=NULL;
        node->prev=NULL;

    }
    list->size++;

}

value_type_t popFront(list_t *list)
{
    if(list == NULL)
    {
        return NO_VALUE;
    }

    node_t * temp = list->front;
    value_type_t value = *(temp->value);

    if(list->size > 1u)
    {
    list->front = list->front->next;
    list->front->prev=NULL;
    }
    else
    {
        list->back=NULL;
        list->front=NULL;
    }

    freeNode(temp);
    list->size--;

    return value;

}

void printList(const list_t * const list)
{

    if(list == NULL)
    {
        return;
    }

    printf("List contains %u elements.\n",list->size);

    //now print all elements

    node_t* print_value = list->front;

    for(uint32_t i = 0; i < list->size;i++)
    {
        printf("%f, \n",*(print_value->value));
        print_value = print_value->next;
    }

}
