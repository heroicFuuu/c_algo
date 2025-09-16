#include <stdio.h>
int main() {
    int c = 5;
    printf("%d\n%d\n%d", c, c <<= 2, c >>= 2);
    getchar();
    return 0;
}
/*

https://stackoverflow.com/questions/367633/what-are-all-the-common-undefined-behaviours-that-a-c-programmer-should-know-a
*/