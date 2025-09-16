#include <stdio.h>

int main(void)
{
    char *a[] = {"abc", "def", "ghijk", "lmnop"};
    char *b = a[2];
    
    printf("%d\n", sizeof(a));       
    printf("%d\n", sizeof(b));        
    printf("%d\n", sizeof(a[2]));  
    printf("%d\n", sizeof(b[2]));  
    printf("%c\n", b[2]); 
    
    return 0;
}
