#include <stdio.h>
void foo(void) {
    unsigned int a = 6;
    int b = -20;
    (a+b > 6) ? puts("> 6") : puts("<= 6");
}


int main(){

    foo();
    getchar();
    return 0;

}

/*
From the C99 standard, section 6.3.1.8 ("Usual arithmetic conversions"):

if the operand that has unsigned integer type has rank greater or equal to the rank of the type of the other operand, 
then the operand with signed integer type is converted to the type of the operand with unsigned integer type.
*/