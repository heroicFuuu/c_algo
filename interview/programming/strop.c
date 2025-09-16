#include <stdio.h>
#include <string.h>

/* ---- 自己實作 ---- */
char *my_strcpy(char *dest, const char *src) {
    char *ret = dest;
    while (*src != '\0') {
        *dest++ = *src++;
    }
    *dest = '\0';
    return ret;
}

char *my_strcat(char *dest, const char *src) {
    char *ret = dest;
    while (*dest != '\0') dest++;
    while (*src != '\0') {
        *dest++ = *src++;
    }
    *dest = '\0';
    return ret;
}

int my_strlen(const char *str) {
    int len = 0;
    while (*str++ != '\0') len++;
    return len;
}

int my_strcmp(const char *s1, const char *s2) {
    while (*s1 && (*s1 == *s2)) {
        s1++;
        s2++;
    }
    return *(const unsigned char *)s1 - *(const unsigned char *)s2;
}

/* ---- 測試 ---- */
int main() {
    char buf1[100];
    char buf2[100];

    /* 測試 strcpy */
    printf("==== strcpy ====\n");
    my_strcpy(buf1, "Hello");
    strcpy(buf2, "Hello");
    printf("my: %s | std: %s\n", buf1, buf2);

    my_strcpy(buf1, "");
    strcpy(buf2, "");
    printf("my: '%s' | std: '%s'\n", buf1, buf2);

    /* 測試 strcat */
    printf("\n==== strcat ====\n");
    my_strcpy(buf1, "Hello");
    strcpy(buf2, "Hello");
    my_strcat(buf1, " World");
    strcat(buf2, " World");
    printf("my: %s | std: %s\n", buf1, buf2);

    my_strcpy(buf1, "A");
    strcpy(buf2, "A");
    my_strcat(buf1, "B");
    strcat(buf2, "B");
    printf("my: %s | std: %s\n", buf1, buf2);

    /* 測試 strlen */
    printf("\n==== strlen ====\n");
    printf("my: %d | std: %lu\n", my_strlen("Hello"), strlen("Hello"));
    printf("my: %d | std: %lu\n", my_strlen(""), strlen(""));
    printf("my: %d | std: %lu\n", my_strlen("Hello World"), strlen("Hello World"));

    /* 測試 strcmp */
    printf("\n==== strcmp ====\n");
    printf("'Hello' vs 'Hello' → my: %d | std: %d\n",
           my_strcmp("Hello", "Hello"), strcmp("Hello", "Hello"));
    printf("'ABC' vs 'ABD' → my: %d | std: %d\n",
           my_strcmp("ABC", "ABD"), strcmp("ABC", "ABD"));
    printf("'ABD' vs 'ABC' → my: %d | std: %d\n",
           my_strcmp("ABD", "ABC"), strcmp("ABD", "ABC"));
    printf("'' vs 'A' → my: %d | std: %d\n",
           my_strcmp("", "A"), strcmp("", "A"));
    printf("'A' vs '' → my: %d | std: %d\n",
           my_strcmp("A", ""), strcmp("A", ""));

    return 0;
}
