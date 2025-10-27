void selection_sort(int* arr, int len) {
    int min = 0, tmp = 0;

    for (int i = 0; i < len; i++) {
        min = i;
        for (int j = i + 1; j < len; j++) {
            if (arr[min] > arr[j])
                min = j;
        }

        /* 如果本身就是最小, 多這個if可以避免自己跟自己交換 */
        if (i != min) {
            tmp = arr[i];
            arr[i] = arr[min];
            arr[min] = tmp;
        }
    }
}