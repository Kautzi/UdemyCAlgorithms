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

/*
typedef struct node
{
    value_type_t value;
    struct node *left;
    struct node *right;
} node_t;
*/

void insertNode(node_t *root, node_t* node)
{

        if(root == NULL || node == NULL)
        {
            return;
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
    if (NULL == root)
    {
        return NULL;
    }

    if (value < root->value)
    {
        root->left = removeNode(root->left, value);
    }
    else if (value > root->value)
    {
        root->right = removeNode(root->right, value);
    }
    else
    {
        if (NULL == root->left)
        {
            freeBST(root->right);
            return NULL;
        }
        else if (NULL == root->right)
        {
            freeBST(root->left);
            return NULL;
        }

        node_t *temp = minValueNode(root->right);
        root->value = temp->value;
        root->right = removeNode(root->right, temp->value);

        return NULL;
    }

    return root;
}

void printBST(const node_t *const node)
{
    if (NULL == node)
    {
        return;
    }

    node_t *left_node = node->left;

    node_t *right_node = node->right;

    value_type_t left_value = left_node != NULL ? left_node->value : NO_VALUE;

    value_type_t right_value = right_node != NULL ? right_node->value : NO_VALUE;

    printf(
        "%.2f\n"
        "/   \\\n"
        "%.2f %.2f\n\n",
        node->value,
        left_value,
        right_value
    );
    printBST(node->left);
    printBST(node->right);

}
