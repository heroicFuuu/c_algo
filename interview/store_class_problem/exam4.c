#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    const char* ptr = "Linux";
    const char* suffix = " this is my version";

    size_t origin_len = strlen(ptr);
    size_t suffix_len = strlen(suffix);
    size_t new_size = origin_len + suffix_len + 1; // +1 放結尾 '\0'

    printf("%zu %zu %zu \n", origin_len, suffix_len, new_size);

    char* my_str = malloc(new_size);
    if (!my_str)
        return 1;

    memcpy(my_str, ptr, origin_len);                     // 複製 "Linux"
    memcpy(my_str + origin_len, suffix, suffix_len + 1); // 連同 '\0' 一起拷

    printf("%s\n", my_str);
    free(my_str);
    return 0;
}
