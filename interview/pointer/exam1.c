#include <stdio.h>
int main() {
    char a[2][3][3] = {'g', 'e', 'e', 'k', 's', 'f', 'o', 'r', 'g', 'e', 'e', 'k', 's'};
    printf("%s ", **a);

    char t[3] = {'a', 'b', 'c'}; // undefine behavior
    printf("%s ", t);

    getchar();
    return 0;
}
