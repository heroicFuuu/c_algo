#include <stdio.h>

#define a 10

int main() {
#ifndef a
#define a 50 // redefine
#endif

    printf("%d", a);

    getchar();
    return 0;
}
