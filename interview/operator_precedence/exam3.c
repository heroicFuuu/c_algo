#include <stdio.h>

int main() {
    char str[] = "geeks\nforgeeks";
    char *ptr1, *ptr2;

    ptr1 = &str[3];//address of str[3] k 
    ptr2 = str + 5;//address of str[5] \n
    printf("%c", ++*str - --*ptr1 + *ptr2 + 2);// h - j + \n + 2 = 104 - 106 + 10 + 2 = ASCII(10) \n 
    printf("%s", str);

    getchar();
    return 0;
}
