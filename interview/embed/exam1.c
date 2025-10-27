#include <stdint.h>
#include <stdio.h>

void write_register(uint64_t* x, unsigned int loc, unsigned char en) {
    if (loc >= 64) { // 超出範圍，直接 return
        printf("bit location out of range\n");
        return;
    }

    if (en == '0') {
        *x &= ~(1ULL << loc); // clear
    } else if (en == '1') {
        *x |= (1ULL << loc); // set
    } else if (en == '2') {
        *x ^= (1ULL << loc); // inverse
    } else {
        printf("input error\n");
    }
}

int main() {
    uint64_t reg = 0;

    write_register(&reg, 3, '1'); // 設定 bit3
    printf("%016lX\n", reg);      // 0000000000000008

    write_register(&reg, 65, '1'); // 超出範圍
    // 輸出: bit location out of range
}
