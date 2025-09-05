#include "quicksort.h"


void swap(int *a, int *b){    
    int t = *a;
    *a =*b;
    *b = t;
}

int partition(vector<int>&arr, int front, int end){

    int i = front - 1;
    int pivot = arr[end];
    for (int j = front ; j < end ; ++j){
        if (arr[j] < pivot){

            ++i;
            swap(&arr[j], &arr[i]);
        }
    }

    swap(&arr[end], &arr[++i]);

    return i;
}


void q_sort(vector<int>&arr, int front, int end){

    if (front < end){
        int pivot_pos = partition(arr, front, end);
        q_sort(arr, front, pivot_pos-1);
        q_sort(arr, pivot_pos+1, end);

    }

};

#ifdef TEST_QUICKSORT
#include <algorithm>
#include "../utilis.h"
int main(int argc, char** argv){

    vector<vector<int>> tests;
    tests.push_back({});
    tests.push_back({42});
    tests.push_back({1,2,3,4,5,6});
    tests.push_back({5,4,3,2,1,-5});
    tests.push_back({2,2,2,2,2,2});
    tests.push_back({9,1,8,2,7,3,6,4,5,12,16});

    tests.push_back(generate_random_vector(10,0,100));
    tests.push_back(generate_random_vector(20,-50,50));

    for (auto test:tests){
        if (!test.empty()) {
            q_sort(test, 0, test.size()-1);
        }   

        if (!std::is_sorted(test.begin(), test.end())){
            std::cerr << "[Error] not sorted" << std::endl;
        }else{
            std::cout << "[Pass] ";
            print_vector_elements(test);
        }
    }

    return 0;
}

#endif

