#include <iostream> 
using namespace std; 
int main() 
{ 
    static int i; // i == 0 因為放在static會被初始化為0
    for (i++; ++i; i++) { // 第一次是靠  i++;++i; 後面都是靠 ;++i; i++
        printf("%d ", i); 
        if (i == 6) 
            break; 
    } 
    return 0; 
} 
