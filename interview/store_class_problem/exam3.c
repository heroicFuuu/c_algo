#include <stdio.h>
// int main()
// {
//   typedef static int *i; // error: multiple storage classes in declaration specifiers
//   int j;
//   i a = &j;
//   printf("%d", *a);
//   getchar();
//   return 0;
// }
int main() {

    // const volatile int a = 0;
    int x = 42;
    const int* p = &x;
    int* q = &x;
    *q = 7;
    printf("%d\n", *p);

    return 0;
}
