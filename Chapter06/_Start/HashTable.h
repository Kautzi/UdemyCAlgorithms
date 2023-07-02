#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <math.h>
#include <stdint.h>
#include <stdio.h>

//### Defines ###
typedef float value_type_t;
#define NO_VALUE (value_type_t)(INFINITY)

#define TABLE_SIZE (uint32_t)7u
#define MAX_NAME_SIZE (uint32_t)256u
#define DELETED_KEY "DELETED"
#define DELETED_KEY_SIZE (uint32_t)8u

//### END Defines ###

//### Types ###

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

//### END Typed ###

//### Function Declaration ###

uint32_t hash(const char key[MAX_NAME_SIZE]);

hash_table_t* createHashtable(void);

void freeHashtable(hash_table_t* hashtable);

void insertItem(hash_table_t *hash_table,item_t* item);

value_type_t getValue(hash_table_t *hash_table,char key[MAX_NAME_SIZE]);

value_type_t removeItem(hash_table_t *hash_table,char key[MAX_NAME_SIZE]);

void printHashTable(const hash_table_t* const hash_table);


//### END Declarations ###



#endif /* HASH_TABLE_H */
