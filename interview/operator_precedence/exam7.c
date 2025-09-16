#include <stdio.h>

int main(void) {
    char* ptr = "Linux";
    printf("%c\n", *ptr++);//(*(ptr++)  L 
    printf("%c\n", *ptr); // i
    return 0;
}
