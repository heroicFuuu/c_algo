#include <stdio.h>
int main() {
    int x = 2;
    switch (x) {
        x--;
        switch (x) {
        case 1:
            printf("Hello");
            break;
        case 2:
            printf("GFG");
            break;
        case 3:
            printf("Welcome");
            break;
        default:
            printf("BYE");
        }
    }
    return (0);
}
