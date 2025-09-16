#include <stdio.h>
#include <stdlib.h>
#include "slist.h"

/* Insert node at the beginning (head insertion) */
void push_head(node **head, int val){
    if (head == NULL) return;   // invalid pointer

    node* p = malloc(sizeof(node));
    if (!p) return;             // malloc failed
    p->val = val;
    p->next = *head;            // link new node before current head

    *head = p;                  // update head pointer
}

/* Insert node at the end (tail insertion) */
void append_tail(node **head, int val){
    if (head == NULL) return;

    node *p = malloc(sizeof(node));
    if (!p) return;             // malloc failed
    p->val = val;
    p->next = NULL;

    if (*head == NULL){         // if list is empty
        *head = p;
        return;
    }

    node* cur = *head;
    while (cur->next != NULL)   // traverse to last node
        cur = cur->next;
    
    cur->next = p;              // append new node
}

/* Delete the first occurrence of a node with given value */
bool delete_value(node **head, int val){
    if (head == NULL) return false;

    node* prev = NULL;
    node* cur = *head;

    // find target node
    while (cur != NULL && cur->val != val){
        prev = cur;
        cur = cur->next;
    }

    if (cur == NULL) return false;  // not found

    if (prev == NULL)               // deleting head
        *head = cur->next;
    else
        prev->next = cur->next;     // bypass target node

    free(cur);
    return true;                    // <-- missing in your code
}

/* Insert new node after position `pos` (1-based index) */
bool insert_after(node *head, int pos, int val){
    if (pos > list_size(head)) return false;

    int index = 1; 
    node *cur = head;
    while (index != pos){       // traverse to position
        index++;
        cur = cur->next;
    }
    
    node *p = malloc(sizeof(node));
    if (!p) return false;       // malloc failed
    p->val = val;
    p->next = cur->next;        // insert after cur
    cur->next = p;
    return true;
}

/* Reverse entire linked list */
void reverse_list(node **head){
    if (head == NULL || *head == NULL) return;

    node *prev = NULL;
    node *cur = *head;
    while (cur != NULL){
        node *t = cur->next;    // store next node
        cur->next = prev;       // reverse pointer
        prev = cur;             // move prev forward
        cur = t;                // move cur forward
    }

    *head = prev;               // new head is last non-NULL node
}

/* Return number of nodes in list */
int list_size(node *head){
    int len = 0;
    while (head != NULL) {
        ++len;
        head = head->next;
    }
    return len;
}

/* Free entire linked list */
void free_list(node **head){
    if (head == NULL || *head == NULL)  
        return;

    node *cur = *head;
    while (cur != NULL) {
        node *next = cur->next;
        free(cur);
        cur = next;
    }

    *head = NULL;   // reset to NULL to avoid dangling pointer
}

/* Print list in human-readable form */
void print_list(node *head){
    if (head == NULL) {
        printf("(empty)\n");
        return;
    }
    
    printf("%d", head->val);

    node* cur = head->next;
    while (cur != NULL){
        printf(" -> %d", cur->val);
        cur = cur->next;
    }
    printf("\n");
}
