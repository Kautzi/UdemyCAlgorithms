#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h> //malloc

#include "HashTable.h"


/*
typedef float value_type_t;

typedef struct hashtabel
{
    size_t capacity;
    size_t size;
    value_type_t* data;

}hashtable_t;
*/

uint32_t hash(const char key[MAX_NAME_SIZE])
{
    uint32_t hash_value = 0u;

    for (uint32_t i = 0u; i < MAX_NAME_SIZE; i++)
    {
        if ('\0' != key[i])
        {
            hash_value = ((uint32_t)(hash_value * 128U) + (uint32_t)(key[i])) % TABLE_SIZE;
        }
        else
        {
            break;
        }
    }

    return hash_value;
}

hash_table_t* createHashtable(void)
{



    hash_table_t * hashtable = (hash_table_t*)malloc(sizeof(hash_table_t));

        if(hashtable == NULL)
        {
            return NULL;
        }

    const size_t data_size = TABLE_SIZE * sizeof(item_t);

    item_t* data = (item_t*)malloc(sizeof(item_t) * data_size);

        if(data == NULL)
        {
            free(hashtable);
            return NULL;
        }

        for(uint32_t i = 0; i < TABLE_SIZE; i ++)
        {
            strncpy(data[i].key,DELETED_KEY,DELETED_KEY_SIZE);
            data[i].value= NO_VALUE;
        }

    hashtable->capacity = TABLE_SIZE;

    hashtable->size = 0;

    hashtable->data = data;

    return hashtable;

}

void freeHashtable(hash_table_t* hashtable)
{
    if(hashtable == NULL)
    {
        return;
    }

    if(hashtable->data == NULL)
    {
        return;
    }

    free(hashtable->data);
    hashtable->data = NULL;

    free(hashtable);
    hashtable = NULL;

    return;

}

void printHashTable(const hash_table_t* const hash_table)
{

    if(hash_table == NULL)
    {

        return ;

    }

    printf("\nHash Table contains %u elements with capacity of %u.\n", hash_table->size,hash_table->capacity);

    for(uint32_t i = 0; i < TABLE_SIZE; i ++)
    {

        const item_t * const item = &hash_table->data[i];
        printf("Index: %u, Key: %s, Value %f\n",i,item->key,item->value);

    }
}

void insertItem(hash_table_t *hash_table,item_t* item)
{




}

value_type_t getValue(hash_table_t *hash_table,char key[MAX_NAME_SIZE])
{




}

value_type_t removeItem(hash_table_t *hash_table,char key[MAX_NAME_SIZE])
{




}
