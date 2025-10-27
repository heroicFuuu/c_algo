#include <stdio.h>

void fun(int* p) {
    static int q = 10;
    p = &q;
}

void fun2(int** p) {
    static int r = 25;
    *p = &r;
}

int main() {
    int r = 20;
    int* p = &r;
    fun(p);
    printf("%d ", *p); // 不會變因為call by value
    fun2(&p);
    printf("%d ", *p); // correct

    getchar();
    return 0;
}
