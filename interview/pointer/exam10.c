#include<stdio.h>
int main()
{
   int a;
   char *x;
   x = (char *) &a;
   a = 512;
   x[0] = 1;// 
   x[1] = 2;
   printf("%d\n",a);
 
   getchar();
   return 0;
} 
/*
int  4 byte 
char 2 byte
low   ---------------------------------->  high
little endian
位址:   x[0]      x[1]      x[2]      x[3]
內容:   00000000  00000010  00000000  00000000   == 512
        (0)      (2)       (0)       (0)

經過 x[0] = 1 ; x[1] = 2;

位址:   x[0]      x[1]      x[2]      x[3]
內容:   00000001  00000010  00000000  00000000
        (1)      (2)       (0)       (0)        == 513


*/

