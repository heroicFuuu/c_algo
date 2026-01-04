// hash.h
typedef struct Data {
    int key;
    int value;
} Data;

void insert(Data *data);
void removekey(int key);
int search(int key);