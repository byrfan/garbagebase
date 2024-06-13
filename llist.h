#include "table.h"

#ifndef HEADER_FILE
#define HEADER_FILE

typedef struct Node Node;

Node* create_list(ht* table);
void print_list(Node* n);
Node* get_tail(Node* n);
void insert_at_pos(Node* n, int p, ht* table);
void append(Node* n, ht* table);
Node* push(Node* n, ht* table);

#endif /* HEADER_FILE */

