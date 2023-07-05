#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "BinarySearchTree.h"

node_t *createBST(const value_type_t value)
{
    node_t *node = (node_t *)malloc(sizeof(node_t));

    if (NULL == node)
    {
        return NULL;
    }

    node->left = NULL;
    node->right = NULL;
    node->value = value;

    return node;
}

node_t *freeBST(node_t *node)
{
    if (NULL == node)
    {
        return NULL;
    }

    free(node);

    return NULL;
}

void insertNode(node_t *root, node_t* node)
{

        if(root == NULL || node == NULL)
        {
            return NULL;
        }


    node_t* current_node = root;

       while(true)
       {
        if(node->value < current_node->value)
        {
            if(current_node->left == NULL)
            {
                current_node->left = node;
                break;
            }
            else
            {
            current_node = current_node->left;

            }

        }
        else
        {
            if(current_node->right == NULL)
            {
                current_node->right = node;
                break;
            }
            else
            {
            current_node = current_node->right;

            }
        }
       }

}

node_t *minValueNode(node_t* node)
{
    if( node == NULL)
    {
        return NULL;
    }

    node_t* next_node = node->left;

    while(next_node !=NULL)
    {
        next_node = next_node->left;
    }

    return next_node;

}

node_t *removeNode(node_t* root, value_type_t value)
{



}

void printBST(const node_t *const node)
{
    if (NULL == node)
    {
        return;
    }
}
