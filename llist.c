#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* create_list(int p) {
    Node* head = (Node*) malloc(sizeof(Node));
    if (head == NULL) {
        return NULL; // Handle allocation failure
    }
    head->data = p;
    head->next = NULL;
    return head;
}

void print_list(Node* n) {
    while (n != NULL) {
        printf("%d ", n->data);
        n = n->next;
    }
    printf("\n");
}

Node* get_tail(Node* n) {
    if (n == NULL) return NULL;
    while (n->next != NULL) {
        n = n->next;
    }
    return n;
}

void insert_at_pos(Node* n, int p, int m) {
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
    current->data = m;

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


void append(Node* n, int m) {
    Node* tail = get_tail(n);
    Node* current = (Node*) malloc(sizeof(Node));
    if (current == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return;
    }
    current->data = m;
    current->next = NULL;
    tail->next = current;
}

Node* push(Node* head, int m) {
    Node* current = (Node*) malloc(sizeof(Node));
    if (current == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return NULL;
    }
    current->data = m;
    current->next = head;
    return current;
}

