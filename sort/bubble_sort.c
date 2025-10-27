#include <stdbool.h>

void bubble_sort(int* arr, int len) {
    int tmp;
    bool swapped;

    for (int i = 0; i < len - 1; i++) {
        swapped = false;
        for (int j = 0; j < len - 1 - i; j++) { // 相鄰比較
            if (arr[j] > arr[j + 1]) {
                tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
                swapped = true;
            }
        }
        if (!swapped)
            break; // 如果某一輪沒有交換，提前結束
    }
}
