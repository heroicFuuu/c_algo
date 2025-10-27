#include <stdbool.h>
#include <stdio.h>

void prime(int n) {

    bool nums[n + 1];

    for (int i = 0; i <= n; i++) {
        nums[i] = true; // 全部先標成可能是質數
    }

    nums[0] = false;
    nums[1] = false; // 0 和 1 不是質數

    for (int i = 2; i * i <= n; i++) {
        if (!nums[i])
            continue;

        for (int cur = i * i; cur <= n; cur += i) {
            nums[cur] = false; // 標記 i 的倍數
        }
    }

    printf("Primes up to %d:\n", n);
    int cnt = 0;
    for (int i = 2; i <= n; i++) {
        if (nums[i]) {
            printf("%d ", i);
            ++cnt;
        }
    }
    printf("\nprime conuts : %d\n", cnt);
}

int main() {
    prime(10); // 預期輸出: 2 3 5 7
    prime(30); // 預期輸出: 2 3 5 7 11 13 17 19 23 29
    prime(50); // 預期輸出: 2 3 5 7 11 13 17 19 23 29 31 37 41 43 47
    prime(100000);
    return 0;
}
