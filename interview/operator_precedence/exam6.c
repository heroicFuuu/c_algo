#include<stdio.h>

int main() {
    int a = 5, b = 7, c;  
    c = a+++b; /*a++ + b ? a+ ++b*/
    printf("%d, %d, %d\n", a, b, c);//  c = 12, a = 6, b = 7
    int i = 5;
    i = ++i + i++;
    printf("%d \n", i);// 13, but this is undefined behavior
    return 0;
}
 
