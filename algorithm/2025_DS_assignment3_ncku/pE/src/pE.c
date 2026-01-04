#include "hash.h"
#include <stdlib.h>
#include <stdbool.h>
#define BUCKET 4099
typedef struct Node{
    Data* data;
    struct Node* next;
}Node;

typedef struct Queue
{
    Node* head;
    Node* tail;
}Queue;

Queue* q[BUCKET];
bool isInit = false ;

void push(Queue *q, Data* data){
    Node* node = malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    if (q->head == NULL){
        q->head = node;
        q->tail = node;
        return ;
    }
    q->tail->next = node;
    q->tail = node;
}


void erase(Queue *q, int key){

    if (q->head == NULL) return;
    
    Node* prev = NULL;
    Node* curr = q->head;
    
    while (curr && curr->data->key != key){
        prev = curr;
        curr = curr->next;
    };

    if (prev == NULL) {           
        q->head = curr->next;
        if (curr == q->tail) q->tail = NULL;
    } else {
        prev->next = curr->next;
        if (curr == q->tail) q->tail = prev;
    }

    free(curr->data);
    free(curr);
}

int find(Queue *q, int key){
    if (q->head == NULL) return -1;

    Node* node = q->head;
    node->data->key;
    while (node != NULL && node->data->key != key){
        node = node->next;
    };

    return node ? node->data->value : -1;
}

void init(Queue *q) {
    q->head = q->tail = NULL;
}

void insert(Data *data){
    if (!isInit){
        for (int i = 0; i < BUCKET; i++ ){
            q[i] = malloc(sizeof(Queue));
            init(q[i]);   
        };
        isInit = true;
    }

    int bucket = data->key%BUCKET;
    push(q[bucket], data);    
};

// api名稱不可以跟<stdio.h> 有命名衝突
// extern int remove (const char *__filename) __THROW;
// https://stackoverflow.com/questions/63355549/redefine-function-in-c
void removekey(int key){
    if (!isInit) return;
    int bucket = key%BUCKET;
    erase(q[bucket], key);
};

int search(int key){
    int bucket = key%BUCKET;
    return find(q[bucket], key);
};