#include <stdio.h>

int main() {
    char arr[] = "geeksforgeeks";
    char* ptr = arr; // ptr = a[0];

    while (*ptr != '\0') // if a[i] != \0
        ++*ptr++; // Postfix increment > Prefix increment, (ptr++)然後會複製一份的指標 ++(*ptr) 對於
                  // 舊的指標內字元 +1
    printf("%s %s", arr, --ptr);

    getchar();
    return 0;
}
/*
https://www.geeksforgeeks.org/c/operator-precedence-and-associativity-in-c/
*/