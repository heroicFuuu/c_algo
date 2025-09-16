#include <stdio.h> 

int main()     
{ 
    unsigned int a = 0xffff; // a = 0x0000ffff
    unsigned int k = ~a; // k = // a = 0xffff0000
    printf("%d %d\n", a, k); 
    return 0; 
} 
