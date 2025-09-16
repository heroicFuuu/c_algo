int is_pow_2(unsigned int x)
{
    return x != 0 && (x & -x) == x;
}

int number_of_one(unsigned int x)
{
    int c = 0;

    while (x != 0) {
        x = x & (x - 1);
        c++;
    }

    return c;
}
void highest_bit(unsigned int x) {
    if (x == 0) {
        printf("x = 0\n");
        return;
    }

    for (int offset = 31; offset >= 0; offset--) {
        if (x & (1u << offset)) {  // 注意括號，避免優先順序錯誤
            printf("highest bit is at %d\n", offset);
            return;
        }
    }
    return ;
}

void lowest_bit(unsigned int x)
{
    if (x == 0) {
        printf("x = 0\n");
        return;
    }

    for (int offset = 0; offset < 32; offset++) {
        if (x & (1u << offset)) {  // 注意括號，避免優先順序錯誤
            printf("lowest bit is at %d\n", offset);
            return;
        }
    }
    return ;
}

