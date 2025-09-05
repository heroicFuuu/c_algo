#include <stdlib.h>
#include <stdbool.h>

// 定義節點
typedef struct Node {
    int val;
    struct Node* prev;
    struct Node* next;
} Node;

// 定義循環佇列
typedef struct {
    int capacity;   // 最大容量
    int count;      // 當前元素數
    Node* head;     // 哨兵節點 (dummy head)
} MyCircularQueue;

// 建立循環佇列
MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue* obj = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    obj->capacity = k;
    obj->count = 0;

    // 建立哨兵節點，prev/next 都指向自己
    obj->head = (Node*)malloc(sizeof(Node));
    obj->head->val = 0; // dummy 值，不會用到
    obj->head->next = obj->head;
    obj->head->prev = obj->head;

    return obj;
}

// 入隊 (插到尾巴，即 head->prev 之前)
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if (obj->count == obj->capacity) return false;

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = value;

    Node* tail = obj->head->prev;

    newNode->next = obj->head;
    newNode->prev = tail;
    tail->next = newNode;
    obj->head->prev = newNode;

    obj->count++;
    return true;
}

// 出隊 (刪除 head->next，即隊首)
bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if (obj->count == 0) return false;

    Node* front = obj->head->next;
    obj->head->next = front->next;
    front->next->prev = obj->head;

    free(front);
    obj->count--;
    return true;
}

// 取隊首
int myCircularQueueFront(MyCircularQueue* obj) {
    if (obj->count == 0) return -1;
    return obj->head->next->val;
}

// 取隊尾
int myCircularQueueRear(MyCircularQueue* obj) {
    if (obj->count == 0) return -1;
    return obj->head->prev->val;
}

// 判斷是否為空
bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    return obj->count == 0;
}

// 判斷是否已滿
bool myCircularQueueIsFull(MyCircularQueue* obj) {
    return obj->count == obj->capacity;
}

// 釋放記憶體
void myCircularQueueFree(MyCircularQueue* obj) {
    Node* cur = obj->head->next;
    while (cur != obj->head) {
        Node* tmp = cur;
        cur = cur->next;
        free(tmp);
    }
    free(obj->head);
    free(obj);
}