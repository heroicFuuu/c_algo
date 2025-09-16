#include <stdio.h> 
int main(void) 
{ 
    int i = 10 > 9 > 7 < 8;
    /*
        10 > 9 == 1
        1 > 7 == 0
        0 < 8 == 1;
    */ 
    printf("%d", i); 
    return 0; 
} 
