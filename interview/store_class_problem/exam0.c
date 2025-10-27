#include <stdio.h>

char* getString() {
    /* the literal string is copied in the read-only section of memory (any attempt to modify it is
     * an undefined behavior) */
    char* str = "Nice test for strings"; // Pass

    /* the literal string is copied into a local array which is destroyed after that array goes out
     * of scope */
    // char str[] = "Will I be printed?"; // Compile Error
    return str;
}

int main() {
    printf("%s", getString());
    getchar();
}