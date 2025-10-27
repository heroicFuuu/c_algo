#include <assert.h>
#include <stdio.h>
int main() {
    int i = 0;
    int* p = &i;
    assert(&(p[0]) == &i); // why not fail?
    return 0;
}
