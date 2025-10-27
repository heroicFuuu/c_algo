#include <stdio.h>
#include <unistd.h>
int main() {
    unsigned int i = 10;
    while (i-- >= 0) {
        // printf("%u \n",i);
        printf("%u ", i);
        fflush(stdout);
        sleep(1);
    }

    return 0;
}
