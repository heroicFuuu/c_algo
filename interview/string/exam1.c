#include <stdio.h>

void reverse(char *str, int lens){
    for (int i = 0 ; i< lens/2 ; i++){
        char t = str[i];
        str[i] = str[lens - 1 - i];
        str[lens - 1 - i] = t;
    }

    return ;
}

int main() {
    char arr[] = "geeksforgeeks"; // 13 + \0
    printf("%zu\n", sizeof(arr));

    int lens = sizeof(arr)/sizeof(char) - 1;
    // reverse
    reverse(arr, lens);
    printf("%s\n", arr);

    getchar();
    return 0;
}
