#ifndef DOUBLE_LINKED_LIST_H
#define DOUBLE_LINKED_LIST_H

/*#############################
######## Includes ############*/
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
/*############################*/
/*##### END Includes #########*/


/*################################
######## Definitions ############*/

#define NO_VALUE (value_type_t)(INFINITY) //for no Value returns


/*###############################*/
/*##### END Definitions #########*/


/*##########################
######## Types ############*/

typedef float value_type_t; // for dynamic type definition use value_type_t instead of float so for future chnge of type float you only have to change it here

/*### Description of node struct:
The node struct gives us the actual value of an Element => value and the adress of the next and
previous value adress as an own node struct in the node struct*/

/* Example
node_t * node ={->value = -21.4,.next=&FF,.prev=&5E}*/


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

/*#########################*/
/*##### END Types #########*/


/*################################
######## Functions ############*/

//Description of creatNode():
/**/
node_t *createNode(const value_type_t value);

node_t *freeNode(node_t *node);

list_t *createList(void);

list_t *freeList(list_t *list);

void pushBack(list_t * list, node_t * node);

value_type_t popBack(list_t *list);

node_t * search_idx(list_t* list, uint32_t idx);

value_type_t popNode(list_t *list,uint32_t idx);

void pushNode(list_t *list, node_t *node,uint32_t idx);

value_type_t valueAtIdx(list_t *list, uint32_t idx);

void pushFront(list_t * list, node_t *node);

value_type_t popFront(list_t *list);

void printList(const list_t * const list);


/*###############################*/
/*##### END Function #########*/

#endif /* DOUBLE_LINKED_LIST_H */
