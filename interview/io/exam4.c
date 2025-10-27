#include <stdio.h>

char* fun() {
    return "awake";
}
int main() {
    printf("%d\n", printf("I see you"));
    printf("%s", fun() + printf("I see you"));
    getchar();
    return 0;
}
/*
 [2]                 [1]
printf("%s",fun()+ printf("I see you")

 [1]    |    [2]
I see youee you

輸出[2]是來自fun的回傳的指標 + 9
地址 →| 'a' 'w' 'a' 'k' 'e' '\0' 'I' ' ' 's' 'e' 'e' ' ' 'y' 'o' 'u' '\0' |
是越界訪問，其實是未定義行為 因為不一定保證他們的排序
*/