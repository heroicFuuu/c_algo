#include <stdio.h> 
int main(void) 
{ 
    int i = 40 >> 5 << 3 >> 2 << 1; 
    // ((((40 >> 5) << 3) >> 2) << 1)
    // 1 ---> 8 ---> 2 --> 4
    printf("%d", i); 
    return 0; 
} 
