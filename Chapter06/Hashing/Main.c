#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include "HashTable.h"

int main()
{
    const char name1[] = "Jan";
    const char name2[] = "Maxi";
    const char name3[] = "Lena";
    const char name4[] = "Peter";
    const char name5[] = "Lara";

    printf("Key: %s, Idx: %u\n", name1, hash(name1));
    printf("Key: %s, Idx: %u\n", name2, hash(name2));
    printf("Key: %s, Idx: %u\n", name3, hash(name3));
    printf("Key: %s, Idx: %u\n", name4, hash(name4));
    printf("Key: %s, Idx: %u\n", name5, hash(name5));
}
