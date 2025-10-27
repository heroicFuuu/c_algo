void insertion_sort(int* arr, int len) {
    int key = 0, j = 0;

    for (int i = 1; i < len; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && key < arr[j]) {
            arr[j + 1] = arr[j];
            j -= 1;
        }
        arr[j + 1] = key;
    }
}
