#include <stdio.h>
int main() {
    int x, a = 0;
    x = sizeof(a++) ? printf("Geeks for Geeks\n") : 0; // print
    printf("Value of x:%d\n", x);                      // x = printf() 包含\0字元數
    printf("Value of a:%d",
           a); // 0, because sizeof will decide in compile time a++ wont execute in runtime
    return 0;
}
