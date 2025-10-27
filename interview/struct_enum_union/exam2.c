#include <stdio.h>

int main() {
    struct bitfield {
        signed int a : 3;    // 4 byte
        unsigned int b : 13; // 4 byte
        unsigned int c : 1;  // 4 byte
    };
    struct bitfield bit1 = {2, 14, 1};
    printf("%ld\n", sizeof(bit1));
    printf("%d\n", bit1.a);
    printf("%d\n", bit1.b);
    printf("%d\n", bit1.c);
    printf("\n");
    struct bitfield bit2 = {-2, 1024, 0}; // {-16, 1024, 1}  -16 will overflow
    printf("%ld\n", sizeof(bit1));
    printf("%d\n", bit2.a);
    printf("%d\n", bit2.b);
    printf("%d\n", bit2.c);

    return 0;
}
