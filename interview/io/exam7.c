#include <stdio.h>
#include <unistd.h>
int main() {
    FILE* fp = fopen("log.txt", "w");
    fprintf(fp, "Log entry: %d\n", 123);
    fclose(fp);

    while (1) {
        fprintf(stdout, "hello-std-out");
        fprintf(stderr, "hello-std-err");
        sleep(1);
    }

    return 0;
}
