#ifndef SLIST_H
#define SLIST_H

#include <stdbool.h>

typedef struct Node {
    int val;
    struct Node* next;
} node;

void push_head(node** head, int val);            /* 頭插 */
void append_tail(node** head, int val);          /* 尾插 */
bool delete_value(node** head, int val);         /* 刪除指定值 */
bool insert_after(node* head, int pos, int val); /* 指定位置後插 */
void reverse_list(node** head);                  /* 反轉 */
int list_size(node* head);                       /* 計算長度 */
void free_list(node** head);                     /* 釋放 */
void print_list(node* head);                     /* 印出 */

#endif /* SLIST_H */
