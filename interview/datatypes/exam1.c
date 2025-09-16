#include <stdbool.h>
#include <stdio.h>
bool is_one(int i) {
    return i == 1;
}
int main() {
    struct {
        signed int a : 1;
    } obj = {.a = 1};
    puts(is_one(obj.a) ? "one"
                       : "not one"); // signed 轉型會變成？ 1 bit 只有 sign bit只能表達 0 / -1
    return 0;
}
