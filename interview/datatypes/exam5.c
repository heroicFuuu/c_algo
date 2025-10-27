#include <stdio.h>
int main() {
    unsigned int a = -1;
    unsigned int b = 4;
    printf("%d\n", a << b); //位元shift // 11111111 11111111 11111111 11110000
    return 0;
}

//正轉負 (~p + 1)
//求負是多少 -1 * (~(n - 1))
