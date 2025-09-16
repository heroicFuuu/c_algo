#include <stdio.h>
#include <stdlib.h>
int main() {
    char* ptr;
    if ((ptr = (char*) malloc(0)) ==
        NULL) // 雖然是 0 但是malloc不會回傳null，雖然不能訪問但是也不一定是null
        puts("Got a null pointer");
    else
        puts("Got a valid pointer");

    return 0;
}
/*
https://stackoverflow.com/questions/2022335/whats-the-point-of-malloc0
*/
