#ifndef HEADER_FILE
#define HEADER_FILE

typedef struct Node Node;

struct Node {
    int data;
    Node* next;
};

Node* create_list(int p);
void print_list(Node* n);
Node* get_tail(Node* n);
void insert_at_pos(Node* n, int p, int m);
void append(Node* n, int m);
Node* push(Node* n, int m);

#endif /* HEADER_FILE */

