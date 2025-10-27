/* define */
// 1. A pointer to a pointer to an integer
// 2. An array of 10 integers
// 3. An array of 10 pointers to integers
// 4. A pointer to an array of 10 integers
// 5. A pointer to a function that takes an integer as an argument and returns an integer
// 6. An array of ten pointers to functions that take an integer argument and return an integer

int** p;
int a[10];
int* p[10];
int (*p)[10];
int (*p)(int);
int (*p[10])(int);
