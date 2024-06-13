#include <stdio.h>
#include <stdlib.h>
#include "table.h"
#include "llist.h"

typedef struct Node {
    ht* data;
    struct Node* next;
} Node;

Node* create_list(ht* table) {
    Node* head = (Node*) malloc(sizeof(Node));
    if (head == NULL) {
        return NULL; // Handle allocation failure
    }
    head->data = table;
    head->next = NULL;
    return head;
}

Node* get_tail(Node* n) {
    if (n == NULL) return NULL;
    while (n->next != NULL) {
        n = n->next;
    }
    return n;
}

void insert_at_pos(Node* n, int p, ht* table) {
    if (p == 0) {
        fprintf(stderr, "Cannot insert at the beginning, use push().\n");
        return;
    }

    Node* n_prev = NULL;
    Node* current = (Node*) malloc(sizeof(Node));
    if (current == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return;
    }
    current->data = table;

    // Traverse to find the position just before where the new node will be inserted
    for (int i = 0; i < p; i++) {
        if (n == NULL) {
            fprintf(stderr, "Position is out of bounds.\n");
            free(current);  // Clean up the allocated node as insertion is not possible
            return;
        }
        if (i == p - 1) {
            n_prev = n;
        }
        n = n->next;
    }

    // Handle cases where position is out of bounds
    if (n_prev == NULL) {
        fprintf(stderr, "Invalid position or list too short.\n");
        free(current);  // Clean up the allocated node
        return;
    }

    // Insert the new node in the middle of the list
    current->next = n_prev->next;  // Link the new node to the next node in the list
    n_prev->next = current;        // Link the previous node to the new node
}


void append(Node* n, ht* table) {
    Node* tail = get_tail(n);
    Node* current = (Node*) malloc(sizeof(Node));
    if (current == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return;
    }
    current->data = table;
    current->next = NULL;
    tail->next = current;
}

Node* push(Node* head, ht* table) {
    Node* current = (Node*) malloc(sizeof(Node));
    if (current == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return NULL;
    }
    current->data = table;
    current->next = head;
    return current;
}

