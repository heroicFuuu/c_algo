#include <iostream>
#include <vector>

#include "binary_search.h"
using std::vector;


int binary_search(vector<int> &arr, int target){
    if (arr.empty()) return -1;
    int l = 0, r = arr.size() - 1;
    while (l < r){
        int mid = l + (r - l) / 2;
        if (arr[mid] == target) return mid;
        if (arr[mid] < target){
            l = mid + 1;
        } else{
            r = mid;
        }
    }

    if (arr[l] == target){
        return l;
    }

    return -1;
}

#ifdef TEST_BINARYSEARCH
#include <iostream>
#include <algorithm>
#include "../utilis.h"
#include "../sort/quicksort.h"

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

    int caseId = 1;
    for (auto test : tests){
        std::cout << "=== Case" << caseId++ << " ===\n";
        if (!test.empty())
            q_sort(test, 0, test.size()-1);


        print_vector_elements(test);

        if (!std::is_sorted(test.begin(), test.end())){
            std::cerr << "[Error] sort failed!\n";
            continue;
        }

        /*test binary search*/
        if (!test.empty()){

            int idx = std::min<int>(5, test.size()-1);
            int target = test[idx];
            int found = binary_search(test, target);
            if (found != -1 && test[found] == target){
                std::cout << "[Pass] Found target " << target << " at index " << found << "\n";
            }else{
                std::cout << "[Error] Fail to find exising target";
            }

            int not_exist_val = test.back()+99;
            int not_found = binary_search(test, not_exist_val);
            if (not_found == -1){
                std::cout << "[Pass] Correct not found " << not_exist_val << "\n";
            }else{
                std::cout << "[Error] Wrong found " << not_exist_val << "at index " << not_found << "\n";
            }
        }

        std::cout << std::endl;
    }

    return 0;


}

#endif