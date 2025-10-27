#include <stdio.h>
int main() {
    int x, y = 5, z = 5;
    x = y == z;      // x = (y == z); x = 1;
    printf("%d", x); // 1

    getchar();
    return 0;
}
