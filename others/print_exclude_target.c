#include <stdio.h>
#include <stdbool.h>
/* 內部工具：交換兩個 int */
static inline void swap_int(int *a, int *b) {
    int t = *a; *a = *b; *b = t;
}

/* Lomuto 分割：pivot = arr[end]，回傳樞紐位置 */
static int partition(int *arr, int front, int end) {
    int pivot = arr[end];
    int i = front - 1;
    for (int j = front; j < end; ++j) {
        if (arr[j] < pivot) {
            ++i;
            swap_int(&arr[i], &arr[j]);
        }
    }
    swap_int(&arr[++i], &arr[end]);
    return i;
}

/* 快速排序（含尾遞迴優化以降低最大遞迴深度） */
void q_sort(int *arr, int front, int end) {
    while (front < end) {
        int p = partition(arr, front, end);
        /* 先遞迴到較小的半邊，較大的半邊改用迴圈繼續（尾遞迴消除） */
        if (p - front < end - p) {
            q_sort(arr, front, p - 1);
            front = p + 1;
        } else {
            q_sort(arr, p + 1, end);
            end = p - 1;
        }
    }
}


/* 給一個int a[size]已排序的陣列，請寫一個function(a, size)能印出0~500的數字，
   且不包含a陣列內的元素，請用最少的時間和空間複雜度完成 */
void func1(int *a, int size){

    int offset = 0;
    
    const int nums_perline = 25;
    int cur_nums = 0;
    
    while ( offset < size && *(a + offset) < 0){
        ++offset;
    }

    for (int i = 0 ; i < 501 ; ++i){
     

        if ( offset < size && *(a + offset) == i){
            for( ; offset < size && *(a + offset) == i; offset++);
            continue;
        }

        printf("%3d ", i);
        cur_nums ++;
        if (cur_nums % nums_perline == 0)
            printf("\n");
        
         
    }

}


/*給一個int a[20]已排序的陣列，請寫一個function(a, size, b) 能依照參數b(b = 0~4)別印出該區間的數字，
  且不包含a陣列內的元素，例如 b =0, 印出0~99 b = 1, 印出100~199 */
void func2(int *a, int size, int b){

}


//Test
typedef void (*Printfunc)(int *a, int size);

static void run_case(const char *name, Printfunc func, int *arr, int n){
    printf("=== %s (n=%d) ===\n", name, n);
    func(arr, n);
    printf("\n");
}

int main (int argc, char **argv){
    
    // Case 1: 20 筆（已排序）
    int a20[20] = {
        0, 3, 7, 11, 50, 75, 100, 123, 150, 175,
        200, 234, 256, 300, 333, 350, 400, 420, 450, 500
    };
    run_case("size=20", func1, a20, 20);

    // Case 2: 含重複值（應只是不印那些值，重複不影響）
    int dup[] = {0, 0, 1, 2, 2, 256,355, 500};
    run_case("duplicates", func1, dup, (int)(sizeof(dup)/sizeof(dup[0])));

    // Case 3: 只有極端（0 與 500）
    int extremes[] = {0, 500};
    run_case("extremes",func1, extremes, 2);

    // Case 4: 完整覆蓋 0..500（應該一個數都不印）
    int full[501];
    for (int i = 0; i <= 500; ++i) full[i] = i;
    run_case("full_0_to_500", func1, full, 501);

    // Case 5: 含負數與超出 500 的值（要能正確忽略 0..500 之內存在的）
    int mixed[] = {-3, -1, 0, 5, 12, 500, 501, 999};
    run_case("mixed(<0 and >500)", func1, mixed, (int)(sizeof(mixed)/sizeof(mixed[0])));

    /* Case 6: 未排序、大小 20，含 0 與 500、以及中間多個值 */
    int unsorted20[] = {50, 0, 333, -7, 420, 11, 123, 3, 500, 150,
                    175, 256, 75, 400, 234, 350, 7, 200, 450, 300};
    int size6 = (int)(sizeof(unsorted20)/sizeof(unsorted20[0]));
    q_sort(unsorted20, 0, size6-1);
    run_case("unsorted20 -> via sort", func1,
    unsorted20, size6);
    
    /* Case 7: 未排序、重複、大小 20，負數、含 0 與 500、以及中間多個值 */
    int unsorted_mixed[] = {12, 12, -7, -1, 999, 501, 0, 5, 500, 5, 42, 300};
    int size7 = (int)(sizeof(unsorted_mixed)/sizeof(unsorted_mixed[0]));
    q_sort(unsorted_mixed, 0, size7-1);
    run_case("unsorted_mixed -> via sort", func1,
              unsorted_mixed,
              size7);

    return 0;
}
