#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// data type
typedef struct Pos{
    int row;
    int col;
}Pos;

typedef struct Node{
    Pos pos;
    struct Node* next;
}Node;

typedef struct List
{
    Node* head;
    Node* tail;
    int size;
}Queue, AdjList;

//api
void init(struct List *q) {
    q->head = q->tail = NULL;
    q->size = 0;
}


void push(struct List *q, int r, int c){
    Node* node = malloc(sizeof(Node));
    node->pos.row = r;
    node->pos.col = c;

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

void pop(struct List *q){
    if (q->head == NULL) return;

    Node* node = q->head;
    q->head = q->head->next;
    if (q->head == NULL) q->tail = NULL;
    q->size--;
    free(node);
}

Pos getQueueFrontVal(struct List *q){
    Pos node = {-1, -1};
    if (q->head == NULL) return node;
    return q->head->pos;
}

int getQueueSize(struct List *q) {
    return q->size;
}
int isEmpty(struct List *q) {
    return q->size == 0;
}

int main(){

    int ROW, COL;
    scanf("%d %d", &ROW, &COL);
    
    char maze[ROW][COL];
    bool visited[ROW][COL];

     for (int i = 0; i < ROW; i++)
        for (int j = 0; j < COL; j++)
            visited[i][j] = false;

    AdjList teleport[26];
    for (int i = 0; i < 26; i++) init(&teleport[i]);

    Queue q;
    init(&q);

    Pos end = {-1, -1};
    for (int i = 0 ; i < ROW ; ++i){
        for (int j = 0; j < COL; ++j){
            char ch ;
            scanf(" %c", &ch);


            maze[i][j] = ch;

            int idx = ch - 'A'; 

            if (idx >= 0 && idx < 26 && idx != 1 && idx != 4){
                push(&teleport[idx], i, j); 
            }else if (idx == 1){
                push(&q, i, j);
            }else if (idx == 4){
                end.row = i ;
                end.col = j ;
            }
        }
    }
    bool reach = false;
    int step = 0;
    int lens;
    int dir[] = {1, 0, -1, 0, 1};

    while ((lens = getQueueSize(&q)) != 0) {

        for (int i = 0; i < lens; i++) {

            Pos cur = getQueueFrontVal(&q);

            // 抵達終點
            if (cur.row == end.row && cur.col == end.col) {
                reach = true;
                break;
            }

            char ch = maze[cur.row][cur.col];

            // 傳送門處理
            if (ch >= 'A' && ch <= 'Z') {
                int idx = ch - 'A';
                while (!isEmpty(&teleport[idx])) {
                    Pos tp = getQueueFrontVal(&teleport[idx]);
                    pop(&teleport[idx]);
                    if (!visited[tp.row][tp.col]) {
                        visited[tp.row][tp.col] = true;
                        push(&q, tp.row, tp.col);
                    }
                }
            }

            // 方向移動
            for (int j = 0; j < 4; j++) {

                int nr = cur.row + dir[j];
                int nc = cur.col + dir[j + 1];

                if (nr < 0 || nr >= ROW || nc < 0 || nc >= COL) continue;
                if (maze[nr][nc] == '#') continue;
                if (visited[nr][nc]) continue;

                visited[nr][nc] = true;
                push(&q, nr, nc);
            }

            pop(&q); 
        }

        if (reach) {
            printf("%d\n", step);
            return 0;
        }

        step++;
    }

    printf("-1\n");
    return 0;
}