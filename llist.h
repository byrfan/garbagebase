#include "table.h"

#ifndef LLIST
#define LLIST


typedef struct Node {
    ht* data;
    struct Node* next;
} Node;

Node* create_list(ht* table);
void print_list(Node* n);
Node* get_tail(Node* n);
void insert_at_pos(Node* n, int p, ht* table);
void append(Node* n, ht* table);
Node* push(Node* n, ht* table);

#endif /* HEADER_FILE */

