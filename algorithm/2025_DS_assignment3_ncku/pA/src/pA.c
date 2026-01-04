#include <stdio.h>
#include <stdlib.h>

// Union-Find 結構
int *parent;
int numsIsland;

typedef struct {
    int u;
    int v;
} Edge;

int FindParent(int x) {
    if (parent[x] != x)
        parent[x] = FindParent(parent[x]);
    return parent[x];
}

void Union(int a, int b) {
    int pa = FindParent(a);
    int pb = FindParent(b);
    if (pa == pb) return;
    parent[pb] = pa;
    numsIsland--;
}

int main() {
    int n, m, q;
    scanf("%d %d %d", &n, &m, &q);

    parent = (int*)malloc((n + 1) * sizeof(int));
    for (int i = 1; i <= n; i++) parent[i] = i;

    numsIsland = n;

    // edges 存所有邊的指標
    Edge** edges = (Edge**)malloc(sizeof(Edge*) * m);
    for (int i = 0; i < m; i++) {
        edges[i] = (Edge*)malloc(sizeof(Edge));
        scanf("%d %d", &edges[i]->u, &edges[i]->v);
    }

    // delete 存被移走的邊
    Edge** del = (Edge**)malloc(sizeof(Edge*) * q);
    for (int i = 0; i < q; i++) {
        int idx;
        scanf("%d", &idx);
        idx--;                  
        del[i] = edges[idx];    // 將邊移到 delete 裡
        edges[idx] = NULL;
    }

    // 建立初始圖（沒有刪除的邊）
    for (int i = 0; i < m; i++) {
        if (edges[i] != NULL) {
            Union(edges[i]->u, edges[i]->v);
        }
    }

    // 紀錄答案（反向加入被刪邊）
    int* ans = (int*)malloc(sizeof(int) * (q + 1));
    ans[0] = numsIsland;
    for (int i = q - 1; i >= 0; i--) {
        Union(del[i]->u, del[i]->v);
        ans[q - i] = numsIsland;
    }

    // 輸出
    for (int i = q; i >= 0; --i) {
        printf("%d\n", ans[i]);
    }

    return 0;
}
