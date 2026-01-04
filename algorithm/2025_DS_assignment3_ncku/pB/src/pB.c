#include <stdio.h>
#include <stdlib.h>
//topological sort
typedef struct Node{
    int val;
    struct Node* next;
}Node;

typedef struct Queue
{
    Node* head;
    Node* tail;
    int size;
    
}Queue;

//
void push(Queue *q, int val){
    Node* node = malloc(sizeof(Node));
    node->val = val;
    node->next = NULL;
    if (q->head == NULL){
        q->head = node;
        q->tail = node;
        q->size ++;
        return ;
    }

    q->tail->next = node;
    q->tail = node;
    q->size ++; 
}

void pop(Queue *q){
    if (q->head == NULL) return;

    Node* node = q->head;
    q->head = q->head->next;
    if (q->head == NULL) q->tail = NULL;
    q->size--;
    free(node);
}

int getQueueFrontVal(Queue *q){
    if (q->head == NULL) return -1;
    return q->head->val;
} 
int getQueueSize(Queue *q) {
    return q->size;
}

int *inDegree;
Queue* next;

int main(){

    int n, d;
    scanf("%d %d", &n, &d);
    inDegree = (int*) malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) inDegree[i] = 0;

    next = (Queue*)malloc(sizeof(Queue) * n);
    for (int i = 0; i < n; i++) {
        next[i].head = NULL;
        next[i].tail = NULL;
        next[i].size = 0;
    }

    for (int i = 0; i < d ; i++){
        int u, v;
        scanf("%d %d", &u, &v);
        inDegree[v] ++;
        push(&next[u], v);
    }

    int left = n;
    
    Queue* q = malloc(sizeof(Queue));
    q->head = q->tail = NULL;
    q->size = 0;

    for (int i = 0; i < n; i++){
        if (inDegree[i] == 0){
            push(q, i);
            left --;
        }
    }

    while((getQueueSize(q)) != 0){
    
        int front = getQueueFrontVal(q);
        pop(q);

        for (Node* nei = next[front].head; nei != NULL ;nei = nei->next){
            int neiVal =nei->val;
            inDegree[neiVal] --;
            if (inDegree[neiVal] == 0){
                push(q, neiVal);
                left --;
            }
        }
    
    };

    printf("%d\n", left == 0 ? 0 : 1);
    return 0;

}