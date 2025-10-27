#include <stdio.h>

int func(int i) {
    if (i % 2)
        return (i++); //這裡i++ 沒有意義
    else
        return func(func(i - 1));
}

int main(int argc, char** argv) {

    int ret = func(8);
    printf("%d\n", ret);
    return 0;
}