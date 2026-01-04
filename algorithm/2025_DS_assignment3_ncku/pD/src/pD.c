#include "mst.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define INIT_CAPACITY 32

typedef struct minHeap{
    Edge **edges;
    int capacity;
    int size;
}minHeap;

static inline void swap(Edge **a, Edge **b) {
    Edge *t = *a;
    *a = *b;
    *b = t;
}

void init_heap(minHeap *heap){
    heap->edges = (Edge **)malloc(sizeof(Edge*) * (INIT_CAPACITY + 1));
    heap->size = 0;
    heap->capacity = INIT_CAPACITY;
}

bool compare(Edge* a, Edge* b){
    return a->w < b->w;
}

void ensure_capacity(minHeap *h) {
    if (h->size >= h->capacity) {
        h->capacity *= 2;
        h->edges = realloc(h->edges, sizeof(Edge*) * (h->capacity + 1));
    }
}

void heapify(minHeap *h, int i) {
    int minIndex = i;
    int left = i * 2;
    int right = i * 2 + 1;

    if (left <= h->size && compare(h->edges[left], h->edges[minIndex]))
        minIndex = left;
    if (right <= h->size && compare(h->edges[right], h->edges[minIndex]))
        minIndex = right;

    if (minIndex != i) {
        swap(&h->edges[i], &h->edges[minIndex]);
        heapify(h, minIndex);
    }
}

void push(minHeap *h, Edge* e) {
    ensure_capacity(h);
    h->edges[++h->size] = e;

    int i = h->size;
    while (i > 1 && compare(h->edges[i], h->edges[i/2]) ) {
        swap(&h->edges[i], &h->edges[i/2]);
        i /= 2;
    }
}

Edge* pop(minHeap *h) {
    if (h->size == 0) {
        fprintf(stderr, "Heap underflow!\n");
        exit(1);
    }
    Edge* min_value = h->edges[1];
    h->edges[1] = h->edges[h->size--];
    if (h->size) heapify(h, 1);
    return min_value;
}

bool isEmpty(minHeap* heap){
    return (heap->size == 0);
}

void free_heap(minHeap *h) {
    free(h->edges);
    h->edges = NULL;
}

// minheap
void generate_mst(Node *node) {
    
    bool* visited = (bool*) malloc(sizeof(bool) * MAX_NODES);
    memset(visited, false, sizeof(bool)* MAX_NODES);

    visited[node->id] = true;

    minHeap heap;
    init_heap(&heap);
    
    for (int i = 0; i < node->edge_count; i++){
        node->edges[i]->keep = -1;
        push(&heap, node->edges[i]);
    }

    //int edgeCnt = 0; /*check push time O(e)*/
    while (!isEmpty(&heap)){
        Edge* edge = pop(&heap);
        
        //edgeCnt++;
        if (edge->keep == 1) continue;

        Node* u = edge->u;
        Node* v = edge->v;

        //if both end alrerady visited, drop
        if (visited[u->id] && visited[v->id]){
            edge->keep = 0;
            continue;
        }

        edge->keep = 1;

        bool u_in = visited[u->id];
        bool v_in = visited[v->id];

        if (u_in ^ v_in) {
            // 把其 neighbor 推入 heap
            if (!u_in && v_in) {
                visited[u->id] = true;
                for (int i = 0; i < u->edge_count; i++) {
                    Edge *e2 = u->edges[i];
                    if (e2->keep == 0) {
                        e2->keep = -1;
                        push(&heap, e2);
                    }
                }
            } else if (!v_in && u_in) {
                visited[v->id] = true;
                for (int i = 0; i < v->edge_count; i++) {
                    Edge *e2 = v->edges[i];
                    if (e2->keep == 0){
                        e2->keep = -1;// avoid re-push into heap
                        push(&heap, e2);
                    } 
                }
            }
        }
    }
    //printf("%d\n", edgeCnt);
    free_heap(&heap);
    free(visited);
    return ;

};