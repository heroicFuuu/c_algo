#include <stdio.h>
#define BUILD_BUG_ON_ZERO(e) (sizeof(struct { int:(-!!(e)); }))

struct foo {
    unsigned int a : 3;
    unsigned int b : 2;
    int : 0; /* Force alignment to next boundary */
    unsigned int c : 4;
    unsigned int d : 3;
};

int main() {
    int i = 0xFFFF;
    struct foo *f = (struct foo *) &i;
    printf("%d\n", sizeof(f));
    printf("a=%d\nb=%d\nc=%d\nd=%d\n", f->a, f->b, f->c, f->d);
    return 0;
}
