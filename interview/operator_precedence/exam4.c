#include <stdio.h>
int main()
{
    int x, y = 2, z, a;// implicit initialization
    printf("%d\n", a);// garbage numbers
    if (x = y % 2) //x = 0 // skip , x still 0;
        z = 2; // skip, z = garbage numbers
    a = 2; // a = 2
    printf("%d %d ", z, x); // z = garbage , x = 0 ;
    return 0;
}
