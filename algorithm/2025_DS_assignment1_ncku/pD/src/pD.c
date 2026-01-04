#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct Text{
    int num;
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
//choose a insert_pos, insert after it. modified the new_pos info
void insert_text(Text *insert_pos, Text **new_pos, int num){
    
    Text *text = malloc(sizeof(*text));
    text->num = num;
    text->prev = insert_pos;
    text->next = insert_pos->next;

    insert_pos->next->prev = text;
    insert_pos->next = text;

    *new_pos = text;
}


/* api */
void insert_head(Text *head, Text **pos, int num){
    insert_text(head, pos, num);
}

void insert_tail(Text *head, Text **pos, int num){
    insert_text(head->prev, pos, num);   
}
 
void insert_k_pos_A(Text *insert_pos, Text **pos, int num){
    insert_text(insert_pos, pos, num);
}

void insert_k_pos_B(Text *insert_pos, Text **pos, int num){
    insert_text(insert_pos->prev, pos, num);
}

void move_to_head(Text *head, Text **pos){
    Text* move_node = *pos;
    move_node->prev->next = move_node->next;
    move_node->next->prev = move_node->prev;
    
    move_node->next = head->next;
    move_node->prev = head;

    head->next->prev = move_node;
    head->next = move_node;
}   

void move_to_tail(Text *head, Text **pos){
    Text* move_node = *pos;
    move_node->prev->next = move_node->next;
    move_node->next->prev = move_node->prev;
    
    move_node->next = head;
    move_node->prev = head->prev;

    head->prev->next = move_node;
    head->prev = move_node;
}

// delete 
void delete_text(Text *head, Text ** pos){

    if (*pos == head) return;

    (*pos)->prev->next = (*pos)->next;
    (*pos)->next->prev = (*pos)->prev;
    free(*pos);

    *pos = NULL;
}

/// 輸出鏈結串列的字元
void print_text(Text *head) {
    if (head->next == head) {   // 空的
        printf("EMPTY\n");
        return;
    }
    bool space = false;
    for (Text *p = head->next; p != head; p = p->next) {
        if (space) printf(" ");
        printf("%d", p->num);
        space = true;
    }
    printf("\n");
}

void print_text_reverse(Text *head) {
    if (head->prev == head) {   // 空的
        printf("EMPTY\n");
        return;
    }
    bool space = false;
    for (Text *p = head->prev; p != head; p = p->prev) {
        if (space) printf(" ");
        printf("%d", p->num);
        space = true;
    }
    printf("\n");
}

int main(){
    int N, Q;
    scanf("%d %d", &N, &Q);

    Text *head = head_new();
    Text **Map = malloc((N+Q+5) * sizeof(Text*));

    for (int i = 0; i < N+Q+5; i++) Map[i] = NULL;

    Text *cur = head;
    for (int i = 1; i <= N; i++) {
        int val;
        scanf("%d", &val);
        insert_text(cur, &Map[i], val);
        cur = Map[i];
    }

    int next_id = N + 1;

    for (int i = 0; i < Q; i++) {
        char op[5];
        scanf("%s", op);

        if (strcmp(op, "H") == 0) {
            int x;
            scanf("%d", &x);
            insert_text(head, &Map[next_id], x);
            next_id++;
        }
        else if (strcmp(op, "T") == 0) {
            int x;
            scanf("%d", &x);
            insert_text(head->prev, &Map[next_id], x);
            next_id++;
        }
        else if (strcmp(op, "A") == 0) {
            int k, x;
            scanf("%d %d", &k, &x);
            insert_text(Map[k], &Map[next_id], x);
            next_id++;
        }
        else if (strcmp(op, "B") == 0) {
            int k, x;
            scanf("%d %d", &k, &x);
            insert_text(Map[k]->prev, &Map[next_id], x);
            next_id++;
        }
        else if (strcmp(op, "D") == 0) {
            int k;
            scanf("%d", &k);
            if (Map[k] != NULL) {
                delete_text(head, &Map[k]);
            }
        }
        else if (strcmp(op, "MH") == 0) {
            int k;
            scanf("%d", &k);
            move_to_head(head, &Map[k]);
        }
        else if (strcmp(op, "MT") == 0) {
            int k;
            scanf("%d", &k);
            move_to_tail(head, &Map[k]);
        }
    }

    print_text(head);
    print_text_reverse(head);

    return 0;
}
