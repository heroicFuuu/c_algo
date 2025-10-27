#include <stdio.h>

int main() {
    typedef struct tag {
        char str[10];
        int a;
    } har;

    har h1, h2 = {"IHelp", 10};
    h1 = h2;
    h1.str[1] = 'h';
    printf("%s, %d\n", h1.str, h1.a);
    printf("%s, %d\n", h2.str, h2.a);

    typedef struct mytag {
        char* str;
        int a;
    } newHar;
    char* s = "IHelP";
    newHar h3, h4 = {s, 20};
    h3 = h4;
    // h3.str[2] = 'E';
    printf("%s, %d\n", h3.str, h3.a);
    printf("%s, %d\n", h4.str, h4.a);

    return 0;
}
