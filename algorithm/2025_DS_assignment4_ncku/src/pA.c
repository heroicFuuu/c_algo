#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>
#define BUCKET 103
// node
typedef struct Node{
    int key;
    int degree;
    struct Node *left; 
    struct Node *right;
    struct Node *parent;
    struct Node *child;
    bool mark;  
}Node;

void init_node(Node* node, int key){
    node->key = key;
    node->degree = 0;
    node->left = node;
    node->right = node;
    node->parent = NULL;
    node->child = NULL;
    node->mark = false;
}

// heap
typedef struct Fheap {
  int size;
  Node *min;
  int degree;
} Fheap;

void init_heap(Fheap **heap){
    if (*heap != NULL) return ; 
    *heap = (Fheap*) malloc(sizeof(Fheap));
    (*heap)->size = 0;
    (*heap)->min = NULL;
    (*heap)->degree = 0;
    return ;
};
// insert node with new key
Node* insert_new(Fheap *heap, int key){
    Node* insert = (Node*) malloc(sizeof(Node));
    init_node(insert, key);
    
    if (heap->min == NULL){
        heap->min = insert;
    }else{

        insert->right = heap->min->right;
        insert->left = heap->min;

        heap->min->right->left = insert;
        heap->min->right = insert;

        if (insert->key < heap->min->key)heap->min = insert;
        
    }
    heap->size ++;
    return insert;
}
// insert node already exist
void insert(Fheap *heap, Node* node){
    node->parent = NULL;
    node->mark = false;
    
    if (heap->min == NULL){
        node->left = node;
        node->right = node;
        heap->min = node;
        return ;
    }

    node->right = heap->min->right;
    node->left = heap->min;
    
    heap->min->right->left = node;
    heap->min->right = node;

    if (node->key < heap->min->key) heap->min = node;
}
void pop_node(Node* node){
    Node* parent = node->parent;

    if (parent != NULL){

        if (parent->child == node && node->right != node){
            Node* cur = node->right;
            parent->child = cur;
            for ( ; cur != node; cur = cur->right){
                if (cur->key < parent->child->key) parent->child = cur;
            }

        }else if (parent->child == node){
            parent->child = NULL;
        }
        parent->degree --;
        node->parent = NULL;
    }

   
    if (node->right == node) return ;

    node->left->right = node->right;
    node->right->left = node->left;

    node->left = node;
    node->right = node;

    node->mark = false;
}

int cal_degree(int n) {
  int count = 0;
  while (n > 0) {
    n = n / 2;
    count++;
  }
  return count;
}

Node* merge(Fheap* heap, Node* a, Node* b){
    if (a->key > b->key){
        Node* temp = b;
        b = a;
        a = temp; // a should be smaller
    }

    pop_node(b);
    b->parent = a;
    b->mark = false;

    if (a->child == NULL){
        a->child = b;
        b->left = b;
        b->right = b;
    } else {
        b->right = a->child->right;
        b->left  = a->child;
        a->child->right->left = b;
        a->child->right = b;
        if (b->key < a->child->key)
            a->child = b;
    }
    a->degree++;
    return a;
}

void consolidate(Fheap* heap){
    if (heap->min == NULL) return ;
    if (heap->min->right == heap->min) return ;

    int lens = cal_degree(heap->size) + 2;
    
    Node** helper_arr = (Node**) malloc(sizeof(Node*) * lens);
    for (int i = 0 ; i < lens ; i++) helper_arr[i] = NULL;

    Node *cur, *start, *exist;
    int degree;

    cur = heap->min;
    start = heap->min;

    do {
        Node* next = cur->right;

        degree = cur->degree;

        while (helper_arr[degree] != NULL){
            exist = helper_arr[degree];
            helper_arr[degree] = NULL;

            cur = merge(heap, exist , cur);
            degree = cur->degree;
        }
        helper_arr[degree] = cur;
        cur = next;
    }while (cur != start);

    heap->min = NULL;
    for (int i = 0; i < lens; i++){
        if (helper_arr[i] != NULL){
            pop_node(helper_arr[i]);
            insert(heap, helper_arr[i]);
        }
    }

    free(helper_arr);
}

Node* extract_min(Fheap *heap){
    if (heap->min == NULL) return NULL;

    Node* min_node = heap->min;

    // find heap new min;
    if ( min_node->right != min_node) {
        heap->min = min_node->right;
        Node* next = heap->min ;    
        for ( ; next != min_node ; next = next->right){
            if (next->key < heap->min->key){
                heap->min = next;
            }
        }
    }else {
        heap->min = NULL;
    }

    pop_node(min_node);
    Node* child = min_node->child;

    if (child != NULL) {
        Node* next = child->right;
        int nums_child = min_node->degree;
        for (int i = 0; i < nums_child ; i++){
            pop_node(child);
            insert(heap, child);
            
            child = next;
            next = next->right;
        }
        min_node->child = NULL; 
        min_node->degree = 0;
    }
   
    consolidate(heap);

    heap->size --;
    return min_node; 
}
void cut(Fheap* heap, Node* node, Node* parent){
    pop_node(node);
    insert(heap, node);
}
void cascading_cut(Fheap* heap, Node* node){
    Node* parent = node->parent;
    if (parent == NULL ) return ;
    
    if (node->mark == false) {
        node->mark = true;
    }else{
        cut(heap, node, parent);
        cascading_cut(heap, parent);
    }
}

void decrease(Fheap* heap, Node* node, int new_key){

    Node *parent = node->parent;
    node->key = new_key;

    if (node == heap->min) return ;

    if (parent != NULL && node->key < parent->key){
        cut(heap, node, parent);
        cascading_cut(heap, parent);
    }
    if (node->key < heap->min->key)
        heap->min = node;
        
    return ;
}

// hashmap
typedef struct Data {
    int key;
    Node* ptr;//Node type for fheap;
} Data;

typedef struct MapNode{
    Data* data;
    struct MapNode* next;
}m_Node;

typedef struct Queue{
    m_Node* head;
    m_Node* tail;
}Queue;

static Queue* q[BUCKET];
static bool isInit = false ;
void push(Queue *q, Data* data){
    m_Node* m_node = malloc(sizeof(m_Node));
    m_node->data = data;
    m_node->next = NULL;
    if (q->head == NULL){
        q->head = m_node;
        q->tail = m_node;
        return ;
    }
    q->tail->next = m_node;
    q->tail = m_node;
}


void erase(Queue *q, int key){

    if (q->head == NULL) return;
    
    m_Node* prev = NULL;
    m_Node* curr = q->head;
    
    while (curr && curr->data->key != key){
        prev = curr;
        curr = curr->next;
    };
    if (curr == NULL) return; 

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

Node* find(Queue *q, int key){
    if (q->head == NULL) return NULL;

    m_Node* node = q->head;
    while (node != NULL && node->data->key != key){
        node = node->next;
    };

    return node ? node->data->ptr : NULL;
}

void init(Queue *q) {
    q->head = q->tail = NULL;
}

void insert_key(Data *data){
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
void remove_key(int key){
    if (!isInit) return;
    int bucket = key%BUCKET;
    erase(q[bucket], key);
};
Node* search_key(int key){
    int bucket = key%BUCKET;
    return find(q[bucket], key);
};



void bubble_sort(Node** arr, int len) {
    Node* tmp;
    bool swapped;

    for (int i = 0; i < len - 1; i++) {
        swapped = false;
        for (int j = 0; j < len - 1 - i; j++) { // 相鄰比較
            if (arr[j]->degree > arr[j + 1]->degree ||
               (arr[j]->degree == arr[j + 1]->degree && arr[j]->key > arr[j + 1]->key)) {
                tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
                swapped = true;
            }
        }
        if (!swapped)
            break; // 如果某一輪沒有交換，提前結束
    }
}

#define LENS 128

void clear_arr(Node** arr, int size){
    for (int i = 0; i < size; i++)arr[i] = NULL;
}

void print_tree(Node* node){
    Node** cur;
    Node** next;
    cur = (Node**) malloc(sizeof(Node*) * LENS);
    next = (Node**) malloc(sizeof(Node*) * LENS);
    
    cur[0] = node;
    int cur_level_nodes = 1;
    int next_level_nodes = 0;
    bool space = false;
    while(cur_level_nodes != 0){

        for (int i = 0; i < cur_level_nodes; i++){
            Node* start = cur[i]->child;
            if (start == NULL) continue;
            do{
                next[next_level_nodes++] = start; 
                start = start->right;
            }while(start != cur[i]->child);
            
        }
        
        bubble_sort(cur, cur_level_nodes);
        for (int i = 0; i < cur_level_nodes; i++){
            if (space) printf(" ");
            
            printf("%d", cur[i]->key);
            space = true;
            
        }

        for (int i = 0; i < next_level_nodes; i++){
            cur[i] = next[i];
        }
        cur_level_nodes = next_level_nodes;
        clear_arr(next, LENS);
        next_level_nodes = 0;
       
        
    }

    free(cur);
    free(next);

}

//print  
void print_heap(Fheap **heap){
    Node* cur = (*heap)->min;
    Node* helper_arr[LENS] ;
    clear_arr(helper_arr, LENS);
    int root_list_nums = 0;
    if (cur != NULL){
        do{
            helper_arr[root_list_nums++] = cur;
            cur = cur->right;
        }while(cur != (*heap)->min);
    }
    bubble_sort(helper_arr, root_list_nums);
    for (int i = 0 ; i < root_list_nums; i++){
        print_tree(helper_arr[i]);
        if (i != root_list_nums - 1) printf("\n");
    }
    printf("\n");
    return ;
}

int main(){
    //build fheap
    Fheap* heap = NULL;
    init_heap(&heap);

    //build hashmap
    char operation[20];
    
    while (scanf("%s", operation)){


        if (strcmp(operation, "insert") == 0){
            int key;
            scanf("%d", &key);
            Node* node = insert_new(heap, key);
            Data* data = malloc(sizeof(Data));
            data->key = key;
            data->ptr = node;
            insert_key(data);
        }else if (strcmp(operation, "extract-min") == 0){
            Node* min_node = extract_min(heap);
            remove_key(min_node->key);
            free(min_node);
        }else if (strcmp(operation, "decrease") == 0){
            
            int key, dec,newkey;
            scanf("%d %d", &key, &dec);
            newkey = key - dec;
            Node* target = search_key(key);
            //fheap;
            decrease(heap, target, newkey);
            //map
            remove_key(key);
            Data* data = malloc(sizeof(Data));
            data->key = newkey;
            data->ptr = target;
            insert_key(data);
        }else if (strcmp(operation, "delete") == 0){
            // decrease + extract
            int key;
            scanf("%d", &key);
            Node* target = search_key(key);
            decrease(heap, target, INT_MIN);
            Node* removed = extract_min(heap);
            remove_key(key);
            free(removed);

        }else if (strcmp(operation, "exit") == 0 ){
            print_heap(&heap);
            #ifdef DEBUG
            while (heap->size > 0){
                Node* node = extract_min(heap);
                printf("%d ", node->key);
            }
            #endif
            break;
        }else{
            break;
        }
    }

    
    return 0;
}