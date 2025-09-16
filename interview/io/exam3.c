#include <stdio.h>
#include <string.h>
int main(void) {
    char buff[100];
    memset(buff, 0, sizeof(buff));//init
    // gets(buff);
    fgets(buff, 10, stdin);
    printf("\n The buffer entered is [%s]\n", buff);
    return 0;
}
