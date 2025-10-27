#include <stdio.h>

int main(void) {
    char* str[] = {"MediaTekOnlineTesting", "WelcomeToHere", "Hello", "EverydayGenius",
                   "HopeEverythingGood"};

    char* m = str[4] + 4;     //"HopeEverythingGood" -> offset = 4 -> "E"
    char* n = str[1];         // //"WelcomeToHere" -> "W"
    char* p = *(str + 2) + 4; // "Hello" -> offset = 4 -> "o"
    printf("1. %s\n", *(str + 1));
    printf("2. %s\n", (str[3] + 8));
    printf("3. %c\n", *m);
    printf("4. %c\n", *(n + 3));
    printf("5. %c\n", *p + 1); // 先解碼 "o" -> +1 -> "p"
    return 0;
}
