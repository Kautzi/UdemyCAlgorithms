#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h> //malloc

#include "HashTable.h"


/*
typedef struct item
{

    char key[MAX_NAME_SIZE];
    value_type_t value;

}item_t;

typedef struct hasht_abel
{

    uint32_t capacity;
    uint32_t size;
    item_t* data;

}hash_table_t;
*/

uint32_t hash( char key[MAX_NAME_SIZE])
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

hash_table_t* createHashTable(void)
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

void freeHashTable(hash_table_t* hashtable)
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
    if(hash_table == NULL || item == NULL || hash_table->capacity == hash_table->size)
    {
        return;
    }

    uint32_t hash_value = hash(item->key);

    int32_t compare = strncmp(hash_table->data[hash_value].key,item->key,MAX_NAME_SIZE);

    while(NO_VALUE != hash_table->data[hash_value].value)
    {
        if( 0 == compare)
        {
            break;
        }

        hash_value = (hash_value +1u) % TABLE_SIZE;

        compare = strncmp(hash_table->data[hash_value].key,item->key,MAX_NAME_SIZE);

    }

    hash_table->data[hash_value] = *item;

    if(compare != 0)
    {
        hash_table->size ++;
    }
return;
}

value_type_t getValue(hash_table_t *hash_table,char key[MAX_NAME_SIZE])
{
    if(hash_table == NULL || 0u == hash_table->size)
    {
        return NO_VALUE;
    }

    uint32_t hash_value = hash(key);
    item_t * item = &hash_table->data[hash_value];

    //int32_t compare = strncmp(hash_table->data[hash_value].key,key,MAX_NAME_SIZE);

    while(0u != strncmp(item->key,key,MAX_NAME_SIZE))
    {

        hash_value = (hash_value +1u) % TABLE_SIZE;
        item = &hash_table->data[hash_value];

    }

    value_type_t value = item->value;
    return value;
}

value_type_t removeItem(hash_table_t *hash_table,char key[MAX_NAME_SIZE])
{

 if(hash_table == NULL || 0u == hash_table->size)
    {
        return NO_VALUE;
    }

    uint32_t hash_value = hash(key);
    item_t * item = &hash_table->data[hash_value];

    //int32_t compare = strncmp(hash_table->data[hash_value].key,key,MAX_NAME_SIZE);

    while(0u != strncmp(item->key,key,MAX_NAME_SIZE))
    {

        hash_value = (hash_value +1u) % TABLE_SIZE;
        item = &hash_table->data[hash_value];

    }

    value_type_t value = item->value;

    hash_table->data[hash_value].value = NO_VALUE;

    strncpy(hash_table->data[hash_value].key,DELETED_KEY,MAX_NAME_SIZE);

    hash_table->size--;
return value;


}
