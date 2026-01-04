#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, K;
    if (scanf("%d %d", &N, &K) != 2) return 0;

    int *A = (int*)malloc(sizeof(int)*N);
    int maxA = 0;
    long long total = 0;
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
        if (A[i] > maxA) maxA = A[i];
        total += A[i];
    }
     // 沒辦法組任何隊
    if (K > maxA) {          
        printf("0\n");
        free(A);
        return 0;
    }

    // 建 frequency 與 prefix-count
    int *cnt = (int*)calloc((size_t)maxA + 1, sizeof(int));
    for (int i = 0; i < N; i++) cnt[A[i]]++;

    int *pc = (int*)malloc(sizeof(int)*(maxA + 1)); // prefix count
    pc[0] = cnt[0];
    for (int v = 1; v <= maxA; v++) pc[v] = pc[v-1] + cnt[v];

    long long best = 0;

    // 枚舉隊伍大小 x
    for (int x = K; x <= maxA; x++) {
        long long sum_floor = 0;  // sum_i floor(a_i / x)
        // 以區間 [t*x, (t+1)*x - 1] 分段
        // 對每個 t，這段內的元素都貢獻 t
        for (int L = x, t = 1; L <= maxA; L += x, t++) {
            int R = L + x - 1;
            if (R > maxA) R = maxA;
            // 這段有幾個總數 , 因為 這些數除起來的t都相同
            int c = pc[R] - pc[L-1];  
            if (c > 0) sum_floor += (long long)t * c;
        }
        long long participants = sum_floor * x; // = sum floor(a_i/x) * x
        if (participants > best) best = participants;
    }

    printf("%lld\n", best);

    free(pc);
    free(cnt);
    free(A);
    return 0;
}