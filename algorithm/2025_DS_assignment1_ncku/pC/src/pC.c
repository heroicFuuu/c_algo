#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct Text{
    char ch;
    struct Text *prev;
    struct Text *next;
}Text;

void Init(Text* head){
    head->next = head;
    head->prev = head;
}

Text *head_new(){
    Text *head = malloc(sizeof(*head));
    if (!head) return NULL;
    Init(head);
    return head;
}

void insert_text(Text *head, Text **cur, char ch){
    
    Text *text = malloc(sizeof(*text));
    text->ch = ch;
    text->prev = *cur;
    text->next = (*cur)->next;

    (*cur)->next->prev = text;
    (*cur)->next = text;

    *cur = text;
}
// 1 for right -1 for left;
void move_cursor(Text *head, Text **cur, int dir){
    
    if (dir>0 && (*cur)->next != head){
        *cur = (*cur)->next;
    }else if(dir < 0 && (*cur) != head){
        *cur = (*cur)->prev;
    }    
}

// delete 
void delete_text(Text *head, Text ** cur){

    if (*cur == head) return;
    Text *new_position = (*cur)->prev;

    (*cur)->prev->next = (*cur)->next;
    (*cur)->next->prev = (*cur)->prev;
    free(*cur);

    *cur = new_position;

}
/// 輸出鏈結串列的字元
void print_text(Text *head) {
    for (Text *p = head->next; p != head; p = p->next) {
        printf("%c",p->ch);
    }
    printf("\n");
}

int main() {
    char init_str[300]; // 初始字串
    if (!fgets(init_str, sizeof(init_str), stdin)) return 1;

    // 去掉換行符
    size_t len = strlen(init_str);
    if (len > 0 && init_str[len-1] == '\n') {
        init_str[len-1] = '\0';
    }

    Text *head = head_new();
    Text *cur = head;

    // 插入初始字串
    for (int i = 0; init_str[i]; i++) {
        insert_text(head, &cur, init_str[i]);
    }

    int M;
    scanf("%d", &M);

    for (int i = 0; i < M; i++) {
        char op[10];
        scanf("%s", op);

        if (op[0] == 'L') {
            move_cursor(head, &cur, -1);
        } else if (op[0] == 'R') {
            move_cursor(head, &cur, 1);
        } else if (op[0] == 'I') {
            char ch;
            scanf(" %c", &ch);
            insert_text(head, &cur, ch);
        } else if (op[0] == 'D') {
            delete_text(head, &cur);
        }
    }

    print_text(head);

    return 0;
}