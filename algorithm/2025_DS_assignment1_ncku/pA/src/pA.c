#include <stdio.h>


typedef struct {
    int pos;
    int val;
}Node;


int main() {
    int N;
    if (scanf("%d", &N) != 1) {
        fprintf(stderr, "Failed to read N\n");
        return 1;
    }

    int A[N];  
    for (int i = 0; i < N; i++) {
        if (scanf("%d", &A[i]) != 1) {
            fprintf(stderr, "Failed to read A[%d]\n", i);
            return 1;
        }
    }

    int ret[N];
    for (int i = 0; i < N ; i++) ret[i] = -1;

    int stk_ptr = -1;
    Node stack[N];

    for (int i = N-1; i >= 0; --i){
        
        int cur_val = A[i];
        Node node = {i, cur_val};

        while (stk_ptr != -1 && stack[stk_ptr].val > cur_val){    
            ret[stack[stk_ptr].pos] = stack[stk_ptr].pos - i;
            --stk_ptr;
        }
        
        stack[++stk_ptr] = node;
    }

    for (int i = 0 ; i < N ; ++i){
        if (i > 0) printf(" ");
        printf("%d", ret[i]);
    }

    printf("\n");

    int has = 0, first = 1;
    for (int i = 0; i < N; i++) {
        if (ret[i] != -1) {
            if (!first) printf(" ");
            printf("%d", ret[i]);
            first = 0;
            has = 1;
        }
    }
    if (!has) printf("EMPTY");
    printf("\n");


    return 0;
}
