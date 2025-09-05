#include <stdio.h>
#include <string.h>
int main()
{
    char arr[] = {1, 2, 3};
    char arr2[40] = "abc";
    char *arr3 = "hello";

    char *p = arr;
    printf(" %zu ", sizeof(p));//address size
    printf(" %zu ", sizeof(arr));// 1 byte * 3
    printf(" %zu ", sizeof(arr2));// 1 byte * 40
    printf(" %zu ", sizeof(arr3));// address size
    printf(" %zu ", strlen(arr3));// if c-style use strlen()
    getchar();
    return 0;
}    
