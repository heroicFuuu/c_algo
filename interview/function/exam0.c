#include <stdio.h>

int func(int a, int b) {
    return a + b;
}

int main() {

    printf("%p\n", main);       // Address of function main.
    printf("%d\n", func(5, 6)); // Address of function main.

    int (*ptr)(int a, int b) = func;
    printf("%p\n", ptr);
    printf("%d\n", ptr(3, 4));

    getchar();
    return 0;
}
