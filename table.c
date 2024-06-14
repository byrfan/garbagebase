//#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "table.h"


// hash function
unsigned int hash_djb2(char* str) {
    unsigned int hash = 5381;
    int c;

    while((c = *str++)) {
        hash = ((hash << 5) + hash) + c;
    }
    return hash;
}

bool isPrime(int num) {
    if(num <= 1) return false;
    if(num <= 3) return true;
    if(num % 2 == 0 || num % 3 == 0) return false;

    int i;
    for(i = 5; i * i <= num; i += 6) {
        if(num % i == 0 || num % (i + 2) == 0)
            return false;
    }
    return true;
}

int nextPrime(int num) {
    while(!isPrime(num))
        num++;
    return num;
}

bool htNeedsResizing(ht* table) {
    return (((float) table->length/(float) table->count) >= 0.7) ? true: false; 
}

// initialises the hash table memory and returns a pointer to the table
ht* ht_init(int size) {
    ht* new_table = (ht*) malloc(sizeof(ht));
    new_table->length = size;
    new_table->count = 0;
    new_table->rows = calloc(size, sizeof(hte*));
    return new_table;
}

// initialises the hash table element memory and returns pointer to the element
hte* hte_init(char* key, char* value) {
    hte* element = malloc(sizeof(hte));
    element->key = strdup(key);
    element->value = strdup(value);
    return element;
}

// inserts values into table frees any memory that persists
void htInsert(ht* table, char* key, char* value) {
    if(htNeedsResizing(table)) {
        htResize(table, nextPrime(table->length));
    }

    unsigned int index = hash_djb2(key) % table->length;
    hte* element = table->rows[index];
    
    if(table->rows[index] != NULL) {
        free(table->rows[index]->key);
        free(table->rows[index]->value);
        free(table->rows[index]);
    }

    table->rows[index] = hte_init(key, value);
    table->count++;
}

void htRemove(ht* table, char* key) {
    unsigned int index = hash_djb2(key) % table->length;
    hte* element = table->rows[index];

    if(element != NULL && strcmp(element->key, key) == 0) {
       free(element->key);
       free(element->value);
       free(element);

       table->rows[index] = NULL;
    }

    table->count--;
}

char* htFind(ht* table, char* key) {
    unsigned int index = hash_djb2(key) % table->length;
    return table->rows[index]->value;
} 

void htResize(ht* table, int size) {
    hte** newRows = calloc(size, sizeof(hte*));
    
    for(size_t i=0; i<table->length; i++) {
        hte* element = table->rows[i]; 
        if(element != NULL) {
            unsigned int newIndex = hash_djb2(element->key) % size;
            newRows[newIndex] = element;
        }
    }

    free(table->rows);
    table->rows = newRows;
    table->length = size;
}

// self explanatory
void printTable(ht* table) {
    for(size_t i = 0; i < table->length; i++) {
        if(table->rows[i] != NULL) {
            printf("Key: %s, Value: %s\n", table->rows[i]->key, table->rows[i]->value);
        }
    }
}

