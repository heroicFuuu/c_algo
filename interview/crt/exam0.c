#include <stdio.h>
#include <stdlib.h> // atexit
#include <unistd.h> // _exit
void func(void) {
    printf("\n Cleanup function called \n");
    return;
}
int main(void) {
    int i = 0;
    atexit(func);
    for (; i < 0xffffff; i++)
        ;
    // _exit(0);
    return 0;
}
/*C Runtime Library*/