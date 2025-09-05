#include <stdio.h>

char *getString()
{
   char* str = "Nice test for strings"; 
   return str;
}
 
int main()
{  
    char* s = getString();
    s[0] = 'a'; // Compile pass but runtime error
    printf("%s\n", s);
    return 0;
}
